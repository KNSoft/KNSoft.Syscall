#include "UnitTest.h"

/*
 * Test case: No import table
 */
_Function_class_(FN_TEST_PROC)
LOGICAL
NoImport(VOID)
{
    return ((PIMAGE_NT_HEADERS)Add2Ptr(&__ImageBase, __ImageBase.e_lfanew))->
        OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress == 0;
}
