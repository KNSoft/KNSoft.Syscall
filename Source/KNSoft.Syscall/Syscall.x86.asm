INCLUDE Syscall.inc

.CODE

ASSUME fs:NOTHING

; FIXME / WIP
$PUBLIC_LABEL Syscall_Proc_Not_Found
    ALIGN 16
    shr eax, 7
    and eax, 011111b
    shl eax, 2
    add esp, eax
    mov eax, 0C000007Ah ; STATUS_PROCEDURE_NOT_FOUND
    retn

; FIXME / WIP
$PUBLIC_LABEL Syscall_Proc_Not_Supported
    ALIGN 16
    shr eax, 7
    and eax, 011111b
    shl eax, 2
    add esp, eax
    mov eax, 0C00000BBh ; STATUS_NOT_SUPPORTED
    retn

$PUBLIC_LABEL Syscall_Proc_X86
    ALIGN 16
    mov edx, esp
    sysenter
    retn

$PUBLIC_LABEL Syscall_Proc_LE_Win7_WowTransition_X86
    ALIGN 16
    xor ecx, ecx
    lea edx, [esp + 8]
    call dword ptr fs:[0C0h]
    retn

END
