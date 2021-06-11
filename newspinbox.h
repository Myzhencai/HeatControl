#ifndef NEWSPINBOX_H
#define NEWSPINBOX_H

#include <QSpinBox>

class NewSpinBox : public QSpinBox
{
    Q_OBJECT

public:
    explicit NewSpinBox(QWidget *parent = 0);
    ~NewSpinBox();

public slots:
   void Recordlower(int num);
   void Recordupper(int num);
   void setValueSource();
   void setMaximuStep(int num);
   void setMaxValue(int num);
   void setMaxElecValue(int num);
   void setValuE(double num);
   void SETMAX(int num);

public:
   int LowValue=0;
   int UpperValue =100;

};

#endif // FANMENUQGROUPBOX_H

