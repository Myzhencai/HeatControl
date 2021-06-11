#ifndef REALTIMEVALUEFORTCP_H
#define REALTIMEVALUEFORTCP_H

#include <QObject>
#include <QThread>
#include <QByteArray>
#include"heatcontrolmenu.h"

class RealtimeValueForTCP:public QThread
{
    Q_OBJECT
public:
    RealtimeValueForTCP();
    RealtimeValueForTCP(HeatControlMenu* TempMenu,bool Tempvalue):HeatControlMenuPointer(TempMenu),isTruable(Tempvalue){}
    void run();

    ~RealtimeValueForTCP();
public slots:
    void TCPSetSingleCoceMode();//设置不同的模式
    void TCPSetPageCodeMode();
    void stop();
    void TCPLiveSingleCoceMode();//离开设置模式
    void TCPLivePageCodeMode();

    void TCPSingleCoceModeisRunningFalse();
    void TCPSendAllModeinRunningFalse();
    void TCPSendDefualtModeinRunningFalse();

signals:
    void TCPSingleCoceModeRealTimeValue();//不同运作方式以信号形式传递
    void TCPDefaultModeRealTimeValue();
    void TCPPageCodeModeRealTimeValue();

private:
    bool DefaultMode = true;
    bool SingleCoceMode = false;
    bool SendAllMode = false;
    bool isTruable;//用于判定是否创建进程

    bool SingleCoceModeinRunning = false;
    bool SendAllModeinRunning =false;
    bool DefaultModeinRunning= false;

    HeatControlMenu* HeatControlMenuPointer;
};

#endif // REALTIMEVALUEFORTCP_H
