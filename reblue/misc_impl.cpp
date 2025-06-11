#include "stdafx.h"
#include <kernel/function.h>

uint32_t QueryPerformanceCounterImpl(LARGE_INTEGER* lpPerformanceCount)
{
    lpPerformanceCount->QuadPart = ByteSwap(std::chrono::steady_clock::now().time_since_epoch().count());
    return TRUE;
}

uint32_t QueryPerformanceFrequencyImpl(LARGE_INTEGER* lpFrequency)
{
    constexpr auto Frequency = std::chrono::steady_clock::period::den / std::chrono::steady_clock::period::num;
    lpFrequency->QuadPart = ByteSwap(Frequency);
    return TRUE;
}

uint32_t GetTickCountImpl()
{
    return uint32_t(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
}

void GlobalMemoryStatusImpl(XLPMEMORYSTATUS lpMemoryStatus)
{
    lpMemoryStatus->dwLength = sizeof(XMEMORYSTATUS);
    lpMemoryStatus->dwMemoryLoad = 0;
    lpMemoryStatus->dwTotalPhys = 0x20000000;
    lpMemoryStatus->dwAvailPhys = 0x20000000;
    lpMemoryStatus->dwTotalPageFile = 0x20000000;
    lpMemoryStatus->dwAvailPageFile = 0x20000000;
    lpMemoryStatus->dwTotalVirtual = 0x20000000;
    lpMemoryStatus->dwAvailVirtual = 0x20000000;
}

//#ifdef _WIN32
GUEST_FUNCTION_HOOK(sub_8248D058, OutputDebugStringA);
//void guest_output_debug_string(const char* fmt)  
//{  
//   LOG_UTILITY(fmt);  
//}
//GUEST_FUNCTION_HOOK(sub_820D1998);
//#else
//GUEST_FUNCTION_STUB(sub_82BD4CA8);
//#endif
//
GUEST_FUNCTION_HOOK(sub_824665A0, QueryPerformanceCounterImpl);
GUEST_FUNCTION_HOOK(sub_82466568, QueryPerformanceFrequencyImpl);
GUEST_FUNCTION_HOOK(sub_8248D098, GetTickCountImpl);

GUEST_FUNCTION_HOOK(sub_8248CED0, GlobalMemoryStatusImpl);
//
//// sprintf
//PPC_FUNC(sub_82BD4AE8)
//{
//    sub_831B1630(ctx, base);
//}

PPC_FUNC_IMPL(__imp__sub_822741B8);
PPC_FUNC(sub_822741B8)
{
    auto threadName = reinterpret_cast<const char*>(base + ctx.r3.u32);
    auto fnStart = reinterpret_cast<uint32_t>(ctx.r4.u32);
    LOGF_UTILITY("Create Worker Thread '{}' Function Start = 0x{:x}", threadName, fnStart);
    __imp__sub_822741B8(ctx, base);
}


void D3DDeviceSetSamplersHook()
{
    return;
}

// SetupFramework??
//GUEST_FUNCTION_STUB(sub_826E5C78);
// UpdateGlobalRenderingFlags
//GUEST_FUNCTION_STUB(sub_82173DF8);
// fuck
//GUEST_FUNCTION_STUB(sub_8246EEB8);
