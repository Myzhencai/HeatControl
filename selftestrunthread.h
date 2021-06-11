#ifndef SELFTESTRUNTHREAD_H
#define SELFTESTRUNTHREAD_H
#include<QThread>
#include<QMutex>
#include<QWaitCondition>
#include"fanmenuqgroupbox.h"
#include "heatcontrolmenu.h"

class SelfTestrunThread:public QThread
{
public:

    SelfTestrunThread(HeatControlMenu * menu,double value):Controlmenu(menu),times(value)
    {

    }
    ~SelfTestrunThread();

    void run();



private:

    HeatControlMenu * Controlmenu;
    double times;


};

#endif // MYNEWQTHREADFORSELF_H
