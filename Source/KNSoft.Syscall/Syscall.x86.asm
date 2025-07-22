INCLUDE Syscall.inc

.CODE

ASSUME fs:NOTHING

$PUBLIC_LABEL _Syscall_Proc_Fast
    ALIGN 16
    mov edx, esp
    sysenter
    retn

$PUBLIC_LABEL _Syscall_Proc_LE_Win7_WowTransition_X86
    ALIGN 16
    xor ecx, ecx
    lea edx, [esp + 8]
    call dword ptr fs:[0C0h]
    retn

END
