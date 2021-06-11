#ifndef SAVEDATATHREAD_H
#define SAVEDATATHREAD_H
#include "heatcontrolmenu.h"
#include <vector>
#include<QThread>
#include<QJsonArray>
#include<QJsonObject>
#include <QObject>
#include <QThread>
#include <QByteArray>

class savedatathread:public QThread
{
    Q_OBJECT
public:
    savedatathread(HeatControlMenu* TempControlMenu):ControlMenu(TempControlMenu){
        for(int i = 0;i<10;i++)
        {
            //转数数据列表
             versionArray.push_back(0);
             versionArray1.push_back(0);
             versionArray2.push_back(0);
             versionArray3.push_back(0);
             versionArray4.push_back(0);
             versionArray5.push_back(0);
             versionArray6.push_back(0);
             versionArray7.push_back(0);
             versionArray8.push_back(0);
             versionArray9.push_back(0);
             versionArray10.push_back(0);
             versionArray11.push_back(0);
             versionArray12.push_back(0);
             versionArray13.push_back(0);
             versionArray14.push_back(0);
             versionArray15.push_back(0);
             versionArray16.push_back(0);
             versionArray17.push_back(0);
             versionArray18.push_back(0);
             versionArray19.push_back(0);

             //风扇最大电压
             versionArra.push_back(0);
             versionArra1.push_back(0);
             versionArra2.push_back(0);
             versionArra3.push_back(0);
             versionArra4.push_back(0);
             versionArra5.push_back(0);
             versionArra6.push_back(0);
             versionArra7.push_back(0);
             versionArra8.push_back(0);
             versionArra9.push_back(0);
             versionArra10.push_back(0);
             versionArra11.push_back(0);
             versionArra12.push_back(0);
             versionArra13.push_back(0);
             versionArra14.push_back(0);
             versionArra15.push_back(0);
             versionArra16.push_back(0);
             versionArra17.push_back(0);
             versionArra18.push_back(0);
             versionArra19.push_back(0);

             //风扇设置（电压/占空比）
             versionArr.push_back(0);
             versionArr1.push_back(0);
             versionArr2.push_back(0);
             versionArr3.push_back(0);
             versionArr4.push_back(0);
             versionArr5.push_back(0);
             versionArr6.push_back(0);
             versionArr7.push_back(0);
             versionArr8.push_back(0);
             versionArr9.push_back(0);
             versionArr10.push_back(0);
             versionArr11.push_back(0);
             versionArr12.push_back(0);
             versionArr13.push_back(0);
             versionArr14.push_back(0);
             versionArr15.push_back(0);
             versionArr16.push_back(0);
             versionArr17.push_back(0);
             versionArr18.push_back(0);
             versionArr19.push_back(0);

             PumpArray.push_back(0);

             TECArray.push_back(0);
             TECArray1.push_back(0);
             TECArray2.push_back(0);
             TECArray3.push_back(0);
             TECArray4.push_back(0);
             TECArray5.push_back(0);

             TECArra.push_back(0);
             TECArra1.push_back(0);
             TECArra2.push_back(0);
             TECArra3.push_back(0);
             TECArra4.push_back(0);
             TECArra5.push_back(0);

             TECArr.push_back(0);
             TECArr1.push_back(0);
             TECArr2.push_back(0);
             TECArr3.push_back(0);
             TECArr4.push_back(0);
             TECArr5.push_back(0);

             ElecArray.push_back(0);
             ElecArray1.push_back(0);
             ElecArray2.push_back(0);
             ElecArray3.push_back(0);

        }
    }
    ~savedatathread();
    void run();
signals:
    void renewData();
    void isSavedatame();
public slots:
    void setStop();
    void handlesave();
    void setStart();
    void receivenewData(std::vector<std::vector<int>>,std::vector<std::vector<int>>,std::vector<std::vector<int>>
                        ,std::vector<std::vector<int>>,std::vector<std::vector<int>>,std::vector<std::vector<int>>);
    void savedata();



private:
    bool setrunning = true;
    bool issave = false;


    //风扇转数
    QJsonArray versionArray;
    QJsonArray versionArray1;
    QJsonArray versionArray2;
    QJsonArray versionArray3;
    QJsonArray versionArray4;
    QJsonArray versionArray5;
    QJsonArray versionArray6;
    QJsonArray versionArray7;
    QJsonArray versionArray8;
    QJsonArray versionArray9;
    QJsonArray versionArray10;
    QJsonArray versionArray11;
    QJsonArray versionArray12;
    QJsonArray versionArray13;
    QJsonArray versionArray14;
    QJsonArray versionArray15;
    QJsonArray versionArray16;
    QJsonArray versionArray17;
    QJsonArray versionArray18;
    QJsonArray versionArray19;

    //风扇最大电压
    QJsonArray versionArra;
    QJsonArray versionArra1;
    QJsonArray versionArra2;
    QJsonArray versionArra3;
    QJsonArray versionArra4;
    QJsonArray versionArra5;
    QJsonArray versionArra6;
    QJsonArray versionArra7;
    QJsonArray versionArra8;
    QJsonArray versionArra9;
    QJsonArray versionArra10;
    QJsonArray versionArra11;
    QJsonArray versionArra12;
    QJsonArray versionArra13;
    QJsonArray versionArra14;
    QJsonArray versionArra15;
    QJsonArray versionArra16;
    QJsonArray versionArra17;
    QJsonArray versionArra18;
    QJsonArray versionArra19;
    //风扇设置（电压/占空比）
    QJsonArray versionArr;
    QJsonArray versionArr1;
    QJsonArray versionArr2;
    QJsonArray versionArr3;
    QJsonArray versionArr4;
    QJsonArray versionArr5;
    QJsonArray versionArr6;
    QJsonArray versionArr7;
    QJsonArray versionArr8;
    QJsonArray versionArr9;
    QJsonArray versionArr10;
    QJsonArray versionArr11;
    QJsonArray versionArr12;
    QJsonArray versionArr13;
    QJsonArray versionArr14;
    QJsonArray versionArr15;
    QJsonArray versionArr16;
    QJsonArray versionArr17;
    QJsonArray versionArr18;
    QJsonArray versionArr19;


    QJsonArray PumpArray;

    QJsonArray TECArray;
    QJsonArray TECArray1;
    QJsonArray TECArray2;
    QJsonArray TECArray3;
    QJsonArray TECArray4;
    QJsonArray TECArray5;

    QJsonArray TECArra;
    QJsonArray TECArra1;
    QJsonArray TECArra2;
    QJsonArray TECArra3;
    QJsonArray TECArra4;
    QJsonArray TECArra5;

    QJsonArray TECArr;
    QJsonArray TECArr1;
    QJsonArray TECArr2;
    QJsonArray TECArr3;
    QJsonArray TECArr4;
    QJsonArray TECArr5;

    QJsonArray ElecArray;
    QJsonArray ElecArray1;
    QJsonArray ElecArray2;
    QJsonArray ElecArray3;

    QJsonObject FanJsonPart;
    QJsonObject FanJsonPart1;
    QJsonObject FanJsonPart2;
    QJsonObject FanJsonPart3;
    QJsonObject FanJsonPart4;
    QJsonObject FanJsonPart5;
    QJsonObject FanJsonPart6;
    QJsonObject FanJsonPart7;
    QJsonObject FanJsonPart8;
    QJsonObject FanJsonPart9;
    QJsonObject FanJsonPart10;
    QJsonObject FanJsonPart11;
    QJsonObject FanJsonPart12;
    QJsonObject FanJsonPart13;
    QJsonObject FanJsonPart14;
    QJsonObject FanJsonPart15;
    QJsonObject FanJsonPart16;
    QJsonObject FanJsonPart17;
    QJsonObject FanJsonPart18;
    QJsonObject FanJsonPart19;

    QJsonObject PumpPart;

    QJsonObject TECPart;
    QJsonObject TECPart1;
    QJsonObject TECPart2;
    QJsonObject TECPart3;
    QJsonObject TECPart4;
    QJsonObject TECPart5;

    QJsonObject ElecPart;
    QJsonObject ElecPart1;
    QJsonObject ElecPart2;
    QJsonObject ElecPart3;

    QJsonObject FanJsonPartAll;

    HeatControlMenu * ControlMenu;

    std::vector<std::vector<int>> FanDataMatrix{20,std::vector<int>(2)};
    std::vector<std::vector<int>> TECDataMatrix{16,std::vector<int>(2)};

    std::vector<std::vector<int>> FanJsonMatrix{20,std::vector<int>(4)};

    //水泵
    std::vector<std::vector<int>> PumpJsonMatrix{16,std::vector<int>(2)};
    std::vector<std::vector<int>> TECJsonMatrix{16,std::vector<int>(2)};
    std::vector<std::vector<int>> ElecJsonMatrix{16,std::vector<int>(2)};

    bool isRenewdata = true;
    bool isSavedata =false;
};
#endif // SELFTESTTHREAD_H
