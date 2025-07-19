#include "UnitTest.h"

/*
 * Test case: Syscall not found
 * NtGetPlugPlayEvent was removed since NT 6.2, should returns STATUS_PROCEDURE_NOT_FOUND
 */
_Function_class_(FN_TEST_PROC)
LOGICAL
NotFound(VOID)
{
    NTSTATUS Status;

    if (SharedUserData->NtMajorVersion > 6 ||
        SharedUserData->NtMajorVersion == 6 && SharedUserData->NtMinorVersion >= 2)
    {
#pragma warning(disable: __WARNING_INVALID_PARAM_VALUE_1)
        Status = ScGetPlugPlayEvent(NULL, NULL, NULL, 0);
#pragma warning(default: __WARNING_INVALID_PARAM_VALUE_1)
        if (Status != STATUS_PROCEDURE_NOT_FOUND)
        {
            return FALSE;
        }
    }

    return TRUE;
}
