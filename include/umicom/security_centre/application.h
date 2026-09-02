/*-----------------------------------------------------------------------------
 * Umicom Security Centre Module
 * File: include/umicom/security_centre/application.h
 *
 * PURPOSE:
 *   Expose the thin application composition over Framework-owned experience metadata and services.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_SECURITY_CENTRE_APPLICATION_H
#define UMICOM_SECURITY_CENTRE_APPLICATION_H

#include "umicom/application/experience.h"
#include "umicom/application/experience_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UMI_SECURITY_CENTRE_MODULE_API_VERSION 1U

/**
 * Provide the security centre application id operation used by this module and its client
 * applications.
 */
const char *umi_security_centre_application_id(void);

/**
 * Provide the security centre application experience operation used by this module and its
 * client applications.
 */
const UmiApplicationExperienceDefinition *
umi_security_centre_application_experience(void);

/**
 * Provide the security centre application status operation used by this module and its
 * client applications.
 */
UmiStatus umi_security_centre_application_status(
    UmiApplicationExperienceStatus *out_status);

#ifdef __cplusplus
}
#endif

#endif
