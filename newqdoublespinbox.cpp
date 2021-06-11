#include "newqdoublespinbox.h"

NewQdoubleSpinbox::NewQdoubleSpinbox(QWidget *parent): QDoubleSpinBox(parent)
{
    
}

NewQdoubleSpinbox::~NewQdoubleSpinbox()
{

}


//void NewQdoubleSpinbox::setMaxValue(double num)
//{

//    int Temp2 = this->objectName().toInt();

//    QMessageBox::warning(this,tr("警告"),tr("重置水泵%1最大电压为：12V").arg(Temp2));
//    this->setMaximum(num);

//}

void NewQdoubleSpinbox::setMax(int num)
{

    if(num ==0)
    {
        this->setMaximum(5);
    }
    else if(num == 1)
    {
        this->setMaximum(12);
    }
    else if(num ==2)
    {
        this->setMaximum(24);
    }

}
