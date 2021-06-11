#include "timecount.h"
#include "ui_timecount.h"
#include <QTimer>
#include <QMessageBox>


ShowTime::ShowTime(int time , QLCDNumber * lcd)
{
    CountTime = time;
    LCD = lcd;
}


ShowTime::~ShowTime()
{

}

void ShowTime::run()
{
    CountTime = LCD->value();
    for(int i = CountTime;i>=0;i--)
    {
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, SLOT(quit()));
        loop.exec();
        LCD->display(i);
    }
}




//计时器界面操作
timecount::timecount(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::timecount)
{
    ui->setupUi(this);
    ui->timeEdit->setDisplayFormat("HH:mm:ss");
    showTime(ui->timeEdit->time());
    Timer=NULL;
}

timecount::~timecount()
{
    delete ui;
}

void timecount::on_timeEdit_timeChanged(const QTime &time)
{
    if(Timer!=NULL)
    {
       Timer->terminate();
       Timer->wait();
    }

    showTime(time);
    int seconds = time.hour()*360 + time.minute() * 60 + time.second();
    double Temp = double(seconds);
    this->time = seconds;
    emit Runtime(Temp);
    ui->pushButton->setEnabled(true);
}

void timecount::showTime(const QTime &time) const
{
    int seconds = time.hour()*360 + time.minute() * 60 + time.second();
    ui->lcd->display(seconds);
}





void timecount::dialogButtonClicked() const
{

}

void timecount::on_pushButton_clicked()
{

    emit StartSelfTestThread();
    emit

    Timer = new ShowTime(time,ui->lcd);
    Timer->start();
    ui->pushButton->setEnabled(false);
    ui->timeEdit->setEnabled(true);

}

void timecount::on_pushButton_2_clicked()
{
    emit StopSelfTestThread();
    Timer->terminate();
    Timer->wait();
}
