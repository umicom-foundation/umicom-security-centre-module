/*-----------------------------------------------------------------------------
 * Umicom Security Centre Module
 * File: include/umicom/security_centre/productisation_contribution.h
 *
 * PURPOSE:
 *   Declare this thin module's adoption of Framework-owned application
 *   experience, components, layouts and productisation evidence.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/
#ifndef UMICOM_SECURITY_CENTRE_PRODUCTISATION_CONTRIBUTION_H
#define UMICOM_SECURITY_CENTRE_PRODUCTISATION_CONTRIBUTION_H

#include "umicom/application/productisation/session.h"
#include "umicom/application/productisation/workspace_guide.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Provide the security centre productisation contribution operation used by this module
 * and its client applications.
 */
const UmiProductApplicationAdoption *
umi_security_centre_productisation_contribution(void);
/**
 * Provide the security centre productisation snapshot operation used by this module and
 * its client applications.
 */
UmiStatus umi_security_centre_productisation_snapshot(
    UmiProductApplicationAdoptionSnapshot *out_snapshot);
/**
 * Initialise security centre product session from caller-provided values so later
 * operations receive a known state.
 */
UmiStatus umi_security_centre_product_session_init(
    UmiProductApplicationSession *out_session);
/* Build welcome-screen workspace choices from the canonical Framework profile. */
UmiStatus umi_security_centre_product_workspace_guide(
    UmiProductWorkspaceGuide *out_guide);

#ifdef __cplusplus
}
#endif

#endif
