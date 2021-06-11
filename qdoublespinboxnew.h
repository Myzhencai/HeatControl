#ifndef QDOUBLESPINBOXNEW_H
#define QDOUBLESPINBOXNEW_H

#include <QDoubleSpinBox>


class QDoubleSpinBoxNew:public QDoubleSpinBox
{
    Q_OBJECT

public:
    explicit QDoubleSpinBoxNew(QWidget *parent = 0);
    ~QDoubleSpinBoxNew();

};

#endif // QDOUBLESPINBOXNEW_H
