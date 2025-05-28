#include <stdafx.h>
#include <kernel/function.h>
#include <kernel/kernel.h>
#include <kernel/xam.h>
#include <apu/audio.h>

GUEST_FUNCTION_HOOK(__imp__XGetVideoMode, reblue::kernel::VdQueryVideoMode); // XGetVideoMode
GUEST_FUNCTION_HOOK(__imp__XNotifyGetNext, reblue::kernel::XNotifyGetNext);
GUEST_FUNCTION_HOOK(__imp__XGetGameRegion, reblue::kernel::XGetGameRegion);
GUEST_FUNCTION_HOOK(__imp__XMsgStartIORequest, reblue::kernel::XMsgStartIORequest);
GUEST_FUNCTION_HOOK(__imp__XamUserGetSigninState, reblue::kernel::XamUserGetSigninState);
GUEST_FUNCTION_HOOK(__imp__XamGetSystemVersion, reblue::kernel::XamGetSystemVersion);
GUEST_FUNCTION_HOOK(__imp__XamContentCreateEx, reblue::kernel::XamContentCreateEx);
GUEST_FUNCTION_HOOK(__imp__XamContentDelete, reblue::kernel::XamContentDelete);
GUEST_FUNCTION_HOOK(__imp__XamContentClose, reblue::kernel::XamContentClose);
GUEST_FUNCTION_HOOK(__imp__XamContentGetCreator, reblue::kernel::XamContentGetCreator);
GUEST_FUNCTION_HOOK(__imp__XamContentCreateEnumerator, reblue::kernel::XamContentCreateEnumerator);
GUEST_FUNCTION_HOOK(__imp__XamContentGetDeviceState, reblue::kernel::XamContentGetDeviceState);
GUEST_FUNCTION_HOOK(__imp__XamContentGetDeviceData, reblue::kernel::XamContentGetDeviceData);
GUEST_FUNCTION_HOOK(__imp__XamEnumerate, reblue::kernel::XamEnumerate);
GUEST_FUNCTION_HOOK(__imp__XamNotifyCreateListener, reblue::kernel::XamNotifyCreateListener);
GUEST_FUNCTION_HOOK(__imp__XamUserGetSigninInfo, reblue::kernel::XamUserGetSigninInfo);
GUEST_FUNCTION_HOOK(__imp__XamShowSigninUI, reblue::kernel::XamShowSigninUI);
GUEST_FUNCTION_HOOK(__imp__XamShowDeviceSelectorUI, reblue::kernel::XamShowDeviceSelectorUI);
GUEST_FUNCTION_HOOK(__imp__XamShowMessageBoxUI, reblue::kernel::XamShowMessageBoxUI);
GUEST_FUNCTION_HOOK(__imp__XamShowDirtyDiscErrorUI, reblue::kernel::XamShowDirtyDiscErrorUI);
GUEST_FUNCTION_HOOK(__imp__XamEnableInactivityProcessing, reblue::kernel::XamEnableInactivityProcessing);
GUEST_FUNCTION_HOOK(__imp__XamResetInactivity, reblue::kernel::XamResetInactivity);
GUEST_FUNCTION_HOOK(__imp__XamShowMessageBoxUIEx, reblue::kernel::XamShowMessageBoxUIEx);
GUEST_FUNCTION_HOOK(__imp__XGetLanguage, reblue::kernel::XGetLanguage);
GUEST_FUNCTION_HOOK(__imp__XGetAVPack, reblue::kernel::XGetAVPack);
GUEST_FUNCTION_HOOK(__imp__XamLoaderTerminateTitle, reblue::kernel::XamLoaderTerminateTitle);
GUEST_FUNCTION_HOOK(__imp__XamGetExecutionId, reblue::kernel::XamGetExecutionId);
GUEST_FUNCTION_HOOK(__imp__XamLoaderLaunchTitle, reblue::kernel::XamLoaderLaunchTitle);
GUEST_FUNCTION_HOOK(__imp__NtOpenFile, reblue::kernel::NtOpenFile);
GUEST_FUNCTION_HOOK(__imp__RtlInitAnsiString, reblue::kernel::RtlInitAnsiString);
GUEST_FUNCTION_HOOK(__imp__NtCreateFile, reblue::kernel::NtCreateFile);
GUEST_FUNCTION_HOOK(__imp__NtClose, reblue::kernel::NtClose);
GUEST_FUNCTION_HOOK(__imp__NtSetInformationFile, reblue::kernel::NtSetInformationFile);
GUEST_FUNCTION_HOOK(__imp__FscSetCacheElementCount, reblue::kernel::FscSetCacheElementCount);
GUEST_FUNCTION_HOOK(__imp__NtWaitForSingleObjectEx, reblue::kernel::NtWaitForSingleObjectEx);
GUEST_FUNCTION_HOOK(__imp__NtWriteFile, reblue::kernel::NtWriteFile);
GUEST_FUNCTION_HOOK(__imp__ExGetXConfigSetting, reblue::kernel::ExGetXConfigSetting);
GUEST_FUNCTION_HOOK(__imp__NtQueryVirtualMemory, reblue::kernel::NtQueryVirtualMemory);
GUEST_FUNCTION_HOOK(__imp__MmQueryStatistics, reblue::kernel::MmQueryStatistics);
GUEST_FUNCTION_HOOK(__imp__NtCreateEvent, reblue::kernel::NtCreateEvent);
GUEST_FUNCTION_HOOK(__imp__XexCheckExecutablePrivilege, reblue::kernel::XexCheckExecutablePrivilege);
GUEST_FUNCTION_HOOK(__imp__DbgPrint, reblue::kernel::DbgPrint);
GUEST_FUNCTION_HOOK(__imp____C_specific_handler, reblue::kernel::__C_specific_handler_x);
GUEST_FUNCTION_HOOK(__imp__RtlNtStatusToDosError, reblue::kernel::RtlNtStatusToDosError);
GUEST_FUNCTION_HOOK(__imp__XexGetProcedureAddress, reblue::kernel::XexGetProcedureAddress);
GUEST_FUNCTION_HOOK(__imp__XexGetModuleSection, reblue::kernel::XexGetModuleSection);
GUEST_FUNCTION_HOOK(__imp__RtlUnicodeToMultiByteN, reblue::kernel::RtlUnicodeToMultiByteN);
GUEST_FUNCTION_HOOK(__imp__KeDelayExecutionThread, reblue::kernel::KeDelayExecutionThread);
GUEST_FUNCTION_HOOK(__imp__ExFreePool, reblue::kernel::ExFreePool);
GUEST_FUNCTION_HOOK(__imp__NtQueryInformationFile, reblue::kernel::NtQueryInformationFile);
GUEST_FUNCTION_HOOK(__imp__NtQueryVolumeInformationFile, reblue::kernel::NtQueryVolumeInformationFile);
GUEST_FUNCTION_HOOK(__imp__NtQueryDirectoryFile, reblue::kernel::NtQueryDirectoryFile);
GUEST_FUNCTION_HOOK(__imp__NtReadFileScatter, reblue::kernel::NtReadFileScatter);
GUEST_FUNCTION_HOOK(__imp__NtReadFile, reblue::kernel::NtReadFile);
GUEST_FUNCTION_HOOK(__imp__NtDuplicateObject, reblue::kernel::NtDuplicateObject);
GUEST_FUNCTION_HOOK(__imp__NtAllocateVirtualMemory, reblue::kernel::NtAllocateVirtualMemory);
GUEST_FUNCTION_HOOK(__imp__NtFreeVirtualMemory, reblue::kernel::NtFreeVirtualMemory);
GUEST_FUNCTION_HOOK(__imp__ObDereferenceObject, reblue::kernel::ObDereferenceObject);
GUEST_FUNCTION_HOOK(__imp__KeSetBasePriorityThread, reblue::kernel::KeSetBasePriorityThread);
GUEST_FUNCTION_HOOK(__imp__ObReferenceObjectByHandle, reblue::kernel::ObReferenceObjectByHandle);
GUEST_FUNCTION_HOOK(__imp__KeQueryBasePriorityThread, reblue::kernel::KeQueryBasePriorityThread);
GUEST_FUNCTION_HOOK(__imp__NtSuspendThread, reblue::kernel::NtSuspendThread);
GUEST_FUNCTION_HOOK(__imp__KeSetAffinityThread, reblue::kernel::KeSetAffinityThread);
GUEST_FUNCTION_HOOK(__imp__RtlLeaveCriticalSection, reblue::kernel::RtlLeaveCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlEnterCriticalSection, reblue::kernel::RtlEnterCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlImageXexHeaderField, reblue::kernel::RtlImageXexHeaderField);
GUEST_FUNCTION_HOOK(__imp__HalReturnToFirmware, reblue::kernel::HalReturnToFirmware);
GUEST_FUNCTION_HOOK(__imp__RtlFillMemoryUlong, reblue::kernel::RtlFillMemoryUlong);
GUEST_FUNCTION_HOOK(__imp__KeBugCheckEx, reblue::kernel::KeBugCheckEx);
GUEST_FUNCTION_HOOK(__imp__KeGetCurrentProcessType, reblue::kernel::KeGetCurrentProcessType);
GUEST_FUNCTION_HOOK(__imp__RtlCompareMemoryUlong, reblue::kernel::RtlCompareMemoryUlong);
GUEST_FUNCTION_HOOK(__imp__RtlInitializeCriticalSection, reblue::kernel::RtlInitializeCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlRaiseException, reblue::kernel::RtlRaiseException_x);
GUEST_FUNCTION_HOOK(__imp__KfReleaseSpinLock, reblue::kernel::KfReleaseSpinLock);
GUEST_FUNCTION_HOOK(__imp__KfAcquireSpinLock, reblue::kernel::KfAcquireSpinLock);
GUEST_FUNCTION_HOOK(__imp__KeQueryPerformanceFrequency, reblue::kernel::KeQueryPerformanceFrequency);
GUEST_FUNCTION_HOOK(__imp__MmFreePhysicalMemory, reblue::kernel::MmFreePhysicalMemory);
GUEST_FUNCTION_HOOK(__imp__VdPersistDisplay, reblue::kernel::VdPersistDisplay);
GUEST_FUNCTION_HOOK(__imp__VdSwap, reblue::kernel::VdSwap);
GUEST_FUNCTION_HOOK(__imp__VdGetSystemCommandBuffer, reblue::kernel::VdGetSystemCommandBuffer);
GUEST_FUNCTION_HOOK(__imp__KeReleaseSpinLockFromRaisedIrql, reblue::kernel::KeReleaseSpinLockFromRaisedIrql);
GUEST_FUNCTION_HOOK(__imp__KeAcquireSpinLockAtRaisedIrql, reblue::kernel::KeAcquireSpinLockAtRaisedIrql);
GUEST_FUNCTION_HOOK(__imp__KiApcNormalRoutineNop, reblue::kernel::KiApcNormalRoutineNop);
GUEST_FUNCTION_HOOK(__imp__VdEnableRingBufferRPtrWriteBack, reblue::kernel::VdEnableRingBufferRPtrWriteBack);
GUEST_FUNCTION_HOOK(__imp__VdInitializeRingBuffer, reblue::kernel::VdInitializeRingBuffer);
GUEST_FUNCTION_HOOK(__imp__MmGetPhysicalAddress, reblue::kernel::MmGetPhysicalAddress);
GUEST_FUNCTION_HOOK(__imp__VdSetSystemCommandBufferGpuIdentifierAddress, reblue::kernel::VdSetSystemCommandBufferGpuIdentifierAddress);
GUEST_FUNCTION_HOOK(__imp__ExRegisterTitleTerminateNotification, reblue::kernel::ExRegisterTitleTerminateNotification);
GUEST_FUNCTION_HOOK(__imp__VdShutdownEngines, reblue::kernel::VdShutdownEngines);
GUEST_FUNCTION_HOOK(__imp__VdQueryVideoMode, reblue::kernel::VdQueryVideoMode);
GUEST_FUNCTION_HOOK(__imp__VdGetCurrentDisplayInformation, reblue::kernel::VdGetCurrentDisplayInformation);
GUEST_FUNCTION_HOOK(__imp__VdSetDisplayMode, reblue::kernel::VdSetDisplayMode);
GUEST_FUNCTION_HOOK(__imp__VdSetGraphicsInterruptCallback, reblue::kernel::VdSetGraphicsInterruptCallback);
GUEST_FUNCTION_HOOK(__imp__VdInitializeEngines, reblue::kernel::VdInitializeEngines);
GUEST_FUNCTION_HOOK(__imp__VdIsHSIOTrainingSucceeded, reblue::kernel::VdIsHSIOTrainingSucceeded);
GUEST_FUNCTION_HOOK(__imp__VdGetCurrentDisplayGamma, reblue::kernel::VdGetCurrentDisplayGamma);
GUEST_FUNCTION_HOOK(__imp__VdQueryVideoFlags, reblue::kernel::VdQueryVideoFlags);
GUEST_FUNCTION_HOOK(__imp__VdCallGraphicsNotificationRoutines, reblue::kernel::VdCallGraphicsNotificationRoutines);
GUEST_FUNCTION_HOOK(__imp__VdInitializeScalerCommandBuffer, reblue::kernel::VdInitializeScalerCommandBuffer);
GUEST_FUNCTION_HOOK(__imp__KeLeaveCriticalRegion, reblue::kernel::KeLeaveCriticalRegion);
GUEST_FUNCTION_HOOK(__imp__VdRetrainEDRAM, reblue::kernel::VdRetrainEDRAM);
GUEST_FUNCTION_HOOK(__imp__VdRetrainEDRAMWorker, reblue::kernel::VdRetrainEDRAMWorker);
GUEST_FUNCTION_HOOK(__imp__KeEnterCriticalRegion, reblue::kernel::KeEnterCriticalRegion);
GUEST_FUNCTION_HOOK(__imp__MmAllocatePhysicalMemoryEx, reblue::kernel::MmAllocatePhysicalMemoryEx);
GUEST_FUNCTION_HOOK(__imp__ObDeleteSymbolicLink, reblue::kernel::ObDeleteSymbolicLink);
GUEST_FUNCTION_HOOK(__imp__ObCreateSymbolicLink, reblue::kernel::ObCreateSymbolicLink);
GUEST_FUNCTION_HOOK(__imp__MmQueryAddressProtect, reblue::kernel::MmQueryAddressProtect);
GUEST_FUNCTION_HOOK(__imp__VdEnableDisableClockGating, reblue::kernel::VdEnableDisableClockGating);
GUEST_FUNCTION_HOOK(__imp__KeBugCheck, reblue::kernel::KeBugCheck);
GUEST_FUNCTION_HOOK(__imp__KeLockL2, reblue::kernel::KeLockL2);
GUEST_FUNCTION_HOOK(__imp__KeUnlockL2, reblue::kernel::KeUnlockL2);
GUEST_FUNCTION_HOOK(__imp__KeSetEvent, reblue::kernel::KeSetEvent);
GUEST_FUNCTION_HOOK(__imp__KeResetEvent, reblue::kernel::KeResetEvent);
GUEST_FUNCTION_HOOK(__imp__KeWaitForSingleObject, reblue::kernel::KeWaitForSingleObject);
GUEST_FUNCTION_HOOK(__imp__KeTlsGetValue, reblue::kernel::KeTlsGetValue);
GUEST_FUNCTION_HOOK(__imp__KeTlsSetValue, reblue::kernel::KeTlsSetValue);
GUEST_FUNCTION_HOOK(__imp__KeTlsAlloc, reblue::kernel::KeTlsAlloc);
GUEST_FUNCTION_HOOK(__imp__KeTlsFree, reblue::kernel::KeTlsFree);
GUEST_FUNCTION_HOOK(__imp__XMsgInProcessCall, reblue::kernel::XMsgInProcessCall);
GUEST_FUNCTION_HOOK(__imp__XamUserReadProfileSettings, reblue::kernel::XamUserReadProfileSettings);
GUEST_FUNCTION_HOOK(__imp__NetDll_WSAStartup, reblue::kernel::NetDll_WSAStartup);
GUEST_FUNCTION_HOOK(__imp__NetDll_WSACleanup, reblue::kernel::NetDll_WSACleanup);
GUEST_FUNCTION_HOOK(__imp__NetDll_socket, reblue::kernel::NetDll_socket);
GUEST_FUNCTION_HOOK(__imp__NetDll_closesocket, reblue::kernel::NetDll_closesocket);
GUEST_FUNCTION_HOOK(__imp__NetDll_setsockopt, reblue::kernel::NetDll_setsockopt);
GUEST_FUNCTION_HOOK(__imp__NetDll_bind, reblue::kernel::NetDll_bind);
GUEST_FUNCTION_HOOK(__imp__NetDll_connect, reblue::kernel::NetDll_connect);
GUEST_FUNCTION_HOOK(__imp__NetDll_listen, reblue::kernel::NetDll_listen);
GUEST_FUNCTION_HOOK(__imp__NetDll_accept, reblue::kernel::NetDll_accept);
GUEST_FUNCTION_HOOK(__imp__NetDll_select, reblue::kernel::NetDll_select);
GUEST_FUNCTION_HOOK(__imp__NetDll_recv, reblue::kernel::NetDll_recv);
GUEST_FUNCTION_HOOK(__imp__NetDll_send, reblue::kernel::NetDll_send);
GUEST_FUNCTION_HOOK(__imp__NetDll_inet_addr, reblue::kernel::NetDll_inet_addr);
GUEST_FUNCTION_HOOK(__imp__NetDll___WSAFDIsSet, reblue::kernel::NetDll___WSAFDIsSet);
GUEST_FUNCTION_HOOK(__imp__XMsgStartIORequestEx, reblue::kernel::XMsgStartIORequestEx);
GUEST_FUNCTION_HOOK(__imp__XamInputGetCapabilities, reblue::kernel::XamInputGetCapabilities);
GUEST_FUNCTION_HOOK(__imp__XamInputGetState, reblue::kernel::XamInputGetState);
GUEST_FUNCTION_HOOK(__imp__XamInputSetState, reblue::kernel::XamInputSetState);
GUEST_FUNCTION_HOOK(__imp__XexGetModuleHandle, reblue::kernel::XexGetModuleHandle);
GUEST_FUNCTION_HOOK(__imp__RtlTryEnterCriticalSection, reblue::kernel::RtlTryEnterCriticalSection);
GUEST_FUNCTION_HOOK(__imp__RtlInitializeCriticalSectionAndSpinCount, reblue::kernel::RtlInitializeCriticalSectionAndSpinCount);
GUEST_FUNCTION_HOOK(__imp__XeCryptBnQwBeSigVerify, reblue::kernel::XeCryptBnQwBeSigVerify);
GUEST_FUNCTION_HOOK(__imp__XeKeysGetKey, reblue::kernel::XeKeysGetKey);
GUEST_FUNCTION_HOOK(__imp__XeCryptRotSumSha, reblue::kernel::XeCryptRotSumSha);
GUEST_FUNCTION_HOOK(__imp__XeCryptSha, reblue::kernel::XeCryptSha);
GUEST_FUNCTION_HOOK(__imp__KeEnableFpuExceptions, reblue::kernel::KeEnableFpuExceptions);
GUEST_FUNCTION_HOOK(__imp__RtlUnwind, reblue::kernel::RtlUnwind_x);
GUEST_FUNCTION_HOOK(__imp__RtlCaptureContext, reblue::kernel::RtlCaptureContext_x);
GUEST_FUNCTION_HOOK(__imp__NtQueryFullAttributesFile, reblue::kernel::NtQueryFullAttributesFile);
GUEST_FUNCTION_HOOK(__imp__RtlMultiByteToUnicodeN, reblue::kernel::RtlMultiByteToUnicodeN);
GUEST_FUNCTION_HOOK(__imp__DbgBreakPoint, reblue::kernel::DbgBreakPoint);
GUEST_FUNCTION_HOOK(__imp__MmQueryAllocationSize, reblue::kernel::MmQueryAllocationSize);
GUEST_FUNCTION_HOOK(__imp__NtClearEvent, reblue::kernel::NtClearEvent);
GUEST_FUNCTION_HOOK(__imp__NtResumeThread, reblue::kernel::NtResumeThread);
GUEST_FUNCTION_HOOK(__imp__NtSetEvent, reblue::kernel::NtSetEvent);
GUEST_FUNCTION_HOOK(__imp__NtCreateSemaphore, reblue::kernel::NtCreateSemaphore);
GUEST_FUNCTION_HOOK(__imp__NtReleaseSemaphore, reblue::kernel::NtReleaseSemaphore);
GUEST_FUNCTION_HOOK(__imp__NtWaitForMultipleObjectsEx, reblue::kernel::NtWaitForMultipleObjectsEx);
GUEST_FUNCTION_HOOK(__imp__RtlCompareStringN, reblue::kernel::RtlCompareStringN);
GUEST_FUNCTION_HOOK(__imp__StfsControlDevice, reblue::kernel::StfsControlDevice);
GUEST_FUNCTION_HOOK(__imp__StfsCreateDevice, reblue::kernel::StfsCreateDevice);
GUEST_FUNCTION_HOOK(__imp__NtFlushBuffersFile, reblue::kernel::NtFlushBuffersFile);
GUEST_FUNCTION_HOOK(__imp__KeQuerySystemTime, reblue::kernel::KeQuerySystemTime);
GUEST_FUNCTION_HOOK(__imp__RtlTimeToTimeFields, reblue::kernel::RtlTimeToTimeFields);
GUEST_FUNCTION_HOOK(__imp__RtlFreeAnsiString, reblue::kernel::RtlFreeAnsiString);
GUEST_FUNCTION_HOOK(__imp__RtlUnicodeStringToAnsiString, reblue::kernel::RtlUnicodeStringToAnsiString);
GUEST_FUNCTION_HOOK(__imp__RtlInitUnicodeString, reblue::kernel::RtlInitUnicodeString);
GUEST_FUNCTION_HOOK(__imp__ExTerminateThread, reblue::kernel::ExTerminateThread);
GUEST_FUNCTION_HOOK(__imp__ExCreateThread, reblue::kernel::ExCreateThread);
GUEST_FUNCTION_HOOK(__imp__IoInvalidDeviceRequest, reblue::kernel::IoInvalidDeviceRequest);
GUEST_FUNCTION_HOOK(__imp__ObReferenceObject, reblue::kernel::ObReferenceObject);
GUEST_FUNCTION_HOOK(__imp__IoCreateDevice, reblue::kernel::IoCreateDevice);
GUEST_FUNCTION_HOOK(__imp__IoDeleteDevice, reblue::kernel::IoDeleteDevice);
GUEST_FUNCTION_HOOK(__imp__ExAllocatePoolTypeWithTag, reblue::kernel::ExAllocatePoolTypeWithTag);
GUEST_FUNCTION_HOOK(__imp__RtlTimeFieldsToTime, reblue::kernel::RtlTimeFieldsToTime);
GUEST_FUNCTION_HOOK(__imp__IoCompleteRequest, reblue::kernel::IoCompleteRequest);
GUEST_FUNCTION_HOOK(__imp__RtlUpcaseUnicodeChar, reblue::kernel::RtlUpcaseUnicodeChar);
GUEST_FUNCTION_HOOK(__imp__ObIsTitleObject, reblue::kernel::ObIsTitleObject);
GUEST_FUNCTION_HOOK(__imp__IoCheckShareAccess, reblue::kernel::IoCheckShareAccess);
GUEST_FUNCTION_HOOK(__imp__IoSetShareAccess, reblue::kernel::IoSetShareAccess);
GUEST_FUNCTION_HOOK(__imp__IoRemoveShareAccess, reblue::kernel::IoRemoveShareAccess);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetStartup, reblue::kernel::NetDll_XNetStartup);
GUEST_FUNCTION_HOOK(__imp__NetDll_XNetGetTitleXnAddr, reblue::kernel::NetDll_XNetGetTitleXnAddr);
GUEST_FUNCTION_HOOK(__imp__KeWaitForMultipleObjects, reblue::kernel::KeWaitForMultipleObjects);
GUEST_FUNCTION_HOOK(__imp__KeRaiseIrqlToDpcLevel, reblue::kernel::RaiseIrqlToDpcLevel);
GUEST_FUNCTION_HOOK(__imp__KfLowerIrql, reblue::kernel::KfLowerIrql);
GUEST_FUNCTION_HOOK(__imp__KeReleaseSemaphore, reblue::kernel::KeReleaseSemaphore);
GUEST_FUNCTION_HOOK(__imp__XAudioGetVoiceCategoryVolume, reblue::kernel::XAudioGetVoiceCategoryVolume);
GUEST_FUNCTION_HOOK(__imp__XAudioGetVoiceCategoryVolumeChangeMask, reblue::kernel::XAudioGetVoiceCategoryVolumeChangeMask);
GUEST_FUNCTION_HOOK(__imp__KeResumeThread, reblue::kernel::KeResumeThread);
GUEST_FUNCTION_HOOK(__imp__KeInitializeSemaphore, reblue::kernel::KeInitializeSemaphore);
GUEST_FUNCTION_HOOK(__imp__XMAReleaseContext, reblue::kernel::XMAReleaseContext);
GUEST_FUNCTION_HOOK(__imp__XMACreateContext, reblue::kernel::XMACreateContext);
GUEST_FUNCTION_HOOK(__imp__XAudioRegisterRenderDriverClient, XAudioRegisterRenderDriverClient);
GUEST_FUNCTION_HOOK(__imp__XAudioUnregisterRenderDriverClient, XAudioUnregisterRenderDriverClient);
GUEST_FUNCTION_HOOK(__imp__XAudioSubmitRenderDriverFrame, XAudioSubmitRenderDriverFrame);
GUEST_FUNCTION_HOOK(__imp__KeTryToAcquireSpinLockAtRaisedIrql, reblue::kernel::KeTryToAcquireSpinLockAtRaisedIrql);
GUEST_FUNCTION_HOOK(__imp__NtCreateMutant, reblue::kernel::NtCreateMutant);
GUEST_FUNCTION_HOOK(__imp__NtDeviceIoControlFile, reblue::kernel::NtDeviceIoControlFile);
GUEST_FUNCTION_HOOK(__imp__NtReleaseMutant, reblue::kernel::NtReleaseMutant);
GUEST_FUNCTION_HOOK(__imp__IoDismountVolumeByFileHandle, reblue::kernel::IoDismountVolumeByFileHandle);
GUEST_FUNCTION_HOOK(__imp__XNotifyPositionUI, reblue::kernel::XNotifyPositionUI);
GUEST_FUNCTION_HOOK(__imp__ExAllocatePool, reblue::kernel::ExAllocatePool);
GUEST_FUNCTION_HOOK(__imp__XamAlloc, reblue::kernel::XamAlloc);
GUEST_FUNCTION_HOOK(__imp__XamContentSetThumbnail, reblue::kernel::XamContentSetThumbnail);
GUEST_FUNCTION_HOOK(__imp__XamFree, reblue::kernel::XamFree);
GUEST_FUNCTION_HOOK(__imp__NtPulseEvent, reblue::kernel::NtPulseEvent);
GUEST_FUNCTION_HOOK(__imp__NtYieldExecution, reblue::kernel::NtYieldExecution);
GUEST_FUNCTION_HOOK(__imp__XamLoaderGetDvdTrayState, reblue::kernel::XamLoaderGetDvdTrayState);
GUEST_FUNCTION_HOOK(__imp__XamTaskCloseHandle, reblue::kernel::XamTaskCloseHandle);
GUEST_FUNCTION_HOOK(__imp__XamTaskSchedule, reblue::kernel::XamTaskSchedule);
GUEST_FUNCTION_HOOK(__imp__XamTaskShouldExit, reblue::kernel::XamTaskShouldExit);
GUEST_FUNCTION_HOOK(__imp__XamUserCreateAchievementEnumerator, reblue::kernel::XamUserCreateAchievementEnumerator);
GUEST_FUNCTION_HOOK(__imp__XamUserGetName, reblue::kernel::XamUserGetName);
GUEST_FUNCTION_HOOK(__imp__XamUserGetXUID, reblue::kernel::XamUserGetXUID);
GUEST_FUNCTION_HOOK(__imp__XamUserWriteProfileSettings, reblue::kernel::XamUserWriteProfileSettings);
GUEST_FUNCTION_HOOK(__imp__XeKeysConsolePrivateKeySign, reblue::kernel::XeKeysConsolePrivateKeySign);
GUEST_FUNCTION_HOOK(__imp__XeKeysConsoleSignatureVerification, reblue::kernel::XeKeysConsoleSignatureVerification);
GUEST_FUNCTION_HOOK(__imp__XexLoadImageHeaders, reblue::kernel::XexLoadImageHeaders);
GUEST_FUNCTION_HOOK(__imp__IoDismountVolumeByName, reblue::kernel::IoDismountVolumeByName);
GUEST_FUNCTION_HOOK(__imp__IoSynchronousDeviceIoControlRequest, reblue::kernel::IoSynchronousDeviceIoControlRequest);
GUEST_FUNCTION_HOOK(__imp__ObOpenObjectByName, reblue::kernel::ObOpenObjectByName);
GUEST_FUNCTION_HOOK(__imp__ObReferenceObjectByName, reblue::kernel::ObReferenceObjectByName);
GUEST_FUNCTION_HOOK(sub_824694A0, reblue::kernel::RtlAllocateHeap);
GUEST_FUNCTION_HOOK(sub_82469D88, reblue::kernel::RtlFreeHeap);
GUEST_FUNCTION_HOOK(sub_8246A070, reblue::kernel::RtlReAllocateHeap);
GUEST_FUNCTION_HOOK(sub_82468738, reblue::kernel::RtlSizeHeap);
GUEST_FUNCTION_HOOK(sub_82466CC8, reblue::kernel::XAllocMem);
GUEST_FUNCTION_HOOK(sub_82466D60, reblue::kernel::XFreeMem);
// native memory operations
GUEST_FUNCTION_HOOK(sub_826C0480, memmove);
GUEST_FUNCTION_HOOK(sub_826BF770, memcpy);
GUEST_FUNCTION_HOOK(sub_826BFCF0, memset);

// stubs
GUEST_FUNCTION_STUB(sub_82468EF0); // HeapCreate
GUEST_FUNCTION_STUB(sub_82BD9250); // HeapDestroy
GUEST_FUNCTION_STUB(__imp__vsprintf);
GUEST_FUNCTION_STUB(__imp___vsnprintf);
GUEST_FUNCTION_STUB(__imp__sprintf);
GUEST_FUNCTION_STUB(__imp___snprintf);
GUEST_FUNCTION_STUB(__imp___snwprintf);
GUEST_FUNCTION_STUB(__imp__vswprintf);
GUEST_FUNCTION_STUB(__imp___vscwprintf);
GUEST_FUNCTION_STUB(__imp__swprintf);


// gpu
//GUEST_FUNCTION_HOOK(sub_82BD99B0, reblue::gpu::CreateDevice);

//GUEST_FUNCTION_HOOK(sub_82BE6230, reblue::gpu::DestructResource);
//GUEST_FUNCTION_HOOK(sub_82BE9300, reblue::gpu::LockTextureRect);
//GUEST_FUNCTION_HOOK(sub_82BE7780, reblue::gpu::UnlockTextureRect);

//GUEST_FUNCTION_HOOK(sub_82BE6B98, reblue::gpu::LockVertexBuffer);
//GUEST_FUNCTION_HOOK(sub_82BE6BE8, reblue::gpu::UnlockVertexBuffer);
//GUEST_FUNCTION_HOOK(sub_82BE61D0, reblue::gpu::GetVertexBufferDesc);
//
//GUEST_FUNCTION_HOOK(sub_82BE6CA8, reblue::gpu::LockIndexBuffer);
//GUEST_FUNCTION_HOOK(sub_82BE6CF0, reblue::gpu::UnlockIndexBuffer);
//GUEST_FUNCTION_HOOK(sub_82BE6200, reblue::gpu::GetIndexBufferDesc);
//
//GUEST_FUNCTION_HOOK(sub_82BE96F0, reblue::gpu::GetSurfaceDesc);
//
//GUEST_FUNCTION_HOOK(sub_82BE04B0, reblue::gpu::GetVertexDeclaration);
//GUEST_FUNCTION_HOOK(sub_82BE0530, reblue::gpu::HashVertexDeclaration);
//
//GUEST_FUNCTION_HOOK(sub_82BDA8C0, Video::Present);
//GUEST_FUNCTION_HOOK(sub_82BDD330, reblue::gpu::GetBackBuffer);
//
//GUEST_FUNCTION_HOOK(sub_82BE9498, reblue::gpu::CreateTexture);
//GUEST_FUNCTION_HOOK(sub_82BE6AD0, reblue::gpu::CreateVertexBuffer);
//GUEST_FUNCTION_HOOK(sub_82BE6BF8, reblue::gpu::CreateIndexBuffer);
//GUEST_FUNCTION_HOOK(sub_82BE95B8, reblue::gpu::CreateSurface);
//
//GUEST_FUNCTION_HOOK(sub_82BF6400, reblue::gpu::StretchRect);
//
//GUEST_FUNCTION_HOOK(sub_82BDD9F0, reblue::gpu::SetRenderTarget);
//GUEST_FUNCTION_HOOK(sub_82BDDD38, reblue::gpu::SetDepthStencilSurface);
//
//GUEST_FUNCTION_HOOK(sub_82BFE4C8, reblue::gpu::Clear);
//
//GUEST_FUNCTION_HOOK(sub_82BDD8C0, reblue::gpu::SetViewport);
//
//GUEST_FUNCTION_HOOK(sub_82BE9818, reblue::gpu::SetTexture);
//GUEST_FUNCTION_HOOK(sub_82BDCFB0, reblue::gpu::SetScissorRect);
//
//GUEST_FUNCTION_HOOK(sub_82BE5900, reblue::gpu::DrawPrimitive);
//GUEST_FUNCTION_HOOK(sub_82BE5CF0, reblue::gpu::DrawIndexedPrimitive);
//GUEST_FUNCTION_HOOK(sub_82BE52F8, reblue::gpu::DrawPrimitiveUP);

//GUEST_FUNCTION_HOOK(sub_82BE0428, reblue::gpu::CreateVertexDeclaration);
//GUEST_FUNCTION_HOOK(sub_82BE02E0, reblue::gpu::SetVertexDeclaration);
//
//GUEST_FUNCTION_HOOK(sub_82BE1A80, reblue::gpu::CreateVertexShader);
//GUEST_FUNCTION_HOOK(sub_82BE0110, reblue::gpu::SetVertexShader);
//
//GUEST_FUNCTION_HOOK(sub_82BDD0F8, reblue::gpu::SetStreamSource);
//GUEST_FUNCTION_HOOK(sub_82BDD218, reblue::gpu::SetIndices);
//
//GUEST_FUNCTION_HOOK(sub_82BE1990, reblue::gpu::CreatePixelShader);
//GUEST_FUNCTION_HOOK(sub_82BDFE58, reblue::gpu::SetPixelShader);
//
//GUEST_FUNCTION_HOOK(sub_82C003B8, reblue::gpu::D3DXFillTexture);
//GUEST_FUNCTION_HOOK(sub_82C00910, reblue::gpu::D3DXFillVolumeTexture);
//
//GUEST_FUNCTION_HOOK(sub_82E43FC8, reblue::gpu::MakePictureData);
//
//GUEST_FUNCTION_HOOK(sub_82E9EE38, reblue::gpu::SetResolution);
//
//GUEST_FUNCTION_HOOK(sub_82AE2BF8, reblue::gpu::ScreenShaderInit);

// This is a buggy function that recreates framebuffers
// if the inverse capture ratio is not 2.0, but the parameter
// is completely unused and not stored, so it ends up
// recreating framebuffers every single frame instead.
//GUEST_FUNCTION_STUB(sub_82BAAD38);
//
//GUEST_FUNCTION_STUB(sub_822C15D8);
//GUEST_FUNCTION_STUB(sub_822C1810);
//GUEST_FUNCTION_STUB(sub_82BD97A8);
//GUEST_FUNCTION_STUB(sub_82BD97E8);
//GUEST_FUNCTION_STUB(sub_82BDD370); // SetGammaRamp
//GUEST_FUNCTION_STUB(sub_82BE05B8);
//GUEST_FUNCTION_STUB(sub_82BE9C98);
//GUEST_FUNCTION_STUB(sub_82BEA308);
//GUEST_FUNCTION_STUB(sub_82CD5D68);
//GUEST_FUNCTION_STUB(sub_82BE9B28);
//GUEST_FUNCTION_STUB(sub_82BEA018);
//GUEST_FUNCTION_STUB(sub_82BEA7C0);
//GUEST_FUNCTION_STUB(sub_82BFFF88); // D3DXFilterTexture
//GUEST_FUNCTION_STUB(sub_82BD96D0);

//PPC_FUNC_IMPL(__imp__sub_824ECA00);
//PPC_FUNC(sub_824ECA00)
//{
//    // Guard against thread ownership changes when between command lists.
//    g_readyForCommands.wait(false);
//    g_presentThreadId = std::this_thread::get_id();
//    __imp__sub_824ECA00(ctx, base);
//}

