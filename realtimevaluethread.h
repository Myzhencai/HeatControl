#ifndef REALTIMEVALUETHREAD_H
#define REALTIMEVALUETHREAD_H

#include<QThread>
#include <QObject>
#include"heatcontrolmenu.h"

class RealtimeValueThread:public QThread
{
//    Q_OBJECT
public:
    RealtimeValueThread();
    RealtimeValueThread(HeatControlMenu* TempMenu,bool Tempvalue):HeatControlMenuPointer(TempMenu),isTruable(Tempvalue){}

    ~RealtimeValueThread();
    void run();
    void stop();
public slots:
    void SendSingleCodeWithUart(QByteArray value);

private:
    HeatControlMenu* HeatControlMenuPointer ;
    bool isTruable;
    QString ATCode_Value = QString(" AT+GetSpeed=Fan?\r\n");
    QString ATCode_Value1 = QString(" AT+GetTemp=Ntc?\r\n");
    QString ATCode_Value2 = QString(" AT+GetDuty=Tec?\r\n");

};
#endif // REALTIMEVALUETHREAD_H
