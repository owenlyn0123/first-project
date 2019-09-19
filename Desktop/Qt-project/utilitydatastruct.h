#ifndef UTILITY_DATA_STRUCT_H
#define UTILITY_DATA_STRUCT_H
#include "datatype.h"

#define MIN_APP_PORT 10000
#define MAX_APP_PORT 15000

//Timer Interval
const DWORD INTERVAL_60 = 60;
const DWORD INTERVAL_20 = 20;
const DWORD INTERVAL_05 = 5;
const DWORD INTERVAL_02 = 2;
const DWORD INTERVAL_90 = 90;
const DWORD INTERVAL_3600 = 3600;
const DWORD INTERVAL_600 = 600;
const DWORD INTERVAL_10 = 10;

typedef enum
{
    TIMER_CHECKCON,
    TIMER_CHECKREG,
    TIMER_CHECKCON_SVR,
    TIMER_CHECKMUL,
    TIMER_CHECKMUL_8130,
    TIMER_CHECKREG_DSVR,
    TIMER_ADVERT_JPG,
    TIMER_WUYE_JPG_8130,
    TIMER_SYNC_STATUS_8130,
    TIMER_GETSERVERTIME, //»ñÈ¡·þÎñÆ÷Ê±¼ä¶¨Ê±Æ÷
    TIMER_CLOUDCALL,     //ÍÆËÍ¶¨Ê±Æ÷ÀàÐÍ  7
    TIMER_CHECK_CFG_UPDATE,
    TIMER_SEND_ROOM_SUM,
    TIMER_WATCH_DOG,
    TIMER_CALL_PHONE,
    TIMER_HANGUP,
    TIMER_UNLOCK_ITEM, // ¿ªÃÅ¼ÇÂ¼
    TIMER_HEARTBEAT,//ÍøÂçsdkÐÄÌø°ü
    TIMER_RECON_DSVR,//ÖØÐÂÁ¬½ÓDServer
    TIMER_Update,
}TimerReason_e;

typedef struct
{
    CSTRING strPath;
    CSTRING strKey;
    CSTRING strNameType;
}FileParam_t;
#endif

