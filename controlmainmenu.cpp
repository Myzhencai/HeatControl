#include "controlmainmenu.h"
#include "ui_controlmainmenu.h"
#include<QToolButton>
#include<heatcontrolmenu.h>

ControlMainMenu::ControlMainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlMainMenu)
{
    ui->setupUi(this);
    vLayout = new QVBoxLayout(this);
    tabW = new QTabWidget();
    vLayout->addWidget(tabW);
}


void ControlMainMenu::addControlMenuTab(HeatControlMenu* value, int number)
{
    tabW->insertTab(number,value,QString(" 测试机器控制界面"));
}


void ControlMainMenu::onTabCloseRequested( int value)
{
//    qDebug()<<value;
    tabW->removeTab(value-1);
}

void ControlMainMenu::showControlMenu(int value)
{
    tabW->setCurrentIndex(value-1);
}


ControlMainMenu::~ControlMainMenu()
{
    delete ui;
}
