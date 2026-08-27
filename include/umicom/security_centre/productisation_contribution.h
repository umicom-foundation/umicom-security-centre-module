/*-----------------------------------------------------------------------------
 * Umicom Security Centre Module
 * File: include/umicom/security_centre/productisation_contribution.h
 *
 * PURPOSE:
 *   Declare this thin module's adoption of Framework-owned application
 *   experience, components, layouts and productisation evidence.
 *
 * Created by: Sammy Hegab
 * Organisation: Umicom Foundation
 * Licence: MIT
 *---------------------------------------------------------------------------*/
#ifndef UMICOM_SECURITY_CENTRE_PRODUCTISATION_CONTRIBUTION_H
#define UMICOM_SECURITY_CENTRE_PRODUCTISATION_CONTRIBUTION_H

#include "umicom/application/productisation/adoption.h"

#ifdef __cplusplus
extern "C" {
#endif

const UmiProductApplicationAdoption *
umi_security_centre_productisation_contribution(void);
UmiStatus umi_security_centre_productisation_snapshot(
    UmiProductApplicationAdoptionSnapshot *out_snapshot);

#ifdef __cplusplus
}
#endif

#endif
