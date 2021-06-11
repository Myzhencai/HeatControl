#ifndef NEWQTHREAD_H
#define NEWQTHREAD_H
#include<QThread>
#include<QMutex>
#include<QWaitCondition>
#include"fanmenuqgroupbox.h"


class MyNewQThread:public QThread
{

public:

    MyNewQThread(FanMenuQGroupBox * FanP,double runTime,int FanID,int Min,int Max,int Step):Fan(FanP),\
        RunTime(runTime),FanId(FanID),Minimum(Min),Maximum(Max),step(Step)
    {

    }
    ~MyNewQThread();
    void run();
private:
    int FanId;
    int Minimum;
    int Maximum;
    int step;
    double RunTime;
    FanMenuQGroupBox * Fan;
};



#endif

