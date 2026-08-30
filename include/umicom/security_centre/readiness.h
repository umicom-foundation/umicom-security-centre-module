/*-----------------------------------------------------------------------------
 * Umicom Security Centre Module
 * File: include/umicom/security_centre/readiness.h
 *
 * PURPOSE:
 *   Expose Framework-owned readiness and ownership evidence through the thin product boundary.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/


#ifndef UMICOM_SECURITY_CENTRE_READINESS_H
#define UMICOM_SECURITY_CENTRE_READINESS_H

#include "umicom/application/runtime/readiness.h"

#ifdef __cplusplus
extern "C" {
#endif

UmiStatus umi_security_centre_readiness_report(
    UmiApplicationReadinessReport *out_report);
const UmiExperienceFeatureDefinition *umi_security_centre_readiness_next_feature(void);

#ifdef __cplusplus
}
#endif

#endif
