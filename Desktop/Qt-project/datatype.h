#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <stdio.h>
#include <algorithm>
#include <ctype.h>
#include <fcntl.h>
#include <map>

#include <errno.h>

#include <set>
#include <list>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <dirent.h>

#include <linux/sockios.h>
#include <linux/types.h>

//#ifdef _WIN32
//#define WIN32_LEAN_AND_MEAN 1
//#include <winsock2.h>
//#include <windows.h>

//#else
#include <netdb.h>
#include <poll.h>
#include <termios.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/socket.h>
//#endif

#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

// ³§ÉÌÀàÐÍ
#ifdef		  _VID_DD121_
#define VID_DD121
#elif defined _VID_AURINE_
#define VID_AURINE
#elif defined _VID_MILI_
#define VID_MILI
#elif defined _VID_FUJU_
#define VID_FUJU
#elif defined _VID_LEELEN_
#define VID_LEELEN
#endif

// ±àÒëÀàÐÍ
#ifdef	_ALSA_CAP_
#define ALSA_CAP // Í¨¹ýAlsaµÄ·½Ê½×¥È¡ÒôÆµ
#endif

// Ð¾Æ¬ÀàÐÍ
#ifdef	_SDK_USE_NET_
#define SDK_USE_NET
#endif
#ifdef _SDK_USE_UART_
#define SDK_USE_UART     // Í¨¹ý±ê×¼UARTÐ­Òé½øÐÐ¶Ô½ÓµÄÉè±¸£¬ÈçXTM8130¡¢Ä£Äâ»ú
#endif

#ifdef  _CHIP_AK3918_
#define CHIP_AK3918
#endif
#ifdef _CHIP_GM8126_
#define CHIP_GM8126
#endif
#ifdef _CHIP_GM8136_
#define CHIP_GM8136
#endif
#ifdef _CHIP_ANDRIOD_
#define CHIP_ANDRIOD
#endif
#ifdef _CHIP_ADR_DD_V1_
#define CHIP_ADR_DD_V1    // ´¿°²×¿µÄ13´ç°²×¿Éè±¸SDK
#endif
#ifdef _CHIP_ANDRIOD_V2_  // 8126/8136 + °²×¿ÃÅ¿Ú»ú
#define CHIP_ADR_DD_V2
#endif
#ifdef _CHIP_ADR_DD_V3_
#define CHIP_ADR_DD_V3    // °²×¿ÊÒÄÚ»ú
#endif
#ifdef _CHIP_CX92755_SEMT_ // Î°´´´ïµÄ92755
#define CHIP_CX92755_SEMT
#endif
#ifdef _CHIP_CX92755_      // µÚÈý·½µÄ92755
#define CHIP_CX92755
#endif
#ifdef _CHIP_HI3515_
#define CHIP_HI3515
#endif
#ifdef _CHIP_RT5350_
#define CHIP_RT5350
#endif
#ifdef _CHIP_N32926_
#define CHIP_N32926
#endif
#ifdef _CHIP_A10_
#define CHIP_A10
#endif
#ifdef _CHIP_AK3918E_
#define CHIP_AK3918E
#endif
#ifdef _CHIP_RV1108_
#define CHIP_RV1108
#endif
#ifdef _CHIP_QZX1_
#define CHIP_QZX1
#endif


#if defined(CHIP_ANDRIOD) || defined(CHIP_ADR_DD_V1) || defined(CHIP_ADR_DD_V3)
  #include <android/log.h>
  #define LOG_DEV_TAG	 "CloudSdk"
  #define printf(...)	 __android_log_print(ANDROID_LOG_VERBOSE, LOG_DEV_TAG, __VA_ARGS__)
#endif //ANDROID

#ifdef _ENABLE_OSD_
#define MACRO_ENA_OSD
#endif

#if defined(CHIP_GM8126)
  #include <mtd/mtd-user.h>
  #include "gm8126/ioctl_gpio.h"
#elif defined(CHIP_GM8136)
  #include <mtd/mtd-user.h>
  #include "gm8136/gmlib.h"
  #include "gm8136/sar_adc_api.h"
  #include "gm8136/ioctl_gpio.h"
#endif
#ifdef CHIP_RT5350
  #include <bits/types.h>
#endif

#if defined(CHIP_ANDRIOD) || defined(CHIP_ADR_DD_V1) || defined(CHIP_ADR_DD_V3)
  #include "NetworkInterface_android.h"
#else
  #include <linux/watchdog.h>
  #ifndef CHIP_A10
    #include <sys/soundcard.h>
  #endif
  #include "networkinterface.h"
#endif

#ifndef interface
#define interface               struct
#endif

#ifndef VIRTUAL
#define VIRTUAL =0
#endif

#ifndef BYTE
typedef unsigned char  BYTE;
#endif

#ifndef __u8
typedef unsigned char  __u8;
#endif

#ifndef u_int8_t
typedef unsigned char  u_int8_t;
#endif

#ifndef WORD
typedef unsigned short WORD;
#endif



#ifndef DWORD
typedef unsigned int  DWORD;


#endif


#ifndef T_S32
typedef signed long T_S32;
#endif

#ifndef UINT
typedef unsigned int   UINT;
#endif

#ifndef LONG
typedef long LONG;
#endif

#ifndef PUCHAR
typedef unsigned char* PUCHAR;
#endif

#ifndef PBYTE
typedef unsigned char* PBYTE;
#endif

#ifndef PPUCHAR
typedef unsigned char** PPUCHAR;
#endif


#ifndef INT64
typedef unsigned long long INT64;
#endif




#ifndef LPCTSTR
typedef const char*    my_LPCTSTR;
#endif

#ifndef CSTRING
typedef std::string    CSTRING;
#endif

typedef std::list<DWORD>   ListDword;
typedef std::set<DWORD>    SET_DWORD;
typedef std::list<CSTRING> ListCString;
typedef std::map<int, CSTRING>  MapInt2CStr;

#define BIT(x) (1<<x)

#define LOCAL_HOST "127.0.0.1"

#define ROOM_NUM_V1  "0000"
#define DEF_ROOM_PWD "123456"
#define DEF_ROOM_ATTR 1

#define WORK_MODE_WUYE      0 //ÎïÒµÆ½Ì¨
#define WORK_MODE_MENJIN    1 //ÃÅ½ûÆ½Ì¨

#define MAX_STACK_SIZE 20*1024 //Ïß³Ì¶ÑÕ»´óÐ¡Îª1M

#define DB_LEN_ROOM_NUM   			12
#define DB_LEN_ROOM_PWD_MD5			16
#define DB_LEN_CARDNUMBER			32
#define DB_LEN_PHONENUMBER			32
#define DB_LEN_UNLOCK_PWD			12
#define DB_LENGTH_MACADDR			 6
#define DB_LENGTH_CURTIME			14

//Daemond Command
#define DMCMD_START_DHCP 0x81
#define DMCMD_STOP_DHCP  0x82
#define DMCMD_UPDATE_APP 0x83

// ÄÚ²¿¶Ë¿Ú¶¨Òå
#define DAEMOND_PORT_PEER						58873
#define RECORD_PORT_PEER						58874
#define RECORD_PORT_LOCAL						56772
#define UPNPCTL_PORT_PEER						60000
#define UPNPCTL_PORT_LOCAL						56771

#define SYNC_PORT_RECV_NOTIFY_VIDEO		56781
#define SYNC_PORT_SEND_NOTIFY_VIDEO		56782
#define SYNC_PORT_RECV_NOTIFY_AUDIO		56783
#define SYNC_PORT_SEND_NOTIFY_AUDIO		56784
#define SYNC_PORT_RECV_NOTIFY_ETH		56785
#define SYNC_PORT_SEND_NOTIFY_ETH		56786
#define SYNC_PORT_RECV_NOTIFY_DEV		56787
#define SYNC_PORT_MAIN_THREAD_UART		56788
#define SYNC_PORT_SUB_THREAD_UART		56789
#define SYNC_PORT_SEND_NOTIFY_VPATH     56794
#define SYNC_PORT_RECV_NOTIFY_VPATH     56795

#define SDK_PORT_CMD_DD				45611
#define SDK_PORT_VIDEO_DD			45612
#define SDK_PORT_AUDIO_DD			45613
#define SDK_PORT_CMD_PEER			45601
#define SDK_PORT_VIDEO_PEER			45602
#define SDK_PORT_AUDIO_PEER			45603

#define SDK_ADDR_MULTICAST			"236.6.8.3"	// Ë«°å×Ó×é²¥¼ÓÈëµØÖ·
#define SDK_PORT_MULTICAST			9525		// Ë«°å×Ó×é²¥¼ÓÈë¶Ë¿Ú(UDP)
#define SDK_PORT_UNICAST_MY			9526		// ßËßË°²×¿»úºËÐÄ°åÕìÌý¶Ë¿Ú

#if defined(CHIP_ADR_DD_V2) || defined(CHIP_ADR_DD_V1)
 #define SDK_PORT_UNICAST_PEER   	9526		// °²×¿Æß´ç»ú°²×¿°åµ¥²¥¶Ë¿Ú
#elif defined(CHIP_ADR_DD_V3)
 #define SDK_PORT_UNICAST_PEER   	9530		// °²×¿ÊÒÄÚ»úµ¥²¥¶Ë¿Ú
#endif

#define VOIPTYPE					  1 // VOIPµç»°ÀàÐÍ,ÔÆÖ®Ñ¶
#define DEF_PHOTO_MODE				103 // Ä¬ÈÏµÄ·Ã¿ÍÁôÓ°ÀàÐÍ,1100111£¬bit0:ºô½ÐÊ§°Ü(³¬Ê±,Î´½ÓÌý) bit1:App½ÓÌý bit2:µç»°½ÓÌý bit3:APP¿ªËø bit4:µç»°¿ªËø bit5:Ë¢¿¨¿ªËø bit6:ÃÜÂë¿ªËø

/* error levels */
#define LOG_NORMAL	1
#define LOG_ERROR	2
typedef enum
{
    None,
    Ucpaas,//ÔÆÖ®Ñ¶
    Yuntx, //ÈÝÁªÔÆ
}VoipType_e;

typedef enum
{
    IM_8130_Outdoor, // 8136ºËÐÄ°å+8130ÃÅ¿Ú»ú ÔËÐÐÄ£Ê½
    IM_8130_Indoor   // 8136ºËÐÄ°å+8130ÊÒÄÚ»ú ÔËÐÐÄ£Ê½
}IndoorMode_e;

typedef struct
{
    PUCHAR pFrame;
    int    nFrameLen;
    BYTE   cPseq;
    WORD   wIseq;
    BYTE   cChanNum;
    BYTE   cMediaType;  //1: audio; 2: h264 video; 3: mjpeg video
    int    nIsKeyFrame;
    timeval tTime;
}MediaFrame_t;

typedef struct
{
    DWORD dwUnlockIndex;
    DWORD dwUnlockType;
    DWORD dwDeviceID;
    DWORD dwRoomID;
    DWORD dwUserID;
    BYTE  szNumber[DB_LEN_PHONENUMBER];
    DWORD dwTimeStamp;
    BYTE  szRoomNum[DB_LEN_ROOM_NUM];
}UnlockRecord_t;
typedef std::list<UnlockRecord_t> LIST_RECORDITEM;

//3.3.2	×Ö¶Î³¤¶È¶¨Òå
const DWORD LEN_CHALLENGESTRING			= 16;
const DWORD CA_LENGTH_MD516				= LEN_CHALLENGESTRING;
const DWORD CA_LENGTH_USERNAME 			= 32;	// ÓÃ»§Ãû³¤¶È
const DWORD CA_LENGTH_PASSWORD			= 32;	// ÃÜÂë³¤¶È
const DWORD CA_LENGTH_SERIALNUMBER		= 32;	// ÐòÁÐºÅ³¤¶È,µ±Ç°ÓÐÐ§³¤¶ÈÎª20
const DWORD CA_LENGTH_CAMERANAME		= 64;	// ÉãÏñ»úÃû³Æ³¤¶È
const DWORD CA_LENGTH_MACADDRRESS		= 12;	// MACµØÖ·³¤¶È,µ±Ç°ÓÐÐ§³¤¶ÈÎª6
const DWORD CA_LENGTH_IMAGEVERSION		= 64;	// Image°æ±¾ÐÅÏ¢³¤¶È
const DWORD CA_LENGTH_SERVERADDR		= 64;	// ·þÎñÆ÷µØÖ·³¤¶È
const DWORD CA_LENGTH_WIFISSID			= CA_LENGTH_USERNAME;
const DWORD CA_LENGTH_WIFIKEY			= 17;
const DWORD CA_LENGTH_WIFIPWD			= CA_LENGTH_PASSWORD; // [8,32]

// ÔÆÆ½Ì¨
const DWORD D5_LENGTH_SERIALNO			= 20;
const DWORD D5_LENGTH_PASSWORD			= 16;
const DWORD D5_LENGTH_IMAGEVERSION		= 20;
const DWORD D5_LENGTH_POSITION			= 128;
const DWORD D5_LENGTH_MOBILEPHONE	    = 32;
const DWORD D5_LENGTH_TOKEN				= 64; // 128
const DWORD D5_LENGTH_CARD_NUM			= 32;
const DWORD D5_LENGTH_PLATFORM_KEY		= 17;
const DWORD	LENGTH_TIMESTAMP2			= 14;
const DWORD D5_LENGTH_DEADLINE			= 8;  //´òµç»°½ØÖ¹ÈÕÆÚµÄ³¤¶È£¨20160707£©
const DWORD	D5_LENGTH_FORMAT			= 10; //ÎÄ¼þ¸ñÊ½
const DWORD D5_LENGTH_URL			    = 256;

#define WAV_KEY_UNLOCK					"unlock_"
#define WAV_NAME_UNLOCK					"unlock_*.wav"
#define ADVERT_JPG_KEY					"ad_"
#define ADVERT_JPG_NAME					"ad_*.jpg"
#define PATH_JPG_FILE					"/gm/dong/ad/jpg/"

#ifdef CHIP_GM8136
    #define PATH_WAV_FILE   			"/gm/dong/ad/wav/"
    #define PATH_WAV_CALL_ING			"/gm/dong/ad/wav/call_ing.wav"
    #define PATH_WAV_CALL_WAIT			"/gm/dong/ad/wav/call_wait.wav"
    #define PATH_WAV_CALL_NOBODY		"/gm/dong/ad/wav/call_nobody.wav"
    #define PATH_WAV_CALL_TALK			"/gm/dong/ad/wav/call_talk.wav"
    #define PATH_WAV_CALL_FINI			"/gm/dong/ad/wav/call_fini.wav"
    #define PATH_WAV_CALL_FAIL			"/gm/dong/ad/wav/call_fail.wav"
    #define PATH_WAV_UNLOCK_OK			"/gm/dong/ad/wav/unlock_ok.wav"
    #define PATH_WAV_CALL_ING_U			"/mnt/mtd/call_ing_u.wav"
    #define PATH_WAV_CALL_WAIT_U		"/mnt/mtd/call_wait_u.wav"
#else
    #define PATH_WAV_FILE   			"/usr/wav/"
    #define PATH_WAV_CALL_ING			"/usr/wav/call_ing.wav"
    #define PATH_WAV_CALL_WAIT			"/usr/wav/call_wait.wav"
    #define PATH_WAV_CALL_NOBODY		"/usr/wav/call_nobody.wav"
    #define PATH_WAV_CALL_TALK			"/usr/wav/call_talk.wav"
    #define PATH_WAV_CALL_FINI			"/usr/wav/call_fini.wav"
    #define PATH_WAV_CALL_FAIL			"/usr/wav/call_fail.wav"
    #define PATH_WAV_UNLOCK_OK			"/usr/wav/unlock_ok.wav"
    #define PATH_WAV_CALL_ING_U			"/mnt/mtd/call_ing_u.wav"
    #define PATH_WAV_CALL_WAIT_U		"/mnt/mtd/call_wait_u.wav"
#endif

typedef enum
{
    Wav_Unknown,
    Wav_OnBtn,
    Wav_OnCome,
    Wav_Call_Ing,    // ¡°ÕýÔÚºô½Ð×¡»§¡±
    Wav_Call_Wait,   // ¡°à½¡±
    Wav_Call_NoBody, // ¡°¶Ô·½ÎÞÈË½ÓÌý¡±5
    Wav_Call_Talk,   // ¡°ÇëÍ¨»°¡±
    Wav_Call_Fini,   // ¡°Í¨»°½áÊø¡±
    Wav_Call_Fail,   // ¡°ºô½ÐÊ§°Ü¡±
    Wav_UnLock_OK,   // ¡°¿ªËø³É¹¦¡±
    Wav_UnLock_OK_AD,// ´ø¹ã¸æÓïµÄ ¡°¿ªËø³É¹¦¡±
}WavType_e;
typedef struct
{
    WavType_e eWavType;
    int nRemainLoopTimes;
}WavPlayTask_t;
typedef std::list<WavPlayTask_t> List_WavPlayTask;

typedef enum
{
    Wpa_Unknown,
    Wpa_Insert, // ²åÈë²¥·Å
    Wpa_Append, // Ë³Ðò²¥·Å£¨ÏÂÒ»¸ö£©
    Wpa_Replace // ¸²¸Ç²¥·Å
}WavPlayAttr_e;

typedef enum
{
    BL_Unknown,
    BL_Work,
    BL_Abnormal,
    BL_Calling,
    BL_Process
}BtnLed_e;

// Vender ID
#define VID_DD          (1 << 4) // ßËßË¼¼Êõ (ov9712)
#define VID_RUIDAO      (2 << 4) // Èðµ¼¿Æ¼¼ (ar0130)
#define VID_JINGMING    (3 << 4) // ½õÃúÊÓÑ¶ (ar0130)
#define VID_XIONGMAI    (4 << 4) // ÐÛÂõ
#define VID_CDS         (5 << 4) // ½Ý¸ß8136 (H42 BG0703 OV9712)

// Sensor Modle ID
#define MODEL_9712		0
#define MODEL_0130		1
#define MODEL_9900		2
#define MODEL_9P031		3
#define MODEL_7725		4
#define MODEL_HD		5
#define MODEL_0331		6
#define MODEL_1375      7
#define MODEL_H42       8
#define MODEL_BG0703    9
#define MODEL_SC1145    10

enum PacketFrgType_e
{
    FrgType_Err,
    FrgType_Single,
    FrgType_Multing,
    FrgType_Multed
};
typedef enum
{
    DB_MediaMode_VIDEO = 0x00000001,	//ÊÓÆµÊý¾Ý
    DB_MediaMode_AUDIO = 0x00000002,	//ÒôÆµÊäÈë
    DB_MediaMode_TALK  = 0x00000004,	//ÒôÆµ²¥·Å
}MediaMode_e;
#define DB_MediaMode_AUDIO_WAV	  0x00000008	//²¥·ÅÒôÆµÎÄ¼þ£¬ÁÙÊ±½èÓÃÒôÆµÉè±¸

typedef enum
{
    CR_None,
    CR_Success,
    CR_NoPushList,
    CR_RegFailed,
    CR_OnlyPhone,
    CR_NoMsgContent,
}CallRet_e;

#endif

