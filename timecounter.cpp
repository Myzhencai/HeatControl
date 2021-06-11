#include "timecounter.h"
#include "ui_timecounter.h"
#include <QTimer>
#include <QMessageBox>

TimeCounter::TimeCounter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TimeCounter)
{
    ui->setupUi(this);
    showTime(ui->timeEdit->time());

}

TimeCounter::~TimeCounter()
{
    delete ui;
}

void TimeCounter::on_timeEdit_timeChanged(const QTime &time)
{
    showTime(time);
    int seconds = time.minute() * 60 + time.second();
    double Temp = double(seconds);
    emit Runtime(Temp);
}

void TimeCounter::showTime(const QTime &time) const
{
    int seconds = time.minute() * 60 + time.second();
    ui->lcd->display(seconds);
}

void TimeCounter::showTimeInt(int seconds) const
{
     ui->lcd->display(seconds);
}

void TimeCounter::updateTime()
{
    if(time - 1 < 0)
    {
        QMessageBox *dialog = new QMessageBox();
        //dialog->setIcon(QMessageBox::Warning);
        dialog->setWindowTitle("泡面好了!");
        dialog->setText("别玩啦，该吃泡面了！");
//        dialog->setIconPixmap(QPixmap("icon.png"));
        dialog->setModal(true);
        this->setVisible(false);
//        WId wid = dialog->winId();
        if(dialog->exec())
        {
            exit(0);
        }

        //dialog->warning(this,"该吃泡面啦！","别玩了，该吃泡面了！", QMessageBox::Ok);
        //QAbstractButton *button = new QAbstractButton(this);
        //connect(dialog,buttonClicked(button),this,dialogButtonClicked(button));
        return;
    }
    showTimeInt(--time);
}

void TimeCounter::dialogButtonClicked() const
{

}

void TimeCounter::on_pushButton_clicked()
{
    time = ui->lcd->value();
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timer->start(1000);
    ui->pushButton->setEnabled(false);
    ui->timeEdit->setEnabled(false);
    emit Clicked(true);
}
