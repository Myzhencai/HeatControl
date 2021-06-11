#include "realtimegraphic.h"
#include "ui_realtimegraphic.h"
#include "qcustomplot.h"

realtimegraphic::realtimegraphic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::realtimegraphic),
    mPlot(0)
{
    ui->setupUi(this);
    mPlot = new QCustomPlot(this);
    mPlot->xAxis->setLabel("时间(1秒)");
    mPlot->yAxis->setLabel("实时数据(rmp)");
    setCentralWidget(mPlot);

    // configure plot to have two right axes:
    mPlot->yAxis->setTickLabels(false);
    connect(mPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), mPlot->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    mPlot->yAxis2->setVisible(true);

    // create graphs:
    mGraph1 = mPlot->addGraph(mPlot->xAxis, mPlot->axisRect()->axis(QCPAxis::atRight, 30));


    mGraph1->setPen(QPen(QColor(250, 120, 0)));



    mPlot->legend->setVisible(true);//图标


    // create tags with newly introduced AxisTag class (see axistag.h/.cpp):
    mTag1 = new AxisTag(mGraph1->valueAxis());
    mTag1->setPen(mGraph1->pen());


    connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    mDataTimer.start(60);
}

realtimegraphic::~realtimegraphic()
{
    delete ui;
}


void realtimegraphic::Settitle(QString value)
{
    mPlot->graph(0)->setName(value);
}


void realtimegraphic::timerSlot()
{
  // calculate and add a new data point to each graph:
  mGraph1->addData(mGraph1->dataCount(), realtimevalue);

  // make key axis range scroll with the data:
  mPlot->xAxis->rescale();
  mGraph1->rescaleValueAxis(false, true);

  mPlot->xAxis->setRange(mPlot->xAxis->range().upper, 60, Qt::AlignRight);

  // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
  double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);

  mTag1->updatePosition(graph1Value);

  mTag1->setText(QString::number(graph1Value, 'f', 2));

  mPlot->replot();
}
