#include "UnitTest.h"

/*
 * Test case: No import table
 */
_Function_class_(FN_TEST_PROC)
LOGICAL
NoImport(VOID)
{
    PIMAGE_NT_HEADERS pNtHeader = Add2Ptr(&__ImageBase, __ImageBase.e_lfanew);
    return pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress == 0;
}
