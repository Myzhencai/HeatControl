#include "realtimevaluefromuart.h"
#include<qdebug.h>
#include<QEventLoop>
#include<QTimer>
#include<QDebug>

RealtimeValueFromUart::RealtimeValueFromUart()
{

}
RealtimeValueFromUart::~RealtimeValueFromUart()
{

}

void RealtimeValueFromUart::run()
{
    while(isTruable){
        if(DefaultMode == true && SingleCoceMode == false &&SendAllMode == false )
        {
            if(DefaultModeinRunning== false){
                DefaultModeinRunning = true;
                emit DefaultModeRealTimeValue();
            }

        }
        else if(DefaultMode == false && SingleCoceMode == true &&SendAllMode == false)
        {
            if(SingleCoceModeinRunning== false){
                SingleCoceModeinRunning = true;
                emit SingleCoceModeRealTimeValue();//发送单条指令运行模式
            }
        }
        else if(DefaultMode == false && SingleCoceMode == false &&SendAllMode == true)
        {
            if(SendAllModeinRunning == false){
                SendAllModeinRunning = true;
                emit PageCodeModeRealTimeValue();//发送界面配置指令发送模式
            }

        }

//        QEventLoop loop;
//        QTimer::singleShot(200, &loop, SLOT(quit()));
//        loop.exec();


        }

}

//模式运行退出
void RealtimeValueFromUart::SingleCoceModeisRunningFalse()
{
//    qDebug()<<"1";
    SingleCoceModeinRunning = false;
}

void RealtimeValueFromUart::SendAllModeinRunningFalse()
{
//    qDebug()<<"2";
    SendAllModeinRunning = false;
}

void RealtimeValueFromUart::SendDefualtModeinRunningFalse()
{
//    qDebug()<<"3";
    DefaultModeinRunning = false;
}

//退出Uart模式
void RealtimeValueFromUart::stop()
{
    isTruable = false;
}

//void RealtimeValueFromUart::StopCurrentEveryThread()
//{
//    isTruable = false;
//}

//进入模式
void RealtimeValueFromUart::SetSingleCoceMode()
{
    DefaultMode = false;
    SingleCoceMode = true;
    SendAllMode = false;
} 

void RealtimeValueFromUart::SetPageCodeMode()
{
    DefaultMode = false;
    SingleCoceMode = false;
    SendAllMode = true;
}

//退出模式
void RealtimeValueFromUart::LiveSingleCoceMode()
{
    DefaultMode = true;
    SingleCoceMode = false;
    SendAllMode = false;
}

void RealtimeValueFromUart::LivePageCodeMode()
{
    DefaultMode = true;
    SingleCoceMode = false;
    SendAllMode = false;
}


