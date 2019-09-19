#ifndef CFG_DATA_STRUCT_H
#define CFG_DATA_STRUCT_H
#include "datatype.h"
#include "syslog.h"



typedef enum
{
    PID_Unknown,
    PID_Android_V2,  // ºËÐÄ°å+°²×¿ÃÅ¿Ú»ú
    PID_8130_Outdoor,// ºËÐÄ°å+XTM8130ÃÅ¿Ú»ú
    PID_8130_Indoor, // ºËÐÄ°å+XTM8130ÊÒÄÚ»ú
    PID_Analog_Louyu,// ºËÐÄ°å+Ä£ÄâÃÅ¿Ú»ú
    PID_Analog_Villa,// ºËÐÄ°å+Ä£Äâ±ðÊû»ú
    PID_Phone,       // ºËÐÄ°å+µç»°ÃÅ¿Ú»ú
    PID_Phone_SDK,   // ºËÐÄ°å+µç»°ÃÅ¿Ú»ú + µÚÈý·½¼¯³É£¨ÉîÛÚÎ÷ÎÖ£©
}ProductType_e;
typedef struct
{
    DWORD dwRoomID;
    DWORD dwCardCrc;
    BYTE  cHasGet;  // ÊÇ·ñÒÑ¾­´ÓGetRoomCardCrcº¯Êý±»È¡×ß¹ý,0±íÊ¾Ã»ÓÐÈ¡×ß£¬1±íÊ¾ÒÑ¾­È¡×ß
}RoomCardCrc_t;//CardCheck£¬¼ì²é¿¨ºÅ
typedef std::list<RoomCardCrc_t> ListRoomCardCrc;
const DWORD COUNT_ROOMID_CARDINDEX = 150;

typedef enum
{
    RR_Unknown,
    RR_Unlock_Mob = 1,   // APP¿ªÃÅ
    RR_Unlock_Card,      // Ë¢¿¨¿ªÃÅ
    RR_Unlock_Wifi,      // Wifi¿ªÃÅ
    RR_Unlock_TmpPwd,    // ÁÙÊ±ÃÜÂë¿ªÃÅ
    RR_Unlock_Pwd = 5,   // ×¡»§ÃÜÂë¿ªÃÅ
    RR_Unlock_CloudCard, // ²éÑ¯ÔÆÆ½Ì¨¿¨ºÅ¿ªÃÅ
    RR_Unlock_Bluetooth, // À¶ÑÀ¿ªÃÅ
    RR_Unlock_Indoor,    // ÊÒÄÚ»ú¿ªÃÅ
    RR_Unlock_Phone = 10,// µç»°¿ªÃÅ
    RR_CallTimeout = 21, // ÔÆºô½Ð³¬Ê±
    RR_CloudAnswer,      // App½ÓÌý
    RR_PhoneAnswer,      // µç»°½ÓÌý
}RecReason_e;

typedef enum
{
    UFT_JPG = 1,
    UFT_MP4 = 11,
    UFT_AVI = 12
}UploadFileType_e;
typedef struct
{
    DWORD dwTime;
    int   nReserveID; // ÓÃÓÚÔ¤¶¨Í¼Æ¬µÄÔ¤¶¨ºÅ¼ÇÂ¼
    char cTTL;  // ³¬Ê±ÐÄÌø¼ÇÂ¼
    DWORD dwRoomID;
    RecReason_e eReason;
    UploadFileType_e eType;
    CSTRING strLocalFile;
    DWORD dwFileSize; // µ¥Î»£º×Ö½Ú
}RecTask_t;     //ÈÎÎñ¼ÇÂ¼
typedef std::list<RecTask_t> List_RecTask;

typedef struct
{
    DWORD dwTime;
    DWORD dwDeviceID;
    DWORD dwStoreID;
    CSTRING strToken;
}UploadToken_t;
typedef struct
{
    DWORD		dwDeviceID;
    DWORD		dwRoomID;
    DWORD		dwSize;
    DWORD		dwStoreID;
    UploadFileType_e eType;
    RecReason_e eReason;
    DWORD dwTime;
}UploadResult_t;

typedef struct
{
    CSTRING strUsername;	// Ö÷ÕÊºÅ
    CSTRING strPassword;	// Ö÷ÕÊºÅÃÜÂë(des+base64)
    CSTRING strAppid;		// Ó¦ÓÃid
}UcpaasInfo_t; // ÔÆÖ®Ñ¶ÐÅÏ¢

typedef struct
{
    CSTRING strUserID;
    CSTRING strAccountSID;
    CSTRING strAuthToken;
    CSTRING strAppKey;
    CSTRING strVendorDisplayNumber;//À´µçÏÔÊ¾ºÅÂë
}YuntxInfo_t;  //ÈÝÁªÔÆÍ¨Ñ¶
typedef enum
{
    CA_VATTRTYPE_BRIGHTNESS = 0x00000001,
    CA_VATTRTYPE_CONTRAST   = 0x00000002,
    CA_VATTRTYPE_HUE        = 0x00000004,
    CA_VATTRTYPE_SATURATION = 0x00000008,
    CA_VATTRTYPE_SHARPNESS  = 0x00000010,
    CA_VATTRTYPE_MIRROR	    = 0x00000020,
    CA_VATTRTYPE_REVERSE	= 0x00000040,
    CA_VATTRTYPE_FLICKER	= 0x00000080,
    CA_VATTRTYPE_TARGETY    = 0x00000100,
}VideoAttrMode_e;   //ÊÓÆµ²ÎÊýÀàÐÍ

typedef enum
{
    CA_VATTRINDEX_BRIGHTNESS	= 0,		// Í¼ÏñÁÁ¶È
    CA_VATTRINDEX_CONTRAST		= 1,		// Í¼Ïñ¶Ô±È¶È
    CA_VATTRINDEX_HUE			= 2,		// Í¼ÏñÉ«¶È
    CA_VATTRINDEX_SATURATION	= 3,		// Í¼Ïñ±¥ºÍ¶È
    CA_VATTRINDEX_SHARPNESS		= 4,		// Í¼ÏñÈñÀû¶È
    CA_VATTRINDEX_MIRROR		= 5,		// ×óÓÒ¾µÏñ
    CA_VATTRINDEX_REVERSE		= 6,		// ÉÏÏÂ·­×ª
    CA_VATTRINDEX_FLICKER		= 7,		// ÉÁË¸ÆµÂÊ
    CA_VATTRINDEX_TARGETY		= 8,		// ¾µÍ·ÁÁ¶È
}VideoAttrIndex_e;  //ÊÓÆµ²ÎÊýË÷Òý

typedef struct
{
    BYTE cIspInit;
    BYTE cBrightness;   //ÁÁ¶È
    BYTE cContrast;     //¶Ô±È¶È
    BYTE cHue;          //É«¶È
    BYTE cSaturation;   //±¥ºÍ¶È
    BYTE cSharpness;    //ÈñÀû¶È
    BYTE cMirror;       //×óÓÒ¾µÏñ
    BYTE cReverse;      //ÉÏÏÂ·­×ª
    BYTE cFlicker;      //0: 60Hz; 1: 50Hz
    BYTE cTargetY;      //ÉãÏñÍ·ÁÁ¶È targetY [0~255 def:85]
}VideoAttr_t;   //ÊÓÆµ²ÎÊýÊýÖµ
const DWORD CA_VATTRTYPE_COUNTVERSION0 = 9;
const DWORD CA_VIDEOATTRTYPE_VALUEMIN  = 0;		// ÊôÐÔ×îÐ¡Öµ
const DWORD CA_VIDEOATTRTYPE_VALUEMAX  = 100;	// ÊôÐÔ×î´óÖµ

typedef enum
{
    CA_REGISTERTYPE_NONE			= 0x0000,	// ÉãÏñ»ú²»Ïò×¢²á·þÎñÆ÷×¢²á
    CA_REGISTERTYPE_SCANAC			= 0x0001,	// ÉãÏñ»úÏò¾ÖÓòÍøÖÐËÑË÷µ½µÄ
                                                // ±¨¾¯ÖÐÐÄ×¢²á(Ä¬ÈÏÖµ)
    CA_REGISTERTYPE_DIRECTAC		= 0x0002,	// ÉãÏñ»úÏòÓÃ»§Éè¶¨µÄ
                                                // ±¨¾¯ÖÐÐÄ×¢²á
    CA_REGISTERTYPE_PLATFORM		= 0x0003,	// ÉãÏñ»úÏòÆ½Ì¨×¢²á
}RegSvrType_e;  //×¢²á·þÎñÆ÷ÀàÐÍ

typedef struct
{
    RegSvrType_e eType;
    DWORD   dwSvr1IP;
    WORD    wSvr1Port;
    WORD    wSvr2Port;
    CSTRING strSvr1Dns;
}RegisterInfo_t;

typedef struct
{
    CSTRING strDevName;
    CSTRING strDevPwd;
    CSTRING strSerialNo;
    CSTRING strVer;
    DWORD   dwDeviceID;
    DWORD   dwVendorID;
    short   sZone; // Ê±Çø£¬GM+8±íÊ¾Îª8*60=480 ÒÔ·ÖÖÓÎªµ¥Î»¼ÇÂ¼
    int     nNet2DialSec; // ÍøÂçºô½Ð×ª²¦´òµç»°µÄÊ±¼ä¼ä¸ô£¨µ¥Î»£ºÃë£©
    RegisterInfo_t tRegInfo;
    BYTE cWorkMode;
}SystemInfo_t;  //ÏµÍ³ÐÅÏ¢
typedef enum
{
    VMT_UNKNOWN,
    VMT_MOB = 0x01, //ÊÖ»ú¶ËÊÓÆµ
    VMT_PC  = 0x02, //pc¶ËÊÓÆµ
    VMT_REC = 0x04  //Â¼Ïñ
}VideoModeType_e;   //ÊÓÆµÀàÐÍ
typedef enum
{
    WLM_UNKNOWN,
    WLM_SOFTAP,
    WLM_STATION
}WlMode_e;  //ÎÞÏßÄ£Ê½
typedef enum
{
    WLS_UNKNOWN,
    WLS_WPA,
    WLS_WEP,
    WLS_NONE,  // Î´¼ÓÃÜ,
    WLS_TOTAL
}WLSecurity_e;  //ÎÞÏß¼ÓÃÜÀàÐÍ
typedef enum
{
    AM_UNKNOWN,
    AM_DHCP,    //×Ô¶¯·ÖÅäIP
    AM_STATIC   //¹Ì¶¨IP
}AddrMode_e;    //IPµØÖ·ÀàÐÍ
typedef enum
{
    NM_UNKNOWN,
    NM_WIRE,    //ÓÐÏß
    NM_WIFI     //ÎÞÏß
}NetMode_e;     //ÍøÂçÀàÐÍ

const DWORD LEN_MAC = 17;
typedef struct
{
    NetMode_e eNetMode;     //ÍøÂçÀàÐÍ
    WORD  wAppPort;         //¶Ë¿ÚºÅ
    BYTE  szMac[LEN_MAC+1]; //ÎïÀíµØÖ·
}NetCommon_t;   //ÍøÂçÊôÐÔ

typedef struct
{
    AddrMode_e eAddrMode;   //µØÖ·ÀàÐÍ
    DWORD dwIP;             //IP
    DWORD dwMask;           //ÑÚÂë
    DWORD dwGateway;        //Íø¹Ø
}AddrParam_t;               //IPµØÖ·²ÎÊý

typedef struct
{
    AddrMode_e eDnsMode;
    DWORD dwDns1;
    DWORD dwDns2;
}DnsParam_t;                //ÓòÃû½âÎö²ÎÊý

typedef struct
{
    WlMode_e eWLMode;
}WLCommon_t;

typedef struct
{
    CSTRING strSSID;
    WLSecurity_e eSecurity;
}SoftApParam_t;

typedef struct
{
    int nCurrent;
    CSTRING strPwd;
    SoftApParam_t tApInfo;
}PeerApInfo_t;

typedef std::map<CSTRING/*strAddr*/, PeerApInfo_t> MAP_PEERAP;

typedef struct
{
    WLCommon_t    tWlCom;
    SoftApParam_t tSAP;
    MAP_PEERAP    mapPeerAP;
}WlParam_t;

typedef struct
{
    NetCommon_t tNetCom;
    AddrParam_t tAddr;
    DnsParam_t  tDns;
    WlParam_t   tWireless;
}NetworkInfoV2_t;

typedef struct
{
    DWORD dwRecMode;
    DWORD dwPcMode;
    DWORD dwMobMode;
    VideoAttr_t tParam;
    DWORD dwPhotoMode;// bit0:ºô½ÐÊ§°Ü(³¬Ê±,Î´½ÓÌý) bit1:App½ÓÌýbit2:µç»°½ÓÌýbit3:APP¿ªËøbit4:µç»°¿ªËøbit5:Ë¢¿¨¿ªËøbit6:ÃÜÂë¿ªËø
}VideoInfo_t;

typedef struct
{
    BYTE cCapVolume;
    BYTE cPlayVolume;
}AudioInfo_t;

typedef struct
{
    CSTRING strName;
    BYTE cDefVal; //0: À­µÍ; 1: À­¸ß
    BYTE cMode;   //Bit0: DO1; Bit1: DO2
}DiParam_t;

typedef struct
{
    CSTRING strName;
    BYTE cDefVal;     //0: À­µÍ; 1: À­¸ß
    DWORD dwInterval; //ms
}DoParam_t;

typedef struct
{
    BYTE cBtnMode; // bit0=1 ±íÊ¾°´¼ü´¥·¢do1£»bit1=1 ±íÊ¾°´¼ü´¥·¢do2£»bit2=1 ±íÊ¾°´¼ü´¥·¢Æ½Ì¨±¨¾¯
    BYTE cAlarmST; // 1=³··À£»2=²¼·À
    DiParam_t tDi[3];
    DoParam_t tDo[2];
    BYTE cVideoLed;		  // ²¹¹âµÆ¹¦ÄÜ 1:´ò¿ª 0:¹Ø±Õ;
    BYTE cWav_btn;		  // °´¼üÁåÉù²¥·ÅÑ­»·´ÎÊý £¨0¡¢1¡¢3¡¢5¡¢8¡¢10£©;
    BYTE cWav_come;		  // À´ÈËÌáÊ¾ÁåÉù²¥·ÅÑ­»·´ÎÊý£¨0¡¢1¡¢3¡¢5¡¢8¡¢10£©;
    BYTE cBtnled_work;	  // °´¼üÖ¸Ê¾µÆ¹¤×÷×´Ì¬;
    BYTE cBtnled_abnormal;// °´¼üÖ¸Ê¾µÆÒì³£×´Ì¬;
    BYTE cBtnled_calling; // °´¼üÖ¸Ê¾µÆºô½ÐµÈ´ý×´Ì¬;
    BYTE cBtnled_process; // °´¼üÖ¸Ê¾µÆºô½Ð´¦Àí×´Ì¬;
}DioInfo_t;

typedef struct
{
    CSTRING strNum; // ·¿ºÅ
    ListCString listPhone;
    ListCString listCard;
}Uart_RoomInfo_t;

#define DEF_BTN_E_TAG  		"E-BTN"//"Emergency"
#define DEF_BTN_C_TAG  		"C-BTN"//"Consult"

#define ALL_ROOM_NUM        "ffffffff"

typedef enum
{
    // Éè±¸Ö÷ÀàÐÍ
    CA_DEVICETYPE_MAIN_GM8126  = 0,  // GM8126Æ½Ì¨Éè±¸
    CA_DEVICETYPE_MAIN_AK3918  = 1,  // AK3918Æ½Ì¨Éè±¸
    CA_DEVICETYPE_MAIN_GM8136  = 2,  // GM8136Æ½Ì¨Éè±¸
    CA_DEVICETYPE_MAIN_ANDROID = 3,  // °²×¿Æ½Ì¨Éè±¸

    // Éè±¸×ÓÀàÐÍ
    CA_DEVICETYPE_SUB_ALARM   = 0,  // ±¨¾¯Éè±¸
    CA_DEVICETYPE_SUB_LINK    = 1,  // ±¨¾¯Áª¶¯Éè±¸
    CA_DEVICETYPE_SUB_IPC     = 2,  // Ïû·ÑÀàÒÆ¶¯ÉãÏñ»ú
    CA_DEVICETYPE_SUB_OUTDOOR = 3,  // Â¥ÓîÃÅ¿Ú»ú
    CA_DEVICETYPE_SUB_INDOOR  = 4,  // Â¥ÓîÊÒÄÚ»ú
}DeviceType_e;

typedef struct
{
    DWORD dwID;
    DWORD dwNetID;
    DWORD dwIP;
    CSTRING strPos;
}DSvrInfo_t;
typedef std::list<DSvrInfo_t> LIST_DSVR;
//////////////////////////////////////////////////////////////////////////

typedef struct
{
    DWORD dwUsrID;
    DWORD dwVID;
    DWORD dwLangID; // Lang: 0:China 1=Taiwei 2=English
    CSTRING strContact;
    CSTRING strDevAlias; // Éè±¸±ðÃû
}UserInfo_t;
typedef std::list<UserInfo_t> LIST_USER;

typedef struct
{
    DWORD dwUsrID;
    DWORD dwVID;
    DWORD dwLangID;     // Lang: 0:China 1=Taiwei 2=English
    DWORD dwPushType;   // 1-Ô­ÉúIOS; 2-°Ù¶ÈAndroid ;3-¸öÍÆIOS;4-¸öÍÆAndroid;5-°Ù¶ÈIOS;6-¼«¹âIOS;7-¼«¹âAndroid;8-Ð¡Ã×Android;9-»ªÎªAndroid;10-÷È×åAndroid;11-ÊÒÄÚ»ú
    CSTRING strToken;
}PushInfo_t;
typedef std::list<PushInfo_t> LIST_PUSH;

typedef struct
{
    PushInfo_t tPushInfo;
    CSTRING strDevAlias;
}PushInfoEx_t;
typedef std::list<PushInfoEx_t> LIST_PUSH_EX;

typedef struct
{
    CSTRING strNum; // ¿¨ºÅ
    BYTE    cType;  // ¿¨ÀàÐÍ£¬µ±Ç°Î´¶¨Òå
    DWORD   dwDeadline;//¿¨ºÅ½ØÖ¹ÈÕÆÚ
}CardInfo_t;
typedef std::list<CardInfo_t> LIST_CARD;

//·¿ºÅÊôÐÔÒªÏÞÖÆµÄ¹¦ÄÜ
typedef enum
{
    RA_CardUnlock   = 8,//Ë¢¿¨¿ªËø
    RA_AppUnlock    = 9,//App¿ªËø
    RA_PhoneUnlock = 10,//µç»°¿ªËø
}RoomAttr_e;

typedef struct
{
    DWORD dwUserID;
    DWORD dwIndoorID;
    BYTE cStatus;//ÊÒÄÚ»úÔÚÏß×´Ì¬
} IndoorInfo_t;
typedef std::list<IndoorInfo_t> LIST_INDOOR;

typedef std::map<DWORD,  BYTE> MAP_DEVICE_STATUS;//Éè±¸IDºÍÉè±¸×´Ì¬

typedef struct
{
    CSTRING strNum; // ·¿ºÅ
    CSTRING strPwd; // ¿ªÃÅÃÜÂë
    DWORD dwRoomAttr;//·¿¼äÊôÐÔ
    DWORD dwUserIndex;	// ÓÃ»§ÅäÖÃË÷Òý
    DWORD dwPushIndex;	// ÍÆËÍÅäÖÃË÷Òý
    DWORD dwCardIndex;	// ¿¨ºÅÅäÖÃË÷Òý
    DWORD dwIndoorIndex;// ÊÒÄÚ»úÅäÖÃË÷Òý
    LIST_USER listUser;     //ÓÃ»§ÁÐ±í
    LIST_PUSH listPush;     //ÍÆËÍÁÐ±í
    LIST_CARD listCard;     //¿¨ºÅÁÐ±í
    LIST_INDOOR listIndoor; //ÊÒÄÚ»úÁÐ±í
}RoomInfo_t;        //·¿¼äÐÅÏ¢
typedef std::map<DWORD, RoomInfo_t> MAP_ROOM;//RoomID ¶ÔÓ¦µÄ·¿¼äÕªÒªÐÅÏ¢

typedef struct
{
    DWORD dwRoomID;     //·¿ºÅID
    CSTRING strNum;     //·¿ºÅ
    CSTRING strPwd;     //¿ªÃÅÃÜÂë
    DWORD dwRoomAttr;   //·¿¼äÊôÐÔ£¬ÔÝÓÃÓÚ¿ØÖÆ·¿¼ä¿ªÃÅÈ¨ÏÞ
}RoomNodeInfo_t;        //·¿¼ä½ÚµãÐÅÏ¢
typedef std::list<RoomNodeInfo_t> LIST_ROOM_NODE;

//////////////////////////////////////////////////////////////////////////

typedef struct
{
    DWORD dwPushIndex;
    LIST_PUSH_EX listPushEx;
}RoomPushEx_t;


#endif




