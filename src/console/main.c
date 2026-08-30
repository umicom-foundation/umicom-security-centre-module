/*-----------------------------------------------------------------------------
 * Umicom Security Centre Module
 * File: src/console/main.c
 *
 * PURPOSE:
 *   Provide a native verification frontend for the thin product composition.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#include <stdio.h>

#include "umicom/security_centre/application.h"
#include "umicom/security_centre/workspace.h"

int main(void)
{
    UmiApplicationExperienceStatus status;
    const UmiApplicationExperienceDefinition *definition =
        umi_security_centre_application_experience();
    const UmiExperienceLayoutDefinition *layout =
        umi_security_centre_workspace_default();
    const UmiExperienceFeatureDefinition *next =
        umi_security_centre_workspace_next_feature();

    if (definition == NULL ||
        umi_security_centre_application_status(&status) != UMI_STATUS_OK ||
        layout == NULL) {
        fputs("Umicom Security Centre: Framework experience unavailable\n", stderr);
        return 1;
    }

    printf("%s\n", definition->display_name);
    printf("application: %s\n", definition->application_id);
    printf("default layout: %s\n", layout->title);
    printf("panels: %zu\n", status.panel_count);
    printf("layouts: %zu\n", status.layout_count);
    printf("features: %zu\n", status.feature_count);
    printf("readiness: %u%%\n", status.readiness_percent);
    if (next != NULL)
        printf("next: %s [%s]\n", next->title,
               umi_experience_priority_text(next->priority));
    return 0;
}
