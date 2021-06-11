#ifndef REALTIMEVALUEFROMUART_H
#define REALTIMEVALUEFROMUART_H

#include <QObject>
#include <QThread>
#include <QByteArray>
#include"heatcontrolmenu.h"

class RealtimeValueFromUart:public QThread
{
        Q_OBJECT
public:
    RealtimeValueFromUart();
    RealtimeValueFromUart(HeatControlMenu* TempMenu,bool Tempvalue):HeatControlMenuPointer(TempMenu),isTruable(Tempvalue){}
    void run();

    ~RealtimeValueFromUart();
public slots:
    void SetSingleCoceMode();//设置不同的模式
    void SetPageCodeMode();
    void stop();
    void LiveSingleCoceMode();//离开设置模式
    void LivePageCodeMode();

    void SingleCoceModeisRunningFalse();
    void SendAllModeinRunningFalse();
    void SendDefualtModeinRunningFalse();

signals:
    void SingleCoceModeRealTimeValue();//不同运作方式以信号形式传递
    void DefaultModeRealTimeValue();
    void PageCodeModeRealTimeValue();

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

#endif // REALTIMEVALUEFROMUART_H
