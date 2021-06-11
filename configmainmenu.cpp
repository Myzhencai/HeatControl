#include "configmainmenu.h"
#include "ui_configmainmenu.h"
#include "mainmenu.h"
#include "heatcontrolmenu.h"
#include "welcompage.h"
#include<QTimer>

ConfigMainMenu::ConfigMainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigMainMenu)
{
    ui->setupUi(this);

    vLayout = new QVBoxLayout(this);
    tabW = new QTabWidget();
    tabW->setTabsClosable(true);
    tabW->insertTab(0,new WelcomPage(),QString("软件欢迎界面"));
    QToolButton* m_tabClosebutton = new QToolButton(this);
    m_tabClosebutton->setIcon(QApplication::style()->standardIcon(QStyle::SP_DesktopIcon));

    MainControlMenu = new ControlMainMenu();
    MainControlMenu->show();
    tabW->setCornerWidget(m_tabClosebutton);


    connect(m_tabClosebutton, &QToolButton::clicked, this ,&ConfigMainMenu::addWidget);
    connect(this,SIGNAL(addControlMenuTab(HeatControlMenu*,int)),MainControlMenu,SLOT(addControlMenuTab(HeatControlMenu*,int)));
    connect(tabW,SIGNAL(tabCloseRequested(int)),this,SLOT(onTabCloseRequested(int)));
    connect(tabW,SIGNAL(tabCloseRequested(int)),MainControlMenu,SLOT(onTabCloseRequested(int)));
    connect(tabW,SIGNAL(tabBarClicked(int)),MainControlMenu,SLOT(showControlMenu(int)));
    vLayout->addWidget(tabW);

}

void ConfigMainMenu::onTabCloseRequested( int value)
{

    if(value>0){
       tabW->removeTab(value);
       ControlMainMenuCreat[value-1]->closeEvent();
//       delete ControlMainMenuCreat[value-1];
       ControlMainMenuCreat[value-1]->~MainMenu();
       ControlMainMenuCreat.replace(value-1,NULL);

       for(value-1;value<Count;value++)
       {
           ControlMainMenuCreat.replace(value-1,ControlMainMenuCreat[value]);

       }

       ControlMainMenuCreat.replace(Count-1,NULL);
       Count --;
    }
}

void ConfigMainMenu::addWidget(){

    if(Count == 5){
        return;
    }
    Count++;
    qDebug()<<"count is:"<<Count;
    MainMenu* TempMainMenu = new MainMenu();
    tabW->insertTab(Count,TempMainMenu,QString(" 测试样机配置界面"));
    emit addControlMenuTab(TempMainMenu->ControlMenu,Count-1);
    ControlMainMenuCreat.insert(Count-1,TempMainMenu);
    ControlMainMenuCreat.resize(5);



}

void ConfigMainMenu::closeEvent(QCloseEvent *event)
{
    delete MainControlMenu;
}

ConfigMainMenu::~ConfigMainMenu()
{
    delete ui;
}
