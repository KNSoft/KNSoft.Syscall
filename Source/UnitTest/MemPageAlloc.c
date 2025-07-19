#include "UnitTest.h"

/*
 * Test case: Memory page allocation
 */
_Function_class_(FN_TEST_PROC)
LOGICAL
MemPageAlloc(VOID)
{
    NTSTATUS Status;
    PBYTE Base = NULL;
    SIZE_T Size = PAGE_SIZE;

    Status = ScAllocateVirtualMemory(NtCurrentProcess(), &Base, 0, &Size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!NT_SUCCESS(Status))
    {
        return FALSE;
    }
    *Base = 0xFF;
    Status = ScFreeVirtualMemory(NtCurrentProcess(), &Base, &Size, MEM_RELEASE);
    if (!NT_SUCCESS(Status))
    {
        return FALSE;
    }

    return TRUE;
}
