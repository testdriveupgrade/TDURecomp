#pragma once

#define GUEST_INVALID_HANDLE_VALUE 0xFFFFFFFF
#define OBJECT_SIGNATURE           (uint32_t)'XBOX'

#include <cpu/ppc_context.h>
#include <cpu/guest_thread.h>
#include <kernel/obj/event.h>
#include <kernel/obj/guest_heap.h>
#include <kernel/obj/guest_memory.h>
#include <kernel/obj/mutant.h>
#include <kernel/obj/semaphore.h>

#include <kernel/net.h>
#include <kernel/hal.h>

#include <os/logger.h>

namespace reblue {
namespace kernel {
    // tls
    static std::vector<size_t>   g_tlsFreeIndices;
    static size_t                g_tlsNextIndex = 0;
    static Mutex                 g_tlsAllocationMutex;
    static std::atomic<uint32_t> g_keSetEventGeneration;

    extern Mutex                 g_kernelLock;

    // guest memory
    extern GuestHeap             g_userHeap;
    extern GuestMemory           g_memory;

    inline void CloseKernelObject(XDISPATCHER_HEADER& header);
    uint32_t GetKernelHandle(KernelObject* obj);
    void DestroyKernelObject(KernelObject* obj);
    void DestroyKernelObject(uint32_t handle);
    bool IsKernelObject(uint32_t handle);
    bool IsKernelObject(void* obj);
    bool IsInvalidKernelObject(void* obj);


    template<typename T, typename... Args>
    inline T* CreateKernelObject(Args&&... args)
    {
        static_assert(std::is_base_of_v<KernelObject, T>);
        return g_userHeap.AllocPhysical<T>(std::forward<Args>(args)...);
    }

    template<typename T = KernelObject>
    inline T* GetKernelObject(uint32_t handle)
    {
        assert(handle != GUEST_INVALID_HANDLE_VALUE);
        return reinterpret_cast<T*>(g_memory.Translate(handle));
    }

    template<typename T = void>
    inline T* GetInvalidKernelObject()
    {
        return reinterpret_cast<T*>(g_memory.Translate(GUEST_INVALID_HANDLE_VALUE));
    }

    template<typename T>
    inline T* QueryKernelObject(XDISPATCHER_HEADER& header)
    {
        std::lock_guard guard{ g_kernelLock };
        if (header.WaitListHead.Flink != OBJECT_SIGNATURE)
        {
            header.WaitListHead.Flink = OBJECT_SIGNATURE;
            auto* obj = CreateKernelObject<T>(reinterpret_cast<typename T::guest_type*>(&header));
            header.WaitListHead.Blink = g_memory.MapVirtual(obj);

            return obj;
        }

        return static_cast<T*>(g_memory.Translate(header.WaitListHead.Blink.get()));
    }

    template<typename T>
    inline T* TryQueryKernelObject(XDISPATCHER_HEADER& header)
    {
        if (header.WaitListHead.Flink != OBJECT_SIGNATURE)
            return nullptr;

        return static_cast<T*>(g_memory.Translate(header.WaitListHead.Blink.get()));
    }
#pragma region System/Debug
    uint32_t GuestTimeoutToMilliseconds(be<int64_t>* timeout);
    void KeQuerySystemTime(be<uint64_t>* time);
    uint32_t RaiseIrqlToDpcLevel();
    void KfLowerIrql();
    uint32_t KiApcNormalRoutineNop();
    void KeEnableFpuExceptions();

    void DbgBreakPoint();
    void TimeStampBundle();
    void DebugMonitorData();
    void CertMonitorData();
    void KeBugCheckEx();
    uint64_t KeQueryPerformanceFrequency();
    void KeBugCheck();

    
    uint32_t XAudioGetVoiceCategoryVolumeChangeMask(uint32_t Driver, be<uint32_t>* Mask);

    void XexGetProcedureAddress();
    void XexGetModuleSection();
    void RtlImageXexHeaderField();

    void XNotifyPositionUI();
    void XAudioGetVoiceCategoryVolume();

    void RtlTimeFieldsToTime();

    void vsprintf_x();
    void DbgPrint();
    void __C_specific_handler_x();
    void RtlNtStatusToDosError();

    void ObDereferenceObject();
    uint32_t ObReferenceObjectByHandle(uint32_t handle, uint32_t objectType, be<uint32_t>* object);

    void RtlRaiseException_x();

    void _snwprintf_x();
    void _swprintf_x();
    void _vscwprintf_x();
    void _vsnprintf_x();
    void _vswprintf_x();
    void sprintf_x();

    uint32_t RtlUnicodeToMultiByteN(char* MultiByteString, uint32_t MaxBytesInMultiByteString, be<uint32_t>* BytesInMultiByteString, const be<uint16_t>* UnicodeString, uint32_t BytesInUnicodeString);
    uint32_t RtlMultiByteToUnicodeN(be<uint16_t>* UnicodeString, uint32_t MaxBytesInUnicodeString, be<uint32_t>* BytesInUnicodeString, const char* MultiByteString, uint32_t BytesInMultiByteString);
    void RtlInitAnsiString(XANSI_STRING* destination, char* source);

    void ExRegisterTitleTerminateNotification();
    void ObDeleteSymbolicLink();
    void ObCreateSymbolicLink();

    void XeCryptBnQwBeSigVerify();
    void XeKeysGetKey();
    void XeCryptRotSumSha();
    void XeCryptSha();
    void XeKeysConsolePrivateKeySign();
    void XeKeysConsoleSignatureVerification();

    void RtlCompareStringN();
    void _snprintf_x();
    void RtlTimeToTimeFields();
    void RtlFreeAnsiString();
    void RtlUnicodeStringToAnsiString();
    void RtlInitUnicodeString();
    void XexLoadImageHeaders();
    void ObOpenObjectByName();
    void ObReferenceObjectByName();
    void RtlUpcaseUnicodeChar();

    void ObIsTitleObject();

    void ObReferenceObject();

    void XMsgStartIORequestEx();

    void XexGetModuleHandle();

    uint32_t XMsgInProcessCall(uint32_t app, uint32_t message, be<uint32_t>* param1, be<uint32_t>* param2);

    void XexExecutableModuleHandle();

    void ExLoadedCommandLine();

    uint32_t XGetGameRegion();

    uint32_t XMsgStartIORequest(uint32_t App, uint32_t Message, XXOVERLAPPED* lpOverlapped, void* Buffer, uint32_t szBuffer);

    uint32_t XGetLanguage();

    uint32_t XGetAVPack();

    uint32_t XexCheckExecutablePrivilege();

    uint32_t ExGetXConfigSetting(uint16_t Category, uint16_t Setting, void* Buffer, uint16_t SizeOfBuffer, be<uint32_t>* RequiredSize);

#pragma endregion

#pragma region Threading
    uint32_t ExCreateThread(be<uint32_t>* handle, uint32_t stackSize, be<uint32_t>* threadId, uint32_t xApiThreadStartup, uint32_t startAddress, uint32_t startContext, uint32_t creationFlags);
    void ExTerminateThread();
    uint32_t NtResumeThread(GuestThreadHandle* hThread, uint32_t* suspendCount);
    uint32_t NtSuspendThread(GuestThreadHandle* hThread, uint32_t* suspendCount);
    uint32_t NtYieldExecution();
    uint32_t KeDelayExecutionThread(uint32_t WaitMode, bool Alertable, be<int64_t>* Timeout);
    uint32_t KeResumeThread(GuestThreadHandle* object);
    void KeSetBasePriorityThread(GuestThreadHandle* hThread, int priority);
    void KeQueryBasePriorityThread();
    uint32_t KeSetAffinityThread(uint32_t Thread, uint32_t Affinity, be<uint32_t>* lpPreviousAffinity);
    uint32_t KeGetCurrentProcessType();
    void ExThreadObjectType();

    uint32_t NtReleaseSemaphore(Semaphore* Handle, uint32_t ReleaseCount, int32_t* PreviousCount);
    uint32_t KeReleaseSemaphore(XKSEMAPHORE* semaphore, uint32_t increment, uint32_t adjustment, uint32_t wait);
    uint32_t NtCreateSemaphore(be<uint32_t>* Handle, XOBJECT_ATTRIBUTES* ObjectAttributes, uint32_t InitialCount, uint32_t MaximumCount);
    void KeInitializeSemaphore(XKSEMAPHORE* semaphore, uint32_t count, uint32_t limit);
    
    uint32_t NtCreateMutant(be<uint32_t>* handle, void* objAttributes, uint32_t initialOwner);
    uint32_t NtReleaseMutant(Mutant* handle, be<uint32_t>* previousCount);

    void KfReleaseSpinLock(uint32_t* spinLock);
    void KfAcquireSpinLock(uint32_t* spinLock);
    void KeReleaseSpinLockFromRaisedIrql(uint32_t* spinLock);
    void KeAcquireSpinLockAtRaisedIrql(uint32_t* spinLock);
    uint32_t KeTryToAcquireSpinLockAtRaisedIrql(uint32_t* spinLock);

    void KeEnterCriticalRegion();
    void KeLeaveCriticalRegion();

    void RtlLeaveCriticalSection(XRTL_CRITICAL_SECTION* cs);
    void RtlEnterCriticalSection(XRTL_CRITICAL_SECTION* cs);
    uint32_t RtlInitializeCriticalSection(XRTL_CRITICAL_SECTION* cs);
    bool RtlTryEnterCriticalSection(XRTL_CRITICAL_SECTION* cs);
    void RtlInitializeCriticalSectionAndSpinCount(XRTL_CRITICAL_SECTION* cs, uint32_t spinCount);

    void RtlUnwind_x();
    void RtlCaptureContext_x();

    void KeLockL2();
    void KeUnlockL2();

    bool KeSetEvent(XKEVENT* pEvent, uint32_t Increment, bool Wait);
    bool KeResetEvent(XKEVENT* pEvent);
    uint32_t NtCreateEvent(be<uint32_t>* handle, void* objAttributes, uint32_t eventType, uint32_t initialState);
    uint32_t NtSetEvent(Event* handle, uint32_t* previousState);
    uint32_t NtPulseEvent(Event* handle, uint32_t* previousState);
    uint32_t NtClearEvent(Event* handle, uint32_t* previousState);

    uint32_t KeWaitForMultipleObjects(uint32_t Count, xpointer<XDISPATCHER_HEADER>* Objects, uint32_t WaitType, uint32_t WaitReason, uint32_t WaitMode, uint32_t Alertable, be<int64_t>* Timeout);
    void NtWaitForMultipleObjectsEx();

    uint32_t KeWaitForSingleObject(XDISPATCHER_HEADER* Object, uint32_t WaitReason, uint32_t WaitMode, bool Alertable, be<int64_t>* Timeout);
    uint32_t NtWaitForSingleObjectEx(uint32_t Handle, uint32_t WaitMode, uint32_t Alertable, be<int64_t>* Timeout);
    
    void NtDuplicateObject();

    static uint32_t& TlsGetValueRef(size_t index);
    uint32_t KeTlsGetValue(uint32_t dwTlsIndex);
    uint32_t KeTlsSetValue(uint32_t dwTlsIndex, uint32_t lpTlsValue);
    uint32_t KeTlsAlloc();
    uint32_t KeTlsFree(uint32_t dwTlsIndex);
#pragma endregion

#pragma region Filesystem
    void NtOpenFile();
    uint32_t NtCreateFile
    (
        be<uint32_t>* FileHandle,
        uint32_t DesiredAccess,
        XOBJECT_ATTRIBUTES* Attributes,
        XIO_STATUS_BLOCK* IoStatusBlock,
        uint64_t* AllocationSize,
        uint32_t FileAttributes,
        uint32_t ShareAccess,
        uint32_t CreateDisposition,
        uint32_t CreateOptions
    );
    void NtWriteFile();
    void NtSetInformationFile();
    void NtQueryInformationFile();
    void NtQueryVolumeInformationFile();
    void NtQueryDirectoryFile();
    void NtReadFileScatter();
    void NtReadFile();
    void NtQueryFullAttributesFile();
    void NtFlushBuffersFile();
    void NtDeviceIoControlFile();
    uint32_t NtClose(uint32_t handle);
#pragma endregion

#pragma region Memory
    uint32_t NtAllocateVirtualMemory(uint32_t processHandle, be<uint32_t>* baseAddress, uint32_t zeroBits, be<uint32_t>* regionSize, uint32_t allocationType, uint32_t protect);
    uint32_t NtFreeVirtualMemory(uint32_t processHandle, be<uint32_t>* baseAddress, be<uint32_t>* regionSize, uint32_t freeType);
    void NtQueryVirtualMemory();

    uint32_t RtlAllocateHeap(uint32_t heapHandle, uint32_t flags, uint32_t size);
    uint32_t RtlReAllocateHeap(uint32_t heapHandle, uint32_t flags, uint32_t memoryPointer, uint32_t size);
    uint32_t RtlFreeHeap(uint32_t heapHandle, uint32_t flags, uint32_t memoryPointer);
    uint32_t RtlSizeHeap(uint32_t heapHandle, uint32_t flags, uint32_t memoryPointer);
    uint32_t XAllocMem(uint32_t size, uint32_t flags);
    void XFreeMem(uint32_t baseAddress, uint32_t flags);
    void MmQueryStatistics();
    void ExFreePool();
    uint32_t VirtualAlloc(uint32_t lpAddress, uint32_t dwSize, uint32_t flAllocationType, uint32_t flProtect);
    uint32_t VirtualFree(uint32_t lpAddress, uint32_t dwSize, uint32_t dwFreeType);

    uint32_t MmGetPhysicalAddress(uint32_t address);
    uint32_t MmAllocatePhysicalMemoryEx
    (
        uint32_t flags,
        uint32_t size,
        uint32_t protect,
        uint32_t minAddress,
        uint32_t maxAddress,
        uint32_t alignment
    );

    uint32_t MmQueryAddressProtect(uint32_t guestAddress);
    void MmQueryAllocationSize();
    uint32_t ExAllocatePool(uint32_t size);
    void ExAllocatePoolTypeWithTag();
    uint32_t XamAlloc(uint32_t size);
    void XamFree(uint32_t ptr);
    void MmFreePhysicalMemory(uint32_t type, uint32_t guestAddress);
    void RtlFillMemoryUlong();
    void RtlCompareMemoryUlong();
#pragma endregion
}
}

extern "C" void* MmGetHostAddress(uint32_t ptr);
