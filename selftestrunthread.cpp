#include "selftestrunthread.h"
#include <QEventLoop>

SelfTestrunThread::~SelfTestrunThread()
{

}

void SelfTestrunThread::run()
{
    for(int i = 0 ;i<ceil(times/500);i++)
    {
        if(Controlmenu->UartPort->serial.isOpen())
        {
            Controlmenu->UartPort->on_btn_led1_Ctrl_2_clicked();
        }
        if(Controlmenu->NetWorkClient->tcpClient->isOpen())
        {
            Controlmenu->NetWorkClient->on_actSendAll_triggered();
        }
        QEventLoop loop;
        QTimer::singleShot(500, &loop, SLOT(quit()));
        loop.exec();
    }
}
