#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "heatcontrolmenu.h"
#include <QButtonGroup>
#include <vector>
#include <stack>
#include "configfileport.h"
#include "selftest.h"
#include "newqthread.h"
#include "realtimevaluethread.h"
#include "realtimevaluefromuart.h"
#include "realtimevaluefortcp.h"
#include "savedatathread.h"
#include "mainwindowselftest.h"
#include"mynewqthreadforself.h"
#include"selftestrunthread.h"
#include"realtimegraphic.h"
#include"showgraphic.h"
#include"newselftestpage.h"


namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
    void closeEvent();
    void Close();
    void FanIDChecked(int FanID);
    bool FanIDisChecked(int FanID);
    void FanIDUnChecked(int FanID);
    void PumpIDUnChecked(int PumpID);
    bool PumpIDisChecked(int PumpID);
    void PumpIDChecked(int PumpID);
    void TECIDUnChecked(int TECID);
    bool TECIDisChecked(int TECID);
    void TECIDChecked(int TECID);
    void ElecIDUnChecked(int TECID);
    bool ElecIDisChecked(int TECID);
    void ElecIDChecked(int TECID);
    HeatControlMenu* ControlMenu;    //散热界面
    void StopEveryThread();


signals:
    void MakeFanshowbuttonenable(int);
    void MakeFanshowbuttonUNenable(int);
    void MakeTECTempshowbuttonenable(int);
    void MakeTECTempshowbuttonUNenable(int);
    void MakeTECDutyshowbuttonenable(int);
    void MakeTECDutyshowbuttonUNenable(int);
    void LivePageCodeMode();
    void SendAllModeinRunningFalse();//返回串口模式操作完信号
    void SendDefualtModeinRunningFalse();
    void ForbidenOpen();
    void TCPLivePageCodeMode();
    void TCPSendAllModeinRunningFalse();
    void Notopen();
    void setStart1();
    void TCPForbidenOpen();
    void TCPSendDefualtModeinRunningFalse();
    void Editctable(int);
    void UNEditctable(int);

    void sendnewData(std::vector<std::vector<int>>,std::vector<std::vector<int>>,std::vector<std::vector<int>>,
                     std::vector<std::vector<int>>,std::vector<std::vector<int>>,std::vector<std::vector<int>>);

    void savedata();

public slots:
    void SendAllPageconfig(bool);
    void DATAsave();
    void savehanle();
    void StopdataThread();
    void SelfTestBegin();
    void SelfTestStop();
    void stopvalue();
    void startvalue();
    void isSavedatame();
    void pushButtonshowReal();
    void pushButtonhideReal();
    void pushButtonshowReal1();
    void pushButtonhideReal1();
    void pushButtonshowReal2();
    void pushButtonhideReal2();
    void pushButtonshowReal3();
    void pushButtonhideReal3();
    void pushButtonshowReal4();
    void pushButtonhideReal4();
    void pushButtonhideReal5();
    void pushButtonshowReal5();
    void pushButtonhideReal6();
    void pushButtonshowReal6();
    void pushButtonshowReal7();
    void pushButtonhideReal7();
    void pushButtonshowReal8();
    void pushButtonhideReal8();
    void pushButtonshowReal9();
    void pushButtonhideReal9();
    void pushButtonshowReal10();
    void pushButtonhideReal10();
    void pushButtonshowReal11();
    void pushButtonhideReal11();
    void pushButtonshowReal12();
    void pushButtonhideReal12();
    void pushButtonshowReal13();
    void pushButtonhideReal13();
    void pushButtonhideReal14();
    void pushButtonshowReal14();
    void pushButtonhideReal15();
    void pushButtonshowReal15();
    void pushButtonshowReal16();
    void pushButtonhideReal16();
    void pushButtonshowReal17();
    void pushButtonhideReal17();
    void pushButtonshowReal18();
    void pushButtonhideReal18();
    void pushButtonshowReal19();
    void pushButtonhideReal19();
    void ButtonshowReal();
    void ButtonhideReal();
    void ButtonshowReal1();
    void ButtonhideReal1();
    void ButtonshowReal2();
    void ButtonhideReal2();
    void ButtonshowReal3();
    void ButtonhideReal3();
    void ButtonshowReal4();
    void ButtonhideReal4();
    void ButtonshowReal5();
    void ButtonhideReal5();
    void uttonshowReal();
    void uttonhideReal();
    void uttonshowReal1();
    void uttonhideReal1();
    void uttonshowReal2();
    void uttonhideReal2();
    void uttonshowReal3();
    void uttonhideReal3();
    void uttonshowReal4();
    void uttonhideReal4();
    void uttonshowReal5();
    void uttonhideReal5();
    void StartSelfTestThread();
    void StopSelfTestThread();
    void SelfTestArraysend(std::vector<std::vector<int>> Arrays);
    void SendTestRunTime(double);

private slots:
    //风扇检测
    void on_bgGroupFan_toggled(int id,bool value);
    void FanStatusCheck();
    void FanCreatWithJson(int FanID,int ContectType,int MaxElec,int FanDucy);
    void SetElecMaxValue(int value,int value1);
    void SetDucyValue(int value,int value1);
   //水泵检测
    void on_bgGroupPump_toggled(int id, bool value);
    void PumpCreatWithJson(int PumpID,int ElecValue);
    void PumpStatusCheck();
    void SetPumpValue(int value,int value1);
   //TEC检测
    void on_bgGroupTEC_toggled(int id, bool value);
    void TECStatusCheck();
    void TECCreatWithJson(int TECID,int ColdTemp,int TECValue);
    void SetTECColdValue(int value,int value1);
    void SetTECHeatValue(int value,int value1);
   //Elec检测
    void on_bgGroupElec_toggled(int id, bool value);
    void ElecStatusCheck();
    void SetElecValue(int value,int value1);
    void ElecCreatWithJson(int  ElecID,int ElecValue);
   //确定按钮
    void on_pushButton_clicked();
    void on_comboBox_currentTextChanged(const QString &arg1);

    //自动检测
    void SetFanstepComp(int Id,int step);
    void SetFanminComp(int Id,int min);
    void SetFanmaxComp(int Id,int max);
    void SetPumpstepComp(int Id,int step);
    void SetPumpminComp(int Id,int min);
    void SetPumpmaxComp(int Id,int max);
    void SetTECstepComp(int Id,int step);
    void SetTECminComp(int Id,int min);
    void SetTECmaxComp(int Id,int max);
    void SetElecstepComp(int Id,int step);
    void SetElecminComp(int Id,int min);
    void SetElecmaxComp(int Id,int max);
    void SelfTestWithValue(bool value);
    void SetTestRunTime(double value);
    void ClearMenu();
    void SetUsefulTel();
    void SetUsefulTwen();
    void sendAllPageConfigwithUart();
    void sendAllPageConfigwithTCPNetWork();
    void RecieveRealtimeValuewithUart(bool);
    void RecieveRealtimeValuewithTCPNetWork(bool);
    void saveCurrentPageConfig();
    void showPageConfig();
    void hidePageConfig();
    void SendAllPageconfigStart();
    void SendAllPageconfigStop();
    void renewData();
    //实时设置风扇转速
    void DefaultModeRealTimeValue();//用Uart实时垂询
    void TCPNetWorkDefaultModeRealTimeValue();
    void RealTimeFanSpeedSet(int FanId,QString Speed);
    void RealTimeNtcTempratureSet(int TECId,QString Temperature);
    void RealTimeTECDutySet(int TECId,QString Duty);
    void TCPNetWorkRealTimeFanSpeedSet(int FanId,QString Speed);
    void TCPRealTimeNtcTempratureSet(int TECId,QString Temperature);
    void TCPRealTimeTECDutySet(int TECId,QString Duty);
    void showSelfTestWindow();
    void hideSelfTestWindow();
    void showReal();
    void hideReal();

private:
    Ui::MainMenu *ui;
    //风扇组
    QButtonGroup * bgFanGroup;
    QButtonGroup * bgFanGroup1;
    std::vector<FanMenuQGroupBox *> FanCreat{std::vector<FanMenuQGroupBox *>(20)};
    std::vector<std::vector<int>> FanJsonMatrix{20,std::vector<int>(4)};
    //水泵组
    QButtonGroup * bgPumpGroup;
    std::vector<FanMenuQGroupBox *> PumpCreat{std::vector<FanMenuQGroupBox *>(16)};
    std::vector<std::vector<int>> PumpJsonMatrix{16,std::vector<int>(2)};
    //TEC
    QButtonGroup * bgTECGroup;
    std::vector<FanMenuQGroupBox *> TECCreat{std::vector<FanMenuQGroupBox *>(16)};
    std::vector<std::vector<int>> TECJsonMatrix{16,std::vector<int>(2)};
    std::vector<std::vector<int>> TECDataMatrix{16,std::vector<int>(2)};
    //Elec
    QButtonGroup * bgElecGroup;
    std::vector<FanMenuQGroupBox *> ElecCreat{std::vector<FanMenuQGroupBox *>(16)};
    std::vector<std::vector<int>> ElecJsonMatrix{16,std::vector<int>(2)};

    //配置文件读取
    ConfigFilePort * ConfigFile;
    QString Fan4MaxElec = "12";

    //自动检测
    SelfTestWidow* SelfTest;
    double SelfTestRunTime = 1000.0;
    //风扇自动检测部分
    std::vector<FanMenuQGroupBox *> SelfTestCreat{std::vector<FanMenuQGroupBox *>(20)};
    std::vector<std::vector<int>> SelfTestMatrix{20,std::vector<int>(4)};
    std::vector<MyNewQThread *> FanSelfTest{std::vector<MyNewQThread *>(20)};
    std::vector<MyNewQThreadForSelf *> newFanSelfTest{std::vector<MyNewQThreadForSelf *>(20)};

    //水泵自动检测部分
    std::vector<FanMenuQGroupBox *> SelfTestPumpCreat{std::vector<FanMenuQGroupBox *>(3)};
    std::vector<std::vector<int>> SelfTestPumpMatrix{3,std::vector<int>(4)};
    std::vector<MyNewQThread *> PumpSelfTest{std::vector<MyNewQThread *>(3)};
    std::vector<MyNewQThreadForSelf *> newPumpSelfTest{std::vector<MyNewQThreadForSelf *>(3)};
    //TEC自动检测部分
    std::vector<FanMenuQGroupBox *> SelfTestTECCreat{std::vector<FanMenuQGroupBox *>(6)};
    std::vector<std::vector<int>> SelfTestTECMatrix{6,std::vector<int>(4)};
    std::vector<MyNewQThread *> TECSelfTest{std::vector<MyNewQThread *>(6)};
    std::vector<MyNewQThreadForSelf *> newTECSelfTest{std::vector<MyNewQThreadForSelf *>(6)};
    //Elec自动检测部分
    std::vector<FanMenuQGroupBox *> SelfTestElecCreat{std::vector<FanMenuQGroupBox *>(3)};
    std::vector<std::vector<int>> SelfTestElecMatrix{4,std::vector<int>(4)};
    std::vector<MyNewQThread *> ElecSelfTest{std::vector<MyNewQThread *>(4)};
    std::vector<MyNewQThreadForSelf *> newElecSelfTest{std::vector<MyNewQThreadForSelf *>(4)};

    //自动获取当前真实值
    RealtimeValueThread*  RealtimeValue ;
    RealtimeValueFromUart* TempUart;
    RealtimeValueForTCP* TempTCP;
    savedatathread *SavedataThread;
    std::vector<std::vector<int>> FanDataMatrix{20,std::vector<int>(2)};
    //新自动测试
    MainWindowSelfTest *newselfTest;//界面
    double selftestnewTime =10;
    std::vector<std::vector<int>> selfTestAss {100,std::vector<int>(32)};
    SelfTestrunThread* selftEstrun;
    std::vector<realtimegraphic *> Fanrealgraphic{std::vector<realtimegraphic *>(20)};
    std::vector<realtimegraphic *> TECrealgraphicTemp{std::vector<realtimegraphic *>(6)};
    std::vector<realtimegraphic *> TECrealgraphicDuty{std::vector<realtimegraphic *>(6)};
    Showgraphic* ShowGrapic;
    newSelfTestpage* newselfestpage;
    bool netisconnect = false;
};

#endif // MAINMENU_H
