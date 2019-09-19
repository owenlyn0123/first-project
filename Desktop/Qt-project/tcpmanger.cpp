#include "tcpmanger.h"


IMPLEMENT_SINGLETON(CTcpManger)

LIST_DeviceInfo g_devicelist;
QString IpAddress;
uint16_t Port;

BYTE CTcpManger::m_szBuffer[MAX_PACKET_SIZE+1];

CTcpManger::CTcpManger(QObject *parent) :
    QObject (parent)
{


     m_pSocket = new QTcpSocket();
     m_pServer = new QTcpServer();






     if(!m_pServer->listen(QHostAddress::Any, 8061))
     {
         qDebug() <<m_pServer->errorString();
     }
     else
     {
         qDebug() << "Server started!";
     }

    //     whenever a user connects, it will emit signal
        connect(m_pServer, SIGNAL(newConnection()),
                this, SLOT(on_newConnection()));
        connect(this, SIGNAL(get_device_list()), this, SLOT(senddevicelist()));

}

void CTcpManger::on_newConnection()
{
    // need to grab the socket
    m_pSocket = m_pServer->nextPendingConnection();
    qint32 Ip_client = m_pSocket->peerAddress().toIPv4Address();        //获取接收方ip与端口
    uint16_t Ip_port = m_pSocket->peerPort();
    IpAddress = IpDword2Str(Ip_client);
    Port = Ip_port ;

    qDebug() << IpAddress;
    qDebug() << Port;



    connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(unpack()));


//    m_pSocket->write("Hello client\r\n");
//    m_pSocket->flush();

//    m_pSocket->waitForBytesWritten(3000);

//    m_pSocket->close();
}

//void CTcpManger::displayError(QAbstractSocket::SocketError socketError)
//{
//    qDebug() << "error: " << socketError <<"\n";
//}



void CTcpManger::FillHeader(CPutBuffer& buffer, WORD wCmdID, WORD wErr, WORD wTotalSeg, WORD wSubSeg)
{
    int nHeadLen = NS_HEADER_SIZE;
    int nPayloadLen = buffer.GetFilledSize() - nHeadLen;

    buffer.SetOffset( 0 );
    // Header 1
    buffer << m_cGroupCode << wCmdID<< (BYTE)2  << (WORD)0 << (WORD)1
           << m_tPacketHeader.dwSourceID << (DWORD)0<< m_tPacketHeader.dwUsrData
           << wTotalSeg << wSubSeg << m_tPacketHeader.wSegFlag
           << m_tPacketHeader.wReserved2 << m_tPacketHeader.dwReserved3;
    // Header 2
//    buffer << wErr << (WORD)0 << CHECKSUMTYPE_NONE << (DWORD)0
//           << PAYLOADVERSION_NONE << (WORD)0;
    buffer.SetOffset( nPayloadLen + nHeadLen );
}



void CTcpManger::unpack()
{
    QByteArray datagram;
    datagram = m_pSocket->readAll();
    int m_Len = datagram.size();

    CGetBuffer bufferGet(datagram.data(), m_Len);

    bufferGet >> m_tPacketHeader.bGroupCode;

    bufferGet >> m_tPacketHeader.wCommand  >> m_tPacketHeader.cSourceType
             >> m_tPacketHeader.wVersion   >> m_tPacketHeader.wReserved1
             >> m_tPacketHeader.dwSourceID >> m_tPacketHeader.dwPeerID
             >> m_tPacketHeader.dwUsrData  >> m_tPacketHeader.wTotalSeg
             >> m_tPacketHeader.wSubSeg    >> m_tPacketHeader.wSegFlag
             >> m_tPacketHeader.wReserved2 >> m_tPacketHeader.dwReserved3;

//    bufferGet >> m_tPayloadHeader.wErrFlag        >> m_tPayloadHeader.wReserved0
//             >> m_tPayloadHeader.cCheckSumType   >> m_tPayloadHeader.dwCheckSum
//             >> m_tPayloadHeader.cPayloadVer     >> m_tPayloadHeader.wPayloadLen;


    switch(m_tPacketHeader.wCommand)
      {

       case 1:

            {

                emit get_device_list();

        break;
            }





    }
}


void CTcpManger::GetDeviceList(LIST_DeviceInfo& devicelist)
{




        deviceinfo_t lst ;
         lst.devicename = "2ds321";
         lst.netip="12.122.213.1";
         lst.password="2213213";
         lst.username= "wkqemqw";

         g_devicelist.push_back(lst);

         deviceinfo_t lst1 ;
          lst1.devicename = "2ds321";
          lst1.netip="12.122.213.1";
          lst1.password="2213213";
          lst1.username= "wkqemqw";

          g_devicelist.push_back(lst1);

          deviceinfo_t lst2 ;
           lst2.devicename = "2ds321";
           lst2.netip="12.122.213.1";
           lst2.password="2213213";
           lst2.username= "wkqemqw";

           g_devicelist.push_back(lst2);

}



void CTcpManger::senddevicelist()
{

//    GetDeviceList(LIST_DeviceInfo& devicelist);

    m_cGroupCode = 0xAD;
    WORD wCmdID = 0x0002;
    WORD wErr = 0x0000;
    WORD wTotalSeg = ceil((double)g_devicelist.size()/19);


    DECLARE_PUTBUFFER( bufferPut )

    for(int i = 1; i <= wTotalSeg; i++)
    {
        if (wTotalSeg >1) m_tPacketHeader.wSegFlag = 111;
        WORD wSubSeg = i;
        qDebug() << "am i still here?" << "\n";

        char put_devicename[32] = {0};
        char put_username[16] = {0};
        char put_password[16] = {0};


        for( int cout = 1; cout <= 19; cout++)
        {

            if(g_devicelist.size() == 0)
            {
                break; //当list中无元素时，跳出循环
             }
            else {

                LIST_DeviceInfo::iterator iter = g_devicelist.begin();



              advance(iter, g_devicelist.size()-1); //取list最后一个

              memcpy(put_devicename, (*iter).devicename.toLocal8Bit().data(),32);
              memcpy(put_username, (*iter).username.toLocal8Bit().data(), 16);
              memcpy(put_password, (*iter).password.toLocal8Bit().data(), 16);

              bufferPut.Put(put_devicename, 32);
              bufferPut << htonl(inet_addr((*iter).netip.toString().toLocal8Bit().data()))
                        << (WORD)(*iter).port;
              bufferPut.Put(put_username, 16);
              bufferPut.Put(put_password,16);
              g_devicelist.erase(iter++);
              std::cout<<g_devicelist.size() << "\n";
            }
        }

        FillHeader(bufferPut, wCmdID, wErr, wTotalSeg, wSubSeg);

//        m_pSocket->abort();

//        m_pSocket->connectToHost(IpAddress, Port);
//        //等待连接成功
//        if(!m_pSocket->waitForConnected(30000)){
//            qDebug()<<"Connection failed!";
//            return;
//        }
//        qDebug()<<"Connection success!";
        m_pSocket->write(bufferPut,  bufferPut.GetFilledSize());
        m_pSocket->waitForBytesWritten();
        m_pSocket->flush();
        qDebug() << "writed!"<<"\n";

//        m_pSocket->disconnectFromHost();
    }
    }

void CTcpManger::SendAttendance(const Attendance_t& attInfo)
{
    m_cGroupCode = 0xAD;
    WORD wCmdID = 0x0003;
    WORD wErr = 0x0000;
    WORD wTotalSeg = 1;
    WORD wSubSeg = 1;

    DECLARE_PUTBUFFER( bufferPut )

    char put_uuID[64] = {0};
    char put_studentname[16] = {0};
    char put_grade[2] = {0};
    char put_department[2] = {0};
    char put_studentID[2] = {0};
    char put_imagename[64] = {0};

    memcpy(put_uuID, attInfo.uuID.toLocal8Bit().data(), 64);
    memcpy(put_studentname, attInfo.studentID.toLocal8Bit().data(), 16);
    memcpy(put_grade, attInfo.grade.toLocal8Bit().data(), 2);
    memcpy(put_department, attInfo.department.toLocal8Bit().data(),2);
    memcpy(put_studentID,attInfo.studentID.toLocal8Bit().data(),2);
    memcpy(put_imagename,attInfo.imagename.toLocal8Bit().data(),64);

    bufferPut.Put(put_uuID, 64);
    bufferPut.Put(put_studentname,16);
    bufferPut.Put(put_grade,2);
    bufferPut.Put(put_department,2);
    bufferPut.Put(put_studentID,2);
    bufferPut.Put(put_imagename,64);

    bufferPut << attInfo.attendancecount << attInfo.status;
    FillHeader(bufferPut, wCmdID, wErr, wTotalSeg, wSubSeg);


//    m_pSocket->abort();

//    m_pSocket->connectToHost(IpAddress, Port);
//    //等待连接成功
//    if(!m_pSocket->waitForConnected(30000)){
//        qDebug()<<"Connection failed!";
//        return;
//    }
//    qDebug()<<"Connection success!";

    m_pSocket->write(bufferPut,bufferPut.GetFilledSize());
    m_pSocket->waitForBytesWritten();
    m_pSocket->flush();
//    m_pSocket->disconnectFromHost();

}





