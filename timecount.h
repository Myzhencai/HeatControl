#ifndef TIMECOUNT_H
#define TIMECOUNT_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QThread>


class ShowTime:public QThread
{
public:
    ShowTime(int time , QLCDNumber * lcd);
    ~ShowTime();
    void run();
private:
    int CountTime;
    QLCDNumber *LCD;
};

namespace Ui {
class timecount;
}

class timecount : public QMainWindow
{
    Q_OBJECT

public:
    explicit timecount(QWidget *parent = 0);
    ~timecount();

signals:
   void Runtime(double);
   void StopSelfTestThread();
   void StartSelfTestThread();


private slots:
    void on_timeEdit_timeChanged(const QTime &time);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::timecount *ui;
    int time;
    void showTime(const QTime &time) const;
    void dialogButtonClicked() const;
    ShowTime* Timer;
    ShowTime* Timer1;

};




#endif // TIMECOUNT_H
