#ifndef SYSLOG_H
#define SYSLOG_H
#include "vigolog.h"
#include "utilityinterface.h"

#define LEN_MSLOGITEM 255

extern bool g_bPrintLog;
static inline void WriteMediaLog(unsigned char nLevel, const char* szFormat, va_list var_arg)
{
        if(!g_bPrintLog) return;

        char buff[LEN_MSLOGITEM+1];
        vsnprintf(buff, LEN_MSLOGITEM, szFormat, var_arg);
        int nIndex = strlen(buff);
        if(nIndex >= LEN_MSLOGITEM) buff[LEN_MSLOGITEM-1] = '\n';
        buff[nIndex] = '\0';
        ShowDebug(buff);
}

inline void LOGEMERG(const char *szFormat, ...)
{
        va_list var_arg;
        va_start(var_arg,szFormat);
        WriteMediaLog(VIGO_LOG_LEVEL_EMERG, szFormat, var_arg);
        va_end (var_arg);
}
inline void LOGALERT(const char *szFormat, ...)
{
        va_list var_arg;
        va_start(var_arg,szFormat);
        WriteMediaLog(VIGO_LOG_LEVEL_ALERT, szFormat, var_arg);
        va_end (var_arg);
}
inline void LOGCRIT(const char *szFormat, ...)
{
        va_list var_arg;
        va_start(var_arg,szFormat);
        WriteMediaLog(VIGO_LOG_LEVEL_CRIT, szFormat, var_arg);
        va_end (var_arg);
}
inline void LOGERR(const char *szFormat, ...)
{
        va_list var_arg;
        va_start(var_arg,szFormat);
        WriteMediaLog(VIGO_LOG_LEVEL_ERR, szFormat, var_arg);
        va_end (var_arg);
}
inline void LOGWARN(const char *szFormat, ...)
{
        va_list var_arg;
        va_start(var_arg,szFormat);
        WriteMediaLog(VIGO_LOG_LEVEL_WARNING, szFormat, var_arg);
        va_end (var_arg);
}
inline void LOGNOTICE(const char *szFormat, ...)
{
        va_list var_arg;
        va_start(var_arg,szFormat);
        WriteMediaLog(VIGO_LOG_LEVEL_NOTICE, szFormat, var_arg);
        va_end (var_arg);
}
inline void LOGINFO(const char *szFormat, ...)
{
        va_list var_arg;
        va_start(var_arg,szFormat);
        WriteMediaLog(VIGO_LOG_LEVEL_INFO, szFormat, var_arg);
        va_end (var_arg);
}
inline void LOGDEBUG(const char *szFormat, ...)
{
        va_list var_arg;
        va_start(var_arg,szFormat);
        WriteMediaLog(VIGO_LOG_LEVEL_DEBUG, szFormat, var_arg);
        va_end (var_arg);
}
inline void LOGDETAIL(const char *szFormat, ...)
{
        va_list var_arg;
        va_start(var_arg,szFormat);
        WriteMediaLog(VIGO_LOG_LEVEL_DETAIL, szFormat, var_arg);
        va_end (var_arg);
}

#define LOG_ASSERT_RET(expr, rv) \
do { \
        if (!(expr)) { \
                ShowDebug("Assert failed: file=%s line=%d expr=%s\n",__FILE__,__LINE__,#expr); \
                return rv;\
        } \
}while(0); \

#define LOG_ASSERT_RETVOID(expr) \
do { \
        if (!(expr)) { \
                ShowDebug("Assert failed: file=%s line=%d expr=%s\n",__FILE__,__LINE__,#expr); \
                return; \
        } \
}while(0); \

#define LOG_ASSERT(expr) \
do { \
        if (!(expr)) { \
                ShowDebug("Assert failed: file=%s line=%d expr=%s\n",__FILE__,__LINE__,#expr); \
        } \
}while(0); \


#endif





