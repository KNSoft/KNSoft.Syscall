#include "UnitTest.h"
#include "AllThunks.inl"

/*
 * Test case: Reference all thunks and print each initialization status
 */
_Function_class_(FN_TEST_PROC)
LOGICAL
AllThunks(VOID)
{
    for (ULONG i = 0; i < ARRAYSIZE(AllThunkDef); i++)
    {
        if (NT_ERROR(Syscall_GetData(AllThunkDef[i].Address)))
        {
            PrintEx(AllThunkDef[i].Name, AllThunkDef[i].NameCch);
            Print(" Failed\r\n");
        }
    }
    return TRUE;
}
