#ifndef UTILITY_INTERFACE_H
#define UTILITY_INTERFACE_H

#include "utilitydatastruct.h"
#include "devdatastruct.h"

bool Init_Utility();
void Fini_Utility();

interface INvrTimerSink
{
    virtual ~INvrTimerSink() {}
    virtual void OnTimer(TimerReason_e eReason, INvrTimerSink* pSink) VIRTUAL;
};
//Interval Unit: second
void AddTimer(TimerReason_e eReason, DWORD dwInterval, INvrTimerSink* pSink);
void DelTimer(TimerReason_e eReason, INvrTimerSink* pSink);

void   imemcpy(void *dest, const void *src, int len);
int    GetFileSize(const char *path);
DWORD  GetDeviceID(char* pSerialNum);
// ²éÑ¯ÐÍºÅID,³É¹¦·µ»ØID,Ê§°Ü·µ»Ø0
DWORD  GetDeviceTID(char* pSerialNum);

DWORD  GetRandDeviceID();
DWORD  GetRandDeviceID_UUID();
DWORD  GetRandPort();
DWORD  GetUUID_Seed();
PUCHAR GetChallenge(PUCHAR pOut);
PUCHAR GenerateInvalidSN();

BYTE   Trans1_100to0_80(BYTE cInVal);   //1~100 => 0~80
BYTE   Trans1_100to0_6(BYTE cInVal);    //1~100 => 0~6

char   Trans127_127to0_100(char cInVal); //-127~127 => 0~100
char   Trans0_100to127_127(char cInVal); //0~100 => -127~127

BYTE   Trans0_255to0_100(BYTE cInVal);   //0~255 => 0~100
BYTE   Trans0_100to0_255(BYTE cInVal);   //0~100 => 0~255

BYTE   Trans0_79to0_100(BYTE cInVal);   //0~79 => 0~100
BYTE   Trans0_100to0_79(BYTE cInVal);   //0~100 => 0~79

int    Base64EncVal(char * base64code, const char * src, int src_len);
int    Base64DecVal(char * buf, const char * base64code, int src_len);
int    USDK_DESEncode(PUCHAR pKey, PUCHAR pInput, int nInLen, PUCHAR pOut);
int    USDK_DESDecode(PUCHAR pKey, PUCHAR pInput, int nInLen, PUCHAR pOut);

DWORD  crc32Compute(PUCHAR pHeader, int nHeaderlen, ImageDataNode_t *pLinux);
PUCHAR CalMd5Val(PUCHAR pInStr, int nLen);
int    HexStr2CharStr(PUCHAR pOutCharStr, PUCHAR pInHexStr,  int nInLen);
int    CharStr2HexStr(PUCHAR pOutHexStr,  PUCHAR pInCharStr, int nInLen);
bool   CheckValidIPV4(PUCHAR pIP);

int    UnicodeToUTF8(char *inbuf, size_t inlen, char *outbuf, size_t outlen);
int    UTF8ToUnicode(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

// 2014-11-01 23:55:55
time_t MsGetCurTimeString_V2(long lSec, char* pLocalTime, int nLen);
// 20141101235555
time_t MsGetCurTimeString_V3(long lSec, char* pLocalTime, int nLen);
// 1611121905 ±íÊ¾Ê±¼äÎª£º2016 Äê£¨16+2000£©11 ÔÂ 12 ÈÕ 19 Ê± 05 ·Ö
time_t MsGetCurTimeString_V4(long lSec, char* pLocalTime, int nLen);

void ShowDebug(const char *szFormat, ...);

int  USDK_SyncReadTimeOut(int nSocket, int bShort);
BYTE USDK_CalcVChannel(DWORD dwMode);
long USDK_TimeDiff(timeval& t1, timeval& t2); // ·µ»ØÁ½¸öÈë²ÎºÁÃë¼¶±ðµÄ²îÖµ

void USDK_ReadCardNum_92755();
void USDK_WriteCardNum_92755();

// Õë¶Ôad_*.jpg unlock_*.wavÀàÐÍµÄÎÄ¼þ
int  USDK_InitFileList(MapInt2CStr& mapFiles, FileParam_t& tParam);
//½âÎöÊÒÄÚ»útokenÖÐµÄÊÒÄÚ»úID
int  IndoorToken_To_ID(const char* pToken, ListDword& lstID);
int pox_system(const char *cmd_line);
void SetThreadStackSize(pthread_attr_t& attr);
void log_printf (int level,const char *fmt, ...);

#endif
