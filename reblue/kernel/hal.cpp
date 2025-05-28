#include <stdafx.h>
#include "hal.h"

void reblue::kernel::VdHSIOCalibrationLock()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::XboxHardwareInfo()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::XGetVideoMode()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t reblue::kernel::FscSetCacheElementCount()
{
    return 0;
}

void reblue::kernel::HalReturnToFirmware()
{
    LOG_UTILITY("!!! STUB !!!");
}

bool reblue::kernel::VdPersistDisplay(uint32_t a1, uint32_t* a2)
{
    *a2 = NULL;
    return false;
}

void reblue::kernel::VdSwap()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdGetSystemCommandBuffer()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdEnableRingBufferRPtrWriteBack()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdInitializeRingBuffer()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdSetSystemCommandBufferGpuIdentifierAddress()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdShutdownEngines()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdQueryVideoMode(XVIDEO_MODE* vm)
{
    memset(vm, 0, sizeof(XVIDEO_MODE));
    vm->DisplayWidth = 1280;
    vm->DisplayHeight = 720;
    vm->IsInterlaced = false;
    vm->IsWidescreen = true;
    vm->IsHighDefinition = true;
    vm->RefreshRate = 0x42700000;
    vm->VideoStandard = 1;
    vm->Unknown4A = 0x4A;
    vm->Unknown01 = 0x01;
}

void reblue::kernel::VdGetCurrentDisplayInformation()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdSetDisplayMode()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdSetGraphicsInterruptCallback()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdInitializeEngines()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdIsHSIOTrainingSucceeded()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdGetCurrentDisplayGamma()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdQueryVideoFlags()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdCallGraphicsNotificationRoutines()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdInitializeScalerCommandBuffer()
{
    LOG_UTILITY("!!! STUB !!!");
}

uint32_t reblue::kernel::VdRetrainEDRAM()
{
    return 0;
}

void reblue::kernel::VdRetrainEDRAMWorker()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::StfsControlDevice()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::StfsCreateDevice()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::IoInvalidDeviceRequest()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::IoCheckShareAccess()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::IoSetShareAccess()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::IoRemoveShareAccess()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::IoDismountVolumeByFileHandle()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::IoDismountVolumeByName()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::IoSynchronousDeviceIoControlRequest()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::XMAReleaseContext()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::XMACreateContext()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::IoCreateDevice()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::IoDeleteDevice()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::IoCompleteRequest()
{
    LOG_UTILITY("!!! STUB !!!");
}

void reblue::kernel::VdEnableDisableClockGating()
{
    LOG_UTILITY("!!! STUB !!!");
}
