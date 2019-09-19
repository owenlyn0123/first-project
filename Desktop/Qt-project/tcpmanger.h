#ifndef TCPMANGER_H
#define TCPMANGER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QNetworkDatagram>
#include <QDebug>
#include <QObject>
#include <QAbstractSocket>
#include <QString>
#include <QByteArray>


#include <iostream>
#include <math.h>

#include "singlenton.h"
#include "netcondef.h"
#include "putbuffer.h"
#include "getbuffer.h"
#include "utilityinterface.h"
#include "cfginterface.h"


typedef struct
{
    QString devicename;
    QHostAddress netip;
    qint16 port;
    QString username;
    QString password;
}deviceinfo_t;


struct Attendance_t
{
    QString uuID;
    QString studentname;
    QString grade;
    QString department;
    QString studentID;
    QString imagename;
    WORD attendancecount;
    BYTE status;

};

typedef std::list<deviceinfo_t> LIST_DeviceInfo;


const int  MAX_PACKET_SIZE = 1400;


class CTcpManger : public QObject
{
    DECLARE_SINGLETON(CTcpManger)
    Q_OBJECT
public:
   CTcpManger(QObject *parent = 0);

    void FillHeader(CPutBuffer& buffer, WORD wCmdID, WORD wErr, WORD wTotalSeg, WORD wSubSeg);

    char* IpDword2Str(unsigned long dwIP)
    {
     in_addr addr;
     addr.s_addr = htonl(dwIP);
     return inet_ntoa(addr);
    }


    void SendAttendance(const Attendance_t& attInfo);
    void GetDeviceList(LIST_DeviceInfo& devicelist);



signals:
    void get_device_list();

public slots:
   void on_newConnection();
   void unpack();
   void senddevicelist();






private:
    QTcpServer *m_pServer;
    QTcpSocket *m_pSocket;

protected:

    BYTE m_cGroupCode;
    static BYTE m_szBuffer[MAX_PACKET_SIZE+1];
    NSPACKETHEADER  m_tPacketHeader;
    NSPAYLOADHEADER m_tPayloadHeader;
};

#define DECLARE_PUTBUFFER( bufferPut ) \
    CPutBuffer bufferPut( CTcpManger::m_szBuffer, MAX_PACKET_SIZE ); \
    bufferPut.Skip( NS_HEADER_SIZE ); \



#endif // TCPMANGER_H
