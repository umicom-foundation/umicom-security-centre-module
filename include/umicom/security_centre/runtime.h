/*-----------------------------------------------------------------------------
 * Umicom Security Centre Module
 * File: include/umicom/security_centre/runtime.h
 *
 * PURPOSE:
 *   Bind the thin product to the Framework-owned application workspace runtime without duplicating services.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_SECURITY_CENTRE_RUNTIME_H
#define UMICOM_SECURITY_CENTRE_RUNTIME_H

#include "umicom/application/runtime/runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialise security centre runtime from caller-provided values so later operations
 * receive a known state.
 */
UmiStatus umi_security_centre_runtime_init(
    UmiApplicationWorkspaceRuntime *out_runtime);
/**
 * Provide the security centre runtime health operation used by this module and its client
 * applications.
 */
UmiStatus umi_security_centre_runtime_health(
    UmiApplicationCapabilityProbe probe,
    void *user_data,
    UmiApplicationRuntimeHealth *out_health);
/**
 * Provide the security centre runtime experience operation used by this module and its
 * client applications.
 */
const UmiApplicationExperienceDefinition *umi_security_centre_runtime_experience(void);

#ifdef __cplusplus
}
#endif

#endif
