#ifndef NEWQDOUBLESPINBOX_H
#define NEWQDOUBLESPINBOX_H

#include <QDoubleSpinBox>
#include<QMessageBox>


class NewQdoubleSpinbox : public QDoubleSpinBox
{
    Q_OBJECT

public:
    explicit NewQdoubleSpinbox(QWidget *parent = 0);
    ~NewQdoubleSpinbox();

public slots:
   void setMax(int);

};

#endif // NEWQDOUBLESPINBOX_H


