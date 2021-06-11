#include "savedatathread.h"
#include<QString>
#include<QMessageBox>
#include<QEventLoop>
#include<QJsonDocument>
#include<QDateTime>
#include <QObject>
#include<QDir>
#include<QMessageBox>
savedatathread::~savedatathread()
{

}

void savedatathread::handlesave(){
    isSavedata = true;
}

void savedatathread::setStop()
{
    FanJsonPart.insert("转数", versionArray);
    FanJsonPart1.insert("转数", versionArray1);
    FanJsonPart2.insert("转数", versionArray2);
    FanJsonPart3.insert("转数", versionArray3);
    FanJsonPart4.insert("转数", versionArray4);
    FanJsonPart5.insert("转数", versionArray5);
    FanJsonPart6.insert("转数", versionArray6);
    FanJsonPart7.insert("转数", versionArray7);
    FanJsonPart8.insert("转数", versionArray8);
    FanJsonPart9.insert("转数", versionArray9);
    FanJsonPart10.insert("转数", versionArray10);
    FanJsonPart11.insert("转数", versionArray11);
    FanJsonPart12.insert("转数", versionArray12);
    FanJsonPart13.insert("转数", versionArray13);
    FanJsonPart14.insert("转数", versionArray14);
    FanJsonPart15.insert("转数", versionArray15);
    FanJsonPart16.insert("转数", versionArray16);
    FanJsonPart17.insert("转数", versionArray17);
    FanJsonPart18.insert("转数", versionArray18);
    FanJsonPart19.insert("转数", versionArray19);
    //最大电压
    FanJsonPart.insert("最大电压", versionArra);
    FanJsonPart1.insert("最大电压", versionArra1);
    FanJsonPart2.insert("最大电压", versionArra2);
    FanJsonPart3.insert("最大电压", versionArra3);
    FanJsonPart4.insert("最大电压", versionArra4);
    FanJsonPart5.insert("最大电压", versionArra5);
    FanJsonPart6.insert("最大电压", versionArra6);
    FanJsonPart7.insert("最大电压", versionArra7);
    FanJsonPart8.insert("最大电压", versionArra8);
    FanJsonPart9.insert("最大电压", versionArra9);
    FanJsonPart10.insert("最大电压", versionArra10);
    FanJsonPart11.insert("最大电压", versionArra11);
    FanJsonPart12.insert("最大电压", versionArra12);
    FanJsonPart13.insert("最大电压", versionArra13);
    FanJsonPart14.insert("最大电压", versionArra14);
    FanJsonPart15.insert("最大电压", versionArra15);
    FanJsonPart16.insert("最大电压", versionArra16);
    FanJsonPart17.insert("最大电压", versionArra17);
    FanJsonPart18.insert("最大电压", versionArra18);
    FanJsonPart19.insert("最大电压", versionArra19);

    //风扇(电压/占空比)
    FanJsonPart.insert("风扇(电压/占空比)", versionArr);
    FanJsonPart1.insert("风扇(电压/占空比)", versionArr1);
    FanJsonPart2.insert("风扇(电压/占空比)", versionArr2);
    FanJsonPart3.insert("风扇(电压/占空比)", versionArr3);
    FanJsonPart4.insert("风扇(电压/占空比)", versionArr4);
    FanJsonPart5.insert("风扇(电压/占空比)", versionArr5);
    FanJsonPart6.insert("风扇(电压/占空比)", versionArr6);
    FanJsonPart7.insert("风扇(电压/占空比)", versionArr7);
    FanJsonPart8.insert("风扇(电压/占空比)", versionArr8);
    FanJsonPart9.insert("风扇(电压/占空比)", versionArr9);
    FanJsonPart10.insert("风扇(电压/占空比)", versionArr10);
    FanJsonPart11.insert("风扇(电压/占空比)", versionArr11);
    FanJsonPart12.insert("风扇(电压/占空比)", versionArr12);
    FanJsonPart13.insert("风扇(电压/占空比)", versionArr13);
    FanJsonPart14.insert("风扇(电压/占空比)", versionArr14);
    FanJsonPart15.insert("风扇(电压/占空比)", versionArr15);
    FanJsonPart16.insert("风扇(电压/占空比)", versionArr16);
    FanJsonPart17.insert("风扇(电压/占空比)", versionArr17);
    FanJsonPart18.insert("风扇(电压/占空比)", versionArr18);
    FanJsonPart19.insert("风扇(电压/占空比)", versionArr19);


    FanJsonPart.insert("风扇ID",1);
    FanJsonPart1.insert("风扇ID",2);
    FanJsonPart2.insert("风扇ID",3);
    FanJsonPart3.insert("风扇ID",4);
    FanJsonPart4.insert("风扇ID",5);
    FanJsonPart5.insert("风扇ID",6);
    FanJsonPart6.insert("风扇ID",7);
    FanJsonPart7.insert("风扇ID",8);
    FanJsonPart8.insert("风扇ID",9);
    FanJsonPart9.insert("风扇ID",10);
    FanJsonPart10.insert("风扇ID",11);
    FanJsonPart11.insert("风扇ID",12);
    FanJsonPart12.insert("风扇ID",13);
    FanJsonPart13.insert("风扇ID",14);
    FanJsonPart14.insert("风扇ID",15);
    FanJsonPart15.insert("风扇ID",16);
    FanJsonPart16.insert("风扇ID",17);
    FanJsonPart17.insert("风扇ID",18);
    FanJsonPart18.insert("风扇ID",19);
    FanJsonPart19.insert("风扇ID",20);

    PumpPart.insert("水泵设置的电压", PumpArray);
    PumpPart.insert("水泵ID（只用一个控制核）",1);

    TECPart.insert("设置冷面温度", TECArray);
    TECPart1.insert("设置冷面温度", TECArray1);
    TECPart2.insert("设置冷面温度", TECArray2);
    TECPart3.insert("设置冷面温度", TECArray3);
    TECPart4.insert("设置冷面温度", TECArray4);
    TECPart5.insert("设置冷面温度", TECArray5);

    TECPart.insert("TEC冷面温度反馈", TECArra);
    TECPart1.insert("TEC冷面温度反馈", TECArra1);
    TECPart2.insert("TEC冷面温度反馈", TECArra2);
    TECPart3.insert("TEC冷面温度反馈", TECArra3);
    TECPart4.insert("TEC冷面温度反馈", TECArra4);
    TECPart5.insert("TEC冷面温度反馈", TECArra5);

    TECPart.insert("TEC占空比", TECArr);
    TECPart1.insert("TEC占空比", TECArr1);
    TECPart2.insert("TEC占空比", TECArr2);
    TECPart3.insert("TEC占空比", TECArr3);
    TECPart4.insert("TEC占空比", TECArr4);
    TECPart5.insert("TEC占空比", TECArr5);

    TECPart.insert("TECID",1);
    TECPart1.insert("TECID",2);
    TECPart2.insert("TECID",3);
    TECPart3.insert("TECID",4);
    TECPart4.insert("TECID",5);
    TECPart5.insert("TECID",6);

    ElecPart.insert("电流值", ElecArray);
    ElecPart1.insert("电流值", ElecArray1);
    ElecPart2.insert("电流值", ElecArray2);
    ElecPart3.insert("电流值", ElecArray3);


    ElecPart.insert("ElecID",1);
    ElecPart1.insert("ElecID",2);
    ElecPart2.insert("ElecID",3);
    ElecPart3.insert("ElecID",4);

    FanJsonPartAll.insert("1",FanJsonPart);
    FanJsonPartAll.insert("2",FanJsonPart1);
    FanJsonPartAll.insert("3",FanJsonPart2);
    FanJsonPartAll.insert("4",FanJsonPart3);
    FanJsonPartAll.insert("5",FanJsonPart4);
    FanJsonPartAll.insert("6",FanJsonPart5);
    FanJsonPartAll.insert("7",FanJsonPart6);
    FanJsonPartAll.insert("8",FanJsonPart7);
    FanJsonPartAll.insert("9",FanJsonPart8);
    FanJsonPartAll.insert("10",FanJsonPart9);
    FanJsonPartAll.insert("11",FanJsonPart10);
    FanJsonPartAll.insert("12",FanJsonPart11);
    FanJsonPartAll.insert("13",FanJsonPart12);
    FanJsonPartAll.insert("14",FanJsonPart13);
    FanJsonPartAll.insert("15",FanJsonPart14);
    FanJsonPartAll.insert("16",FanJsonPart15);
    FanJsonPartAll.insert("17",FanJsonPart16);
    FanJsonPartAll.insert("18",FanJsonPart17);
    FanJsonPartAll.insert("19",FanJsonPart18);
    FanJsonPartAll.insert("20",FanJsonPart19);

    FanJsonPartAll.insert("21",PumpPart);

    FanJsonPartAll.insert("22",TECPart);
    FanJsonPartAll.insert("23",TECPart1);
    FanJsonPartAll.insert("24",TECPart2);
    FanJsonPartAll.insert("25",TECPart3);
    FanJsonPartAll.insert("26",TECPart4);
    FanJsonPartAll.insert("27",TECPart5);

    FanJsonPartAll.insert("28",ElecPart);
    FanJsonPartAll.insert("29",ElecPart1);
    FanJsonPartAll.insert("30",ElecPart2);
    FanJsonPartAll.insert("31",ElecPart3);


    QJsonDocument doc;
    doc.setObject(FanJsonPartAll);
    QByteArray data = doc.toJson();

    QTime current_time = QTime::currentTime();
    int hour = current_time.hour();        //当前的小时
    int minute = current_time.minute();    //当前的分
    int second = current_time.second();    //当前的秒

    QString dir_str = "D://Users//no2//Desktop2";

    // 检查目录是否存在，若不存在则新建
    QDir dir;
    if (!dir.exists(dir_str))
    {
      dir.mkpath(dir_str);
    }

    QString fileName = tr("D://Users//no2//Desktop2//停止时刻%1h%2m%3s..json").arg(hour).arg(minute).arg(second);

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(data);
    file.close();
    setrunning = false;
}

void savedatathread::setStart()
{

}

void savedatathread::savedata()
{

}


void savedatathread::receivenewData(std::vector<std::vector<int>> Matrixone,
                                    std::vector<std::vector<int>> Matrixone1,
                                    std::vector<std::vector<int>> Matrixone2,
                                    std::vector<std::vector<int>> Matrixone3,
                                    std::vector<std::vector<int>> Matrixone4,
                                    std::vector<std::vector<int>> Matrixone5)
{
    FanDataMatrix = Matrixone;
    FanJsonMatrix = Matrixone1;
    PumpJsonMatrix=Matrixone2;
    TECJsonMatrix =Matrixone3;
    ElecJsonMatrix =Matrixone4;
    TECDataMatrix=Matrixone5;
}


void savedatathread::run()
{
    
    //初始化部分
    for(int i =0;i<20;i++)
    {
        FanDataMatrix[i][0]=0;
        FanDataMatrix[i][1]=1;

        FanJsonMatrix[i][0]=0;
        FanJsonMatrix[i][1]=1;
        FanJsonMatrix[i][2]=2;
        FanJsonMatrix[i][3]=3;


    }
    for(int i =0;i<16;i++)
    {
        PumpJsonMatrix[i][0] =0;
        TECJsonMatrix[i][0] =0;
        ElecJsonMatrix[i][0] =0;

        PumpJsonMatrix[i][1] =1;
        TECJsonMatrix[i][1] = 1;
        ElecJsonMatrix[i][1] = 1;
    }

    int Count =0;
   
    isRenewdata =true;

    
    while(setrunning)
   {
        
        if(isRenewdata)//用于更新数据
        {
            emit renewData();
            QEventLoop loop;
            QTimer::singleShot(500, &loop, SLOT(quit()));
            loop.exec();
            isRenewdata=false;
        }


        else
        {
            //用于保存数据
            for(int i = 0; i<20;i++)
            {
             if(FanDataMatrix[i][0] !=0)
               {
                switch (i) {
                case 0:
                    versionArray.pop_front();
                    versionArray.push_back(FanDataMatrix[i][1]);
                    versionArra.pop_front();
                    versionArra.push_back(FanJsonMatrix[i][2]);
                    versionArr.pop_front();
                    versionArr.push_back(FanJsonMatrix[i][3]);
                    break;
                case 1:
                    versionArray1.pop_front();
                    versionArray1.push_back(FanDataMatrix[i][1]);
                    versionArra1.pop_front();
                    versionArra1.push_back(FanJsonMatrix[i][2]);
                    versionArr1.pop_front();
                    versionArr1.push_back(FanJsonMatrix[i][3]);
                    break;
                case 2:
                    versionArray2.pop_front();
                    versionArray2.push_back(FanDataMatrix[i][1]);
                    versionArra2.pop_front();
                    versionArra2.push_back(FanJsonMatrix[i][2]);
                    versionArr2.pop_front();
                    versionArr2.push_back(FanJsonMatrix[i][3]);
                    break;
                case 3:
                    versionArray3.pop_front();
                    versionArray3.push_back(FanDataMatrix[i][1]);
                    versionArra3.pop_front();
                    versionArra3.push_back(FanJsonMatrix[i][2]);
                    versionArr3.pop_front();
                    versionArr3.push_back(FanJsonMatrix[i][3]);
                    break;
                case 4:
                    versionArray4.pop_front();
                    versionArray4.push_back(FanDataMatrix[i][1]);
                    versionArra4.pop_front();
                    versionArra4.push_back(FanJsonMatrix[i][2]);
                    versionArr4.pop_front();
                    versionArr4.push_back(FanJsonMatrix[i][3]);
                    break;
                case 5:
                    versionArray5.pop_front();
                    versionArray5.push_back(FanDataMatrix[i][1]);
                    versionArra5.pop_front();
                    versionArra5.push_back(FanJsonMatrix[i][2]);
                    versionArr5.pop_front();
                    versionArr5.push_back(FanJsonMatrix[i][3]);
                    break;
                case 6:
                    versionArray6.pop_front();
                    versionArray6.push_back(FanDataMatrix[i][1]);
                    versionArra6.pop_front();
                    versionArra6.push_back(FanJsonMatrix[i][2]);
                    versionArr6.pop_front();
                    versionArr6.push_back(FanJsonMatrix[i][3]);
                    break;

                case 7:
                    versionArray7.pop_front();
                    versionArray7.push_back(FanDataMatrix[i][1]);
                    versionArra7.pop_front();
                    versionArra7.push_back(FanJsonMatrix[i][2]);
                    versionArr7.pop_front();
                    versionArr7.push_back(FanJsonMatrix[i][3]);
                    break;
                case 8:
                    versionArray8.pop_front();
                    versionArray8.push_back(FanDataMatrix[i][1]);
                    versionArra8.pop_front();
                    versionArra8.push_back(FanJsonMatrix[i][2]);
                    versionArr8.pop_front();
                    versionArr8.push_back(FanJsonMatrix[i][3]);
                    break;
                case 9:
                    versionArray9.pop_front();
                    versionArray9.push_back(FanDataMatrix[i][1]);
                    versionArra9.pop_front();
                    versionArra9.push_back(FanJsonMatrix[i][2]);
                    versionArr9.pop_front();
                    versionArr9.push_back(FanJsonMatrix[i][3]);
                    break;
                case 10:
                    versionArray10.pop_front();
                    versionArray10.push_back(FanDataMatrix[i][1]);
                    versionArra10.pop_front();
                    versionArra10.push_back(FanJsonMatrix[i][2]);
                    versionArr10.pop_front();
                    versionArr10.push_back(FanJsonMatrix[i][3]);
                    break;
                case 11:
                    versionArray11.pop_front();
                    versionArray11.push_back(FanDataMatrix[i][1]);
                    versionArra11.pop_front();
                    versionArra11.push_back(FanJsonMatrix[i][2]);
                    versionArr11.pop_front();
                    versionArr11.push_back(FanJsonMatrix[i][3]);
                    break;
                case 12:
                    versionArray12.pop_front();
                    versionArray12.push_back(FanDataMatrix[i][1]);
                    versionArra12.pop_front();
                    versionArra12.push_back(FanJsonMatrix[i][2]);
                    versionArr12.pop_front();
                    versionArr12.push_back(FanJsonMatrix[i][3]);
                    break;
                case 13:
                    versionArray13.pop_front();
                    versionArray13.push_back(FanDataMatrix[i][1]);
                    versionArra13.pop_front();
                    versionArra13.push_back(FanJsonMatrix[i][2]);
                    versionArr13.pop_front();
                    versionArr13.push_back(FanJsonMatrix[i][3]);
                    break;
                case 14:
                    versionArray14.pop_front();
                    versionArray14.push_back(FanDataMatrix[i][1]);
                    versionArra14.pop_front();
                    versionArra14.push_back(FanJsonMatrix[i][2]);
                    versionArr14.pop_front();
                    versionArr14.push_back(FanJsonMatrix[i][3]);
                    break;
                case 15:
                    versionArray15.pop_front();
                    versionArray15.push_back(FanDataMatrix[i][1]);
                    versionArra15.pop_front();
                    versionArra15.push_back(FanJsonMatrix[i][2]);
                    versionArr15.pop_front();
                    versionArr15.push_back(FanJsonMatrix[i][3]);
                    break;
                case 16:
                    versionArray16.pop_front();
                    versionArray16.push_back(FanDataMatrix[i][1]);
                    versionArra16.pop_front();
                    versionArra16.push_back(FanJsonMatrix[i][2]);
                    versionArr16.pop_front();
                    versionArr16.push_back(FanJsonMatrix[i][3]);
                    break;
                case 17:
                    versionArray17.pop_front();
                    versionArray17.push_back(FanDataMatrix[i][1]);
                    versionArra17.pop_front();
                    versionArra17.push_back(FanJsonMatrix[i][2]);
                    versionArr17.pop_front();
                    versionArr17.push_back(FanJsonMatrix[i][3]);
                    break;
                case 18:
                    versionArray18.pop_front();
                    versionArray18.push_back(FanDataMatrix[i][1]);
                    versionArra18.pop_front();
                    versionArra18.push_back(FanJsonMatrix[i][2]);
                    versionArr18.pop_front();
                    versionArr18.push_back(FanJsonMatrix[i][3]);
                    break;
                case 19:
                    versionArray19.pop_front();
                    versionArray19.push_back(FanDataMatrix[i][1]);
                    versionArra19.pop_front();
                    versionArra19.push_back(FanJsonMatrix[i][2]);
                    versionArr19.pop_front();
                    versionArr19.push_back(FanJsonMatrix[i][3]);
                    break;
                default:
                    break;
                }

            }
         }
            for(int i = 0; i<16;i++)
            {
             if(PumpJsonMatrix[i][0] !=0)
               {
                switch (i) {
                case 0:
                    PumpArray.pop_front();
                    PumpArray.push_back(PumpJsonMatrix[i][1]);
                    break;
                default:
                    break;
                }

            }
         }
            for(int i = 0; i<16;i++)
            {
             if(TECJsonMatrix[i][0] !=0)
               {
                switch (i) {
                case 0:
                    TECArray.pop_front();
                    TECArray.push_back(TECJsonMatrix[i][1]);
                    TECArra.pop_front();
                    TECArra.push_back(TECDataMatrix[i][0]);
                    TECArr.pop_front();
                    TECArr.push_back(TECDataMatrix[i][1]);
                    break;
                case 1:
                    TECArray1.pop_front();
                    TECArray1.push_back(TECJsonMatrix[i][1]);
                    TECArra1.pop_front();
                    TECArra1.push_back(TECDataMatrix[i][0]);
                    TECArr1.pop_front();
                    TECArr1.push_back(TECDataMatrix[i][1]);
                    break;
                case 2:
                    TECArray2.pop_front();
                    TECArray2.push_back(TECJsonMatrix[i][1]);
                    TECArra2.pop_front();
                    TECArra2.push_back(TECDataMatrix[i][0]);
                    TECArr2.pop_front();
                    TECArr2.push_back(TECDataMatrix[i][1]);
                    break;
                case 3:
                    TECArray3.pop_front();
                    TECArray3.push_back(TECJsonMatrix[i][1]);
                    TECArra3.pop_front();
                    TECArra3.push_back(TECDataMatrix[i][0]);
                    TECArr3.pop_front();
                    TECArr3.push_back(TECDataMatrix[i][1]);
                    break;
                case 4:
                    TECArray4.pop_front();
                    TECArray4.push_back(TECJsonMatrix[i][1]);
                    TECArra4.pop_front();
                    TECArra4.push_back(TECDataMatrix[i][0]);
                    TECArr4.pop_front();
                    TECArr4.push_back(TECDataMatrix[i][1]);
                    break;
                case 5:
                    TECArray5.pop_front();
                    TECArray5.push_back(TECJsonMatrix[i][1]);
                    TECArra5.pop_front();
                    TECArra5.push_back(TECDataMatrix[i][0]);
                    TECArr5.pop_front();
                    TECArr5.push_back(TECDataMatrix[i][1]);
                    break;

                default:
                    break;
                }

            }
         }
            for(int i = 0; i<16;i++)
            {
             if(ElecJsonMatrix[i][0] !=0)
               {
                switch (i) {
                case 0:
                    ElecArray.pop_front();
                    ElecArray.push_back(ElecJsonMatrix[i][1]);
                    break;
                case 1:
                    ElecArray1.pop_front();
                    ElecArray1.push_back(ElecJsonMatrix[i][1]);
                    break;
                case 2:
                    ElecArray2.pop_front();
                    ElecArray2.push_back(ElecJsonMatrix[i][1]);
                    break;
                case 3:
                    ElecArray3.pop_front();
                    ElecArray3.push_back(ElecJsonMatrix[i][1]);
                    break;
                default:
                    break;
                }

            }
         }
    isRenewdata=true;


    Count +=1;

    //保存数据
    if(Count%10 ==0 )
    {
        FanJsonPart.insert("转数", versionArray);
        FanJsonPart1.insert("转数", versionArray1);
        FanJsonPart2.insert("转数", versionArray2);
        FanJsonPart3.insert("转数", versionArray3);
        FanJsonPart4.insert("转数", versionArray4);
        FanJsonPart5.insert("转数", versionArray5);
        FanJsonPart6.insert("转数", versionArray6);
        FanJsonPart7.insert("转数", versionArray7);
        FanJsonPart8.insert("转数", versionArray8);
        FanJsonPart9.insert("转数", versionArray9);
        FanJsonPart10.insert("转数", versionArray10);
        FanJsonPart11.insert("转数", versionArray11);
        FanJsonPart12.insert("转数", versionArray12);
        FanJsonPart13.insert("转数", versionArray13);
        FanJsonPart14.insert("转数", versionArray14);
        FanJsonPart15.insert("转数", versionArray15);
        FanJsonPart16.insert("转数", versionArray16);
        FanJsonPart17.insert("转数", versionArray17);
        FanJsonPart18.insert("转数", versionArray18);
        FanJsonPart19.insert("转数", versionArray19);
        //最大电压
        FanJsonPart.insert("最大电压", versionArra);
        FanJsonPart1.insert("最大电压", versionArra1);
        FanJsonPart2.insert("最大电压", versionArra2);
        FanJsonPart3.insert("最大电压", versionArra3);
        FanJsonPart4.insert("最大电压", versionArra4);
        FanJsonPart5.insert("最大电压", versionArra5);
        FanJsonPart6.insert("最大电压", versionArra6);
        FanJsonPart7.insert("最大电压", versionArra7);
        FanJsonPart8.insert("最大电压", versionArra8);
        FanJsonPart9.insert("最大电压", versionArra9);
        FanJsonPart10.insert("最大电压", versionArra10);
        FanJsonPart11.insert("最大电压", versionArra11);
        FanJsonPart12.insert("最大电压", versionArra12);
        FanJsonPart13.insert("最大电压", versionArra13);
        FanJsonPart14.insert("最大电压", versionArra14);
        FanJsonPart15.insert("最大电压", versionArra15);
        FanJsonPart16.insert("最大电压", versionArra16);
        FanJsonPart17.insert("最大电压", versionArra17);
        FanJsonPart18.insert("最大电压", versionArra18);
        FanJsonPart19.insert("最大电压", versionArra19);

        //风扇(电压/占空比)
        FanJsonPart.insert("风扇(电压/占空比)", versionArr);
        FanJsonPart1.insert("风扇(电压/占空比)", versionArr1);
        FanJsonPart2.insert("风扇(电压/占空比)", versionArr2);
        FanJsonPart3.insert("风扇(电压/占空比)", versionArr3);
        FanJsonPart4.insert("风扇(电压/占空比)", versionArr4);
        FanJsonPart5.insert("风扇(电压/占空比)", versionArr5);
        FanJsonPart6.insert("风扇(电压/占空比)", versionArr6);
        FanJsonPart7.insert("风扇(电压/占空比)", versionArr7);
        FanJsonPart8.insert("风扇(电压/占空比)", versionArr8);
        FanJsonPart9.insert("风扇(电压/占空比)", versionArr9);
        FanJsonPart10.insert("风扇(电压/占空比)", versionArr10);
        FanJsonPart11.insert("风扇(电压/占空比)", versionArr11);
        FanJsonPart12.insert("风扇(电压/占空比)", versionArr12);
        FanJsonPart13.insert("风扇(电压/占空比)", versionArr13);
        FanJsonPart14.insert("风扇(电压/占空比)", versionArr14);
        FanJsonPart15.insert("风扇(电压/占空比)", versionArr15);
        FanJsonPart16.insert("风扇(电压/占空比)", versionArr16);
        FanJsonPart17.insert("风扇(电压/占空比)", versionArr17);
        FanJsonPart18.insert("风扇(电压/占空比)", versionArr18);
        FanJsonPart19.insert("风扇(电压/占空比)", versionArr19);


        FanJsonPart.insert("风扇ID",1);
        FanJsonPart1.insert("风扇ID",2);
        FanJsonPart2.insert("风扇ID",3);
        FanJsonPart3.insert("风扇ID",4);
        FanJsonPart4.insert("风扇ID",5);
        FanJsonPart5.insert("风扇ID",6);
        FanJsonPart6.insert("风扇ID",7);
        FanJsonPart7.insert("风扇ID",8);
        FanJsonPart8.insert("风扇ID",9);
        FanJsonPart9.insert("风扇ID",10);
        FanJsonPart10.insert("风扇ID",11);
        FanJsonPart11.insert("风扇ID",12);
        FanJsonPart12.insert("风扇ID",13);
        FanJsonPart13.insert("风扇ID",14);
        FanJsonPart14.insert("风扇ID",15);
        FanJsonPart15.insert("风扇ID",16);
        FanJsonPart16.insert("风扇ID",17);
        FanJsonPart17.insert("风扇ID",18);
        FanJsonPart18.insert("风扇ID",19);
        FanJsonPart19.insert("风扇ID",20);

        PumpPart.insert("水泵设置的电压", PumpArray);
        PumpPart.insert("水泵ID（只用一个控制核）",1);

        TECPart.insert("设置冷面温度", TECArray);
        TECPart1.insert("设置冷面温度", TECArray1);
        TECPart2.insert("设置冷面温度", TECArray2);
        TECPart3.insert("设置冷面温度", TECArray3);
        TECPart4.insert("设置冷面温度", TECArray4);
        TECPart5.insert("设置冷面温度", TECArray5);

        TECPart.insert("TEC冷面温度反馈", TECArra);
        TECPart1.insert("TEC冷面温度反馈", TECArra1);
        TECPart2.insert("TEC冷面温度反馈", TECArra2);
        TECPart3.insert("TEC冷面温度反馈", TECArra3);
        TECPart4.insert("TEC冷面温度反馈", TECArra4);
        TECPart5.insert("TEC冷面温度反馈", TECArra5);

        TECPart.insert("TEC占空比", TECArr);
        TECPart1.insert("TEC占空比", TECArr1);
        TECPart2.insert("TEC占空比", TECArr2);
        TECPart3.insert("TEC占空比", TECArr3);
        TECPart4.insert("TEC占空比", TECArr4);
        TECPart5.insert("TEC占空比", TECArr5);

        TECPart.insert("TECID",1);
        TECPart1.insert("TECID",2);
        TECPart2.insert("TECID",3);
        TECPart3.insert("TECID",4);
        TECPart4.insert("TECID",5);
        TECPart5.insert("TECID",6);

        ElecPart.insert("电流值", ElecArray);
        ElecPart1.insert("电流值", ElecArray1);
        ElecPart2.insert("电流值", ElecArray2);
        ElecPart3.insert("电流值", ElecArray3);


        ElecPart.insert("ElecID",1);
        ElecPart1.insert("ElecID",2);
        ElecPart2.insert("ElecID",3);
        ElecPart3.insert("ElecID",4);

        FanJsonPartAll.insert("1",FanJsonPart);
        FanJsonPartAll.insert("2",FanJsonPart1);
        FanJsonPartAll.insert("3",FanJsonPart2);
        FanJsonPartAll.insert("4",FanJsonPart3);
        FanJsonPartAll.insert("5",FanJsonPart4);
        FanJsonPartAll.insert("6",FanJsonPart5);
        FanJsonPartAll.insert("7",FanJsonPart6);
        FanJsonPartAll.insert("8",FanJsonPart7);
        FanJsonPartAll.insert("9",FanJsonPart8);
        FanJsonPartAll.insert("10",FanJsonPart9);
        FanJsonPartAll.insert("11",FanJsonPart10);
        FanJsonPartAll.insert("12",FanJsonPart11);
        FanJsonPartAll.insert("13",FanJsonPart12);
        FanJsonPartAll.insert("14",FanJsonPart13);
        FanJsonPartAll.insert("15",FanJsonPart14);
        FanJsonPartAll.insert("16",FanJsonPart15);
        FanJsonPartAll.insert("17",FanJsonPart16);
        FanJsonPartAll.insert("18",FanJsonPart17);
        FanJsonPartAll.insert("19",FanJsonPart18);
        FanJsonPartAll.insert("20",FanJsonPart19);

        FanJsonPartAll.insert("21",PumpPart);

        FanJsonPartAll.insert("22",TECPart);
        FanJsonPartAll.insert("23",TECPart1);
        FanJsonPartAll.insert("24",TECPart2);
        FanJsonPartAll.insert("25",TECPart3);
        FanJsonPartAll.insert("26",TECPart4);
        FanJsonPartAll.insert("27",TECPart5);

        FanJsonPartAll.insert("28",ElecPart);
        FanJsonPartAll.insert("29",ElecPart1);
        FanJsonPartAll.insert("30",ElecPart2);
        FanJsonPartAll.insert("31",ElecPart3);


        QJsonDocument doc;
        doc.setObject(FanJsonPartAll);
        QByteArray data = doc.toJson();
        QDateTime time = QDateTime::currentDateTime();
//        int timeT = time.toTime_t();
        QTime current_time = QTime::currentTime();
        int hour = current_time.hour();        //当前的小时
        int minute = current_time.minute();    //当前的分
        int second = current_time.second();    //当前的秒


        QString dir_str = "D://Users//no2//Desktop2";

        // 检查目录是否存在，若不存在则新建
        QDir dir;
        if (!dir.exists(dir_str))
        {
          dir.mkpath(dir_str);
        }

        QString fileName = tr("D://Users//no2//Desktop2/正常保存%1h%2m%3s.json").arg(hour).arg(minute).arg(second);

        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        file.write(data);
        file.close();

        Count =0;

        }


    }
  }
}


