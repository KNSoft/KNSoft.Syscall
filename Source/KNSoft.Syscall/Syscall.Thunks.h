#pragma once

#include <KNSoft/NDK/NDK.h>

EXTERN_C_START

typedef
NTSTATUS
NTAPI
FN_ScAcceptConnectPort(
    _Out_ PHANDLE PortHandle,
    _In_opt_ PVOID PortContext,
    _In_ PPORT_MESSAGE ConnectionRequest,
    _In_ BOOLEAN AcceptConnection,
    _Inout_opt_ PPORT_VIEW ServerView,
    _Out_opt_ PREMOTE_PORT_VIEW ClientView
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAcceptConnectPort* volatile ScAcceptConnectPort;

typedef
NTSTATUS
NTAPI
FN_ScAccessCheck(
    _In_ PSECURITY_DESCRIPTOR SecurityDescriptor,
    _In_ HANDLE ClientToken,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PGENERIC_MAPPING GenericMapping,
    _Out_writes_bytes_(*PrivilegeSetLength) PPRIVILEGE_SET PrivilegeSet,
    _Inout_ PULONG PrivilegeSetLength,
    _Out_ PACCESS_MASK GrantedAccess,
    _Out_ PNTSTATUS AccessStatus
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAccessCheck* volatile ScAccessCheck;

typedef
NTSTATUS
NTAPI
FN_ScAccessCheckAndAuditAlarm(
    _In_ PUNICODE_STRING SubsystemName,
    _In_opt_ PVOID HandleId,
    _In_ PUNICODE_STRING ObjectTypeName,
    _In_ PUNICODE_STRING ObjectName,
    _In_ PSECURITY_DESCRIPTOR SecurityDescriptor,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PGENERIC_MAPPING GenericMapping,
    _In_ BOOLEAN ObjectCreation,
    _Out_ PACCESS_MASK GrantedAccess,
    _Out_ PNTSTATUS AccessStatus,
    _Out_ PBOOLEAN GenerateOnClose
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAccessCheckAndAuditAlarm* volatile ScAccessCheckAndAuditAlarm;

typedef
NTSTATUS
NTAPI
FN_ScAccessCheckByType(
    _In_ PSECURITY_DESCRIPTOR SecurityDescriptor,
    _In_opt_ PSID PrincipalSelfSid,
    _In_ HANDLE ClientToken,
    _In_ ACCESS_MASK DesiredAccess,
    _In_reads_(ObjectTypeListLength) POBJECT_TYPE_LIST ObjectTypeList,
    _In_ ULONG ObjectTypeListLength,
    _In_ PGENERIC_MAPPING GenericMapping,
    _Out_writes_bytes_(*PrivilegeSetLength) PPRIVILEGE_SET PrivilegeSet,
    _Inout_ PULONG PrivilegeSetLength,
    _Out_ PACCESS_MASK GrantedAccess,
    _Out_ PNTSTATUS AccessStatus
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAccessCheckByType* volatile ScAccessCheckByType;

typedef
NTSTATUS
NTAPI
FN_ScAccessCheckByTypeAndAuditAlarm(
    _In_ PUNICODE_STRING SubsystemName,
    _In_opt_ PVOID HandleId,
    _In_ PUNICODE_STRING ObjectTypeName,
    _In_ PUNICODE_STRING ObjectName,
    _In_ PSECURITY_DESCRIPTOR SecurityDescriptor,
    _In_opt_ PSID PrincipalSelfSid,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ AUDIT_EVENT_TYPE AuditType,
    _In_ ULONG Flags,
    _In_reads_opt_(ObjectTypeListLength) POBJECT_TYPE_LIST ObjectTypeList,
    _In_ ULONG ObjectTypeListLength,
    _In_ PGENERIC_MAPPING GenericMapping,
    _In_ BOOLEAN ObjectCreation,
    _Out_ PACCESS_MASK GrantedAccess,
    _Out_ PNTSTATUS AccessStatus,
    _Out_ PBOOLEAN GenerateOnClose
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAccessCheckByTypeAndAuditAlarm* volatile ScAccessCheckByTypeAndAuditAlarm;

typedef
NTSTATUS
NTAPI
FN_ScAccessCheckByTypeResultList(
    _In_ PSECURITY_DESCRIPTOR SecurityDescriptor,
    _In_opt_ PSID PrincipalSelfSid,
    _In_ HANDLE ClientToken,
    _In_ ACCESS_MASK DesiredAccess,
    _In_reads_(ObjectTypeListLength) POBJECT_TYPE_LIST ObjectTypeList,
    _In_ ULONG ObjectTypeListLength,
    _In_ PGENERIC_MAPPING GenericMapping,
    _Out_writes_bytes_(*PrivilegeSetLength) PPRIVILEGE_SET PrivilegeSet,
    _Inout_ PULONG PrivilegeSetLength,
    _Out_writes_(ObjectTypeListLength) PACCESS_MASK GrantedAccess,
    _Out_writes_(ObjectTypeListLength) PNTSTATUS AccessStatus
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAccessCheckByTypeResultList* volatile ScAccessCheckByTypeResultList;

typedef
NTSTATUS
NTAPI
FN_ScAccessCheckByTypeResultListAndAuditAlarm(
    _In_ PUNICODE_STRING SubsystemName,
    _In_opt_ PVOID HandleId,
    _In_ PUNICODE_STRING ObjectTypeName,
    _In_ PUNICODE_STRING ObjectName,
    _In_ PSECURITY_DESCRIPTOR SecurityDescriptor,
    _In_opt_ PSID PrincipalSelfSid,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ AUDIT_EVENT_TYPE AuditType,
    _In_ ULONG Flags,
    _In_reads_opt_(ObjectTypeListLength) POBJECT_TYPE_LIST ObjectTypeList,
    _In_ ULONG ObjectTypeListLength,
    _In_ PGENERIC_MAPPING GenericMapping,
    _In_ BOOLEAN ObjectCreation,
    _Out_writes_(ObjectTypeListLength) PACCESS_MASK GrantedAccess,
    _Out_writes_(ObjectTypeListLength) PNTSTATUS AccessStatus,
    _Out_ PBOOLEAN GenerateOnClose
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAccessCheckByTypeResultListAndAuditAlarm* volatile ScAccessCheckByTypeResultListAndAuditAlarm;

typedef
NTSTATUS
NTAPI
FN_ScAccessCheckByTypeResultListAndAuditAlarmByHandle(
    _In_ PUNICODE_STRING SubsystemName,
    _In_opt_ PVOID HandleId,
    _In_ HANDLE ClientToken,
    _In_ PUNICODE_STRING ObjectTypeName,
    _In_ PUNICODE_STRING ObjectName,
    _In_ PSECURITY_DESCRIPTOR SecurityDescriptor,
    _In_opt_ PSID PrincipalSelfSid,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ AUDIT_EVENT_TYPE AuditType,
    _In_ ULONG Flags,
    _In_reads_opt_(ObjectTypeListLength) POBJECT_TYPE_LIST ObjectTypeList,
    _In_ ULONG ObjectTypeListLength,
    _In_ PGENERIC_MAPPING GenericMapping,
    _In_ BOOLEAN ObjectCreation,
    _Out_writes_(ObjectTypeListLength) PACCESS_MASK GrantedAccess,
    _Out_writes_(ObjectTypeListLength) PNTSTATUS AccessStatus,
    _Out_ PBOOLEAN GenerateOnClose
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAccessCheckByTypeResultListAndAuditAlarmByHandle* volatile ScAccessCheckByTypeResultListAndAuditAlarmByHandle;

typedef
NTSTATUS
NTAPI
FN_ScAcquireCrossVmMutant(
    _In_ HANDLE CrossVmMutant,
    _In_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAcquireCrossVmMutant* volatile ScAcquireCrossVmMutant;

typedef
NTSTATUS
NTAPI
FN_ScAcquireProcessActivityReference(
    _Out_ PHANDLE ActivityReferenceHandle,
    _In_ HANDLE ParentProcessHandle,
    _In_ PROCESS_ACTIVITY_TYPE ProcessActivityType
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAcquireProcessActivityReference* volatile ScAcquireProcessActivityReference;

typedef
NTSTATUS
NTAPI
FN_ScAddAtom(
    _In_reads_bytes_opt_(Length) PCWSTR AtomName,
    _In_ ULONG Length,
    _Out_opt_ PRTL_ATOM Atom
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAddAtom* volatile ScAddAtom;

typedef
NTSTATUS
NTAPI
FN_ScAddAtomEx(
    _In_reads_bytes_opt_(Length) PCWSTR AtomName,
    _In_ ULONG Length,
    _Out_opt_ PRTL_ATOM Atom,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAddAtomEx* volatile ScAddAtomEx;

typedef
NTSTATUS
NTAPI
FN_ScAddBootEntry(
    _In_ PBOOT_ENTRY BootEntry,
    _Out_opt_ PULONG Id
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAddBootEntry* volatile ScAddBootEntry;

typedef
NTSTATUS
NTAPI
FN_ScAddDriverEntry(
    _In_ PEFI_DRIVER_ENTRY DriverEntry,
    _Out_opt_ PULONG Id
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAddDriverEntry* volatile ScAddDriverEntry;

typedef
NTSTATUS
NTAPI
FN_ScAdjustGroupsToken(
    _In_ HANDLE TokenHandle,
    _In_ BOOLEAN ResetToDefault,
    _In_opt_ PTOKEN_GROUPS NewState,
    _In_opt_ ULONG BufferLength,
    _Out_writes_bytes_to_opt_(BufferLength, *ReturnLength) PTOKEN_GROUPS PreviousState,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAdjustGroupsToken* volatile ScAdjustGroupsToken;

typedef
NTSTATUS
NTAPI
FN_ScAdjustPrivilegesToken(
    _In_ HANDLE TokenHandle,
    _In_ BOOLEAN DisableAllPrivileges,
    _In_opt_ PTOKEN_PRIVILEGES NewState,
    _In_ ULONG BufferLength,
    _Out_writes_bytes_to_opt_(BufferLength, *ReturnLength) PTOKEN_PRIVILEGES PreviousState,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAdjustPrivilegesToken* volatile ScAdjustPrivilegesToken;

typedef
NTSTATUS
NTAPI
FN_ScAdjustTokenClaimsAndDeviceGroups(
    _In_ HANDLE TokenHandle,
    _In_ BOOLEAN UserResetToDefault,
    _In_ BOOLEAN DeviceResetToDefault,
    _In_ BOOLEAN DeviceGroupsResetToDefault,
    _In_opt_ PTOKEN_SECURITY_ATTRIBUTES_INFORMATION NewUserState,
    _In_opt_ PTOKEN_SECURITY_ATTRIBUTES_INFORMATION NewDeviceState,
    _In_opt_ PTOKEN_GROUPS NewDeviceGroupsState,
    _In_ ULONG UserBufferLength,
    _Out_writes_bytes_to_opt_(UserBufferLength, *UserReturnLength) PTOKEN_SECURITY_ATTRIBUTES_INFORMATION PreviousUserState,
    _In_ ULONG DeviceBufferLength,
    _Out_writes_bytes_to_opt_(DeviceBufferLength, *DeviceReturnLength) PTOKEN_SECURITY_ATTRIBUTES_INFORMATION PreviousDeviceState,
    _In_ ULONG DeviceGroupsBufferLength,
    _Out_writes_bytes_to_opt_(DeviceGroupsBufferLength, *DeviceGroupsReturnBufferLength) PTOKEN_GROUPS PreviousDeviceGroups,
    _Out_opt_ PULONG UserReturnLength,
    _Out_opt_ PULONG DeviceReturnLength,
    _Out_opt_ PULONG DeviceGroupsReturnBufferLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAdjustTokenClaimsAndDeviceGroups* volatile ScAdjustTokenClaimsAndDeviceGroups;

typedef
NTSTATUS
NTAPI
FN_ScAlertResumeThread(
    _In_ HANDLE ThreadHandle,
    _Out_opt_ PULONG PreviousSuspendCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlertResumeThread* volatile ScAlertResumeThread;

typedef
NTSTATUS
NTAPI
FN_ScAlertThread(
    _In_ HANDLE ThreadHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlertThread* volatile ScAlertThread;

typedef
NTSTATUS
NTAPI
FN_ScAlertThreadByThreadId(
    _In_ HANDLE ThreadId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlertThreadByThreadId* volatile ScAlertThreadByThreadId;

typedef
NTSTATUS
NTAPI
FN_ScAlertThreadByThreadIdEx(
    _In_ HANDLE ThreadId,
    _In_opt_ PRTL_SRWLOCK Lock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlertThreadByThreadIdEx* volatile ScAlertThreadByThreadIdEx;

typedef
NTSTATUS
NTAPI
FN_ScAllocateLocallyUniqueId(
    _Out_ PLUID Luid
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAllocateLocallyUniqueId* volatile ScAllocateLocallyUniqueId;

typedef
NTSTATUS
NTAPI
FN_ScAllocateReserveObject(
    _Out_ PHANDLE MemoryReserveHandle,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ MEMORY_RESERVE_TYPE Type
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAllocateReserveObject* volatile ScAllocateReserveObject;

typedef
NTSTATUS
NTAPI
FN_ScAllocateUserPhysicalPages(
    _In_ HANDLE ProcessHandle,
    _Inout_ PSIZE_T NumberOfPages,
    _Out_writes_(*NumberOfPages) PULONG_PTR UserPfnArray
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAllocateUserPhysicalPages* volatile ScAllocateUserPhysicalPages;

typedef
NTSTATUS
NTAPI
FN_ScAllocateUserPhysicalPagesEx(
    _In_ HANDLE ProcessHandle,
    _Inout_ PULONG_PTR NumberOfPages,
    _Out_writes_(*NumberOfPages) PULONG_PTR UserPfnArray,
    _Inout_updates_opt_(ExtendedParameterCount) PMEM_EXTENDED_PARAMETER ExtendedParameters,
    _In_ ULONG ExtendedParameterCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAllocateUserPhysicalPagesEx* volatile ScAllocateUserPhysicalPagesEx;

typedef
NTSTATUS
NTAPI
FN_ScAllocateUuids(
    _Out_ PULARGE_INTEGER Time,
    _Out_ PULONG Range,
    _Out_ PULONG Sequence,
    _Out_ PCHAR Seed
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAllocateUuids* volatile ScAllocateUuids;

typedef
NTSTATUS
NTAPI
FN_ScAllocateVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _Inout_ _At_(*BaseAddress, _Readable_bytes_(*RegionSize) _Writable_bytes_(*RegionSize) _Post_readable_byte_size_(*RegionSize)) PVOID *BaseAddress,
    _In_ ULONG_PTR ZeroBits,
    _Inout_ PSIZE_T RegionSize,
    _In_ ULONG AllocationType,
    _In_ ULONG PageProtection
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAllocateVirtualMemory* volatile ScAllocateVirtualMemory;

typedef
NTSTATUS
NTAPI
FN_ScAllocateVirtualMemoryEx(
    _In_ HANDLE ProcessHandle,
    _Inout_ _At_(*BaseAddress, _Readable_bytes_(*RegionSize) _Writable_bytes_(*RegionSize) _Post_readable_byte_size_(*RegionSize)) PVOID *BaseAddress,
    _Inout_ PSIZE_T RegionSize,
    _In_ ULONG AllocationType,
    _In_ ULONG PageProtection,
    _Inout_updates_opt_(ExtendedParameterCount) PMEM_EXTENDED_PARAMETER ExtendedParameters,
    _In_ ULONG ExtendedParameterCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAllocateVirtualMemoryEx* volatile ScAllocateVirtualMemoryEx;

typedef
NTSTATUS
NTAPI
FN_ScAlpcAcceptConnectPort(
    _Out_ PHANDLE PortHandle,
    _In_ HANDLE ConnectionPortHandle,
    _In_ ULONG Flags,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ PALPC_PORT_ATTRIBUTES PortAttributes,
    _In_opt_ PVOID PortContext,
    _In_reads_bytes_(ConnectionRequest->u1.s1.TotalLength) PPORT_MESSAGE ConnectionRequest,
    _Inout_opt_ PALPC_MESSAGE_ATTRIBUTES ConnectionMessageAttributes,
    _In_ BOOLEAN AcceptConnection
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcAcceptConnectPort* volatile ScAlpcAcceptConnectPort;

typedef
NTSTATUS
NTAPI
FN_ScAlpcCancelMessage(
    _In_ HANDLE PortHandle,
    _In_ ULONG Flags,
    _In_ PALPC_CONTEXT_ATTR MessageContext
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcCancelMessage* volatile ScAlpcCancelMessage;

typedef
NTSTATUS
NTAPI
FN_ScAlpcConnectPort(
    _Out_ PHANDLE PortHandle,
    _In_ PUNICODE_STRING PortName,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ PALPC_PORT_ATTRIBUTES PortAttributes,
    _In_ ULONG Flags,
    _In_opt_ PSID RequiredServerSid,
    _Inout_updates_bytes_to_opt_(*BufferLength, *BufferLength) PPORT_MESSAGE ConnectionMessage,
    _Inout_opt_ PSIZE_T BufferLength,
    _Inout_opt_ PALPC_MESSAGE_ATTRIBUTES OutMessageAttributes,
    _Inout_opt_ PALPC_MESSAGE_ATTRIBUTES InMessageAttributes,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcConnectPort* volatile ScAlpcConnectPort;

typedef
NTSTATUS
NTAPI
FN_ScAlpcConnectPortEx(
    _Out_ PHANDLE PortHandle,
    _In_ POBJECT_ATTRIBUTES ConnectionPortObjectAttributes,
    _In_opt_ POBJECT_ATTRIBUTES ClientPortObjectAttributes,
    _In_opt_ PALPC_PORT_ATTRIBUTES PortAttributes,
    _In_ ULONG Flags,
    _In_opt_ PSECURITY_DESCRIPTOR ServerSecurityRequirements,
    _Inout_updates_bytes_to_opt_(*BufferLength, *BufferLength) PPORT_MESSAGE ConnectionMessage,
    _Inout_opt_ PSIZE_T BufferLength,
    _Inout_opt_ PALPC_MESSAGE_ATTRIBUTES OutMessageAttributes,
    _Inout_opt_ PALPC_MESSAGE_ATTRIBUTES InMessageAttributes,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcConnectPortEx* volatile ScAlpcConnectPortEx;

typedef
NTSTATUS
NTAPI
FN_ScAlpcCreatePort(
    _Out_ PHANDLE PortHandle,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ PALPC_PORT_ATTRIBUTES PortAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcCreatePort* volatile ScAlpcCreatePort;

typedef
NTSTATUS
NTAPI
FN_ScAlpcCreatePortSection(
    _In_ HANDLE PortHandle,
    _In_ ULONG Flags,
    _In_opt_ HANDLE SectionHandle,
    _In_ SIZE_T SectionSize,
    _Out_ PALPC_HANDLE AlpcSectionHandle,
    _Out_ PSIZE_T ActualSectionSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcCreatePortSection* volatile ScAlpcCreatePortSection;

typedef
NTSTATUS
NTAPI
FN_ScAlpcCreateResourceReserve(
    _In_ HANDLE PortHandle,
    _Reserved_ ULONG Flags,
    _In_ SIZE_T MessageSize,
    _Out_ PALPC_HANDLE ResourceId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcCreateResourceReserve* volatile ScAlpcCreateResourceReserve;

typedef
NTSTATUS
NTAPI
FN_ScAlpcCreateSectionView(
    _In_ HANDLE PortHandle,
    _Reserved_ ULONG Flags,
    _Inout_ PALPC_DATA_VIEW_ATTR ViewAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcCreateSectionView* volatile ScAlpcCreateSectionView;

typedef
NTSTATUS
NTAPI
FN_ScAlpcCreateSecurityContext(
    _In_ HANDLE PortHandle,
    _Reserved_ ULONG Flags,
    _Inout_ PALPC_SECURITY_ATTR SecurityAttribute
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcCreateSecurityContext* volatile ScAlpcCreateSecurityContext;

typedef
NTSTATUS
NTAPI
FN_ScAlpcDeletePortSection(
    _In_ HANDLE PortHandle,
    _Reserved_ ULONG Flags,
    _In_ ALPC_HANDLE SectionHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcDeletePortSection* volatile ScAlpcDeletePortSection;

typedef
NTSTATUS
NTAPI
FN_ScAlpcDeleteResourceReserve(
    _In_ HANDLE PortHandle,
    _Reserved_ ULONG Flags,
    _In_ ALPC_HANDLE ResourceId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcDeleteResourceReserve* volatile ScAlpcDeleteResourceReserve;

typedef
NTSTATUS
NTAPI
FN_ScAlpcDeleteSectionView(
    _In_ HANDLE PortHandle,
    _Reserved_ ULONG Flags,
    _In_ PVOID ViewBase
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcDeleteSectionView* volatile ScAlpcDeleteSectionView;

typedef
NTSTATUS
NTAPI
FN_ScAlpcDeleteSecurityContext(
    _In_ HANDLE PortHandle,
    _Reserved_ ULONG Flags,
    _In_ ALPC_HANDLE ContextHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcDeleteSecurityContext* volatile ScAlpcDeleteSecurityContext;

typedef
NTSTATUS
NTAPI
FN_ScAlpcDisconnectPort(
    _In_ HANDLE PortHandle,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcDisconnectPort* volatile ScAlpcDisconnectPort;

typedef
NTSTATUS
NTAPI
FN_ScAlpcImpersonateClientContainerOfPort(
    _In_ HANDLE PortHandle,
    _In_ PPORT_MESSAGE Message,
    _Reserved_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcImpersonateClientContainerOfPort* volatile ScAlpcImpersonateClientContainerOfPort;

typedef
NTSTATUS
NTAPI
FN_ScAlpcImpersonateClientOfPort(
    _In_ HANDLE PortHandle,
    _In_ PPORT_MESSAGE Message,
    _In_ PVOID Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcImpersonateClientOfPort* volatile ScAlpcImpersonateClientOfPort;

typedef
NTSTATUS
NTAPI
FN_ScAlpcOpenSenderProcess(
    _Out_ PHANDLE ProcessHandle,
    _In_ HANDLE PortHandle,
    _In_ PPORT_MESSAGE PortMessage,
    _Reserved_ ULONG Flags,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcOpenSenderProcess* volatile ScAlpcOpenSenderProcess;

typedef
NTSTATUS
NTAPI
FN_ScAlpcOpenSenderThread(
    _Out_ PHANDLE ThreadHandle,
    _In_ HANDLE PortHandle,
    _In_ PPORT_MESSAGE PortMessage,
    _Reserved_ ULONG Flags,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcOpenSenderThread* volatile ScAlpcOpenSenderThread;

typedef
NTSTATUS
NTAPI
FN_ScAlpcQueryInformation(
    _In_opt_ HANDLE PortHandle,
    _In_ ALPC_PORT_INFORMATION_CLASS PortInformationClass,
    _Inout_updates_bytes_to_(Length, *ReturnLength) PVOID PortInformation,
    _In_ ULONG Length,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcQueryInformation* volatile ScAlpcQueryInformation;

typedef
NTSTATUS
NTAPI
FN_ScAlpcQueryInformationMessage(
    _In_ HANDLE PortHandle,
    _In_ PPORT_MESSAGE PortMessage,
    _In_ ALPC_MESSAGE_INFORMATION_CLASS MessageInformationClass,
    _Out_writes_bytes_to_opt_(Length, *ReturnLength) PVOID MessageInformation,
    _In_ ULONG Length,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcQueryInformationMessage* volatile ScAlpcQueryInformationMessage;

typedef
NTSTATUS
NTAPI
FN_ScAlpcRevokeSecurityContext(
    _In_ HANDLE PortHandle,
    _Reserved_ ULONG Flags,
    _In_ ALPC_HANDLE ContextHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcRevokeSecurityContext* volatile ScAlpcRevokeSecurityContext;

typedef
NTSTATUS
NTAPI
FN_ScAlpcSendWaitReceivePort(
    _In_ HANDLE PortHandle,
    _In_ ULONG Flags,
    _In_reads_bytes_opt_(SendMessage->u1.s1.TotalLength) PPORT_MESSAGE SendMessage,
    _Inout_opt_ PALPC_MESSAGE_ATTRIBUTES SendMessageAttributes,
    _Out_writes_bytes_to_opt_(*BufferLength, *BufferLength) PPORT_MESSAGE ReceiveMessage,
    _Inout_opt_ PSIZE_T BufferLength,
    _Inout_opt_ PALPC_MESSAGE_ATTRIBUTES ReceiveMessageAttributes,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcSendWaitReceivePort* volatile ScAlpcSendWaitReceivePort;

typedef
NTSTATUS
NTAPI
FN_ScAlpcSetInformation(
    _In_ HANDLE PortHandle,
    _In_ ALPC_PORT_INFORMATION_CLASS PortInformationClass,
    _In_reads_bytes_opt_(Length) PVOID PortInformation,
    _In_ ULONG Length
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAlpcSetInformation* volatile ScAlpcSetInformation;

typedef
NTSTATUS
NTAPI
FN_ScApphelpCacheControl(
    _In_ ULONG ServiceClass,
    _Inout_opt_ PVOID ServiceContext // AHC_SERVICE_DATA
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScApphelpCacheControl* volatile ScApphelpCacheControl;

typedef
NTSTATUS
NTAPI
FN_ScAreMappedFilesTheSame(
    _In_ PVOID File1MappedAsAnImage,
    _In_ PVOID File2MappedAsFile
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAreMappedFilesTheSame* volatile ScAreMappedFilesTheSame;

typedef
NTSTATUS
NTAPI
FN_ScAssignProcessToJobObject(
    _In_ HANDLE JobHandle,
    _In_ HANDLE ProcessHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAssignProcessToJobObject* volatile ScAssignProcessToJobObject;

typedef
NTSTATUS
NTAPI
FN_ScAssociateWaitCompletionPacket(
    _In_ HANDLE WaitCompletionPacketHandle,
    _In_ HANDLE IoCompletionHandle,
    _In_ HANDLE TargetObjectHandle,
    _In_opt_ PVOID KeyContext,
    _In_opt_ PVOID ApcContext,
    _In_ NTSTATUS IoStatus,
    _In_ ULONG_PTR IoStatusInformation,
    _Out_opt_ PBOOLEAN AlreadySignaled
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScAssociateWaitCompletionPacket* volatile ScAssociateWaitCompletionPacket;

typedef
NTSTATUS
NTAPI
FN_ScCallbackReturn(
    _In_reads_bytes_opt_(OutputLength) PVOID OutputBuffer,
    _In_ ULONG OutputLength,
    _In_ NTSTATUS Status
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCallbackReturn* volatile ScCallbackReturn;

typedef
NTSTATUS
NTAPI
FN_ScCallEnclave(
    _In_ PENCLAVE_ROUTINE Routine,
    _In_ PVOID Reserved,              // SelectVsmEnclaveByNumber > 0 // reserved for dispatch (RtlEnclaveCallDispatch)
    _In_ ULONG Flags,                 // ENCLAVE_CALL_FLAG_*
    _Inout_ PVOID* RoutineParamReturn // input routine parameter, output routine return value
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCallEnclave* volatile ScCallEnclave;

typedef
NTSTATUS
NTAPI
FN_ScCancelIoFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCancelIoFile* volatile ScCancelIoFile;

typedef
NTSTATUS
NTAPI
FN_ScCancelIoFileEx(
    _In_ HANDLE FileHandle,
    _In_opt_ PIO_STATUS_BLOCK IoRequestToCancel,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCancelIoFileEx* volatile ScCancelIoFileEx;

typedef
NTSTATUS
NTAPI
FN_ScCancelSynchronousIoFile(
    _In_ HANDLE ThreadHandle,
    _In_opt_ PIO_STATUS_BLOCK IoRequestToCancel,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCancelSynchronousIoFile* volatile ScCancelSynchronousIoFile;

typedef
NTSTATUS
NTAPI
FN_ScCancelTimer(
    _In_ HANDLE TimerHandle,
    _Out_opt_ PBOOLEAN CurrentState
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCancelTimer* volatile ScCancelTimer;

typedef
NTSTATUS
NTAPI
FN_ScCancelTimer2(
    _In_ HANDLE TimerHandle,
    _In_ PT2_CANCEL_PARAMETERS Parameters
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCancelTimer2* volatile ScCancelTimer2;

typedef
NTSTATUS
NTAPI
FN_ScCancelWaitCompletionPacket(
    _In_ HANDLE WaitCompletionPacketHandle,
    _In_ BOOLEAN RemoveSignaledPacket
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCancelWaitCompletionPacket* volatile ScCancelWaitCompletionPacket;

typedef
NTSTATUS
NTAPI
FN_ScChangeProcessState(
    _In_ HANDLE ProcessStateChangeHandle,
    _In_ HANDLE ProcessHandle,
    _In_ PROCESS_STATE_CHANGE_TYPE StateChangeType,
    _In_opt_ _Reserved_ PVOID ExtendedInformation,
    _In_opt_ _Reserved_ SIZE_T ExtendedInformationLength,
    _In_opt_ _Reserved_ ULONG Reserved
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScChangeProcessState* volatile ScChangeProcessState;

typedef
NTSTATUS
NTAPI
FN_ScChangeThreadState(
    _In_ HANDLE ThreadStateChangeHandle,
    _In_ HANDLE ThreadHandle,
    _In_ THREAD_STATE_CHANGE_TYPE StateChangeType,
    _In_opt_ PVOID ExtendedInformation,
    _In_opt_ SIZE_T ExtendedInformationLength,
    _In_opt_ ULONG Reserved
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScChangeThreadState* volatile ScChangeThreadState;

typedef
NTSTATUS
NTAPI
FN_ScClearEvent(
    _In_ HANDLE EventHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScClearEvent* volatile ScClearEvent;

typedef
NTSTATUS
NTAPI
FN_ScClose(
    _In_ _Post_ptr_invalid_ HANDLE Handle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScClose* volatile ScClose;

typedef
NTSTATUS
NTAPI
FN_ScCloseObjectAuditAlarm(
    _In_ PUNICODE_STRING SubsystemName,
    _In_opt_ PVOID HandleId,
    _In_ BOOLEAN GenerateOnClose
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCloseObjectAuditAlarm* volatile ScCloseObjectAuditAlarm;

typedef
NTSTATUS
NTAPI
FN_ScCommitComplete(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCommitComplete* volatile ScCommitComplete;

typedef
NTSTATUS
NTAPI
FN_ScCommitEnlistment(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCommitEnlistment* volatile ScCommitEnlistment;

typedef
NTSTATUS
NTAPI
FN_ScCommitRegistryTransaction(
    _In_ HANDLE RegistryTransactionHandle,
    _Reserved_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCommitRegistryTransaction* volatile ScCommitRegistryTransaction;

typedef
NTSTATUS
NTAPI
FN_ScCommitTransaction(
    _In_ HANDLE TransactionHandle,
    _In_ BOOLEAN Wait
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCommitTransaction* volatile ScCommitTransaction;

typedef
NTSTATUS
NTAPI
FN_ScCompactKeys(
    _In_ ULONG Count,
    _In_reads_(Count) HANDLE KeyArray[]
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCompactKeys* volatile ScCompactKeys;

typedef
NTSTATUS
NTAPI
FN_ScCompareObjects(
    _In_ HANDLE FirstObjectHandle,
    _In_ HANDLE SecondObjectHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCompareObjects* volatile ScCompareObjects;

typedef
NTSTATUS
NTAPI
FN_ScCompareSigningLevels(
    _In_ SE_SIGNING_LEVEL FirstSigningLevel,
    _In_ SE_SIGNING_LEVEL SecondSigningLevel
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCompareSigningLevels* volatile ScCompareSigningLevels;

typedef
NTSTATUS
NTAPI
FN_ScCompareTokens(
    _In_ HANDLE FirstTokenHandle,
    _In_ HANDLE SecondTokenHandle,
    _Out_ PBOOLEAN Equal
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCompareTokens* volatile ScCompareTokens;

typedef
NTSTATUS
NTAPI
FN_ScCompleteConnectPort(
    _In_ HANDLE PortHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCompleteConnectPort* volatile ScCompleteConnectPort;

typedef
NTSTATUS
NTAPI
FN_ScCompressKey(
    _In_ HANDLE KeyHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCompressKey* volatile ScCompressKey;

typedef
NTSTATUS
NTAPI
FN_ScConnectPort(
    _Out_ PHANDLE PortHandle,
    _In_ PUNICODE_STRING PortName,
    _In_ PSECURITY_QUALITY_OF_SERVICE SecurityQos,
    _Inout_opt_ PPORT_VIEW ClientView,
    _Inout_opt_ PREMOTE_PORT_VIEW ServerView,
    _Out_opt_ PULONG MaxMessageLength,
    _Inout_updates_bytes_to_opt_(*ConnectionInformationLength, *ConnectionInformationLength) PVOID ConnectionInformation,
    _Inout_opt_ PULONG ConnectionInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScConnectPort* volatile ScConnectPort;

typedef
NTSTATUS
NTAPI
FN_ScContinue(
    _In_ PCONTEXT ContextRecord,
    _In_ BOOLEAN TestAlert
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScContinue* volatile ScContinue;

typedef
NTSTATUS
NTAPI
FN_ScContinueEx(
    _In_ PCONTEXT ContextRecord,
    _In_ PVOID ContinueArgument // PKCONTINUE_ARGUMENT and BOOLEAN are valid
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScContinueEx* volatile ScContinueEx;

typedef
NTSTATUS
NTAPI
FN_ScConvertBetweenAuxiliaryCounterAndPerformanceCounter(
    _In_ BOOLEAN ConvertAuxiliaryToPerformanceCounter,
    _In_ PULONG64 PerformanceOrAuxiliaryCounterValue,
    _Out_ PULONG64 ConvertedValue,
    _Out_opt_ PULONG64 ConversionError
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScConvertBetweenAuxiliaryCounterAndPerformanceCounter* volatile ScConvertBetweenAuxiliaryCounterAndPerformanceCounter;

typedef
NTSTATUS
NTAPI
FN_ScCopyFileChunk(
    _In_ HANDLE SourceHandle,
    _In_ HANDLE DestinationHandle,
    _In_opt_ HANDLE EventHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ ULONG Length,
    _In_ PLARGE_INTEGER SourceOffset,
    _In_ PLARGE_INTEGER DestOffset,
    _In_opt_ PULONG SourceKey,
    _In_opt_ PULONG DestKey,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCopyFileChunk* volatile ScCopyFileChunk;

typedef
NTSTATUS
NTAPI
FN_ScCreateCrossVmEvent(
    _Out_ PHANDLE CrossVmEvent,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ULONG CrossVmEventFlags,
    _In_ LPCGUID VMID,
    _In_ LPCGUID ServiceID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateCrossVmEvent* volatile ScCreateCrossVmEvent;

typedef
NTSTATUS
NTAPI
FN_ScCreateCrossVmMutant(
    _Out_ PHANDLE EventHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ULONG CrossVmEventFlags,
    _In_ LPCGUID VMID,
    _In_ LPCGUID ServiceID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateCrossVmMutant* volatile ScCreateCrossVmMutant;

typedef
NTSTATUS
NTAPI
FN_ScCreateDebugObject(
    _Out_ PHANDLE DebugObjectHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateDebugObject* volatile ScCreateDebugObject;

typedef
NTSTATUS
NTAPI
FN_ScCreateDirectoryObject(
    _Out_ PHANDLE DirectoryHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateDirectoryObject* volatile ScCreateDirectoryObject;

typedef
NTSTATUS
NTAPI
FN_ScCreateDirectoryObjectEx(
    _Out_ PHANDLE DirectoryHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ HANDLE ShadowDirectoryHandle,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateDirectoryObjectEx* volatile ScCreateDirectoryObjectEx;

typedef
NTSTATUS
NTAPI
FN_ScCreateEnclave(
    _In_ HANDLE ProcessHandle,
    _Inout_ PVOID* BaseAddress,
    _In_ ULONG_PTR ZeroBits,
    _In_ SIZE_T Size,
    _In_ SIZE_T InitialCommitment,
    _In_ ULONG EnclaveType,
    _In_reads_bytes_(EnclaveInformationLength) PVOID EnclaveInformation,
    _In_ ULONG EnclaveInformationLength,
    _Out_opt_ PULONG EnclaveError
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateEnclave* volatile ScCreateEnclave;

typedef
NTSTATUS
NTAPI
FN_ScCreateEnlistment(
    _Out_ PHANDLE EnlistmentHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ HANDLE ResourceManagerHandle,
    _In_ HANDLE TransactionHandle,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ ULONG CreateOptions,
    _In_ NOTIFICATION_MASK NotificationMask,
    _In_opt_ PVOID EnlistmentKey
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateEnlistment* volatile ScCreateEnlistment;

typedef
NTSTATUS
NTAPI
FN_ScCreateEvent(
    _Out_ PHANDLE EventHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ EVENT_TYPE EventType,
    _In_ BOOLEAN InitialState
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateEvent* volatile ScCreateEvent;

typedef
NTSTATUS
NTAPI
FN_ScCreateEventPair(
    _Out_ PHANDLE EventPairHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateEventPair* volatile ScCreateEventPair;

typedef
NTSTATUS
NTAPI
FN_ScCreateFile(
    _Out_ PHANDLE FileHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_opt_ PLARGE_INTEGER AllocationSize,
    _In_ ULONG FileAttributes,
    _In_ ULONG ShareAccess,
    _In_ ULONG CreateDisposition,
    _In_ ULONG CreateOptions,
    _In_reads_bytes_opt_(EaLength) PVOID EaBuffer,
    _In_ ULONG EaLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateFile* volatile ScCreateFile;

typedef
NTSTATUS
NTAPI
FN_ScCreateIoCompletion(
    _Out_ PHANDLE IoCompletionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ ULONG Count
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateIoCompletion* volatile ScCreateIoCompletion;

typedef
NTSTATUS
NTAPI
FN_ScCreateIoRing(
    _Out_ PHANDLE IoRingHandle,
    _In_ ULONG CreateParametersLength,
    _In_ PVOID CreateParameters,
    _In_ ULONG OutputParametersLength,
    _Out_ PVOID OutputParameters
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateIoRing* volatile ScCreateIoRing;

typedef
NTSTATUS
NTAPI
FN_ScCreateIRTimer(
    _Out_ PHANDLE TimerHandle,
    _In_ PVOID Reserved,
    _In_ ACCESS_MASK DesiredAccess
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateIRTimer* volatile ScCreateIRTimer;

typedef
NTSTATUS
NTAPI
FN_ScCreateJobObject(
    _Out_ PHANDLE JobHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateJobObject* volatile ScCreateJobObject;

typedef
NTSTATUS
NTAPI
FN_ScCreateJobSet(
    _In_ ULONG NumJob,
    _In_reads_(NumJob) PJOB_SET_ARRAY UserJobSet,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateJobSet* volatile ScCreateJobSet;

typedef
NTSTATUS
NTAPI
FN_ScCreateKey(
    _Out_ PHANDLE KeyHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _Reserved_ ULONG TitleIndex,
    _In_opt_ PUNICODE_STRING Class,
    _In_ ULONG CreateOptions,
    _Out_opt_ PULONG Disposition
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateKey* volatile ScCreateKey;

typedef
NTSTATUS
NTAPI
FN_ScCreateKeyedEvent(
    _Out_ PHANDLE KeyedEventHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _Reserved_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateKeyedEvent* volatile ScCreateKeyedEvent;

typedef
NTSTATUS
NTAPI
FN_ScCreateKeyTransacted(
    _Out_ PHANDLE KeyHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _Reserved_ ULONG TitleIndex,
    _In_opt_ PUNICODE_STRING Class,
    _In_ ULONG CreateOptions,
    _In_ HANDLE TransactionHandle,
    _Out_opt_ PULONG Disposition
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateKeyTransacted* volatile ScCreateKeyTransacted;

typedef
NTSTATUS
NTAPI
FN_ScCreateLowBoxToken(
    _Out_ PHANDLE TokenHandle,
    _In_ HANDLE ExistingTokenHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ PSID PackageSid,
    _In_ ULONG CapabilityCount,
    _In_reads_opt_(CapabilityCount) PSID_AND_ATTRIBUTES Capabilities,
    _In_ ULONG HandleCount,
    _In_reads_opt_(HandleCount) HANDLE *Handles
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateLowBoxToken* volatile ScCreateLowBoxToken;

typedef
NTSTATUS
NTAPI
FN_ScCreateMailslotFile(
    _Out_ PHANDLE FileHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ ULONG CreateOptions,
    _In_ ULONG MailslotQuota,
    _In_ ULONG MaximumMessageSize,
    _In_ PLARGE_INTEGER ReadTimeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateMailslotFile* volatile ScCreateMailslotFile;

typedef
NTSTATUS
NTAPI
FN_ScCreateMutant(
    _Out_ PHANDLE MutantHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ BOOLEAN InitialOwner
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateMutant* volatile ScCreateMutant;

typedef
NTSTATUS
NTAPI
FN_ScCreateNamedPipeFile(
    _Out_ PHANDLE FileHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ ULONG ShareAccess,
    _In_ ULONG CreateDisposition,
    _In_ ULONG CreateOptions,
    _In_ ULONG NamedPipeType,
    _In_ ULONG ReadMode,
    _In_ ULONG CompletionMode,
    _In_ ULONG MaximumInstances,
    _In_ ULONG InboundQuota,
    _In_ ULONG OutboundQuota,
    _In_ PLARGE_INTEGER DefaultTimeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateNamedPipeFile* volatile ScCreateNamedPipeFile;

typedef
NTSTATUS
NTAPI
FN_ScCreatePagingFile(
    _In_ PUNICODE_STRING PageFileName,
    _In_ PLARGE_INTEGER MinimumSize,
    _In_ PLARGE_INTEGER MaximumSize,
    _In_ ULONG Priority
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreatePagingFile* volatile ScCreatePagingFile;

typedef
NTSTATUS
NTAPI
FN_ScCreatePartition(
    _In_opt_ HANDLE ParentPartitionHandle,
    _Out_ PHANDLE PartitionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ULONG PreferredNode
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreatePartition* volatile ScCreatePartition;

typedef
NTSTATUS
NTAPI
FN_ScCreatePort(
    _Out_ PHANDLE PortHandle,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ULONG MaxConnectionInfoLength,
    _In_ ULONG MaxMessageLength,
    _In_opt_ ULONG MaxPoolUsage
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreatePort* volatile ScCreatePort;

typedef
NTSTATUS
NTAPI
FN_ScCreatePrivateNamespace(
    _Out_ PHANDLE NamespaceHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ POBJECT_BOUNDARY_DESCRIPTOR BoundaryDescriptor
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreatePrivateNamespace* volatile ScCreatePrivateNamespace;

typedef
NTSTATUS
NTAPI
FN_ScCreateProcess(
    _Out_ PHANDLE ProcessHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ HANDLE ParentProcess,
    _In_ BOOLEAN InheritObjectTable,
    _In_opt_ HANDLE SectionHandle,
    _In_opt_ HANDLE DebugPort,
    _In_opt_ HANDLE TokenHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateProcess* volatile ScCreateProcess;

typedef
NTSTATUS
NTAPI
FN_ScCreateProcessEx(
    _Out_ PHANDLE ProcessHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ HANDLE ParentProcess,
    _In_ ULONG Flags, // PROCESS_CREATE_FLAGS_*
    _In_opt_ HANDLE SectionHandle,
    _In_opt_ HANDLE DebugPort,
    _In_opt_ HANDLE TokenHandle,
    _Reserved_ ULONG Reserved // JobMemberLevel
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateProcessEx* volatile ScCreateProcessEx;

typedef
NTSTATUS
NTAPI
FN_ScCreateProcessStateChange(
    _Out_ PHANDLE ProcessStateChangeHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ HANDLE ProcessHandle,
    _In_opt_ _Reserved_ ULONG Reserved
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateProcessStateChange* volatile ScCreateProcessStateChange;

typedef
NTSTATUS
NTAPI
FN_ScCreateProfile(
    _Out_ PHANDLE ProfileHandle,
    _In_opt_ HANDLE Process,
    _In_ PVOID ProfileBase,
    _In_ SIZE_T ProfileSize,
    _In_ ULONG BucketSize,
    _In_reads_bytes_(BufferSize) PULONG Buffer,
    _In_ ULONG BufferSize,
    _In_ KPROFILE_SOURCE ProfileSource,
    _In_ KAFFINITY Affinity
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateProfile* volatile ScCreateProfile;

typedef
NTSTATUS
NTAPI
FN_ScCreateProfileEx(
    _Out_ PHANDLE ProfileHandle,
    _In_opt_ HANDLE Process,
    _In_ PVOID ProfileBase,
    _In_ SIZE_T ProfileSize,
    _In_ ULONG BucketSize,
    _In_reads_bytes_(BufferSize) PULONG Buffer,
    _In_ ULONG BufferSize,
    _In_ KPROFILE_SOURCE ProfileSource,
    _In_ USHORT GroupCount,
    _In_reads_(GroupCount) PGROUP_AFFINITY GroupAffinity
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateProfileEx* volatile ScCreateProfileEx;

typedef
NTSTATUS
NTAPI
FN_ScCreateRegistryTransaction(
    _Out_ PHANDLE RegistryTransactionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjAttributes,
    _Reserved_ ULONG CreateOptions
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateRegistryTransaction* volatile ScCreateRegistryTransaction;

typedef
NTSTATUS
NTAPI
FN_ScCreateResourceManager(
    _Out_ PHANDLE ResourceManagerHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ HANDLE TmHandle,
    _In_ LPGUID RmGuid,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ ULONG CreateOptions,
    _In_opt_ PUNICODE_STRING Description
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateResourceManager* volatile ScCreateResourceManager;

typedef
NTSTATUS
NTAPI
FN_ScCreateSection(
    _Out_ PHANDLE SectionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ PLARGE_INTEGER MaximumSize,
    _In_ ULONG SectionPageProtection,
    _In_ ULONG AllocationAttributes,
    _In_opt_ HANDLE FileHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateSection* volatile ScCreateSection;

typedef
NTSTATUS
NTAPI
FN_ScCreateSectionEx(
    _Out_ PHANDLE SectionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ PLARGE_INTEGER MaximumSize,
    _In_ ULONG SectionPageProtection,
    _In_ ULONG AllocationAttributes,
    _In_opt_ HANDLE FileHandle,
    _Inout_updates_opt_(ExtendedParameterCount) PMEM_EXTENDED_PARAMETER ExtendedParameters,
    _In_ ULONG ExtendedParameterCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateSectionEx* volatile ScCreateSectionEx;

typedef
NTSTATUS
NTAPI
FN_ScCreateSemaphore(
    _Out_ PHANDLE SemaphoreHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ LONG InitialCount,
    _In_ LONG MaximumCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateSemaphore* volatile ScCreateSemaphore;

typedef
NTSTATUS
NTAPI
FN_ScCreateSymbolicLinkObject(
    _Out_ PHANDLE LinkHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ PUNICODE_STRING LinkTarget
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateSymbolicLinkObject* volatile ScCreateSymbolicLinkObject;

typedef
NTSTATUS
NTAPI
FN_ScCreateThread(
    _Out_ PHANDLE ThreadHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ HANDLE ProcessHandle,
    _Out_ PCLIENT_ID ClientId,
    _In_ PCONTEXT ThreadContext,
    _In_ PINITIAL_TEB InitialTeb,
    _In_ BOOLEAN CreateSuspended
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateThread* volatile ScCreateThread;

typedef
NTSTATUS
NTAPI
FN_ScCreateThreadEx(
    _Out_ PHANDLE ThreadHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ HANDLE ProcessHandle,
    _In_ PUSER_THREAD_START_ROUTINE StartRoutine,
    _In_opt_ PVOID Argument,
    _In_ ULONG CreateFlags, // THREAD_CREATE_FLAGS_*
    _In_ SIZE_T ZeroBits,
    _In_ SIZE_T StackSize,
    _In_ SIZE_T MaximumStackSize,
    _In_opt_ PPS_ATTRIBUTE_LIST AttributeList
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateThreadEx* volatile ScCreateThreadEx;

typedef
NTSTATUS
NTAPI
FN_ScCreateThreadStateChange(
    _Out_ PHANDLE ThreadStateChangeHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ HANDLE ThreadHandle,
    _In_opt_ _Reserved_ ULONG Reserved
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateThreadStateChange* volatile ScCreateThreadStateChange;

typedef
NTSTATUS
NTAPI
FN_ScCreateTimer(
    _Out_ PHANDLE TimerHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ TIMER_TYPE TimerType
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateTimer* volatile ScCreateTimer;

typedef
NTSTATUS
NTAPI
FN_ScCreateTimer2(
    _Out_ PHANDLE TimerHandle,
    _In_opt_ PVOID Reserved1,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ULONG Attributes, // TIMER_TYPE
    _In_ ACCESS_MASK DesiredAccess
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateTimer2* volatile ScCreateTimer2;

typedef
NTSTATUS
NTAPI
FN_ScCreateToken(
    _Out_ PHANDLE TokenHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ TOKEN_TYPE Type,
    _In_ PLUID AuthenticationId,
    _In_ PLARGE_INTEGER ExpirationTime,
    _In_ PTOKEN_USER User,
    _In_ PTOKEN_GROUPS Groups,
    _In_ PTOKEN_PRIVILEGES Privileges,
    _In_opt_ PTOKEN_OWNER Owner,
    _In_ PTOKEN_PRIMARY_GROUP PrimaryGroup,
    _In_opt_ PTOKEN_DEFAULT_DACL DefaultDacl,
    _In_ PTOKEN_SOURCE Source
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateToken* volatile ScCreateToken;

typedef
NTSTATUS
NTAPI
FN_ScCreateTokenEx(
    _Out_ PHANDLE TokenHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ TOKEN_TYPE Type,
    _In_ PLUID AuthenticationId,
    _In_ PLARGE_INTEGER ExpirationTime,
    _In_ PTOKEN_USER User,
    _In_ PTOKEN_GROUPS Groups,
    _In_ PTOKEN_PRIVILEGES Privileges,
    _In_opt_ PTOKEN_SECURITY_ATTRIBUTES_INFORMATION UserAttributes,
    _In_opt_ PTOKEN_SECURITY_ATTRIBUTES_INFORMATION DeviceAttributes,
    _In_opt_ PTOKEN_GROUPS DeviceGroups,
    _In_opt_ PTOKEN_MANDATORY_POLICY MandatoryPolicy,
    _In_opt_ PTOKEN_OWNER Owner,
    _In_ PTOKEN_PRIMARY_GROUP PrimaryGroup,
    _In_opt_ PTOKEN_DEFAULT_DACL DefaultDacl,
    _In_ PTOKEN_SOURCE Source
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateTokenEx* volatile ScCreateTokenEx;

typedef
NTSTATUS
NTAPI
FN_ScCreateTransaction(
    _Out_ PHANDLE TransactionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ LPGUID Uow,
    _In_opt_ HANDLE TmHandle,
    _In_opt_ ULONG CreateOptions,
    _In_opt_ ULONG IsolationLevel,
    _In_opt_ ULONG IsolationFlags,
    _In_opt_ PLARGE_INTEGER Timeout,
    _In_opt_ PUNICODE_STRING Description
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateTransaction* volatile ScCreateTransaction;

typedef
NTSTATUS
NTAPI
FN_ScCreateTransactionManager(
    _Out_ PHANDLE TmHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ PUNICODE_STRING LogFileName,
    _In_opt_ ULONG CreateOptions,
    _In_opt_ ULONG CommitStrength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateTransactionManager* volatile ScCreateTransactionManager;

typedef
NTSTATUS
NTAPI
FN_ScCreateUserProcess(
    _Out_ PHANDLE ProcessHandle,
    _Out_ PHANDLE ThreadHandle,
    _In_ ACCESS_MASK ProcessDesiredAccess,
    _In_ ACCESS_MASK ThreadDesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ProcessObjectAttributes,
    _In_opt_ PCOBJECT_ATTRIBUTES ThreadObjectAttributes,
    _In_ ULONG ProcessFlags, // PROCESS_CREATE_FLAGS_*
    _In_ ULONG ThreadFlags, // THREAD_CREATE_FLAGS_*
    _In_opt_ PRTL_USER_PROCESS_PARAMETERS ProcessParameters,
    _Inout_ PPS_CREATE_INFO CreateInfo,
    _In_opt_ PPS_ATTRIBUTE_LIST AttributeList
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateUserProcess* volatile ScCreateUserProcess;

typedef
NTSTATUS
NTAPI
FN_ScCreateWaitablePort(
    _Out_ PHANDLE PortHandle,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ULONG MaxConnectionInfoLength,
    _In_ ULONG MaxMessageLength,
    _In_opt_ ULONG MaxPoolUsage
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateWaitablePort* volatile ScCreateWaitablePort;

typedef
NTSTATUS
NTAPI
FN_ScCreateWaitCompletionPacket(
    _Out_ PHANDLE WaitCompletionPacketHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateWaitCompletionPacket* volatile ScCreateWaitCompletionPacket;

typedef
NTSTATUS
NTAPI
FN_ScCreateWnfStateName(
    _Out_ PWNF_STATE_NAME StateName,
    _In_ WNF_STATE_NAME_LIFETIME NameLifetime,
    _In_ WNF_DATA_SCOPE DataScope,
    _In_ BOOLEAN PersistData,
    _In_opt_ PCWNF_TYPE_ID TypeId,
    _In_ ULONG MaximumStateSize,
    _In_ PSECURITY_DESCRIPTOR SecurityDescriptor
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateWnfStateName* volatile ScCreateWnfStateName;

typedef
NTSTATUS
NTAPI
FN_ScCreateWorkerFactory(
    _Out_ PHANDLE WorkerFactoryHandleReturn,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ HANDLE CompletionPortHandle,
    _In_ HANDLE WorkerProcessHandle,
    _In_ PVOID StartRoutine,
    _In_opt_ PVOID StartParameter,
    _In_opt_ ULONG MaxThreadCount,
    _In_opt_ SIZE_T StackReserve,
    _In_opt_ SIZE_T StackCommit
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScCreateWorkerFactory* volatile ScCreateWorkerFactory;

typedef
NTSTATUS
NTAPI
FN_ScDebugActiveProcess(
    _In_ HANDLE ProcessHandle,
    _In_ HANDLE DebugObjectHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDebugActiveProcess* volatile ScDebugActiveProcess;

typedef
NTSTATUS
NTAPI
FN_ScDebugContinue(
    _In_ HANDLE DebugObjectHandle,
    _In_ PCLIENT_ID ClientId,
    _In_ NTSTATUS ContinueStatus
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDebugContinue* volatile ScDebugContinue;

typedef
NTSTATUS
NTAPI
FN_ScDelayExecution(
    _In_ BOOLEAN Alertable,
    _In_ PLARGE_INTEGER DelayInterval
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDelayExecution* volatile ScDelayExecution;

typedef
NTSTATUS
NTAPI
FN_ScDeleteAtom(
    _In_ RTL_ATOM Atom
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeleteAtom* volatile ScDeleteAtom;

typedef
NTSTATUS
NTAPI
FN_ScDeleteBootEntry(
    _In_ ULONG Id
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeleteBootEntry* volatile ScDeleteBootEntry;

typedef
NTSTATUS
NTAPI
FN_ScDeleteDriverEntry(
    _In_ ULONG Id
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeleteDriverEntry* volatile ScDeleteDriverEntry;

typedef
NTSTATUS
NTAPI
FN_ScDeleteFile(
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeleteFile* volatile ScDeleteFile;

typedef
NTSTATUS
NTAPI
FN_ScDeleteKey(
    _In_ HANDLE KeyHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeleteKey* volatile ScDeleteKey;

typedef
NTSTATUS
NTAPI
FN_ScDeleteObjectAuditAlarm(
    _In_ PUNICODE_STRING SubsystemName,
    _In_opt_ PVOID HandleId,
    _In_ BOOLEAN GenerateOnClose
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeleteObjectAuditAlarm* volatile ScDeleteObjectAuditAlarm;

typedef
NTSTATUS
NTAPI
FN_ScDeletePrivateNamespace(
    _In_ HANDLE NamespaceHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeletePrivateNamespace* volatile ScDeletePrivateNamespace;

typedef
NTSTATUS
NTAPI
FN_ScDeleteValueKey(
    _In_ HANDLE KeyHandle,
    _In_ PUNICODE_STRING ValueName
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeleteValueKey* volatile ScDeleteValueKey;

typedef
NTSTATUS
NTAPI
FN_ScDeleteWnfStateData(
    _In_ PCWNF_STATE_NAME StateName,
    _In_opt_ const VOID* ExplicitScope
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeleteWnfStateData* volatile ScDeleteWnfStateData;

typedef
NTSTATUS
NTAPI
FN_ScDeleteWnfStateName(
    _In_ PCWNF_STATE_NAME StateName
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeleteWnfStateName* volatile ScDeleteWnfStateName;

typedef
NTSTATUS
NTAPI
FN_ScDeviceIoControlFile(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ ULONG IoControlCode,
    _In_reads_bytes_opt_(InputBufferLength) PVOID InputBuffer,
    _In_ ULONG InputBufferLength,
    _Out_writes_bytes_opt_(OutputBufferLength) PVOID OutputBuffer,
    _In_ ULONG OutputBufferLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDeviceIoControlFile* volatile ScDeviceIoControlFile;

typedef
NTSTATUS
NTAPI
FN_ScDisableLastKnownGood(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDisableLastKnownGood* volatile ScDisableLastKnownGood;

typedef
NTSTATUS
NTAPI
FN_ScDisplayString(
    _In_ PUNICODE_STRING String
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDisplayString* volatile ScDisplayString;

typedef
NTSTATUS
NTAPI
FN_ScDrawText(
    _In_ PUNICODE_STRING Text
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDrawText* volatile ScDrawText;

typedef
NTSTATUS
NTAPI
FN_ScDuplicateObject(
    _In_ HANDLE SourceProcessHandle,
    _In_ HANDLE SourceHandle,
    _In_opt_ HANDLE TargetProcessHandle,
    _Out_opt_ PHANDLE TargetHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ ULONG HandleAttributes,
    _In_ ULONG Options
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDuplicateObject* volatile ScDuplicateObject;

typedef
NTSTATUS
NTAPI
FN_ScDuplicateToken(
    _In_ HANDLE ExistingTokenHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ BOOLEAN EffectiveOnly,
    _In_ TOKEN_TYPE Type,
    _Out_ PHANDLE NewTokenHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScDuplicateToken* volatile ScDuplicateToken;

typedef
NTSTATUS
NTAPI
FN_ScEnableLastKnownGood(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScEnableLastKnownGood* volatile ScEnableLastKnownGood;

typedef
NTSTATUS
NTAPI
FN_ScEnumerateBootEntries(
    _Out_writes_bytes_opt_(*BufferLength) PVOID Buffer,
    _Inout_ PULONG BufferLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScEnumerateBootEntries* volatile ScEnumerateBootEntries;

typedef
NTSTATUS
NTAPI
FN_ScEnumerateDriverEntries(
    _Out_writes_bytes_opt_(*BufferLength) PVOID Buffer,
    _Inout_ PULONG BufferLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScEnumerateDriverEntries* volatile ScEnumerateDriverEntries;

typedef
NTSTATUS
NTAPI
FN_ScEnumerateKey(
    _In_ HANDLE KeyHandle,
    _In_ ULONG Index,
    _In_ KEY_INFORMATION_CLASS KeyInformationClass,
    _Out_writes_bytes_to_opt_(Length, *ResultLength) PVOID KeyInformation,
    _In_ ULONG Length,
    _Out_ PULONG ResultLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScEnumerateKey* volatile ScEnumerateKey;

typedef
NTSTATUS
NTAPI
FN_ScEnumerateSystemEnvironmentValuesEx(
    _In_ ULONG InformationClass, // SYSTEM_ENVIRONMENT_INFORMATION_CLASS
    _Out_ PVOID Buffer,
    _Inout_ PULONG BufferLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScEnumerateSystemEnvironmentValuesEx* volatile ScEnumerateSystemEnvironmentValuesEx;

typedef
NTSTATUS
NTAPI
FN_ScEnumerateTransactionObject(
    _In_opt_ HANDLE RootObjectHandle,
    _In_ KTMOBJECT_TYPE QueryType,
    _Inout_updates_bytes_(ObjectCursorLength) PKTMOBJECT_CURSOR ObjectCursor,
    _In_ ULONG ObjectCursorLength,
    _Out_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScEnumerateTransactionObject* volatile ScEnumerateTransactionObject;

typedef
NTSTATUS
NTAPI
FN_ScEnumerateValueKey(
    _In_ HANDLE KeyHandle,
    _In_ ULONG Index,
    _In_ KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
    _Out_writes_bytes_to_opt_(Length, *ResultLength) PVOID KeyValueInformation,
    _In_ ULONG Length,
    _Out_ PULONG ResultLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScEnumerateValueKey* volatile ScEnumerateValueKey;

typedef
NTSTATUS
NTAPI
FN_ScExtendSection(
    _In_ HANDLE SectionHandle,
    _Inout_ PLARGE_INTEGER NewSectionSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScExtendSection* volatile ScExtendSection;

typedef
NTSTATUS
NTAPI
FN_ScFilterBootOption(
    _In_ FILTER_BOOT_OPTION_OPERATION FilterOperation,
    _In_ ULONG ObjectType,
    _In_ ULONG ElementType,
    _In_reads_bytes_opt_(DataSize) PVOID Data,
    _In_ ULONG DataSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFilterBootOption* volatile ScFilterBootOption;

typedef
NTSTATUS
NTAPI
FN_ScFilterToken(
    _In_ HANDLE ExistingTokenHandle,
    _In_ ULONG Flags,
    _In_opt_ PTOKEN_GROUPS SidsToDisable,
    _In_opt_ PTOKEN_PRIVILEGES PrivilegesToDelete,
    _In_opt_ PTOKEN_GROUPS RestrictedSids,
    _Out_ PHANDLE NewTokenHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFilterToken* volatile ScFilterToken;

typedef
NTSTATUS
NTAPI
FN_ScFilterTokenEx(
    _In_ HANDLE ExistingTokenHandle,
    _In_ ULONG Flags,
    _In_opt_ PTOKEN_GROUPS SidsToDisable,
    _In_opt_ PTOKEN_PRIVILEGES PrivilegesToDelete,
    _In_opt_ PTOKEN_GROUPS RestrictedSids,
    _In_ ULONG DisableUserClaimsCount,
    _In_opt_ PUNICODE_STRING UserClaimsToDisable,
    _In_ ULONG DisableDeviceClaimsCount,
    _In_opt_ PUNICODE_STRING DeviceClaimsToDisable,
    _In_opt_ PTOKEN_GROUPS DeviceGroupsToDisable,
    _In_opt_ PTOKEN_SECURITY_ATTRIBUTES_INFORMATION RestrictedUserAttributes,
    _In_opt_ PTOKEN_SECURITY_ATTRIBUTES_INFORMATION RestrictedDeviceAttributes,
    _In_opt_ PTOKEN_GROUPS RestrictedDeviceGroups,
    _Out_ PHANDLE NewTokenHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFilterTokenEx* volatile ScFilterTokenEx;

typedef
NTSTATUS
NTAPI
FN_ScFindAtom(
    _In_reads_bytes_opt_(Length) PCWSTR AtomName,
    _In_ ULONG Length,
    _Out_opt_ PRTL_ATOM Atom
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFindAtom* volatile ScFindAtom;

typedef
NTSTATUS
NTAPI
FN_ScFlushBuffersFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFlushBuffersFile* volatile ScFlushBuffersFile;

typedef
NTSTATUS
NTAPI
FN_ScFlushBuffersFileEx(
    _In_ HANDLE FileHandle,
    _In_ ULONG Flags,
    _In_reads_bytes_(ParametersSize) PVOID Parameters,
    _In_ ULONG ParametersSize,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFlushBuffersFileEx* volatile ScFlushBuffersFileEx;

typedef
NTSTATUS
NTAPI
FN_ScFlushInstallUILanguage(
    _In_ LANGID InstallUILanguage,
    _In_ ULONG SetComittedFlag
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFlushInstallUILanguage* volatile ScFlushInstallUILanguage;

typedef
NTSTATUS
NTAPI
FN_ScFlushInstructionCache(
    _In_ HANDLE ProcessHandle,
    _In_opt_ PVOID BaseAddress,
    _In_ SIZE_T RegionSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFlushInstructionCache* volatile ScFlushInstructionCache;

typedef
NTSTATUS
NTAPI
FN_ScFlushKey(
    _In_ HANDLE KeyHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFlushKey* volatile ScFlushKey;

typedef
NTSTATUS
NTAPI
FN_ScFlushProcessWriteBuffers(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFlushProcessWriteBuffers* volatile ScFlushProcessWriteBuffers;

typedef
NTSTATUS
NTAPI
FN_ScFlushVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _Inout_ PVOID *BaseAddress,
    _Inout_ PSIZE_T RegionSize,
    _Out_ PIO_STATUS_BLOCK IoStatus
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFlushVirtualMemory* volatile ScFlushVirtualMemory;

typedef
NTSTATUS
NTAPI
FN_ScFlushWriteBuffer(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFlushWriteBuffer* volatile ScFlushWriteBuffer;

typedef
NTSTATUS
NTAPI
FN_ScFreeUserPhysicalPages(
    _In_ HANDLE ProcessHandle,
    _Inout_ PULONG_PTR NumberOfPages,
    _In_reads_(*NumberOfPages) PULONG_PTR UserPfnArray
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFreeUserPhysicalPages* volatile ScFreeUserPhysicalPages;

typedef
NTSTATUS
NTAPI
FN_ScFreeVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _Inout_ __drv_freesMem(Mem) PVOID* BaseAddress,
    _Inout_ PSIZE_T RegionSize,
    _In_ ULONG FreeType
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFreeVirtualMemory* volatile ScFreeVirtualMemory;

typedef
NTSTATUS
NTAPI
FN_ScFreezeRegistry(
    _In_ ULONG TimeOutInSeconds
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFreezeRegistry* volatile ScFreezeRegistry;

typedef
NTSTATUS
NTAPI
FN_ScFreezeTransactions(
    _In_ PLARGE_INTEGER FreezeTimeout,
    _In_ PLARGE_INTEGER ThawTimeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFreezeTransactions* volatile ScFreezeTransactions;

typedef
NTSTATUS
NTAPI
FN_ScFsControlFile(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ ULONG FsControlCode,
    _In_reads_bytes_opt_(InputBufferLength) PVOID InputBuffer,
    _In_ ULONG InputBufferLength,
    _Out_writes_bytes_opt_(OutputBufferLength) PVOID OutputBuffer,
    _In_ ULONG OutputBufferLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScFsControlFile* volatile ScFsControlFile;

typedef
NTSTATUS
NTAPI
FN_ScGetCachedSigningLevel(
    _In_ HANDLE File,
    _Out_ PULONG Flags,
    _Out_ PSE_SIGNING_LEVEL SigningLevel,
    _Out_writes_bytes_to_opt_(*ThumbprintSize, *ThumbprintSize) PUCHAR Thumbprint,
    _Inout_opt_ PULONG ThumbprintSize,
    _Out_opt_ PULONG ThumbprintAlgorithm
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetCachedSigningLevel* volatile ScGetCachedSigningLevel;

typedef
NTSTATUS
NTAPI
FN_ScGetCompleteWnfStateSubscription(
    _In_opt_ PWNF_STATE_NAME OldDescriptorStateName,
    _In_opt_ ULONG64 *OldSubscriptionId,
    _In_opt_ ULONG OldDescriptorEventMask,
    _In_opt_ ULONG OldDescriptorStatus,
    _Out_writes_bytes_(DescriptorSize) PWNF_DELIVERY_DESCRIPTOR NewDeliveryDescriptor,
    _In_ ULONG DescriptorSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetCompleteWnfStateSubscription* volatile ScGetCompleteWnfStateSubscription;

typedef
NTSTATUS
NTAPI
FN_ScGetContextThread(
    _In_ HANDLE ThreadHandle,
    _Inout_ PCONTEXT ThreadContext
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetContextThread* volatile ScGetContextThread;

typedef
ULONG
NTAPI
FN_ScGetCurrentProcessorNumber(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetCurrentProcessorNumber* volatile ScGetCurrentProcessorNumber;

typedef
ULONG
NTAPI
FN_ScGetCurrentProcessorNumberEx(
    _Out_opt_ PPROCESSOR_NUMBER ProcessorNumber
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetCurrentProcessorNumberEx* volatile ScGetCurrentProcessorNumberEx;

typedef
NTSTATUS
NTAPI
FN_ScGetDevicePowerState(
    _In_ HANDLE Device,
    _Out_ PDEVICE_POWER_STATE State
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetDevicePowerState* volatile ScGetDevicePowerState;

typedef
NTSTATUS
NTAPI
FN_ScGetMUIRegistryInfo(
    _In_ ULONG Flags,
    _Inout_ PULONG DataSize,
    _Out_ PVOID Data
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetMUIRegistryInfo* volatile ScGetMUIRegistryInfo;

typedef
NTSTATUS
NTAPI
FN_ScGetNextProcess(
    _In_opt_ HANDLE ProcessHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ ULONG HandleAttributes,
    _In_ ULONG Flags,
    _Out_ PHANDLE NewProcessHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetNextProcess* volatile ScGetNextProcess;

typedef
NTSTATUS
NTAPI
FN_ScGetNextThread(
    _In_ HANDLE ProcessHandle,
    _In_opt_ HANDLE ThreadHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ ULONG HandleAttributes,
    _In_ ULONG Flags,
    _Out_ PHANDLE NewThreadHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetNextThread* volatile ScGetNextThread;

typedef
NTSTATUS
NTAPI
FN_ScGetNlsSectionPtr(
    _In_ ULONG SectionType,
    _In_ ULONG SectionData,
    _In_ PVOID ContextData,
    _Out_ PVOID *SectionPointer,
    _Out_ PULONG SectionSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetNlsSectionPtr* volatile ScGetNlsSectionPtr;

typedef
NTSTATUS
NTAPI
FN_ScGetNotificationResourceManager(
    _In_ HANDLE ResourceManagerHandle,
    _Out_ PTRANSACTION_NOTIFICATION TransactionNotification,
    _In_ ULONG NotificationLength,
    _In_opt_ PLARGE_INTEGER Timeout,
    _Out_opt_ PULONG ReturnLength,
    _In_ ULONG Asynchronous,
    _In_opt_ ULONG_PTR AsynchronousContext
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetNotificationResourceManager* volatile ScGetNotificationResourceManager;

typedef
NTSTATUS
NTAPI
FN_ScGetPlugPlayEvent(
    _In_ HANDLE EventHandle,
    _In_opt_ PVOID Context,
    _Out_writes_bytes_(EventBufferSize) PPLUGPLAY_EVENT_BLOCK EventBlock,
    _In_ ULONG EventBufferSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetPlugPlayEvent* volatile ScGetPlugPlayEvent;

typedef
NTSTATUS
NTAPI
FN_ScGetWriteWatch(
    _In_ HANDLE ProcessHandle,
    _In_ ULONG Flags,
    _In_ PVOID BaseAddress,
    _In_ SIZE_T RegionSize,
    _Out_writes_(*EntriesInUserAddressArray) PVOID *UserAddressArray,
    _Inout_ PULONG_PTR EntriesInUserAddressArray,
    _Out_ PULONG Granularity
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScGetWriteWatch* volatile ScGetWriteWatch;

typedef
NTSTATUS
NTAPI
FN_ScImpersonateAnonymousToken(
    _In_ HANDLE ThreadHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScImpersonateAnonymousToken* volatile ScImpersonateAnonymousToken;

typedef
NTSTATUS
NTAPI
FN_ScImpersonateClientOfPort(
    _In_ HANDLE PortHandle,
    _In_ PPORT_MESSAGE Message
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScImpersonateClientOfPort* volatile ScImpersonateClientOfPort;

typedef
NTSTATUS
NTAPI
FN_ScImpersonateThread(
    _In_ HANDLE ServerThreadHandle,
    _In_ HANDLE ClientThreadHandle,
    _In_ PSECURITY_QUALITY_OF_SERVICE SecurityQos
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScImpersonateThread* volatile ScImpersonateThread;

typedef
NTSTATUS
NTAPI
FN_ScInitializeEnclave(
    _In_ HANDLE ProcessHandle,
    _In_ PVOID BaseAddress,
    _In_reads_bytes_(EnclaveInformationLength) PVOID EnclaveInformation,
    _In_ ULONG EnclaveInformationLength,
    _Out_opt_ PULONG EnclaveError
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScInitializeEnclave* volatile ScInitializeEnclave;

typedef
NTSTATUS
NTAPI
FN_ScInitializeNlsFiles(
    _Out_ PVOID *BaseAddress,
    _Out_ PLCID DefaultLocaleId,
    _Out_ PLARGE_INTEGER DefaultCasingTableSize,
    _Out_opt_ PULONG CurrentNLSVersion
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScInitializeNlsFiles* volatile ScInitializeNlsFiles;

typedef
NTSTATUS
NTAPI
FN_ScInitializeRegistry(
    _In_ USHORT BootCondition
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScInitializeRegistry* volatile ScInitializeRegistry;

typedef
NTSTATUS
NTAPI
FN_ScInitiatePowerAction(
    _In_ POWER_ACTION SystemAction,
    _In_ SYSTEM_POWER_STATE LightestSystemState,
    _In_ ULONG Flags, // POWER_ACTION_* flags
    _In_ BOOLEAN Asynchronous
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScInitiatePowerAction* volatile ScInitiatePowerAction;

typedef
NTSTATUS
NTAPI
FN_ScIsProcessInJob(
    _In_ HANDLE ProcessHandle,
    _In_opt_ HANDLE JobHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScIsProcessInJob* volatile ScIsProcessInJob;

typedef
BOOLEAN
NTAPI
FN_ScIsSystemResumeAutomatic(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScIsSystemResumeAutomatic* volatile ScIsSystemResumeAutomatic;

typedef
NTSTATUS
NTAPI
FN_ScIsUILanguageComitted(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScIsUILanguageComitted* volatile ScIsUILanguageComitted;

typedef
NTSTATUS
NTAPI
FN_ScListenPort(
    _In_ HANDLE PortHandle,
    _Out_ PPORT_MESSAGE ConnectionRequest
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScListenPort* volatile ScListenPort;

typedef
NTSTATUS
NTAPI
FN_ScLoadDriver(
    _In_ PUNICODE_STRING DriverServiceName
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScLoadDriver* volatile ScLoadDriver;

typedef
NTSTATUS
NTAPI
FN_ScLoadEnclaveData(
    _In_ HANDLE ProcessHandle,
    _In_ PVOID BaseAddress,
    _In_reads_bytes_(BufferSize) PVOID Buffer,
    _In_ SIZE_T BufferSize,
    _In_ ULONG Protect,
    _In_reads_bytes_(PageInformationLength) PVOID PageInformation,
    _In_ ULONG PageInformationLength,
    _Out_opt_ PSIZE_T NumberOfBytesWritten,
    _Out_opt_ PULONG EnclaveError
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScLoadEnclaveData* volatile ScLoadEnclaveData;

typedef
NTSTATUS
NTAPI
FN_ScLoadKey(
    _In_ POBJECT_ATTRIBUTES TargetKey,
    _In_ POBJECT_ATTRIBUTES SourceFile
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScLoadKey* volatile ScLoadKey;

typedef
NTSTATUS
NTAPI
FN_ScLoadKey2(
    _In_ POBJECT_ATTRIBUTES TargetKey,
    _In_ POBJECT_ATTRIBUTES SourceFile,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScLoadKey2* volatile ScLoadKey2;

typedef
NTSTATUS
NTAPI
FN_ScLoadKey3(
    _In_ POBJECT_ATTRIBUTES TargetKey,
    _In_ POBJECT_ATTRIBUTES SourceFile,
    _In_ ULONG Flags,
    _In_reads_(ExtendedParameterCount) PCM_EXTENDED_PARAMETER ExtendedParameters,
    _In_ ULONG ExtendedParameterCount,
    _In_opt_ ACCESS_MASK DesiredAccess,
    _Out_opt_ PHANDLE RootHandle,
    _Reserved_ PVOID Reserved
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScLoadKey3* volatile ScLoadKey3;

typedef
NTSTATUS
NTAPI
FN_ScLoadKeyEx(
    _In_ POBJECT_ATTRIBUTES TargetKey,
    _In_ POBJECT_ATTRIBUTES SourceFile,
    _In_ ULONG Flags,
    _In_opt_ HANDLE TrustClassKey, // this and below were added on Win10
    _In_opt_ HANDLE Event,
    _In_opt_ ACCESS_MASK DesiredAccess,
    _Out_opt_ PHANDLE RootHandle,
    _Reserved_ PVOID Reserved // previously PIO_STATUS_BLOCK
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScLoadKeyEx* volatile ScLoadKeyEx;

typedef
NTSTATUS
NTAPI
FN_ScLockFile(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ PLARGE_INTEGER ByteOffset,
    _In_ PLARGE_INTEGER Length,
    _In_ ULONG Key,
    _In_ BOOLEAN FailImmediately,
    _In_ BOOLEAN ExclusiveLock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScLockFile* volatile ScLockFile;

typedef
NTSTATUS
NTAPI
FN_ScLockProductActivationKeys(
    _Inout_opt_ ULONG *pPrivateVer,
    _Out_opt_ ULONG *pSafeMode
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScLockProductActivationKeys* volatile ScLockProductActivationKeys;

typedef
NTSTATUS
NTAPI
FN_ScLockRegistryKey(
    _In_ HANDLE KeyHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScLockRegistryKey* volatile ScLockRegistryKey;

typedef
NTSTATUS
NTAPI
FN_ScLockVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _Inout_ PVOID *BaseAddress,
    _Inout_ PSIZE_T RegionSize,
    _In_ ULONG MapType
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScLockVirtualMemory* volatile ScLockVirtualMemory;

typedef
NTSTATUS
NTAPI
FN_ScMakePermanentObject(
    _In_ HANDLE Handle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScMakePermanentObject* volatile ScMakePermanentObject;

typedef
NTSTATUS
NTAPI
FN_ScMakeTemporaryObject(
    _In_ HANDLE Handle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScMakeTemporaryObject* volatile ScMakeTemporaryObject;

typedef
NTSTATUS
NTAPI
FN_ScManagePartition(
    _In_ HANDLE TargetHandle,
    _In_opt_ HANDLE SourceHandle,
    _In_ PARTITION_INFORMATION_CLASS PartitionInformationClass,
    _Inout_updates_bytes_(PartitionInformationLength) PVOID PartitionInformation,
    _In_ ULONG PartitionInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScManagePartition* volatile ScManagePartition;

typedef
NTSTATUS
NTAPI
FN_ScMapCMFModule(
    _In_ ULONG What,
    _In_ ULONG Index,
    _Out_opt_ PULONG CacheIndexOut,
    _Out_opt_ PULONG CacheFlagsOut,
    _Out_opt_ PULONG ViewSizeOut,
    _Out_opt_ PVOID *BaseAddress
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScMapCMFModule* volatile ScMapCMFModule;

typedef
NTSTATUS
NTAPI
FN_ScMapUserPhysicalPages(
    _In_ PVOID VirtualAddress,
    _In_ SIZE_T NumberOfPages,
    _In_reads_opt_(NumberOfPages) PULONG_PTR UserPfnArray
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScMapUserPhysicalPages* volatile ScMapUserPhysicalPages;

typedef
NTSTATUS
NTAPI
FN_ScMapUserPhysicalPagesScatter(
    _In_reads_(NumberOfPages) PVOID *VirtualAddresses,
    _In_ SIZE_T NumberOfPages,
    _In_reads_opt_(NumberOfPages) PULONG_PTR UserPfnArray
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScMapUserPhysicalPagesScatter* volatile ScMapUserPhysicalPagesScatter;

typedef
NTSTATUS
NTAPI
FN_ScMapViewOfSection(
    _In_ HANDLE SectionHandle,
    _In_ HANDLE ProcessHandle,
    _Inout_ _At_(*BaseAddress, _Readable_bytes_(*ViewSize) _Writable_bytes_(*ViewSize) _Post_readable_byte_size_(*ViewSize)) PVOID *BaseAddress,
    _In_ ULONG_PTR ZeroBits,
    _In_ SIZE_T CommitSize,
    _Inout_opt_ PLARGE_INTEGER SectionOffset,
    _Inout_ PSIZE_T ViewSize,
    _In_ SECTION_INHERIT InheritDisposition,
    _In_ ULONG AllocationType,
    _In_ ULONG PageProtection
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScMapViewOfSection* volatile ScMapViewOfSection;

typedef
NTSTATUS
NTAPI
FN_ScMapViewOfSectionEx(
    _In_ HANDLE SectionHandle,
    _In_ HANDLE ProcessHandle,
    _Inout_ _At_(*BaseAddress, _Readable_bytes_(*ViewSize) _Writable_bytes_(*ViewSize) _Post_readable_byte_size_(*ViewSize)) PVOID *BaseAddress,
    _Inout_opt_ PLARGE_INTEGER SectionOffset,
    _Inout_ PSIZE_T ViewSize,
    _In_ ULONG AllocationType,
    _In_ ULONG PageProtection,
    _Inout_updates_opt_(ExtendedParameterCount) PMEM_EXTENDED_PARAMETER ExtendedParameters,
    _In_ ULONG ExtendedParameterCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScMapViewOfSectionEx* volatile ScMapViewOfSectionEx;

typedef
NTSTATUS
NTAPI
FN_ScModifyBootEntry(
    _In_ PBOOT_ENTRY BootEntry
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScModifyBootEntry* volatile ScModifyBootEntry;

typedef
NTSTATUS
NTAPI
FN_ScModifyDriverEntry(
    _In_ PEFI_DRIVER_ENTRY DriverEntry
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScModifyDriverEntry* volatile ScModifyDriverEntry;

typedef
NTSTATUS
NTAPI
FN_ScNotifyChangeDirectoryFile(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _Out_writes_bytes_(Length) PVOID Buffer, // FILE_NOTIFY_INFORMATION
    _In_ ULONG Length,
    _In_ ULONG CompletionFilter,
    _In_ BOOLEAN WatchTree
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScNotifyChangeDirectoryFile* volatile ScNotifyChangeDirectoryFile;

typedef
NTSTATUS
NTAPI
FN_ScNotifyChangeDirectoryFileEx(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _Out_writes_bytes_(Length) PVOID Buffer,
    _In_ ULONG Length,
    _In_ ULONG CompletionFilter,
    _In_ BOOLEAN WatchTree,
    _In_opt_ DIRECTORY_NOTIFY_INFORMATION_CLASS DirectoryNotifyInformationClass
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScNotifyChangeDirectoryFileEx* volatile ScNotifyChangeDirectoryFileEx;

typedef
NTSTATUS
NTAPI
FN_ScNotifyChangeKey(
    _In_ HANDLE KeyHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ ULONG CompletionFilter,
    _In_ BOOLEAN WatchTree,
    _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
    _In_ ULONG BufferSize,
    _In_ BOOLEAN Asynchronous
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScNotifyChangeKey* volatile ScNotifyChangeKey;

typedef
NTSTATUS
NTAPI
FN_ScNotifyChangeMultipleKeys(
    _In_ HANDLE MasterKeyHandle,
    _In_opt_ ULONG Count,
    _In_reads_opt_(Count) OBJECT_ATTRIBUTES SubordinateObjects[],
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ ULONG CompletionFilter,
    _In_ BOOLEAN WatchTree,
    _Out_writes_bytes_opt_(BufferSize) PVOID Buffer,
    _In_ ULONG BufferSize,
    _In_ BOOLEAN Asynchronous
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScNotifyChangeMultipleKeys* volatile ScNotifyChangeMultipleKeys;

typedef
NTSTATUS
NTAPI
FN_ScNotifyChangeSession(
    _In_ HANDLE SessionHandle,
    _In_ ULONG ChangeSequenceNumber,
    _In_ PLARGE_INTEGER ChangeTimeStamp,
    _In_ IO_SESSION_EVENT Event,
    _In_ IO_SESSION_STATE NewState,
    _In_ IO_SESSION_STATE PreviousState,
    _In_reads_bytes_opt_(PayloadSize) PVOID Payload,
    _In_ ULONG PayloadSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScNotifyChangeSession* volatile ScNotifyChangeSession;

typedef
NTSTATUS
NTAPI
FN_ScOpenDirectoryObject(
    _Out_ PHANDLE DirectoryHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenDirectoryObject* volatile ScOpenDirectoryObject;

typedef
NTSTATUS
NTAPI
FN_ScOpenEnlistment(
    _Out_ PHANDLE EnlistmentHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ HANDLE ResourceManagerHandle,
    _In_ LPGUID EnlistmentGuid,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenEnlistment* volatile ScOpenEnlistment;

typedef
NTSTATUS
NTAPI
FN_ScOpenEvent(
    _Out_ PHANDLE EventHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenEvent* volatile ScOpenEvent;

typedef
NTSTATUS
NTAPI
FN_ScOpenEventPair(
    _Out_ PHANDLE EventPairHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenEventPair* volatile ScOpenEventPair;

typedef
NTSTATUS
NTAPI
FN_ScOpenFile(
    _Out_ PHANDLE FileHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ ULONG ShareAccess,
    _In_ ULONG OpenOptions
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenFile* volatile ScOpenFile;

typedef
NTSTATUS
NTAPI
FN_ScOpenIoCompletion(
    _Out_ PHANDLE IoCompletionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenIoCompletion* volatile ScOpenIoCompletion;

typedef
NTSTATUS
NTAPI
FN_ScOpenJobObject(
    _Out_ PHANDLE JobHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenJobObject* volatile ScOpenJobObject;

typedef
NTSTATUS
NTAPI
FN_ScOpenKey(
    _Out_ PHANDLE KeyHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenKey* volatile ScOpenKey;

typedef
NTSTATUS
NTAPI
FN_ScOpenKeyedEvent(
    _Out_ PHANDLE KeyedEventHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenKeyedEvent* volatile ScOpenKeyedEvent;

typedef
NTSTATUS
NTAPI
FN_ScOpenKeyEx(
    _Out_ PHANDLE KeyHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ULONG OpenOptions
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenKeyEx* volatile ScOpenKeyEx;

typedef
NTSTATUS
NTAPI
FN_ScOpenKeyTransacted(
    _Out_ PHANDLE KeyHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ HANDLE TransactionHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenKeyTransacted* volatile ScOpenKeyTransacted;

typedef
NTSTATUS
NTAPI
FN_ScOpenKeyTransactedEx(
    _Out_ PHANDLE KeyHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ULONG OpenOptions,
    _In_ HANDLE TransactionHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenKeyTransactedEx* volatile ScOpenKeyTransactedEx;

typedef
NTSTATUS
NTAPI
FN_ScOpenMutant(
    _Out_ PHANDLE MutantHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenMutant* volatile ScOpenMutant;

typedef
NTSTATUS
NTAPI
FN_ScOpenObjectAuditAlarm(
    _In_ PUNICODE_STRING SubsystemName,
    _In_opt_ PVOID HandleId,
    _In_ PUNICODE_STRING ObjectTypeName,
    _In_ PUNICODE_STRING ObjectName,
    _In_opt_ PSECURITY_DESCRIPTOR SecurityDescriptor,
    _In_ HANDLE ClientToken,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ ACCESS_MASK GrantedAccess,
    _In_opt_ PPRIVILEGE_SET Privileges,
    _In_ BOOLEAN ObjectCreation,
    _In_ BOOLEAN AccessGranted,
    _Out_ PBOOLEAN GenerateOnClose
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenObjectAuditAlarm* volatile ScOpenObjectAuditAlarm;

typedef
NTSTATUS
NTAPI
FN_ScOpenPartition(
    _Out_ PHANDLE PartitionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenPartition* volatile ScOpenPartition;

typedef
NTSTATUS
NTAPI
FN_ScOpenPrivateNamespace(
    _Out_ PHANDLE NamespaceHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ POBJECT_BOUNDARY_DESCRIPTOR BoundaryDescriptor
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenPrivateNamespace* volatile ScOpenPrivateNamespace;

typedef
NTSTATUS
NTAPI
FN_ScOpenProcess(
    _Out_ PHANDLE ProcessHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ PCLIENT_ID ClientId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenProcess* volatile ScOpenProcess;

typedef
NTSTATUS
NTAPI
FN_ScOpenProcessToken(
    _In_ HANDLE ProcessHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PHANDLE TokenHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenProcessToken* volatile ScOpenProcessToken;

typedef
NTSTATUS
NTAPI
FN_ScOpenProcessTokenEx(
    _In_ HANDLE ProcessHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ ULONG HandleAttributes,
    _Out_ PHANDLE TokenHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenProcessTokenEx* volatile ScOpenProcessTokenEx;

typedef
NTSTATUS
NTAPI
FN_ScOpenRegistryTransaction(
    _Out_ PHANDLE RegistryTransactionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenRegistryTransaction* volatile ScOpenRegistryTransaction;

typedef
NTSTATUS
NTAPI
FN_ScOpenResourceManager(
    _Out_ PHANDLE ResourceManagerHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ HANDLE TmHandle,
    _In_opt_ LPGUID ResourceManagerGuid,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenResourceManager* volatile ScOpenResourceManager;

typedef
NTSTATUS
NTAPI
FN_ScOpenSection(
    _Out_ PHANDLE SectionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenSection* volatile ScOpenSection;

typedef
NTSTATUS
NTAPI
FN_ScOpenSemaphore(
    _Out_ PHANDLE SemaphoreHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenSemaphore* volatile ScOpenSemaphore;

typedef
NTSTATUS
NTAPI
FN_ScOpenSession(
    _Out_ PHANDLE SessionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenSession* volatile ScOpenSession;

typedef
NTSTATUS
NTAPI
FN_ScOpenSymbolicLinkObject(
    _Out_ PHANDLE LinkHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ POBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenSymbolicLinkObject* volatile ScOpenSymbolicLinkObject;

typedef
NTSTATUS
NTAPI
FN_ScOpenThread(
    _Out_ PHANDLE ThreadHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ PCLIENT_ID ClientId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenThread* volatile ScOpenThread;

typedef
NTSTATUS
NTAPI
FN_ScOpenThreadToken(
    _In_ HANDLE ThreadHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ BOOLEAN OpenAsSelf,
    _Out_ PHANDLE TokenHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenThreadToken* volatile ScOpenThreadToken;

typedef
NTSTATUS
NTAPI
FN_ScOpenThreadTokenEx(
    _In_ HANDLE ThreadHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ BOOLEAN OpenAsSelf,
    _In_ ULONG HandleAttributes,
    _Out_ PHANDLE TokenHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenThreadTokenEx* volatile ScOpenThreadTokenEx;

typedef
NTSTATUS
NTAPI
FN_ScOpenTimer(
    _Out_ PHANDLE TimerHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenTimer* volatile ScOpenTimer;

typedef
NTSTATUS
NTAPI
FN_ScOpenTransaction(
    _Out_ PHANDLE TransactionHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ LPGUID Uow,
    _In_opt_ HANDLE TmHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenTransaction* volatile ScOpenTransaction;

typedef
NTSTATUS
NTAPI
FN_ScOpenTransactionManager(
    _Out_ PHANDLE TmHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_opt_ PUNICODE_STRING LogFileName,
    _In_opt_ LPGUID TmIdentity,
    _In_opt_ ULONG OpenOptions
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScOpenTransactionManager* volatile ScOpenTransactionManager;

typedef
NTSTATUS
NTAPI
FN_ScPlugPlayControl(
    _In_ PLUGPLAY_CONTROL_CLASS PnPControlClass,
    _Inout_updates_bytes_(PnPControlDataLength) PVOID PnPControlData,
    _In_ ULONG PnPControlDataLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPlugPlayControl* volatile ScPlugPlayControl;

typedef
NTSTATUS
NTAPI
FN_ScPowerInformation(
    _In_ POWER_INFORMATION_LEVEL InformationLevel,
    _In_reads_bytes_opt_(InputBufferLength) PVOID InputBuffer,
    _In_ ULONG InputBufferLength,
    _Out_writes_bytes_opt_(OutputBufferLength) PVOID OutputBuffer,
    _In_ ULONG OutputBufferLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPowerInformation* volatile ScPowerInformation;

typedef
NTSTATUS
NTAPI
FN_ScPrepareComplete(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPrepareComplete* volatile ScPrepareComplete;

typedef
NTSTATUS
NTAPI
FN_ScPrepareEnlistment(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPrepareEnlistment* volatile ScPrepareEnlistment;

typedef
NTSTATUS
NTAPI
FN_ScPrePrepareComplete(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPrePrepareComplete* volatile ScPrePrepareComplete;

typedef
NTSTATUS
NTAPI
FN_ScPrePrepareEnlistment(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPrePrepareEnlistment* volatile ScPrePrepareEnlistment;

typedef
NTSTATUS
NTAPI
FN_ScPrivilegeCheck(
    _In_ HANDLE ClientToken,
    _Inout_ PPRIVILEGE_SET RequiredPrivileges,
    _Out_ PBOOLEAN Result
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPrivilegeCheck* volatile ScPrivilegeCheck;

typedef
NTSTATUS
NTAPI
FN_ScPrivilegedServiceAuditAlarm(
    _In_ PUNICODE_STRING SubsystemName,
    _In_ PUNICODE_STRING ServiceName,
    _In_ HANDLE ClientToken,
    _In_ PPRIVILEGE_SET Privileges,
    _In_ BOOLEAN AccessGranted
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPrivilegedServiceAuditAlarm* volatile ScPrivilegedServiceAuditAlarm;

typedef
NTSTATUS
NTAPI
FN_ScPrivilegeObjectAuditAlarm(
    _In_ PUNICODE_STRING SubsystemName,
    _In_opt_ PVOID HandleId,
    _In_ HANDLE ClientToken,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ PPRIVILEGE_SET Privileges,
    _In_ BOOLEAN AccessGranted
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPrivilegeObjectAuditAlarm* volatile ScPrivilegeObjectAuditAlarm;

typedef
NTSTATUS
NTAPI
FN_ScPropagationComplete(
    _In_ HANDLE ResourceManagerHandle,
    _In_ ULONG RequestCookie,
    _In_ ULONG BufferLength,
    _In_ PVOID Buffer
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPropagationComplete* volatile ScPropagationComplete;

typedef
NTSTATUS
NTAPI
FN_ScPropagationFailed(
    _In_ HANDLE ResourceManagerHandle,
    _In_ ULONG RequestCookie,
    _In_ NTSTATUS PropStatus
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPropagationFailed* volatile ScPropagationFailed;

typedef
NTSTATUS
NTAPI
FN_ScProtectVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _Inout_ PVOID *BaseAddress,
    _Inout_ PSIZE_T RegionSize,
    _In_ ULONG NewProtection,
    _Out_ PULONG OldProtection
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScProtectVirtualMemory* volatile ScProtectVirtualMemory;

typedef
NTSTATUS
NTAPI
FN_ScPssCaptureVaSpaceBulk(
    _In_ HANDLE ProcessHandle,
    _In_opt_ PVOID BaseAddress,
    _In_ PNTPSS_MEMORY_BULK_INFORMATION BulkInformation,
    _In_ SIZE_T BulkInformationLength,
    _Out_opt_ PSIZE_T ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPssCaptureVaSpaceBulk* volatile ScPssCaptureVaSpaceBulk;

typedef
NTSTATUS
NTAPI
FN_ScPulseEvent(
    _In_ HANDLE EventHandle,
    _Out_opt_ PLONG PreviousState
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScPulseEvent* volatile ScPulseEvent;

typedef
NTSTATUS
NTAPI
FN_ScQueryAttributesFile(
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _Out_ PFILE_BASIC_INFORMATION FileInformation
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryAttributesFile* volatile ScQueryAttributesFile;

typedef
NTSTATUS
NTAPI
FN_ScQueryAuxiliaryCounterFrequency(
    _Out_ PULONG64 AuxiliaryCounterFrequency
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryAuxiliaryCounterFrequency* volatile ScQueryAuxiliaryCounterFrequency;

typedef
NTSTATUS
NTAPI
FN_ScQueryBootEntryOrder(
    _Out_writes_opt_(*Count) PULONG Ids,
    _Inout_ PULONG Count
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryBootEntryOrder* volatile ScQueryBootEntryOrder;

typedef
NTSTATUS
NTAPI
FN_ScQueryBootOptions(
    _Out_writes_bytes_opt_(*BootOptionsLength) PBOOT_OPTIONS BootOptions,
    _Inout_ PULONG BootOptionsLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryBootOptions* volatile ScQueryBootOptions;

typedef
NTSTATUS
NTAPI
FN_ScQueryDebugFilterState(
    _In_ ULONG ComponentId,
    _In_ ULONG Level
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryDebugFilterState* volatile ScQueryDebugFilterState;

typedef
NTSTATUS
NTAPI
FN_ScQueryDefaultLocale(
    _In_ BOOLEAN UserProfile,
    _Out_ PLCID DefaultLocaleId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryDefaultLocale* volatile ScQueryDefaultLocale;

typedef
NTSTATUS
NTAPI
FN_ScQueryDefaultUILanguage(
    _Out_ LANGID *DefaultUILanguageId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryDefaultUILanguage* volatile ScQueryDefaultUILanguage;

typedef
NTSTATUS
NTAPI
FN_ScQueryDirectoryFile(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _Out_writes_bytes_(Length) PVOID FileInformation,
    _In_ ULONG Length,
    _In_ FILE_INFORMATION_CLASS FileInformationClass,
    _In_ BOOLEAN ReturnSingleEntry,
    _In_opt_ PUNICODE_STRING FileName,
    _In_ BOOLEAN RestartScan
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryDirectoryFile* volatile ScQueryDirectoryFile;

typedef
NTSTATUS
NTAPI
FN_ScQueryDirectoryFileEx(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _Out_writes_bytes_(Length) PVOID FileInformation,
    _In_ ULONG Length,
    _In_ FILE_INFORMATION_CLASS FileInformationClass,
    _In_ ULONG QueryFlags,
    _In_opt_ PUNICODE_STRING FileName
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryDirectoryFileEx* volatile ScQueryDirectoryFileEx;

typedef
NTSTATUS
NTAPI
FN_ScQueryDirectoryObject(
    _In_ HANDLE DirectoryHandle,
    _Out_writes_bytes_opt_(Length) PVOID Buffer,
    _In_ ULONG Length,
    _In_ BOOLEAN ReturnSingleEntry,
    _In_ BOOLEAN RestartScan,
    _Inout_ PULONG Context,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryDirectoryObject* volatile ScQueryDirectoryObject;

typedef
NTSTATUS
NTAPI
FN_ScQueryDriverEntryOrder(
    _Out_writes_opt_(*Count) PULONG Ids,
    _Inout_ PULONG Count
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryDriverEntryOrder* volatile ScQueryDriverEntryOrder;

typedef
NTSTATUS
NTAPI
FN_ScQueryEaFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _Out_writes_bytes_(Length) PVOID Buffer,
    _In_ ULONG Length,
    _In_ BOOLEAN ReturnSingleEntry,
    _In_reads_bytes_opt_(EaListLength) PVOID EaList,
    _In_ ULONG EaListLength,
    _In_opt_ PULONG EaIndex,
    _In_ BOOLEAN RestartScan
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryEaFile* volatile ScQueryEaFile;

typedef
NTSTATUS
NTAPI
FN_ScQueryEvent(
    _In_ HANDLE EventHandle,
    _In_ EVENT_INFORMATION_CLASS EventInformationClass,
    _Out_writes_bytes_(EventInformationLength) PVOID EventInformation,
    _In_ ULONG EventInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryEvent* volatile ScQueryEvent;

typedef
NTSTATUS
NTAPI
FN_ScQueryFullAttributesFile(
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _Out_ PFILE_NETWORK_OPEN_INFORMATION FileInformation
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryFullAttributesFile* volatile ScQueryFullAttributesFile;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationAtom(
    _In_ RTL_ATOM Atom,
    _In_ ATOM_INFORMATION_CLASS AtomInformationClass,
    _Out_writes_bytes_(AtomInformationLength) PVOID AtomInformation,
    _In_ ULONG AtomInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationAtom* volatile ScQueryInformationAtom;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationByName(
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _Out_writes_bytes_(Length) PVOID FileInformation,
    _In_ ULONG Length,
    _In_ FILE_INFORMATION_CLASS FileInformationClass
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationByName* volatile ScQueryInformationByName;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationCpuPartition(
    _In_ HANDLE CpuPartitionHandle,
    _In_ ULONG CpuPartitionInformationClass,
    _Out_writes_bytes_opt_(CpuPartitionInformationLength) PVOID CpuPartitionInformation,
    _In_ ULONG CpuPartitionInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationCpuPartition* volatile ScQueryInformationCpuPartition;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationEnlistment(
    _In_ HANDLE EnlistmentHandle,
    _In_ ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass,
    _Out_writes_bytes_(EnlistmentInformationLength) PVOID EnlistmentInformation,
    _In_ ULONG EnlistmentInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationEnlistment* volatile ScQueryInformationEnlistment;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _Out_writes_bytes_(Length) PVOID FileInformation,
    _In_ ULONG Length,
    _In_ FILE_INFORMATION_CLASS FileInformationClass
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationFile* volatile ScQueryInformationFile;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationJobObject(
    _In_opt_ HANDLE JobHandle,
    _In_ JOBOBJECTINFOCLASS JobObjectInformationClass,
    _Out_writes_bytes_(JobObjectInformationLength) PVOID JobObjectInformation,
    _In_ ULONG JobObjectInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationJobObject* volatile ScQueryInformationJobObject;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationPort(
    _In_ HANDLE PortHandle,
    _In_ PORT_INFORMATION_CLASS PortInformationClass,
    _Out_writes_bytes_to_(Length, *ReturnLength) PVOID PortInformation,
    _In_ ULONG Length,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationPort* volatile ScQueryInformationPort;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationProcess(
    _In_ HANDLE ProcessHandle,
    _In_ PROCESSINFOCLASS ProcessInformationClass,
    _Out_writes_bytes_(ProcessInformationLength) PVOID ProcessInformation,
    _In_ ULONG ProcessInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationProcess* volatile ScQueryInformationProcess;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationResourceManager(
    _In_ HANDLE ResourceManagerHandle,
    _In_ RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
    _Out_writes_bytes_(ResourceManagerInformationLength) PVOID ResourceManagerInformation,
    _In_ ULONG ResourceManagerInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationResourceManager* volatile ScQueryInformationResourceManager;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationThread(
    _In_ HANDLE ThreadHandle,
    _In_ THREADINFOCLASS ThreadInformationClass,
    _Out_writes_bytes_(ThreadInformationLength) PVOID ThreadInformation,
    _In_ ULONG ThreadInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationThread* volatile ScQueryInformationThread;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationToken(
    _In_ HANDLE TokenHandle,
    _In_ TOKEN_INFORMATION_CLASS TokenInformationClass,
    _Out_writes_bytes_to_opt_(TokenInformationLength, *ReturnLength) PVOID TokenInformation,
    _In_ ULONG TokenInformationLength,
    _Out_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationToken* volatile ScQueryInformationToken;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationTransaction(
    _In_ HANDLE TransactionHandle,
    _In_ TRANSACTION_INFORMATION_CLASS TransactionInformationClass,
    _Out_writes_bytes_(TransactionInformationLength) PVOID TransactionInformation,
    _In_ ULONG TransactionInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationTransaction* volatile ScQueryInformationTransaction;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationTransactionManager(
    _In_ HANDLE TransactionManagerHandle,
    _In_ TRANSACTIONMANAGER_INFORMATION_CLASS TransactionManagerInformationClass,
    _Out_writes_bytes_(TransactionManagerInformationLength) PVOID TransactionManagerInformation,
    _In_ ULONG TransactionManagerInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationTransactionManager* volatile ScQueryInformationTransactionManager;

typedef
NTSTATUS
NTAPI
FN_ScQueryInformationWorkerFactory(
    _In_ HANDLE WorkerFactoryHandle,
    _In_ WORKERFACTORYINFOCLASS WorkerFactoryInformationClass,
    _Out_writes_bytes_(WorkerFactoryInformationLength) PVOID WorkerFactoryInformation,
    _In_ ULONG WorkerFactoryInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInformationWorkerFactory* volatile ScQueryInformationWorkerFactory;

typedef
NTSTATUS
NTAPI
FN_ScQueryInstallUILanguage(
    _Out_ LANGID *InstallUILanguageId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryInstallUILanguage* volatile ScQueryInstallUILanguage;

typedef
NTSTATUS
NTAPI
FN_ScQueryIntervalProfile(
    _In_ KPROFILE_SOURCE ProfileSource,
    _Out_ PULONG Interval
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryIntervalProfile* volatile ScQueryIntervalProfile;

typedef
NTSTATUS
NTAPI
FN_ScQueryIoCompletion(
    _In_ HANDLE IoCompletionHandle,
    _In_ IO_COMPLETION_INFORMATION_CLASS IoCompletionInformationClass,
    _Out_writes_bytes_(IoCompletionInformationLength) PVOID IoCompletionInformation,
    _In_ ULONG IoCompletionInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryIoCompletion* volatile ScQueryIoCompletion;

typedef
NTSTATUS
NTAPI
FN_ScQueryIoRingCapabilities(
    _In_ SIZE_T IoRingCapabilitiesLength,
    _Out_ PVOID IoRingCapabilities
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryIoRingCapabilities* volatile ScQueryIoRingCapabilities;

typedef
NTSTATUS
NTAPI
FN_ScQueryKey(
    _In_ HANDLE KeyHandle,
    _In_ KEY_INFORMATION_CLASS KeyInformationClass,
    _Out_writes_bytes_to_opt_(Length, *ResultLength) PVOID KeyInformation,
    _In_ ULONG Length,
    _Out_ PULONG ResultLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryKey* volatile ScQueryKey;

typedef
NTSTATUS
NTAPI
FN_ScQueryLicenseValue(
    _In_ PUNICODE_STRING ValueName,
    _Out_opt_ PULONG Type,
    _Out_writes_bytes_to_opt_(DataSize, *ResultDataSize) PVOID Data,
    _In_ ULONG DataSize,
    _Out_ PULONG ResultDataSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryLicenseValue* volatile ScQueryLicenseValue;

typedef
NTSTATUS
NTAPI
FN_ScQueryMultipleValueKey(
    _In_ HANDLE KeyHandle,
    _Inout_updates_(EntryCount) PKEY_VALUE_ENTRY ValueEntries,
    _In_ ULONG EntryCount,
    _Out_writes_bytes_(*BufferLength) PVOID ValueBuffer,
    _Inout_ PULONG BufferLength,
    _Out_opt_ PULONG RequiredBufferLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryMultipleValueKey* volatile ScQueryMultipleValueKey;

typedef
NTSTATUS
NTAPI
FN_ScQueryMutant(
    _In_ HANDLE MutantHandle,
    _In_ MUTANT_INFORMATION_CLASS MutantInformationClass,
    _Out_writes_bytes_(MutantInformationLength) PVOID MutantInformation,
    _In_ ULONG MutantInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryMutant* volatile ScQueryMutant;

typedef
NTSTATUS
NTAPI
FN_ScQueryObject(
    _In_opt_ HANDLE Handle,
    _In_ OBJECT_INFORMATION_CLASS ObjectInformationClass,
    _Out_writes_bytes_opt_(ObjectInformationLength) PVOID ObjectInformation,
    _In_ ULONG ObjectInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryObject* volatile ScQueryObject;

typedef
NTSTATUS
NTAPI
FN_ScQueryOpenSubKeys(
    _In_ POBJECT_ATTRIBUTES TargetKey,
    _Out_ PULONG HandleCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryOpenSubKeys* volatile ScQueryOpenSubKeys;

typedef
NTSTATUS
NTAPI
FN_ScQueryOpenSubKeysEx(
    _In_ POBJECT_ATTRIBUTES TargetKey,
    _In_ ULONG BufferLength,
    _Out_writes_bytes_opt_(BufferLength) PVOID Buffer,
    _Out_ PULONG RequiredSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryOpenSubKeysEx* volatile ScQueryOpenSubKeysEx;

typedef
NTSTATUS
NTAPI
FN_ScQueryPerformanceCounter(
    _Out_ PLARGE_INTEGER PerformanceCounter,
    _Out_opt_ PLARGE_INTEGER PerformanceFrequency
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryPerformanceCounter* volatile ScQueryPerformanceCounter;

typedef
NTSTATUS
NTAPI
FN_ScQueryPortInformationProcess(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryPortInformationProcess* volatile ScQueryPortInformationProcess;

typedef
NTSTATUS
NTAPI
FN_ScQueryQuotaInformationFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _Out_writes_bytes_(Length) PVOID Buffer,
    _In_ ULONG Length,
    _In_ BOOLEAN ReturnSingleEntry,
    _In_reads_bytes_opt_(SidListLength) PVOID SidList,
    _In_ ULONG SidListLength,
    _In_opt_ PSID StartSid,
    _In_ BOOLEAN RestartScan
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryQuotaInformationFile* volatile ScQueryQuotaInformationFile;

typedef
NTSTATUS
NTAPI
FN_ScQuerySection(
    _In_ HANDLE SectionHandle,
    _In_ SECTION_INFORMATION_CLASS SectionInformationClass,
    _Out_writes_bytes_(SectionInformationLength) PVOID SectionInformation,
    _In_ SIZE_T SectionInformationLength,
    _Out_opt_ PSIZE_T ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySection* volatile ScQuerySection;

typedef
NTSTATUS
NTAPI
FN_ScQuerySecurityAttributesToken(
    _In_ HANDLE TokenHandle,
    _In_reads_opt_(NumberOfAttributes) PUNICODE_STRING Attributes,
    _In_ ULONG NumberOfAttributes,
    _Out_writes_bytes_(Length) PVOID Buffer, // PTOKEN_SECURITY_ATTRIBUTES_INFORMATION
    _In_ ULONG Length,
    _Out_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySecurityAttributesToken* volatile ScQuerySecurityAttributesToken;

typedef
NTSTATUS
NTAPI
FN_ScQuerySecurityObject(
    _In_ HANDLE Handle,
    _In_ SECURITY_INFORMATION SecurityInformation,
    _Out_writes_bytes_to_opt_(Length, *LengthNeeded) PSECURITY_DESCRIPTOR SecurityDescriptor,
    _In_ ULONG Length,
    _Out_ PULONG LengthNeeded
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySecurityObject* volatile ScQuerySecurityObject;

typedef
NTSTATUS
NTAPI
FN_ScQuerySecurityPolicy(
    _In_ PCUNICODE_STRING Policy, 
    _In_ PCUNICODE_STRING KeyName,
    _In_ PCUNICODE_STRING ValueName,
    _In_ SECURE_SETTING_VALUE_TYPE ValueType,
    _Out_writes_bytes_opt_(*ValueSize) PVOID Value,
    _Inout_ PULONG ValueSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySecurityPolicy* volatile ScQuerySecurityPolicy;

typedef
NTSTATUS
NTAPI
FN_ScQuerySemaphore(
    _In_ HANDLE SemaphoreHandle,
    _In_ SEMAPHORE_INFORMATION_CLASS SemaphoreInformationClass,
    _Out_writes_bytes_(SemaphoreInformationLength) PVOID SemaphoreInformation,
    _In_ ULONG SemaphoreInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySemaphore* volatile ScQuerySemaphore;

typedef
NTSTATUS
NTAPI
FN_ScQuerySymbolicLinkObject(
    _In_ HANDLE LinkHandle,
    _Inout_ PUNICODE_STRING LinkTarget,
    _Out_opt_ PULONG ReturnedLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySymbolicLinkObject* volatile ScQuerySymbolicLinkObject;

typedef
NTSTATUS
NTAPI
FN_ScQuerySystemEnvironmentValue(
    _In_ PUNICODE_STRING VariableName,
    _Out_writes_bytes_(ValueLength) PWSTR VariableValue,
    _In_ USHORT ValueLength,
    _Out_opt_ PUSHORT ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySystemEnvironmentValue* volatile ScQuerySystemEnvironmentValue;

typedef
NTSTATUS
NTAPI
FN_ScQuerySystemEnvironmentValueEx(
    _In_ PUNICODE_STRING VariableName,
    _In_ PCGUID VendorGuid,
    _Out_writes_bytes_opt_(*BufferLength) PVOID Buffer,
    _Inout_ PULONG BufferLength,
    _Out_opt_ PULONG Attributes // EFI_VARIABLE_*
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySystemEnvironmentValueEx* volatile ScQuerySystemEnvironmentValueEx;

typedef
NTSTATUS
NTAPI
FN_ScQuerySystemInformation(
    _In_ SYSTEM_INFORMATION_CLASS SystemInformationClass,
    _Out_writes_bytes_opt_(SystemInformationLength) PVOID SystemInformation,
    _In_ ULONG SystemInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySystemInformation* volatile ScQuerySystemInformation;

typedef
NTSTATUS
NTAPI
FN_ScQuerySystemInformationEx(
    _In_ SYSTEM_INFORMATION_CLASS SystemInformationClass,
    _In_reads_bytes_(InputBufferLength) PVOID InputBuffer,
    _In_ ULONG InputBufferLength,
    _Out_writes_bytes_opt_(SystemInformationLength) PVOID SystemInformation,
    _In_ ULONG SystemInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySystemInformationEx* volatile ScQuerySystemInformationEx;

typedef
NTSTATUS
NTAPI
FN_ScQuerySystemTime(
    _Out_ PLARGE_INTEGER SystemTime
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQuerySystemTime* volatile ScQuerySystemTime;

typedef
NTSTATUS
NTAPI
FN_ScQueryTimer(
    _In_ HANDLE TimerHandle,
    _In_ TIMER_INFORMATION_CLASS TimerInformationClass,
    _Out_writes_bytes_(TimerInformationLength) PVOID TimerInformation,
    _In_ ULONG TimerInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryTimer* volatile ScQueryTimer;

typedef
NTSTATUS
NTAPI
FN_ScQueryTimerResolution(
    _Out_ PULONG MaximumTime,
    _Out_ PULONG MinimumTime,
    _Out_ PULONG CurrentTime
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryTimerResolution* volatile ScQueryTimerResolution;

typedef
NTSTATUS
NTAPI
FN_ScQueryValueKey(
    _In_ HANDLE KeyHandle,
    _In_ PUNICODE_STRING ValueName,
    _In_ KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
    _Out_writes_bytes_to_opt_(Length, *ResultLength) PVOID KeyValueInformation,
    _In_ ULONG Length,
    _Out_ PULONG ResultLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryValueKey* volatile ScQueryValueKey;

typedef
NTSTATUS
NTAPI
FN_ScQueryVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _In_opt_ PVOID BaseAddress,
    _In_ MEMORY_INFORMATION_CLASS MemoryInformationClass,
    _Out_writes_bytes_(MemoryInformationLength) PVOID MemoryInformation,
    _In_ SIZE_T MemoryInformationLength,
    _Out_opt_ PSIZE_T ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryVirtualMemory* volatile ScQueryVirtualMemory;

typedef
NTSTATUS
NTAPI
FN_ScQueryVolumeInformationFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _Out_writes_bytes_(Length) PVOID FsInformation,
    _In_ ULONG Length,
    _In_ FSINFOCLASS FsInformationClass
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryVolumeInformationFile* volatile ScQueryVolumeInformationFile;

typedef
NTSTATUS
NTAPI
FN_ScQueryWnfStateData(
    _In_ PCWNF_STATE_NAME StateName,
    _In_opt_ PCWNF_TYPE_ID TypeId,
    _In_opt_ const VOID* ExplicitScope,
    _Out_ PWNF_CHANGE_STAMP ChangeStamp,
    _Out_writes_bytes_opt_(*BufferLength) PVOID Buffer,
    _Inout_ PULONG BufferLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryWnfStateData* volatile ScQueryWnfStateData;

typedef
NTSTATUS
NTAPI
FN_ScQueryWnfStateNameInformation(
    _In_ PCWNF_STATE_NAME StateName,
    _In_ WNF_STATE_NAME_INFORMATION NameInfoClass,
    _In_opt_ const VOID* ExplicitScope,
    _Out_writes_bytes_(BufferLength) PVOID Buffer,
    _In_ ULONG BufferLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueryWnfStateNameInformation* volatile ScQueryWnfStateNameInformation;

typedef
NTSTATUS
NTAPI
FN_ScQueueApcThread(
    _In_ HANDLE ThreadHandle,
    _In_ PPS_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcArgument1,
    _In_opt_ PVOID ApcArgument2,
    _In_opt_ PVOID ApcArgument3
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueueApcThread* volatile ScQueueApcThread;

typedef
NTSTATUS
NTAPI
FN_ScQueueApcThreadEx(
    _In_ HANDLE ThreadHandle,
    _In_opt_ HANDLE ReserveHandle, // NtAllocateReserveObject // SPECIAL_USER_APC
    _In_ PPS_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcArgument1,
    _In_opt_ PVOID ApcArgument2,
    _In_opt_ PVOID ApcArgument3
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueueApcThreadEx* volatile ScQueueApcThreadEx;

typedef
NTSTATUS
NTAPI
FN_ScQueueApcThreadEx2(
    _In_ HANDLE ThreadHandle,
    _In_opt_ HANDLE ReserveHandle, // NtAllocateReserveObject
    _In_ ULONG ApcFlags, // QUEUE_USER_APC_FLAGS
    _In_ PPS_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcArgument1,
    _In_opt_ PVOID ApcArgument2,
    _In_opt_ PVOID ApcArgument3
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScQueueApcThreadEx2* volatile ScQueueApcThreadEx2;

typedef
NTSTATUS
NTAPI
FN_ScRaiseException(
    _In_ PEXCEPTION_RECORD ExceptionRecord,
    _In_ PCONTEXT ContextRecord,
    _In_ BOOLEAN FirstChance
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRaiseException* volatile ScRaiseException;

typedef
NTSTATUS
NTAPI
FN_ScRaiseHardError(
    _In_ NTSTATUS ErrorStatus,
    _In_ ULONG NumberOfParameters,
    _In_ ULONG UnicodeStringParameterMask,
    _In_reads_(NumberOfParameters) PULONG_PTR Parameters,
    _In_ ULONG ValidResponseOptions,
    _Out_ PULONG Response
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRaiseHardError* volatile ScRaiseHardError;

typedef
NTSTATUS
NTAPI
FN_ScReadFile(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _Out_writes_bytes_(Length) PVOID Buffer,
    _In_ ULONG Length,
    _In_opt_ PLARGE_INTEGER ByteOffset,
    _In_opt_ PULONG Key
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReadFile* volatile ScReadFile;

typedef
NTSTATUS
NTAPI
FN_ScReadFileScatter(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ PFILE_SEGMENT_ELEMENT SegmentArray,
    _In_ ULONG Length,
    _In_opt_ PLARGE_INTEGER ByteOffset,
    _In_opt_ PULONG Key
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReadFileScatter* volatile ScReadFileScatter;

typedef
NTSTATUS
NTAPI
FN_ScReadOnlyEnlistment(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReadOnlyEnlistment* volatile ScReadOnlyEnlistment;

typedef
NTSTATUS
NTAPI
FN_ScReadRequestData(
    _In_ HANDLE PortHandle,
    _In_ PPORT_MESSAGE Message,
    _In_ ULONG DataEntryIndex,
    _Out_writes_bytes_to_(BufferSize, *NumberOfBytesRead) PVOID Buffer,
    _In_ SIZE_T BufferSize,
    _Out_opt_ PSIZE_T NumberOfBytesRead
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReadRequestData* volatile ScReadRequestData;

typedef
NTSTATUS
NTAPI
FN_ScReadVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _In_ PVOID BaseAddress,
    _Out_writes_bytes_(NumberOfBytesToRead) PVOID Buffer,
    _In_ SIZE_T NumberOfBytesToRead,
    _Out_opt_ PSIZE_T NumberOfBytesRead
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReadVirtualMemory* volatile ScReadVirtualMemory;

typedef
NTSTATUS
NTAPI
FN_ScReadVirtualMemoryEx(
    _In_ HANDLE ProcessHandle,
    _In_ PVOID BaseAddress,
    _Out_writes_bytes_(NumberOfBytesToRead) PVOID Buffer,
    _In_ SIZE_T NumberOfBytesToRead,
    _Out_opt_ PSIZE_T NumberOfBytesRead,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReadVirtualMemoryEx* volatile ScReadVirtualMemoryEx;

typedef
NTSTATUS
NTAPI
FN_ScRecoverEnlistment(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PVOID EnlistmentKey
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRecoverEnlistment* volatile ScRecoverEnlistment;

typedef
NTSTATUS
NTAPI
FN_ScRecoverResourceManager(
    _In_ HANDLE ResourceManagerHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRecoverResourceManager* volatile ScRecoverResourceManager;

typedef
NTSTATUS
NTAPI
FN_ScRecoverTransactionManager(
    _In_ HANDLE TransactionManagerHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRecoverTransactionManager* volatile ScRecoverTransactionManager;

typedef
NTSTATUS
NTAPI
FN_ScRegisterProtocolAddressInformation(
    _In_ HANDLE ResourceManager,
    _In_ PCRM_PROTOCOL_ID ProtocolId,
    _In_ ULONG ProtocolInformationSize,
    _In_ PVOID ProtocolInformation,
    _In_opt_ ULONG CreateOptions
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRegisterProtocolAddressInformation* volatile ScRegisterProtocolAddressInformation;

typedef
NTSTATUS
NTAPI
FN_ScRegisterThreadTerminatePort(
    _In_ HANDLE PortHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRegisterThreadTerminatePort* volatile ScRegisterThreadTerminatePort;

typedef
NTSTATUS
NTAPI
FN_ScReleaseKeyedEvent(
    _In_opt_ HANDLE KeyedEventHandle,
    _In_ PVOID KeyValue,
    _In_ BOOLEAN Alertable,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReleaseKeyedEvent* volatile ScReleaseKeyedEvent;

typedef
NTSTATUS
NTAPI
FN_ScReleaseMutant(
    _In_ HANDLE MutantHandle,
    _Out_opt_ PLONG PreviousCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReleaseMutant* volatile ScReleaseMutant;

typedef
NTSTATUS
NTAPI
FN_ScReleaseSemaphore(
    _In_ HANDLE SemaphoreHandle,
    _In_ LONG ReleaseCount,
    _Out_opt_ PLONG PreviousCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReleaseSemaphore* volatile ScReleaseSemaphore;

typedef
NTSTATUS
NTAPI
FN_ScReleaseWorkerFactoryWorker(
    _In_ HANDLE WorkerFactoryHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReleaseWorkerFactoryWorker* volatile ScReleaseWorkerFactoryWorker;

typedef
NTSTATUS
NTAPI
FN_ScRemoveIoCompletion(
    _In_ HANDLE IoCompletionHandle,
    _Out_ PVOID *KeyContext,
    _Out_ PVOID *ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRemoveIoCompletion* volatile ScRemoveIoCompletion;

typedef
NTSTATUS
NTAPI
FN_ScRemoveIoCompletionEx(
    _In_ HANDLE IoCompletionHandle,
    _Out_writes_to_(Count, *NumEntriesRemoved) PFILE_IO_COMPLETION_INFORMATION IoCompletionInformation,
    _In_ ULONG Count,
    _Out_ PULONG NumEntriesRemoved,
    _In_opt_ PLARGE_INTEGER Timeout,
    _In_ BOOLEAN Alertable
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRemoveIoCompletionEx* volatile ScRemoveIoCompletionEx;

typedef
NTSTATUS
NTAPI
FN_ScRemoveProcessDebug(
    _In_ HANDLE ProcessHandle,
    _In_ HANDLE DebugObjectHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRemoveProcessDebug* volatile ScRemoveProcessDebug;

typedef
NTSTATUS
NTAPI
FN_ScRenameKey(
    _In_ HANDLE KeyHandle,
    _In_ PUNICODE_STRING NewName
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRenameKey* volatile ScRenameKey;

typedef
NTSTATUS
NTAPI
FN_ScRenameTransactionManager(
    _In_ PUNICODE_STRING LogFileName,
    _In_ LPGUID ExistingTransactionManagerGuid
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRenameTransactionManager* volatile ScRenameTransactionManager;

typedef
NTSTATUS
NTAPI
FN_ScReplaceKey(
    _In_ POBJECT_ATTRIBUTES NewFile,
    _In_ HANDLE TargetHandle,
    _In_ POBJECT_ATTRIBUTES OldFile
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReplaceKey* volatile ScReplaceKey;

typedef
NTSTATUS
NTAPI
FN_ScReplacePartitionUnit(
    _In_ PUNICODE_STRING TargetInstancePath,
    _In_ PUNICODE_STRING SpareInstancePath,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReplacePartitionUnit* volatile ScReplacePartitionUnit;

typedef
NTSTATUS
NTAPI
FN_ScReplyPort(
    _In_ HANDLE PortHandle,
    _In_reads_bytes_(ReplyMessage->u1.s1.TotalLength) PPORT_MESSAGE ReplyMessage
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReplyPort* volatile ScReplyPort;

typedef
NTSTATUS
NTAPI
FN_ScReplyWaitReceivePort(
    _In_ HANDLE PortHandle,
    _Out_opt_ PVOID *PortContext,
    _In_reads_bytes_opt_(ReplyMessage->u1.s1.TotalLength) PPORT_MESSAGE ReplyMessage,
    _Out_ PPORT_MESSAGE ReceiveMessage
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReplyWaitReceivePort* volatile ScReplyWaitReceivePort;

typedef
NTSTATUS
NTAPI
FN_ScReplyWaitReceivePortEx(
    _In_ HANDLE PortHandle,
    _Out_opt_ PVOID *PortContext,
    _In_reads_bytes_opt_(ReplyMessage->u1.s1.TotalLength) PPORT_MESSAGE ReplyMessage,
    _Out_ PPORT_MESSAGE ReceiveMessage,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReplyWaitReceivePortEx* volatile ScReplyWaitReceivePortEx;

typedef
NTSTATUS
NTAPI
FN_ScReplyWaitReplyPort(
    _In_ HANDLE PortHandle,
    _Inout_ PPORT_MESSAGE ReplyMessage
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScReplyWaitReplyPort* volatile ScReplyWaitReplyPort;

typedef
NTSTATUS
NTAPI
FN_ScRequestPort(
    _In_ HANDLE PortHandle,
    _In_reads_bytes_(RequestMessage->u1.s1.TotalLength) PPORT_MESSAGE RequestMessage
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRequestPort* volatile ScRequestPort;

typedef
NTSTATUS
NTAPI
FN_ScRequestWaitReplyPort(
    _In_ HANDLE PortHandle,
    _In_reads_bytes_(RequestMessage->u1.s1.TotalLength) PPORT_MESSAGE RequestMessage,
    _Out_ PPORT_MESSAGE ReplyMessage
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRequestWaitReplyPort* volatile ScRequestWaitReplyPort;

typedef
NTSTATUS
NTAPI
FN_ScResetEvent(
    _In_ HANDLE EventHandle,
    _Out_opt_ PLONG PreviousState
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScResetEvent* volatile ScResetEvent;

typedef
NTSTATUS
NTAPI
FN_ScResetWriteWatch(
    _In_ HANDLE ProcessHandle,
    _In_ PVOID BaseAddress,
    _In_ SIZE_T RegionSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScResetWriteWatch* volatile ScResetWriteWatch;

typedef
NTSTATUS
NTAPI
FN_ScRestoreKey(
    _In_ HANDLE KeyHandle,
    _In_ HANDLE FileHandle,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRestoreKey* volatile ScRestoreKey;

typedef
NTSTATUS
NTAPI
FN_ScResumeProcess(
    _In_ HANDLE ProcessHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScResumeProcess* volatile ScResumeProcess;

typedef
NTSTATUS
NTAPI
FN_ScResumeThread(
    _In_ HANDLE ThreadHandle,
    _Out_opt_ PULONG PreviousSuspendCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScResumeThread* volatile ScResumeThread;

typedef
NTSTATUS
NTAPI
FN_ScRevertContainerImpersonation(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRevertContainerImpersonation* volatile ScRevertContainerImpersonation;

typedef
NTSTATUS
NTAPI
FN_ScRollbackComplete(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRollbackComplete* volatile ScRollbackComplete;

typedef
NTSTATUS
NTAPI
FN_ScRollbackEnlistment(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRollbackEnlistment* volatile ScRollbackEnlistment;

typedef
NTSTATUS
NTAPI
FN_ScRollbackRegistryTransaction(
    _In_ HANDLE RegistryTransactionHandle,
    _Reserved_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRollbackRegistryTransaction* volatile ScRollbackRegistryTransaction;

typedef
NTSTATUS
NTAPI
FN_ScRollbackTransaction(
    _In_ HANDLE TransactionHandle,
    _In_ BOOLEAN Wait
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRollbackTransaction* volatile ScRollbackTransaction;

typedef
NTSTATUS
NTAPI
FN_ScRollforwardTransactionManager(
    _In_ HANDLE TransactionManagerHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScRollforwardTransactionManager* volatile ScRollforwardTransactionManager;

typedef
NTSTATUS
NTAPI
FN_ScSaveKey(
    _In_ HANDLE KeyHandle,
    _In_ HANDLE FileHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSaveKey* volatile ScSaveKey;

typedef
NTSTATUS
NTAPI
FN_ScSaveKeyEx(
    _In_ HANDLE KeyHandle,
    _In_ HANDLE FileHandle,
    _In_ ULONG Format
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSaveKeyEx* volatile ScSaveKeyEx;

typedef
NTSTATUS
NTAPI
FN_ScSaveMergedKeys(
    _In_ HANDLE HighPrecedenceKeyHandle,
    _In_ HANDLE LowPrecedenceKeyHandle,
    _In_ HANDLE FileHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSaveMergedKeys* volatile ScSaveMergedKeys;

typedef
NTSTATUS
NTAPI
FN_ScSecureConnectPort(
    _Out_ PHANDLE PortHandle,
    _In_ PUNICODE_STRING PortName,
    _In_ PSECURITY_QUALITY_OF_SERVICE SecurityQos,
    _Inout_opt_ PPORT_VIEW ClientView,
    _In_opt_ PSID RequiredServerSid,
    _Inout_opt_ PREMOTE_PORT_VIEW ServerView,
    _Out_opt_ PULONG MaxMessageLength,
    _Inout_updates_bytes_to_opt_(*ConnectionInformationLength, *ConnectionInformationLength) PVOID ConnectionInformation,
    _Inout_opt_ PULONG ConnectionInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSecureConnectPort* volatile ScSecureConnectPort;

typedef
NTSTATUS
NTAPI
FN_ScSerializeBoot(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSerializeBoot* volatile ScSerializeBoot;

typedef
NTSTATUS
NTAPI
FN_ScSetBootEntryOrder(
    _In_reads_(Count) PULONG Ids,
    _In_ ULONG Count
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetBootEntryOrder* volatile ScSetBootEntryOrder;

typedef
NTSTATUS
NTAPI
FN_ScSetBootOptions(
    _In_ PBOOT_OPTIONS BootOptions,
    _In_ ULONG FieldsToChange
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetBootOptions* volatile ScSetBootOptions;

typedef
NTSTATUS
NTAPI
FN_ScSetCachedSigningLevel(
    _In_ ULONG Flags,
    _In_ SE_SIGNING_LEVEL InputSigningLevel,
    _In_reads_(SourceFileCount) PHANDLE SourceFiles,
    _In_ ULONG SourceFileCount,
    _In_opt_ HANDLE TargetFile
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetCachedSigningLevel* volatile ScSetCachedSigningLevel;

typedef
NTSTATUS
NTAPI
FN_ScSetCachedSigningLevel2(
    _In_ ULONG Flags,
    _In_ SE_SIGNING_LEVEL InputSigningLevel,
    _In_reads_(SourceFileCount) PHANDLE SourceFiles,
    _In_ ULONG SourceFileCount,
    _In_opt_ HANDLE TargetFile,
    _In_opt_ SE_SET_FILE_CACHE_INFORMATION* CacheInformation
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetCachedSigningLevel2* volatile ScSetCachedSigningLevel2;

typedef
NTSTATUS
NTAPI
FN_ScSetContextThread(
    _In_ HANDLE ThreadHandle,
    _In_ PCONTEXT ThreadContext
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetContextThread* volatile ScSetContextThread;

typedef
NTSTATUS
NTAPI
FN_ScSetDebugFilterState(
    _In_ ULONG ComponentId,
    _In_ ULONG Level,
    _In_ BOOLEAN State
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetDebugFilterState* volatile ScSetDebugFilterState;

typedef
NTSTATUS
NTAPI
FN_ScSetDefaultHardErrorPort(
    _In_ HANDLE DefaultHardErrorPort
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetDefaultHardErrorPort* volatile ScSetDefaultHardErrorPort;

typedef
NTSTATUS
NTAPI
FN_ScSetDefaultLocale(
    _In_ BOOLEAN UserProfile,
    _In_ LCID DefaultLocaleId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetDefaultLocale* volatile ScSetDefaultLocale;

typedef
NTSTATUS
NTAPI
FN_ScSetDefaultUILanguage(
    _In_ LANGID DefaultUILanguageId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetDefaultUILanguage* volatile ScSetDefaultUILanguage;

typedef
NTSTATUS
NTAPI
FN_ScSetDriverEntryOrder(
    _In_reads_(Count) PULONG Ids,
    _In_ ULONG Count
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetDriverEntryOrder* volatile ScSetDriverEntryOrder;

typedef
NTSTATUS
NTAPI
FN_ScSetEaFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_reads_bytes_(Length) PVOID Buffer,
    _In_ ULONG Length
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetEaFile* volatile ScSetEaFile;

typedef
NTSTATUS
NTAPI
FN_ScSetEvent(
    _In_ HANDLE EventHandle,
    _Out_opt_ PLONG PreviousState
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetEvent* volatile ScSetEvent;

typedef
NTSTATUS
NTAPI
FN_ScSetEventEx(
    _In_ HANDLE ThreadId,
    _In_opt_ PRTL_SRWLOCK Lock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetEventEx* volatile ScSetEventEx;

typedef
NTSTATUS
NTAPI
FN_ScSetEventBoostPriority(
    _In_ HANDLE EventHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetEventBoostPriority* volatile ScSetEventBoostPriority;

typedef
NTSTATUS
NTAPI
FN_ScSetHighEventPair(
    _In_ HANDLE EventPairHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetHighEventPair* volatile ScSetHighEventPair;

typedef
NTSTATUS
NTAPI
FN_ScSetHighWaitLowEventPair(
    _In_ HANDLE EventPairHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetHighWaitLowEventPair* volatile ScSetHighWaitLowEventPair;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationDebugObject(
    _In_ HANDLE DebugObjectHandle,
    _In_ DEBUGOBJECTINFOCLASS DebugObjectInformationClass,
    _In_reads_bytes_(DebugInformationLength) PVOID DebugInformation,
    _In_ ULONG DebugInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationDebugObject* volatile ScSetInformationDebugObject;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationEnlistment(
    _In_opt_ HANDLE EnlistmentHandle,
    _In_ ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass,
    _In_reads_bytes_(EnlistmentInformationLength) PVOID EnlistmentInformation,
    _In_ ULONG EnlistmentInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationEnlistment* volatile ScSetInformationEnlistment;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_reads_bytes_(Length) PVOID FileInformation,
    _In_ ULONG Length,
    _In_ FILE_INFORMATION_CLASS FileInformationClass
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationFile* volatile ScSetInformationFile;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationIoRing(
    _In_ HANDLE IoRingHandle,
    _In_ ULONG IoRingInformationClass,
    _In_ ULONG IoRingInformationLength,
    _In_ PVOID IoRingInformation
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationIoRing* volatile ScSetInformationIoRing;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationJobObject(
    _In_ HANDLE JobHandle,
    _In_ JOBOBJECTINFOCLASS JobObjectInformationClass,
    _In_reads_bytes_(JobObjectInformationLength) PVOID JobObjectInformation,
    _In_ ULONG JobObjectInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationJobObject* volatile ScSetInformationJobObject;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationKey(
    _In_ HANDLE KeyHandle,
    _In_ KEY_SET_INFORMATION_CLASS KeySetInformationClass,
    _In_reads_bytes_(KeySetInformationLength) PVOID KeySetInformation,
    _In_ ULONG KeySetInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationKey* volatile ScSetInformationKey;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationObject(
    _In_ HANDLE Handle,
    _In_ OBJECT_INFORMATION_CLASS ObjectInformationClass,
    _In_reads_bytes_(ObjectInformationLength) PVOID ObjectInformation,
    _In_ ULONG ObjectInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationObject* volatile ScSetInformationObject;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationProcess(
    _In_ HANDLE ProcessHandle,
    _In_ PROCESSINFOCLASS ProcessInformationClass,
    _In_reads_bytes_(ProcessInformationLength) PVOID ProcessInformation,
    _In_ ULONG ProcessInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationProcess* volatile ScSetInformationProcess;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationResourceManager(
    _In_ HANDLE ResourceManagerHandle,
    _In_ RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
    _In_reads_bytes_(ResourceManagerInformationLength) PVOID ResourceManagerInformation,
    _In_ ULONG ResourceManagerInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationResourceManager* volatile ScSetInformationResourceManager;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationSymbolicLink(
    _In_ HANDLE LinkHandle,
    _In_ SYMBOLIC_LINK_INFO_CLASS SymbolicLinkInformationClass,
    _In_reads_bytes_(SymbolicLinkInformationLength) PVOID SymbolicLinkInformation,
    _In_ ULONG SymbolicLinkInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationSymbolicLink* volatile ScSetInformationSymbolicLink;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationThread(
    _In_ HANDLE ThreadHandle,
    _In_ THREADINFOCLASS ThreadInformationClass,
    _In_reads_bytes_(ThreadInformationLength) PVOID ThreadInformation,
    _In_ ULONG ThreadInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationThread* volatile ScSetInformationThread;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationToken(
    _In_ HANDLE TokenHandle,
    _In_ TOKEN_INFORMATION_CLASS TokenInformationClass,
    _In_reads_bytes_(TokenInformationLength) PVOID TokenInformation,
    _In_ ULONG TokenInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationToken* volatile ScSetInformationToken;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationTransaction(
    _In_ HANDLE TransactionHandle,
    _In_ TRANSACTION_INFORMATION_CLASS TransactionInformationClass,
    _In_reads_bytes_(TransactionInformationLength) PVOID TransactionInformation,
    _In_ ULONG TransactionInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationTransaction* volatile ScSetInformationTransaction;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationTransactionManager(
    _In_opt_ HANDLE TmHandle,
    _In_ TRANSACTIONMANAGER_INFORMATION_CLASS TransactionManagerInformationClass,
    _In_reads_bytes_(TransactionManagerInformationLength) PVOID TransactionManagerInformation,
    _In_ ULONG TransactionManagerInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationTransactionManager* volatile ScSetInformationTransactionManager;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _In_ VIRTUAL_MEMORY_INFORMATION_CLASS VmInformationClass,
    _In_ SIZE_T NumberOfEntries,
    _In_reads_(NumberOfEntries) PMEMORY_RANGE_ENTRY VirtualAddresses,
    _In_reads_bytes_(VmInformationLength) PVOID VmInformation,
    _In_ ULONG VmInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationVirtualMemory* volatile ScSetInformationVirtualMemory;

typedef
NTSTATUS
NTAPI
FN_ScSetInformationWorkerFactory(
    _In_ HANDLE WorkerFactoryHandle,
    _In_ WORKERFACTORYINFOCLASS WorkerFactoryInformationClass,
    _In_reads_bytes_(WorkerFactoryInformationLength) PVOID WorkerFactoryInformation,
    _In_ ULONG WorkerFactoryInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetInformationWorkerFactory* volatile ScSetInformationWorkerFactory;

typedef
NTSTATUS
NTAPI
FN_ScSetIntervalProfile(
    _In_ ULONG Interval,
    _In_ KPROFILE_SOURCE Source
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetIntervalProfile* volatile ScSetIntervalProfile;

typedef
NTSTATUS
NTAPI
FN_ScSetIoCompletion(
    _In_ HANDLE IoCompletionHandle,
    _In_opt_ PVOID KeyContext,
    _In_opt_ PVOID ApcContext,
    _In_ NTSTATUS IoStatus,
    _In_ ULONG_PTR IoStatusInformation
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetIoCompletion* volatile ScSetIoCompletion;

typedef
NTSTATUS
NTAPI
FN_ScSetIoCompletionEx(
    _In_ HANDLE IoCompletionHandle,
    _In_ HANDLE IoCompletionPacketHandle,
    _In_opt_ PVOID KeyContext,
    _In_opt_ PVOID ApcContext,
    _In_ NTSTATUS IoStatus,
    _In_ ULONG_PTR IoStatusInformation
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetIoCompletionEx* volatile ScSetIoCompletionEx;

typedef
NTSTATUS
NTAPI
FN_ScSetIRTimer(
    _In_ HANDLE TimerHandle,
    _In_opt_ PLARGE_INTEGER DueTime
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetIRTimer* volatile ScSetIRTimer;

typedef
NTSTATUS
NTAPI
FN_ScSetLdtEntries(
    _In_ ULONG Selector0,
    _In_ ULONG Entry0Low,
    _In_ ULONG Entry0Hi,
    _In_ ULONG Selector1,
    _In_ ULONG Entry1Low,
    _In_ ULONG Entry1Hi
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetLdtEntries* volatile ScSetLdtEntries;

typedef
NTSTATUS
NTAPI
FN_ScSetLowEventPair(
    _In_ HANDLE EventPairHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetLowEventPair* volatile ScSetLowEventPair;

typedef
NTSTATUS
NTAPI
FN_ScSetLowWaitHighEventPair(
    _In_ HANDLE EventPairHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetLowWaitHighEventPair* volatile ScSetLowWaitHighEventPair;

typedef
NTSTATUS
NTAPI
FN_ScSetQuotaInformationFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_reads_bytes_(Length) PVOID Buffer,
    _In_ ULONG Length
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetQuotaInformationFile* volatile ScSetQuotaInformationFile;

typedef
NTSTATUS
NTAPI
FN_ScSetSecurityObject(
    _In_ HANDLE Handle,
    _In_ SECURITY_INFORMATION SecurityInformation,
    _In_ PSECURITY_DESCRIPTOR SecurityDescriptor
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetSecurityObject* volatile ScSetSecurityObject;

typedef
NTSTATUS
NTAPI
FN_ScSetSystemEnvironmentValue(
    _In_ PUNICODE_STRING VariableName,
    _In_ PUNICODE_STRING VariableValue
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetSystemEnvironmentValue* volatile ScSetSystemEnvironmentValue;

typedef
NTSTATUS
NTAPI
FN_ScSetSystemEnvironmentValueEx(
    _In_ PUNICODE_STRING VariableName,
    _In_ PCGUID VendorGuid,
    _In_reads_bytes_opt_(BufferLength) PVOID Buffer,
    _In_ ULONG BufferLength, // 0 = delete variable
    _In_ ULONG Attributes // EFI_VARIABLE_*
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetSystemEnvironmentValueEx* volatile ScSetSystemEnvironmentValueEx;

typedef
NTSTATUS
NTAPI
FN_ScSetSystemInformation(
    _In_ SYSTEM_INFORMATION_CLASS SystemInformationClass,
    _In_reads_bytes_opt_(SystemInformationLength) PVOID SystemInformation,
    _In_ ULONG SystemInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetSystemInformation* volatile ScSetSystemInformation;

typedef
NTSTATUS
NTAPI
FN_ScSetSystemPowerState(
    _In_ POWER_ACTION SystemAction,
    _In_ SYSTEM_POWER_STATE LightestSystemState,
    _In_ ULONG Flags // POWER_ACTION_* flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetSystemPowerState* volatile ScSetSystemPowerState;

typedef
NTSTATUS
NTAPI
FN_ScSetSystemTime(
    _In_opt_ PLARGE_INTEGER SystemTime,
    _Out_opt_ PLARGE_INTEGER PreviousTime
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetSystemTime* volatile ScSetSystemTime;

typedef
NTSTATUS
NTAPI
FN_ScSetThreadExecutionState(
    _In_ EXECUTION_STATE NewFlags, // ES_* flags
    _Out_ EXECUTION_STATE *PreviousFlags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetThreadExecutionState* volatile ScSetThreadExecutionState;

typedef
NTSTATUS
NTAPI
FN_ScSetTimer(
    _In_ HANDLE TimerHandle,
    _In_ PLARGE_INTEGER DueTime,
    _In_opt_ PTIMER_APC_ROUTINE TimerApcRoutine,
    _In_opt_ PVOID TimerContext,
    _In_ BOOLEAN ResumeTimer,
    _In_opt_ LONG Period,
    _Out_opt_ PBOOLEAN PreviousState
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetTimer* volatile ScSetTimer;

typedef
NTSTATUS
NTAPI
FN_ScSetTimer2(
    _In_ HANDLE TimerHandle,
    _In_ PLARGE_INTEGER DueTime,
    _In_opt_ PLARGE_INTEGER Period,
    _In_ PT2_SET_PARAMETERS Parameters
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetTimer2* volatile ScSetTimer2;

typedef
NTSTATUS
NTAPI
FN_ScSetTimerEx(
    _In_ HANDLE TimerHandle,
    _In_ TIMER_SET_INFORMATION_CLASS TimerSetInformationClass,
    _Inout_updates_bytes_opt_(TimerSetInformationLength) PVOID TimerSetInformation,
    _In_ ULONG TimerSetInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetTimerEx* volatile ScSetTimerEx;

typedef
NTSTATUS
NTAPI
FN_ScSetTimerResolution(
    _In_ ULONG DesiredTime,
    _In_ BOOLEAN SetResolution,
    _Out_ PULONG ActualTime
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetTimerResolution* volatile ScSetTimerResolution;

typedef
NTSTATUS
NTAPI
FN_ScSetUuidSeed(
    _In_ PCHAR Seed
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetUuidSeed* volatile ScSetUuidSeed;

typedef
NTSTATUS
NTAPI
FN_ScSetValueKey(
    _In_ HANDLE KeyHandle,
    _In_ PUNICODE_STRING ValueName,
    _In_opt_ ULONG TitleIndex,
    _In_ ULONG Type,
    _In_reads_bytes_opt_(DataSize) PVOID Data,
    _In_ ULONG DataSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetValueKey* volatile ScSetValueKey;

typedef
NTSTATUS
NTAPI
FN_ScSetVolumeInformationFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_reads_bytes_(Length) PVOID FsInformation,
    _In_ ULONG Length,
    _In_ FSINFOCLASS FsInformationClass
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetVolumeInformationFile* volatile ScSetVolumeInformationFile;

typedef
NTSTATUS
NTAPI
FN_ScSetWnfProcessNotificationEvent(
    _In_ HANDLE NotificationEvent
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSetWnfProcessNotificationEvent* volatile ScSetWnfProcessNotificationEvent;

typedef
NTSTATUS
NTAPI
FN_ScShutdownSystem(
    _In_ SHUTDOWN_ACTION Action
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScShutdownSystem* volatile ScShutdownSystem;

typedef
NTSTATUS
NTAPI
FN_ScShutdownWorkerFactory(
    _In_ HANDLE WorkerFactoryHandle,
    _Inout_ volatile LONG *PendingWorkerCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScShutdownWorkerFactory* volatile ScShutdownWorkerFactory;

typedef
NTSTATUS
NTAPI
FN_ScSignalAndWaitForSingleObject(
    _In_ HANDLE SignalHandle,
    _In_ HANDLE WaitHandle,
    _In_ BOOLEAN Alertable,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSignalAndWaitForSingleObject* volatile ScSignalAndWaitForSingleObject;

typedef
NTSTATUS
NTAPI
FN_ScSinglePhaseReject(
    _In_ HANDLE EnlistmentHandle,
    _In_opt_ PLARGE_INTEGER TmVirtualClock
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSinglePhaseReject* volatile ScSinglePhaseReject;

typedef
NTSTATUS
NTAPI
FN_ScStartProfile(
    _In_ HANDLE ProfileHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScStartProfile* volatile ScStartProfile;

typedef
NTSTATUS
NTAPI
FN_ScStopProfile(
    _In_ HANDLE ProfileHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScStopProfile* volatile ScStopProfile;

typedef
NTSTATUS
NTAPI
FN_ScSubmitIoRing(
    _In_ HANDLE IoRingHandle,
    _In_ ULONG Flags,
    _In_opt_ ULONG WaitOperations,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSubmitIoRing* volatile ScSubmitIoRing;

typedef
NTSTATUS
NTAPI
FN_ScSubscribeWnfStateChange(
    _In_ PCWNF_STATE_NAME StateName,
    _In_opt_ WNF_CHANGE_STAMP ChangeStamp,
    _In_ ULONG EventMask,
    _Out_opt_ PULONG64 SubscriptionId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSubscribeWnfStateChange* volatile ScSubscribeWnfStateChange;

typedef
NTSTATUS
NTAPI
FN_ScSuspendProcess(
    _In_ HANDLE ProcessHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSuspendProcess* volatile ScSuspendProcess;

typedef
NTSTATUS
NTAPI
FN_ScSuspendThread(
    _In_ HANDLE ThreadHandle,
    _Out_opt_ PULONG PreviousSuspendCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSuspendThread* volatile ScSuspendThread;

typedef
NTSTATUS
NTAPI
FN_ScSystemDebugControl(
    _In_ SYSDBG_COMMAND Command,
    _Inout_updates_bytes_opt_(InputBufferLength) PVOID InputBuffer,
    _In_ ULONG InputBufferLength,
    _Out_writes_bytes_opt_(OutputBufferLength) PVOID OutputBuffer,
    _In_ ULONG OutputBufferLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScSystemDebugControl* volatile ScSystemDebugControl;

typedef
NTSTATUS
NTAPI
FN_ScTerminateEnclave(
    _In_ PVOID BaseAddress,
    _In_ ULONG Flags // TERMINATE_ENCLAVE_FLAG_*
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScTerminateEnclave* volatile ScTerminateEnclave;

typedef
NTSTATUS
NTAPI
FN_ScTerminateJobObject(
    _In_ HANDLE JobHandle,
    _In_ NTSTATUS ExitStatus
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScTerminateJobObject* volatile ScTerminateJobObject;

typedef
NTSTATUS
NTAPI
FN_ScTerminateProcess(
    _In_opt_ HANDLE ProcessHandle,
    _In_ NTSTATUS ExitStatus
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScTerminateProcess* volatile ScTerminateProcess;

typedef
NTSTATUS
NTAPI
FN_ScTerminateThread(
    _In_opt_ HANDLE ThreadHandle,
    _In_ NTSTATUS ExitStatus
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScTerminateThread* volatile ScTerminateThread;

typedef
NTSTATUS
NTAPI
FN_ScTestAlert(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScTestAlert* volatile ScTestAlert;

typedef
NTSTATUS
NTAPI
FN_ScThawRegistry(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScThawRegistry* volatile ScThawRegistry;

typedef
NTSTATUS
NTAPI
FN_ScThawTransactions(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScThawTransactions* volatile ScThawTransactions;

typedef
NTSTATUS
NTAPI
FN_ScTraceControl(
    _In_ ETWTRACECONTROLCODE TraceControlCode,
    _In_reads_bytes_opt_(InputBufferLength) PVOID InputBuffer,
    _In_ ULONG InputBufferLength,
    _Out_writes_bytes_opt_(OutputBufferLength) PVOID OutputBuffer,
    _In_ ULONG OutputBufferLength,
    _Out_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScTraceControl* volatile ScTraceControl;

typedef
NTSTATUS
NTAPI
FN_ScTraceEvent(
    _In_ HANDLE TraceHandle,
    _In_ ULONG Flags,
    _In_ ULONG FieldSize,
    _In_ PVOID Fields
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScTraceEvent* volatile ScTraceEvent;

typedef
NTSTATUS
NTAPI
FN_ScTranslateFilePath(
    _In_ PFILE_PATH InputFilePath,
    _In_ ULONG OutputType,
    _Out_writes_bytes_opt_(*OutputFilePathLength) PFILE_PATH OutputFilePath,
    _Inout_opt_ PULONG OutputFilePathLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScTranslateFilePath* volatile ScTranslateFilePath;

typedef
NTSTATUS
NTAPI
FN_ScUmsThreadYield(
    _In_ PVOID SchedulerParam
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUmsThreadYield* volatile ScUmsThreadYield;

typedef
NTSTATUS
NTAPI
FN_ScUnloadDriver(
    _In_ PUNICODE_STRING DriverServiceName
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUnloadDriver* volatile ScUnloadDriver;

typedef
NTSTATUS
NTAPI
FN_ScUnloadKey(
    _In_ POBJECT_ATTRIBUTES TargetKey
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUnloadKey* volatile ScUnloadKey;

typedef
NTSTATUS
NTAPI
FN_ScUnloadKey2(
    _In_ POBJECT_ATTRIBUTES TargetKey,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUnloadKey2* volatile ScUnloadKey2;

typedef
NTSTATUS
NTAPI
FN_ScUnloadKeyEx(
    _In_ POBJECT_ATTRIBUTES TargetKey,
    _In_opt_ HANDLE Event
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUnloadKeyEx* volatile ScUnloadKeyEx;

typedef
NTSTATUS
NTAPI
FN_ScUnlockFile(
    _In_ HANDLE FileHandle,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ PLARGE_INTEGER ByteOffset,
    _In_ PLARGE_INTEGER Length,
    _In_ ULONG Key
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUnlockFile* volatile ScUnlockFile;

typedef
NTSTATUS
NTAPI
FN_ScUnlockVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _Inout_ PVOID *BaseAddress,
    _Inout_ PSIZE_T RegionSize,
    _In_ ULONG MapType
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUnlockVirtualMemory* volatile ScUnlockVirtualMemory;

typedef
NTSTATUS
NTAPI
FN_ScUnmapViewOfSection(
    _In_ HANDLE ProcessHandle,
    _In_opt_ PVOID BaseAddress
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUnmapViewOfSection* volatile ScUnmapViewOfSection;

typedef
NTSTATUS
NTAPI
FN_ScUnmapViewOfSectionEx(
    _In_ HANDLE ProcessHandle,
    _In_opt_ PVOID BaseAddress,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUnmapViewOfSectionEx* volatile ScUnmapViewOfSectionEx;

typedef
NTSTATUS
NTAPI
FN_ScUnsubscribeWnfStateChange(
    _In_ PCWNF_STATE_NAME StateName
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUnsubscribeWnfStateChange* volatile ScUnsubscribeWnfStateChange;

typedef
NTSTATUS
NTAPI
FN_ScUpdateWnfStateData(
    _In_ PCWNF_STATE_NAME StateName,
    _In_reads_bytes_opt_(Length) const VOID* Buffer,
    _In_opt_ ULONG Length,
    _In_opt_ PCWNF_TYPE_ID TypeId,
    _In_opt_ const VOID* ExplicitScope,
    _In_ WNF_CHANGE_STAMP MatchingChangeStamp,
    _In_ LOGICAL CheckStamp
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUpdateWnfStateData* volatile ScUpdateWnfStateData;

typedef
NTSTATUS
NTAPI
FN_ScVdmControl(
    _In_ VDMSERVICECLASS Service,
    _Inout_ PVOID ServiceData
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScVdmControl* volatile ScVdmControl;

typedef
NTSTATUS
NTAPI
FN_ScWaitForAlertByThreadId(
    _In_opt_ PVOID Address,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWaitForAlertByThreadId* volatile ScWaitForAlertByThreadId;

typedef
NTSTATUS
NTAPI
FN_ScWaitForDebugEvent(
    _In_ HANDLE DebugObjectHandle,
    _In_ BOOLEAN Alertable,
    _In_opt_ PLARGE_INTEGER Timeout,
    _Out_ PDBGUI_WAIT_STATE_CHANGE WaitStateChange
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWaitForDebugEvent* volatile ScWaitForDebugEvent;

typedef
NTSTATUS
NTAPI
FN_ScWaitForKeyedEvent(
    _In_opt_ HANDLE KeyedEventHandle,
    _In_ PVOID KeyValue,
    _In_ BOOLEAN Alertable,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWaitForKeyedEvent* volatile ScWaitForKeyedEvent;

typedef
NTSTATUS
NTAPI
FN_ScWaitForMultipleObjects(
    _In_ ULONG Count,
    _In_reads_(Count) HANDLE Handles[],
    _In_ WAIT_TYPE WaitType,
    _In_ BOOLEAN Alertable,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWaitForMultipleObjects* volatile ScWaitForMultipleObjects;

typedef
NTSTATUS
NTAPI
FN_ScWaitForMultipleObjects32(
    _In_ ULONG Count,
    _In_reads_(Count) LONG Handles[],
    _In_ WAIT_TYPE WaitType,
    _In_ BOOLEAN Alertable,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWaitForMultipleObjects32* volatile ScWaitForMultipleObjects32;

typedef
NTSTATUS
NTAPI
FN_ScWaitForSingleObject(
    _In_ HANDLE Handle,
    _In_ BOOLEAN Alertable,
    _In_opt_ PLARGE_INTEGER Timeout
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWaitForSingleObject* volatile ScWaitForSingleObject;

typedef
NTSTATUS
NTAPI
FN_ScWaitForWorkViaWorkerFactory(
    _In_ HANDLE WorkerFactoryHandle,
    _Out_writes_to_(Count, *PacketsReturned) PFILE_IO_COMPLETION_INFORMATION MiniPackets,
    _In_ ULONG Count,
    _Out_ PULONG PacketsReturned,
    _In_ PWORKER_FACTORY_DEFERRED_WORK DeferredWork
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWaitForWorkViaWorkerFactory* volatile ScWaitForWorkViaWorkerFactory;

typedef
NTSTATUS
NTAPI
FN_ScWaitHighEventPair(
    _In_ HANDLE EventPairHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWaitHighEventPair* volatile ScWaitHighEventPair;

typedef
NTSTATUS
NTAPI
FN_ScWaitLowEventPair(
    _In_ HANDLE EventPairHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWaitLowEventPair* volatile ScWaitLowEventPair;

typedef
NTSTATUS
NTAPI
FN_ScWorkerFactoryWorkerReady(
    _In_ HANDLE WorkerFactoryHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWorkerFactoryWorkerReady* volatile ScWorkerFactoryWorkerReady;

typedef
NTSTATUS
NTAPI
FN_ScWow64AllocateVirtualMemory64(
    _In_ HANDLE ProcessHandle,
    _Inout_ _At_(*BaseAddress,
                 _Readable_bytes_(*RegionSize)
                 _Writable_bytes_(*RegionSize)
                 _Post_readable_byte_size_(*RegionSize)) PULONGLONG BaseAddress,
    _In_ ULONGLONG ZeroBits,
    _Inout_ PULONGLONG RegionSize,
    _In_ ULONG AllocationType,
    _In_ ULONG Protect
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWow64AllocateVirtualMemory64* volatile ScWow64AllocateVirtualMemory64;

typedef
NTSTATUS
NTAPI
FN_ScWow64GetNativeSystemInformation(
    _In_ SYSTEM_INFORMATION_CLASS SystemInformationClass,
    _In_ PVOID NativeSystemInformation,
    _In_ ULONG InformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWow64GetNativeSystemInformation* volatile ScWow64GetNativeSystemInformation;

typedef
BOOLEAN
NTAPI
FN_ScWow64IsProcessorFeaturePresent(
    _In_ ULONG ProcessorFeature
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWow64IsProcessorFeaturePresent* volatile ScWow64IsProcessorFeaturePresent;

typedef
NTSTATUS
NTAPI
FN_ScWow64QueryInformationProcess64(
    _In_ HANDLE ProcessHandle,
    _In_ PROCESSINFOCLASS ProcessInformationClass,
    _Out_writes_bytes_to_(ProcessInformationLength, *ReturnLength) PVOID ProcessInformation,
    _In_ ULONG ProcessInformationLength,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWow64QueryInformationProcess64* volatile ScWow64QueryInformationProcess64;

typedef
NTSTATUS
NTAPI
FN_ScWow64ReadVirtualMemory64(
    _In_ HANDLE ProcessHandle,
    _In_ ULONGLONG BaseAddress,
    _Out_writes_bytes_to_(NumberOfBytesToRead, *NumberOfBytesRead) PVOID Buffer,
    _In_ ULONGLONG NumberOfBytesToRead,
    _Out_opt_ PULONGLONG NumberOfBytesRead
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWow64ReadVirtualMemory64* volatile ScWow64ReadVirtualMemory64;

typedef
NTSTATUS
NTAPI
FN_ScWow64WriteVirtualMemory64(
    _In_ HANDLE ProcessHandle,
    _In_ ULONGLONG BaseAddress,
    _In_reads_bytes_(NumberOfBytesToWrite) PVOID Buffer,
    _In_ ULONGLONG NumberOfBytesToWrite,
    _Out_opt_ PULONGLONG NumberOfBytesWritten
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWow64WriteVirtualMemory64* volatile ScWow64WriteVirtualMemory64;

typedef
NTSTATUS
NTAPI
FN_ScWriteFile(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_reads_bytes_(Length) PVOID Buffer,
    _In_ ULONG Length,
    _In_opt_ PLARGE_INTEGER ByteOffset,
    _In_opt_ PULONG Key
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWriteFile* volatile ScWriteFile;

typedef
NTSTATUS
NTAPI
FN_ScWriteFileGather(
    _In_ HANDLE FileHandle,
    _In_opt_ HANDLE Event,
    _In_opt_ PIO_APC_ROUTINE ApcRoutine,
    _In_opt_ PVOID ApcContext,
    _Out_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ PFILE_SEGMENT_ELEMENT SegmentArray,
    _In_ ULONG Length,
    _In_opt_ PLARGE_INTEGER ByteOffset,
    _In_opt_ PULONG Key
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWriteFileGather* volatile ScWriteFileGather;

typedef
NTSTATUS
NTAPI
FN_ScWriteRequestData(
    _In_ HANDLE PortHandle,
    _In_ PPORT_MESSAGE Message,
    _In_ ULONG DataEntryIndex,
    _In_reads_bytes_(BufferSize) PVOID Buffer,
    _In_ SIZE_T BufferSize,
    _Out_opt_ PSIZE_T NumberOfBytesWritten
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWriteRequestData* volatile ScWriteRequestData;

typedef
NTSTATUS
NTAPI
FN_ScWriteVirtualMemory(
    _In_ HANDLE ProcessHandle,
    _In_ PVOID BaseAddress,
    _In_reads_bytes_(NumberOfBytesToWrite) PVOID Buffer,
    _In_ SIZE_T NumberOfBytesToWrite,
    _Out_opt_ PSIZE_T NumberOfBytesWritten
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScWriteVirtualMemory* volatile ScWriteVirtualMemory;

typedef
NTSTATUS
NTAPI
FN_ScYieldExecution(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScYieldExecution* volatile ScYieldExecution;

typedef
NTSTATUS
NTAPI
FN_ScUserAttachThreadInput(
    _In_ ULONG IdAttach,
    _In_ ULONG IdAttachTo,
    _In_ BOOL Attach
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserAttachThreadInput* volatile ScUserAttachThreadInput;

typedef
HDC
NTAPI
FN_ScUserBeginPaint(
    _In_ HWND WindowHandle,
    _Inout_ LPPAINTSTRUCT lpPaint
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserBeginPaint* volatile ScUserBeginPaint;

typedef
BOOL
NTAPI
FN_ScUserBlockInput(
    _In_ BOOL BlockInput
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserBlockInput* volatile ScUserBlockInput;

typedef
HWND
NTAPI
FN_ScUserFindWindowEx(
    _In_opt_ HWND hwndParent,
    _In_opt_ HWND hwndChild,
    _In_ PCUNICODE_STRING ClassName,
    _In_ PCUNICODE_STRING WindowName,
    _In_ ULONG Type // FW_*
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserFindWindowEx* volatile ScUserFindWindowEx;

typedef
NTSTATUS
NTAPI
FN_ScUserBuildHwndList(
    _In_opt_ HANDLE DesktopHandle,
    _In_opt_ HWND StartWindowHandle,
    _In_opt_ LOGICAL IncludeChildren,
    _In_opt_ LOGICAL ExcludeImmersive,
    _In_opt_ ULONG ThreadId,
    _In_ ULONG HwndListInformationLength,
    _Out_writes_bytes_(HwndListInformationLength) PVOID HwndListInformation,
    _Out_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserBuildHwndList* volatile ScUserBuildHwndList;

typedef
NTSTATUS
NTAPI
FN_ScUserBuildNameList(
    _In_ HWINSTA WindowStationHandle, // GetProcessWindowStation
    _In_ ULONG NameListInformationLength,
    _Out_writes_bytes_(NameListInformationLength) PVOID NameListInformation,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserBuildNameList* volatile ScUserBuildNameList;

typedef
NTSTATUS
NTAPI
FN_ScUserBuildPropList(
    _In_ HWINSTA WindowStationHandle,
    _In_ ULONG PropListInformationLength,
    _Out_writes_bytes_(PropListInformationLength) PVOID PropListInformation,
    _Out_opt_ PULONG ReturnLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserBuildPropList* volatile ScUserBuildPropList;

typedef
LOGICAL
NTAPI
FN_ScUserCanCurrentThreadChangeForeground(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserCanCurrentThreadChangeForeground* volatile ScUserCanCurrentThreadChangeForeground;

typedef
BOOL
NTAPI
FN_ScUserCalculatePopupWindowPosition(
    _In_ const POINT* anchorPoint,
    _In_ const SIZE* windowSize,
    _In_ ULONG flags,
    _Inout_ RECT* excludeRect,
    _Inout_ RECT* popupWindowPosition
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserCalculatePopupWindowPosition* volatile ScUserCalculatePopupWindowPosition;

typedef
NTSTATUS
NTAPI
FN_ScUserCheckAccessForIntegrityLevel(
    _In_ ULONG ProcessIdFirst,
    _In_ ULONG ProcessIdSecond,
    _Out_ PBOOLEAN GrantedAccess
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserCheckAccessForIntegrityLevel* volatile ScUserCheckAccessForIntegrityLevel;

typedef
NTSTATUS
NTAPI
FN_ScUserCheckProcessForClipboardAccess(
    _In_ ULONG ProcessId,
    _Out_ PULONG GrantedAccess
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserCheckProcessForClipboardAccess* volatile ScUserCheckProcessForClipboardAccess;

typedef
LOGICAL
NTAPI
FN_ScUserCloseWindowStation(
    _In_ HWINSTA WindowStationHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserCloseWindowStation* volatile ScUserCloseWindowStation;

typedef
LOGICAL
NTAPI
FN_ScUserDisableProcessWindowsGhosting(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserDisableProcessWindowsGhosting* volatile ScUserDisableProcessWindowsGhosting;

typedef
NTSTATUS
NTAPI
FN_ScUserConsoleControl(
    _In_ CONSOLECONTROL Command,
    _In_reads_bytes_(ConsoleInformationLength) PVOID ConsoleInformation,
    _In_ ULONG ConsoleInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserConsoleControl* volatile ScUserConsoleControl;

typedef
NTSTATUS
NTAPI
FN_ScUserCreateWindowStation(
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ACCESS_MASK DesiredAccess,
    _In_opt_ HANDLE KeyboardLayoutHandle,
    _In_opt_ PVOID KeyboardLayoutOffset,
    _In_opt_ PVOID NlsTableOffset,
    _In_opt_ PVOID KeyboardDescriptor,
    _In_opt_ PUNICODE_STRING LanguageIdString,
    _In_opt_ ULONG KeyboardLocale
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserCreateWindowStation* volatile ScUserCreateWindowStation;

typedef
HWND
NTAPI
FN_ScUserGetClassName(
    _In_ HWND WindowHandle,
    _In_ BOOL Real,
    _Out_ PUNICODE_STRING ClassName
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetClassName* volatile ScUserGetClassName;

typedef
HWND
NTAPI
FN_ScUserGetForegroundWindow(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetForegroundWindow* volatile ScUserGetForegroundWindow;

typedef
LOGICAL
NTAPI
FN_ScUserGetIconInfo(
    _In_ HICON IconOrCursorHandle,
    _Out_ PICONINFO Iconinfo,
    _Inout_opt_ PUNICODE_STRING Name,
    _Inout_opt_ PUNICODE_STRING ResourceId,
    _Out_opt_ PULONG ColorBits,
    _In_ LOGICAL IsCursorHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetIconInfo* volatile ScUserGetIconInfo;

typedef
LOGICAL
NTAPI
FN_ScUserGetIconSize(
    _In_ HGDIOBJ IconOrCursorHandle,
    _In_ LOGICAL IsCursorHandle,
    _Out_ PULONG XX,
    _Out_ PULONG YY
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetIconSize* volatile ScUserGetIconSize;

typedef
HWND
NTAPI
FN_ScUserGetProcessWindowStation(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetProcessWindowStation* volatile ScUserGetProcessWindowStation;

typedef
ULONG_PTR
NTAPI
FN_ScUserGetThreadState(
    _In_ ULONG UserThreadState
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetThreadState* volatile ScUserGetThreadState;

typedef
HWND
NTAPI
FN_ScUserGhostWindowFromHungWindow(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGhostWindowFromHungWindow* volatile ScUserGhostWindowFromHungWindow;

typedef
HWND
NTAPI
FN_ScUserHungWindowFromGhostWindow(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserHungWindowFromGhostWindow* volatile ScUserHungWindowFromGhostWindow;

typedef
ULONG
NTAPI
FN_ScUserInternalGetWindowText(
    _In_ HWND WindowHandle,
    _Out_writes_to_(cchMaxCount, return + 1) LPWSTR pString,
    _In_ ULONG cchMaxCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserInternalGetWindowText* volatile ScUserInternalGetWindowText;

typedef
HICON
NTAPI
FN_ScUserInternalGetWindowIcon(
    _In_ HWND WindowHandle,
    _In_ ULONG IconType
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserInternalGetWindowIcon* volatile ScUserInternalGetWindowIcon;

typedef
HANDLE
NTAPI
FN_ScUserOpenDesktop(
    _In_ PCOBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ULONG Flags,
    _In_ ACCESS_MASK DesiredAccess
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserOpenDesktop* volatile ScUserOpenDesktop;

typedef
HWINSTA
NTAPI
FN_ScUserOpenWindowStation(
    _In_ POBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ACCESS_MASK DesiredAccess
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserOpenWindowStation* volatile ScUserOpenWindowStation;

typedef
ULONG_PTR
NTAPI
FN_ScUserQueryWindow(
    _In_ HWND WindowHandle,
    _In_ WINDOWINFOCLASS WindowInfo
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserQueryWindow* volatile ScUserQueryWindow;

typedef
HWND
NTAPI
FN_ScUserSetActiveWindow(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetActiveWindow* volatile ScUserSetActiveWindow;

typedef
LPARAM
NTAPI
FN_ScUserSetMessageExtraInfo(
    _In_ LPARAM lParam
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetMessageExtraInfo* volatile ScUserSetMessageExtraInfo;

typedef
NTSTATUS
NTAPI
FN_ScUserSetChildWindowNoActivate(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetChildWindowNoActivate* volatile ScUserSetChildWindowNoActivate;

typedef
HWND
NTAPI
FN_ScUserSetFocus(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetFocus* volatile ScUserSetFocus;

typedef
NTSTATUS
NTAPI
FN_ScUserSetInformationThread(
    _In_ HANDLE ThreadHandle,
    _In_ USERTHREADINFOCLASS ThreadInformationClass,
    _In_reads_bytes_(ThreadInformationLength) PVOID ThreadInformation,
    _In_ ULONG ThreadInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetInformationThread* volatile ScUserSetInformationThread;

typedef
LOGICAL
NTAPI
FN_ScUserSetProcessWindowStation(
    _In_ HWINSTA WindowStationHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetProcessWindowStation* volatile ScUserSetProcessWindowStation;

typedef
BOOL
NTAPI
FN_ScUserSetWindowPlacement(
    _In_  HWND WindowHandle,
    _Inout_ const WINDOWPLACEMENT* lpwndpl
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetWindowPlacement* volatile ScUserSetWindowPlacement;

typedef
LOGICAL
NTAPI
FN_ScUserSetWindowStationUser(
    _In_ HWINSTA WindowStationHandle,
    _In_ PLUID UserLogonId,
    _In_ PSID UserSid,
    _In_ ULONG UserSidLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetWindowStationUser* volatile ScUserSetWindowStationUser;

typedef
NTSTATUS
NTAPI
FN_ScUserTestForInteractiveUser(
    _In_ PLUID AuthenticationId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserTestForInteractiveUser* volatile ScUserTestForInteractiveUser;

typedef
LOGICAL
NTAPI
FN_ScUserSwitchDesktop(
    _In_ HDESK DesktopHandle,
    _In_opt_ ULONG Flags,
    _In_opt_ ULONG FadeTime
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSwitchDesktop* volatile ScUserSwitchDesktop;

typedef
LOGICAL
NTAPI
FN_ScUserSetThreadDesktop(
    _In_ HDESK DesktopHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetThreadDesktop* volatile ScUserSetThreadDesktop;

typedef
HWND
NTAPI
FN_ScUserChildWindowFromPointEx(
    _In_ HWND WindowHandle,
    _In_ POINT pt,
    _In_ ULONG flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserChildWindowFromPointEx* volatile ScUserChildWindowFromPointEx;

typedef
BOOL
NTAPI
FN_ScUserClipCursor(
    _In_ const RECT* lpRect
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserClipCursor* volatile ScUserClipCursor;

typedef
BOOL
NTAPI
FN_ScUserCloseDesktop(
    _In_ HDESK DesktopHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserCloseDesktop* volatile ScUserCloseDesktop;

typedef
LONG
NTAPI
FN_ScUserCopyAcceleratorTable(
    _In_ HACCEL hAccelSrc,
    _In_ LPACCEL lpAccelDst,
    _In_ LONG cAccelEntries
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserCopyAcceleratorTable* volatile ScUserCopyAcceleratorTable;

typedef
HACCEL
NTAPI
FN_ScUserCreateAcceleratorTable(
    _In_ LPACCEL paccel,
    _In_ LONG cAccel
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserCreateAcceleratorTable* volatile ScUserCreateAcceleratorTable;

typedef
BOOL
NTAPI
FN_ScUserDeleteMenu(
    _In_ HMENU MenuHandle,
    _In_ ULONG Position,
    _In_ ULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserDeleteMenu* volatile ScUserDeleteMenu;

typedef
BOOL
NTAPI
FN_ScUserDestroyMenu(
    _In_ HMENU MenuHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserDestroyMenu* volatile ScUserDestroyMenu;

typedef
BOOL
NTAPI
FN_ScUserDestroyWindow(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserDestroyWindow* volatile ScUserDestroyWindow;

typedef
BOOL
NTAPI
FN_ScUserDragDetect(
    _In_ HWND WindowHandle,
    _In_ POINT pt
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserDragDetect* volatile ScUserDragDetect;

typedef
ULONG
NTAPI
FN_ScUserDragObject(
    _In_ HWND WindowHandleParent,
    _In_ HWND WindowHandleFrom,
    _In_ ULONG fmt,
    _In_ ULONG_PTR data,
    _In_ HCURSOR hcur
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserDragObject* volatile ScUserDragObject;

typedef
BOOL
NTAPI
FN_ScUserDrawAnimatedRects(
    _In_ HWND WindowHandle,
    _In_ int idAni,
    _In_ const RECT* lprcFrom,
    _In_ const RECT* lprcTo
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserDrawAnimatedRects* volatile ScUserDrawAnimatedRects;

typedef
BOOL
NTAPI
FN_ScUserEndMenu(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserEndMenu* volatile ScUserEndMenu;

typedef
BOOL
NTAPI
FN_ScUserEndPaint(
    _In_ HWND WindowHandle,
    _Inout_ const PAINTSTRUCT* lpPaint
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserEndPaint* volatile ScUserEndPaint;

typedef
BOOL
NTAPI
FN_ScUserEnumDisplayMonitors(
    _In_ HDC hdc,
    _In_ LPCRECT lprcClip,
    _In_ MONITORENUMPROC lpfnEnum,
    _In_ LPARAM dwData
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserEnumDisplayMonitors* volatile ScUserEnumDisplayMonitors;

typedef
HRGN
NTAPI
FN_ScUserExcludeUpdateRgn(
    _In_ HDC hDC,
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserExcludeUpdateRgn* volatile ScUserExcludeUpdateRgn;

typedef
BOOL
NTAPI
FN_ScUserFlashWindowEx(
    _In_ PFLASHWINFO pfwi
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserFlashWindowEx* volatile ScUserFlashWindowEx;

typedef
HWND
NTAPI
FN_ScUserGetAncestor(
    _In_ HWND WindowHandle,
    _In_ ULONG gaFlags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetAncestor* volatile ScUserGetAncestor;

typedef
ULONG
NTAPI
FN_ScUserGetCaretBlinkTime(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetCaretBlinkTime* volatile ScUserGetCaretBlinkTime;

typedef
BOOL
NTAPI
FN_ScUserGetCaretPos(
    _In_ LPPOINT lpPoint
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetCaretPos* volatile ScUserGetCaretPos;

typedef
BOOL
NTAPI
FN_ScUserGetClipCursor(
    _In_ LPRECT lpRect
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetClipCursor* volatile ScUserGetClipCursor;

typedef
BOOL
NTAPI
FN_ScUserGetComboBoxInfo(
    _In_ HWND WindowHandleCombo,
    _Inout_ PCOMBOBOXINFO pcbi
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetComboBoxInfo* volatile ScUserGetComboBoxInfo;

typedef
BOOL
NTAPI
FN_ScUserGetCurrentInputMessageSource(
    _Inout_ INPUT_MESSAGE_SOURCE* InputMessageSource
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetCurrentInputMessageSource* volatile ScUserGetCurrentInputMessageSource;

typedef
HCURSOR
NTAPI
FN_ScUserGetCursor(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetCursor* volatile ScUserGetCursor;

typedef
BOOL
NTAPI
FN_ScUserGetCursorInfo(
    _In_ PCURSORINFO pci
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetCursorInfo* volatile ScUserGetCursorInfo;

typedef
HDC
NTAPI
FN_ScUserGetDCEx(
    _In_ HWND WindowHandle,
    _In_ HRGN hrgnClip,
    _In_ ULONG flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetDCEx* volatile ScUserGetDCEx;

typedef
BOOL
NTAPI
FN_ScUserGetDisplayAutoRotationPreferences(
    _In_ ORIENTATION_PREFERENCE* pOrientation
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetDisplayAutoRotationPreferences* volatile ScUserGetDisplayAutoRotationPreferences;

typedef
ULONG
NTAPI
FN_ScUserGetDoubleClickTime(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetDoubleClickTime* volatile ScUserGetDoubleClickTime;

typedef
BOOL
NTAPI
FN_ScUserGetGUIThreadInfo(
    _In_ ULONG idThread,
    _In_ PGUITHREADINFO pgui
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetGUIThreadInfo* volatile ScUserGetGUIThreadInfo;

typedef
ULONG
NTAPI
FN_ScUserGetGuiResources(
    _In_ HANDLE ProcessHandle,
    _In_ ULONG uiFlags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetGuiResources* volatile ScUserGetGuiResources;

typedef
BOOL
NTAPI
FN_ScUserGetLayeredWindowAttributes(
    _In_ HWND WindowHandle,
    _In_ COLORREF* pcrKey,
    _In_ BYTE* pbAlpha,
    _In_ ULONG pdwFlags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetLayeredWindowAttributes* volatile ScUserGetLayeredWindowAttributes;

typedef
ULONG
NTAPI
FN_ScUserGetListBoxInfo(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetListBoxInfo* volatile ScUserGetListBoxInfo;

typedef
BOOL
NTAPI
FN_ScUserGetMenuBarInfo(
    _In_ HWND WindowHandle,
    _In_ LONG idObject,
    _In_ LONG idItem,
    _In_ PMENUBARINFO pmbi
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetMenuBarInfo* volatile ScUserGetMenuBarInfo;

typedef
BOOL
NTAPI
FN_ScUserGetMenuItemRect(
    _In_ HWND WindowHandle,
    _In_ HMENU MenuHandle,
    _In_ ULONG MenuIndex,
    _In_ PRECT MenuRect
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetMenuItemRect* volatile ScUserGetMenuItemRect;

typedef
LONG
NTAPI
FN_ScUserGetMouseMovePointsEx(
    _In_ ULONG MouseMovePointsSize,
    _In_ LPMOUSEMOVEPOINT InputBuffer,
    _Out_ LPMOUSEMOVEPOINT OutputBuffer,
    _In_ LONG OutputBufferCount,
    _In_ ULONG Resolution
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetMouseMovePointsEx* volatile ScUserGetMouseMovePointsEx;

typedef
ULONG
NTAPI
FN_ScUserGetRawInputData(
    _In_ HRAWINPUT RawInputData,
    _In_ ULONG RawInputCommand,
    _Out_opt_ PVOID RawInputBuffer,
    _Inout_ PULONG RawInputBufferSize,
    _In_ ULONG RawInputHeaderSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetRawInputData* volatile ScUserGetRawInputData;

typedef
ULONG
NTAPI
FN_ScUserGetRawInputDeviceList(
    _In_ PRAWINPUTDEVICELIST RawInputDeviceList,
    _Inout_ PULONG RawInputDeviceCount,
    _In_ ULONG RawInputDeviceSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetRawInputDeviceList* volatile ScUserGetRawInputDeviceList;

typedef
ULONG
NTAPI
FN_ScUserGetRegisteredRawInputDevices(
    _Out_opt_ PRAWINPUTDEVICE RawInputDevices,
    _Inout_ PULONG RawInputDeviceCount,
    _In_ ULONG RawInputDeviceSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetRegisteredRawInputDevices* volatile ScUserGetRegisteredRawInputDevices;

typedef
HMENU
NTAPI
FN_ScUserGetSendMessageReceiver(
    _In_ HANDLE ThreadId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetSendMessageReceiver* volatile ScUserGetSendMessageReceiver;

typedef
HMENU
NTAPI
FN_ScUserGetSystemMenu(
    _In_ HWND WindowHandle,
    _In_ BOOL Revert
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetSystemMenu* volatile ScUserGetSystemMenu;

typedef
HDESK
NTAPI
FN_ScUserGetThreadDesktop(
    _In_ ULONG ThreadId
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetThreadDesktop* volatile ScUserGetThreadDesktop;

typedef
BOOL
NTAPI
FN_ScUserGetTitleBarInfo(
    _In_ HWND WindowHandle,
    _In_ PTITLEBARINFO pti
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetTitleBarInfo* volatile ScUserGetTitleBarInfo;

typedef
BOOL
NTAPI
FN_ScUserGetObjectInformation(
    _In_ HANDLE ObjectHandle,
    _In_ LONG Index,
    _In_ PVOID vInfo,
    _In_ ULONG Length,
    _In_ PULONG LengthNeeded
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetObjectInformation* volatile ScUserGetObjectInformation;

typedef
HDC
NTAPI
FN_ScUserGetWindowDC(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetWindowDC* volatile ScUserGetWindowDC;

typedef
BOOL
NTAPI
FN_ScUserGetWindowPlacement(
    _In_ HWND WindowHandle,
    _Inout_ PWINDOWPLACEMENT WindowPlacement
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserGetWindowPlacement* volatile ScUserGetWindowPlacement;

typedef
BOOL
NTAPI
FN_ScUserHiliteMenuItem(
    _In_ HWND WindowHandle,
    _In_ HMENU MenuHandle,
    _In_ ULONG IDHiliteItem,
    _In_ ULONG Hilite
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserHiliteMenuItem* volatile ScUserHiliteMenuItem;

typedef
BOOL
NTAPI
FN_ScUserInvalidateRect(
    _In_ HWND WindowHandle,
    _In_ const RECT* Rect,
    _In_ BOOL Erase
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserInvalidateRect* volatile ScUserInvalidateRect;

typedef
BOOL
NTAPI
FN_ScUserInvalidateRgn(
    _In_ HWND WindowHandle,
    _In_ HRGN hRgn,
    _In_ BOOL Erase
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserInvalidateRgn* volatile ScUserInvalidateRgn;

typedef
BOOL
NTAPI
FN_ScUserIsTouchWindow(
    _In_ HWND WindowHandle,
    _In_ PULONG Flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserIsTouchWindow* volatile ScUserIsTouchWindow;

typedef
BOOL
NTAPI
FN_ScUserKillTimer(
    _In_ HWND WindowHandle,
    _In_ ULONG_PTR IDEvent
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserKillTimer* volatile ScUserKillTimer;

typedef
BOOL
NTAPI
FN_ScUserLockWorkStation(
    VOID
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserLockWorkStation* volatile ScUserLockWorkStation;

typedef
BOOL
NTAPI
FN_ScUserLogicalToPhysicalPoint(
    _In_ HWND WindowHandle,
    _In_ LPPOINT lpPoint
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserLogicalToPhysicalPoint* volatile ScUserLogicalToPhysicalPoint;

typedef
LONG
NTAPI
FN_ScUserMenuItemFromPoint(
    _In_ HWND WindowHandle,
    _In_ HMENU MenuHandle,
    _In_ POINT ptScreen
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserMenuItemFromPoint* volatile ScUserMenuItemFromPoint;

typedef
BOOL
NTAPI
FN_ScUserMoveWindow(
    _In_ HWND WindowHandle,
    _In_ LONG X,
    _In_ LONG Y,
    _In_ LONG Width,
    _In_ LONG Height,
    _In_ BOOL Repaint
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserMoveWindow* volatile ScUserMoveWindow;

typedef
HDESK
NTAPI
FN_ScUserOpenInputDesktop(
    _In_ ULONG Flags,
    _In_ BOOL Inherit,
    _In_ ACCESS_MASK DesiredAccess
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserOpenInputDesktop* volatile ScUserOpenInputDesktop;

typedef
BOOL
NTAPI
FN_ScUserPhysicalToLogicalPoint(
    _In_ HWND WindowHandle,
    _In_ LPPOINT lpPoint
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserPhysicalToLogicalPoint* volatile ScUserPhysicalToLogicalPoint;

typedef
BOOL
NTAPI
FN_ScUserPrintWindow(
    _In_ HWND WindowHandle,
    _In_ HDC hdcBlt,
    _In_ ULONG nFlags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserPrintWindow* volatile ScUserPrintWindow;

typedef
NTSTATUS
NTAPI
FN_ScUserQueryInformationThread(
    _In_ HANDLE ThreadHandle,
    _In_ USERTHREADINFOCLASS ThreadInformationClass,
    _Out_writes_bytes_(*ThreadInformationLength) PVOID ThreadInformation,
    _Out_opt_ PULONG ThreadInformationLength
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserQueryInformationThread* volatile ScUserQueryInformationThread;

typedef
NTSTATUS
NTAPI
FN_ScUserRaiseLowerShellWindow(
    _In_ HWND WindowHandle,
    _In_ BOOLEAN SetWithOptions
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserRaiseLowerShellWindow* volatile ScUserRaiseLowerShellWindow;

typedef
BOOL
NTAPI
FN_ScUserRedrawWindow(
    _In_ HWND WindowHandle,
    _In_ const PRECT lprcUpdate,
    _In_ HRGN hrgnUpdate,
    _In_ ULONG flags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserRedrawWindow* volatile ScUserRedrawWindow;

typedef
HWND
NTAPI
FN_ScUserRealChildWindowFromPoint(
    _In_ HWND WindowHandleParent,
    _In_ POINT ptParentClientCoords
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserRealChildWindowFromPoint* volatile ScUserRealChildWindowFromPoint;

typedef
BOOL
NTAPI
FN_ScUserRegisterHotKey(
    _In_ HWND WindowHandle,
    _In_ LONG id,
    _In_ ULONG fsModifiers,
    _In_ ULONG vk
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserRegisterHotKey* volatile ScUserRegisterHotKey;

typedef
BOOL
NTAPI
FN_ScUserRemoveMenu(
    _In_ HMENU MenuHandle,
    _In_ ULONG uPosition,
    _In_ ULONG uFlags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserRemoveMenu* volatile ScUserRemoveMenu;

typedef
ULONG
NTAPI
FN_ScUserSendInput(
    _In_ ULONG cInputs,
    _In_ LPINPUT pInputs,
    _In_ LONG cbSize
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSendInput* volatile ScUserSendInput;

typedef
HWND
NTAPI
FN_ScUserSetCapture(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetCapture* volatile ScUserSetCapture;

typedef
ULONG_PTR
NTAPI
FN_ScUserSetTimer(
    _In_ HWND WindowHandle,
    _In_ ULONG_PTR nIDEvent,
    _In_ ULONG uElapse,
    _In_ TIMERPROC lpTimerFunc,
    _In_ ULONG uToleranceDelay
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetTimer* volatile ScUserSetTimer;

typedef
WORD
NTAPI
FN_ScUserSetClassWord(
    _In_ HWND WindowHandle,
    _In_ LONG nIndex,
    _In_ WORD wNewWord
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetClassWord* volatile ScUserSetClassWord;

typedef
BOOL
NTAPI
FN_ScUserSetCursorPos(
    _In_ LONG X,
    _In_ LONG Y
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetCursorPos* volatile ScUserSetCursorPos;

typedef
BOOL
NTAPI
FN_ScUserSetLayeredWindowAttributes(
    _In_ HWND WindowHandle,
    _In_ COLORREF crKey,
    _In_ BYTE bAlpha,
    _In_ DWORD dwFlags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetLayeredWindowAttributes* volatile ScUserSetLayeredWindowAttributes;

typedef
BOOL
NTAPI
FN_ScUserSetProcessRestrictionExemption(
    _In_ BOOL EnableExemption
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetProcessRestrictionExemption* volatile ScUserSetProcessRestrictionExemption;

typedef
BOOL
NTAPI
FN_ScUserSetWindowPos(
    _In_ HWND WindowHandle,
    _In_ HWND WindowHandleInsertAfter,
    _In_ LONG X,
    _In_ LONG Y,
    _In_ LONG cx,
    _In_ LONG cy,
    _In_ ULONG uFlags
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetWindowPos* volatile ScUserSetWindowPos;

typedef
WORD
NTAPI
FN_ScUserSetWindowWord(
    _In_ HWND WindowHandle,
    _In_ LONG nIndex,
    _In_ WORD wNewWord
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetWindowWord* volatile ScUserSetWindowWord;

typedef
NTSTATUS
NTAPI
FN_ScUserSetForegroundWindowForApplication(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetForegroundWindowForApplication* volatile ScUserSetForegroundWindowForApplication;

typedef
HWND
NTAPI
FN_ScUserShellForegroundBoostProcess(
    _In_ HANDLE ProcessHandle,
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserShellForegroundBoostProcess* volatile ScUserShellForegroundBoostProcess;

typedef
ULONG
NTAPI
FN_ScUserSetAdditionalForegroundBoostProcesses(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetAdditionalForegroundBoostProcesses* volatile ScUserSetAdditionalForegroundBoostProcesses;

typedef
ULONG
NTAPI
FN_ScUserSetAdditionalPowerThrottlingProcess(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserSetAdditionalPowerThrottlingProcess* volatile ScUserSetAdditionalPowerThrottlingProcess;

typedef
LONG
NTAPI
FN_ScUserShowCursor(
    _In_ BOOL bShow
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserShowCursor* volatile ScUserShowCursor;

typedef
BOOL
NTAPI
FN_ScUserShowWindow(
    _In_ HWND WindowHandle,
    _In_ LONG nCmdShow
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserShowWindow* volatile ScUserShowWindow;

typedef
BOOL
NTAPI
FN_ScUserShowWindowAsync(
    _In_ HWND WindowHandle,
    _In_ LONG nCmdShow
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserShowWindowAsync* volatile ScUserShowWindowAsync;

typedef
BOOL
NTAPI
FN_ScUserShutdownBlockReasonQuery(
    _In_ HWND WindowHandle,
    _Out_ PWSTR Buffer,
    _Inout_ PULONG BufferCount
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserShutdownBlockReasonQuery* volatile ScUserShutdownBlockReasonQuery;

typedef
BOOL
NTAPI
FN_ScUserShutdownReasonDestroy(
    _In_ HWND WindowHandle
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserShutdownReasonDestroy* volatile ScUserShutdownReasonDestroy;

typedef
BOOL
NTAPI
FN_ScUserTrackMouseEvent(
    _In_ LPTRACKMOUSEEVENT lpEventTrack
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserTrackMouseEvent* volatile ScUserTrackMouseEvent;

typedef
BOOL
NTAPI
FN_ScUserTrackPopupMenuEx(
    _In_ HMENU MenuHandle,
    _In_ ULONG uFlags,
    _In_ LONG x,
    _In_ LONG y,
    _In_ HWND WindowHandle,
    _In_ LPTPMPARAMS lptpm
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserTrackPopupMenuEx* volatile ScUserTrackPopupMenuEx;

typedef
BOOL
NTAPI
FN_ScUserUnhookWinEvent(
    _In_ HWINEVENTHOOK hWinEventHook
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserUnhookWinEvent* volatile ScUserUnhookWinEvent;

typedef
BOOL
NTAPI
FN_ScUserUnregisterHotKey(
    _In_ HWND WindowHandle,
    _In_ LONG id
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserUnregisterHotKey* volatile ScUserUnregisterHotKey;

typedef
BOOL
NTAPI
FN_ScUserUserHandleGrantAccess(
    _In_ HANDLE UserHandle,
    _In_ HANDLE Job,
    _In_ BOOL Grant
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserUserHandleGrantAccess* volatile ScUserUserHandleGrantAccess;

typedef
BOOL
NTAPI
FN_ScUserValidateRect(
    _In_ HWND WindowHandle,
    _In_ const RECT* Rect
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserValidateRect* volatile ScUserValidateRect;

typedef
HWND
NTAPI
FN_ScUserWindowFromDC(
    _In_ HDC hDC
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserWindowFromDC* volatile ScUserWindowFromDC;

typedef
HWND
NTAPI
FN_ScUserWindowFromPhysicalPoint(
    _In_ POINT Point
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserWindowFromPhysicalPoint* volatile ScUserWindowFromPhysicalPoint;

typedef
HWND
NTAPI
FN_ScUserWindowFromPoint(
    _In_ POINT Point
    );
EXTERN_C DECLSPEC_POINTERALIGN FN_ScUserWindowFromPoint* volatile ScUserWindowFromPoint;

EXTERN_C_END
