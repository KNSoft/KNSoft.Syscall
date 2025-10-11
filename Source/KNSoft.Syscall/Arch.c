#include "Syscall.inl"

#define SYSCALL_NT_VER(Major, Minor, Build) ((ULONG)((((Major) & 0xFF) << 24) | (((Minor) & 0xFF) << 16) | ((Build) & 0xFFFF)))

EXTERN_C VOID Syscall_Proc_Fast(VOID);
#if defined(_M_X64)
EXTERN_C VOID Syscall_Proc_Int2E(VOID);
#elif defined(_M_IX86)
EXTERN_C VOID Syscall_Proc_LE_Win7_WowTransition_X86(VOID);
#endif

PVOID Syscall_FastSystemCall = NULL; // aka KiFastSystemCall or Wow64SystemServiceCall

static ULONG g_NTVer = 0;
static PVOID g_Wow64Transition = NULL;

LOGICAL
Syscall_InitArch(VOID)
{
    g_NTVer = SYSCALL_NT_VER(SharedUserData->NtMajorVersion,
                             SharedUserData->NtMinorVersion,
                             SharedUserData->NtBuildNumber);
    g_Wow64Transition = (PVOID*)NtReadTebPVOID(WOW32Reserved);

    if (g_Wow64Transition == NULL)
    {
        Syscall_FastSystemCall = &Syscall_Proc_Fast;
        /* Win11 and above, int 2E can be enabled */
#if defined(_M_X64)
        if (g_NTVer >= SYSCALL_NT_VER(10, 0, 22000) && SharedUserData->SystemCall)
        {
            Syscall_FastSystemCall = &Syscall_Proc_Int2E;
        }
#endif
    } else
    {
#if defined(_M_IX86)
        if (g_NTVer >= SYSCALL_NT_VER(6, 2, 0))
        {
            /* Win8 and above */
            Syscall_FastSystemCall = g_Wow64Transition;
        } else
        {
            Syscall_FastSystemCall = &Syscall_Proc_LE_Win7_WowTransition_X86;
        }
#endif
    }

    return Syscall_FastSystemCall != NULL;
}

_Success_(return != FALSE)
BOOL
Syscall_GetSSNFromFunction(
    _In_ PVOID Function,
    _Out_ PULONG SSN)
{
#if defined(_M_X64)
    if (*(PULONG)Function == 0xB8D18B4C)
    {
        /*
         * All Windows x64:
         *
         * 4C:8BD1      mov r10, rcx
         * B8 ????????  mov eax, (i32, SSN)
         */
        *SSN = *(PULONG)Add2Ptr(Function, 4);
        return TRUE;
    }
#elif defined(_M_IX86)
    if (*(PUCHAR)Function == 0xB8)
    {
        /*
         * All Windows x86:
         *
         * B8 ????????  mov eax, (i32, SSN)
         */
        *SSN = *(PULONG)Add2Ptr(Function, 1);
        return TRUE;
    }
#endif
    return FALSE;
}
