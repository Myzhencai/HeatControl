#ifndef MAINWINDOWSELFTEST_H
#define MAINWINDOWSELFTEST_H

#include <QMainWindow>
#include"timecount.h"

namespace Ui {
class MainWindowSelfTest;
}

class MainWindowSelfTest : public QMainWindow
{
    Q_OBJECT

signals:
    void SelfTestArraysend(std::vector<std::vector<int>>);
    void SendTestRunTime(double);
    void SelfTestBegin();
    void SelfTestStop();
public:
    explicit MainWindowSelfTest(QWidget *parent = 0);
    ~MainWindowSelfTest();
    std::vector<std::vector<int>> SelfTestArray{100,std::vector<int>(32)};

public slots:
    void Edictable(int);
    void UNEdictable(int);
    void TimeEdictable(int);
    void KeepArray();
    void SendRunTime(double);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::MainWindowSelfTest *ui;
};

#endif // MAINWINDOWSELFTEST_H
