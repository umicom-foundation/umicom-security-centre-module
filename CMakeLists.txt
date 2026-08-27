#-----------------------------------------------------------------------------
# Umicom Security Centre Module
# File: CMakeLists.txt
#
# PURPOSE:
#   Build the thin Umicom Security Centre composition against the canonical Umicom
#   Framework application target without defining local reusable services.
#
# Created by: Sammy Hegab
# Organisation: Umicom Foundation
# Licence: MIT
#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.24)

project(
    UmicomSecurityCentreModule
    VERSION 0.1.0
    DESCRIPTION "Thin Umicom Security Centre composition over Umicom Framework"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(UMICOM_SECURITY_CENTRE_BUILD_CONSOLE
       "Build the native Umicom Security Centre verification console"
       ON)

include(CTest)
include(GNUInstallDirs)

if(NOT TARGET Umicom::Framework)
    find_package(UmicomFramework CONFIG REQUIRED)
endif()

if(NOT TARGET Umicom::application)
    message(FATAL_ERROR
        "Umicom Security Centre requires Framework target Umicom::application")
endif()

if(NOT COMMAND umicom_apply_warnings)
    function(umicom_apply_warnings target)
        if(MSVC)
            target_compile_options(${target} PRIVATE /W4)
        else()
            target_compile_options(${target} PRIVATE
                -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
        endif()
    endfunction()
endif()

if(NOT COMMAND umicom_apply_sanitizers)
    function(umicom_apply_sanitizers target)
    endfunction()
endif()

add_library(umicom_security_centre_module STATIC
    src/application.c
    src/workspace.c
)
add_library(Umicom::security_centre_module ALIAS umicom_security_centre_module)

target_include_directories(umicom_security_centre_module PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(umicom_security_centre_module PUBLIC
    Umicom::Framework
    Umicom::application
)

if(COMMAND umicom_apply_warnings)
    umicom_apply_warnings(umicom_security_centre_module)
endif()
if(COMMAND umicom_apply_sanitizers)
    umicom_apply_sanitizers(umicom_security_centre_module)
endif()

if(UMICOM_SECURITY_CENTRE_BUILD_CONSOLE)
    add_executable(umicom-security-centre-console
        src/console/main.c)
    target_link_libraries(umicom-security-centre-console PRIVATE
        Umicom::security_centre_module)
    if(COMMAND umicom_apply_warnings)
        umicom_apply_warnings(umicom-security-centre-console)
    endif()
    if(COMMAND umicom_apply_sanitizers)
        umicom_apply_sanitizers(umicom-security-centre-console)
    endif()
endif()

if(BUILD_TESTING)
    add_executable(umicom_security_centre_module-test
        tests/test_application.c)
    target_link_libraries(umicom_security_centre_module-test PRIVATE
        Umicom::security_centre_module)
    if(COMMAND umicom_apply_warnings)
        umicom_apply_warnings(umicom_security_centre_module-test)
    endif()
    if(COMMAND umicom_apply_sanitizers)
        umicom_apply_sanitizers(umicom_security_centre_module-test)
    endif()
    add_test(
        NAME security-centre.module.application
        COMMAND umicom_security_centre_module-test)
endif()

install(TARGETS umicom_security_centre_module
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
if(TARGET umicom-security-centre-console)
    install(TARGETS umicom-security-centre-console
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES application.umicom.yaml
    DESTINATION ${CMAKE_INSTALL_DATADIR}/umicom/applications/security-centre)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
    install(FILES README.md
        DESTINATION ${CMAKE_INSTALL_DATADIR}/umicom/applications/security-centre)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
    install(FILES LICENSE
        DESTINATION ${CMAKE_INSTALL_DATADIR}/licenses/security-centre)
endif()

message(STATUS "Umicom Security Centre Module version: ${PROJECT_VERSION}")
message(STATUS "Umicom Security Centre uses Framework-owned thin-client composition")

include(
    "${CMAKE_CURRENT_SOURCE_DIR}/../../framework/cmake/UmicomApplicationProductisationContribution.cmake")
umicom_add_application_productisation_contribution(
    NAME "security-centre"
    TARGET umicom_security_centre_productisation
    SOURCE "src/productisation_contribution.c"
    TEST_SOURCE "tests/test_productisation_contribution.c")
