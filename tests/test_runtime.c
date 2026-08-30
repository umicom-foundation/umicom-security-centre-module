/*-----------------------------------------------------------------------------
 * Umicom Security Centre Module
 * File: tests/test_runtime.c
 *
 * PURPOSE:
 *   Verify the thin product starts and evaluates a Framework-owned workspace runtime.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/


#include <assert.h>

#include "umicom/security_centre/runtime.h"

int main(void)
{
    UmiApplicationWorkspaceRuntime runtime;
    UmiApplicationRuntimeHealth health;
    assert(umi_security_centre_runtime_init(&runtime) == UMI_STATUS_OK);
    assert(runtime.session.experience == umi_security_centre_runtime_experience());
    assert(runtime.session.active_panel_count > 0U);
    assert(runtime.commands.command_count > 0U);
    assert(umi_security_centre_runtime_health(NULL, NULL, &health) == UMI_STATUS_OK);
    assert(health.readiness_percent <= 100U);
    assert(health.unavailable_capabilities == 0U);
    return 0;
}
