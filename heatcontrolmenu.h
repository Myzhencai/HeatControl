#ifndef HEATCONTROLMENU_H
#define HEATCONTROLMENU_H

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
#include "tcpclient.h"
#include "mainwindow.h"    //新的tcp网络接口
#include "newqdoublespinbox.h"

class HeatControlMenu : public QWidget
{
    Q_OBJECT

public:
    explicit HeatControlMenu(QWidget *parent = 0);
    ~HeatControlMenu();

    FanMenuQGroupBox *Fan3(int num);
    FanMenuQGroupBox *Fan4(int num , QString MaxElec);
    FanMenuQGroupBox *Fan(int FanID,int ContectType,int MaxElec,int FanDucy);//Json 文件生成风扇控制界面
    FanMenuQGroupBox *Pump(int num1);
    FanMenuQGroupBox *Pump(int PumpID,int ElecValue);//Json 文件生成水泵控制界面
    FanMenuQGroupBox *TEC(int num2);
    FanMenuQGroupBox *TEC(int TECID ,int ColdTemp ,int TECValue);//Json 文件生成TEC控制界面
    FanMenuQGroupBox *Elec(int num3);
    FanMenuQGroupBox *Elec(int ElecID, int ElecValue);//Json 文件生成电流控制界面
    void *Uart();//串口通信模块
    void *NetWorkClientEdict();//Tcp网口通信
    QGridLayout *GetGrid();
    void HeatMenu();//界面生成代码
    //风扇
    FanMenuQGroupBox *FanMenuAdd(FanMenuQGroupBox *& pFan,int Id);
    FanMenuQGroupBox *FanMenuDel( FanMenuQGroupBox *& pFan1);
    void EditFanMenu();
    //水泵
    FanMenuQGroupBox *PumpMenuDel(FanMenuQGroupBox *& pPump1);
    FanMenuQGroupBox *PumpMenuAdd(FanMenuQGroupBox *& pPump,int Id );
    void EditPumpMenu();
    //TEC
    FanMenuQGroupBox *TECMenuDel(FanMenuQGroupBox *& pTEC1);
    FanMenuQGroupBox *TECMenuAdd(FanMenuQGroupBox *& pTEC,int Id );
    void EditTECMenu();
    //Elec
    FanMenuQGroupBox *ElecMenuDel(FanMenuQGroupBox *& pElec1);
    FanMenuQGroupBox *ElecMenuAdd(FanMenuQGroupBox *& pElec,int Id );
    void EditElecMenu();
    MainWindow * NetWorkClient;
    Dialog * UartPort;

signals:
    void SendToConfig(int);

    //风扇Json相关变量发送
    void SendElecMaxValue(int,int);
    void SendDucyValue(int,int);
    void SendPumpValue(int,int);
    void SendElecValue(int,int);
    void SendTECColdValue(int,int);
    void SendTECHeatValue(int,int);
    void SendValueComp(double);

public slots:
    //风扇Json相关变量发送
    void FanJsonFanIDandElecMax(int value,int value1);
    void FanJsonFanIDandDucy(int value,int value1);
    void PumpJsonFanIDandElec(int value,int value1);
    void TECJsonFanIDandElec(int value,int value1);
    void TECJsonFanIDandElecHeat(int value ,int value1);
    void ElecJsonFanIDandElec(int value ,int value1);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void SendFanControlCode(int,int);

private:
    QGridLayout *grid;//总得图形界面

    //风扇
    QScrollArea * FanMenuScrollArea;//风扇滑动窗口
    QWidget *FanMenu ;//单个风扇组
    QGridLayout * FanMenuGrid ;//多个风扇组

    //水泵
    QScrollArea * PumpMenuScrollArea;
    QWidget *PumpMenu;//单个水泵组
    QGridLayout *PumpMenuGrid;//多个水泵组

    //TEC
    QScrollArea * TECMenuScrollArea;
    QWidget *TECMenu;//单个TEC组
    QGridLayout *TECMenuGrid;//多个TEC组

    //电流
    QScrollArea * ElecMenuScrollArea;
    QWidget *ElecMenu;//单个TEC组
    QGridLayout *ElecMenuGrid;//多个TEC组

};

#endif
