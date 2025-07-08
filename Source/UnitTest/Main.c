#include <KNSoft/NDK/NDK.h>
#include <KNSoft/NDK/Package/UnitTest.inl>

#pragma comment (lib, "KNSoft.Syscall.lib")

TEST_DECL_FUNC(Test);

CONST UNITTEST_ENTRY UnitTestList[] = {
    TEST_DECL_ENTRY(Test),
    { 0 }
};

int
_cdecl
wmain(
    _In_ int argc,
    _In_reads_(argc) _Pre_z_ wchar_t** argv)
{
    return UnitTest_Main(argc, argv);
}
