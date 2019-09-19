#ifndef NET_CON_DATA_STRUCT_H
#define NET_CON_DATA_STRUCT_H
#include "datatype.h"
#include "cfgdatastruct.h"

#define DD_PORT_LOGIN_SVR		5432		// µÇÂ½·þÎñÆ÷¶Ë¿Ú
#define DD_PORT_D_SVR	    	3478		// ×¢²á·þÎñÆ÷¶Ë¿Ú
#define DD_PORT_ALC 	    	9534		// ±¨¾¯·þÎñÆ÷¶Ë¿Ú

typedef enum
{
    CA_NETWORKTYPE_NONE			= 0x0000,	// ¿ÕÖµ
    CA_NETWORKTYPE_WIRED		= 0x0001,	// ÓÐÏß
    CA_NETWORKTYPE_WIFI			= 0x0002,	// WIFI
    CA_NETWORKTYPE_3G			= 0x0004	// 3G/4G/5G
}NetType_e;

typedef enum
{
    CA_NETWORKADDRTYPE_NONE			= 0x00,		// ¿ÕÖµ
    CA_NETWORKADDRTYPE_DHCPIP		= 0x01,		// DHCPµØÖ·
    CA_NETWORKADDRTYPE_STATICIP		= 0x02,		// ¾²Ì¬IP
    CA_NETWORKADDRTYPE_PPPOEIP		= 0x03,		// PPPOEµØÖ·
    CA_NETWORKADDRTYPE_DHCPDNS		= 0x10,		// DHCP DNS
    CA_NETWORKADDRTYPE_STATICDNS	= 0x20,		// ¹Ì¶¨DNS
}NetAddrType_e;

typedef struct
{
    DWORD dwRoomID;
    CSTRING strNum; // ·¿ºÅ
    CSTRING strPwd; // ¿ªÃÅÃÜÂë
    DWORD dwRoomAttr;//·¿¼äÊôÐÔ
    DWORD dwUserIndex;	// ÓÃ»§ÅäÖÃË÷Òý
    DWORD dwPushIndex;	// ÍÆËÍÅäÖÃË÷Òý
    DWORD dwCardIndex;	// ¿¨ºÅÅäÖÃË÷Òý
    DWORD dwIndoorIndex;// ÊÒÄÚ»úÅäÖÃË÷Òý
}DS_RoomIndex_Rep_t;
typedef std::list<DS_RoomIndex_Rep_t> LIST_ROOM_INDEX_REP;

typedef struct
{
    DWORD dwUserIndex;	// ÓÃ»§ÅäÖÃË÷Òý
    LIST_USER listUser;
}DS_RoomUser_Rep_t;
typedef std::map<DWORD, DS_RoomUser_Rep_t> MAP_ROOM_USER_REP;
typedef struct
{
    DWORD dwPushIndex;	// ÍÆËÍÅäÖÃË÷Òý
    LIST_PUSH listPush;
}DS_RoomPush_Rep_t;
typedef std::map<DWORD, DS_RoomPush_Rep_t> MAP_ROOM_PUSH_REP;
typedef struct
{
    DWORD dwCardIndex;	// ¿¨ºÅÅäÖÃË÷Òý
    LIST_CARD listCard;
}DS_RoomCard_Rep_t;
typedef std::map<DWORD, DS_RoomCard_Rep_t> MAP_ROOM_CARD_REP;//roomID¼°¶ÔÓ¦·¿¼äµÄ¿¨ºÅÐÅÏ¢
typedef struct
{
    DWORD dwIndoorIndex;
    LIST_INDOOR listIndoor;
}DS_RoomIndoor_Rep_t;
typedef std::map<DWORD, DS_RoomIndoor_Rep_t> MAP_ROOM_INDOOR_REP;//roomID£¬¶ÔÓ¦µÄÊÒÄÚ»úÐÅÏ¢

typedef struct
{
    DWORD dwRoomID;
    DS_RoomCard_Rep_t tCard;
}RoomCard_t;
typedef std::list<RoomCard_t> LIST_ROOM_CARD;

typedef struct
{
    DWORD dwAdID;
    DWORD dwAdType;
    DWORD dwTimeStamp;
    CSTRING strFormat;
    CSTRING strUrl;
    DWORD dwDelay;
} AdvertUrl_t;
typedef std::list<AdvertUrl_t> LIST_ADVERT_URL;

#endif

