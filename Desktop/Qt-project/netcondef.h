#ifndef NET_CON_DEF_H
#define NET_CON_DEF_H
#include "netcondatastruct.h"
#include "cfgdatastruct.h"

#define CA_ADDR_MULTICAST_CAMERA		"236.6.8.1"	// ÉãÏñ»ú×é²¥¼ÓÈëµØÖ·
#define CA_ADDR_MULTICAST_CLIENT		"236.6.8.2"	// ¿Í»§¶Ë×é²¥¼ÓÈëµØÖ·

#if 1
#define CA_PORT_MULTICAST_CAMERA		9527		// ÉãÏñ»ú×é²¥¼ÓÈë¶Ë¿Ú(UDP)
#define CA_PORT_MULTICAST_CLIENT		9527		// ¿Í»§¶Ë×é²¥¼ÓÈë¶Ë¿Ú(UDP)
#else
#define CA_PORT_MULTICAST_CAMERA		49266		// ÉãÏñ»ú×é²¥¼ÓÈë¶Ë¿Ú(UDP)
#define CA_PORT_MULTICAST_CLIENT		49266		// ¿Í»§¶Ë×é²¥¼ÓÈë¶Ë¿Ú(UDP)
#endif

#define CA_PORT_UNICAST_CAMERA			9528		// ÉãÏñ»úµ¥²¥ÕìÌý¶Ë¿Ú(UDP)
#define CA_PORT_UNICAST_CLIENT			9528		// ¿Í»§¶Ëµ¥²¥ÕìÌý¶Ë¿Ú(UDP)

#define CA_PORT_CAMERA					9529		// ÉãÏñ»ú¹Ì¶¨ÕìÌý¶Ë¿Ú(TCP,UDP)

#define COUNT_ACCEPTOR                  4
typedef enum
{
    Apt_AppTcp,
    Apt_AppUdp,
    Apt_ComTcp,
    Apt_ComUdp,
}AcceptorIndex_e;

const DWORD TIMEOUT_TMPCON						= 5;

const BYTE CHECKSUMTYPE_NONE		            = 0x00;	    // ¿ÕÖµ,Ã»ÓÐÐ£ÑéÖµ
const BYTE PAYLOADVERSION_NONE	                = 0x00;	    // Ä¬ÈÏ,Payload DataÖ»ÓÐÒ»¸ö°æ±¾
const BYTE PAYLOADVERSION_1                     = 0x01;

const BYTE MAX_AP_COUNT_ONE_SEG = 24;
const DWORD DEF_CHANID          = 0xFFFFFFF;

typedef enum
{
    CT_NONE,
    CT_PeerCon,
    CT_PeerRawUdp,
    CT_RegAlc,
    CT_RegRelaySvr
}ClientType_e;

typedef enum
{
    CA_SYSTEMCMD_NONE			= 0x0000,	// ¿ÕÖµÎÞÒâÒå
    CA_SYSTEMCMD_SHUTDOWN		= 0x0001,	// ÉãÏñ»ú¹Ø»ú
    CA_SYSTEMCMD_RESTART		= 0x0002,	// ÉãÏñ»úÖØÆô
    CA_SYSTEMCMD_RESET			= 0x0003,	// ÉãÏñ»ú»¹Ô­
    CA_SYSTEMCMD_SAVE			= 0x0004,	// ÉãÏñ»ú±£´æ
    CA_SYSTEMCMD_LED_ON 		= 0x0005,	// ´ò¿ª²¹¹âµÆ¹¦ÄÜ
    CA_SYSTEMCMD_LED_OFF		= 0x0006,	// ¹Ø±Õ²¹¹âµÆ¹¦ÄÜ
}SysCtlCmd_e;

typedef enum
{
    MEDIATYPE_H264				= 0x91,	// H264±àÂë¸ñÊ½ÊÓÆµÊý¾Ý
    MEDIATYPE_PCM				= 0x11,	// PCM¸ñÊ½ÒôÆµÊý¾Ý
    MEDIATYPE_GSM				= 0x21,	// GSM¸ñÊ½ÒôÆµÊý¾Ý
    MEDIATYPE_G711_ALAW			= 0x41,	// G711¸ñÊ½ÒôÆµÊý¾Ý ALAW
    MEDIATYPE_G711_ULAW			= 0x43,	// G711¸ñÊ½ÒôÆµÊý¾Ý ULAW
}MediaType_t;

typedef enum
{
    CA_AUDIODEVICE_INNERMIC		= 0x01,	// ÄÚÖÃÂó¿Ë·ç
    CA_AUDIODEVICE_OUTERMIC		= 0x02,	// ÍâÖÃÂó¿Ë·ç
    CA_AUDIODEVICE_INNERSPK		= 0x11,	// ÄÚÖÃÀ®°È
    CA_AUDIODEVICE_OUTERSPK		= 0x12, // ÍâÖÃÀ®°È
}AudioDevice_e;

typedef enum
{
    CA_AUDIODEVICE_FMT_INNERMIC	= 0x0001,
    CA_AUDIODEVICE_FMT_OUTERMIC	= 0x0002,
    CA_AUDIODEVICE_FMT_INNERSPK	= 0x1000,
    CA_AUDIODEVICE_FMT_OUTERSPK	= 0x2000,
}AudioDeviceFMT_e;

typedef enum
{
    MEDIAOFFSET_NONE		= 0x00,	// ¿ÕÖµ,±íÊ¾Ã»ÓÐºóÐø¸½¼ÓÊý¾ÝÁË
    MEDIAOFFSET_TIME		= 0x01,	// ¸½¼ÓÊý¾ÝÎªÒôÊÓÆµÊý¾ÝÊ±¼ä
    MEDIAOFFSET_NAME		= 0x02,	// ¸½¼ÓÊý¾ÝÎªÉãÏñ»úÃû³Æ
    MEDIAOFFSET_TIMEFMT		= 0x03,	// ¸½¼ÓÊý¾ÝÎªÒôÊÓÆµÊý¾ÝÊ±¼äÏÔÊ¾¸ñÊ½
    MEDIAOFFSET_VIDEOCHG	= 0x04,	// ¸½¼ÓÊý¾ÝÎªÊÓÆµÊý¾Ý·­×ªÀàÐÍ
    MEDIAOFFSET_MOTIONINFO	= 0x05,	// ¸½¼ÓÊý¾ÝÎªÊÓÆµÊý¾ÝµÄMotionÐÅÏ¢
}OffsetType_e;

typedef enum
{
    CA_ALARMSTEP_NONE		= 0x00,		// ¿ÕÖµ
    CA_ALARMSTEP_WAITING	= 0x01,		// µÈ´ý´¦Àí
    CA_ALARMSTEP_DEALING	= 0x02,		// ÕýÔÚ´¦Àí
    CA_ALARMSTEP_FINISHED	= 0x03,		// ´¦ÀíÍê±Ï
}AlarmStep_e;

typedef struct
{
    INetConnection*  pMultiCon;
    INetConnection*  pUniCon;
}RawUdpCon_t;

typedef enum
{
    CS_NONE,
    CS_CON_ING,
    CS_CON_FAIL,
    CS_CON_OK
}ConStep_e;
typedef struct
{
    INetConnection* pCon;
    DWORD dwConTick;
    ConStep_e eStep;
}ConSvrInfo_t;

//setup packet header structure
typedef struct _tagNSPayloadHeader
{
    WORD wErrFlag;
    WORD wReserved0;
    DWORD dwCheckSum;
    BYTE cCheckSumType;
    BYTE cPayloadVer;
    WORD wPayloadLen;
}NSPAYLOADHEADER, *LPNSPAYLOADHEADER;
const int NSPAYLOAD_HEADER_SIZE = sizeof(NSPAYLOADHEADER);

typedef struct _tagNSPacketHeader
{
    BYTE bGroupCode;
    BYTE cSourceType;
    WORD wCommand;
    WORD wVersion;
    WORD wReserved1;
    DWORD dwSourceID;
    DWORD dwPeerID;
    DWORD dwUsrData;
    WORD wTotalSeg;
    WORD wSubSeg;
    WORD wSegFlag;
    WORD wReserved2;
    DWORD dwReserved3;// wVersion >= 2£¬ÕâÀï±íÊ¾UserID
} NSPACKETHEADER, *LPNSPACKETHEADER;
const int NSPACKET_HEADER_SIZE = sizeof(NSPACKETHEADER);
const int NS_HEADER_SIZE = NSPACKET_HEADER_SIZE + NSPAYLOAD_HEADER_SIZE;

typedef struct
{
    NSPACKETHEADER  tPacketHeader;
    NSPAYLOADHEADER tPayloadHeader;
    BYTE* pSegBuffer;
    DWORD dwSegBufLen;
}NSComFrgBuffer_t;

typedef enum
{
    CA_AUTHTYPE_DEFAULT		= 0x00,		// Ä¬ÈÏµÇÈëÀ´Ô´·½Ê½; Ä¬ÈÏÊÖ»ú¿Í»§¶ËÖ±Á¬µÇÈëÑéÖ¤
    CA_AUTHTYPE_SETUP		= 0x01,		// Setup¿Í»§¶ËÖ±Á¬µÇÈëÑéÖ¤
    CA_AUTHTYPE_CAMERA		= 0x02,		// ÉãÏñ»ú
}AuthType_e;

typedef enum
{
    CA_SESSIONTYPE_NONE				= 0x00000000,	// ¿ÕÖµ,ÎÞÒâÒå
    CA_SESSIONTYPE_COMMAND		    = 0x00000001,	// ÃüÁîÁ¬½Ó
    CA_SESSIONTYPE_VIDEO			= 0x00000002,	// ÊÓÆµÁ¬½Ó
    CA_SESSIONTYPE_AUDIO			= 0x00000004,	// ÒôÆµÁ¬½Ó
    CA_SESSIONTYPE_VIDEOUSER		= 0x00000008,	// ÊÓÆµÁ¬½Ó,¿Í»§¶Ë»Ø´«
    CA_SESSIONTYPE_TALK     		= 0x00000010,	// ÒôÆµÁ¬½Ó,¿Í»§¶Ë»Ø´«
}SessionType_e;
typedef std::map<INetConnection*, DWORD/*SessionType*/> Map_Connection;

typedef enum
{
    CA_CHANNELTYPE_DEFAULT		= 0x00000000,	// Ä¬ÈÏchannel;     ·ÇÕæÊµchannel; Ä¬ÈÏ ÊµÊ±Ä¬ÈÏchannel
    CA_CHANNELTYPE_RTDEFAULT	= 0x00000001,	// ÊµÊ±Ä¬ÈÏchannel; ·ÇÕæÊµÊµÊ±channel; ÓÉÉãÏñ»ú¾ö¶¨»òÓÃ»§ÉèÖÃ
    CA_CHANNELTYPE_PBDEFAULT	= 0x00000002,	// »Ø·ÅÄ¬ÈÏchannel; ·ÇÕæÊµ»Ø·Åchannel; ÓÉÉãÏñ»ú¾ö¶¨»òÓÃ»§ÉèÖÃ
    CA_CHANNELTYPE_RTALARMCT	= 0x00000003,	// Ô¤¶¨ÒåÊµÊ±±¨¾¯ÖÐÐÄchannel; ·ÇÕæÊµÊµÊ±channel; ÓÉÉãÏñ»ú¾ö¶¨»òÓÃ»§Éè¶¨
    CA_CHANNELTYPE_RTCHANNEL_PC	= 0x00000011,	// µÚÒ»Â·ÊµÊ±channel; ÕæÊµÊµÊ±channel PC¿Í»§¶Ë
    CA_CHANNELTYPE_RTCHANNEL_MOB= 0x00000012,	// µÚ¶þÂ·ÊµÊ±channel; ÕæÊµÊµÊ±channel ÊÖ»ú¿Í»§¶Ë
    CA_CHANNELTYPE_RTCHANNEL3	= 0x00000013,	// µÚÈýÂ·ÊµÊ±channel; ÕæÊµÊµÊ±channel
    CA_CHANNELTYPE_PBSDCARD		= 0x00000101,	// SD¿¨»Ø·Åchannel;   ÕæÊµ»Ø·Åchannel
    CA_CHANNELTYPE_PBNAS		= 0x00000102,	// NAS»Ø·Åchannel;    ÕæÊµ»Ø·Åchannel
}ChannelType_e;

typedef enum
{
    CA_PLAY_TRANSFLAG_NORMAL		= 0x00,	// ÆÕÍ¨´«Êä·½Ê½
    CA_PLAY_TRANSFLAG_DOWNLOAD		= 0x01,	// ÏÂÔØ´«Êä·½Ê½
}TransFlag_e;

typedef struct
{
    BYTE	szUserName[CA_LENGTH_USERNAME+1];	// ÓÃ»§Ãû,¼û×¢ÊÍËµÃ÷
    BYTE	cAuthType;							// µÇÈëÑéÖ¤À´Ô´ AuthType_e
    DWORD	dwSessionType;						// Á¬½ÓÍ¨µÀÀàÐÍ SessionType_e
    DWORD	dwSessionID;						// Á¬½ÓÍ¨µÀID,¼û×¢ÊÍËµÃ÷
    DWORD	dwDeviceID;							// Á¬½Ó¶ÔÓ¦ÉãÏñ»úID,¼û×¢ÊÍËµÃ÷
    DWORD	dwChannelType;						// Á¬½Ó¶ÔÓ¦µÄÒôÊÓÆµÊý¾ÝÀ´Ô´ÀàÐÍ ChannelType_e
}AuthParamCA_t;

typedef enum
{
    CA_REGISTERSTATE_NONE		= 0x0000,	// ÉãÏñ»úÉÐÎ´¿ªÊ¼×¢²áÐÐ¶¯
    CA_REGISTERSTATE_SUCCESS	= 0x0001,	// Ïò×¢²á·þÎñÆ÷×¢²á³É¹¦
    CA_REGISTERSTATE_NOSERVER	= 0x0002,	// ²»Ïò×¢²á·þÎñÆ÷×¢²á
                                                // CA_REGISTERTYPE_NONE
                                                // ×¢²áÀàÐÍÌØÓÐ×´Ì¬
    CA_REGISTERSTATE_NOTFOUND	= 0x0003,	// Î´·¢ÏÖ×¢²á·þÎñÆ÷
                                                // ËÑË÷ÀàÐÍÃ»ÓÐ·¢ÏÖ×¢²á·þÎñÆ÷
                                                // ÉèÖÃµØÖ·ÀàÐÍµØÖ·È«²¿Îª¿Õ
    CA_REGISTERSTATE_DNSFAIL	= 0x0004,	// ×¢²á·þÎñÆ÷µØÖ·½âÎöÊ§°Ü
                                                // CA_REGISTERTYPE_DIRECTAC
                                                // CA_REGISTERTYPE_PLATFORM
                                                // ×¢²áÀàÐÍ²ÅÓÐ×´Ì¬
    CA_REGISTERSTATE_TRYING		= 0x0005,	// ÕýÔÚÏò×¢²á·þÎñÆ÷×¢²á
    CA_REGISTERSTATE_CONNFAIL	= 0x0006,	// ×¢²á·þÎñÆ÷Á¬½ÓÊ§°Ü
    CA_REGISTERSTATE_DISCONN	= 0x0007,	// ×¢²á·þÎñÆ÷¶ÏÏß
    CA_REGISTERSTATE_NOTAUTH	= 0x0008,	// ×¢²á·þÎñÆ÷Î´ÊÚÈ¨×¢²á
    CA_REGISTERSTATE_FAIL		= 0x0009,	// ÆäËûÔ­Òòµ¼ÖÂµÄ×¢²áÊ§°Ü
}RegStatus_e;

typedef enum
{
    CA_REGISTER_GETFMT_NONE			= 0x0000,	// ¿ÕÖµ
    CA_REGISTER_GETFMT_ALL			= 0x8000,	// ²éÑ¯ËùÓÐÐÅÏ¢
    CA_REGISTER_GETFMT_SETINFO		= 0x0001,	// ²éÑ¯ÉèÖÃÐÅÏ¢
    CA_REGISTER_GETFMT_STATE		= 0x0002,	// ²éÑ¯×¢²á×´Ì¬ÐÅÏ¢
    CA_REGISTER_GETFMT_CURSERVER	= 0x0004,	// ²éÑ¯µ±Ç°Á¬½Ó×¢²á·þÎñÆ÷ÐÅÏ¢
}RegGetFmt_e;
const WORD W_GETFMT_ALL = CA_REGISTER_GETFMT_ALL | CA_REGISTER_GETFMT_SETINFO | CA_REGISTER_GETFMT_STATE | CA_REGISTER_GETFMT_CURSERVER;

typedef enum
{
    SOURCE_TYPE_NONE	= 0x00,	// Ä¬ÈÏ, Î´Ã÷È··¢ËÍ¶Ë
    SOURCE_TYPE_DEVICE	= 0x01,	// Ç°¶ËÉè±¸£¨Èç±¨¾¯Éè±¸¡¢±¨¾¯Áª¶¯Éè±¸¡¢IPCµÈ£©
    SOURCE_TYPE_SETUP	= 0x02,	// SetupÈí¼þ
    SOURCE_TYPE_ALCSVR	= 0x03,	// ±¨¾¯·þÎñÆ÷Èí¼þ
    SOURCE_TYPE_ANDRIOD = 0x04,	// °²×¿ÊÖ»ú¿Í»§¶Ë
    SOURCE_TYPE_IOS		= 0x05,	// Æ»¹ûÊÖ»ú¿Í»§¶Ë
    SOURCE_TYPE_V6PC    = 0x06,	// Ïû·ÑÀàµçÄÔ¿Í»§¶Ë
    SOURCE_TYPE_ANDROID_INDOOR	= 0x08,	// °²×¿Æ½°åÊÒÄÚ»ú
    SOURCE_TYPE_IOS_INDOOR		= 0x09,	// Æ»¹ûÆ½°åÊÒÄÚ»ú
}SourceType_e;

/////////////////////////////ÔÆÆ½Ì¨///////////////////////////////////////
//macros on network type
#define NT_HAS_PUBLIC_IP     0x0001
#define NT_UDP_REACHABLE     0x0002
#define HAS_PUBLIC_IP( type )    ( (type) & NT_HAS_PUBLIC_IP )
#define IS_UDP_REACHABLE( type ) ( (type) & NT_UDP_REACHABLE )
#define PUBLIC_IP_SET( type )       type |= NT_HAS_PUBLIC_IP
#define PUBLIC_IP_CLR( type )       type &= ~NT_HAS_PUBLIC_IP
#define UDP_REACHABLE_SET( type )   type |= NT_UDP_REACHABLE
#define UDP_REACHABLE_CLR( type )   type &= ~NT_UDP_REACHABLE

const int MAX_SEND_DEVICE_COUNT_1 = 336;

typedef struct
{
    DWORD		dwPublicIP;
    WORD		wPublicPortTCP;
    WORD		wPublicPortUDP;
    WORD		wLocalPortUDP;
    DWORD	    szLocalIP[2];
    WORD		wNetworkType;  // 1-¾ßÓÐ¹«ÍøµØÖ· 2-udpÍ¨
}NetInfo_t;

typedef struct
{
    BYTE		bSrcType;		// 0-¿Í»§¶Ë 1-×¢²á·þÎñÆ÷ 2-×´Ì¬·þÎñÆ÷ 3-×ª·¢·þÎñÆ÷
    DWORD		dwServerID;		// ×¢1 ServerID
    DWORD		dwUserID;		// ¿Í»§¶ËUserID
    DWORD		dwSessionID;	// ¿Í»§¶ËSessionID
    DWORD		dwDeviceID;		// ¹Û¿´Éè±¸DeviceID
    BYTE		bType;			// 0:ÊµÊ±
    NetInfo_t	tNetInfo;		// ¿Í»§¶ËNetInfo
    UINT		nTransmitSessionMode;
}TransClientInfo_t;

typedef struct
{
    DWORD		dwDeviceID;
    DWORD		dwDSvrCfgIndex;	// ×¢²á·þÎñÆ÷ÐÅÏ¢
    DWORD		dwUserCfgIndex;	// ÕËºÅÐÅÏ¢
    DWORD		dwPushCfgIndex;	// ÍÆËÍÐÅÏ¢
    DWORD		dwVendorID;
    CSTRING     strSerial;
    CSTRING     strDevName_DD;  // Éè±¸Æ½Ì¨Ãû³Æ
    DWORD		dwPublicIP;
    WORD		wPublicPort;
    BYTE cWorkMode;//ÓÃÀ´±êÊ¶µ±Ç°Éè±¸¹¤×÷ÔÚÃÅ½ûÆ½Ì¨»¹ÊÇÔÆ¶Ô½²Æ½Ì¨
    DWORD       dwGMT_Sec;      // ¸ñÁÖÍþÖÎÊ±¼ä
    CSTRING     strDeadLine;    // ´òµç»°µÄ½ØÖÁÈÕÆÚ
    CSTRING     strMajorAccount;//Ö÷ÕËºÅ
}DS_Register_Rep_t;

typedef struct
{
    DWORD dwUserData;            // ×îºóÒ»´ÎÍ¨Öª¿Í»§¶Ë¶Ô½²Õ¼ÏßµÄÓÃ»§±êÊ¶
    time_t tLastNotifyTime_Busy; // ×îºóÒ»´ÎÍ¨Öª¿Í»§¶Ë¶Ô½²Õ¼ÏßµÄÊ±¼ä
    time_t tLastNotifyTime_OK;   // ×îºóÒ»´ÎÍ¨Öª¿Í»§¶Ë¶Ô½²³É¹¦µÄÊ±¼ä
}APlayNotify_t;
//////////////////////////////////////////////////////////////////////////
#endif
