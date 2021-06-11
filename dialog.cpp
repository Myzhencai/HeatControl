#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QTextCodec>   //中文支持
#include <QDir>
#include <QTimer>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    /*********************/
    this->setWindowTitle("串口控制LED - By wcc ");
    connect(&serial, & QSerialPort::readyRead, this, &Dialog::serialPort_readyRead);

    ui->cbb_com->clear();
    //运行开始查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->cbb_com->addItem(info.portName());  //串口号下拉菜单，增加一个条目，为串口号COM4
        qDebug() << "串口搜索完成";
    }
    ui->cbb_baud->insertItem(0, "9600");
    ui->cbb_baud->insertItem(1, "115200");
    ui->cbb_baud->insertItem(2, "3000000");
    ui->cbb_baud->insertItem(3, "自定义");
    //初始化按钮失能
//    this->ui->btn_led1_Ctrl->setDisabled(true); //LED控制不可用
//    this->ui->btn_led2_Ctrl->setDisabled(true);
    this->ui->btn_send->setDisabled(true);
//    this->ui->te_tx_buf->setDisabled(true);
    this->ui->tb_rx_buf->document()->setMaximumBlockCount(10);//设置显示框最大行数为10行

    TempRealTimeValueBuffer = new QString();
    this->ui->btn_led1_Ctrl->setText("休眠");

    qDebug() << QDir::currentPath();
}

Dialog::~Dialog()
{
    delete ui;
}



//发送单条指令模式调用函数
void Dialog::SingleCoceModeRealTimeValue()
{

  ReceiveCode1=false;
  ReceiveCode2=false;
  ReceiveCode3=false;

  QString tx_buf = ui->te_tx_buf->toPlainText();  //文本输入框的内容
  QByteArray tx_buf_tmp = tx_buf.toLocal8Bit();
  serial.write(tx_buf_tmp);     //把数据通过串口发送出去
  tx_buf.clear();
  emit LiveSingleCoceMode();//先离开模式在切换变量
  emit SingleCoceModeisRunningFalse();

  //可以删除不删除是为了线程安全（高频率或者长语句输入，输入的语句过长会有bug）
  QEventLoop loop;
  QTimer::singleShot(500, &loop, SLOT(quit()));
  loop.exec();
}


//Uart 与Tcp客户端互斥
void Dialog::makeUartClientClose(bool value)
{
    this->ui->btn_uart_Ctrl->setEnabled(value);
}

void Dialog::makeUartClientOpen(bool value)
{
    this->ui->btn_uart_Ctrl->setEnabled(value);
}


//打开串口按钮
void Dialog::on_btn_uart_Ctrl_clicked()
{
    if(this->ui->btn_uart_Ctrl->text() == "打开串口")   //初始状态，配置串口参数
    {

//        qDebug()<<"open";
        serial.setPortName(ui->cbb_com->currentText());     //设置串口号、
        serial.setBaudRate(ui->cbb_baud->currentText().toInt());    //设置波特率
        serial.setDataBits(QSerialPort::Data8);     //设置串口数据位8
        serial.setParity(QSerialPort::NoParity);    //无校验位
        serial.setStopBits(QSerialPort::OneStop);   //1位停止位
        serial.setFlowControl(QSerialPort::NoFlowControl);
        //打开串口
        if(!serial.open(QIODevice::ReadWrite))
        {
            QMessageBox::critical(NULL, "提示", "串口打开失败");
            emit RecieveRealtimeValuewithUart(false);
            //保护机制

            return;
        }
        emit makeTcpClientClose(false);
        qDebug() << "串口打开成功";
        this->ui->btn_uart_Ctrl->setText("关闭串口");
//        this->ui->btn_led1_Ctrl->setEnabled(true);
//        this->ui->btn_led2_Ctrl->setEnabled(true);
        this->ui->btn_send->setEnabled(true);
        this->ui->te_tx_buf->setEnabled(true);
        ForbidenOpen();
        emit RecieveRealtimeValuewithUart(true);
    }
    else
    {
        //关闭串口
//        qDebug()<<"close";
        emit RecieveRealtimeValuewithUart(false);
        serial.close();
        this->ui->btn_uart_Ctrl->setText("打开串口");
//        this->ui->btn_led1_Ctrl->setDisabled(true); //LED控制不可用
//        this->ui->btn_led2_Ctrl->setDisabled(true);
        this->ui->btn_send->setDisabled(true);
        this->ui->te_tx_buf->setDisabled(true);
        emit makeTcpClientOpen(true);//使得TCP网口打开
        //关闭串口实时数据更新线程

    }
}

void Dialog::ForbidenOpen()
{
    ui->btn_uart_Ctrl->setEnabled(false);
    QEventLoop loop;
    QTimer::singleShot(1000, &loop, SLOT(quit()));
    loop.exec();
    ui->btn_uart_Ctrl->setEnabled(true);
}

void Dialog::Notopen()
{
   notopen =false;
}

//LED1控制按钮
void Dialog::on_btn_led1_Ctrl_clicked()
{
    QPalette colr;
    if(serial.isOpen()==true)
    {

        if(this->ui->btn_led1_Ctrl->text() == "唤醒")
        {

            colr.setColor(QPalette::WindowText,Qt::blue);
            this->ui->lbe_red->setPalette(colr);
            this->ui->btn_led1_Ctrl->setText("休眠");
            ui->te_tx_buf->setText(QString("AT+Shutdown=On,1\r\n"));
            this->on_btn_send_clicked();//单条发送
//            serial.write(QString("AT+Shutdown=1\r\n").toLocal8Bit());

        }
        else
        {
            colr.setColor(QPalette::WindowText,Qt::black);
            this->ui->lbe_red->setPalette(colr);
            this->ui->btn_led1_Ctrl->setText("唤醒");
            ui->te_tx_buf->setText(QString("AT+Shutdown=Off,1\r\n"));
            this->on_btn_send_clicked();
//            this->on_btn_uart_Ctrl_clicked();
//            serial.write(QString("AT+Shutdown=0\r\n").toLocal8Bit());
        }

    }
    else if(TempTcpClient->tcpClient->isOpen()==true)
    {

        if(this->ui->btn_led1_Ctrl->text() == "唤醒")
        {
            colr.setColor(QPalette::WindowText,Qt::blue);
            this->ui->lbe_red->setPalette(colr);

            this->ui->btn_led1_Ctrl->setText("休眠");
            emit SetTcpText(QString("AT+Shutdown=On,1\r\n"));//设置发送的内容
            TempTcpClient->on_btnSend_clicked();
//            TempTcpClient->tcpClient->write(QString("AT+Shutdown=1\r\n").toLocal8Bit());
        }
        else
        {
            colr.setColor(QPalette::WindowText,Qt::blue);
            this->ui->lbe_red->setPalette(colr);
            this->ui->btn_led1_Ctrl->setText("唤醒");
            emit SetTcpText(QString("AT+Shutdown=Off,1\r\n"));//设置发送的内容
            TempTcpClient->on_btnSend_clicked();
//            TempTcpClient->on_actDisconnect_triggered();
//            TempTcpClient->tcpClient->write(QString("AT+Shutdown=0\r\n").toLocal8Bit());
        }

    }
    else
    {
        QMessageBox::warning(this,tr("警告"),tr("请先打开网口或者串口工具！"),\
                             QMessageBox::Ok);
    }

}
//LED2控制按钮
void Dialog::on_btn_led2_Ctrl_clicked()
{
    QPalette colr;
    if(serial.isOpen()==true)
    {
    if(this->ui->btn_led2_Ctrl->text() == "确认测试图")
    {
        colr.setColor(QPalette::WindowText,Qt::blue);
        this->ui->lbe_blue->setPalette(colr);
        ui->te_tx_buf->setText(QString("AT+SetTestPic=%1,1\r\n").arg(ui->comboBox->currentText()));
        this->on_btn_send_clicked();
//        this->ui->btn_led2_Ctrl->setText("重选测试图");
//        serial.write(QString("AT+SetTestPic=%1,1\r\n").arg(ui->comboBox->currentText()).toLocal8Bit());
    }
//    else
//    {
//        colr.setColor(QPalette::WindowText,Qt::black);
//        this->ui->lbe_blue->setPalette(colr);
//        this->ui->btn_led2_Ctrl->setText("确认测试图");
//    }
    }
    else if(TempTcpClient->tcpClient->isOpen()==true)
    {

        if(this->ui->btn_led2_Ctrl->text() == "确认测试图")
        {
            colr.setColor(QPalette::WindowText,Qt::blue);
            this->ui->lbe_blue->setPalette(colr);
            emit SetTcpText(QString("AT+SetTestPic=%1,1\r\n").arg(ui->comboBox->currentText()));//设置发送的内容
            TempTcpClient->on_btnSend_clicked();
//            this->ui->btn_led2_Ctrl->setText("重选测试图");
//            TempTcpClient->tcpClient->write(QString("AT+SetTestPic=%1,1\r\n").arg(ui->comboBox->currentText()).toLocal8Bit());
        }
//        else
//        {
//            colr.setColor(QPalette::WindowText,Qt::blue);
//            this->ui->lbe_blue->setPalette(colr);
//            this->ui->btn_led2_Ctrl->setText("确认测试图");
//        }

    }
    else
    {
        QMessageBox::warning(this,tr("警告"),tr("请先打开网口或者串口工具！"),\
                             QMessageBox::Ok);
    }


}

//串口数据接收并显示
void Dialog::serialPort_readyRead()
{
    TempRealTimeValue.clear();

    QByteArray rx_buf= serial.readAll();
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
            ui->tb_rx_buf->insertPlainText(*TempRealTimeValueBuffer);
//            qDebug()<<"hello"<<*TempRealTimeValueBuffer<<"hello";//处理模块
            TempRealTimeValueBuffer->remove(QString("\r\n"), Qt::CaseInsensitive);
            QStringList strList = TempRealTimeValueBuffer->split(",");

            for(int i = 0;i<strList.length();i++)
            {   QStringList TempstrList = strList[i].split(":");
                emit RealTimeFanSpeedSet(i,TempstrList[1]);//向界面发送实时风扇速度
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
            ui->tb_rx_buf->insertPlainText(*TempRealTimeValueBuffer);
//            qDebug()<<"hello"<<*TempRealTimeValueBuffer<<"hello";//处理模块

            TempRealTimeValueBuffer->remove(QString("\r\n"), Qt::CaseInsensitive);
            QStringList strList = TempRealTimeValueBuffer->split(",");

            for(int i = 0;i<strList.length();i++)
            {   QStringList TempstrList = strList[i].split(":");
                int TempValue = TempstrList[1].toInt()/10;
                QString TempString = QString::number(TempValue);

                emit RealTimeNtcTempratureSet(i,TempString);//向界面发送实时风扇速度
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
//            qDebug()<<"hello"<<*TempRealTimeValueBuffer<<"hello";//处理模块
            ui->tb_rx_buf->insertPlainText(*TempRealTimeValueBuffer);
            TempRealTimeValueBuffer->remove(QString("\r\n"), Qt::CaseInsensitive);
            QStringList strList = TempRealTimeValueBuffer->split(",");

            for(int i = 0;i<strList.length();i++)
            {   QStringList TempstrList = strList[i].split(":");
                emit RealTimeTECDutySet(i,TempstrList[1]);//向界面发送实时风扇速度
            }

            strList.clear();
            TempRealTimeValueBuffer->clear();
        }

    }
    /****************************默认模式时实时数据显示模块****************************************/

    ui->tb_rx_buf->insertPlainText(TempRealTimeValue); //追加显示，末尾不会添加
    TempRealTimeValue.clear();
    rx_buf.clear();

}

//清除接收窗口按钮
void Dialog::on_btn_clear_clicked()
{
    this->ui->tb_rx_buf->clear();
}
//自定义波特率
void Dialog::on_cbb_baud_currentIndexChanged(const QString &arg1)
{
    if(this->ui->cbb_baud->currentIndex() == 3)
    {
        this->ui->cbb_baud->setItemText(3, ""); //调成自定义波特率时，内容设置为空，准备接收输入
        this->ui->cbb_baud->setEditable(true);
    }
    else
    {
        this->ui->cbb_baud->setItemText(3, "自定义"); //调成自定义波特率时，内容设置为空，准备接收输入
        this->ui->cbb_baud->setEditable(false);
    }
    serial.setBaudRate(ui->cbb_baud->currentText().toInt());    //即使打开串口后，仍然可以设置波特率
}
//搜索串口功能
void Dialog::on_btn_serch_clicked()
{
    ui->cbb_com->clear();
    //运行开始查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->cbb_com->addItem(info.portName());  //串口号下拉菜单，增加一个条目，为串口号COM4
        qDebug() << "串口搜索完成";
    }
}
//发送按钮被按下
void Dialog::on_btn_send_clicked()
{
      emit SendSingleCodeWithUart();//设置为单行命令发送模式

//    emit RecieveRealtimeValuewithUart(false);
//    qDebug()<<"hello";
//    QString tx_buf = ui->te_tx_buf->toPlainText();  //文本输入框的内容
//    qDebug()<<tx_buf;
//获取多行输入框的数据并转换为UTF8格式
//QByteArray tx_buf_tmp = tx_buf.toLocal8Bit();   //转换为标准字符，支持中文
//    if(ui->cb_send_enter->isChecked())
//        tx_buf += "\r\n";
//    serial.write(tx_buf_tmp);     //把数据通过串口发送出去
//    tx_buf.clear();
}

void Dialog::on_btn_led1_Ctrl_2_clicked()
{
    emit SendPageCodeWithUart();//设置为全页面发送模式
}

void Dialog::on_pushButton_clicked()
{
    emit saveCurrentPageConfig();
}

void Dialog::on_pushButton_2_clicked()
{


    if(this->ui->pushButton_2->text() == "配置界面显示")
    {
        this->ui->pushButton_2->setText("配置界面关闭");
        emit showPageConfig();

    }
    else
    {
        this->ui->pushButton_2->setText("配置界面显示");
        emit hidePageConfig();;

    }
}

void Dialog::on_pushButton_3_clicked()
{

    if(this->ui->pushButton_3->text() == "自动测试界面显示")
    {
        this->ui->pushButton_3->setText("自动测试界面关闭");
        emit showSelfTestWindow();

    }
    else
    {
        this->ui->pushButton_3->setText("自动测试界面显示");
        emit hideSelfTestWindow();

    }

}

void Dialog::on_pushButton_4_clicked()
{
    if(this->ui->pushButton_4->text() == "显示实时数据图像")
    {
        this->ui->pushButton_4->setText("显示实时数据图像关闭");
        emit showReal();

    }
    else
    {
        this->ui->pushButton_4->setText("显示实时数据图像");
        emit hideReal();

    }
}

void Dialog::on_pushButton_5_clicked()
{

    if(this->ui->pushButton_5->text() == "开始保存数据" && notopen==true)
    {
        this->ui->pushButton_5->setText("停止保存数据");
        emit StartsaveData();
    }
    else
    {

        this->ui->pushButton_5->setText("开始保存数据");
        emit StopsaveData();

    }

}

