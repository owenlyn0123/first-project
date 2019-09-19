#ifndef CFG_INTERFACE_H
#define CFG_INTERFACE_H
#include "cfgdatastruct.h"
#include "netcondatastruct.h"

interface ICfgSink
{
    virtual ~ICfgSink() {}
    virtual void OnDelCard(CSTRING& strCardNum) VIRTUAL;
    virtual void OnNetParamChange() VIRTUAL;
    virtual void OnPlatformChange() VIRTUAL;
    virtual void OnSerialNumChange() {}
};
//ºËÐÄ°åÅäÖÃ½Ó¿Ú
interface ICloud
{
    virtual ~ICloud() {}
    virtual void   SetDevVendorID(DWORD dwVendorID) VIRTUAL;
    virtual int    GetDSvrList(DWORD& dwVendorID, DWORD& dwIndex, LIST_DSVR& lstDInfo) VIRTUAL;
    virtual void   SetDSvrList(DWORD dwVendorID, DWORD dwIndex, LIST_DSVR& lstDInfo) VIRTUAL;

    virtual void   AddRoomHeaderV2(RoomNodeInfo_t& tHeader) VIRTUAL;
    virtual void   AppendRoomUserV2(MAP_ROOM_USER_REP& mapRoom) VIRTUAL;
    virtual void   AppendRoomPushV2(MAP_ROOM_PUSH_REP& mapRoom) VIRTUAL;
    virtual void   AppendRoomCardV2(MAP_ROOM_CARD_REP& mapRoom) VIRTUAL;
    virtual void   UpdateRoomInfoV2(LIST_ROOM_NODE& listRoom) VIRTUAL;
    virtual void   DelRoomV2(ListDword& listRoom) VIRTUAL;

    virtual DWORD  GetDSvrCfgIndex() VIRTUAL;
    virtual DWORD  GetUserCfgIndex(DWORD dwRoomID) VIRTUAL;
    virtual DWORD  GetPushCfgIndex(DWORD dwRoomID) VIRTUAL;
    virtual DWORD  GetCardCfgIndex(DWORD dwRoomID) VIRTUAL;
    virtual DWORD  GetIndoorCfgIndex(DWORD dwRoomID) VIRTUAL;

    virtual void   FlushRoomNode(LIST_ROOM_NODE& listRoom) VIRTUAL;

    virtual int    GetRoomPush(DWORD dwRoomID, RoomPushEx_t& tPushEx) VIRTUAL;
    virtual int    GetRoomPush_ExceptUser(DWORD dwRoomID, RoomPushEx_t& tPushEx, DWORD dwUserID) VIRTUAL;
    virtual int    GetUserPush(DWORD dwRoomID, DWORD dwUserID, RoomPushEx_t& tPushEx) VIRTUAL;

    virtual void   DelRoom(DWORD dwRoomID, bool bSave = true) VIRTUAL;
    virtual DWORD  GetRoomID(PUCHAR pRoomNum) VIRTUAL;
    virtual DWORD  GetRoomIDbyCard(PUCHAR pCardNum) VIRTUAL;
    virtual void   GetRoomID(DWORD dwUserID, SET_DWORD& setRoomID) VIRTUAL;
    virtual int GetRoomIDFromPush(DWORD dwUserID, SET_DWORD& setRoomID) VIRTUAL;
    virtual DWORD  GetRoomIDByCardNum(PUCHAR pCardNum, DWORD&  dwUserID) VIRTUAL;
    virtual DWORD  GetRoomID_Wuye() VIRTUAL;
    virtual void   GetRoomNum(DWORD dwRoomID, CSTRING& strRoomNum) VIRTUAL;
    virtual bool   GetRoomInfo(Uart_RoomInfo_t& tRoom) VIRTUAL;
    virtual void   GetRoomNum(DWORD dwUserID, ListCString& listRoomNum) VIRTUAL;
    virtual PUCHAR GetUserContact(DWORD dwUserID) VIRTUAL;

    virtual bool   CheckRoomUser(DWORD dwUserID, SET_DWORD& setRoomID) VIRTUAL;
    virtual bool   CheckCardNum(PUCHAR pCardNum, CSTRING& strNum) VIRTUAL;
    virtual bool   CheckUnlockPwd(PUCHAR pPwd) VIRTUAL;
    virtual bool   CheckUnlockPwd(PUCHAR pRoomNum, PUCHAR pPwd) VIRTUAL;

    virtual void   GetRoomPhoneNums(DWORD dwRoomID, ListCString& listPhoneNum) VIRTUAL;
    virtual DWORD  GetUserID(PUCHAR pPhoneNum) VIRTUAL;
    // »ñÈ¡·¿ºÅÏÂµÄµÚÒ»¸öÓÃ»§ID
    virtual DWORD  GetUserID(DWORD dwRoomID) VIRTUAL;
    virtual DWORD  GetUserID(DWORD dwRoomID, PUCHAR pPhoneNum) VIRTUAL;

    // ¸ø°²×¿»úÍ¬²½¿¨ºÅÓÃµÄ½Ó¿Ú
    virtual DWORD  GetRoomCardCrc(ListRoomCardCrc& listCheckSum, int nCount) VIRTUAL;
    virtual DWORD  DelRoomCardCrc(int nCount) VIRTUAL;
    virtual void   UpdateRoomCardCrc() VIRTUAL;
    virtual bool   GetRoomCardInfo(DWORD dwRoomID, DWORD& dwCardCrc, LIST_CARD& listCard) VIRTUAL;

    virtual DWORD  GetRoomAttr(PUCHAR pRoomNum) VIRTUAL;
    virtual DWORD  GetRoomAttr(DWORD dwRoomID) VIRTUAL;

    virtual void   GetIndoorID(ListDword& lstID) VIRTUAL;
    virtual void   SetIndoorStatus(LIST_INDOOR& lstIndoor) VIRTUAL;

    virtual void ResetIndex(SET_DWORD&  setRoomID) VIRTUAL;
};

//ÍøÂçÐÅÏ¢ÅäÖÃ½Ó¿Ú
interface INetCfg
{
    virtual ~INetCfg() {}
    virtual void   GetAppAddr(DWORD& dwIP, WORD& wPort) VIRTUAL;
    virtual void   GetNetInfo(NetworkInfoV2_t& tInfo) VIRTUAL;
    virtual NetMode_e GetNetMode() VIRTUAL;
    virtual bool   SetWireNetInfo(NetworkInfoV2_t& tInfo, bool& bUpdateMac) VIRTUAL;
    virtual bool   SetAppPort(WORD wPort) VIRTUAL;
    virtual WORD   GetAppPort() VIRTUAL;
    virtual bool   IsRandomPort() VIRTUAL;
    virtual bool   UpdateRandomPort(WORD wPort) VIRTUAL;
    virtual bool   GetProtocolMac(PUCHAR pMac) VIRTUAL;
    virtual bool   SetNetMode(NetMode_e eMode) VIRTUAL;
    virtual const char*  GetDhcpFile_Eth0() VIRTUAL;
    virtual const char*  GetDhcpFile_Wlan0() VIRTUAL;

    // Wireless
    virtual bool SetWlMode(WlMode_e eMode) VIRTUAL;
    virtual WlMode_e GetWlMode() VIRTUAL;
    virtual bool SetSoftApInfo(CSTRING& strSSID) VIRTUAL;
    virtual bool GetSoftApInfo(CSTRING& strSSID) VIRTUAL;
    virtual bool SetConnectAp(CSTRING& strAddr, PeerApInfo_t& tParam) VIRTUAL;
    virtual bool GetConnectAp(CSTRING& strAddr, PeerApInfo_t& tParam) VIRTUAL;
    virtual bool DelConnectAp(CSTRING& strAddr) VIRTUAL;
    virtual bool GetPeerAPs(MAP_PEERAP& mapPeerAP) VIRTUAL;
};

//ÅäÖÃ
interface ICfg : public ICloud, public INetCfg
{
    virtual ~ICfg() {}
    virtual short  GetZone() VIRTUAL;
    virtual bool   SetSdkVer(PUCHAR pVer) VIRTUAL;
    virtual PUCHAR GetDeviceDefName() VIRTUAL;
    virtual PUCHAR GetDeviceName() VIRTUAL;
    virtual bool   SetDeviceName(PUCHAR pName) VIRTUAL;
    virtual PUCHAR GetDevicePwd() VIRTUAL;
    virtual PUCHAR GetDevicePwd_MD5() VIRTUAL;
    virtual bool   SetDevicePwd(PUCHAR pPwd) VIRTUAL;
    virtual PUCHAR GetSerialNum() VIRTUAL;
    virtual bool   SetSerialNum(PUCHAR pSerialNum) VIRTUAL;
    virtual DWORD  GetSNID() VIRTUAL;
    virtual DWORD  GetDeviceType() VIRTUAL;
    virtual bool   SetPlatformAddr(RegisterInfo_t& tInfo) VIRTUAL;
    virtual void   GetPlatformAddr(RegisterInfo_t& tInfo) VIRTUAL;
    virtual bool   SetRegStatus(bool bReg) VIRTUAL;
    virtual bool   SaveSysCfgFile() VIRTUAL;

    virtual DWORD  GetVideoMode_Def(BYTE& cRes, BYTE& cFps, WORD& wBit) VIRTUAL;
    virtual DWORD  GetVideoMode(VideoModeType_e eType) VIRTUAL;
    virtual bool   SetVideoMode(DWORD dwMode, VideoModeType_e eType) VIRTUAL;
    virtual void   GetIspParam(VideoAttr_t& tParam) VIRTUAL;
    virtual bool   UpdateIspParam(VideoAttr_t& tParam) VIRTUAL;
    virtual bool   UpdateIspParam(DWORD dwAttrMode, VideoAttr_t& tParam) VIRTUAL;

    virtual bool   GetVolume(int& nRecordVolume, int& nPlayVolume) VIRTUAL;
    virtual bool   SetVolume(int nRecordVolume, int nPlayVolume) VIRTUAL;

    virtual void   GetDioInfo(DioInfo_t& tInfo) VIRTUAL;
    virtual bool   SetDioInfo(DWORD dwMask, DioInfo_t& tInfo) VIRTUAL;
    virtual BYTE   GetWavPlayTimes(WavType_e eWav) VIRTUAL;
    virtual bool   IsVideoLedEna() VIRTUAL;
    virtual void   GetBtnLedRule(PUCHAR pRule) VIRTUAL;

    virtual void   SetModelID(int nModelID) VIRTUAL;
    virtual int    GetModelID() VIRTUAL;
    virtual int    GetDevVID() VIRTUAL; // ·µ»Ø±¨¾¯Æ½Ì¨µÄVID
    virtual int    GetDevSensorID() VIRTUAL;
    virtual DWORD  GetPhotoMode() VIRTUAL;
    virtual bool   SetPhotoMode(DWORD dwValue) VIRTUAL;

    virtual CSTRING GetAlarmTag(AlarmType_e eType) VIRTUAL;
    // ÔÆ¶Ô½²ºô½Ð×ª²¦´òµç»°µÄÊ±¼ä¼ä¸ô
    virtual bool   GetCloudCallTimeout(int& nTimer) VIRTUAL;
    virtual bool   SetCloudCallTimeout(int nTimer) VIRTUAL;
    //ÉèÖÃ¹¤×÷Ä£Ê½£¬ÓÃÓÚÇø·ÖÊÇÔÚÃÅ½ûÆ½Ì¨»¹ÊÇÎïÒµÆ½Ì¨
    virtual void SetWorkMode(BYTE cWorkMode) VIRTUAL;
    virtual BYTE GetWorkMode() VIRTUAL;
};
ICfg* CSDK_GetCfgHandle();

// ÓÐ±ä»¯µÄ·¿ºÅ£¨Ä¿Ç°Ö»ÓÐµç»°ÃÅ¿Ú»úÊ¹ÓÃ£©
interface IRoomLog
{
    virtual ~IRoomLog() {}
    virtual bool  AddRoomLogItem(const char* pRoomNum) VIRTUAL;
    virtual bool  AddRoomLogItem(ListCString& listRoomNum) VIRTUAL;
    virtual const char* GetRoomLogItem() VIRTUAL;
    virtual bool  DelRoomLogItem(const char* pRoomNum) VIRTUAL;
    virtual void  SyncRoomLog_All() VIRTUAL;
};
IRoomLog* CSDK_GetRoomLog();

interface ICfgUtility
{
    virtual ~ICfgUtility() {}
    virtual void  Init_Version() VIRTUAL;
    virtual char* GetImageVersion() VIRTUAL;
    virtual int   GetMyDefinedSensorID() VIRTUAL;
    virtual ProductType_e GetProductType() VIRTUAL;
    virtual bool  IsPhoneLike() VIRTUAL;    // ÊÇ·ñÎªµç»°ÃÅ¿Ú»úºÍµç»°ÃÅ¿Ú»úSDK ÕâÁ½ÖÖÀàÐÍ
    virtual bool  IsAnalogLike() VIRTUAL;   // ÊÇ·ñÎªÄ£ÄâÃÅ¿Ú»úºÍÄ£Äâ±ðÊû»ú ÕâÁ½ÖÖÀàÐÍ
    virtual bool  HasAudioSwitch() VIRTUAL; // ÊÇ·ñÓÐÒôÆµÀ©Õ¹°æ¹¦ÄÜ
    virtual bool  WatchdogEnable() VIRTUAL; // GM8136 5.*°æ±¾ÓÐÐ§

    virtual bool  EnableVisitorUnlock() VIRTUAL;
    virtual void  ClearNetInfo(NetworkInfoV2_t& tInfo) VIRTUAL;

    virtual void  RegCfgSink(ICfgSink* pSink) VIRTUAL;
    virtual void  UnRegCfgSink(ICfgSink* pSink) VIRTUAL;

    virtual void  AppendErrToDisk(char* pErr) VIRTUAL;
};
ICfgUtility* CSDK_GetUtility();

bool Init_Cfg();
void Fini_Cfg();

#endif

