#ifndef SELFTEST_H
#define SELFTEST_H

#include <QWidget>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QPushButton>
#include <QMenu>
#include <QComboBox>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <stack>
#include <QGridLayout>
#include <QScrollArea>
#include "dialog.h"
#include <QSettings>
#include "fanmenuqgroupbox.h"
#include "timecount.h"

class SelfTestWidow : public QWidget
{
    Q_OBJECT

public:
    explicit SelfTestWidow(QWidget *parent = 0);
    ~SelfTestWidow();

    //创建风扇自动检测窗口
    FanMenuQGroupBox *FanSelfTestWindow(int Id);
    void EditSelfMenu();
    FanMenuQGroupBox *EditSelfMenuAdd(FanMenuQGroupBox *&pFan,int Id);
    FanMenuQGroupBox *EditSelfMenuDel(FanMenuQGroupBox *&pFan1);

    //创建水泵自动检测窗口
    FanMenuQGroupBox *PumpSelfTestWindow(int Id);
    void EditSelfPumpMenu();
    FanMenuQGroupBox *EditSelfPumpMenuAdd(FanMenuQGroupBox *&pFan,int Id);
    FanMenuQGroupBox *EditSelfPumpMenuDel(FanMenuQGroupBox *&pFan1);

    //创建TEC自动检测窗口
    FanMenuQGroupBox *TECSelfTestWindow(int Id);
    void EditSelfTECMenu();
    FanMenuQGroupBox *EditSelfTECMenuAdd(FanMenuQGroupBox *&pFan,int Id);
    FanMenuQGroupBox *EditSelfTECMenuDel(FanMenuQGroupBox *&pFan1);

    //创建Elec自动检测窗口
    FanMenuQGroupBox *ElecSelfTestWindow(int Id);
    void EditSelfElecMenu();
    FanMenuQGroupBox *EditSelfElecMenuAdd(FanMenuQGroupBox *&pFan,int Id);
    FanMenuQGroupBox *EditSelfElecMenuDel(FanMenuQGroupBox *&pFan1);


    void SelfTestMenu();
    void closeEvent();

signals:
    void SendFanminComp(int,int);
    void SendFanmaxComp(int,int);
    void SendFanstepComp(int,int);

    void SendPumpminComp(int,int);
    void SendPumpmaxComp(int,int);
    void SendPumpstepComp(int,int);

    void SendTECminComp(int,int);
    void SendTECmaxComp(int,int);
    void SendTECstepComp(int,int);

    void SendElecminComp(int,int);
    void SendElecmaxComp(int,int);
    void SendElecstepComp(int,int);


    void SendRunTest(bool);
    void SendTestRunTime(double);

public slots:

    void SendFanmin(int Id,int value);
    void SendFanmax(int Id,int value);
    void SendFanstep(int Id,int value);

    void SendPumpmin(int Id,int value);
    void SendPumpmax(int Id,int value);
    void SendPumpstep(int Id,int value);

    void SendTECmin(int Id,int value);
    void SendTECmax(int Id,int value);
    void SendTECstep(int Id,int value);

    void SendElecmin(int Id,int value);
    void SendElecmax(int Id,int value);
    void SendElecstep(int Id,int value);

    void RunTest(bool value);

    void SendRunTime(double value);


private:
    QGridLayout *grid;//总得图形界面

    //计时器界面
    timecount* Timecount;

    //风扇图形界面
    QScrollArea* SelfTestWindow ;
    QWidget* SelfTestMENU = new QWidget;
    QGridLayout* SelfTestMenuGrid = new QGridLayout;

    //水泵图形界面
    QScrollArea* SelfTestPumpWindow ;
    QWidget* SelfTestPumpMENU = new QWidget;
    QGridLayout* SelfTestPumpMenuGrid = new QGridLayout;

    //TEC图形界面
    QScrollArea* SelfTestTECWindow ;
    QWidget* SelfTestTECMENU = new QWidget;
    QGridLayout* SelfTestTECMenuGrid = new QGridLayout;

    //Elec图形界面
    QScrollArea* SelfTestElecWindow ;
    QWidget* SelfTestElecMENU = new QWidget;
    QGridLayout* SelfTestElecMenuGrid = new QGridLayout;





};



#endif // SELFTEST_H
