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

PPC_FUNC(sub_82273440) {
    PPC_FUNC_PROLOGUE();
    PPCRegister ctr{};
    PPCXERRegister xer{};
    PPCCRRegister cr0{};
    PPCCRRegister cr6{};
    PPCRegister r11{};
    PPCRegister r23{};
    PPCRegister r24{};
    PPCRegister r25{};
    PPCRegister r26{};
    PPCRegister r27{};
    PPCRegister r28{};
    PPCRegister r29{};
    PPCRegister r30{};
    PPCRegister r31{};
    PPCRegister f0{};
    PPCRegister temp{};
    uint32_t ea{};
    // mflr r12
    // bl 0x826bfc64
    // stwu r1,-160(r1)
    ea = -160 + ctx.r1.u32;
    PPC_STORE_U32(ea, ctx.r1.u32);
    ctx.r1.u32 = ea;
    // lis r11,-32101
    r11.s64 = -2103771136;
    // mr r26,r3
    r26.u64 = ctx.r3.u64;
    // addi r31,r11,22272
    r31.s64 = r11.s64 + 22272;
    // li r5,192
    ctx.r5.s64 = 192;
    // li r4,0
    ctx.r4.s64 = 0;
    // mr r3,r31
    ctx.r3.u64 = r31.u64;
    // bl 0x826bfcf0
    sub_826BFCF0(ctx, base);
    // li r23,0
    r23.s64 = 0;
    // mr r11,r31
    r11.u64 = r31.u64;
    // mr r10,r23
    ctx.r10.u64 = r23.u64;
loc_82273474:
    // mr r9,r10
    ctx.r9.u64 = ctx.r10.u64;
    // addi r10,r10,1
    ctx.r10.s64 = ctx.r10.s64 + 1;
    // stb r9,0(r11)
    PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
    // addi r11,r11,12
    r11.s64 = r11.s64 + 12;
    // addi r9,r31,192
    ctx.r9.s64 = r31.s64 + 192;
    // cmpw cr6,r11,r9
    cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
    // blt cr6,0x82273474
    if (cr6.lt) goto loc_82273474;
    // li r11,1
    r11.s64 = 1;
    // li r9,0
    ctx.r9.s64 = 0;
    // li r8,0
    ctx.r8.s64 = 0;
    // li r7,0
    ctx.r7.s64 = 0;
    // addi r6,r31,4
    ctx.r6.s64 = r31.s64 + 4;
    // li r5,0
    ctx.r5.s64 = 0;
    // stb r11,1(r31)
    PPC_STORE_U8(r31.u32 + 1, r11.u8);
    // li r4,-2
    ctx.r4.s64 = -2;
    // li r3,0
    ctx.r3.s64 = 0;
    // bl 0x8248d760
    sub_8248D760(ctx, base);
    // bl 0x8248b040
    sub_8248B040(ctx, base);
    // lis r11,-32249
    r11.s64 = -2113470464;
    // li r27,-1
    r27.s64 = -1;
    // stw r3,8(r31)
    PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
    // addi r4,r11,21016
    ctx.r4.s64 = r11.s64 + 21016;
    // mr r3,r27
    ctx.r3.u64 = r27.u64;
    // bl 0x82274140
    sub_82274140(ctx, base);
    // lis r30,-32101
    r30.s64 = -2103771136;
    // lwz r11,22468(r30)
    r11.u64 = PPC_LOAD_U32(r30.u32 + 22468);
    // cmplwi cr6,r11,0
    cr6.compare<uint32_t>(r11.u32, 0, xer);
    // beq cr6,0x822734ec
    if (cr6.eq) goto loc_822734EC;
    // lwz r11,232(r11)
    r11.u64 = PPC_LOAD_U32(r11.u32 + 232);
    // b 0x82273558
    goto loc_82273558;
loc_822734EC:
    // li r3,248
    ctx.r3.s64 = 248;
    // bl 0x826bdd60
    sub_826BDD60(ctx, base);
    // mr. r31,r3
    r31.u64 = ctx.r3.u64;
    cr0.compare<int32_t>(r31.s32, 0, xer);
    // beq 0x8227353c
    if (cr0.eq) goto loc_8227353C;
    // li r11,1
    r11.s64 = 1;
    // stb r23,0(r31)
    PPC_STORE_U8(r31.u32 + 0, r23.u8);
    // addi r28,r31,8
    r28.s64 = r31.s64 + 8;
    // li r29,3
    r29.s64 = 3;
    // stw r11,4(r31)
    PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_82273510:
    // mr r3,r28
    ctx.r3.u64 = r28.u64;
    // bl 0x82274558
    sub_82274558(ctx, base);
    // addic. r29,r29,-1
    xer.ca = r29.u32 > 0;
    r29.s64 = r29.s64 + -1;
    cr0.compare<int32_t>(r29.s32, 0, xer);
    // addi r28,r28,56
    r28.s64 = r28.s64 + 56;
    // bge 0x82273510
    if (!cr0.lt) goto loc_82273510;
    // stw r23,232(r31)
    PPC_STORE_U32(r31.u32 + 232, r23.u32);
    // stw r23,236(r31)
    PPC_STORE_U32(r31.u32 + 236, r23.u32);
    // stw r23,240(r31)
    PPC_STORE_U32(r31.u32 + 240, r23.u32);
    // stw r31,22468(r30)
    PPC_STORE_U32(r30.u32 + 22468, r31.u32);
    // stw r23,244(r31)
    PPC_STORE_U32(r31.u32 + 244, r23.u32);
    // b 0x82273544
    goto loc_82273544;
loc_8227353C:
    // mr r11,r23
    r11.u64 = r23.u64;
    // stw r11,22468(r30)
    PPC_STORE_U32(r30.u32 + 22468, r11.u32);
loc_82273544:
    // lis r3,2048
    ctx.r3.s64 = 134217728;
    // bl 0x822745b0
    sub_822745B0(ctx, base);
    // lwz r10,22468(r30)
    ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 22468);
    // mr r11,r3
    r11.u64 = ctx.r3.u64;
    // stw r11,232(r10)
    PPC_STORE_U32(ctx.r10.u32 + 232, r11.u32);
loc_82273558:
    // stw r11,0(r26)
    PPC_STORE_U32(r26.u32 + 0, r11.u32);
    // lis r10,-32134
    ctx.r10.s64 = -2105933824;
    // mr r11,r23
    r11.u64 = r23.u64;
    // lis r7,8192
    ctx.r7.s64 = 536870912;
    // li r6,64
    ctx.r6.s64 = 64;
    // ori r7,r7,4
    ctx.r7.u64 = ctx.r7.u64 | 4;
    // mr r5,r27
    ctx.r5.u64 = r27.u64;
    // li r4,0
    ctx.r4.s64 = 0;
    // stb r11,32486(r10)
    PPC_STORE_U8(ctx.r10.u32 + 32486, r11.u8);
    // li r3,4096
    ctx.r3.s64 = 4096;
    // bl 0x824675c0
    sub_824675C0(ctx, base);
    // mr. r31,r3
    r31.u64 = ctx.r3.u64;
    cr0.compare<int32_t>(r31.s32, 0, xer);
    // bne 0x82273598
    if (!cr0.eq) goto loc_82273598;
    // lis r11,-32249
    r11.s64 = -2113470464;
    // addi r3,r11,21524
    ctx.r3.s64 = r11.s64 + 21524;
    // bl 0x822739f0
    sub_822739F0(ctx, base);
loc_82273598:
    // lis r11,-32101
    r11.s64 = -2103771136;
    // mr r10,r23
    ctx.r10.u64 = r23.u64;
    // addi r11,r11,22600
    r11.s64 = r11.s64 + 22600;
    // mr r3,r31
    ctx.r3.u64 = r31.u64;
    // stw r31,0(r11)
    PPC_STORE_U32(r11.u32 + 0, r31.u32);
    // stb r10,4(r11)
    PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
    // stw r31,8(r11)
    PPC_STORE_U32(r11.u32 + 8, r31.u32);
    // bl 0x82274bc0
    sub_82274BC0(ctx, base);
    // bl 0x82272c00
    sub_82272C00(ctx, base);
    // lis r11,-32034
    r11.s64 = -2099380224;
    // lis r29,-32251
    r29.s64 = -2113601536;
    // addi r3,r11,-22704
    ctx.r3.s64 = r11.s64 + -22704;
    // lis r11,-32101
    r11.s64 = -2103771136;
    // lis r10,-32247
    ctx.r10.s64 = -2113339392;
    // addi r11,r11,-31092
    r11.s64 = r11.s64 + -31092;
    // lfs f0,20908(r29)
    ctx.fpscr.disableFlushMode();
    temp.u32 = PPC_LOAD_U32(r29.u32 + 20908);
    f0.f64 = double(temp.f32);
    // li r9,2
    ctx.r9.s64 = 2;
    // li r5,296
    ctx.r5.s64 = 296;
    // li r4,0
    ctx.r4.s64 = 0;
    // stfs f0,0(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 0, temp.u32);
    // stfs f0,4(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 4, temp.u32);
    // lfs f0,-5136(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5136);
    f0.f64 = double(temp.f32);
    // lis r10,-32034
    ctx.r10.s64 = -2099380224;
    // stfs f0,8(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 8, temp.u32);
    // addi r10,r10,-23232
    ctx.r10.s64 = ctx.r10.s64 + -23232;
    // stw r9,356(r10)
    PPC_STORE_U32(ctx.r10.u32 + 356, ctx.r9.u32);
    // lis r9,-32250
    ctx.r9.s64 = -2113536000;
    // addi r30,r9,-388
    r30.s64 = ctx.r9.s64 + -388;
    // li r9,1
    ctx.r9.s64 = 1;
    // lfs f0,0(r30)
    temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
    f0.f64 = double(temp.f32);
    // stb r9,0(r10)
    PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
    // lis r10,-32247
    ctx.r10.s64 = -2113339392;
    // stfs f0,16(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 16, temp.u32);
    // lfs f0,-5140(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5140);
    f0.f64 = double(temp.f32);
    // stfs f0,12(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 12, temp.u32);
    // bl 0x826bfcf0
    sub_826BFCF0(ctx, base);
    // lis r11,-32036
    r11.s64 = -2099511296;
    // li r5,524
    ctx.r5.s64 = 524;
    // addi r31,r11,-5536
    r31.s64 = r11.s64 + -5536;
    // li r4,0
    ctx.r4.s64 = 0;
    // mr r3,r31
    ctx.r3.u64 = r31.u64;
    // bl 0x826bfcf0
    sub_826BFCF0(ctx, base);
    // lis r11,-32247
    r11.s64 = -2113339392;
    // mr r27,r23
    r27.u64 = r23.u64;
    // mr r28,r23
    r28.u64 = r23.u64;
    // lis r25,-32133
    r25.s64 = -2105868288;
    // lfs f0,-5416(r11)
    ctx.fpscr.disableFlushMode();
    temp.u32 = PPC_LOAD_U32(r11.u32 + -5416);
    f0.f64 = double(temp.f32);
    // mr r11,r23
    r11.u64 = r23.u64;
    // stfs f0,4(r31)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r31.u32 + 4, temp.u32);
    // stw r11,520(r31)
    PPC_STORE_U32(r31.u32 + 520, r11.u32);
    // lis r11,-32036
    r11.s64 = -2099511296;
    // addi r24,r11,-7376
    r24.s64 = r11.s64 + -7376;
loc_82273668:
    // mr r31,r23
    r31.u64 = r23.u64;
loc_8227366C:
    // srawi r11,r31,2
    xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
    r11.s64 = r31.s32 >> 2;
    // lwz r3,-31532(r25)
    ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -31532);
    // mr r4,r27
    ctx.r4.u64 = r27.u64;
    // addze r11,r11
    temp.s64 = r11.s64 + xer.ca;
    xer.ca = temp.u32 < r11.u32;
    r11.s64 = temp.s64;
    // add r10,r3,r31
    ctx.r10.u64 = ctx.r3.u64 + r31.u64;
    // add r11,r11,r28
    r11.u64 = r11.u64 + r28.u64;
    // rlwinm r26,r11,2,0,29
    r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
    // lwz r11,912(r10)
    r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 912);
    // mtctr r11
    ctr.u64 = r11.u64;
    // bctrl 
    // PPC_CALL_INDIRECT_FUNC(ctr.u32);
    
    // addi r31,r31,4
    r31.s64 = r31.s64 + 4;
    // stwx r3,r26,r24
    PPC_STORE_U32(r26.u32 + r24.u32, ctx.r3.u32);
    // cmpwi cr6,r31,80
    cr6.compare<int32_t>(r31.s32, 80, xer);
    // blt cr6,0x8227366c
    if (cr6.lt) goto loc_8227366C;
    // addi r28,r28,20
    r28.s64 = r28.s64 + 20;
    // addi r27,r27,1
    r27.s64 = r27.s64 + 1;
    // cmpwi cr6,r28,320
    cr6.compare<int32_t>(r28.s32, 320, xer);
    // blt cr6,0x82273668
    if (cr6.lt) goto loc_82273668;
    // lis r11,-32036
    r11.s64 = -2099511296;
    // mr r31,r23
    r31.u64 = r23.u64;
    // addi r27,r11,-7768
    r27.s64 = r11.s64 + -7768;
loc_822736C0:
    // lwz r3,-31532(r25)
    ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -31532);
    // srawi r11,r31,2
    xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
    r11.s64 = r31.s32 >> 2;
    // add r10,r3,r31
    ctx.r10.u64 = ctx.r3.u64 + r31.u64;
    // addze r11,r11
    temp.s64 = r11.s64 + xer.ca;
    xer.ca = temp.u32 < r11.u32;
    r11.s64 = temp.s64;
    // rlwinm r28,r11,2,0,29
    r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
    // lwz r11,524(r10)
    r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 524);
    // mtctr r11
    ctr.u64 = r11.u64;
    // bctrl 
    // PPC_CALL_INDIRECT_FUNC(ctr.u32);

    // addi r31,r31,4
    r31.s64 = r31.s64 + 4;
    // stwx r3,r28,r27
    PPC_STORE_U32(r28.u32 + r27.u32, ctx.r3.u32);
    // cmpwi cr6,r31,388
    cr6.compare<int32_t>(r31.s32, 388, xer);
    // blt cr6,0x822736c0
    if (cr6.lt) goto loc_822736C0;

    // lis r11,-32033
    r11.s64 = -2099314688;
    // li r5,56
    ctx.r5.s64 = 56;
    // addi r31,r11,-30448
    r31.s64 = r11.s64 + -30448;
    // li r4,0
    ctx.r4.s64 = 0;
    // mr r3,r31
    ctx.r3.u64 = r31.u64;
    // bl memset
    sub_826BFCF0(ctx, base);
    // lis r11,-32036
    r11.s64 = -2099511296;
    // li r5,516
    ctx.r5.s64 = 516;
    // addi r3,r11,-6096
    ctx.r3.s64 = r11.s64 + -6096;
    // lis r11,-32215
    r11.s64 = -2111242240;
    // li r4,0
    ctx.r4.s64 = 0;
    // addi r11,r11,-31528
    r11.s64 = r11.s64 + -31528;
    // stw r11,48(r31)
    PPC_STORE_U32(r31.u32 + 48, r11.u32);
    // mr r11,r23
    r11.u64 = r23.u64;
    // stw r11,52(r31)
    PPC_STORE_U32(r31.u32 + 52, r11.u32);
    // bl 0x826bfcf0
    sub_826BFCF0(ctx, base);
    // lis r11,-32137
    r11.s64 = -2106130432;
    // lis r9,-32242
    ctx.r9.s64 = -2113011712;
    // addi r10,r11,32276
    ctx.r10.s64 = r11.s64 + 32276;
    // lis r11,-32034
    r11.s64 = -2099380224;
    // addi r9,r9,-1456
    ctx.r9.s64 = ctx.r9.s64 + -1456;
    // addi r11,r11,-22320
    r11.s64 = r11.s64 + -22320;
    // lis r8,-32242
    ctx.r8.s64 = -2113011712;
    // lfs f0,0(r10)
    ctx.fpscr.disableFlushMode();
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
    f0.f64 = double(temp.f32);
    // stfs f0,4(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 4, temp.u32);
    // lfs f0,4(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
    f0.f64 = double(temp.f32);
    // stfs f0,8(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 8, temp.u32);
    // lfs f0,8(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
    f0.f64 = double(temp.f32);
    // li r10,2
    ctx.r10.s64 = 2;
    // stfs f0,12(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 12, temp.u32);
    // stb r10,0(r11)
    PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
    // lis r10,-32137
    ctx.r10.s64 = -2106130432;
    // addi r10,r10,32288
    ctx.r10.s64 = ctx.r10.s64 + 32288;
    // lfs f0,0(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
    f0.f64 = double(temp.f32);
    // stfs f0,28(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 28, temp.u32);
    // stw r9,212(r11)
    PPC_STORE_U32(r11.u32 + 212, ctx.r9.u32);
    // lfs f0,4(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
    f0.f64 = double(temp.f32);
    // addi r9,r8,-1456
    ctx.r9.s64 = ctx.r8.s64 + -1456;
    // stfs f0,32(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 32, temp.u32);
    // lfs f0,8(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
    f0.f64 = double(temp.f32);
    // lis r10,-32137
    ctx.r10.s64 = -2106130432;
    // addi r10,r10,32300
    ctx.r10.s64 = ctx.r10.s64 + 32300;
    // stw r9,216(r11)
    PPC_STORE_U32(r11.u32 + 216, ctx.r9.u32);
    // stfs f0,36(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 36, temp.u32);
    // lfs f0,0(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
    f0.f64 = double(temp.f32);
    // stfs f0,72(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 72, temp.u32);
    // lfs f0,4(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
    f0.f64 = double(temp.f32);
    // stfs f0,76(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 76, temp.u32);
    // lfs f0,8(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
    f0.f64 = double(temp.f32);
    // lis r10,-32137
    ctx.r10.s64 = -2106130432;
    // stfs f0,80(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 80, temp.u32);
    // lfs f0,-6612(r30)
    temp.u32 = PPC_LOAD_U32(r30.u32 + -6612);
    f0.f64 = double(temp.f32);
    // stfs f0,44(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 44, temp.u32);
    // lfs f0,-6616(r30)
    temp.u32 = PPC_LOAD_U32(r30.u32 + -6616);
    f0.f64 = double(temp.f32);
    // stfs f0,40(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 40, temp.u32);
    // lfs f0,32312(r10)
    temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32312);
    f0.f64 = double(temp.f32);
    // stfs f0,48(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 48, temp.u32);
    // lfs f0,20908(r29)
    temp.u32 = PPC_LOAD_U32(r29.u32 + 20908);
    f0.f64 = double(temp.f32);
    // stfs f0,52(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 52, temp.u32);
    // lfs f0,-6604(r30)
    temp.u32 = PPC_LOAD_U32(r30.u32 + -6604);
    f0.f64 = double(temp.f32);
    // stfs f0,56(r11)
    temp.f32 = float(f0.f64);
    PPC_STORE_U32(r11.u32 + 56, temp.u32);
    // bl 0x8227d9d0
    sub_8227D9D0(ctx, base);
    // lis r11,-32137
    r11.s64 = -2106130432;
    // addi r3,r11,9712
    ctx.r3.s64 = r11.s64 + 9712;
    // bl 0x8247c418
    sub_8247C418(ctx, base);
    // lis r11,-32249
    r11.s64 = -2113470464;
    // addi r4,r11,21028
    ctx.r4.s64 = r11.s64 + 21028;
    // lis r11,-32101
    r11.s64 = -2103771136;
    // stw r3,22464(r11)
    PPC_STORE_U32(r11.u32 + 22464, ctx.r3.u32);
    // li r3,4
    ctx.r3.s64 = 4;
    // bl 0x82270930
    sub_82270930(ctx, base);
    // bl 0x82285eb8
    sub_82285EB8(ctx, base);
    // bl 0x82284ee8
    sub_82284EE8(ctx, base);
    // lis r11,-32249
    r11.s64 = -2113470464;
    // li r3,0
    ctx.r3.s64 = 0;
    // addi r4,r11,20896
    ctx.r4.s64 = r11.s64 + 20896;
    // bl 0x822749d8
    sub_822749D8(ctx, base);
    // lis r10,-32035
    ctx.r10.s64 = -2099445760;
    // lis r11,-32217
    r11.s64 = -2111373312;
    // addi r31,r10,-26176
    r31.s64 = ctx.r10.s64 + -26176;
    // mr r6,r3
    ctx.r6.u64 = ctx.r3.u64;
    // li r5,18
    ctx.r5.s64 = 18;
    // stw r6,-4(r31)
    PPC_STORE_U32(r31.u32 + -4, ctx.r6.u32);
    // addi r4,r11,10176
    ctx.r4.s64 = r11.s64 + 10176;
    // bl 0x82274b20
    sub_82274B20(ctx, base);
    // lwz r11,-52(r6)
    r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -52);
    // stw r11,0(r31)
    PPC_STORE_U32(r31.u32 + 0, r11.u32);
    // addi r1,r1,160
    ctx.r1.s64 = ctx.r1.s64 + 160;
    // b 0x826bfcb4
    return;
}
