#ifndef TIMECOUNTER_H
#define TIMECOUNTER_H

#include <QMainWindow>

namespace Ui {
class TimeCounter;
}

class TimeCounter : public QMainWindow
{
    Q_OBJECT

public:
    explicit TimeCounter(QWidget *parent = 0);
    ~TimeCounter();

signals:
   void Runtime(double);
   void Clicked(bool);

private slots:
    void on_timeEdit_timeChanged(const QTime &time);
    void on_pushButton_clicked();
    void updateTime();

private:
    Ui::TimeCounter *ui;
    int time;
    void showTime(const QTime &time) const;
    void showTimeInt(int seconds) const;
    void dialogButtonClicked() const;
};

#endif // TIMECOUNTER_H
