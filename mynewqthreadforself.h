#ifndef MYNEWQTHREADFORSELF_H
#define MYNEWQTHREADFORSELF_H
#include<QThread>
#include<QMutex>
#include<QWaitCondition>
#include"fanmenuqgroupbox.h"

class MyNewQThreadForSelf:public QThread
{
public:

    MyNewQThreadForSelf(FanMenuQGroupBox * FanP,double runTime,int FanID,std::vector<int> Vectors):Fan(FanP),\
        RunTime(runTime),FanId(FanID),SelfTestVector(Vectors)
    {

    }
    ~MyNewQThreadForSelf();

    void run();
private:
    int FanId;
    std::vector<int> SelfTestVector{std::vector<int>(101)};
    double RunTime;
    FanMenuQGroupBox * Fan;
};

#endif // MYNEWQTHREADFORSELF_H
