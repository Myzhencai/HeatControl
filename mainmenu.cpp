#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QDebug>
#include <vector>
#include <stack>
#include "heatcontrolmenu.h"
#include <QMessageBox>
#include <QElapsedTimer>
#include <QFuture>
#include <QString>
#include <QDebug>
#include <QThread>
#include <QApplication>
#include <QDebug>
#include <QThread>
#include <QtConcurrent>
#include <QFuture>
#include "newqthread.h"
#include<QElapsedTimer>
#include<QEventLoop>
#include<math.h>


MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
   ui->setupUi(this);

   //初始化json
   for(int i = 0 ;i<8;i++)
   {
      FanJsonMatrix[i][1] =3;
      FanJsonMatrix[i][2] =5;
      FanJsonMatrix[i][3] =1;
      FanDataMatrix[i][0] =0;
      FanDataMatrix[i][1] =1;
   }
   for(int i = 8 ;i<20;i++)
   {
      FanJsonMatrix[i][1] =4;
      FanJsonMatrix[i][2] =12;
      FanJsonMatrix[i][3] =1;
      FanDataMatrix[i][0] =0;
      FanDataMatrix[i][1] =1;
   }

   for(int i =0;i<16;i++)
   {
       TECDataMatrix[i][0] =0;
       TECDataMatrix[i][1] =0;
   }


   for(int i = 0;i<20;i++)
   {
          FanSelfTest[i] = NULL;
          newFanSelfTest[i] = NULL;
   }

   for(int i = 0;i<3;i++)
   {
          PumpSelfTest[i] = NULL;
          newPumpSelfTest[i] = NULL;
   }

   for(int i = 0;i<6;i++)
   {
          TECSelfTest[i] = NULL;
          newTECSelfTest[i] = NULL;
   }
   for(int i = 0;i<4;i++)
   {
          ElecSelfTest[i] = NULL;
          newElecSelfTest[i] = NULL;
   }

   TempUart= NULL;
   TempTCP= NULL;

   RealtimeValue = NULL;
   SavedataThread =NULL;

   selftEstrun =NULL;

   ShowGrapic = new Showgraphic();
   newselfestpage = NULL;

   //生成初始化的界面
   ControlMenu = new HeatControlMenu;
   //初始化风扇部分
   ControlMenu->EditFanMenu();
   //初始化水泵部分
   ControlMenu->EditPumpMenu();
   //初始化TEC部分
   ControlMenu->EditTECMenu();
   //初始化电流部分
   ControlMenu->EditElecMenu();
   //初始化总体的界面
   ControlMenu->HeatMenu();


   //自动测试界面生成
   SelfTest = new SelfTestWidow;
   SelfTest->EditSelfMenu();//风扇
   SelfTest->EditSelfPumpMenu();
   SelfTest->EditSelfTECMenu();
   SelfTest->EditSelfElecMenu();
   SelfTest->SelfTestMenu();
   SelfTest->setEnabled(false);

   newselfTest = new MainWindowSelfTest();


   for(int i =0;i<20;i++)
   {
       Fanrealgraphic[i] = NULL;
   }

   for(int i = 0;i<6;i++)
   {
       TECrealgraphicTemp[i] =NULL;
       TECrealgraphicDuty[i] =NULL;
   }


   //检查各种器件勾选状态并动态生成对应数量的风扇
   FanStatusCheck();
   PumpStatusCheck();
   TECStatusCheck();
   ElecStatusCheck();

   //配置文件读取解析与生成
   ConfigFile = new ConfigFilePort;
   ui->scrollArea->setWidget(ConfigFile);



   //根据Json解析的内容来画图
   connect(ConfigFile,SIGNAL(ClearAll()),this,SLOT(ClearMenu()));//读取之前清除所有的界面控件
   connect(ConfigFile,SIGNAL(SetUsefulTwen()),this,SLOT(SetUsefulTwen()));
   connect(ConfigFile,SIGNAL(SetUsefulTel()),this,SLOT(SetUsefulTel()));

   connect(ConfigFile,SIGNAL(FanCreatWithJson(int,int,int,int)),this,SLOT(FanCreatWithJson(int,int,int,int)));
   connect(ConfigFile,SIGNAL(PumpCreatWithJson(int,int)),this,SLOT(PumpCreatWithJson(int,int)));
   connect(ConfigFile,SIGNAL(TECCreatWithJson(int,int,int)),this,SLOT(TECCreatWithJson(int,int,int)));
   connect(ConfigFile,SIGNAL(ElecCreatWithJson(int,int)),this,SLOT(ElecCreatWithJson(int,int)));
   //根据界面改动来生成Json文件

   connect(ControlMenu,SIGNAL(SendElecMaxValue(int,int)),this,SLOT(SetElecMaxValue(int,int)));
   connect(ControlMenu,SIGNAL(SendDucyValue(int,int)),this,SLOT(SetDucyValue(int,int)));
   connect(ControlMenu,SIGNAL(SendPumpValue(int,int)),this,SLOT(SetPumpValue(int,int)));
   connect(ControlMenu,SIGNAL(SendTECColdValue(int,int)),this,SLOT(SetTECColdValue(int,int)));
   connect(ControlMenu,SIGNAL(SendTECHeatValue(int,int)),this,SLOT(SetTECHeatValue(int,int)));
   connect(ControlMenu,SIGNAL(SendElecValue(int,int)),this,SLOT(SetElecValue(int,int)));

   //自动检测
   connect(SelfTest,SIGNAL(SendFanminComp(int,int)),this,SLOT(SetFanminComp(int,int)));
   connect(SelfTest,SIGNAL(SendFanmaxComp(int,int)),this,SLOT(SetFanmaxComp(int,int)));
   connect(SelfTest,SIGNAL(SendFanstepComp(int,int)),this,SLOT(SetFanstepComp(int,int)));

   connect(SelfTest,SIGNAL(SendPumpminComp(int,int)),this,SLOT(SetPumpminComp(int,int)));
   connect(SelfTest,SIGNAL(SendPumpmaxComp(int,int)),this,SLOT(SetPumpmaxComp(int,int)));
   connect(SelfTest,SIGNAL(SendPumpstepComp(int,int)),this,SLOT(SetPumpstepComp(int,int)));

   connect(SelfTest,SIGNAL(SendTECminComp(int,int)),this,SLOT(SetTECminComp(int,int)));
   connect(SelfTest,SIGNAL(SendTECmaxComp(int,int)),this,SLOT(SetTECmaxComp(int,int)));
   connect(SelfTest,SIGNAL(SendTECstepComp(int,int)),this,SLOT(SetTECstepComp(int,int)));

   connect(SelfTest,SIGNAL(SendElecminComp(int,int)),this,SLOT(SetElecminComp(int,int)));
   connect(SelfTest,SIGNAL(SendElecmaxComp(int,int)),this,SLOT(SetElecmaxComp(int,int)));
   connect(SelfTest,SIGNAL(SendElecstepComp(int,int)),this,SLOT(SetElecstepComp(int,int)));

   connect(SelfTest,SIGNAL(SendTestRunTime(double)),this,SLOT(SetTestRunTime(double)));
   connect(SelfTest,SIGNAL(SendRunTest(bool)),this,SLOT(SelfTestWithValue(bool)));
   connect(SelfTest,SIGNAL(SendRunTest(bool)),this,SLOT(SendAllPageconfig(bool)));//自动检测界面配置发送

   //获取实时的实际数据
   connect(ControlMenu->UartPort,SIGNAL(RecieveRealtimeValuewithUart(bool)),this,SLOT(RecieveRealtimeValuewithUart(bool)));
   connect(ControlMenu->NetWorkClient,SIGNAL(RecieveRealtimeValuewithTcpNet(bool)),this,SLOT(RecieveRealtimeValuewithTCPNetWork(bool)));

   //实时的数据更新
   //Uart
   connect(ControlMenu->UartPort,SIGNAL(RealTimeFanSpeedSet(int,QString)),this,SLOT(RealTimeFanSpeedSet(int,QString)));
   connect(ControlMenu->UartPort,SIGNAL(RealTimeNtcTempratureSet(int,QString)),this,SLOT(RealTimeNtcTempratureSet(int,QString)));
   connect(ControlMenu->UartPort,SIGNAL(RealTimeTECDutySet(int,QString)),this,SLOT(RealTimeTECDutySet(int,QString)));

   //TCP
   connect(ControlMenu->NetWorkClient,SIGNAL(TCPRealTimeFanSpeedSet(int,QString)),this,SLOT(TCPNetWorkRealTimeFanSpeedSet(int,QString)));
   connect(ControlMenu->NetWorkClient,SIGNAL(TCPRealTimeNtcTempratureSet(int,QString)),this,SLOT(TCPRealTimeNtcTempratureSet(int,QString)));
   connect(ControlMenu->NetWorkClient,SIGNAL(TCPRealTimeTECDutySet(int,QString)),this,SLOT(TCPRealTimeTECDutySet(int,QString)));

   //关闭当前所有线程
   connect(this,SIGNAL(ForbidenOpen()),ControlMenu->UartPort,SLOT(ForbidenOpen()));
   connect(this,SIGNAL(TCPForbidenOpen()),ControlMenu->NetWorkClient,SLOT(TCPForbidenOpen()));

   //配置测试图与开关
   connect(ControlMenu->UartPort,SIGNAL(SetTcpText(QString)),ControlMenu->NetWorkClient,SLOT(SetTcpText(QString)));

   //保存当前界面配置
   connect(ControlMenu->UartPort,SIGNAL(saveCurrentPageConfig()),this,SLOT(saveCurrentPageConfig()));
   connect(ControlMenu->UartPort,SIGNAL(showPageConfig()),this,SLOT(showPageConfig()));
   connect(ControlMenu->UartPort,SIGNAL(hidePageConfig()),this,SLOT(hidePageConfig()));
   connect(ControlMenu->UartPort,SIGNAL(showSelfTestWindow()),this,SLOT(showSelfTestWindow()));
   connect(ControlMenu->UartPort,SIGNAL(hideSelfTestWindow()),this,SLOT(hideSelfTestWindow()));
   connect(ControlMenu->UartPort,SIGNAL(showReal()),this,SLOT(showReal()));
   connect(ControlMenu->UartPort,SIGNAL(hideReal()),this,SLOT(hideReal()));
   connect(this,SIGNAL(Notopen()),ControlMenu->UartPort,SLOT(Notopen()));
   connect(ControlMenu->UartPort,SIGNAL(StopsaveData()),this,SLOT(StopdataThread()));
   connect(ControlMenu->UartPort,SIGNAL(StartsaveData()),this,SLOT(DATAsave()));
   connect(ControlMenu->NetWorkClient,SIGNAL(StopdataThread()),this,SLOT(stopvalue()));
   connect(ControlMenu->NetWorkClient,SIGNAL(startDataThread()),this,SLOT(startvalue()));


   //自动测试动态编辑
   connect(this,SIGNAL(UNEditctable(int)),newselfTest,SLOT(UNEdictable(int)));
   connect(this,SIGNAL(Editctable(int)),newselfTest,SLOT(Edictable(int)));

   //自动测试矩阵  
   connect(newselfTest,SIGNAL(SelfTestArraysend(std::vector<std::vector<int>>)),this,SLOT(SelfTestArraysend(std::vector<std::vector<int>>)));

   //自动测试时间
   connect(newselfTest,SIGNAL(SelfTestBegin()),this,SLOT(SendAllPageconfigStart()));//自动检测界面配置发送
   connect(newselfTest,SIGNAL(SelfTestStop()),this,SLOT(SendAllPageconfigStop()));//自动检测界面配置发送
   connect(newselfTest,SIGNAL(SelfTestBegin()),this,SLOT(SelfTestBegin()));
   connect(newselfTest,SIGNAL(SelfTestStop()),this,SLOT(SelfTestStop()));
   connect(newselfTest,SIGNAL(SendTestRunTime(double)),this,SLOT(SendTestRunTime(double)));


   //实时图像
   connect(this,SIGNAL(MakeFanshowbuttonenable(int)),ShowGrapic,SLOT(MakeFanshowbuttonenable(int)));
   connect(this,SIGNAL(MakeFanshowbuttonUNenable(int)),ShowGrapic,SLOT(MakeFanshowbuttonUNenable(int)));
   connect(this,SIGNAL(MakeTECTempshowbuttonenable(int)),ShowGrapic,SLOT(MakeTECTempshowbuttonenable(int)));
   connect(this,SIGNAL(MakeTECTempshowbuttonUNenable(int)),ShowGrapic,SLOT(MakeTECTempshowbuttonUNenable(int)));
   connect(this,SIGNAL(MakeTECDutyshowbuttonenable(int)),ShowGrapic,SLOT(MakeTECDutyshowbuttonenable(int)));
   connect(this,SIGNAL(MakeTECDutyshowbuttonUNenable(int)),ShowGrapic,SLOT(MakeTECDutyshowbuttonUNenable(int)));


   connect(ShowGrapic,SIGNAL(pushButtonhideReal()),this,SLOT(pushButtonhideReal()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal1()),this,SLOT(pushButtonhideReal1()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal2()),this,SLOT(pushButtonhideReal2()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal3()),this,SLOT(pushButtonhideReal3()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal4()),this,SLOT(pushButtonhideReal4()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal5()),this,SLOT(pushButtonhideReal5()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal6()),this,SLOT(pushButtonhideReal6()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal7()),this,SLOT(pushButtonhideReal7()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal8()),this,SLOT(pushButtonhideReal8()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal9()),this,SLOT(pushButtonhideReal9()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal10()),this,SLOT(pushButtonhideReal10()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal11()),this,SLOT(pushButtonhideReal11()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal12()),this,SLOT(pushButtonhideReal12()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal13()),this,SLOT(pushButtonhideReal13()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal14()),this,SLOT(pushButtonhideReal14()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal15()),this,SLOT(pushButtonhideReal15()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal16()),this,SLOT(pushButtonhideReal16()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal17()),this,SLOT(pushButtonhideReal17()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal18()),this,SLOT(pushButtonhideReal18()));
   connect(ShowGrapic,SIGNAL(pushButtonhideReal19()),this,SLOT(pushButtonhideReal19()));


   connect(ShowGrapic,SIGNAL(pushButtonshowReal()),this,SLOT(pushButtonshowReal()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal1()),this,SLOT(pushButtonshowReal1()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal2()),this,SLOT(pushButtonshowReal2()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal3()),this,SLOT(pushButtonshowReal3()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal4()),this,SLOT(pushButtonshowReal4()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal5()),this,SLOT(pushButtonshowReal5()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal6()),this,SLOT(pushButtonshowReal6()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal7()),this,SLOT(pushButtonshowReal7()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal8()),this,SLOT(pushButtonshowReal8()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal9()),this,SLOT(pushButtonshowReal9()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal10()),this,SLOT(pushButtonshowReal10()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal11()),this,SLOT(pushButtonshowReal11()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal12()),this,SLOT(pushButtonshowReal12()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal13()),this,SLOT(pushButtonshowReal13()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal14()),this,SLOT(pushButtonshowReal14()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal15()),this,SLOT(pushButtonshowReal15()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal16()),this,SLOT(pushButtonshowReal16()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal17()),this,SLOT(pushButtonshowReal17()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal18()),this,SLOT(pushButtonshowReal18()));
   connect(ShowGrapic,SIGNAL(pushButtonshowReal19()),this,SLOT(pushButtonshowReal19()));


   connect(ShowGrapic,SIGNAL(ButtonshowReal()),this,SLOT(ButtonshowReal()));
   connect(ShowGrapic,SIGNAL(ButtonshowReal1()),this,SLOT(ButtonshowReal1()));
   connect(ShowGrapic,SIGNAL(ButtonshowReal2()),this,SLOT(ButtonshowReal2()));
   connect(ShowGrapic,SIGNAL(ButtonshowReal3()),this,SLOT(ButtonshowReal3()));
   connect(ShowGrapic,SIGNAL(ButtonshowReal4()),this,SLOT(ButtonshowReal4()));
   connect(ShowGrapic,SIGNAL(ButtonshowReal5()),this,SLOT(ButtonshowReal5()));

   connect(ShowGrapic,SIGNAL(ButtonhideReal()),this,SLOT(ButtonhideReal()));
   connect(ShowGrapic,SIGNAL(ButtonhideReal1()),this,SLOT(ButtonhideReal1()));
   connect(ShowGrapic,SIGNAL(ButtonhideReal2()),this,SLOT(ButtonhideReal2()));
   connect(ShowGrapic,SIGNAL(ButtonhideReal3()),this,SLOT(ButtonhideReal3()));
   connect(ShowGrapic,SIGNAL(ButtonhideReal4()),this,SLOT(ButtonhideReal4()));
   connect(ShowGrapic,SIGNAL(ButtonhideReal5()),this,SLOT(ButtonhideReal5()));

   connect(ShowGrapic,SIGNAL(uttonshowReal()),this,SLOT(uttonshowReal()));
   connect(ShowGrapic,SIGNAL(uttonshowReal1()),this,SLOT(uttonshowReal1()));
   connect(ShowGrapic,SIGNAL(uttonshowReal2()),this,SLOT(uttonshowReal2()));
   connect(ShowGrapic,SIGNAL(uttonshowReal3()),this,SLOT(uttonshowReal3()));
   connect(ShowGrapic,SIGNAL(uttonshowReal4()),this,SLOT(uttonshowReal4()));
   connect(ShowGrapic,SIGNAL(uttonshowReal5()),this,SLOT(uttonshowReal5()));

   connect(ShowGrapic,SIGNAL(uttonhideReal()),this,SLOT(uttonhideReal()));
   connect(ShowGrapic,SIGNAL(uttonhideReal1()),this,SLOT(uttonhideReal1()));
   connect(ShowGrapic,SIGNAL(uttonhideReal2()),this,SLOT(uttonhideReal2()));
   connect(ShowGrapic,SIGNAL(uttonhideReal3()),this,SLOT(uttonhideReal3()));
   connect(ShowGrapic,SIGNAL(uttonhideReal4()),this,SLOT(uttonhideReal4()));
   connect(ShowGrapic,SIGNAL(uttonhideReal5()),this,SLOT(uttonhideReal5()));




}

void MainMenu::savehanle()
{
    emit setStart1();

}

void MainMenu::stopvalue()
{
    StopdataThread();
    netisconnect = false;

}

void MainMenu::startvalue()
{
    netisconnect = true;
}

void MainMenu::isSavedatame()
{
    emit savedata();
}


void MainMenu::SelfTestBegin(){

    if(newselfestpage ==NULL)
    {
        newselfestpage = new newSelfTestpage(selfTestAss,
                                             FanCreat,PumpCreat,
                                             TECCreat,ElecCreat);

        newselfestpage->start();
    }

}

void MainMenu::SelfTestStop(){

    if(newselfestpage !=NULL)
    {
        newselfestpage->terminate();
        newselfestpage->wait();
        newselfestpage =NULL;
    }

}

void MainMenu::ButtonshowReal(){
    TECrealgraphicTemp[0]->show();
}
void MainMenu::ButtonshowReal1(){
    TECrealgraphicTemp[1]->show();
}
void MainMenu::ButtonshowReal2(){
    TECrealgraphicTemp[2]->show();
}
void MainMenu::ButtonshowReal3(){
    TECrealgraphicTemp[3]->show();
}
void MainMenu::ButtonshowReal4(){
    TECrealgraphicTemp[4]->show();
}
void MainMenu::ButtonshowReal5(){
    TECrealgraphicTemp[5]->show();
}


void MainMenu::ButtonhideReal()
{
    TECrealgraphicTemp[0]->hide();
}
void MainMenu::ButtonhideReal1()
{
    TECrealgraphicTemp[1]->hide();
}
void MainMenu::ButtonhideReal2()
{
    TECrealgraphicTemp[2]->hide();
}
void MainMenu::ButtonhideReal3()
{
    TECrealgraphicTemp[3]->hide();
}

void MainMenu::ButtonhideReal4()
{
    TECrealgraphicTemp[4]->hide();
}
void MainMenu::ButtonhideReal5()
{
    TECrealgraphicTemp[5]->hide();
}



void MainMenu::uttonshowReal(){
    TECrealgraphicDuty[0]->show();
}
void MainMenu::uttonshowReal1(){
    TECrealgraphicDuty[1]->show();
}
void MainMenu::uttonshowReal2(){
    TECrealgraphicDuty[2]->show();
}
void MainMenu::uttonshowReal3(){
    TECrealgraphicDuty[3]->show();
}
void MainMenu::uttonshowReal4(){
    TECrealgraphicDuty[4]->show();
}
void MainMenu::uttonshowReal5(){
    TECrealgraphicDuty[5]->show();
}


void MainMenu::uttonhideReal(){
    TECrealgraphicDuty[0]->hide();
}
void MainMenu::uttonhideReal1(){
    TECrealgraphicDuty[1]->hide();
}
void MainMenu::uttonhideReal2(){
    TECrealgraphicDuty[2]->hide();
}
void MainMenu::uttonhideReal3(){
    TECrealgraphicDuty[3]->hide();
}
void MainMenu::uttonhideReal4(){
    TECrealgraphicDuty[4]->hide();
}
void MainMenu::uttonhideReal5(){
    TECrealgraphicDuty[5]->hide();
}



void MainMenu::pushButtonhideReal()
{
    Fanrealgraphic[0]->hide();
}
void MainMenu::pushButtonhideReal1()
{
    Fanrealgraphic[1]->hide();
}
void MainMenu::pushButtonhideReal2()
{
    Fanrealgraphic[2]->hide();
}
void MainMenu::pushButtonhideReal3()
{
    Fanrealgraphic[3]->hide();
}
void MainMenu::pushButtonhideReal4()
{
    Fanrealgraphic[4]->hide();
}
void MainMenu::pushButtonhideReal5()
{
    Fanrealgraphic[5]->hide();
}
void MainMenu::pushButtonhideReal6()
{
    Fanrealgraphic[6]->hide();
}
void MainMenu::pushButtonhideReal7()
{
    Fanrealgraphic[7]->hide();
}
void MainMenu::pushButtonhideReal8()
{
    Fanrealgraphic[8]->hide();
}
void MainMenu::pushButtonhideReal9()
{
    Fanrealgraphic[9]->hide();
}
void MainMenu::pushButtonhideReal10()
{
    Fanrealgraphic[10]->hide();
}
void MainMenu::pushButtonhideReal11()
{
    Fanrealgraphic[11]->hide();
}
void MainMenu::pushButtonhideReal12()
{
    Fanrealgraphic[12]->hide();
}
void MainMenu::pushButtonhideReal13()
{
    Fanrealgraphic[13]->hide();
}
void MainMenu::pushButtonhideReal14()
{
    Fanrealgraphic[14]->hide();
}
void MainMenu::pushButtonhideReal15()
{
    Fanrealgraphic[15]->hide();
}
void MainMenu::pushButtonhideReal16()
{
    Fanrealgraphic[16]->hide();
}
void MainMenu::pushButtonhideReal17()
{
    Fanrealgraphic[17]->hide();
}
void MainMenu::pushButtonhideReal18()
{
    Fanrealgraphic[18]->hide();
}
void MainMenu::pushButtonhideReal19()
{
    Fanrealgraphic[19]->hide();
}


void MainMenu::pushButtonshowReal()
{
    Fanrealgraphic[0]->show();
}
void MainMenu::pushButtonshowReal1()
{
    Fanrealgraphic[1]->show();
}
void MainMenu::pushButtonshowReal2()
{
    Fanrealgraphic[2]->show();
}
void MainMenu::pushButtonshowReal3()
{
    Fanrealgraphic[3]->show();
}
void MainMenu::pushButtonshowReal4()
{
    Fanrealgraphic[4]->show();
}
void MainMenu::pushButtonshowReal5()
{
    Fanrealgraphic[5]->show();
}
void MainMenu::pushButtonshowReal6()
{
    Fanrealgraphic[6]->show();
}
void MainMenu::pushButtonshowReal7()
{
    Fanrealgraphic[7]->show();
}
void MainMenu::pushButtonshowReal8()
{
    Fanrealgraphic[8]->show();
}
void MainMenu::pushButtonshowReal9()
{
    Fanrealgraphic[9]->show();
}

void MainMenu::pushButtonshowReal10()
{
    Fanrealgraphic[10]->show();
}
void MainMenu::pushButtonshowReal11()
{
    Fanrealgraphic[11]->show();
}
void MainMenu::pushButtonshowReal12()
{
    Fanrealgraphic[12]->show();
}
void MainMenu::pushButtonshowReal13()
{
    Fanrealgraphic[13]->show();
}
void MainMenu::pushButtonshowReal14()
{
    Fanrealgraphic[14]->show();
}
void MainMenu::pushButtonshowReal15()
{
    Fanrealgraphic[15]->show();
}
void MainMenu::pushButtonshowReal16()
{
    Fanrealgraphic[16]->show();
}
void MainMenu::pushButtonshowReal17()
{
    Fanrealgraphic[17]->show();
}
void MainMenu::pushButtonshowReal18()
{
    Fanrealgraphic[18]->show();
}
void MainMenu::pushButtonshowReal19()
{
    Fanrealgraphic[19]->show();
}


//更新需要保存的数据
void MainMenu::renewData(){
    emit sendnewData(FanDataMatrix,FanJsonMatrix,PumpJsonMatrix,TECJsonMatrix,ElecJsonMatrix,TECDataMatrix);
}

//实时发送页面内容做自动检测,自动测试阶段无法被打断
void MainMenu::SendAllPageconfigStart()
{
    if(selftEstrun==NULL)
    {
        selftEstrun = new SelfTestrunThread(ControlMenu,selftestnewTime);
        selftEstrun->start();
    }

}


void MainMenu::SendAllPageconfigStop()
{
    if(selftEstrun!=NULL)
    {
        selftEstrun->terminate();
        selftEstrun->wait();
        delete selftEstrun;
        selftEstrun =NULL;

    }

}

//新自动测试时间
void MainMenu::SendTestRunTime(double value)
{
    selftestnewTime = value;
}
//新自动测试举证
void MainMenu::SelfTestArraysend(std::vector<std::vector<int>> Arrays)
{
    selfTestAss = Arrays;
}

void MainMenu::SendAllPageconfig(bool value)
{
    for(int i = 0 ;i<ceil(SelfTestRunTime/200);i++)
    {
        if(ControlMenu->UartPort->serial.isOpen())
        {
            ControlMenu->UartPort->on_btn_led1_Ctrl_2_clicked();
        }
        if(ControlMenu->NetWorkClient->tcpClient->isOpen())
        {
            ControlMenu->NetWorkClient->on_actSendAll_triggered();
        }
    }
}








/****************************************************停止当前页面所有的线程**************************************************/

void MainMenu::showSelfTestWindow()
{
    SelfTest->hide();
    newselfTest->show();
}

void MainMenu::hideSelfTestWindow()
{
    SelfTest->hide();
    newselfTest->hide();
}


void MainMenu::showReal()
{
    ShowGrapic->show();
}

void MainMenu::hideReal()
{
    ShowGrapic->hide();
}

void MainMenu::showPageConfig()
{
    this->show();
}

void MainMenu::hidePageConfig()
{
    this->hide();
}


void MainMenu::StopEveryThread()
{
    //停止Uart垂询线程
    if(TempUart!=NULL){
        RecieveRealtimeValuewithUart(false);
    }
    ControlMenu->UartPort->serial.close();

    //停止TCP
    if(TempTCP!=NULL){
        RecieveRealtimeValuewithTCPNetWork(false);
    }
    ControlMenu->NetWorkClient->tcpClient->close();

    //停止数据保存线程
    if(SavedataThread!=NULL){
        StopdataThread();
    }
    //停止自动测试
    if(newselfestpage != NULL)
    {
        SelfTestStop();
    }
    //停止页面配置进程
    if(selftEstrun !=NULL)
    {
        SendAllPageconfigStop();
    }


}

/******************************************************通过Uart实时数据更新********************************************************/
//通过Uart捕获实时的数据反馈模式设置
void MainMenu::RecieveRealtimeValuewithUart(bool value)
{

       if(value && TempUart==NULL)
       {
         TempUart = new RealtimeValueFromUart(ControlMenu,value);
         TempUart->start();

         //默认模式
         connect(TempUart,SIGNAL(DefaultModeRealTimeValue()),this,SLOT(DefaultModeRealTimeValue()));
         connect(this,SIGNAL(SendDefualtModeinRunningFalse()),TempUart,SLOT(SendDefualtModeinRunningFalse()));

         //手动单行模式
         connect(ControlMenu->UartPort,SIGNAL(SendSingleCodeWithUart()),TempUart,SLOT(SetSingleCoceMode()));//设置为单行命令发送模式
         connect(TempUart,SIGNAL(SingleCoceModeRealTimeValue()),ControlMenu->UartPort,SLOT(SingleCoceModeRealTimeValue()));
         connect(ControlMenu->UartPort,SIGNAL(SingleCoceModeisRunningFalse()),TempUart,SLOT(SingleCoceModeisRunningFalse()));//单行命令模式结束信号
         connect(ControlMenu->UartPort,SIGNAL(LiveSingleCoceMode()),TempUart,SLOT(LiveSingleCoceMode()));

         //全页面模式
         connect(ControlMenu->UartPort,SIGNAL(SendPageCodeWithUart()),TempUart,SLOT(SetPageCodeMode()));
         //切换到mainmenu上运行
         connect(TempUart,SIGNAL(PageCodeModeRealTimeValue()),this,SLOT(sendAllPageConfigwithUart()));
         connect(this,SIGNAL(SendAllModeinRunningFalse()),TempUart,SLOT(SendAllModeinRunningFalse()));//单行运行结束操作
         connect(this,SIGNAL(LivePageCodeMode()),TempUart,SLOT(LivePageCodeMode()));

       }

       if(value == false && TempUart!=NULL)
       {
         //禁止用户操作开关按钮1秒钟保护线程完全退出
         TempUart->stop();
         TempUart->quit();
         TempUart->wait();
         emit ForbidenOpen();
         delete TempUart;
         TempUart = NULL;
      }
}

//通过Uart发送所有控制界面的配置
void MainMenu::sendAllPageConfigwithUart()
{
    ControlMenu->UartPort->ReceiveCode1=false;
    ControlMenu->UartPort->ReceiveCode2=false;
    ControlMenu->UartPort->ReceiveCode3=false;
    //发送1-8风扇配置
    for(int i = 0; i<8;i++)
    {
        if(FanJsonMatrix[i][0] !=0)
        {
            QString ATCode_Value = QString("AT+SetVoltage=Fan%1,%2\r\n").arg(FanJsonMatrix[i][0]).arg(FanJsonMatrix[i][3]*1000);

            QByteArray tx_buf_tmp = ATCode_Value.toLocal8Bit();
            ControlMenu->UartPort->serial.write(tx_buf_tmp);     //把数据通过串口发送出去
            QEventLoop loop;
            QTimer::singleShot(200, &loop, SLOT(quit()));
            loop.exec();
        }
    }
    //发送9-20风扇配置
    for(int i = 8; i<20;i++)
    {
        if(FanJsonMatrix[i][0] !=0)
        {
            QString ATCode_Value = QString("AT+SetDuty=Fan%1,%2\r\n").arg(FanJsonMatrix[i][0]).arg(FanJsonMatrix[i][3]*10);

            QByteArray tx_buf_tmp = ATCode_Value.toLocal8Bit();
            ControlMenu->UartPort->serial.write(tx_buf_tmp);     //把数据通过串口发送出去
            QEventLoop loop;
            QTimer::singleShot(200, &loop, SLOT(quit()));
            loop.exec();
        }
    }


    //发送水泵配置
    for(int i = 0; i<16;i++)
    {
        if(PumpJsonMatrix[i][0] !=0)
        {
            QString ATCode_Value = QString("AT+SetVoltage=Pump,%1\r\n").arg(PumpJsonMatrix[i][1]*1000);
            QByteArray tx_buf_tmp = ATCode_Value.toLocal8Bit();
            ControlMenu->UartPort->serial.write(tx_buf_tmp);     //把数据通过串口发送出去

            QEventLoop loop;
            QTimer::singleShot(100, &loop, SLOT(quit()));//根据现象更改时间
            loop.exec();
        }
    }
    //发送TEC配置
    for(int i = 0; i<16;i++)
    {
        if(TECJsonMatrix[i][0] !=0)
        {
            QString ATCode_Value = QString("AT+SetTemp=Tec%1,%2\r\n").arg(TECJsonMatrix[i][0]).arg(TECJsonMatrix[i][1]*10);
            QByteArray tx_buf_tmp = ATCode_Value.toLocal8Bit();
            ControlMenu->UartPort->serial.write(tx_buf_tmp);     //把数据通过串口发送出去

            QEventLoop loop;
            QTimer::singleShot(100, &loop, SLOT(quit()));
            loop.exec();
        }
    }


    //TEC电压配置
    for(int i = 0; i<16;i++)
    {
        if(TECJsonMatrix[i][0] !=0)
        {
            //发送电压配置
            QString ATCode_Value0 = QString("AT+SetVoltage=Tec%1,%2\r\n").arg(TECJsonMatrix[i][0]).arg(TECJsonMatrix[i][2]*1000);
            QByteArray tx_buf_tmp0 = ATCode_Value0.toLocal8Bit();
            ControlMenu->NetWorkClient->tcpClient->write(tx_buf_tmp0);

            QEventLoop loop;
            QTimer::singleShot(200, &loop, SLOT(quit()));
            loop.exec();
        }
    }

//  发送Elec配置需要根据需求更改
    for(int i = 0; i<16;i++)
    {
        if(ElecJsonMatrix[i][0] !=0)
        {
            switch (ElecJsonMatrix[i][0]) {
              case 1:
                ControlMenu->UartPort->serial.write(QString("AT+SetCurrent=Laser1,%1\r\n")\
                                                          .arg(ElecJsonMatrix[i][1]*10).toLocal8Bit());
                break;
              case 2:
                ControlMenu->UartPort->serial.write(QString("AT+SetCurrent=Laser2,%1\r\n")\
                                                          .arg(ElecJsonMatrix[i][1]*10).toLocal8Bit());
                break;
              case 3:
                ControlMenu->UartPort->serial.write(QString("AT+SetCurrent=GreenLaser,%1\r\n")\
                                                          .arg(ElecJsonMatrix[i][1]*10).toLocal8Bit());
                break;
              case 4:
                ControlMenu->UartPort->serial.write(QString("AT+SetCurrent=RedLaser,%1\r\n")\
                                                          .arg(ElecJsonMatrix[i][1]*10).toLocal8Bit());
                break;
              default:
                break;
              }

            QEventLoop loop;
            QTimer::singleShot(100, &loop, SLOT(quit()));
            loop.exec();
        }
    }
    emit LivePageCodeMode();
    emit SendAllModeinRunningFalse();
}

//通过Uart默认模式实时垂询
void MainMenu::DefaultModeRealTimeValue()
{
    ControlMenu->UartPort->ReceiveCode1 = true;

    if(ControlMenu->UartPort->serial.isOpen()){
        ControlMenu->UartPort->serial.write(ControlMenu->UartPort->ATCode_Value1.toUtf8().data());
        //此模块可以以锁的形式替换有一定风险
        QEventLoop loop;
        QTimer::singleShot(200, &loop, SLOT(quit()));
        loop.exec();
        ControlMenu->UartPort->ReceiveCode1 = false;

        ControlMenu->UartPort->ReceiveCode2 = true;
        ControlMenu->UartPort->serial.write(ControlMenu->UartPort->ATCode_Value2.toUtf8().data());
        QTimer::singleShot(200, &loop, SLOT(quit()));
        loop.exec();
        ControlMenu->UartPort->ReceiveCode2 = false;

        ControlMenu->UartPort->ReceiveCode3 = true;
        ControlMenu->UartPort->serial.write(ControlMenu->UartPort->ATCode_Value3.toUtf8().data());
        QTimer::singleShot(200, &loop, SLOT(quit()));
        loop.exec();
        ControlMenu->UartPort->ReceiveCode3 = false;
    }
    emit SendDefualtModeinRunningFalse();
}

//通过Uart实时更新界面的实际数据
void MainMenu::RealTimeFanSpeedSet(int FanId,QString Speed)
{
    if(FanCreat[FanId]!=NULL)
    {FanCreat[FanId]->setFanRealtimeSpeed(Speed);}
}

void MainMenu::RealTimeNtcTempratureSet(int TECId,QString Temperature)
{
    if(TECCreat[TECId]!=NULL)
    {TECCreat[TECId]->setTECRealtimeTemparature(Temperature);}
}

void MainMenu::RealTimeTECDutySet(int TECId,QString Duty)
{
    if(TECCreat[TECId]!=NULL)
    {TECCreat[TECId]->setRealTimeTECDuty(Duty);}
}

/******************************************************通过TCPNetWork实时数据更新********************************************************/
//通过TCP捕获实时的数据反馈模式设置
void MainMenu::RecieveRealtimeValuewithTCPNetWork(bool value)
{
    if(value && TempTCP==NULL)
    {
      TempTCP = new RealtimeValueForTCP(ControlMenu,value);
      TempTCP->start();

      //默认模式
      connect(TempTCP,SIGNAL(TCPDefaultModeRealTimeValue()),this,SLOT(TCPNetWorkDefaultModeRealTimeValue()));
      connect(this,SIGNAL(TCPSendDefualtModeinRunningFalse()),TempTCP,SLOT(TCPSendDefualtModeinRunningFalse()));

      //手动单行模式
      connect(ControlMenu->NetWorkClient,SIGNAL(TCPSendSingleCodeWithUart()),TempTCP,SLOT(TCPSetSingleCoceMode()));//设置为单行命令发送模式
      connect(TempTCP,SIGNAL(TCPSingleCoceModeRealTimeValue()),ControlMenu->NetWorkClient,SLOT(TCPSingleCoceModeRealTimeValue()));
      connect(ControlMenu->NetWorkClient,SIGNAL(TCPSingleCoceModeisRunningFalse()),TempTCP,SLOT(TCPSingleCoceModeisRunningFalse()));//单行命令模式结束信号
      connect(ControlMenu->NetWorkClient,SIGNAL(TCPLiveSingleCoceMode()),TempTCP,SLOT(TCPLiveSingleCoceMode()));

      //全页面模式
      connect(ControlMenu->NetWorkClient,SIGNAL(TCPSendPageCodeWithUart()),TempTCP,SLOT(TCPSetPageCodeMode()));
      connect(TempTCP,SIGNAL(TCPPageCodeModeRealTimeValue()),this,SLOT(sendAllPageConfigwithTCPNetWork()));
      connect(this,SIGNAL(TCPSendAllModeinRunningFalse()),TempTCP,SLOT(TCPSendAllModeinRunningFalse()));//单行运行结束操作
      connect(this,SIGNAL(TCPLivePageCodeMode()),TempTCP,SLOT(TCPLivePageCodeMode()));
    }

    if(value == false && TempTCP!=NULL)
    {
      //禁止用户操作开关按钮1秒钟保护线程完全退出
      TempTCP->stop();
      TempTCP->terminate();
      TempTCP->wait();
      emit TCPForbidenOpen();
      delete TempTCP;
      TempTCP = NULL;
   }
}

//通过TCP发送所有控制界面的配置
void MainMenu::sendAllPageConfigwithTCPNetWork()
{
    ControlMenu->NetWorkClient->ReceiveCode1=false;
    ControlMenu->NetWorkClient->ReceiveCode2=false;
    ControlMenu->NetWorkClient->ReceiveCode3=false;
    //发送风扇配置

    for(int i = 0; i<8;i++)
    {
        if(FanJsonMatrix[i][0] !=0)
        {
            QString ATCode_Value = QString("AT+SetVoltage=Fan%1,%2\r\n").arg(FanJsonMatrix[i][0]).arg(FanJsonMatrix[i][3]*1000);

            QByteArray tx_buf_tmp = ATCode_Value.toLocal8Bit();
            ControlMenu->NetWorkClient->tcpClient->write(tx_buf_tmp);//把数据通过串口发送出去

            QEventLoop loop;
            QTimer::singleShot(200, &loop, SLOT(quit()));
            loop.exec();
        }
    }
    //发送9-20风扇配置
    for(int i = 8; i<20;i++)
    {
        if(FanJsonMatrix[i][0] !=0)
        {
            QString ATCode_Value = QString("AT+SetDuty=Fan%1,%2\r\n").arg(FanJsonMatrix[i][0]).arg(FanJsonMatrix[i][3]*10);

            QByteArray tx_buf_tmp = ATCode_Value.toLocal8Bit();
            ControlMenu->NetWorkClient->tcpClient->write(tx_buf_tmp);//把数据通过串口发送出去

            QEventLoop loop;
            QTimer::singleShot(200, &loop, SLOT(quit()));
            loop.exec();
        }
    }
    //发送水泵配置
    for(int i = 0; i<16;i++)
    {
        if(PumpJsonMatrix[i][0] !=0)
        {
            QString ATCode_Value = QString("AT+SetVoltage=Pump,%1\r\n").arg(PumpJsonMatrix[i][1]*1000);
            QByteArray tx_buf_tmp = ATCode_Value.toLocal8Bit();
            ControlMenu->NetWorkClient->tcpClient->write(tx_buf_tmp);

            QEventLoop loop;
            QTimer::singleShot(200, &loop, SLOT(quit()));//根据现象更改时间
            loop.exec();
        }
    }
    //发送TEC配置
    for(int i = 0; i<16;i++)
    {
        if(TECJsonMatrix[i][0] !=0)
        {
            QString ATCode_Value = QString("AT+SetTemp=Tec%1,%2\r\n").arg(TECJsonMatrix[i][0]).arg(TECJsonMatrix[i][1]*10);
            QByteArray tx_buf_tmp = ATCode_Value.toLocal8Bit();
            ControlMenu->NetWorkClient->tcpClient->write(tx_buf_tmp);

            QEventLoop loop;
            QTimer::singleShot(200, &loop, SLOT(quit()));
            loop.exec();
        }
    }
//  发送Elec配置需要根据需求更改
    for(int i = 0; i<16;i++)
    {
        if(ElecJsonMatrix[i][0] !=0)
        {
            switch (ElecJsonMatrix[i][0]) {
              case 1:
                ControlMenu->NetWorkClient->tcpClient->write(QString("AT+SetCurrent=Laser1,%1\r\n")\
                                                          .arg(ElecJsonMatrix[i][1]*10).toLocal8Bit());
                break;
              case 2:
                ControlMenu->NetWorkClient->tcpClient->write(QString("AT+SetCurrent=Laser2,%1\r\n")\
                                                          .arg(ElecJsonMatrix[i][1]*10).toLocal8Bit());
                break;
              case 3:
                ControlMenu->NetWorkClient->tcpClient->write(QString("AT+SetCurrent=GreenLaser,%1\r\n")\
                                                          .arg(ElecJsonMatrix[i][1]*10).toLocal8Bit());
                break;
              case 4:
                ControlMenu->NetWorkClient->tcpClient->write(QString("AT+SetCurrent=RedLaser,%1\r\n")\
                                                          .arg(ElecJsonMatrix[i][1]*10).toLocal8Bit());
                break;
              default:
                break;
              }

            QEventLoop loop;
            QTimer::singleShot(200, &loop, SLOT(quit()));
            loop.exec();
        }
    }
    emit TCPLivePageCodeMode();
    emit TCPSendAllModeinRunningFalse();
}



void MainMenu::StopdataThread()
{

    if(SavedataThread!= NULL)
    {
        SavedataThread->setStop();
        SavedataThread->terminate();
        SavedataThread->wait();
        delete SavedataThread;
        SavedataThread=NULL;
    }
    if(netisconnect==false)
    {
        QMessageBox::warning(this,tr("警告"),tr("由于之前没有开启网口所以没有开启数据保存线程！请在链接了网口后，重新点按保存数据按钮！"),\
                                 QMessageBox::Ok);
    }
}


void MainMenu::DATAsave()
{

    if(netisconnect){
        if(SavedataThread == NULL){
           SavedataThread = new savedatathread(ControlMenu);
           SavedataThread->start();

           connect(SavedataThread,SIGNAL(renewData()),this,SLOT(renewData()));
           connect(this,SIGNAL(sendnewData(std::vector<std::vector<int>>,std::vector<std::vector<int>>,std::vector<std::vector<int>>
                                           ,std::vector<std::vector<int>>,std::vector<std::vector<int>>,std::vector<std::vector<int>>))
                   ,SavedataThread,SLOT(receivenewData(std::vector<std::vector<int>>,std::vector<std::vector<int>>,std::vector<std::vector<int>>
                                                       ,std::vector<std::vector<int>>,std::vector<std::vector<int>>,std::vector<std::vector<int>>)));
           connect(ControlMenu->UartPort,SIGNAL(savehandle()),SavedataThread,SLOT(handlesave()));
           connect(SavedataThread,SIGNAL(isSavedatame()),this,SLOT(isSavedatame()));
           connect(this,SIGNAL(savedata()),SavedataThread,SLOT(savedata()));
         }

    }
    else{
        QMessageBox::warning(this,tr("警告"),tr("请先打开网口链接，当前不会保存任何数据！"),\
                                 QMessageBox::Ok);



    }
    

}











//通过TCP默认模式实时垂询
void MainMenu::TCPNetWorkDefaultModeRealTimeValue()
{

    ControlMenu->NetWorkClient->ReceiveCode1 = true;

    if(ControlMenu->NetWorkClient->tcpClient->isOpen()){
        ControlMenu->NetWorkClient->tcpClient->write(ControlMenu->NetWorkClient->ATCode_Value1.toLocal8Bit());
        QEventLoop loop;//此模块可以以锁的形式替换有一定风险
        QTimer::singleShot(500, &loop, SLOT(quit()));
        loop.exec();
        ControlMenu->NetWorkClient->ReceiveCode1 = false;

        ControlMenu->NetWorkClient->ReceiveCode2 = true;
        ControlMenu->NetWorkClient->tcpClient->write(ControlMenu->NetWorkClient->ATCode_Value2.toLocal8Bit());
        QTimer::singleShot(500, &loop, SLOT(quit()));
        loop.exec();
        ControlMenu->NetWorkClient->ReceiveCode2 = false;

        ControlMenu->NetWorkClient->ReceiveCode3 = true;
        ControlMenu->NetWorkClient->tcpClient->write(ControlMenu->NetWorkClient->ATCode_Value3.toLocal8Bit());
        QTimer::singleShot(500, &loop, SLOT(quit()));
        loop.exec();
        ControlMenu->NetWorkClient->ReceiveCode3 = false;
    }
    emit TCPSendDefualtModeinRunningFalse();
}

//通过TCP实时更新界面的实际数据
void MainMenu::TCPNetWorkRealTimeFanSpeedSet(int FanId,QString Speed)
{
    if(FanCreat[FanId]!=NULL)
    {
        FanDataMatrix[FanId][1] = Speed.toInt();

        //更改数据图像
        Fanrealgraphic[FanId]->realtimevalue =  Speed.toInt();
        FanCreat[FanId]->TCPsetFanRealtimeSpeed(Speed);}
}
void MainMenu::TCPRealTimeNtcTempratureSet(int TECId,QString Temperature)
{
    if(TECCreat[TECId]!=NULL)
    {   TECDataMatrix[TECId][0] = Temperature.toInt();
        TECrealgraphicTemp[TECId]->realtimevalue = Temperature.toInt();
        TECCreat[TECId]->TCPsetTECRealtimeTemparature(Temperature);}
}
void MainMenu::TCPRealTimeTECDutySet(int TECId,QString Duty)
{
    if(TECCreat[TECId]!=NULL)
    {   TECDataMatrix[TECId][1] = Duty.toInt();
        TECrealgraphicDuty[TECId]->realtimevalue = Duty.toInt();
        TECCreat[TECId]->TCPsetRealTimeTECDuty(Duty);}
}

/***********************************************************除控制界面避免文本配置与手动配置冲突****************************************************************/

//清除控制界面避免文本配置与手动配置冲突
void MainMenu::ClearMenu()
{
    for(int i = 1;i<21;i++)
    {
        FanIDUnChecked(i);
    }

    for(int i = 1;i<4;i++)
    {
        PumpIDUnChecked(i);
    }

    for(int i = 1;i<7;i++)
    {
        TECIDUnChecked(i);
    }

    for(int i = 1;i<4;i++)
    {
        ElecIDUnChecked(i);
    }


}

void MainMenu::SetUsefulTwen()
{
    ui->comboBox->setEnabled(true);
    ui->comboBox->setCurrentIndex(1);
}

void MainMenu::SetUsefulTel()
{
     ui->comboBox->setEnabled(true);
     ui->comboBox->setCurrentIndex(0);
}

//自动检测时间
void MainMenu::SetTestRunTime(double value)
{
    SelfTestRunTime = value;
}

//设置自动检测的值
void MainMenu::SetFanminComp(int Id,int min)
{
    SelfTestMatrix[Id-1][1]=min;
}

void MainMenu::SetFanmaxComp(int Id,int max)
{
    SelfTestMatrix[Id-1][2]=max;
}

void MainMenu::SetFanstepComp(int Id,int step)
{
    SelfTestMatrix[Id-1][3]=step;
}

//设置水泵自动检测的值
void MainMenu::SetPumpminComp(int Id,int min)
{
    SelfTestPumpMatrix[Id-1][1]=min;
}

void MainMenu::SetPumpmaxComp(int Id,int max)
{
    SelfTestPumpMatrix[Id-1][2]=max;
}

void MainMenu::SetPumpstepComp(int Id,int step)
{
    SelfTestPumpMatrix[Id-1][3]=step;
}

//设置TEC自动检测的值
void MainMenu::SetTECminComp(int Id,int min)
{
    SelfTestTECMatrix[Id-1][1]=min;
}
void MainMenu::SetTECmaxComp(int Id,int max)
{
    SelfTestTECMatrix[Id-1][2]=max;
}
void MainMenu::SetTECstepComp(int Id,int step)
{
    SelfTestTECMatrix[Id-1][3]=step;
}

//设置Elec自动检测的值
void MainMenu::SetElecminComp(int Id,int min)
{
    SelfTestElecMatrix[Id-1][1]=min;
}
void MainMenu::SetElecmaxComp(int Id,int max)
{
    SelfTestElecMatrix[Id-1][2]=max;
}
void MainMenu::SetElecstepComp(int Id,int step)
{
    SelfTestElecMatrix[Id-1][3]=step;
}





//新的自动测试
void MainMenu::StartSelfTestThread()
{
    /*******************运行阶段出现再次点按的情况需要停止所有线程******************************************/
    //风扇的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<20;i++)
    {
        if(newFanSelfTest[i]!=NULL)
        {
            newFanSelfTest[i]->terminate();
            newFanSelfTest[i]->wait();
        }
    }

    //水泵的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<3;i++)
    {
       if(newPumpSelfTest[i]!=NULL)
       {
          newPumpSelfTest[i]->terminate();
          newPumpSelfTest[i]->wait();
       }
    }

    //TEC的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<6;i++)
    {
       if(newTECSelfTest[i]!=NULL)
       {
          newTECSelfTest[i]->terminate();
          newTECSelfTest[i]->wait();
       }
    }

    //Elec的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<4;i++)
    {
       if(newElecSelfTest[i]!=NULL)
       {
          newElecSelfTest[i]->terminate();
          newElecSelfTest[i]->wait();
       }
    }


    for(int i = 0;i<20;i++)
    {
        if(SelfTestMatrix[i][0] && selfTestAss[i][0])
        {
            newFanSelfTest[i] = new MyNewQThreadForSelf(FanCreat[i],selftestnewTime,SelfTestMatrix[i][0],selfTestAss[i]);
            newFanSelfTest[i]->start();

        }
    }

    for(int i = 0;i<3;i++)
    {
        if(SelfTestPumpMatrix[i][0]&&selfTestAss[i+20][0])
        {
            newPumpSelfTest[i] = new MyNewQThreadForSelf(PumpCreat[i],selftestnewTime,SelfTestPumpMatrix[i][0],selfTestAss[i+20]);
            newPumpSelfTest[i]->start();
        }
    }

    for(int i = 0;i<6;i++)
    {
        if(SelfTestTECMatrix[i][0]&&selfTestAss[i+21][0])
        {
            newTECSelfTest[i] = new MyNewQThreadForSelf(TECCreat[i],selftestnewTime,SelfTestTECMatrix[i][0],selfTestAss[i+21]);
            newTECSelfTest[i]->start();
        }
    }

    for(int i = 0;i<4;i++)
    {
        if(SelfTestElecMatrix[i][0]&&selfTestAss[i+27][0])
        {
            newElecSelfTest[i] = new MyNewQThreadForSelf(ElecCreat[i],selftestnewTime,SelfTestElecMatrix[i][0],selfTestAss[i+27]);
            newElecSelfTest[i]->start();
        }
    }

}

void MainMenu::StopSelfTestThread()
{
//    qDebug()<<"wolrd";

    for(int i = 0;i<20;i++)
    {
        if(newFanSelfTest[i]!=NULL)
        {
            newFanSelfTest[i]->terminate();
            newFanSelfTest[i]->wait();
        }
    }

//    水泵的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<3;i++)
    {
       if(newPumpSelfTest[i]!=NULL)
       {
          newPumpSelfTest[i]->terminate();
          newPumpSelfTest[i]->wait();
       }
    }

//    TEC的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<6;i++)
    {
       if(newTECSelfTest[i]!=NULL)
       {
          newTECSelfTest[i]->terminate();
          newTECSelfTest[i]->wait();
       }
    }

//    Elec的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<4;i++)
    {
       if(newElecSelfTest[i]!=NULL)
       {
          newElecSelfTest[i]->terminate();
          newElecSelfTest[i]->wait();
       }
    }
}




//根据配置的参数来更改对应参数
void MainMenu::SelfTestWithValue(bool value)
{
    /*******************运行阶段出现再次点按的情况需要停止所有线程******************************************/
    //风扇的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<20;i++)
    {
        if(FanSelfTest[i]!=NULL)
        {
            FanSelfTest[i]->terminate();
            FanSelfTest[i]->wait();
        }
    }

    //水泵的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<3;i++)
    {
       if(PumpSelfTest[i]!=NULL)
       {
          PumpSelfTest[i]->terminate();
          PumpSelfTest[i]->wait();
       }
    }

    //TEC的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<6;i++)
    {
       if(TECSelfTest[i]!=NULL)
       {
          TECSelfTest[i]->terminate();
          TECSelfTest[i]->wait();
       }
    }

    //Elec的自动调参模块（当点按多次时自动回复初始状态）
    for(int i = 0;i<4;i++)
    {
       if(ElecSelfTest[i]!=NULL)
       {
          ElecSelfTest[i]->terminate();
          ElecSelfTest[i]->wait();
       }
    }


    for(int i = 0;i<20;i++)
    {
        if(SelfTestMatrix[i][0])
        {
            FanSelfTest[i] = new MyNewQThread(FanCreat[i],SelfTestRunTime,SelfTestMatrix[i][0], \
                    SelfTestMatrix[i][1], SelfTestMatrix[i][2],SelfTestMatrix[i][3]);
             FanSelfTest[i]->start();
        }
    }

    for(int i = 0;i<3;i++)
    {
        if(SelfTestPumpMatrix[i][0])
        {
            PumpSelfTest[i] = new MyNewQThread(PumpCreat[i],SelfTestRunTime,SelfTestPumpMatrix[i][0], \
                    SelfTestPumpMatrix[i][1], SelfTestPumpMatrix[i][2],SelfTestPumpMatrix[i][3]);
            PumpSelfTest[i]->start();
        }
    }

    for(int i = 0;i<6;i++)
    {
        if(SelfTestTECMatrix[i][0])
        {
            TECSelfTest[i] = new MyNewQThread(TECCreat[i],SelfTestRunTime,SelfTestTECMatrix[i][0], \
                    SelfTestTECMatrix[i][1], SelfTestTECMatrix[i][2],SelfTestTECMatrix[i][3]);
            TECSelfTest[i]->start();
        }
    }

    for(int i = 0;i<4;i++)
    {
        if(SelfTestElecMatrix[i][0])
        {
            ElecSelfTest[i] = new MyNewQThread(ElecCreat[i],SelfTestRunTime,SelfTestElecMatrix[i][0], \
                    SelfTestElecMatrix[i][1], SelfTestElecMatrix[i][2],SelfTestElecMatrix[i][3]);
            ElecSelfTest[i]->start();
        }
    }

}

/*************************************根据风扇界面的操作来实现生成对应的Json配置文件***********************************************/

void MainMenu::SetElecMaxValue(int value,int value1)
{
    FanJsonMatrix[value-1][2] = value1;
}

void MainMenu::SetDucyValue(int value,int value1)
{
    FanJsonMatrix[value-1][3] = value1;
}

void MainMenu::SetPumpValue(int value,int value1)
{

    PumpJsonMatrix[value-1][1] = value1;
}

/****************************************根据Json解析的内容来画图**********************************************************/
void MainMenu::FanCreatWithJson(int FanID,int ContectType,int MaxElec,int FanDucy)
{

    bool value = FanIDisChecked(FanID);//检查当前的选项是否被勾选

    if(value)
    {
        FanIDUnChecked(FanID);//删除勾选的项
        FanCreat[FanID-1] = ControlMenu->Fan(FanID,ContectType,MaxElec,FanDucy);
        ControlMenu->FanMenuAdd(FanCreat[FanID-1],FanID);

        SelfTestCreat[FanID-1]=SelfTest->FanSelfTestWindow(FanID);
        SelfTest->EditSelfMenuAdd(SelfTestCreat[FanID-1],FanID);

        FanIDChecked(FanID);

    }
    else
    {
        FanCreat[FanID-1] = ControlMenu->Fan(FanID,ContectType,MaxElec,FanDucy);
        ControlMenu->FanMenuAdd(FanCreat[FanID-1],FanID);

        SelfTestCreat[FanID-1]=SelfTest->FanSelfTestWindow(FanID);
        SelfTest->EditSelfMenuAdd(SelfTestCreat[FanID-1],FanID);

        FanIDChecked(FanID);
    }
}

void MainMenu::PumpCreatWithJson(int PumpID,int ElecValue)
{

    bool value = PumpIDisChecked(PumpID);//检查当前的选项是否被勾选

    if(value)
    {
        PumpIDUnChecked(PumpID);//删除勾选的项
        PumpCreat[PumpID-1] = ControlMenu->Pump(PumpID,ElecValue);
        ControlMenu->PumpMenuAdd(PumpCreat[PumpID-1],PumpID);

        SelfTestPumpCreat[PumpID-1]=SelfTest->PumpSelfTestWindow(PumpID);
        SelfTest->EditSelfPumpMenuAdd(SelfTestPumpCreat[PumpID-1],PumpID);

        PumpIDChecked(PumpID);
    }
    else
    {
        PumpCreat[PumpID-1] = ControlMenu->Pump(PumpID,ElecValue);
        ControlMenu->PumpMenuAdd(PumpCreat[PumpID-1],PumpID);

        SelfTestPumpCreat[PumpID-1]=SelfTest->PumpSelfTestWindow(PumpID);
        SelfTest->EditSelfPumpMenuAdd(SelfTestPumpCreat[PumpID-1],PumpID);

        PumpIDChecked(PumpID);
    }

}

/*************************************************让风扇勾选状态改变*************************************************************/
void MainMenu::FanIDUnChecked(int FanID)
{

    switch (FanID) {
    case 1:
        ui->rb1->setChecked(false);
        break;
    case 2:
        ui->rb2->setChecked(false);
        break;
    case 3:
        ui->rb3->setChecked(false);
        break;
    case 4:
        ui->rb4->setChecked(false);
        break;
    case 5:
        ui->rb5->setChecked(false);
        break;
    case 6:
        ui->rb6->setChecked(false);
        break;
    case 7:
        ui->rb7->setChecked(false);
        break;
    case 8:
        ui->rb8->setChecked(false);
        break;
    case 9:
        ui->rb9->setChecked(false);
        break;
    case 10:
        ui->rb10->setChecked(false);
        break;
    case 11:
        ui->rb11->setChecked(false);
        break;
    case 12:
        ui->rb12->setChecked(false);
        break;
    case 13:
        ui->rb13->setChecked(false);
        break;
    case 14:
        ui->rb14->setChecked(false);
        break;
    case 15:
        ui->rb15->setChecked(false);
        break;
    case 16:
        ui->rb16->setChecked(false);
        break;
    case 17:
        ui->rb17->setChecked(false);
        break;
    case 18:
        ui->rb18->setChecked(false);
        break;
    case 19:
        ui->rb19->setChecked(false);
        break;
    case 20:
        ui->rb20->setChecked(false);
        break;
    default:
        break;
    }
}

/***********************************************************检测风扇是否被勾选******************************************************/
bool MainMenu::FanIDisChecked(int FanID)
{
    bool value = false;
    switch (FanID) {
    case 1:
        value =ui->rb1->isChecked();
        break;
    case 2:
        value =ui->rb2->isChecked();
        break;
    case 3:
        value =ui->rb3->isChecked();
        break;
    case 4:
        value =ui->rb4->isChecked();
        break;
    case 5:
        value =ui->rb5->isChecked();
        break;
    case 6:
        value =ui->rb6->isChecked();
        break;
    case 7:
        value =ui->rb7->isChecked();
        break;
    case 8:
        value =ui->rb8->isChecked();
        break;
    case 9:
        value =ui->rb9->isChecked();
        break;
    case 10:
        value =ui->rb10->isChecked();
        break;
    case 11:
        value =ui->rb11->isChecked();
        break;
    case 12:
        value =ui->rb12->isChecked();
        break;
    case 13:
        value =ui->rb13->isChecked();
        break;
    case 14:
        value =ui->rb14->isChecked();
        break;
    case 15:
        value =ui->rb15->isChecked();
        break;
    case 16:
        value =ui->rb16->isChecked();
        break;
    case 17:
        value =ui->rb17->isChecked();
        break;
    case 18:
        value =ui->rb18->isChecked();
        break;
    case 19:
        value =ui->rb19->isChecked();
        break;
    case 20:
        value =ui->rb20->isChecked();
        break;
    default:
        break;
    }
    return value;
}

/***************************************************设置被勾选的ID为Checked****************************************************/
void MainMenu::FanIDChecked(int FanID)
{
    switch (FanID) {
    case 1:
        ui->rb1->setChecked(true);
        break;
    case 2:
        ui->rb2->setChecked(true);
        break;
    case 3:
        ui->rb3->setChecked(true);
        break;
    case 4:
        ui->rb4->setChecked(true);
        break;
    case 5:
        ui->rb5->setChecked(true);
        break;
    case 6:
        ui->rb6->setChecked(true);
        break;
    case 7:
        ui->rb7->setChecked(true);
        break;
    case 8:
        ui->rb8->setChecked(true);
        break;
    case 9:
        ui->rb9->setChecked(true);
        break;
    case 10:
        ui->rb10->setChecked(true);
        break;
    case 11:
        ui->rb11->setChecked(true);
        break;
    case 12:
        ui->rb12->setChecked(true);
        break;
    case 13:
        ui->rb13->setChecked(true);
        break;
    case 14:
        ui->rb14->setChecked(true);
        break;
    case 15:
        ui->rb15->setChecked(true);
        break;
    case 16:
        ui->rb16->setChecked(true);
        break;
    case 17:
        ui->rb17->setChecked(true);
        break;
    case 18:
        ui->rb18->setChecked(true);
        break;
    case 19:
        ui->rb19->setChecked(true);
        break;
    case 20:
        ui->rb20->setChecked(true);
        break;
    default:
        break;
    }
}

/*************************************************让水泵勾选状态改变*************************************************************/
void MainMenu::PumpIDUnChecked(int PumpID)
{

    switch (PumpID) {
    case 1:
        ui->sb1->setChecked(false);
        break;
//    case 2:
//        ui->sb2->setChecked(false);
//        break;
//    case 3:
//        ui->sb3->setChecked(false);
//        break;
    default:
        break;
    }
}

/***********************************************************检测水泵是否被勾选******************************************************/
bool MainMenu::PumpIDisChecked(int PumpID)
{
    bool value = false;
    switch (PumpID) {
    case 1:
        value =ui->sb1->isChecked();
        break;
//    case 2:
//        value =ui->sb2->isChecked();
//        break;
//    case 3:
//        value =ui->sb3->isChecked();
//        break;
    default:
        break;
    }
    return value;
}

/***************************************************设置被勾选的ID为Checked****************************************************/
void MainMenu::PumpIDChecked(int PumpID)
{
    switch (PumpID) {
    case 1:
        ui->sb1->setChecked(true);
        break;
//    case 2:
//        ui->sb2->setChecked(true);
//        break;
//    case 3:
//        ui->sb3->setChecked(true);
//        break;
    default:
        break;
    }
}

/****************************************************************Fan****************************************************************/

//风扇勾选状态检测与动态构建
void MainMenu::FanStatusCheck()
{
    bgFanGroup = new QButtonGroup;
    bgFanGroup->setExclusive(false);

    bgFanGroup->addButton(ui->rb1);
    bgFanGroup->addButton(ui->rb2);
    bgFanGroup->addButton(ui->rb3);
    bgFanGroup->addButton(ui->rb4);
    bgFanGroup->addButton(ui->rb5);
    bgFanGroup->addButton(ui->rb6);
    bgFanGroup->addButton(ui->rb7);
    bgFanGroup->addButton(ui->rb8);
    bgFanGroup->addButton(ui->rb9);
    bgFanGroup->addButton(ui->rb10);
    bgFanGroup->addButton(ui->rb11);
    bgFanGroup->addButton(ui->rb12);
    bgFanGroup->addButton(ui->rb13);
    bgFanGroup->addButton(ui->rb14);
    bgFanGroup->addButton(ui->rb15);
    bgFanGroup->addButton(ui->rb16);
    bgFanGroup->addButton(ui->rb17);
    bgFanGroup->addButton(ui->rb18);
    bgFanGroup->addButton(ui->rb19);
    bgFanGroup->addButton(ui->rb20);

    bgFanGroup->setId(ui->rb1,1);
    bgFanGroup->setId(ui->rb2,2);
    bgFanGroup->setId(ui->rb3,3);
    bgFanGroup->setId(ui->rb4,4);
    bgFanGroup->setId(ui->rb5,5);
    bgFanGroup->setId(ui->rb6,6);
    bgFanGroup->setId(ui->rb7,7);
    bgFanGroup->setId(ui->rb8,8);
    bgFanGroup->setId(ui->rb9,9);
    bgFanGroup->setId(ui->rb10,10);
    bgFanGroup->setId(ui->rb11,11);
    bgFanGroup->setId(ui->rb12,12);
    bgFanGroup->setId(ui->rb13,13);
    bgFanGroup->setId(ui->rb14,14);
    bgFanGroup->setId(ui->rb15,15);
    bgFanGroup->setId(ui->rb16,16);
    bgFanGroup->setId(ui->rb17,17);
    bgFanGroup->setId(ui->rb18,18);
    bgFanGroup->setId(ui->rb19,19);
    bgFanGroup->setId(ui->rb20,20);


    connect(bgFanGroup,SIGNAL(buttonToggled(int,bool)),this,\
            SLOT(on_bgGroupFan_toggled(int, bool)));
}

//让四线风扇都不能选择
//void MainMenu::UnUsebaleFour()
//{

//    ui->rb9->setCheckable(false);
//    ui->rb10->setCheckable(false);
//    ui->rb11->setCheckable(false);
//    ui->rb12->setCheckable(false);
//    ui->rb13->setCheckable(false);
//    ui->rb14->setCheckable(false);
//    ui->rb15->setCheckable(false);
//    ui->rb16->setCheckable(false);
//}

//void MainMenu::UsebaleFour()
//{

//    ui->rb9->setCheckable(true);
//    ui->rb10->setCheckable(true);
//    ui->rb11->setCheckable(true);
//    ui->rb12->setCheckable(true);
//    ui->rb13->setCheckable(true);
//    ui->rb14->setCheckable(true);
//    ui->rb15->setCheckable(true);
//    ui->rb16->setCheckable(true);
//}

void MainMenu::on_bgGroupFan_toggled(int id, bool value)
{
    //根据勾选状态来生成对应的风扇界面
    if(value)
    {
        //如果勾选了当前的风扇则添加当前的风扇界面
       if(FanCreat[id-1] == NULL)
       {
           if(id<=8)
           {
               FanCreat[id-1]=ControlMenu->Fan3(id);
               ControlMenu->FanMenuAdd(FanCreat[id-1],id);
               SelfTestCreat[id-1]=SelfTest->FanSelfTestWindow(id);
               SelfTest->EditSelfMenuAdd(SelfTestCreat[id-1],id);
           }
           else
           {
               FanCreat[id-1]=ControlMenu->Fan4(id,Fan4MaxElec);
               ControlMenu->FanMenuAdd(FanCreat[id-1],id);
               SelfTestCreat[id-1]=SelfTest->FanSelfTestWindow(id);
               FanJsonMatrix[id-1][2] = Fan4MaxElec.toInt();
               SelfTest->EditSelfMenuAdd(SelfTestCreat[id-1],id);
           }
       }
       //发送自动测试界面开通
       emit Editctable(id);
       FanJsonMatrix[id-1][0] = id;
       SelfTestMatrix[id-1][0] = id;
       FanDataMatrix[id-1][0]=id;


       Fanrealgraphic[id-1] = new realtimegraphic();
       Fanrealgraphic[id-1]->Settitle(QString(tr("风扇%1").arg(id)));

       emit MakeFanshowbuttonenable(id);

    }
    else
    {
        //如果没有勾选当前的风扇则删除这个风扇界面
       ControlMenu->FanMenuDel(FanCreat[id-1]);
       FanCreat[id-1]=NULL;
       FanJsonMatrix[id-1][0] = 0;

       SelfTest->EditSelfMenuDel(SelfTestCreat[id-1]);
       SelfTestCreat[id-1]=NULL;
       delete Fanrealgraphic[id-1];
       Fanrealgraphic[id-1] =NULL;
       SelfTestMatrix[id-1][0] = 0;
       FanDataMatrix[id-1][0] = 0;
       emit MakeFanshowbuttonUNenable(id);
       //发送无法配置
       emit UNEditctable(id);

    }
}

/****************************************************************Pump******************************************/
//水泵勾选状态检测与动态构建
void MainMenu::PumpStatusCheck()
{
    bgPumpGroup = new QButtonGroup;

    bgPumpGroup->addButton(ui->sb1);
//    bgPumpGroup->addButton(ui->sb2);
//    bgPumpGroup->addButton(ui->sb3);

    bgPumpGroup->setId(ui->sb1,1);
//    bgPumpGroup->setId(ui->sb2,2);
//    bgPumpGroup->setId(ui->sb3,3);

    bgPumpGroup->setExclusive(false);
    connect(bgPumpGroup,SIGNAL(buttonToggled(int,bool)),this,\
            SLOT(on_bgGroupPump_toggled(int, bool)));
}

void MainMenu::on_bgGroupPump_toggled(int id, bool value)
{
    if(value)
    {
      if(PumpCreat[id-1] == NULL)
       {
          PumpCreat[id-1]=ControlMenu->Pump(id);
          ControlMenu->PumpMenuAdd(PumpCreat[id-1],id);

          SelfTestPumpCreat[id-1]=SelfTest->PumpSelfTestWindow(id);
          SelfTest->EditSelfPumpMenuAdd(SelfTestPumpCreat[id-1],id);
       }
        PumpJsonMatrix[id-1][0] = id;
        SelfTestPumpMatrix[id-1][0] = id;
        emit Editctable(21);

    }
    else
    {
       ControlMenu->PumpMenuDel(PumpCreat[id-1]);
       PumpCreat[id-1]=NULL;
       PumpJsonMatrix[id-1][0] = 0;

       SelfTest->EditSelfPumpMenuDel(SelfTestPumpCreat[id-1]);
       SelfTestPumpCreat[id-1]=NULL;
       SelfTestPumpMatrix[id-1][0] = 0;
       emit UNEditctable(21);
    }

}
/****************************************************************TEC******************************************/
//TEC勾选状态检测与动态构建
void MainMenu::TECStatusCheck()
{
    bgTECGroup = new QButtonGroup;

    bgTECGroup->addButton(ui->tec1);
    bgTECGroup->addButton(ui->tec2);
    bgTECGroup->addButton(ui->tec3);
    bgTECGroup->addButton(ui->tec4);
    bgTECGroup->addButton(ui->tec5);
    bgTECGroup->addButton(ui->tec6);


    bgTECGroup->setId(ui->tec1,1);
    bgTECGroup->setId(ui->tec2,2);
    bgTECGroup->setId(ui->tec3,3);
    bgTECGroup->setId(ui->tec4,4);
    bgTECGroup->setId(ui->tec5,5);
    bgTECGroup->setId(ui->tec6,6);

    bgTECGroup->setExclusive(false);
    connect(bgTECGroup,SIGNAL(buttonToggled(int,bool)),this,\
            SLOT(on_bgGroupTEC_toggled(int, bool)));
}

void MainMenu::on_bgGroupTEC_toggled(int id, bool value)
{  
    if(value)
    {
        if(TECCreat[id-1] == NULL)
        {TECCreat[id-1]=ControlMenu->TEC(id);
         ControlMenu->TECMenuAdd(TECCreat[id-1],id);
         SelfTestTECCreat[id-1]=SelfTest->TECSelfTestWindow(id);
         SelfTest->EditSelfTECMenuAdd(SelfTestTECCreat[id-1],id);
        }
         TECJsonMatrix[id-1][0] = id;
         SelfTestTECMatrix[id-1][0] = id;
         emit Editctable(21+id);

         TECrealgraphicTemp[id-1] = new realtimegraphic();
         TECrealgraphicDuty[id-1] = new realtimegraphic();

         TECrealgraphicTemp[id-1]->Settitle(QString(tr("TEC%1实时温度").arg(id)));
         TECrealgraphicDuty[id-1]->Settitle(QString(tr("TEC%1占空比").arg(id)));


         emit MakeTECTempshowbuttonenable(id);
         emit MakeTECDutyshowbuttonenable(id);


    }
    else
    {
       ControlMenu->TECMenuDel(TECCreat[id-1]);
       TECCreat[id-1]=NULL;
       TECJsonMatrix[id-1][0] = 0;

       SelfTest->EditSelfTECMenuDel(SelfTestTECCreat[id-1]);
       SelfTestTECCreat[id-1]=NULL;
       SelfTestTECMatrix[id-1][0] = 0;
       emit UNEditctable(21+id);

       delete TECrealgraphicTemp[id-1];
       delete TECrealgraphicDuty[id-1];

       TECrealgraphicTemp[id-1]=NULL;
       TECrealgraphicDuty[id-1]=NULL;

       emit MakeTECTempshowbuttonUNenable(id);
       emit MakeTECDutyshowbuttonUNenable(id);
    }

}

void MainMenu::SetTECColdValue(int value,int value1)
{
    TECJsonMatrix[value-1][1] = value1;
}

void MainMenu::SetTECHeatValue(int value,int value1)
{
    TECJsonMatrix[value-1][2] = value1;
}


void MainMenu::SetElecValue(int value,int value1)
{
    ElecJsonMatrix[value-1][1] = value1;
}


void MainMenu::TECCreatWithJson(int TECID,int ColdTemp,int TECValue)
{
    bool value = TECIDisChecked(TECID);//检查当前的选项是否被勾选

    if(value)
    {
        TECIDUnChecked(TECID);//删除勾选的项
         TECCreat[TECID-1] = ControlMenu->TEC(TECID,ColdTemp,TECValue);
        ControlMenu->TECMenuAdd(TECCreat[TECID-1],TECID);

        SelfTestTECCreat[TECID-1]=SelfTest->TECSelfTestWindow(TECID);
        SelfTest->EditSelfTECMenuAdd(SelfTestTECCreat[TECID-1],TECID);

        TECIDChecked(TECID);
    }
    else
    {
        TECCreat[TECID-1] = ControlMenu->TEC(TECID,ColdTemp,TECValue);
        ControlMenu->TECMenuAdd(TECCreat[TECID-1],TECID);

        SelfTestTECCreat[TECID-1]=SelfTest->TECSelfTestWindow(TECID);
        SelfTest->EditSelfTECMenuAdd(SelfTestTECCreat[TECID-1],TECID);

        TECIDChecked(TECID);
    }

}

void MainMenu::ElecCreatWithJson(int  ElecID,int ElecValue)
{
    bool value = ElecIDisChecked(ElecID);//检查当前的选项是否被勾选

    if(value)
    {
        ElecIDUnChecked(ElecID);//删除勾选的项
        ElecCreat[ElecID-1] = ControlMenu->Elec(ElecID,ElecValue);
        ControlMenu->ElecMenuAdd(ElecCreat[ElecID-1],ElecID);

        SelfTestElecCreat[ElecID-1]=SelfTest->ElecSelfTestWindow(ElecID);
        SelfTest->EditSelfElecMenuAdd(SelfTestElecCreat[ElecID-1],ElecID);

        ElecIDChecked(ElecID);
    }
    else
    {
        ElecCreat[ElecID-1] = ControlMenu->Elec(ElecID,ElecValue);
        ControlMenu->ElecMenuAdd(ElecCreat[ElecID-1],ElecID);

        SelfTestElecCreat[ElecID-1]=SelfTest->ElecSelfTestWindow(ElecID);
        SelfTest->EditSelfElecMenuAdd(SelfTestElecCreat[ElecID-1],ElecID);

        ElecIDChecked(ElecID);
    }

}

void MainMenu::ElecIDUnChecked(int ElecID)
{

    switch (ElecID)
    {
    case 1:
        ui->elec1->setChecked(false);
        break;
    case 2:
        ui->elec2->setChecked(false);
        break;
    case 3:
        ui->elec3->setChecked(false);
        break;
    case 4:
        ui->elec4->setChecked(false);
        break;
    default:
        break;
    }
}

/***********************************************************检测水泵是否被勾选******************************************************/
bool MainMenu::ElecIDisChecked(int ElecID)
{
    bool value = false;
    switch (ElecID) {
    case 1:
        value =ui->elec1->isChecked();
        break;
    case 2:
        value =ui->elec2->isChecked();
        break;
    case 3:
        value =ui->elec3->isChecked();
        break;
    case 4:
        value =ui->elec4->isChecked();
        break;
    default:
        break;
    }
    return value;
}

/***************************************************设置被勾选的ID为Checked****************************************************/
void MainMenu::ElecIDChecked(int ElecID)
{
    switch (ElecID) {
    case 1:
        ui->elec1->setChecked(true);
        break;
    case 2:
        ui->elec2->setChecked(true);
        break;
    case 3:
        ui->elec3->setChecked(true);
        break;
    case 4:
        ui->elec4->setChecked(true);
        break;
    default:
        break;
    }
}

/*************************************************让水泵勾选状态改变*************************************************************/
void MainMenu::TECIDUnChecked(int TECID)
{

    switch (TECID) {
    case 1:
        ui->tec1->setChecked(false);
        break;
    case 2:
        ui->tec2->setChecked(false);
        break;
    case 3:
        ui->tec3->setChecked(false);
        break;
    case 4:
        ui->tec4->setChecked(false);
        break;
    case 5:
        ui->tec5->setChecked(false);
        break;
    case 6:
        ui->tec6->setChecked(false);
        break;
    default:
        break;
    }
}

/***********************************************************检测水泵是否被勾选******************************************************/
bool MainMenu::TECIDisChecked(int TECID)
{
    bool value = false;
    switch (TECID) {
    case 1:
        value =ui->tec1->isChecked();
        break;
    case 2:
        value =ui->tec2->isChecked();
        break;
    case 3:
        value =ui->tec3->isChecked();
        break;
    case 4:
        value =ui->tec4->isChecked();
        break;
    case 5:
        value =ui->tec5->isChecked();
        break;
    case 6:
        value =ui->tec6->isChecked();
        break;
    default:
        break;
    }
    return value;
}

/***************************************************设置被勾选的ID为Checked****************************************************/
void MainMenu::TECIDChecked(int TECID)
{
    switch (TECID) {
    case 1:
        ui->tec1->setChecked(true);
        break;
    case 2:
        ui->tec2->setChecked(true);
        break;
    case 3:
        ui->tec3->setChecked(true);
        break;
    case 4:
        ui->tec4->setChecked(true);
        break;
    case 5:
        ui->tec5->setChecked(true);
        break;
    case 6:
        ui->tec6->setChecked(true);
        break;
    default:
        break;
    }
}

/****************************************************************Elec******************************************/
//TEC勾选状态检测与动态构建
void MainMenu::ElecStatusCheck()
{
    bgElecGroup = new QButtonGroup;

    bgElecGroup->addButton(ui->elec1);
    bgElecGroup->addButton(ui->elec2);
    bgElecGroup->addButton(ui->elec3);
    bgElecGroup->addButton(ui->elec4);


    bgElecGroup->setId(ui->elec1,1);
    bgElecGroup->setId(ui->elec2,2);
    bgElecGroup->setId(ui->elec3,3);
    bgElecGroup->setId(ui->elec4,4);


    bgElecGroup->setExclusive(false);
    connect(bgElecGroup,SIGNAL(buttonToggled(int,bool)),this,\
            SLOT(on_bgGroupElec_toggled(int, bool)));
}

void MainMenu::on_bgGroupElec_toggled(int id, bool value)
{
    if(value)
    {
        if(ElecCreat[id-1] == NULL)
        {
            ElecCreat[id-1]=ControlMenu->Elec(id);
            ControlMenu->ElecMenuAdd(ElecCreat[id-1],id);

            SelfTestElecCreat[id-1]=SelfTest->ElecSelfTestWindow(id);
            SelfTest->EditSelfElecMenuAdd(SelfTestElecCreat[id-1],id);

        }
         ElecJsonMatrix[id-1][0] = id;
         SelfTestElecMatrix[id-1][0] = id;
         emit Editctable(27+id);
    }
    else
    {
       ControlMenu->ElecMenuDel(ElecCreat[id-1]);
       ElecCreat[id-1]=NULL;
       ElecJsonMatrix[id-1][0] = 0;

       SelfTest->EditSelfTECMenuDel(SelfTestElecCreat[id-1]);
       SelfTestElecCreat[id-1]=NULL;
       SelfTestElecMatrix[id-1][0] = 0;
       emit UNEditctable(27+id);
    }

}

void MainMenu::saveCurrentPageConfig()
{
    ConfigFile->createConfigJson(FanJsonMatrix,PumpJsonMatrix,TECJsonMatrix,ElecJsonMatrix);
}

void MainMenu::Close()
{
    int Check = QMessageBox::warning(this,tr("警告"),tr("即将关闭散热逻辑界面，是否保存当前页面配置？"),\
                         QMessageBox::Ok|QMessageBox::Cancel);

    if(Check == QMessageBox::Ok)
    {
        ConfigFile->createConfigJson(FanJsonMatrix,PumpJsonMatrix,TECJsonMatrix,ElecJsonMatrix);
        return;
    }
    else if(Check == QMessageBox::Cancel)
    {

    }

}


//关闭界面保存配置表
void MainMenu::closeEvent()         //关闭按钮触发时此函数被调用，检查文本是否已保存
{
    this->hide();
}

//确定键显示所有的内容
void MainMenu::on_pushButton_clicked()
{

    int Check = QMessageBox::warning(this,tr("警告"),tr("四线风扇最高电压设置为：%1V").arg(Fan4MaxElec),\
                         QMessageBox::Ok|QMessageBox::Cancel);

    if(Check == QMessageBox::Ok)
    {
        ControlMenu->show();

        ui->comboBox->setEnabled(false);

        return;
    }
    else if(Check == QMessageBox::Cancel)
    {
        for(int i = 9;i<17;i++)
        {
            FanIDUnChecked(i);
        }
//        UnUsebaleFour();
        ui->comboBox->setEnabled(true);
        ControlMenu->hide();
        QMessageBox::warning(this,tr("警告"),tr("请先选择四线风扇最大电压再勾选风扇！"),\
                                 QMessageBox::Ok);
    }

}

MainMenu::~MainMenu()
{
   StopEveryThread();


   for(int i =0;i<20;i++){
       if(Fanrealgraphic[i] !=NULL)
       {
           Fanrealgraphic[i]->close();
       }

   }

   for(int i =0;i<6;i++){
       if(Fanrealgraphic[i] !=NULL)
       {
           TECrealgraphicTemp[i]->close();
       }

   }

   for(int i =0;i<6;i++){
       if(Fanrealgraphic[i] !=NULL)
       {
           TECrealgraphicDuty[i]->close();
       }

   }

   ShowGrapic->close();
   this->close();
   newselfTest->close();
}

//更改四线风扇的控制电压
void MainMenu::on_comboBox_currentTextChanged(const QString &arg1)
{
    for(int i = 9;i<17;i++)
    {
        FanIDUnChecked(i);
    }
    Fan4MaxElec = arg1;
//    UsebaleFour();
}




