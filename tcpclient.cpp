#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QHostAddress>
#include <QDebug>
#include <QTimer>

TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(recivedata()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),
        this,SLOT(displayError(QAbstractSocket::SocketError)));
}

TcpClient::~TcpClient()
{
    delete ui;
}

//与Uart互斥
void TcpClient::makeTcpClientClose(bool value)
{
    this->ui->pushButton_connect->setEnabled(value);
    this->ui->pushButton_close->setEnabled(value);
}

void TcpClient::makeTcpClientOpen(bool value)
{
    this->ui->pushButton_connect->setEnabled(value);
    this->ui->pushButton_close->setEnabled(value);
}

//保护机制
void TcpClient::TCPForbidenOpen(){
    ui->pushButton_connect->setEnabled(false);
    QEventLoop loop;
    QTimer::singleShot(1000, &loop, SLOT(quit()));
    loop.exec();
    ui->pushButton_connect->setEnabled(true);
}


void TcpClient::on_pushButton_connect_clicked()
{
    socket->abort();
    QString ip = ui->lineEdit_ip->text();
    quint16 port = ui->lineEdit_port->text().toInt();
    socket->connectToHost(QHostAddress(ip),port);
    emit makeUartClientClose(false);
    emit RecieveRealtimeValuewithTcpNet(true);
}
void TcpClient::displayError(QAbstractSocket::SocketError)
{
   qDebug()<<socket->errorString();
   socket->close();
}

void TcpClient::recivedata()
{
    qDebug()<<"ReciveData From TCP";
    TempRealTimeValue.clear();
    QByteArray rx_buf=socket->readAll();
    TempRealTimeValue = QString::fromLocal8Bit(rx_buf);

    if(ReceiveCode1)
    {
//    风扇实时数据处理代码
        if(TempRealTimeValue.startsWith("AT+GetSpeed#")){
            AddString= true;
        }
        if(TempRealTimeValue.endsWith("\r\n"))
        {
            AddString= false;
        }
        if(AddString)
        {
            TempRealTimeValueBuffer->append(TempRealTimeValue);
        }
        else
        {
            TempRealTimeValueBuffer->append(TempRealTimeValue);
            ui->textEdit_read->insertPlainText(*TempRealTimeValueBuffer);

            TempRealTimeValueBuffer->remove(QString("\r\n"), Qt::CaseInsensitive);
            QStringList strList = TempRealTimeValueBuffer->split(",");

            for(int i = 0;i<strList.length();i++)
            {   QStringList TempstrList = strList[i].split(":");
                emit TCPRealTimeFanSpeedSet(i,TempstrList[1]);//向界面发送实时风扇速度
            }

            strList.clear();
            TempRealTimeValueBuffer->clear();
        }

    }

    if(ReceiveCode2)
    {

     //温度回复归总处理
        if(TempRealTimeValue.startsWith("AT+Temperature#"))
        {

            AddString= true;
        }
        if(TempRealTimeValue.endsWith("\r\n"))//
        {
            AddString= false;
        }
        if(AddString)
        {

            TempRealTimeValueBuffer->append(TempRealTimeValue);
        }
        else
        {
            TempRealTimeValueBuffer->append(TempRealTimeValue);
            ui->textEdit_read->insertPlainText(*TempRealTimeValueBuffer);

            TempRealTimeValueBuffer->remove(QString("\r\n"), Qt::CaseInsensitive);
            QStringList strList = TempRealTimeValueBuffer->split(",");

            for(int i = 0;i<strList.length();i++)
            {   QStringList TempstrList = strList[i].split(":");
                emit TCPRealTimeNtcTempratureSet(i,TempstrList[1]);//向界面发送实时风扇速度
            }

            strList.clear();

            TempRealTimeValueBuffer->clear();
        }

    }

    if(ReceiveCode3)
    {

     //温度回复归总处理
        if(TempRealTimeValue.startsWith("AT+GetDuty#"))
        {

            AddString= true;
        }
        if(TempRealTimeValue.endsWith("\r\n"))
        {
            AddString= false;
        }
        if(AddString)
        {
            TempRealTimeValueBuffer->append(TempRealTimeValue);
        }
        else
        {
            TempRealTimeValueBuffer->append(TempRealTimeValue);
            ui->textEdit_read->insertPlainText(*TempRealTimeValueBuffer);
            TempRealTimeValueBuffer->remove(QString("\r\n"), Qt::CaseInsensitive);
            QStringList strList = TempRealTimeValueBuffer->split(",");

            for(int i = 0;i<strList.length();i++)
            {   QStringList TempstrList = strList[i].split(":");
                emit TCPRealTimeTECDutySet(i,TempstrList[1]);//向界面发送实时风扇速度
            }

            strList.clear();
            TempRealTimeValueBuffer->clear();
        }

    }
    /****************************默认模式时实时数据显示模块****************************************/
    ui->textEdit_read->insertPlainText(TempRealTimeValue); //追加显示，末尾不会添加
    TempRealTimeValue.clear();
    rx_buf.clear();
}

void TcpClient::TCPSingleCoceModeRealTimeValue()
{
    ReceiveCode1=false;
    ReceiveCode2=false;
    ReceiveCode3=false;

    QString txt = ui->textEdit_write->toPlainText();
    QByteArray tx_buf_tmp = txt.toLocal8Bit();
    socket->write(tx_buf_tmp);

    txt.clear();
    emit TCPLiveSingleCoceMode();//先离开模式在切换变量
    emit TCPSingleCoceModeisRunningFalse();

    //可以删除不删除是为了线程安全（高频率或者长语句输入，输入的语句过长会有bug）
    QEventLoop loop;
    QTimer::singleShot(500, &loop, SLOT(quit()));
    loop.exec();
}

void TcpClient::on_pushButton_send_clicked()
{
    emit TCPSendSingleCodeWithUart();
}

void TcpClient::on_pushButton_close_clicked()
{
    emit makeUartClientOpen(true);
    emit RecieveRealtimeValuewithTcpNet(false);
    socket->close();
}

void TcpClient::on_pushButton_send_2_clicked()
{
    emit TCPSendPageCodeWithUart();
}

/*********************************************************Modified Part********************************************************/
