#include "Syscall.inl"

#if defined(_M_X64)
EXTERN_C PVOID Syscall_Proc_GE_Win11_X64;
EXTERN_C PVOID Syscall_Proc_Int2E_GE_Win11_X64;
#elif defined(_M_IX86)
EXTERN_C PVOID Syscall_Proc_X86;
EXTERN_C PVOID Syscall_Proc_LE_Win7_WowTransition_X86;
#endif

PVOID Syscall_Proc = NULL;

static PVOID g_Wow64Transition = NULL;

LOGICAL
Syscall_InitArch(VOID)
{
    g_Wow64Transition = NtReadTebPVOID(WOW32Reserved);

    if (g_Wow64Transition == NULL)
    {
#if defined(_M_X64)

        if (SharedUserData->NtMajorVersion > 10 ||
            SharedUserData->NtMajorVersion == 10 && SharedUserData->NtBuildNumber >= 22000)
        {
            /* Win11 and above */
            Syscall_Proc = !SharedUserData->SystemCall ? &Syscall_Proc_GE_Win11_X64 : &Syscall_Proc_Int2E_GE_Win11_X64;
        }

#elif defined(_M_IX86)

        Syscall_Proc = &Syscall_Proc_X86;

#endif
    } else
    {
        Syscall_Proc = g_Wow64Transition;
#if defined(_M_IX86)
        if (SharedUserData->NtMajorVersion < 6 ||
            (SharedUserData->NtMajorVersion == 6 && SharedUserData->NtMinorVersion <= 1))
        {
            Syscall_Proc = &Syscall_Proc_LE_Win7_WowTransition_X86;
        }
#endif
    }

    return Syscall_Proc != NULL;
}

_Success_(return != FALSE)
BOOL
Syscall_GetSSNFromFunction_X64(
    _In_ PVOID Function,
    _Out_ PULONG SSN)
{
    if (*(PULONG)Function == 0xB8D18B4C &&                          // 4C:8BD1              mov r10, rcx
                                                                    // B8 ????????          mov eax, (i32)
        *(PULONGLONG)Add2Ptr(Function, 8) == 0x017FFE03082504F6 &&  // F60425 0803FE7F 01   test byte ptr [7FFE0308h], 1
        *(PULONGLONG)Add2Ptr(Function, 16) == 0xC32ECDC3050F0375    // 75 03                jne +3
                                                                    // 0F05                 syscall
                                                                    // C3                   ret
                                                                    // CD 2E                int 2Eh
                                                                    // C3                   ret
        )
    {
        *SSN = *(PULONG)Add2Ptr(Function, 4);
        return TRUE;
    }

    return FALSE;
}

_Success_(return != FALSE)
BOOL
Syscall_GetSSNFromFunction_X86_WOW(
    _In_ PVOID Function,
    _Out_ PULONG SSN,
    _Out_opt_ PUSHORT RetSize)
{
    if (*(PBYTE)Function == 0xB8 &&             // B8 ????????  mov eax, (i32)
        *(PBYTE)Add2Ptr(Function, 5) == 0xBA && // BA ????????  mov edx, (&Wow64SystemServiceCall)
        *(PWORD)Add2Ptr(Function, 10) == 0xD2FF // FFD2         call edx
        )
    {
        if (*(PBYTE)Add2Ptr(Function, 12) == 0xC2)
        {
            /* C2 ????  ret (i16) */
            if (RetSize != NULL)
            {
                *RetSize = *(PUSHORT)Add2Ptr(Function, 13);
            }
        } else if (*(PBYTE)Add2Ptr(Function, 12) == 0xC3)
        {
            /* C3       retn */
            if (RetSize != NULL)
            {
                *RetSize = 0;
            }
        } else
        {
            return FALSE;
        }
        *SSN = *(PULONG)Add2Ptr(Function, 1);
        return TRUE;
    }

    return FALSE;
}

_Success_(return != FALSE)
BOOL
Syscall_GetSSNFromFunction(
    _In_ PVOID Function,
    _Out_ PULONG SSN)
{
    BOOL Ret = FALSE;

#if defined(_M_X64)
    if (g_Wow64Transition == NULL)
    {
        Ret = Syscall_GetSSNFromFunction_X64(Function, SSN);
    }
#elif defined(_M_IX86)
    if (g_Wow64Transition != NULL)
    {
        Ret = Syscall_GetSSNFromFunction_X86_WOW(Function, SSN, NULL);
    }
#endif

    return Ret;
}
