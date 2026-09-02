/*-----------------------------------------------------------------------------
 * Umicom Security Centre Module
 * File: src/application.c
 *
 * PURPOSE:
 *   Bind the product identity to the canonical Framework application-experience catalogue.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#include "umicom/security_centre/application.h"

#include "umicom/application/experience_catalogue.h"

/*
 * Provide the security centre application id operation used by this module and its client
 * applications.
 */
const char *umi_security_centre_application_id(void)
{
    return "org.umicom.security-centre";
}

/*
 * Provide the security centre application experience operation used by this module and its
 * client applications.
 */
const UmiApplicationExperienceDefinition *
umi_security_centre_application_experience(void)
{
    return umi_application_experience_catalogue_find(
        umi_security_centre_application_id());
}

/*
 * Provide the security centre application status operation used by this module and its
 * client applications.
 */
UmiStatus umi_security_centre_application_status(
    UmiApplicationExperienceStatus *out_status)
{
    const UmiApplicationExperienceDefinition *definition =
        umi_security_centre_application_experience();
    /*
     * Protect caller-owned memory by checking that required state is available before it is
     * used.
     */
    if (definition == NULL) return UMI_STATUS_NOT_FOUND;
    return umi_application_experience_status(definition, out_status);
}
