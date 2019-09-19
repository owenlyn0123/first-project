#ifndef DEV_DATA_STRUCT_H
#define DEV_DATA_STRUCT_H
#include "datatype.h"
#include <QString>
#include <QHostAddress>




typedef enum
{
    Img_Firmware, // Éè±¸¹Ì¼þ
    Img_Wav_Btn1, // °´¼üÌáÊ¾Òô
    Img_Wav_Come, // À´ÈËÌáÊ¾Òô
}ImgType_e;

typedef enum
{
    AT_NONE  = 0,
    AT_Start = 1,
    AT_DI1   = 1,
    AT_DI2   = 2,
    AT_DI3   = 3,
    AT_BTNE  = 4,    // ½ô¼±ÇóÖú
    AT_BTNB  = 5,    // ÒµÎñ×ÉÑ¯
    AT_ONLINE  = 6,
    AT_OFFLINE = 7,
    AT_CALL    = 8,  // Éè±¸ºô½Ð
    AT_BODY    = 9,  // ÈËÌå¸ÐÓ¦
    AT_TUNNEL  = 10, // Í¸´«ÏûÏ¢
    AT_CALL_ANSWER = 11, // ºô½ÐÒÑ½ÓÌý
    AT_CALL_END    = 12, // ºô½ÐÒÑ½áÊø
    AT_DOOR_UNLOCK = 13, // ÃÅ³¤Ê±¼äÎ´Ëø ±¨¾¯
    AT_DOOR_LOCK   = 14, // ÃÅÒÑ¾­ËøÉÏ   ±¨¾¯È¡Ïû
    AT_End   = AT_DOOR_LOCK
}AlarmType_e;

//const static char g_szAlarmTag[AT_End+1][20] = {
//    "Î´ÖªÀàÐÍ",
//    "¿ª¹ØÁ¿1",
//    "¿ª¹ØÁ¿2",
//    "¿ª¹ØÁ¿3",
//    "½ô¼±ÇóÖú",
//    "ÒµÎñ×ÉÑ¯",
//    "Éè±¸ÉÏÏß",
//    "Éè±¸ÀëÏß",
//    "Éè±¸ºô½Ð",
//    "ÈËÌå¸ÐÓ¦",
//    "Í¸´«ÏûÏ¢",
//    "ºô½ÐÒÑ½ÓÌý",
//    "ºô½ÐÒÑ½áÊø",
//    "ÃÅ³¤Ê±¼äÎ´Ëø",
//    "ÃÅÒÑËøÉÏ"
//};

const static char g_szAlarmTag_Base64[AT_End+1][50] = {
    "5pyq55+l57G75Z6L", //"zrTWqsDg0M0=",//"Î´ÖªÀàÐÍ",
    "5byA5YWz6YePMQ==", //"v6q52MG/MQ==",//"¿ª¹ØÁ¿1",
    "5byA5YWz6YePMg==", //"v6q52MG/Mg==",//"¿ª¹ØÁ¿2",
    "5byA5YWz6YePMw==", //"v6q52MG/Mw==",//"¿ª¹ØÁ¿3",
    "57Sn5oCl5rGC5Yqp", //"vfS8scfz1vo=",//"½ô¼±ÇóÖú",
    "5Lia5Yqh5ZKo6K+i", //"0rXO8dfJ0a8=",//"ÒµÎñ×ÉÑ¯",
    "6K6+5aSH5LiK57q/", //"yeixuMnPz98=",//"Éè±¸ÉÏÏß",
    "6K6+5aSH56a757q/", //"yeixuMDrz98=",//"Éè±¸ÀëÏß",
    "6K6+5aSH5ZG85Y+r", //"yeixuLr0vdA=",//"Éè±¸ºô½Ð",
    "5Lq65L2T5oSf5bqU", //"yMvM5bjQ06Y=" //"ÈËÌå¸ÐÓ¦",
    "6YCP5Lyg5raI5oGv", //"Í¸´«ÏûÏ¢"
    "5bey5o6l5ZCs",     //"5ZG85Y+r5bey5o6l5ZCs", // ºô½ÐÒÑ½ÓÌý
    "5ZG85Y+r5bey57uT5p2f",       // ºô½ÐÒÑ½áÊø
    "6Zeo6ZW/5pe26Ze05pyq6ZSB",   // ÃÅ³¤Ê±¼äÎ´Ëø
    "6Zeo5bey6ZSB5LiK"            // ÃÅÒÑËøÉÏ
};

typedef struct
{
    AlarmType_e eType;
    DWORD  dwRoomID;
    DWORD  dwUserID;
    PUCHAR pRoomNum;
    PUCHAR pPhoneNum;
    PUCHAR pMsg;
}CallParam_t;

typedef struct
{
    DWORD dwAddr;
    WORD  wPort;
    DWORD dwCon;
    DWORD dwID;
    DWORD dwImageSize;
    ImgType_e eType;
}UpdateImageParam_t;

typedef struct
{
    DWORD dwAddr;
    WORD  wPort;
    DWORD dwCon;
    DWORD dwID;
    DWORD dwSequence;
    WORD  wLen;
    PUCHAR pData;
}ImageFragment_t;

typedef struct ImageDataNode
{
    PUCHAR pBuf;
    WORD   wLen;
    WORD   wReadIndex;
    ImageDataNode *pNext;
}ImageDataNode_t;

typedef struct
{
    PUCHAR pData;
    bool bDI1_Valid;  // true: DI1ÉÏ±¨ÁË×´Ì¬£¬bDI1_Change²ÎÊýÓÐÐ§
    bool bDI1_Change; // true: DI1²»µÈÓÚÄ¬ÈÏ×´Ì¬
    bool bDI2_Valid;
    bool bDI2_Change;
}DIOccur_8136_t;

typedef struct
{
    PUCHAR pData;
    BYTE cDI1; // 0: Î´´¥·¢£»1£º´¥·¢
    bool bDO1;
    bool bDO2;
    bool bWav;
    AlarmType_e eType;
}DIOccur_t;

typedef enum
{
    UIS_INIT,
    UIS_STEP1,  //get update image request
    UIS_STEP2,  //wait for get image header
    UIS_STEP3,  //wait for get image data
    UIS_STEP4,  //begin write to flash
    UIS_STEP5   //write flash finish
}UpdateImageStatus_e;

typedef struct
{
    DWORD dwAddr;
    WORD  wPort;
    DWORD dwCon;
    CSTRING strVersion;
    CSTRING strUrl;
}RemoteUpdateInfo_t;

typedef struct
{
    DWORD  dwMagic;		// IMAGE_HEADER_MAGIC_8126
    DWORD  dwChecksum;
    DWORD  dwImageLen;  //¾µÏñÎÄ¼þµÄ Êµ¼Ê´óÐ¡
    char   szImageVer[8];
}ImageHeader_DD;
const DWORD MIN_LEN_IMAGE_HEADER = sizeof(ImageHeader_DD);

#endif
