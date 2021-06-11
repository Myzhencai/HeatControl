#ifndef NEWSELFTESTPAGE_H
#define NEWSELFTESTPAGE_H
#include<QThread>
#include<QMutex>
#include<QWaitCondition>
#include"fanmenuqgroupbox.h"
using namespace std;


class newSelfTestpage:public QThread
{

public:

    newSelfTestpage(std::vector<std::vector<int>>  elfTestArray,
                    std::vector<FanMenuQGroupBox *> FanCreat,std::vector<FanMenuQGroupBox *> PumpCreat,
                    std::vector<FanMenuQGroupBox *> TECCreat,std::vector<FanMenuQGroupBox *> ElecCreat):SelfTestArray(elfTestArray),\
        FanCreat(FanCreat),PumpCreat(PumpCreat),TECCreat(TECCreat),ElecCreat(ElecCreat)
    {

    }
    ~newSelfTestpage();
    void run();
private:
    std::vector<std::vector<int>> SelfTestArray{100,std::vector<int>(32)};
    std::vector<FanMenuQGroupBox *> FanCreat{std::vector<FanMenuQGroupBox *>(20)};
    std::vector<FanMenuQGroupBox *> PumpCreat{std::vector<FanMenuQGroupBox *>(16)};
    std::vector<FanMenuQGroupBox *> TECCreat{std::vector<FanMenuQGroupBox *>(16)};
    std::vector<FanMenuQGroupBox *> ElecCreat{std::vector<FanMenuQGroupBox *>(16)};

};

#endif // NEWSELFTESTPAGE_H





