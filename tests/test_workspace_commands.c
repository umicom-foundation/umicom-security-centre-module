/*-----------------------------------------------------------------------------
 * Umicom Security Centre Module
 * File: tests/test_workspace_commands.c
 *
 * PURPOSE:
 *   Verify product commands forward to the canonical Framework workspace runtime.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/


#include <assert.h>

#include "umicom/security_centre/workspace_commands.h"

/*
 * Start this command or application, report setup failures, and return a process exit code
 * to the operating system.
 */
int main(void)
{
    UmiApplicationWorkspaceRuntime runtime;
    const UmiApplicationExperienceDefinition *experience =
        umi_security_centre_runtime_experience();
    const UmiApplicationCommandSurface *commands;
    assert(experience != NULL);
    assert(umi_security_centre_runtime_init(&runtime) == UMI_STATUS_OK);
    assert(umi_security_centre_workspace_select_layout(
               &runtime, experience->default_layout_id) == UMI_STATUS_OK);
    assert(umi_security_centre_workspace_activate_panel(
               &runtime, experience->panels[0].panel_id) == UMI_STATUS_OK);
    commands = umi_security_centre_workspace_commands(&runtime);
    assert(commands != NULL);
    assert(umi_application_command_surface_find(
               commands, UMI_APPLICATION_COMMAND_SELECT_LAYOUT,
               experience->default_layout_id) != NULL);
    assert(umi_security_centre_workspace_commands(NULL) == NULL);
    return 0;
}
