#include "realtimevaluethread.h"


RealtimeValueThread::RealtimeValueThread()
{

}

void RealtimeValueThread::run()
{
//    while(isTruable)
//    {
//        HeatControlMenuPointer->UartPort->serial.write(ATCode_Value.toUtf8().data());
//        QByteArray rx_buf= HeatControlMenuPointer->UartPort->serial.readAll();
//        if(rx_buf.endsWith("\r\n"))
//        {
//         //解读所有风扇数据并更新实时数据
//          QString rx_buf_tmp = QString::fromLocal8Bit(rx_buf);    //转换为中文格式
//          qDebug() << rx_buf_tmp;

//        }
//        rx_buf.clear();

//        HeatControlMenuPointer->UartPort->serial.write(ATCode_Value1.toUtf8().data());
//        rx_buf= HeatControlMenuPointer->UartPort->serial.readAll();
//        if(rx_buf.endsWith("\r\n"))
//        {
//         //解读所有Ntc温度数据并更新实时数据
//          QString rx_buf_tmp = QString::fromLocal8Bit(rx_buf);    //转换为中文格式
//          qDebug() << rx_buf_tmp;
//        }
//        rx_buf.clear();

//        HeatControlMenuPointer->UartPort->serial.write(ATCode_Value2.toUtf8().data());
//        rx_buf= HeatControlMenuPointer->UartPort->serial.readAll();
//        if(rx_buf.endsWith("\r\n"))
//        {
//         //解读所有TEC占空比数据并更新实时数据
//          QString rx_buf_tmp = QString::fromLocal8Bit(rx_buf);    //转换为中文格式
//          qDebug() << rx_buf_tmp;
//        }
//        rx_buf.clear();
//        QEventLoop loop;
//        QTimer::singleShot(20, &loop, SLOT(quit()));
//        loop.exec();
//    }
    qDebug()<<"hello";
    return;
}

void RealtimeValueThread::stop()
{
    isTruable = false;
}

void RealtimeValueThread::SendSingleCodeWithUart(QByteArray value)
{
    qDebug()<<"hello";
    HeatControlMenuPointer->UartPort->serial.write(value);
    QByteArray rx_buf= HeatControlMenuPointer->UartPort->serial.readAll();
    if(rx_buf.endsWith("\r\n"))
    {
     //解读所有TEC占空比数据并更新实时数据
      QString rx_buf_tmp = QString::fromLocal8Bit(rx_buf);    //转换为中文格式
      qDebug() << rx_buf_tmp;
    }
    rx_buf.clear();
    qDebug()<<"llalal";
}


RealtimeValueThread::~RealtimeValueThread()
{

}

