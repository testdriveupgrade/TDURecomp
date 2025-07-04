#pragma once
#include <xbox.h>

#define MSGID(Area, Number) (uint32_t)((uint16_t)(Area) << 16 | (uint16_t)(Number))
#define MSG_AREA(msgid)     (((msgid) >> 16) & 0xFFFF)
#define MSG_NUMBER(msgid)   ((msgid) & 0xFFFF)
namespace reblue {
namespace kernel {
    XCONTENT_DATA XamMakeContent(uint32_t type, const std::string_view& name);
    void XamRegisterContent(const XCONTENT_DATA& data, const std::string_view& root);

    std::string_view XamGetRootPath(const std::string_view& root);
    void XamRootCreate(const std::string_view& root, const std::string_view& path);

    uint32_t XamNotifyCreateListener(uint64_t qwAreas);
    void XamNotifyEnqueueEvent(uint32_t dwId, uint32_t dwParam); // i made it the fuck up
    bool XNotifyGetNext(uint32_t hNotification, uint32_t dwMsgFilter, big_endian<uint32_t>* pdwId, big_endian<uint32_t>* pParam);

    uint32_t XamShowMessageBoxUI(uint32_t dwUserIndex, big_endian<uint16_t>* wszTitle, big_endian<uint16_t>* wszText, uint32_t cButtons,
        xpointer<big_endian<uint16_t>>* pwszButtons, uint32_t dwFocusButton, uint32_t dwFlags, big_endian<uint32_t>* pResult, XXOVERLAPPED* pOverlapped);

    uint32_t XamContentCreateEnumerator(uint32_t dwUserIndex, uint32_t DeviceID, uint32_t dwContentType,
        uint32_t dwContentFlags, uint32_t cItem, big_endian<uint32_t>* pcbBuffer, big_endian<uint32_t>* phEnum);
    uint32_t XamEnumerate(uint32_t hEnum, uint32_t dwFlags, void* pvBuffer, uint32_t cbBuffer, big_endian<uint32_t>* pcItemsReturned, XXOVERLAPPED* pOverlapped);

    uint32_t XamContentCreateEx(uint32_t dwUserIndex, const char* szRootName, const XCONTENT_DATA* pContentData,
        uint32_t dwContentFlags, big_endian<uint32_t>* pdwDisposition, big_endian<uint32_t>* pdwLicenseMask,
        uint32_t dwFileCacheSize, uint64_t uliContentSize, PXXOVERLAPPED pOverlapped);
    uint32_t XamContentGetDeviceData(uint32_t DeviceID, XDEVICE_DATA* pDeviceData);
    uint32_t XamContentClose(const char* szRootName, XXOVERLAPPED* pOverlapped);

    uint32_t XamInputGetCapabilities(uint32_t unk, uint32_t userIndex, uint32_t flags, XAMINPUT_CAPABILITIES* caps);
    uint32_t XamInputGetState(uint32_t userIndex, uint32_t flags, XAMINPUT_STATE* state);
    uint32_t XamInputSetState(uint32_t userIndex, uint32_t flags, XAMINPUT_VIBRATION* vibration);

    uint32_t XamUserGetSigninState(uint32_t userIndex);

    uint32_t XamGetSystemVersion();

    void XamContentDelete();

    uint32_t XamContentGetCreator(uint32_t userIndex, const XCONTENT_DATA* contentData, big_endian<uint32_t>* isCreator, big_endian<uint64_t>* xuid, XXOVERLAPPED* overlapped);

    uint32_t XamContentGetDeviceState();

    uint32_t XamUserGetSigninInfo(uint32_t userIndex, uint32_t flags, XUSER_SIGNIN_INFO* info);

    void XamShowSigninUI();

    uint32_t XamShowDeviceSelectorUI
    (
        uint32_t userIndex,
        uint32_t contentType,
        uint32_t contentFlags,
        uint64_t totalRequested,
        big_endian<uint32_t>* deviceId,
        XXOVERLAPPED* overlapped
    );

    void XamShowDirtyDiscErrorUI();

    void XamEnableInactivityProcessing();

    void XamResetInactivity();

    void XamShowMessageBoxUIEx();

    void XamLoaderTerminateTitle();

    void XamGetExecutionId();

    void XamLoaderLaunchTitle();

    void XamUserReadProfileSettings
    (
        uint32_t titleId,
        uint32_t userIndex,
        uint32_t xuidCount,
        uint64_t* xuids,
        uint32_t settingCount,
        uint32_t* settingIds,
        big_endian<uint32_t>* bufferSize,
        void* buffer,
        void* overlapped
    );

    void XamContentSetThumbnail();

    uint32_t XamLoaderGetDvdTrayState();

    void XamTaskCloseHandle();

    void XamTaskSchedule();

    void XamTaskShouldExit();

    void XamUserCreateAchievementEnumerator();

    uint32_t XamUserGetName(uint32_t userIndex, char* userName, uint32_t userNameLength);

    uint32_t XamUserGetXUID(uint32_t userIndex, big_endian<uint64_t>* xuid);

    void XamUserWriteProfileSettings();

    // Additional stubbed kernel functions
    void XNotifyDelayUI(uint32_t dwMilliseconds);
    uint32_t XamLoaderGetLaunchDataSize(big_endian<uint32_t>* size);
    uint32_t XamLoaderGetLaunchData(void* buffer, uint32_t bufferSize, big_endian<uint32_t>* size);
    uint32_t XamLoaderSetLaunchData(const void* data, uint32_t size);
    void XamUserCreateStatsEnumerator();
    void XamWriteGamerTile();
    uint32_t XamShowKeyboardUI();
    uint32_t XamShowGamerCardUIForXUID();
    uint32_t XamShowMarketplaceUI();
    uint32_t XamContentGetLicenseMask(uint32_t userIndex, big_endian<uint32_t>* mask);
    uint32_t XamGetOverlappedResult(XXOVERLAPPED* pOverlapped, big_endian<uint32_t>* result, uint32_t wait);
    void XMsgCompleteIORequest(XXOVERLAPPED* pOverlapped, uint32_t status, uint32_t extendedError);

    // Missing kernel exports implemented as stubs
    void* XamGetPrivateEnumStructureFromHandle(uint32_t handle);
    void XamSessionRefObjByHandle();
    void XamSessionCreateHandle();
    void XamCreateEnumeratorHandle();
    void XamUserGetMembershipTierFromXUID();
    void XamUserGetOnlineCountryFromXUID();
}
}
