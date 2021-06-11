#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>
#include <QHostInfo>
#include <QComboBox>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tcpClient=new QTcpSocket(this); //创建socket对象

    LabSocketState=new QLabel("Socket状态：");//状态栏标签
    LabSocketState->setMinimumWidth(250);
    ui->statusBar->addWidget(LabSocketState);

    QString localIP=getLocalIP();//本机IP
    this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);
    ui->comboServer->addItem(localIP);


    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));//连接
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));//断开连接

    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));//状态改变
    connect(tcpClient,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));//有数据待读取
    


    //定时器更新数据
//    timer=new QTimer(this);
//    connect(timer,&QTimer::timeout,this,&MainWindow::timeoutTable);
//    timer->start(500);
}

QString MainWindow::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);
    QString   localIP="";

    QList<QHostAddress> addList=hostInfo.addresses();//

    if (!addList.isEmpty())
    for (int i=0;i<addList.count();i++)
    {
        QHostAddress aHost=addList.at(i);
        if (QAbstractSocket::IPv4Protocol==aHost.protocol())
        {
            localIP=aHost.toString();
            break;
        }
    }
    return localIP;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (tcpClient->state()==QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
    event->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::timeoutTable()
//{
//    tcpClient->write(str);
//}

void MainWindow::onConnected()
{ //connected()信号槽函数
    ui->plainTextEdit->appendPlainText("**已连接到服务器");
    ui->plainTextEdit->appendPlainText("**peer address:"+
                                   tcpClient->peerAddress().toString());
    ui->plainTextEdit->appendPlainText("**peer port:"+
                                   QString::number(tcpClient->peerPort()));
    ui->actConnect->setEnabled(false);
    ui->actDisconnect->setEnabled(true);
}

//与Uart互斥
void MainWindow::makeTcpClientClose(bool value)
{
    this->ui->actConnect->setEnabled(value);
    this->ui->actDisconnect->setEnabled(value);
}

void MainWindow::makeTcpClientOpen(bool value)
{
    this->ui->actConnect->setEnabled(value);
    this->ui->actDisconnect->setEnabled(value);
}



//保护机制
void MainWindow::TCPForbidenOpen(){
    ui->actConnect->setEnabled(false);
    QEventLoop loop;
    QTimer::singleShot(1000, &loop, SLOT(quit()));
    loop.exec();
    ui->actConnect->setEnabled(true);
}


void MainWindow::onDisconnected()
{//disConnected()信号槽函数
    ui->plainTextEdit->appendPlainText("**已断开与服务器的连接");
    ui->actConnect->setEnabled(true);
    ui->actDisconnect->setEnabled(false);
}



void MainWindow::onSocketReadyRead()
{
    //需要修改但是暂时不修改
    while(tcpClient->canReadLine())
    {
        TempRealTimeValue.clear();
        QByteArray rx_buf = tcpClient->readLine();
        TempRealTimeValue = QString::fromLocal8Bit(rx_buf);
        ui->plainTextEdit->appendPlainText("[in] "+TempRealTimeValue);

        if(ReceiveCode1)
        {
            TempRealTimeValue.remove(QString("\r\n"), Qt::CaseInsensitive);
            QStringList strList = TempRealTimeValue.split(",");

            for(int i = 0;i<strList.length();i++)
            {
                QStringList TempstrList = strList[i].split(":");
                emit TCPRealTimeFanSpeedSet(i,TempstrList[1]);//向界面发送实时风扇速度
                emit RealtimeFanvalue(i,TempstrList[1].toInt());
            }

            strList.clear();
            TempRealTimeValue.clear();
        }

        if(ReceiveCode2)
        {
            TempRealTimeValue.remove(QString("\r\n"), Qt::CaseInsensitive);
            QStringList strList = TempRealTimeValue.split(",");

            for(int i = 0;i<strList.length();i++)
            {
                QStringList TempstrList = strList[i].split(":");
                int TempValue = TempstrList[1].toInt()/10;
                QString TempString = QString::number(TempValue);
                emit TCPRealTimeNtcTempratureSet(i,TempString);//向界面发送实时风扇速度显示除以10
            }

            strList.clear();
            TempRealTimeValue.clear();
        }

        if(ReceiveCode3)
        {
            TempRealTimeValue.remove(QString("\r\n"), Qt::CaseInsensitive);
            QStringList strList = TempRealTimeValue.split(",");

            for(int i = 0;i<strList.length();i++)
            {
                QStringList TempstrList = strList[i].split(":");
                emit TCPRealTimeTECDutySet(i,TempstrList[1]);//向界面发送实时风扇速度
            }

            strList.clear();
            TempRealTimeValue.clear();
        }

        TempRealTimeValue.clear();
        rx_buf.clear();
       }
}

void MainWindow::onSocketStateChange(QAbstractSocket::SocketState socketState)
{//stateChange()信号槽函数
    switch(socketState)
    {
    case QAbstractSocket::UnconnectedState:
        LabSocketState->setText("scoket状态：UnconnectedState");
        break;
    case QAbstractSocket::HostLookupState:
        LabSocketState->setText("scoket状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        LabSocketState->setText("scoket状态：ConnectingState");
        break;

    case QAbstractSocket::ConnectedState:
        LabSocketState->setText("scoket状态：ConnectedState");
        break;

    case QAbstractSocket::BoundState:
        LabSocketState->setText("scoket状态：BoundState");
        break;

    case QAbstractSocket::ClosingState:
        LabSocketState->setText("scoket状态：ClosingState");
        break;

    case QAbstractSocket::ListeningState:
        LabSocketState->setText("scoket状态：ListeningState");
    }
    Currentstatus = socketState;
}

void MainWindow::on_actConnect_triggered()
{//连接到服务器
    QString     addr=ui->comboServer->currentText();
    quint16     port=ui->spinPort->value();
    tcpClient->connectToHost(addr,port);
//    tcpClient->connectToHost(QHostAddress::LocalHost,port);
    if(Currentstatus == QAbstractSocket::UnconnectedState)
    {
        return;
    }
    else{
        emit makeUartClientClose(false);
        emit RecieveRealtimeValuewithTcpNet(true);
        emit startDataThread();
    }

}

void MainWindow::on_actDisconnect_triggered()
{//断开与服务器的连接
    if (tcpClient->state()==QAbstractSocket::ConnectedState)
    {
        emit makeUartClientOpen(true);
        emit RecieveRealtimeValuewithTcpNet(false);
        emit StopdataThread();
        tcpClient->disconnectFromHost();
    }
}

void MainWindow::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}

//单条指令发送模式
void MainWindow::TCPSingleCoceModeRealTimeValue()
{
    ReceiveCode1=false;
    ReceiveCode2=false;
    ReceiveCode3=false;

    //AT+SetVoltage=Fan%1,%2\r\n
    if(ui->editMsg->text().contains("SetVoltage")&&ui->editMsg->text().contains("Fan"))
    {
        QMessageBox::warning(this,tr("警告"),tr("请通过控制界面来调控电压！"),\
                                 QMessageBox::Ok);
        ui->editMsg->clear();
    }

    //AT+SetDuty=Fan%1,%2\r\n
    else if(ui->editMsg->text().contains("SetDuty")&&ui->editMsg->text().contains("Fan")){
                QString NewString = ui->editMsg->text().replace("AT+SetDuty=Fan","");
                QStringList TempstrList = NewString.split(",");


                QString txt = QString(ui->editMsg->text().append("\r\n"));
                QByteArray str=txt.toLocal8Bit();
                tcpClient->write(str);
                txt.clear();
                ui->editMsg->clear();

                //发送信号(要分1-9 10-20)
                int TempintID = TempstrList[0].toInt();
                int TempValue = TempstrList[1].toInt();
                if(TempintID<9){
                    emit SendSingleFan(TempintID-1,TempValue/1000.0);
                }
                else{
                    emit SendSingleFan(TempintID-1,TempValue/10.0);
                }
    }
    //AT+SetVoltage=Pump,%1\r\n
    else if(ui->editMsg->text().contains("SetVoltage")&&ui->editMsg->text().contains("Pump")){
                QString NewString = ui->editMsg->text().replace("AT+SetVoltage=Pump","");
                QStringList TempstrList = NewString.split(",");


                QString txt = QString(ui->editMsg->text().append("\r\n"));
                QByteArray str=txt.toLocal8Bit();
                tcpClient->write(str);
                txt.clear();
                ui->editMsg->clear();

                //发送信号
                int TempValue = TempstrList[1].toInt();
                emit SendSinglePump(0,TempValue/1.0);
    }
    //AT+SetTemp=Tec%1,%2\r\n
    else if(ui->editMsg->text().contains("SetTemp")&&ui->editMsg->text().contains("Tec")){
                QString NewString = ui->editMsg->text().replace("AT+SetTemp=Tec","");
                QStringList TempstrList = NewString.split(",");


                QString txt = QString(ui->editMsg->text().append("\r\n"));
                QByteArray str=txt.toLocal8Bit();
                tcpClient->write(str);
                txt.clear();
                ui->editMsg->clear();

                //发送信号

                int TempintID = TempstrList[0].toInt();
                int TempValue = TempstrList[1].toInt();
                emit SendSingleTecTemp(TempintID-1,TempValue/10.0);

    }
    //AT+SetVoltage=Tec%1,%2\r\n
    else if(ui->editMsg->text().contains("SetVoltage")&&ui->editMsg->text().contains("Tec")){
                QString NewString = ui->editMsg->text().replace("AT+SetVoltage=Tec","");
                QStringList TempstrList = NewString.split(",");


                QString txt = QString(ui->editMsg->text().append("\r\n"));
                QByteArray str=txt.toLocal8Bit();
                tcpClient->write(str);
                txt.clear();
                ui->editMsg->clear();

                //发送信号
                int TempintID = TempstrList[0].toInt();
                int TempValue = TempstrList[1].toInt();
                emit SendSingleTecV(TempintID-1,TempValue/1000.0);
    }
    //AT+SetCurrent=Laser1,%1\r\n
    else if(ui->editMsg->text().contains("SetCurrent")&&ui->editMsg->text().contains("Laser1")){
                QString NewString = ui->editMsg->text().replace("AT+SetCurrent=Laser1","");
                QStringList TempstrList = NewString.split(",");


                QString txt = QString(ui->editMsg->text().append("\r\n"));
                QByteArray str=txt.toLocal8Bit();
                tcpClient->write(str);
                txt.clear();
                ui->editMsg->clear();

                //发送信号
                int TempValue = TempstrList[1].toInt();
                emit SendSingleLaser1(0,TempValue/10.0);
    }
    //AT+SetCurrent=Laser2,%1\r\n
    else if(ui->editMsg->text().contains("SetCurrent")&&ui->editMsg->text().contains("Laser2")){
                QString NewString = ui->editMsg->text().replace("AT+SetCurrent=Laser2","");
                QStringList TempstrList = NewString.split(",");


                QString txt = QString(ui->editMsg->text().append("\r\n"));
                QByteArray str=txt.toLocal8Bit();
                tcpClient->write(str);
                txt.clear();
                ui->editMsg->clear();

                //发送信号
                int TempValue = TempstrList[1].toInt();
                emit SendSingleLaser2(1,TempValue/10.0);
    }
    //AT+SetCurrent=GreenLaser,%1\r\n
    else if(ui->editMsg->text().contains("SetCurrent")&&ui->editMsg->text().contains("GreenLaser")){
                QString NewString = ui->editMsg->text().replace("AT+SetCurrent=GreenLaser","");
                QStringList TempstrList = NewString.split(",");


                QString txt = QString(ui->editMsg->text().append("\r\n"));
                QByteArray str=txt.toLocal8Bit();
                tcpClient->write(str);
                txt.clear();
                ui->editMsg->clear();

                //发送信号
                int TempValue = TempstrList[1].toInt();
                emit SendSingleLaser3(2,TempValue/10.0);
    }
    //AT+SetCurrent=RedLaser,%1\r\n
    else if(ui->editMsg->text().contains("SetCurrent")&&ui->editMsg->text().contains("RedLaser")){
                QString NewString = ui->editMsg->text().replace("AT+SetCurrent=RedLaser","");
                QStringList TempstrList = NewString.split(",");


                QString txt = QString(ui->editMsg->text().append("\r\n"));
                QByteArray str=txt.toLocal8Bit();
                tcpClient->write(str);
                txt.clear();
                ui->editMsg->clear();

                //发送信号
                int TempValue = TempstrList[1].toInt();
                emit SendSingleLaser4(3,TempValue/10.0);
    }

    else{
        int Check = QMessageBox::warning(this,tr("警告"),tr("请确保输入无误！"),\
                             QMessageBox::Ok|QMessageBox::Cancel);

        if(Check == QMessageBox::Ok)
        {
            QString txt = QString(ui->editMsg->text().append("\r\n"));
            QByteArray str=txt.toLocal8Bit();
            tcpClient->write(str);
            txt.clear();
            ui->editMsg->clear();

        }
        else if(Check == QMessageBox::Cancel)
        {
            QMessageBox::warning(this,tr("警告"),tr("请您在单条命令框修改！"),\
                                         QMessageBox::Ok);
            ui->editMsg->clear();


        }
    }



    QEventLoop loop;
    QTimer::singleShot(200, &loop, SLOT(quit()));
    loop.exec();

    emit TCPLiveSingleCoceMode();//先离开模式在切换变量
    emit TCPSingleCoceModeisRunningFalse();

    //可以删除不删除是为了线程安全（高频率或者长语句输入，输入的语句过长会有bug）
}

void MainWindow::on_btnSend_clicked()
{//发送数据
    emit TCPSendSingleCodeWithUart();
}

void MainWindow::on_actSendAll_triggered()
{
    emit TCPSendPageCodeWithUart();
}

void MainWindow::SetTcpText(QString Tempvalue)
{
    ui->editMsg->setText(Tempvalue);
}

