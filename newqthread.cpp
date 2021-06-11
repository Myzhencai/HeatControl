#include "newqthread.h"
#include<QEventLoop>
#include<QTimer>
#include<QDebug>



MyNewQThread::~MyNewQThread()
{

}

void MyNewQThread::run()
{
    int Temp = (Maximum-Minimum)/step;
    for(int i=0;i<Temp;i++)
    {
        double Temp1 = double(Minimum+step*i);
        double RunStep = RunTime/Temp;
        Fan->setValueComp(Temp1);
        //每一秒显示一个变化值
        QEventLoop loop;
        QTimer::singleShot(RunStep, &loop, SLOT(quit()));
        loop.exec();
    }
    Fan->setValueComp(Maximum);
}


