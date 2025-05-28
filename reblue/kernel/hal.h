#pragma once
#include <os/logger.h>
namespace reblue {
namespace kernel {
    void XboxHardwareInfo();
    void XGetVideoMode();
    uint32_t FscSetCacheElementCount();
    void HalReturnToFirmware();

    void VdHSIOCalibrationLock();
    bool VdPersistDisplay(uint32_t a1, uint32_t* a2);
    void VdSwap();
    void VdGetSystemCommandBuffer();
    void VdEnableRingBufferRPtrWriteBack();
    void VdInitializeRingBuffer();
    void VdSetSystemCommandBufferGpuIdentifierAddress();
    void VdShutdownEngines();
    void VdQueryVideoMode(XVIDEO_MODE* vm);
    void VdGetCurrentDisplayInformation();
    void VdSetDisplayMode();
    void VdSetGraphicsInterruptCallback();
    void VdInitializeEngines();
    void VdIsHSIOTrainingSucceeded();
    void VdGetCurrentDisplayGamma();
    void VdQueryVideoFlags();
    void VdCallGraphicsNotificationRoutines();
    void VdInitializeScalerCommandBuffer();
    uint32_t VdRetrainEDRAM();
    void VdRetrainEDRAMWorker();
    void VdEnableDisableClockGating();

    void StfsControlDevice();
    void StfsCreateDevice();

    void IoInvalidDeviceRequest();
    void IoCheckShareAccess();
    void IoSetShareAccess();
    void IoRemoveShareAccess();
    void IoDismountVolumeByFileHandle();
    void IoDismountVolumeByName();
    void IoSynchronousDeviceIoControlRequest();
    void IoCreateDevice();
    void IoDeleteDevice();
    void IoCompleteRequest();

    void XMAReleaseContext();
    void XMACreateContext();
}
}
