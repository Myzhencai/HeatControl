#ifndef REALTIMEGRAPHIC_H
#define REALTIMEGRAPHIC_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "axistag.h"

namespace Ui {
class realtimegraphic;
}

class realtimegraphic : public QMainWindow
{
  Q_OBJECT

public:
  explicit realtimegraphic(QWidget *parent = 0);
  ~realtimegraphic();
   int realtimevalue =0;
   void Settitle(QString);


private slots:
  void timerSlot();

private:
  Ui::realtimegraphic*ui;
  QCustomPlot *mPlot;
  QPointer<QCPGraph> mGraph1;
  AxisTag *mTag1;
  QTimer mDataTimer;


};
#endif
