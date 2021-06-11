#include "newqgroupbox.h"
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

newQgroupbox::newQgroupbox(QWidget *parent) :
    QGroupBox(parent)
{

}

newQgroupbox::~newQgroupbox()
{

}

//传递风扇自动检测配置参数
void newQgroupbox::SendFanSelfmin(int min)
{
    int Temp2 = this->objectName().toInt();
    emit SendFanmin(Temp2,min);
}
void newQgroupbox::SendFanSelfmax(int max)
{
    int Temp2 = this->objectName().toInt();
    emit SendFanmax(Temp2,max);
}
void newQgroupbox::SendFanSelfstep(int step)
{
    int Temp2 = this->objectName().toInt();
    emit SendFanstep(Temp2,step);
}

//传递水泵自动检测参数
void newQgroupbox::SendPumpSelfmin(int min)
{
    int Temp2 = this->objectName().toInt();
    emit SendPumpmin(Temp2,min);
}
void newQgroupbox::SendPumpSelfmax(int max)
{
    int Temp2 = this->objectName().toInt();
    emit SendPumpmax(Temp2,max);
}
void newQgroupbox::SendPumpSelfstep(int step)
{
    int Temp2 = this->objectName().toInt();
    emit SendPumpstep(Temp2,step);
}

//传递TEC自动检测参数
void newQgroupbox::SendTECSelfmin(int min)
{
    int Temp2 = this->objectName().toInt();
    emit SendTECmin(Temp2,min);
}
void newQgroupbox::SendTECSelfmax(int max)
{
    int Temp2 = this->objectName().toInt();
    emit SendTECmax(Temp2,max);
}
void newQgroupbox::SendTECSelfstep(int step)
{
    int Temp2 = this->objectName().toInt();
    emit SendTECstep(Temp2,step);
}

//传递Elec自动检测参数
void newQgroupbox::SendElecSelfmin(int min)
{
    int Temp2 = this->objectName().toInt();
    emit SendElecmin(Temp2,min);
}
void newQgroupbox::SendElecSelfmax(int max)
{
    int Temp2 = this->objectName().toInt();
    emit SendElecmax(Temp2,max);
}
void newQgroupbox::SendElecSelfstep(int step)
{
    int Temp2 = this->objectName().toInt();
    emit SendElecstep(Temp2,step);
}

//进入单个风扇界面风扇id确定
void newQgroupbox::enterEvent(QEvent *)
{
    this->FanId = this->objectName().toInt();
}

//风扇占空比设置
void newQgroupbox::FanDucyValueSet(double value)
{
    Ducy = int(value);
}

//鼠标离开单个风扇控制界面发送AT指令集
void newQgroupbox::leaveEvent(QEvent *)
{
    emit CursorLeaveout(FanId,Ducy);
}

void newQgroupbox::FanJsonElecCheck(int index)
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
void newQgroupbox::FanJsonElecMax(int index)
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
void newQgroupbox::FanJsonDucy(double index)
{

    int Temp2 = this->objectName().toInt();
    int Temp = int(index);

    emit FanJsonFanIDandDucy(Temp2,Temp);
}


void newQgroupbox::PumpJsonElec(int index)
{
    int Temp2 = this->objectName().toInt();
    emit PumpJsonFanIDandElec(Temp2,index);
}

void newQgroupbox::ElecJsonElec(int index)
{
    int Temp2 = this->objectName().toInt();
    emit ElecJsonFanIDandElec(Temp2,index);
}


void newQgroupbox::TECJsonElec(int index)
{
    int Temp2 = this->objectName().toInt();
    emit TECJsonFanIDandElec(Temp2,index);
}

void newQgroupbox::TECJsonElecHeat(int index)
{
    int Temp2 = this->objectName().toInt();
    emit TECJsonFanIDandElecHeat(Temp2,index);
}

void newQgroupbox::setValueComp(double index)
{
    emit SetValueForTest(index);
}

//通过串口实时显示数据
void newQgroupbox::setFanRealtimeSpeed(QString Speed)
{

    emit SetValueForRealtime(Speed);
}

void newQgroupbox::setTECRealtimeTemparature(QString Temperature)
{
    emit SetTECValueForRealtime(Temperature);
}

void newQgroupbox::setRealTimeTECDuty(QString Temperature)
{
    emit setTECforRealTimeDuty(Temperature);
}


//通过网口实时显示数据
void newQgroupbox::TCPsetFanRealtimeSpeed(QString Speed)
{

    emit TCPSetValueForRealtime(Speed);
}

void newQgroupbox::TCPsetTECRealtimeTemparature(QString Temperature)
{
    emit TCPSetTECValueForRealtime(Temperature);
}

void newQgroupbox::TCPsetRealTimeTECDuty(QString Temperature)
{
    emit TCPsetTECforRealTimeDuty(Temperature);
}

void newQgroupbox::setFanMaximum(int num)
{
    int Temp;

    if(num == 0)
    {
        Temp = 5;
    }
    else if(num == 1)
    {
        Temp = 12;
    }
    else if(num == 2)
    {
        Temp = 24;
    }
    qDebug()<<"hello"<<Temp;

    emit SetFanMaximum(Temp);
}

void newQgroupbox::SetselftestFanMaximum(int num)
{
    qDebug()<<"hello"<<num;
    emit SetselftestFanMaximumValue(num);

}








