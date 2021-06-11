#include "heatcontrolmenu.h"
#include<QSpinBox>
#include<QSlider>
#include<QSpinBox>
#include <QFormLayout>
#include <Qsize>
#include <QScrollArea>
#include <QDebug>
#include "dialog.h"
#include <QSettings>
#include <QTimer>
#include "QxtSpanSlider.h"
#include"newspinbox.h"
#include"newqdoublespinbox.h"
//#include"qdoublespinboxnew.h"

HeatControlMenu::HeatControlMenu(QWidget *parent) :
    QWidget(parent)
{
      //散热逻总界面
      grid = new QGridLayout(this);
//      NetWorkClient = new TcpClient();
      NetWorkClient = new MainWindow();
//      NetWorkClient->show();
      UartPort = new Dialog;

      UartPort->TempTcpClient = NetWorkClient;

      //风扇总网格参数
      FanMenuScrollArea = new QScrollArea(this);//(tr("风扇组"));
      FanMenuScrollArea->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, \
                                                    QSizePolicy::Expanding));
      FanMenuScrollArea->setWidgetResizable(true);
      FanMenuScrollArea->setMaximumSize(QSize(800,1000));
      FanMenu = new QWidget;//(tr("风扇组"));
      FanMenu->setMaximumSize(QSize(800,1000));
      FanMenuGrid = new QGridLayout;
      FanMenuGrid->setSpacing(3);

      //水泵总网格参数
      PumpMenuScrollArea = new QScrollArea;//(tr("风扇组"));
      PumpMenuScrollArea->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, \
                                                   QSizePolicy::Expanding));
      PumpMenuScrollArea->setWidgetResizable(true);
      PumpMenuScrollArea->setMaximumSize(QSize(800,800));
      PumpMenu = new QWidget;//(tr("水泵组"));
      PumpMenu->setMaximumSize(QSize(800,800));
      PumpMenuGrid = new QGridLayout;
      PumpMenuGrid->setSpacing(3);

      //TEC总网格参数
      TECMenuScrollArea = new QScrollArea;//(tr("风扇组"));
      TECMenuScrollArea->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, \
                                                   QSizePolicy::Expanding));
      TECMenuScrollArea->setWidgetResizable(true);
      TECMenuScrollArea->setMaximumSize(QSize(800,800));
      TECMenu = new QWidget;//(tr("水泵组"));
      TECMenu->setMaximumSize(QSize(1200,800));
      TECMenuGrid = new QGridLayout(TECMenu);
      TECMenuGrid->setSpacing(3);

      //Elec总网格参数
      ElecMenuScrollArea = new QScrollArea;//(tr("风扇组"));
      ElecMenuScrollArea->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, \
                                                   QSizePolicy::Expanding));
      ElecMenuScrollArea->setWidgetResizable(true);
      ElecMenuScrollArea->setMaximumSize(QSize(800,800));
      ElecMenu = new QWidget;//(tr("水泵组"));
      ElecMenu->setMaximumSize(QSize(800,800));
      ElecMenuGrid = new QGridLayout(ElecMenu);
      ElecMenuGrid->setSpacing(3);

      Uart();//串口初始化
      NetWorkClientEdict();//网口初始化

      //网口与串口互斥设定
      connect(UartPort,SIGNAL(makeTcpClientClose(bool)),NetWorkClient,SLOT(makeTcpClientClose(bool)));
      connect(UartPort,SIGNAL(makeTcpClientOpen(bool)),NetWorkClient,SLOT(makeTcpClientOpen(bool)));

      connect(NetWorkClient,SIGNAL(makeUartClientClose(bool)),UartPort,SLOT(makeUartClientClose(bool)));
      connect(NetWorkClient,SIGNAL(makeUartClientOpen(bool)),UartPort,SLOT(makeUartClientOpen(bool)));

      //发送所有当前页面配置

}

//关闭窗口事件
void HeatControlMenu::closeEvent(QCloseEvent *event)
{
    //关闭窗口后的处理事件：可能是提醒保存文件等。
}

/*******************************************************HeatMenu整体的画面设置****************************************************/
QGridLayout* HeatControlMenu::GetGrid()
{
    return grid;
}

void HeatControlMenu::HeatMenu()
{
    setLayout(grid);
    setWindowTitle(tr("散热逻辑控制界面"));
    resize(2000,2000);
}

/*******************************************************风扇界面生成与控制代码****************************************************/

//风扇指令发送代码（需要删除）
void HeatControlMenu::SendFanControlCode(int FanId,int FanDucy)
{
    if(FanDucy<0)
        FanDucy = 1;//针对没有更改ducy时会存在负数问题
    QString ATCode_Value = QString("AT+SetFan=Fan%1:%2").arg(FanId).arg(FanDucy);

    QByteArray ATCode_Value_Send = ATCode_Value.toLocal8Bit();
    this->UartPort->serial.write(ATCode_Value_Send);
    ATCode_Value_Send.clear();
    ATCode_Value.clear();
}

//添加Fan模块到HeatMenu
void HeatControlMenu::EditFanMenu()
{
    FanMenu->setLayout(FanMenuGrid);
    FanMenuScrollArea->setWidget(FanMenu);
    grid->addWidget(FanMenuScrollArea,0,0,1,1);
}

//添加Fan的函数
FanMenuQGroupBox *HeatControlMenu::FanMenuAdd(FanMenuQGroupBox *&pFan,int Id)
{
    int GridX = (Id-1)/4;
    int GridY = (Id-1)%4;
    FanMenuGrid->addWidget(pFan,GridX,GridY,Qt::AlignLeft);
}

//删除Fan的函数
FanMenuQGroupBox *HeatControlMenu::FanMenuDel(FanMenuQGroupBox *&pFan1)
{
    delete pFan1;
}

//绘画三线Fan的单个窗格
FanMenuQGroupBox *HeatControlMenu::Fan3(int num)
{
      FanMenuQGroupBox *Fan = new FanMenuQGroupBox;
      Fan->setTitle(tr("三线风扇%1").arg(num));
      Fan->setObjectName(tr("%1").arg(num));//风扇id用于AT指令集

      QLabel * FirstLable = new QLabel;
      FirstLable->setText("电压设置");

      QLabel * SecondLable = new QLabel;
      SecondLable->setText("三线控制");

      QComboBox * ElecValue = new QComboBox;
      ElecValue->addItem("5V");
      ElecValue->addItem("12V");
      ElecValue->addItem("24V");

      //根据更改的选项来传递当前的窗口号和对应的值
      connect(ElecValue,SIGNAL(currentIndexChanged(int)),Fan,SLOT(FanJsonElecCheck(int)));
      connect(Fan,SIGNAL(FanJsonElecCheckComp(int)),ElecValue,SLOT(setCurrentIndex(int)));
      connect(ElecValue,SIGNAL(activated(int)),Fan,SLOT(FanJsonElecMax(int)));
      connect(Fan,SIGNAL(FanJsonFanIDandElecMax(int,int)),this,SLOT(FanJsonFanIDandElecMax(int,int)));

//      QDoubleSpinBox* Ducy = new QDoubleSpinBox;
//      Ducy->setRange(0.f, 5000.f);


      NewQdoubleSpinbox* Ducy = new NewQdoubleSpinbox;
      Ducy->setValue(1.f);
      Ducy->setRange(0.f, 5.f);
      connect(ElecValue,SIGNAL(currentIndexChanged(int)),Ducy,SLOT(setMax(int)));


      //自动检测
      connect(Fan,SIGNAL(SetValueForTest(double)),Ducy,SLOT(setValue(double)));

      //根据更改的选项来传递当前的窗口号和对应的值
      connect(Ducy,SIGNAL(valueChanged(double)),Fan,SLOT(FanDucyValueSet(double)));
      connect(Ducy,SIGNAL(valueChanged(double)),Fan,SLOT(FanJsonDucy(double)));
      connect(Fan,SIGNAL(FanJsonFanIDandDucy(int,int)),this,SLOT(FanJsonFanIDandDucy(int,int)));

      QLabel * ThirdLable = new QLabel;
      ThirdLable->setText("V");

      QLabel * FourLable = new QLabel;
      FourLable->setText("转速反馈");

      QLineEdit* Speed = new QLineEdit;
      Speed->setReadOnly(true);
      connect(Fan,SIGNAL(SetValueForRealtime(QString)),Speed,SLOT(setText(QString)));//实时得到实际的数值
      connect(Fan,SIGNAL(TCPSetValueForRealtime(QString)),Speed,SLOT(setText(QString)));//实时得到实际的数值
      QLabel * FiveLable = new QLabel;
      FiveLable->setText("rpm");

      QGridLayout * test = new QGridLayout;
      test->addWidget(FirstLable,0,0);
      test->addWidget(ElecValue,0,1);
      test->addWidget(SecondLable,1,0);
      test->addWidget(Ducy,1,1);
      test->addWidget(ThirdLable,1,2);
      test->addWidget(FourLable,2,0);
      test->addWidget(Speed,2,1);
      test->addWidget(FiveLable,2,2);

      Fan->setLayout(test);
      Fan->setFixedSize(QSize(200,200));

      //当鼠标离开当前的风扇窗口时发送当前页面的所有指令信息
//      connect(Fan,SIGNAL(CursorLeaveout(int,int)),this,SLOT(SendFanControlCode(int,int)));

      return Fan;
}

//绘画四线Fan的单个窗口
FanMenuQGroupBox *HeatControlMenu::Fan4(int num , QString MaxElec)
{
      FanMenuQGroupBox *Fan = new FanMenuQGroupBox;
      Fan->setTitle(tr("四线风扇%1").arg(num));
      Fan->setObjectName(tr("%1").arg(num));//风扇id用于AT指令集

      QLabel * FirstLable = new QLabel;
      FirstLable->setText("电压设置");

      QLabel * SecondLable = new QLabel;
      SecondLable->setText("四线控制");
      QLineEdit* MaxEle = new QLineEdit;

      MaxEle->setText(MaxElec);
      MaxEle->setReadOnly(true);

      QDoubleSpinBox* Ducy = new QDoubleSpinBox;
      Ducy->setRange(0.f, 100.f);
      Ducy->setValue(1.f);
      Ducy->setSingleStep(0.1);

      //自动检测
      connect(Fan,SIGNAL(SetValueForTest(double)),Ducy,SLOT(setValue(double)));

      connect(Ducy,SIGNAL(valueChanged(double)),Fan,SLOT(FanDucyValueSet(double)));
      //根据更改的选项来传递当前的窗口号和对应的值
      connect(Ducy,SIGNAL(valueChanged(double)),Fan,SLOT(FanJsonDucy(double)));
      connect(Fan,SIGNAL(FanJsonFanIDandDucy(int,int)),this,SLOT(FanJsonFanIDandDucy(int,int)));

      QLabel * ThirdLable = new QLabel;
      ThirdLable->setText("%");

      QLabel * FourLable = new QLabel;
      FourLable->setText("转速反馈");

      QLineEdit* Speed = new QLineEdit;
      Speed->setReadOnly(true);
      connect(Fan,SIGNAL(SetValueForRealtime(QString)),Speed,SLOT(setText(QString)));//实时得到实际的数值
      connect(Fan,SIGNAL(TCPSetValueForRealtime(QString)),Speed,SLOT(setText(QString)));

      QLabel * FiveLable = new QLabel;
      FiveLable->setText("rpm");

      QLabel * SixLable = new QLabel;
      SixLable->setText("V");

      QGridLayout * test = new QGridLayout;
      test->addWidget(FirstLable,0,0);
      test->addWidget(MaxEle,0,1);
      test->addWidget(SixLable,0,2);

      test->addWidget(SecondLable,1,0);
      test->addWidget(Ducy,1,1);
      test->addWidget(ThirdLable,1,2);
      test->addWidget(FourLable,2,0);
      test->addWidget(Speed,2,1);
      test->addWidget(FiveLable,2,2);

      Fan->setLayout(test);
      Fan->setFixedSize(QSize(200,200));

      //当鼠标离开当前的风扇窗口时发送当前页面的所有指令信息
//      connect(Fan,SIGNAL(CursorLeaveout(int,int)),this,SLOT(SendFanControlCode(int,int)));

      return Fan;
}

//风扇参数传递
void HeatControlMenu::FanJsonFanIDandElecMax(int value,int value1)
{
   emit SendElecMaxValue(value,value1);
}

void HeatControlMenu::FanJsonFanIDandDucy(int value,int value1)
{
   emit SendDucyValue(value,value1);
}

//依据Json中的参数绘画Fan的单个窗格
FanMenuQGroupBox *HeatControlMenu::Fan(int FanID,int ContectType,int MaxElec,int FanDucy)
{
    if(ContectType == 3)
    {
        FanMenuQGroupBox *Fan = new FanMenuQGroupBox;
        Fan->setTitle(tr("三线风扇%1").arg(FanID));
        Fan->setObjectName(tr("%1").arg(FanID));//风扇id用于AT指令集

        QLabel * FirstLable = new QLabel;
        FirstLable->setText("电压设置");

        QLabel * SecondLable = new QLabel;
        SecondLable->setText("三线控制");

        QComboBox * ElecValue = new QComboBox;
        ElecValue->addItem("24V");
        ElecValue->addItem("12V");
        ElecValue->addItem("5V");

        if(MaxElec == 24)
            ElecValue->setCurrentIndex(0);
        else if(MaxElec == 12)
            ElecValue->setCurrentIndex(1);
        else
            ElecValue->setCurrentIndex(2);

        //根据更改的选项来传递当前的窗口号和对应的值
        connect(ElecValue,SIGNAL(currentIndexChanged(int)),Fan,SLOT(FanJsonElecCheck(int)));
        connect(Fan,SIGNAL(FanJsonElecCheckComp(int)),ElecValue,SLOT(setCurrentIndex(int)));
        connect(ElecValue,SIGNAL(activated(int)),Fan,SLOT(FanJsonElecMax(int)));
        connect(Fan,SIGNAL(FanJsonFanIDandElecMax(int,int)),this,SLOT(FanJsonFanIDandElecMax(int,int)));

        //三线风扇通过电压控制
        NewQdoubleSpinbox* Ducy = new NewQdoubleSpinbox;
        connect(ElecValue,SIGNAL(currentIndexChanged(int)),Ducy,SLOT(setMax(int)));

        
        Ducy->setValue(0);
        connect(Ducy,SIGNAL(valueChanged(double)),Fan,SLOT(FanDucyValueSet(double)));
        Ducy->setValue(FanDucy);


        //自动检测
        connect(Fan,SIGNAL(SetValueForTest(double)),Ducy,SLOT(setValue(double)));

        connect(Ducy,SIGNAL(valueChanged(double)),Fan,SLOT(FanJsonDucy(double)));
        connect(Fan,SIGNAL(FanJsonFanIDandDucy(int,int)),this,SLOT(FanJsonFanIDandDucy(int,int)));

        QLabel * ThirdLable = new QLabel;
        ThirdLable->setText("V");

        QLabel * FourLable = new QLabel;
        FourLable->setText("转速反馈");

        QLineEdit* Speed = new QLineEdit;
        Speed->setReadOnly(true);

        QLabel * FiveLable = new QLabel;
        FiveLable->setText("rpm");

        QGridLayout * test = new QGridLayout;
        test->addWidget(FirstLable,0,0);
        test->addWidget(ElecValue,0,1);

        test->addWidget(SecondLable,1,0);
        test->addWidget(Ducy,1,1);
        test->addWidget(ThirdLable,1,2);
        test->addWidget(FourLable,2,0);
        test->addWidget(Speed,2,1);
        test->addWidget(FiveLable,2,2);

        Fan->setLayout(test);
        Fan->setFixedSize(QSize(200,200));

        //当鼠标离开当前的风扇窗口时发送当前页面的所有指令信息
//        connect(Fan,SIGNAL(CursorLeaveout(int,int)),this,SLOT(SendFanControlCode(int,int)));

        return Fan;
    }
    else
    {
        FanMenuQGroupBox *Fan = new FanMenuQGroupBox;
        Fan->setTitle(tr("四线风扇%1").arg(FanID));
        Fan->setObjectName(tr("%1").arg(FanID));//风扇id用于AT指令集

        QLabel * FirstLable = new QLabel;
        FirstLable->setText("电压设置");

        QLabel * SecondLable = new QLabel;
        SecondLable->setText("四线控制");

        QLineEdit* MaxEle = new QLineEdit;
        MaxEle->setText(QString::number(MaxElec));
        MaxEle->setReadOnly(true);

        //根据更改的选项来传递当前的窗口号和对应的值
        NewQdoubleSpinbox* Ducy = new NewQdoubleSpinbox;
        Ducy->setRange(0.f, 100.f);


        //自动检测

        connect(Fan,SIGNAL(SetValueForTest(double)),Ducy,SLOT(setValue(double)));

        Ducy->setValue(0);
        connect(Ducy,SIGNAL(valueChanged(double)),Fan,SLOT(FanDucyValueSet(double)));
        Ducy->setValue(FanDucy);
        //根据更改的选项来传递当前的窗口号和对应的值
        connect(Ducy,SIGNAL(valueChanged(double)),Fan,SLOT(FanJsonDucy(double)));
        connect(Fan,SIGNAL(FanJsonFanIDandDucy(int,int)),this,SLOT(FanJsonFanIDandDucy(int,int)));

        QLabel * ThirdLable = new QLabel;
        ThirdLable->setText("%");

        QLabel * FourLable = new QLabel;
        FourLable->setText("转速反馈");

        QLineEdit* Speed = new QLineEdit;
        Speed->setReadOnly(true);

        QLabel * FiveLable = new QLabel;
        FiveLable->setText("rpm");

        QLabel * SixLable = new QLabel;
        SixLable->setText("V");

        QGridLayout * test = new QGridLayout;
        test->addWidget(FirstLable,0,0);
        test->addWidget(MaxEle,0,1);
        test->addWidget(SixLable,0,2);
        test->addWidget(SecondLable,1,0);
        test->addWidget(Ducy,1,1);
        test->addWidget(ThirdLable,1,2);
        test->addWidget(FourLable,2,0);
        test->addWidget(Speed,2,1);
        test->addWidget(FiveLable,2,2);

        Fan->setLayout(test);
        Fan->setFixedSize(QSize(200,200));

        //当鼠标离开当前的风扇窗口时发送当前页面的所有指令信息
//        connect(Fan,SIGNAL(CursorLeaveout(int,int)),this,SLOT(SendFanControlCode(int,int)));
        return Fan;
    }

 }

/*******************************************************Pump****************************************************/
//水泵页面添加代码
void HeatControlMenu::EditPumpMenu()
{
    PumpMenu->setLayout(PumpMenuGrid);
    PumpMenuScrollArea->setWidget(PumpMenu);
    grid->addWidget(PumpMenuScrollArea,0,1,1,1);
}

//添加Pump的函数
FanMenuQGroupBox *HeatControlMenu::PumpMenuAdd(FanMenuQGroupBox *&pPump,int Id )
{
    int GridX = (Id-1)/3;
    int GridY = (Id-1)%3;
    PumpMenuGrid->addWidget(pPump,GridX,GridY,Qt::AlignLeft);
}

//删除Pump的函数
FanMenuQGroupBox *HeatControlMenu::PumpMenuDel(FanMenuQGroupBox *&pPump1)
{
    delete pPump1;
}

//绘画水泵的单个界面
FanMenuQGroupBox *HeatControlMenu::Pump(int num1)
{
     FanMenuQGroupBox *Pump = new FanMenuQGroupBox;
//     Pump->setTitle(tr("水泵控制界面%1").arg(num1));
     Pump->setTitle(tr("水泵控制界面"));
     Pump->setObjectName(tr("%1").arg(num1));//风扇id用于AT指令集
     int nMin = 0;
     int nMax = 12;
     int nSingleStep = 1;

     QLabel * FirstLable = new QLabel;
     FirstLable->setText("电压值：");

     QLabel * SecondLable = new QLabel;
     SecondLable->setText(" V ");

     QLabel * ThirdLable = new QLabel;
     ThirdLable->setText("最大电压值：");

     QLabel * FourthLable = new QLabel;
     FourthLable->setText(" V ");

     //显示调度
     NewSpinBox *pSpinBox = new NewSpinBox;
     pSpinBox->setMinimum(nMin);  // 最小值
     pSpinBox->setMaximum(nMax);  // 最大值
     pSpinBox->setSingleStep(nSingleStep);  // 步长

     QComboBox * MaxValue = new QComboBox;
     MaxValue->addItem("12");
     MaxValue->addItem("24");


     pSpinBox->setValue(0);
     connect(MaxValue,SIGNAL(currentIndexChanged(int)),pSpinBox,SLOT(setMaxValue(int)));

     //自动化测试
     connect(Pump,SIGNAL(SetValueForTest(double)),pSpinBox,SLOT(setValuE(double)));


     connect(pSpinBox,SIGNAL(valueChanged(int)),Pump,SLOT(PumpJsonElec(int)));
     connect(Pump,SIGNAL(PumpJsonFanIDandElec(int,int)),this,SLOT(PumpJsonFanIDandElec(int,int)));

//     QPushButton * Button = new QPushButton;
//     Button->setText(QString("确定"));

     QGridLayout * test = new QGridLayout;
     test->addWidget(ThirdLable,0,0);
     test->addWidget(FourthLable,0,2);
     test->addWidget(MaxValue,0,1);
     test->addWidget(FirstLable,1,0);
     test->addWidget(SecondLable,1,2);
     test->addWidget(pSpinBox,1,1);
//     test->addWidget(Button,2,2);

     Pump->setLayout(test);
     Pump->setFixedSize(QSize(200,200));
     return Pump;
}

//依据Json文件生成对应的水泵窗口
FanMenuQGroupBox *HeatControlMenu::Pump(int PumpID,int ElecValue)
{
    FanMenuQGroupBox *Pump = new FanMenuQGroupBox;
//    Pump->setTitle(tr("水泵%1").arg(PumpID));
    Pump->setTitle(tr("水泵控制界面").arg(PumpID));
    Pump->setObjectName(tr("%1").arg(PumpID));//风扇id用于AT指令集

    int nMin = 0;
    int nMax = 12;
    int nSingleStep = 1;

    QLabel * FirstLable = new QLabel;
    FirstLable->setText("电压值：");

    QLabel * SecondLable = new QLabel;
    SecondLable->setText(" V ");

    QLabel * ThirdLable = new QLabel;
    ThirdLable->setText("最大电压值：");

    QLabel * FourthLable = new QLabel;
    FourthLable->setText(" V ");

    //显示调度
    NewSpinBox *pSpinBox = new NewSpinBox;
    pSpinBox->setMinimum(nMin);  // 最小值
    pSpinBox->setMaximum(nMax);
    pSpinBox->setSingleStep(nSingleStep);  // 步长

    QComboBox * MaxValue = new QComboBox;
    MaxValue->addItem("12");
    MaxValue->addItem("24");


    //自动检测
    pSpinBox->setValue(0);
    connect(Pump,SIGNAL(SetValueForTest(double)),pSpinBox,SLOT(setValuE(double)));
    pSpinBox->setValue(ElecValue);

    connect(MaxValue,SIGNAL(currentIndexChanged(int)),pSpinBox,SLOT(setMaxValue(int)));
    connect(pSpinBox,SIGNAL(valueChanged(int)),Pump,SLOT(PumpJsonElec(int)));
    connect(Pump,SIGNAL(PumpJsonFanIDandElec(int,int)),this,SLOT(PumpJsonFanIDandElec(int,int)));
//    QPushButton * Button = new QPushButton;
//    Button->setText(QString("确定"));

    QGridLayout * test = new QGridLayout;


    test->addWidget(ThirdLable,0,0);
    test->addWidget(FourthLable,0,2);
    test->addWidget(MaxValue,0,1);
    test->addWidget(FirstLable,1,0);
    test->addWidget(SecondLable,1,2);
    test->addWidget(pSpinBox,1,1);
//    test->addWidget(Button,2,2);

    Pump->setLayout(test);
    Pump->setFixedSize(QSize(200,200));
    return Pump;
}

//传递水泵界面参数到Json文件
void HeatControlMenu::PumpJsonFanIDandElec(int value,int value1)
{
   emit SendPumpValue(value,value1);
}



/*******************************************************TEC****************************************************/
//添加TEC界面到主界面
void HeatControlMenu::EditTECMenu()
{
    TECMenu->setLayout(TECMenuGrid);
    TECMenuScrollArea->setWidget(TECMenu);
    grid->addWidget(TECMenuScrollArea,1,0,1,1);
}

//添加TEC的函数
FanMenuQGroupBox *HeatControlMenu::TECMenuAdd(FanMenuQGroupBox *&pTEC,int Id )
{
    int GridX = (Id-1)/3;
    int GridY = (Id-1)%3;
    TECMenuGrid->addWidget(pTEC,GridX,GridY,Qt::AlignLeft);
}

//删除TEC的函数
FanMenuQGroupBox *HeatControlMenu::TECMenuDel(FanMenuQGroupBox *&pTEC1)
{
    delete pTEC1;
}

//绘制TEC的界面
FanMenuQGroupBox *HeatControlMenu::TEC(int num2)
{
     FanMenuQGroupBox *TEC = new FanMenuQGroupBox;
     TEC->setTitle(tr("TEC%1").arg(num2));
     TEC->setObjectName(tr("%1").arg(num2));//风扇id用于AT指令集

     QLabel * FirstLable = new QLabel;
     FirstLable->setText("冷面设置(℃):");

     NewSpinBox *pSpinBox = new NewSpinBox;
     pSpinBox->setMinimum(0);  // 最小值
     pSpinBox->setMaximum(45);  // 最大值
//     pSpinBox->setSingleStep(1);  // 步长

     //自动检测
     connect(TEC,SIGNAL(setSingle2(int)),pSpinBox,SLOT(setValue(int)));

     connect(TEC,SIGNAL(SetValueForTest(double)),pSpinBox,SLOT(setValuE(double)));
     connect(pSpinBox,SIGNAL(valueChanged(int)),TEC,SLOT(TECJsonElec(int)));
     connect(TEC,SIGNAL(TECJsonFanIDandElec(int,int)),this,SLOT(TECJsonFanIDandElec(int,int)));


     //TEC电压设置
     QLabel * FirstLable0 = new QLabel;
     FirstLable0->setText("电压设置(V)):");

     NewSpinBox *pSpinBox0 = new NewSpinBox;
     pSpinBox0->setMinimum(0);  // 最小值
     pSpinBox0->setMaximum(24);  // 最大值
//     pSpinBox0->setSingleStep(0.1);  // 步长

     connect(TEC,SIGNAL(setSingle3(int)),pSpinBox0,SLOT(setValue(int)));
     //自动检测
     connect(TEC,SIGNAL(SetValueForTest0(double)),pSpinBox0,SLOT(setValuE(double)));//需要修改
     connect(pSpinBox0,SIGNAL(valueChanged(int)),TEC,SLOT(TECJsonElecHeat(int)));
     connect(TEC,SIGNAL(TECJsonFanIDandElecHeat(int,int)),this,SLOT(TECJsonFanIDandElecHeat(int,int)));

     QLabel * SecondLable = new QLabel;
     SecondLable->setText("TEC冷面温度反馈:");

     QLineEdit* RealTemp = new QLineEdit;
     RealTemp->setPlaceholderText("实际冷面温度");
     RealTemp->setReadOnly(true);
     connect(TEC,SIGNAL(SetTECValueForRealtime(QString)),RealTemp,SLOT(setText(QString)));//实时得到实际的数值
     connect(TEC,SIGNAL(TCPSetTECValueForRealtime(QString)),RealTemp,SLOT(setText(QString)));


     QLabel * ThirdLable = new QLabel;
     ThirdLable->setText("TEC占空比反馈:");

     QLineEdit* DutyCycle  = new QLineEdit;
     DutyCycle->setPlaceholderText("TEC占空比");
     DutyCycle->setReadOnly(true);
     connect(TEC,SIGNAL(setTECforRealTimeDuty(QString)),DutyCycle,SLOT(setText(QString)));
     connect(TEC,SIGNAL(TCPsetTECforRealTimeDuty(QString)),DutyCycle,SLOT(setText(QString)));

//     QPushButton * Button = new QPushButton;
//     Button->setText(QString("开关"));

     QGridLayout * test = new QGridLayout;


     test->addWidget(FirstLable0,0,0);
     test->addWidget(pSpinBox0,0,1);
     test->addWidget(FirstLable,1,0);
     test->addWidget(pSpinBox,1,1);
     test->addWidget(SecondLable,2,0);
     test->addWidget(RealTemp,2,1);
     test->addWidget(ThirdLable,3,0);
     test->addWidget(DutyCycle,3,1);
     TEC->setLayout(test);
     TEC->setFixedSize(QSize(300,200));
     return TEC;
//     test->addWidget(RealTemp,0,2);
//     test->addWidget(SecondLable,1,0);
//     test->addWidget(pSpinBox1,1,1);
//     test->addWidget(RealTemp1,1,2);
//     test->addWidget(Button,2,1);
}

//依据Json生成TEC界面
FanMenuQGroupBox *HeatControlMenu::TEC(int TECID ,int ColdTemp,int TECValue)
{

    FanMenuQGroupBox *TEC = new FanMenuQGroupBox;
    TEC->setTitle(tr("TEC%1").arg(TECID));
    TEC->setObjectName(tr("%1").arg(TECID));//风扇id用于AT指令集

    QLabel * FirstLable = new QLabel;
    FirstLable->setText("冷面设置(℃):");

    NewSpinBox *pSpinBox = new NewSpinBox;
    pSpinBox->setMinimum(0);  // 最小值
    pSpinBox->setMaximum(45);  // 最大值
//    pSpinBox->setSingleStep(1);  // 步长


    connect(TEC,SIGNAL(setSingle2(int)),pSpinBox,SLOT(setValue(int)));
    //自动检测
    connect(TEC,SIGNAL(SetValueForTest(double)),pSpinBox,SLOT(setValuE(double)));
    pSpinBox->setValue(0);
    connect(pSpinBox,SIGNAL(valueChanged(int)),TEC,SLOT(TECJsonElec(int)));
    pSpinBox->setValue(ColdTemp);
    connect(TEC,SIGNAL(TECJsonFanIDandElec(int,int)),this,SLOT(TECJsonFanIDandElec(int,int)));

    //TEC电压设置
    QLabel * FirstLable0 = new QLabel;
    FirstLable0->setText("电压设置(V)):");

    NewSpinBox *pSpinBox0 = new NewSpinBox;
    pSpinBox0->setMinimum(0);  // 最小值
    pSpinBox0->setMaximum(24);  // 最大值
//    pSpinBox0->setSingleStep(0.1);  // 步长

    connect(TEC,SIGNAL(setSingle3(int)),pSpinBox0,SLOT(setValue(int)));
    //自动检测
    connect(TEC,SIGNAL(SetValueForTest0(double)),pSpinBox0,SLOT(setValuE(double)));
    pSpinBox0->setValue(0);
    connect(pSpinBox0,SIGNAL(valueChanged(int)),TEC,SLOT(TECJsonElecHeat(int)));
    pSpinBox0->setValue(TECValue);
    connect(TEC,SIGNAL(TECJsonFanIDandElecHeat(int,int)),this,SLOT(TECJsonFanIDandElecHeat(int,int)));

    QLabel * SecondLable = new QLabel;
    SecondLable->setText("TEC冷面温度反馈:");


    QLineEdit* RealTemp = new QLineEdit;
    RealTemp->setPlaceholderText("实际冷面温度");
    RealTemp->setReadOnly(true);
    connect(TEC,SIGNAL(SetTECValueForRealtime(QString)),RealTemp,SLOT(setText(QString)));
    connect(TEC,SIGNAL(TCPSetTECValueForRealtime(QString)),RealTemp,SLOT(setText(QString)));

    QLabel * ThirdLable = new QLabel;
    ThirdLable->setText("TEC占空比反馈:");

    QLineEdit* DutyCycle  = new QLineEdit;
    DutyCycle->setPlaceholderText("TEC占空比");
    DutyCycle->setReadOnly(true);
    connect(TEC,SIGNAL(setTECforRealTimeDuty(QString)),DutyCycle,SLOT(setText(QString)));
    connect(TEC,SIGNAL(TCPsetTECforRealTimeDuty(QString)),DutyCycle,SLOT(setText(QString)));


    QGridLayout * test = new QGridLayout;

    test->addWidget(FirstLable0,0,0);
    test->addWidget(pSpinBox0,0,1);
    test->addWidget(FirstLable,1,0);
    test->addWidget(pSpinBox,1,1);
    test->addWidget(SecondLable,2,0);
    test->addWidget(RealTemp,2,1);
    test->addWidget(ThirdLable,3,0);
    test->addWidget(DutyCycle,3,1);
    TEC->setLayout(test);
    TEC->setFixedSize(QSize(300,200));
    return TEC;
    /*************************************************************************************/

}

//传递TEC界面的参数到Json文件
void HeatControlMenu::TECJsonFanIDandElec(int value,int value1)
{
    emit SendTECColdValue(value,value1);
}
//(需要删除)
void HeatControlMenu::TECJsonFanIDandElecHeat(int value ,int value1)
{
    emit SendTECHeatValue(value,value1);
}

/*******************************************************Elec****************************************************/
//添加电流控制界面到主界面
void HeatControlMenu::EditElecMenu()
{
    ElecMenu->setLayout(ElecMenuGrid);
    ElecMenuScrollArea->setWidget(ElecMenu);
    grid->addWidget(ElecMenuScrollArea,1,1,1,1);
}

//添加Elec的函数
FanMenuQGroupBox *HeatControlMenu::ElecMenuAdd(FanMenuQGroupBox *&pElec ,int Id)
{
    int GridX = (Id-1)/3;
    int GridY = (Id-1)%3;
    ElecMenuGrid->addWidget(pElec,GridX,GridY,Qt::AlignLeft);
}

//删除Elec的函数
FanMenuQGroupBox *HeatControlMenu::ElecMenuDel(FanMenuQGroupBox *&pElec1)
{
    delete pElec1;
}

//绘制电流控制的界面
FanMenuQGroupBox *HeatControlMenu::Elec(int num3)
{
    int nMin = 0;
    int nMax = 38;
    int nSingleStep = 1;

    FanMenuQGroupBox *Elec = new FanMenuQGroupBox;
    switch (num3) {
    case 1:
        Elec->setTitle(tr("Laser1"));
        Elec->setObjectName(tr("%1").arg(num3));
        break;
    case 2:
        Elec->setTitle(tr("Laser2"));
        Elec->setObjectName(tr("%1").arg(num3));
        break;
    case 3:
        Elec->setTitle(tr("GreenLaser"));
        Elec->setObjectName(tr("%1").arg(num3));
        break;
    case 4:
        Elec->setTitle(tr("RedLaser"));
        Elec->setObjectName(tr("%1").arg(num3));
        break;
    default:
        break;
    }


    QLabel * FirstLable0 = new QLabel;
    FirstLable0->setText("最大电流：");

    QComboBox * MaxValue = new QComboBox;
    MaxValue->addItem("1.9A(19)");
    MaxValue->addItem("3.8A(38)");


    QLabel * FirstLable = new QLabel;
    FirstLable->setText("电流设置：");

    NewSpinBox* ElecControl = new NewSpinBox;
    ElecControl->setMinimum(nMin);  // 最小值
    ElecControl->setMaximum(nMax);
    ElecControl->setSingleStep(nSingleStep);  // 步长
    connect(MaxValue,SIGNAL(currentIndexChanged(int)),ElecControl,SLOT(setMaxElecValue(int)));


    //自动检测
    connect(Elec,SIGNAL(SetValueForTest(double)),ElecControl,SLOT(setValuE(double)));

    connect(ElecControl,SIGNAL(valueChanged(int)),Elec,SLOT(ElecJsonElec(int)));
    connect(Elec,SIGNAL(ElecJsonFanIDandElec(int,int)),this,SLOT(ElecJsonFanIDandElec(int,int)));

//    QLabel * SecondLable = new QLabel;
//    SecondLable->setText("实际电流：");

//    QLineEdit* RealElec = new QLineEdit;
//    RealElec->setPlaceholderText("实际电流");
//    RealElec->setReadOnly(true);


//    QLabel * ThirdLable = new QLabel;
//    ThirdLable->setText("色轮转速：");

//    QLineEdit* RealSpeed = new QLineEdit;
//    RealSpeed->setPlaceholderText("色轮转速");
//    RealSpeed->setReadOnly(true);

//    QPushButton * Button = new QPushButton;
//    Button->setText(QString("确定"));


    QGridLayout * test = new QGridLayout;

    test->addWidget(FirstLable0,0,0);
    test->addWidget(MaxValue,0,1);
    test->addWidget(FirstLable,1,0);
    test->addWidget(ElecControl,1,1);
//    test->addWidget(SecondLable,2,0);
//    test->addWidget(RealElec,2,1);
//    test->addWidget(ThirdLable,3,0);
//    test->addWidget(RealSpeed,3,1);
//    test->addWidget(Button,4,1);

    Elec->setLayout(test);
    Elec->setFixedSize(QSize(200,200));
    return Elec;
}

//依据Json生成对应的电流界面
FanMenuQGroupBox *HeatControlMenu::Elec(int ElecID, int ElecValue)
{
    double nMin = 0;
    double nMax = 38;
    double nSingleStep = 1;

    FanMenuQGroupBox *Elec = new FanMenuQGroupBox;
//    Elec->setTitle(tr("Elec%1").arg(ElecID));
//    Elec->setObjectName(tr("%1").arg(ElecID));//风扇id用于AT指令集
    switch (ElecID) {
    case 1:
        Elec->setTitle(tr("Laser1"));
        Elec->setObjectName(tr("%1").arg(ElecID));
        break;
    case 2:
        Elec->setTitle(tr("Laser2"));
        Elec->setObjectName(tr("%1").arg(ElecID));
        break;
    case 3:
        Elec->setTitle(tr("GreenLaser"));
        Elec->setObjectName(tr("%1").arg(ElecID));
        break;
    case 4:
        Elec->setTitle(tr("RedLaser"));
        Elec->setObjectName(tr("%1").arg(ElecID));
        break;
    default:
        break;
    }

    QLabel * FirstLable0 = new QLabel;
    FirstLable0->setText("最大电流：");

    QComboBox * MaxValue = new QComboBox;
    MaxValue->addItem("1.9A(19)");
    MaxValue->addItem("3.8A(38)");

    QLabel * FirstLable = new QLabel;
    FirstLable->setText("电流设置：");

    NewSpinBox* ElecControl = new NewSpinBox;
    ElecControl->setMinimum(nMin);  // 最小值
    ElecControl->setMaximum(nMax);  // 最大值
    ElecControl->setSingleStep(nSingleStep);  // 步长

    //自动检测
    connect(Elec,SIGNAL(SetValueForTest(double)),ElecControl,SLOT(setValuE(double)));

    connect(MaxValue,SIGNAL(currentIndexChanged(int)),ElecControl,SLOT(setMaxElecValue(int)));
    ElecControl->setValue(0);
    connect(ElecControl,SIGNAL(valueChanged(int)),Elec,SLOT(ElecJsonElec(int)));
    ElecControl->setValue(ElecValue);
    connect(Elec,SIGNAL(ElecJsonFanIDandElec(int,int)),this,SLOT(ElecJsonFanIDandElec(int,int)));

//    QLabel * SecondLable = new QLabel;
//    SecondLable->setText("实际电流：");

//    QLineEdit* RealElec = new QLineEdit;
//    RealElec->setPlaceholderText("实际电流");
//    RealElec->setReadOnly(true);


//    QLabel * ThirdLable = new QLabel;
//    ThirdLable->setText("色轮转速：");

//    QLineEdit* RealSpeed = new QLineEdit;
//    RealSpeed->setPlaceholderText("色轮转速");
//    RealSpeed->setReadOnly(true);


//    QPushButton * Button = new QPushButton;
//    Button->setText(QString("确定"));


    QGridLayout * test = new QGridLayout;

    test->addWidget(FirstLable0,0,0);
    test->addWidget(MaxValue,0,1);
    test->addWidget(FirstLable,1,0);
    test->addWidget(ElecControl,1,1);
//    test->addWidget(SecondLable,2,0);
//    test->addWidget(RealElec,2,1);
//    test->addWidget(ThirdLable,3,0);
//    test->addWidget(RealSpeed,3,1);
//    test->addWidget(Button,4,1);

    Elec->setLayout(test);
    Elec->setFixedSize(QSize(200,200));
    return Elec;
}

//传递电流界面的参数
void HeatControlMenu::ElecJsonFanIDandElec(int value ,int value1)
{
      emit SendElecValue(value,value1);
}

//串口界面生成代码
void *HeatControlMenu::Uart()
{
    grid->addWidget(UartPort,0,2,1,1);
}

//Tcp网络客户端生成代码
void *HeatControlMenu::NetWorkClientEdict()
{

    grid->addWidget(NetWorkClient,1,2,1,1);
//    grid->addWidget(NetWorkClient2,1,2,1,1);
}

HeatControlMenu::~HeatControlMenu()
{

}
