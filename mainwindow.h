#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QLabel>
#include <QPlainTextEdit>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
     //socket
    QLabel  *LabSocketState;  //状态栏显示标签

    QString getLocalIP();//获取本机IP地址
protected:
    void    closeEvent(QCloseEvent *event);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTcpSocket  *tcpClient;

    QAbstractSocket::SocketState Currentstatus=QAbstractSocket::UnconnectedState;

    void timeoutTable();

    //实时垂询变量
    bool ReceiveCode1 = false;
    bool ReceiveCode2 = false;
    bool ReceiveCode3 = false;

    QString ATCode_Value1 = QString(" AT+GetSpeed=Fan?\r\n");
    QString ATCode_Value2 = QString(" AT+GetTemp=Tec?\r\n");
    QString ATCode_Value3 = QString(" AT+GetDuty=Tec?\r\n");

    QString  TempRealTimeValue;

public slots:

    void    onConnected();
    void    onDisconnected();
    void    onSocketStateChange(QAbstractSocket::SocketState socketState);
    void    onSocketReadyRead();//读取socket传入的数据
    void on_actConnect_triggered();
    void on_actDisconnect_triggered();
    void on_actClear_triggered();
    void on_btnSend_clicked();

    //添加的函数
    void makeTcpClientClose(bool);
    void makeTcpClientOpen(bool);
    void TCPForbidenOpen();
    void TCPSingleCoceModeRealTimeValue();
    void on_actSendAll_triggered();
    void SetTcpText(QString Tempvalue);


signals:
    void StopdataThread();
    void makeUartClientClose(bool);
    void makeUartClientOpen(bool);
    void RecieveRealtimeValuewithTcpNet(bool);
    void startDataThread();
    void TCPSendSingleCodeWithUart();
    void TCPSingleCoceModeisRunningFalse();
    void TCPLiveSingleCoceMode();
    void TCPSendPageCodeWithUart();
    void TCPRealTimeFanSpeedSet(int,QString);
    void TCPRealTimeNtcTempratureSet(int,QString);
    void TCPRealTimeTECDutySet(int,QString);
    void RealtimeFanvalue(int,int);
    void SendSingleFan(int,double);
    void SendSinglePump(int,double);
    void SendSingleTecTemp(int ,double);
    void SendSingleTecV(int, double);
    void SendSingleLaser1(int,double);
    void SendSingleLaser2(int,double);
    void SendSingleLaser3(int,double);
    void SendSingleLaser4(int,double);

private:
    Ui::MainWindow *ui;
    QTimer *timer;                      //定时器
    QByteArray  str;
};

#endif // MAINWINDOW_H
