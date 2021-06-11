#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QSerialPort serial;
public slots:
    void on_btn_led1_Ctrl_2_clicked();

private slots:
    void on_btn_uart_Ctrl_clicked();
    void on_btn_led1_Ctrl_clicked();
    void on_btn_led2_Ctrl_clicked();
    void on_btn_clear_clicked();
    void on_cbb_baud_currentIndexChanged(const QString &arg1);
    void on_btn_serch_clicked();
    void serialPort_readyRead();
    void on_btn_send_clicked();
    void makeUartClientClose(bool value);
    void makeUartClientOpen(bool value);
    void SingleCoceModeRealTimeValue();
    void ForbidenOpen();
    void Notopen();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

signals:
    void makeTcpClientClose(bool);
    void makeTcpClientOpen(bool);
    void RecieveRealtimeValuewithUart(bool);
    void SendSingleCodeWithUart();
    void SendPageCodeWithUart();
    void saveCurrentPageConfig();
    void sendAllPageConfigwithUart();
    void SingleCoceModeisRunningFalse();
    void LiveSingleCoceMode();
    void SendDefualtModeinRunningFalse();
    void RealTimeFanSpeedSet(int,QString);
    void RealTimeNtcTempratureSet(int,QString);
    void RealTimeTECDutySet(int,QString);
    void SetTcpText(QString);
    void showPageConfig();
    void hidePageConfig();
    void savehandle();
    void showSelfTestWindow();
    void hideSelfTestWindow();
    void showReal();
    void hideReal();
    void StartsaveData();
    void StopsaveData();

public:
    Ui::Dialog *ui;
    QString  TempRealTimeValue;
    QString  *TempRealTimeValueBuffer;
    bool AddString = false;
    MainWindow * TempTcpClient;

    //为实时垂询提供的状态量
    QString ATCode_Value1 = QString(" AT+GetSpeed=Fan?\r\n");
    QString ATCode_Value2 = QString(" AT+GetTemp=Tec?\r\n");
    QString ATCode_Value3 = QString(" AT+GetDuty=Tec?\r\n");

    bool ReceiveCode1 =false;
    bool ReceiveCode2 =false;
    bool ReceiveCode3 =false;
    bool notopen = true;
};

#endif // DIALOG_H
