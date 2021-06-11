#include "fanmenuqgroupbox.h"
#include <QDebug>
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
#include <QMessageBox>

FanMenuQGroupBox::FanMenuQGroupBox(QWidget *parent) :
    QGroupBox(parent)
{

}

FanMenuQGroupBox::~FanMenuQGroupBox()
{

}

//传递风扇自动检测配置参数
void FanMenuQGroupBox::SendFanSelfmin(int min)
{
    int Temp2 = this->objectName().toInt();
    emit SendFanmin(Temp2,min);
}
void FanMenuQGroupBox::SendFanSelfmax(int max)
{
    int Temp2 = this->objectName().toInt();
    emit SendFanmax(Temp2,max);
}
void FanMenuQGroupBox::SendFanSelfstep(int step)
{
    int Temp2 = this->objectName().toInt();
    emit SendFanstep(Temp2,step);
}

//传递水泵自动检测参数
void FanMenuQGroupBox::SendPumpSelfmin(int min)
{
    int Temp2 = this->objectName().toInt();
    emit SendPumpmin(Temp2,min);
}
void FanMenuQGroupBox::SendPumpSelfmax(int max)
{
    int Temp2 = this->objectName().toInt();
    emit SendPumpmax(Temp2,max);
}
void FanMenuQGroupBox::SendPumpSelfstep(int step)
{
    int Temp2 = this->objectName().toInt();
    emit SendPumpstep(Temp2,step);
}

//传递TEC自动检测参数
void FanMenuQGroupBox::SendTECSelfmin(int min)
{
    int Temp2 = this->objectName().toInt();
    emit SendTECmin(Temp2,min);
}
void FanMenuQGroupBox::SendTECSelfmax(int max)
{
    int Temp2 = this->objectName().toInt();
    emit SendTECmax(Temp2,max);
}
void FanMenuQGroupBox::SendTECSelfstep(int step)
{
    int Temp2 = this->objectName().toInt();
    emit SendTECstep(Temp2,step);
}

//传递Elec自动检测参数
void FanMenuQGroupBox::SendElecSelfmin(int min)
{
    int Temp2 = this->objectName().toInt();
    emit SendElecmin(Temp2,min);
}
void FanMenuQGroupBox::SendElecSelfmax(int max)
{
    int Temp2 = this->objectName().toInt();
    emit SendElecmax(Temp2,max);
}
void FanMenuQGroupBox::SendElecSelfstep(int step)
{
    int Temp2 = this->objectName().toInt();
    emit SendElecstep(Temp2,step);
}

//进入单个风扇界面风扇id确定
void FanMenuQGroupBox::enterEvent(QEvent *)
{
    this->FanId = this->objectName().toInt();
}

//风扇占空比设置
void FanMenuQGroupBox::FanDucyValueSet(double value)
{
    Ducy = int(value);
}

//鼠标离开单个风扇控制界面发送AT指令集
void FanMenuQGroupBox::leaveEvent(QEvent *)
{
    emit CursorLeaveout(FanId,Ducy);
}

void FanMenuQGroupBox::FanJsonElecCheck(int index)
{
    int Temp =0;
    int Temp2 = this->objectName().toInt();
    if(index == 0)
    {
        int TempC= QMessageBox::warning(this,tr("警告"),tr("重置风扇%1最大电压为：5V").arg(Temp2));

    }
    else if(index == 1)
    {
        int TempC= QMessageBox::warning(this,tr("警告"),tr("设置风扇%1最大电压为：12V").arg(Temp2),\
                                 QMessageBox::Ok|QMessageBox::Cancel);
        if(TempC ==QMessageBox::Ok)
        {
            Temp = 1;
        }
        else
        {
            QMessageBox::warning(this,tr("警告"),tr("请重新为风扇%1设置最大电压！").arg(Temp2));
        }

    }
    else if(index == 2)
    {
        int TempC= QMessageBox::warning(this,tr("警告"),tr("设置风扇%1最大电压为：24V").arg(Temp2),\
                                 QMessageBox::Ok|QMessageBox::Cancel);
        if(TempC ==QMessageBox::Ok)
        {
            Temp = 2;
        }
        else
        {
            QMessageBox::warning(this,tr("警告"),tr("请重新为风扇%1设置最大电压！").arg(Temp2));
        }
    }
    emit FanJsonElecCheckComp(Temp);

}

//传递三线风扇最大电压
void FanMenuQGroupBox::FanJsonElecMax(int index)
{
    int Temp;
    int Temp2 = this->objectName().toInt();

    if(index == 0)
    {
        Temp = 5;
    }
    else if(index == 1)
    {
        Temp = 12;
    }
    else if(index == 2)
    {
        Temp = 24;
    }
    emit FanJsonFanIDandElecMax(Temp2,Temp);
}

//传递风扇占空比
void FanMenuQGroupBox::FanJsonDucy(double index)
{

    int Temp2 = this->objectName().toInt();
    int Temp = int(index);

    emit FanJsonFanIDandDucy(Temp2,Temp);
}


void FanMenuQGroupBox::PumpJsonElec(int index)
{
    int Temp2 = this->objectName().toInt();
    emit PumpJsonFanIDandElec(Temp2,index);
}

void FanMenuQGroupBox::ElecJsonElec(int index)
{
    int Temp2 = this->objectName().toInt();
    emit ElecJsonFanIDandElec(Temp2,index);
}


void FanMenuQGroupBox::TECJsonElec(int index)
{
    int Temp2 = this->objectName().toInt();
    emit TECJsonFanIDandElec(Temp2,index);
}

void FanMenuQGroupBox::TECJsonElecHeat(int index)
{
    int Temp2 = this->objectName().toInt();
    emit TECJsonFanIDandElecHeat(Temp2,index);
}

void FanMenuQGroupBox::setValueComp0(double index)
{
    emit SetValueForTest0(index);
}

void FanMenuQGroupBox::setValueComp(double index)
{
    emit SetValueForTest(index);
}

//通过串口实时显示数据
void FanMenuQGroupBox::setFanRealtimeSpeed(QString Speed)
{

    emit SetValueForRealtime(Speed);
}

void FanMenuQGroupBox::setTECRealtimeTemparature(QString Temperature)
{
    emit SetTECValueForRealtime(Temperature);
}

void FanMenuQGroupBox::setRealTimeTECDuty(QString Temperature)
{
    emit setTECforRealTimeDuty(Temperature);
}


//通过网口实时显示数据
void FanMenuQGroupBox::TCPsetFanRealtimeSpeed(QString Speed)
{

    emit TCPSetValueForRealtime(Speed);
}

void FanMenuQGroupBox::TCPsetTECRealtimeTemparature(QString Temperature)
{
    emit TCPSetTECValueForRealtime(Temperature);
}

void FanMenuQGroupBox::TCPsetRealTimeTECDuty(QString Temperature)
{
    emit TCPsetTECforRealTimeDuty(Temperature);
}








