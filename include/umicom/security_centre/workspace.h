/*-----------------------------------------------------------------------------
 * Umicom Security Centre Module
 * File: include/umicom/security_centre/workspace.h
 *
 * PURPOSE:
 *   Expose product workspace lookups without duplicating Framework workbench or layout logic.
 *
 * Created by: Sammy Hegab
 * Organisation: Umicom Foundation
 * Licence: MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_SECURITY_CENTRE_WORKSPACE_H
#define UMICOM_SECURITY_CENTRE_WORKSPACE_H

#include <stddef.h>

#include "umicom/application/experience.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t umi_security_centre_workspace_layout_count(void);

const UmiExperienceLayoutDefinition *umi_security_centre_workspace_layout_at(
    size_t index);

const UmiExperienceLayoutDefinition *umi_security_centre_workspace_default(void);

const UmiExperienceFeatureDefinition *umi_security_centre_workspace_next_feature(
    void);

#ifdef __cplusplus
}
#endif

#endif
