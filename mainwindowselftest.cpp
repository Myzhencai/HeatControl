#include "mainwindowselftest.h"
#include "ui_mainwindowselftest.h"
#include<QDebug>
#include<QDesktopWidget>

MainWindowSelfTest::MainWindowSelfTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowSelfTest)
{
    ui->setupUi(this);

    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<32;j++)
        {
            SelfTestArray[i][j]=0;
        }

    }

    for(int i =1;i<32;i++)
    {
        UNEdictable(i);
    }

     TimeEdictable(0);




    ui->pushButton_2->setEnabled(false);


//    QDesktopWidget* desktopWidget = QApplication::desktop();
        //获取可用桌面大小
//        QRect deskRect = desktopWidget->availableGeometry();
//        resize(deskRect.width(),deskRect.height());
        //获取设备屏幕大小

//        QRect screenRect = desktopWidget->screenGeometry();

//        resize(screenRect.width(),screenRect.height());

}

void MainWindowSelfTest::SendRunTime(double Timesecond)
{
    emit SendTestRunTime(Timesecond*60*1000);//对应单位为1000为1毫秒
}


void MainWindowSelfTest::UNEdictable(int lie){

    for(int i = 0;i<100;i++)
    {
        QTableWidgetItem * Items = new QTableWidgetItem(QString("-1"));
        Items->setFlags(Items->flags()&32);
        ui->tableWidget->setItem(i, lie, Items);
    }
}

void MainWindowSelfTest::TimeEdictable(int lie){

    for(int i = 0;i<100;i++)
    {
        QTableWidgetItem * Items = new QTableWidgetItem(QString("0"));
        Items->setFlags(Items->flags()&63);
        ui->tableWidget->setItem(i, lie, Items);
    }
}


//使得某列可编辑
void MainWindowSelfTest::Edictable(int lie){

    for(int i = 0;i<100;i++)
    {
        QTableWidgetItem * Items = new QTableWidgetItem(QString("0"));
        Items->setFlags(Items->flags()&63);
        ui->tableWidget->setItem(i, lie, Items);
    }
}

void MainWindowSelfTest::KeepArray()
{
    for(int i = 0;i<100;i++)
    {
        for(int j = 0;j<32;j++)
        {
            if(ui->tableWidget->item(i,j)->text()==QString("-1"))
            {
               SelfTestArray[i][j]=0;
            }
            else{
                SelfTestArray[i][j]=ui->tableWidget->item(i,j)->text().toInt();
            }

        }
    }

}



MainWindowSelfTest::~MainWindowSelfTest()
{
    delete ui;
}

void MainWindowSelfTest::on_pushButton_clicked()
{
    KeepArray();   
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    emit SelfTestArraysend(SelfTestArray);
    double TempTime = 0.0;
    for(int i =0;i<100;i++)
    {
       TempTime += SelfTestArray[i][0];
    }
    emit SendTestRunTime(TempTime*60*1000);
}

void MainWindowSelfTest::on_pushButton_2_clicked()
{
//    TimeCount->show();
//     ui->pushButton_2->setEnabled(false);
     ui->pushButton->setEnabled(true);

     if(this->ui->pushButton_2->text() == "开始测试")
     {
         this->ui->pushButton_2->setText("停止测试");
         emit SelfTestBegin();

     }
     else
     {
         this->ui->pushButton_2->setText("开始测试");
         emit SelfTestStop();

     }
}

