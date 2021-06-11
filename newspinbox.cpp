#include "newspinbox.h"
#include<QMessageBox>
#include<QDebug>

NewSpinBox::NewSpinBox(QWidget *parent): QSpinBox(parent)
{

}

NewSpinBox::~NewSpinBox()
{

}

void NewSpinBox::Recordlower(int num)
{
    LowValue = num;
}

void NewSpinBox::Recordupper(int num)
{
    UpperValue = num;
}

void NewSpinBox::setMaximuStep(int num)
{
   int Temp= this->UpperValue - this->LowValue;
   this->setMaximum(Temp);
   this->setMinimum(1);
}

void NewSpinBox::setValueSource()
{
    this->setValue(1);
}

void NewSpinBox::setMaxValue(int num)
{

    int Temp2 = this->objectName().toInt();
    if(num ==0)
    {
        QMessageBox::warning(this,tr("警告"),tr("重置水泵%1最大电压为：12V").arg(Temp2));
        this->setMaximum(12);
    }
    else if(num == 1)
    {
        QMessageBox::warning(this,tr("警告"),tr("重置水泵%1最大电压为：24V").arg(Temp2));
        this->setMaximum(24);

    }
}

void NewSpinBox::setMaxElecValue(int num)
{

    int Temp2 = this->objectName().toInt();
    if(num ==0)
    {
        QMessageBox::warning(this,tr("警告"),tr("重置电源%1最大电流为：1.9A").arg(Temp2));
        this->setMaximum(19);
    }
    else if(num == 1)
    {
        QMessageBox::warning(this,tr("警告"),tr("重置电源%1最大电流为：3.8A").arg(Temp2));
        this->setMaximum(38);

    }
}

void NewSpinBox::setValuE(double num)
{
    this->setValue(int(num));
}

void NewSpinBox::SETMAX(int num)
{
    qDebug()<<"hello";
    this->setMaximum(num);
}

