#include "mynewqthreadforself.h"
#include <QQueue>
#include<QEventLoop>
#include<QTimer>
#include<QList>
#include<QVector>
using namespace std;

MyNewQThreadForSelf::~MyNewQThreadForSelf()
{

}
void MyNewQThreadForSelf::run()
{
    //向量数据处理
    QQueue<int> Tempque;
    for(int i ;i<101;i++)
    {
        if(SelfTestVector[i]>0){
            Tempque.enqueue(SelfTestVector[i]);
        }
    }

    int Round = Tempque.dequeue();
    int Temp = Tempque.size();
    double RunStep = RunTime/(Temp*Round);
    QVector<int> Templist = Tempque.toVector();

    for(int i = 0;i<Round;i++){
        for(int j =0;j<Temp;j++)
        {
            double Temp1 = double(Templist.at(j));
            Fan->setValueComp(Temp1);

            //每一秒显示一个变化值

            QEventLoop loop;
            QTimer::singleShot(RunStep, &loop, SLOT(quit()));
            loop.exec();
        }
    }

    return;
}

