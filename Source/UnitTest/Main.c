#include <KNSoft/NDK/NDK.h>

#include "UnitTest.h"

#pragma comment (lib, "KNSoft.Syscall.lib")

extern FN_TEST_PROC NotFound;
extern FN_TEST_PROC MemPageAlloc;

#define RUN_TEST(x) if (!x()) return 1;

int
_cdecl
mainCRTStartup(void)
{
    HRESULT hr = Syscall_Init();
    if (FAILED(hr))
    {
        return hr;
    }

    RUN_TEST(NotFound);
    RUN_TEST(MemPageAlloc);

    return 0;
}
