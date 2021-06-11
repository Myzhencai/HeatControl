#include "realtimevaluefortcp.h"
#include<qdebug.h>
#include<QEventLoop>
#include<QTimer>
#include<QDebug>

RealtimeValueForTCP::RealtimeValueForTCP()
{

}

RealtimeValueForTCP::~RealtimeValueForTCP()
{

}

void RealtimeValueForTCP::run()
{

    while(isTruable){
        if(DefaultMode == true && SingleCoceMode == false &&SendAllMode == false )
        {
            if(DefaultModeinRunning== false){
                DefaultModeinRunning = true;
                emit TCPDefaultModeRealTimeValue();
            }

        }
        else if(DefaultMode == false && SingleCoceMode == true &&SendAllMode == false)
        {
            if(SingleCoceModeinRunning== false){
                SingleCoceModeinRunning = true;
                emit TCPSingleCoceModeRealTimeValue();
            }
        }
        else if(DefaultMode == false && SingleCoceMode == false &&SendAllMode == true)
        {
            if(SendAllModeinRunning == false){
                SendAllModeinRunning = true;
                emit TCPPageCodeModeRealTimeValue();
            }
        }
        }
}

//模式运行退出
void RealtimeValueForTCP::TCPSingleCoceModeisRunningFalse()
{
//    qDebug()<<"1";
    SingleCoceModeinRunning = false;
}

void RealtimeValueForTCP::TCPSendAllModeinRunningFalse()
{
//    qDebug()<<"2";
    SendAllModeinRunning = false;
}

void RealtimeValueForTCP::TCPSendDefualtModeinRunningFalse()
{
//    qDebug()<<"3";
    DefaultModeinRunning = false;
}

//退出Uart模式
void RealtimeValueForTCP::stop()
{
    isTruable = false;
}

//进入模式
void RealtimeValueForTCP::TCPSetSingleCoceMode()
{
    DefaultMode = false;
    SingleCoceMode = true;
    SendAllMode = false;
}

void RealtimeValueForTCP::TCPSetPageCodeMode()
{
    DefaultMode = false;
    SingleCoceMode = false;
    SendAllMode = true;
}

//退出模式
void RealtimeValueForTCP::TCPLiveSingleCoceMode()
{
    DefaultMode = true;
    SingleCoceMode = false;
    SendAllMode = false;
}

void RealtimeValueForTCP::TCPLivePageCodeMode()
{
    DefaultMode = true;
    SingleCoceMode = false;
    SendAllMode = false;
}


