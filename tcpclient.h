#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class TcpClient;
}

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    QTcpSocket *socket;
    ~TcpClient();

    //实时垂询变量
    bool ReceiveCode1 = false;
    bool ReceiveCode2 = false;
    bool ReceiveCode3 = false;

    QString ATCode_Value1 = QString(" AT+GetSpeed=Fan?\r\n");
    QString ATCode_Value2 = QString(" AT+GetTemp=Ntc?\r\n");
    QString ATCode_Value3 = QString(" AT+GetDuty=Tec?\r\n");

    QString  TempRealTimeValue;
    QString  *TempRealTimeValueBuffer;
    bool AddString = false;


private slots:

    void displayError(QAbstractSocket::SocketError);
    void on_pushButton_connect_clicked();
    void recivedata();
    void on_pushButton_send_clicked();
    void on_pushButton_close_clicked();
    void makeTcpClientClose(bool);
    void makeTcpClientOpen(bool);
    void on_pushButton_send_2_clicked();
    void TCPForbidenOpen();
    void TCPSingleCoceModeRealTimeValue();

signals:
    void makeUartClientClose(bool);
    void makeUartClientOpen(bool);
    void RecieveRealtimeValuewithTcpNet(bool);
    void TCPSendSingleCodeWithUart();
    void TCPSingleCoceModeisRunningFalse();
    void TCPLiveSingleCoceMode();
    void TCPSendPageCodeWithUart();
    void TCPRealTimeFanSpeedSet(int,QString);
    void TCPRealTimeNtcTempratureSet(int,QString);
    void TCPRealTimeTECDutySet(int,QString);

private:
    Ui::TcpClient *ui;


};

#endif // TCPCLIENT_H
