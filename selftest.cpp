#include "selftest.h"
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
#include "newspinbox.h"




SelfTestWidow::SelfTestWidow(QWidget *parent) :
    QWidget(parent)
{
      //自动检测总界面
      grid = new QGridLayout(this);

      //风扇自动测试界面
      SelfTestWindow = new QScrollArea(this);//(tr("风扇组"));
      SelfTestWindow->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, \
                                                    QSizePolicy::Expanding));
      SelfTestWindow->setWidgetResizable(true);
      SelfTestWindow->setMaximumSize(QSize(1000,1000));
      SelfTestMENU = new QWidget;//(tr("风扇组"));
      SelfTestMENU->setMaximumSize(QSize(1000,1000));
      SelfTestMenuGrid = new QGridLayout;
      SelfTestMenuGrid->setSpacing(3);

      //水泵自动测试界面
      SelfTestPumpWindow = new QScrollArea(this);//(tr("水泵组"));
      SelfTestPumpWindow->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, \
                                                    QSizePolicy::Expanding));
      SelfTestPumpWindow->setWidgetResizable(true);
      SelfTestPumpWindow->setMaximumSize(QSize(1000,1000));
      SelfTestPumpMENU = new QWidget;//(tr("风扇组"));
      SelfTestPumpMENU->setMaximumSize(QSize(1000,1000));
      SelfTestPumpMenuGrid = new QGridLayout;
      SelfTestPumpMenuGrid->setSpacing(3);

      //TEC自动测试界面
      SelfTestTECWindow = new QScrollArea(this);//(tr("水泵组"));
      SelfTestTECWindow->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, \
                                                    QSizePolicy::Expanding));
      SelfTestTECWindow->setWidgetResizable(true);
      SelfTestTECWindow->setMaximumSize(QSize(1000,1000));
      SelfTestTECMENU = new QWidget;//(tr("风扇组"));
      SelfTestTECMENU->setMaximumSize(QSize(1000,1000));
      SelfTestTECMenuGrid = new QGridLayout;
      SelfTestTECMenuGrid->setSpacing(3);

      //Elec自动测试界面
      SelfTestElecWindow = new QScrollArea(this);//(tr("水泵组"));
      SelfTestElecWindow->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, \
                                                    QSizePolicy::Expanding));
      SelfTestElecWindow->setWidgetResizable(true);
      SelfTestElecWindow->setMaximumSize(QSize(1000,1000));
      SelfTestElecMENU = new QWidget;//(tr("风扇组"));
      SelfTestElecMENU->setMaximumSize(QSize(1000,1000));
      SelfTestElecMenuGrid = new QGridLayout;
      SelfTestElecMenuGrid->setSpacing(3);


}

//风扇自动测试设置界面
FanMenuQGroupBox *SelfTestWidow::FanSelfTestWindow(int Id)
{

        FanMenuQGroupBox *FanSelfTestWindow = new FanMenuQGroupBox;
        FanSelfTestWindow->setTitle(tr("风扇%1").arg(Id));
        FanSelfTestWindow->setObjectName(tr("%1").arg(Id));


        NewSpinBox* MinuMum = new NewSpinBox;

        MinuMum->setReadOnly(true);
    //    MinuMum->setMaximum(5000);

        NewSpinBox* MaxMum = new NewSpinBox;
        MaxMum->setReadOnly(true);
    //    MaxMum->setMaximum(5000);

        MinuMum->setMaximum(24);
        MaxMum->setMaximum(24);


    //    connect(FanSelfTestWindow,SIGNAL(SetselftestFanMaximumValue(int)),MinuMum,SLOT(SETMAX(int)));
    //    connect(FanSelfTestWindow,SIGNAL(SetselftestFanMaximumValue(int)),MaxMum,SLOT(SETMAX(int)));

        NewSpinBox* Step = new NewSpinBox;//最大值只能是前两个框的差值

        QxtSpanSlider*  horizontalSlider = new QxtSpanSlider;

        horizontalSlider->setSliderDown(true);

        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setGeometry(0,0,500,6);

        horizontalSlider->setHandleMovementMode(QxtSpanSlider::NoOverlapping);
        horizontalSlider->setMaximum(24);
        horizontalSlider->setLowerValue(0);
        horizontalSlider->setUpperValue(24);

        //根据滑动条设置最大最小值和步长
        connect(horizontalSlider,SIGNAL(lowerValueChanged(int)),MinuMum,SLOT(setValue(int)));
        connect(horizontalSlider,SIGNAL(upperValueChanged(int)),MaxMum,SLOT(setValue(int)));
        connect(MinuMum,SIGNAL(valueChanged(int)),Step,SLOT(Recordlower(int)));
        connect(MaxMum,SIGNAL(valueChanged(int)),Step,SLOT(Recordupper(int)));
        connect(MinuMum,SIGNAL(valueChanged(int)),Step,SLOT(setValueSource()));
        connect(MaxMum,SIGNAL(valueChanged(int)),Step,SLOT(setValueSource()));
        connect(Step,SIGNAL(valueChanged(int)),Step,SLOT(setMaximuStep(int)));

        //发送参数到对应的数组中(单独发送)
        connect(MinuMum,SIGNAL(valueChanged(int)),FanSelfTestWindow,SLOT(SendFanSelfmin(int)));
        connect(MaxMum,SIGNAL(valueChanged(int)),FanSelfTestWindow,SLOT(SendFanSelfmax(int)));
        connect(Step,SIGNAL(valueChanged(int)),FanSelfTestWindow,SLOT(SendFanSelfstep(int)));

        connect(FanSelfTestWindow,SIGNAL(SendFanmin(int,int)),this,SLOT(SendFanmin(int,int)));
        connect(FanSelfTestWindow,SIGNAL(SendFanmax(int,int)),this,SLOT(SendFanmax(int,int)));
        connect(FanSelfTestWindow,SIGNAL(SendFanstep(int,int)),this,SLOT(SendFanstep(int,int)));

        MaxMum->setValue(24);
        MinuMum->setValue(0);
        Step->setMinimum(1);

        QLabel * Lable1 = new QLabel;
        Lable1->setText("Min:");
        QLabel * Lable2 = new QLabel;
        Lable2->setText("Max:");
        QLabel * Lable3 = new QLabel;
        Lable3->setText("Step:");

        QGridLayout * test = new QGridLayout;

        test->addWidget(horizontalSlider,0,0,1,4);
        test->addWidget(Lable1,1,0);
        test->addWidget(MinuMum,1,1);
        test->addWidget(Lable2,1,2);
        test->addWidget(MaxMum,1,3);
        test->addWidget(Lable3,2,0);
        test->addWidget(Step,2,1);

        FanSelfTestWindow->setLayout(test);
        FanSelfTestWindow->setFixedSize(QSize(250,250));

    return FanSelfTestWindow;
}

//水泵检测页面
FanMenuQGroupBox *SelfTestWidow::PumpSelfTestWindow(int Id)
{
    FanMenuQGroupBox *PumpSelfTestWindow = new FanMenuQGroupBox;
    PumpSelfTestWindow->setTitle(tr("水泵%1").arg(Id));
    PumpSelfTestWindow->setObjectName(tr("%1").arg(Id));


    NewSpinBox* MinuMum = new NewSpinBox;
    MinuMum->setReadOnly(true);
    MinuMum->setMaximum(24);

    NewSpinBox* MaxMum = new NewSpinBox;
    MaxMum->setReadOnly(true);
    MaxMum->setMaximum(24);

    NewSpinBox* Step = new NewSpinBox;//最大值只能是前两个框的差值


    QxtSpanSlider*  horizontalSlider = new QxtSpanSlider;

    horizontalSlider->setSliderDown(true);

    horizontalSlider->setOrientation(Qt::Horizontal);
    horizontalSlider->setGeometry(0,0,500,6);


    horizontalSlider->setHandleMovementMode(QxtSpanSlider::NoOverlapping);
    horizontalSlider->setMaximum(24);
    horizontalSlider->setLowerValue(0);
    horizontalSlider->setUpperValue(24);

    //根据滑动条设置最大最小值和步长
    connect(horizontalSlider,SIGNAL(lowerValueChanged(int)),MinuMum,SLOT(setValue(int)));
    connect(horizontalSlider,SIGNAL(upperValueChanged(int)),MaxMum,SLOT(setValue(int)));
    connect(MinuMum,SIGNAL(valueChanged(int)),Step,SLOT(Recordlower(int)));
    connect(MaxMum,SIGNAL(valueChanged(int)),Step,SLOT(Recordupper(int)));
    connect(MinuMum,SIGNAL(valueChanged(int)),Step,SLOT(setValueSource()));
    connect(MaxMum,SIGNAL(valueChanged(int)),Step,SLOT(setValueSource()));
    connect(Step,SIGNAL(valueChanged(int)),Step,SLOT(setMaximuStep(int)));



    //发送参数到对应的数组中(单独发送)
    connect(MinuMum,SIGNAL(valueChanged(int)),PumpSelfTestWindow,SLOT(SendPumpSelfmin(int)));
    connect(MaxMum,SIGNAL(valueChanged(int)),PumpSelfTestWindow,SLOT(SendPumpSelfmax(int)));
    connect(Step,SIGNAL(valueChanged(int)),PumpSelfTestWindow,SLOT(SendPumpSelfstep(int)));

    connect(PumpSelfTestWindow,SIGNAL(SendPumpmin(int,int)),this,SLOT(SendPumpmin(int,int)));
    connect(PumpSelfTestWindow,SIGNAL(SendPumpmax(int,int)),this,SLOT(SendPumpmax(int,int)));
    connect(PumpSelfTestWindow,SIGNAL(SendPumpstep(int,int)),this,SLOT(SendPumpstep(int,int)));

    MaxMum->setValue(24);
    MinuMum->setValue(0);
    Step->setMinimum(1);

    QLabel * Lable1 = new QLabel;
    Lable1->setText("Min:");
    QLabel * Lable2 = new QLabel;
    Lable2->setText("Max:");
    QLabel * Lable3 = new QLabel;
    Lable3->setText("Step:");

    QGridLayout * test = new QGridLayout;

    test->addWidget(horizontalSlider,0,0,1,4);
    test->addWidget(Lable1,1,0);
    test->addWidget(MinuMum,1,1);
    test->addWidget(Lable2,1,2);
    test->addWidget(MaxMum,1,3);
    test->addWidget(Lable3,2,0);
    test->addWidget(Step,2,1);

    PumpSelfTestWindow->setLayout(test);
    PumpSelfTestWindow->setFixedSize(QSize(250,250));
    return PumpSelfTestWindow;
}

void SelfTestWidow::closeEvent()
{
    this->hide();
}




//TEC自动控制界面
FanMenuQGroupBox *SelfTestWidow::TECSelfTestWindow(int Id)
{
    FanMenuQGroupBox *TECSelfTestWindow = new FanMenuQGroupBox;
    TECSelfTestWindow->setTitle(tr("TEC%1").arg(Id));
    TECSelfTestWindow->setObjectName(tr("%1").arg(Id));


    NewSpinBox* MinuMum = new NewSpinBox;
    MinuMum->setReadOnly(true);
    MinuMum->setMaximum(45);

    NewSpinBox* MaxMum = new NewSpinBox;
    MaxMum->setReadOnly(true);
    MaxMum->setMaximum(45);

    NewSpinBox* Step = new NewSpinBox;//最大值只能是前两个框的差值

    QxtSpanSlider*  horizontalSlider = new QxtSpanSlider;

    horizontalSlider->setSliderDown(true);
    horizontalSlider->setOrientation(Qt::Horizontal);
    horizontalSlider->setGeometry(0,0,500,6);


    horizontalSlider->setHandleMovementMode(QxtSpanSlider::NoOverlapping);
    horizontalSlider->setMaximum(45);
    horizontalSlider->setLowerValue(0);
    horizontalSlider->setUpperValue(45);

    //根据滑动条设置最大最小值和步长
    connect(horizontalSlider,SIGNAL(lowerValueChanged(int)),MinuMum,SLOT(setValue(int)));
    connect(horizontalSlider,SIGNAL(upperValueChanged(int)),MaxMum,SLOT(setValue(int)));
    connect(MinuMum,SIGNAL(valueChanged(int)),Step,SLOT(Recordlower(int)));
    connect(MaxMum,SIGNAL(valueChanged(int)),Step,SLOT(Recordupper(int)));
    connect(MinuMum,SIGNAL(valueChanged(int)),Step,SLOT(setValueSource()));
    connect(MaxMum,SIGNAL(valueChanged(int)),Step,SLOT(setValueSource()));
    connect(Step,SIGNAL(valueChanged(int)),Step,SLOT(setMaximuStep(int)));



    //发送参数到对应的数组中(单独发送)
    connect(MinuMum,SIGNAL(valueChanged(int)),TECSelfTestWindow,SLOT(SendTECSelfmin(int)));
    connect(MaxMum,SIGNAL(valueChanged(int)),TECSelfTestWindow,SLOT(SendTECSelfmax(int)));
    connect(Step,SIGNAL(valueChanged(int)),TECSelfTestWindow,SLOT(SendTECSelfstep(int)));

    connect(TECSelfTestWindow,SIGNAL(SendTECmin(int,int)),this,SLOT(SendTECmin(int,int)));
    connect(TECSelfTestWindow,SIGNAL(SendTECmax(int,int)),this,SLOT(SendTECmax(int,int)));
    connect(TECSelfTestWindow,SIGNAL(SendTECstep(int,int)),this,SLOT(SendTECstep(int,int)));

    MaxMum->setValue(45);
    MinuMum->setValue(0);
    Step->setMaximum(1);//设置最小步长为1


    QLabel * Lable1 = new QLabel;
    Lable1->setText("Min:");
    QLabel * Lable2 = new QLabel;
    Lable2->setText("Max:");
    QLabel * Lable3 = new QLabel;
    Lable3->setText("Step:");

    QGridLayout * test = new QGridLayout;

    test->addWidget(horizontalSlider,0,0,1,4);
    test->addWidget(Lable1,1,0);
    test->addWidget(MinuMum,1,1);
    test->addWidget(Lable2,1,2);
    test->addWidget(MaxMum,1,3);
    test->addWidget(Lable3,2,0);
    test->addWidget(Step,2,1);

    TECSelfTestWindow->setLayout(test);
    TECSelfTestWindow->setFixedSize(QSize(250,250));
    return TECSelfTestWindow;
}

//电流自动控制界面
FanMenuQGroupBox *SelfTestWidow::ElecSelfTestWindow(int Id)
{
    FanMenuQGroupBox *ElecSelfTestWindow = new FanMenuQGroupBox;
    ElecSelfTestWindow->setTitle(tr("电流%1").arg(Id));
    ElecSelfTestWindow->setObjectName(tr("%1").arg(Id));


    NewSpinBox* MinuMum = new NewSpinBox;
    MinuMum->setReadOnly(true);
    MinuMum->setMaximum(38);

    NewSpinBox* MaxMum = new NewSpinBox;
    MaxMum->setReadOnly(true);
    MaxMum->setMaximum(38);

    NewSpinBox* Step = new NewSpinBox;//最大值只能是前两个框的差值


    QxtSpanSlider*  horizontalSlider = new QxtSpanSlider;
    horizontalSlider->setSliderDown(true);
    horizontalSlider->setOrientation(Qt::Horizontal);
    horizontalSlider->setGeometry(0,0,500,6);

    horizontalSlider->setHandleMovementMode(QxtSpanSlider::NoOverlapping);
    horizontalSlider->setMaximum(38);
    horizontalSlider->setLowerValue(0);
    horizontalSlider->setUpperValue(38);

    //根据滑动条设置最大最小值和步长
    connect(horizontalSlider,SIGNAL(lowerValueChanged(int)),MinuMum,SLOT(setValue(int)));
    connect(horizontalSlider,SIGNAL(upperValueChanged(int)),MaxMum,SLOT(setValue(int)));
    connect(MinuMum,SIGNAL(valueChanged(int)),Step,SLOT(Recordlower(int)));
    connect(MaxMum,SIGNAL(valueChanged(int)),Step,SLOT(Recordupper(int)));
    connect(MinuMum,SIGNAL(valueChanged(int)),Step,SLOT(setValueSource()));
    connect(MaxMum,SIGNAL(valueChanged(int)),Step,SLOT(setValueSource()));
    connect(Step,SIGNAL(valueChanged(int)),Step,SLOT(setMaximuStep(int)));

    //发送参数到对应的数组中(单独发送)
    connect(MinuMum,SIGNAL(valueChanged(int)),ElecSelfTestWindow,SLOT(SendElecSelfmin(int)));
    connect(MaxMum,SIGNAL(valueChanged(int)),ElecSelfTestWindow,SLOT(SendElecSelfmax(int)));
    connect(Step,SIGNAL(valueChanged(int)),ElecSelfTestWindow,SLOT(SendElecSelfstep(int)));

    connect(ElecSelfTestWindow,SIGNAL(SendElecmin(int,int)),this,SLOT(SendElecmin(int,int)));
    connect(ElecSelfTestWindow,SIGNAL(SendElecmax(int,int)),this,SLOT(SendElecmax(int,int)));
    connect(ElecSelfTestWindow,SIGNAL(SendElecstep(int,int)),this,SLOT(SendElecstep(int,int)));

    MaxMum->setValue(38);
    MinuMum->setValue(0);
    Step->setMaximum(1);//设置最小步长为1




    QLabel * Lable1 = new QLabel;
    Lable1->setText("Min:");
    QLabel * Lable2 = new QLabel;
    Lable2->setText("Max:");
    QLabel * Lable3 = new QLabel;
    Lable3->setText("Step:");

    QGridLayout * test = new QGridLayout;

    test->addWidget(horizontalSlider,0,0,1,4);
    test->addWidget(Lable1,1,0);
    test->addWidget(MinuMum,1,1);
    test->addWidget(Lable2,1,2);
    test->addWidget(MaxMum,1,3);
    test->addWidget(Lable3,2,0);
    test->addWidget(Step,2,1);

    ElecSelfTestWindow->setLayout(test);
    ElecSelfTestWindow->setFixedSize(QSize(250,250));
    return ElecSelfTestWindow;
}

//传递风扇的自动检测参数
void SelfTestWidow::SendFanmin(int Id,int value)
{
    emit SendFanminComp(Id,value);
}
void SelfTestWidow::SendFanmax(int Id,int value)
{
    emit SendFanmaxComp(Id,value);
}
void SelfTestWidow::SendFanstep(int Id,int value)
{
    emit SendFanstepComp(Id,value);
}


//传递水泵的自动检测参数
void SelfTestWidow::SendPumpmin(int Id,int value)
{
    emit SendPumpminComp(Id,value);
}
void SelfTestWidow::SendPumpmax(int Id,int value)
{
    emit SendPumpmaxComp(Id,value);
}
void SelfTestWidow::SendPumpstep(int Id,int value)
{
    emit SendPumpstepComp(Id,value);
}

//传递TEC的自动检测参数
void SelfTestWidow::SendTECmin(int Id,int value)
{
    emit SendTECminComp(Id,value);
}
void SelfTestWidow::SendTECmax(int Id,int value)
{
    emit SendTECmaxComp(Id,value);
}
void SelfTestWidow::SendTECstep(int Id,int value)
{
    emit SendTECstepComp(Id,value);
}

//传递Elec的自动检测参数
void SelfTestWidow::SendElecmin(int Id,int value)
{
    emit SendElecminComp(Id,value);
}
void SelfTestWidow::SendElecmax(int Id,int value)
{
    emit SendElecmaxComp(Id,value);
}
void SelfTestWidow::SendElecstep(int Id,int value)
{
    emit SendElecstepComp(Id,value);
}



//风扇自动控制界面生成
void SelfTestWidow::EditSelfMenu()
{
    SelfTestMENU->setLayout(SelfTestMenuGrid);
    SelfTestWindow->setWidget(SelfTestMENU);
    grid->addWidget(SelfTestWindow,1,1,1,1);
}

FanMenuQGroupBox *SelfTestWidow::EditSelfMenuAdd(FanMenuQGroupBox *&pFan,int Id)
{
    int GridX = (Id-1)/4;
    int GridY = (Id-1)%4;
    SelfTestMenuGrid->addWidget(pFan,GridX,GridY,Qt::AlignLeft);
}

FanMenuQGroupBox *SelfTestWidow::EditSelfMenuDel(FanMenuQGroupBox *&pFan1)
{
    delete pFan1;
}

//水泵自动控制生成
void SelfTestWidow::EditSelfPumpMenu()
{
    SelfTestPumpMENU->setLayout(SelfTestPumpMenuGrid);
    SelfTestPumpWindow->setWidget(SelfTestPumpMENU);
    grid->addWidget(SelfTestPumpWindow,0,1,1,1);
}

FanMenuQGroupBox *SelfTestWidow::EditSelfPumpMenuAdd(FanMenuQGroupBox *&pFan,int Id)
{
    int GridX = (Id-1)/4;
    int GridY = (Id-1)%4;
    SelfTestPumpMenuGrid->addWidget(pFan,GridX,GridY,Qt::AlignLeft);
}

FanMenuQGroupBox *SelfTestWidow::EditSelfPumpMenuDel(FanMenuQGroupBox *&pFan1)
{
    delete pFan1;
}


//TEC自动控制生成
void SelfTestWidow::EditSelfTECMenu()
{
    SelfTestTECMENU->setLayout(SelfTestTECMenuGrid);
    SelfTestTECWindow->setWidget(SelfTestTECMENU);
    grid->addWidget(SelfTestTECWindow,0,0,1,1);
}

FanMenuQGroupBox *SelfTestWidow::EditSelfTECMenuAdd(FanMenuQGroupBox *&pFan,int Id)
{
    int GridX = (Id-1)/4;
    int GridY = (Id-1)%4;
    SelfTestTECMenuGrid->addWidget(pFan,GridX,GridY,Qt::AlignLeft);
}

FanMenuQGroupBox *SelfTestWidow::EditSelfTECMenuDel(FanMenuQGroupBox *&pFan1)
{
    delete pFan1;
}


//Elec自动控制生成
void SelfTestWidow::EditSelfElecMenu()
{
    SelfTestElecMENU->setLayout(SelfTestElecMenuGrid);
    SelfTestElecWindow->setWidget(SelfTestElecMENU);
    grid->addWidget(SelfTestElecWindow,1,0,1,1);
}

FanMenuQGroupBox *SelfTestWidow::EditSelfElecMenuAdd(FanMenuQGroupBox *&pFan,int Id)
{
    int GridX = (Id-1)/4;
    int GridY = (Id-1)%4;
    SelfTestElecMenuGrid->addWidget(pFan,GridX,GridY,Qt::AlignLeft);
}

FanMenuQGroupBox *SelfTestWidow::EditSelfElecMenuDel(FanMenuQGroupBox *&pFan1)
{
    delete pFan1;
}


//总的界面
void SelfTestWidow::SelfTestMenu()
{
    Timecount = new timecount;
    Timecount->setEnabled(false);
    connect(Timecount,SIGNAL(Runtime(double)),this,SLOT(SendRunTime(double)));
    connect(Timecount,SIGNAL(Clicked(bool)),this,SLOT(RunTest(bool)));
    grid->addWidget(Timecount,2,0,1,1);
    //改为计时器

    setLayout(grid);
    setWindowTitle(tr("自动控制界面"));
    resize(800,800);

}

void SelfTestWidow::SendRunTime(double value)
{
    emit SendTestRunTime(value*1000);//对应单位为1000为1毫秒
}

void SelfTestWidow::RunTest(bool value)
{
    emit SendRunTest(value);
}

SelfTestWidow::~SelfTestWidow()
{

}
