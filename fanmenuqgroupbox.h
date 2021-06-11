#ifndef FANMENUQGROUPBOX_H
#define FANMENUQGROUPBOX_H

#include <QGroupBox>

class FanMenuQGroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit FanMenuQGroupBox(QWidget *parent = 0);
    ~FanMenuQGroupBox();
protected:
    void enterEvent(QEvent *);                  //进入QWidget瞬间事件
    void leaveEvent(QEvent *);                      //离开QWidget瞬间事件

signals:
    void CursorLeaveout(int,int);//传递AT指令参数
    void FanJsonElecCheckComp(int);//传递判定结果
    void FanJsonFanIDandElecMax(int,int);//传递最大电压和当前窗口ID
    void FanJsonFanIDandDucy(int,int);//传递占空比和当前窗口ID
    void SetValueForTest(double);
    //串口发送实时数据
    void SetValueForRealtime(QString);
    void SetTECValueForRealtime(QString);
    void setTECforRealTimeDuty(QString);
    //网口发送实时数据
    void TCPSetValueForRealtime(QString);
    void TCPSetTECValueForRealtime(QString);
    void TCPsetTECforRealTimeDuty(QString);


    //传递风扇、电流和TEC冷热面数值给Json文件
    void PumpJsonFanIDandElec(int,int);
    void ElecJsonFanIDandElec(int,int);
    void TECJsonFanIDandElec(int,int);
    void TECJsonFanIDandElecHeat(int,int);

    //自动控制
    void SendFanmin(int,int);
    void SendFanmax(int,int);
    void SendFanstep(int,int);

    void SendPumpmin(int,int);
    void SendPumpmax(int,int);
    void SendPumpstep(int,int);

    void SendTECmin(int,int);
    void SendTECmax(int,int);
    void SendTECstep(int,int);

    void SendElecmin(int,int);
    void SendElecmax(int,int);
    void SendElecstep(int,int);
    void SetValueForTest0(double);

public:


public slots:

    void FanJsonElecCheck(int index);//三线风扇电压改变判定
    void FanJsonElecMax(int index);//传递最大电压
    void FanJsonDucy(double index);//传递占空比
    void setValueComp(double index);//传递自动检测的参数
    void setValueComp0(double index);//为了TEC电压
    //串口传送数据
    void setFanRealtimeSpeed(QString Speed);
    void setTECRealtimeTemparature(QString Temperature);
    void setRealTimeTECDuty(QString Duty);
    //网口传递数据
    void TCPsetFanRealtimeSpeed(QString Speed);
    void TCPsetTECRealtimeTemparature(QString Temperature);
    void TCPsetRealTimeTECDuty(QString Duty);
    void PumpJsonElec(int index);
    void ElecJsonElec(int index);
    void TECJsonElec(int index);//冷面
    void TECJsonElecHeat(int index);//热面
    //自动控制
    void SendFanSelfmin(int min);
    void SendFanSelfmax(int max);
    void SendFanSelfstep(int step);
    void SendPumpSelfmin(int min);
    void SendPumpSelfmax(int max);
    void SendPumpSelfstep(int step);
    void SendTECSelfmin(int min);
    void SendTECSelfmax(int max);
    void SendTECSelfstep(int step);
    void SendElecSelfmin(int min);
    void SendElecSelfmax(int max);
    void SendElecSelfstep(int step);

private slots:
    void FanDucyValueSet(double value);
public:
    int FanId=0;
    int Ducy=1;
};

#endif // FANMENUQGROUPBOX_H
