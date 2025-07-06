include KNSoft\NDK\Assembly\Header.inc
include KNSoft\NDK\Assembly\NDK.inc

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

EXTERN Syscall_Proc:SIZE_T

$SYSCALL_SSN MACRO Name:REQ

    EXTERN @CatStr(<Syscall_ThunkData_>, <Name>, <:DWORD>)
    EXITM <@CatStr(<Syscall_ThunkData_>, <Name>)>

ENDM

IFDEF _M_X64

$SYSCALL MACRO Name:REQ, ArgCount

    LOCAL FuncName
    FuncName CATSTR <Syscall_>, <Name>

    ALIGN 16
    FuncName PROC PUBLIC

    mov eax, $SYSCALL_SSN(Name)
    jmp [Syscall_Proc]

    FuncName ENDP

ENDM

ELSEIFDEF _M_IX86

$SYSCALL MACRO Name:REQ, ArgCount:REQ

    LOCAL ArgSize, FuncName
    ArgSize = ArgCount * 4
    FuncName CATSTR <Syscall_>, <Name>, <@>, %(ArgSize)

    ALIGN 16
    FuncName PROC C PUBLIC

    mov eax, $SYSCALL_SSN(Name)
    call [Syscall_Proc]
    ret ArgSize

    FuncName ENDP

ENDM

ENDIF
