#include "newselftestpage.h"
#include<QEventLoop>
#include<QTimer>
#include<QDebug>

newSelfTestpage::~newSelfTestpage()
{

}

void newSelfTestpage::run()
{

    for(int i = 0;i<100;i++)
    {
        if(SelfTestArray[i][0]!=0){

            for(int i1 = 0;i1<20;i1++){
                if(FanCreat[i1]!=NULL)
                {
                    FanCreat[i1]->setValueComp(SelfTestArray[i][i1+1]);
                }
            }

            for(int i2 = 0;i2<1;i2++){
                if(PumpCreat[i2]!=NULL)
                {
                    PumpCreat[i2]->setValueComp(SelfTestArray[i][i2+21]);
                }
            }

            for(int i3 = 0;i3<6;i3++){
                if(TECCreat[i3]!=NULL)
                {
                    TECCreat[i3]->setValueComp(SelfTestArray[i][i3+22]);
                }
            }

            for(int i4 = 0;i4<4;i4++){
                if(ElecCreat[i4]!=NULL)
                {
                    ElecCreat[i4]->setValueComp(SelfTestArray[i][i4+28]);
                }
            }

            QEventLoop loop;
            QTimer::singleShot(SelfTestArray[i][0]*60*1000, &loop, SLOT(quit()));
            loop.exec();
        }

    }


}
