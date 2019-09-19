#include <QCoreApplication>
#include "tcpmanger.h"
#include <QApplication>


//LIST_DeviceInfo g_devicelist;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);


    CTcpManger *go ;
    go = CTcpManger::Instance();

//    go->senddevicelist();


     return a.exec();
}
