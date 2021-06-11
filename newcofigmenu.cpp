#include "newcofigmenu.h"
#include "ui_newcofigmenu.h"
#include <QToolButton>
#include "welcompage.h"
#include<QPushButton>


NewCofigMenu::NewCofigMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewCofigMenu)
{
    ui->setupUi(this);

    vLayout = new QVBoxLayout(this);
    tabW = new QTabWidget();
    tabW->setTabsClosable(true);
    pwelcom = new  WelcomPage();

    tabW->insertTab(0,pwelcom,QString("软件欢迎界面"));
    m_tabClosebutton = new QToolButton(this);
    m_tabClosebutton->setText("添加散热器件窗口");

    m_tabClosebutton->setIconSize(QSize(900, 600));
    tabW->setCornerWidget(m_tabClosebutton);
    vLayout->addWidget(tabW);

    connect(m_tabClosebutton, &QToolButton::clicked, this ,&NewCofigMenu::addWidget);
    connect(tabW,SIGNAL(tabCloseRequested(int)),this,SLOT(onTabCloseRequested(int)));
    connect(pwelcom,SIGNAL(Creatfirstone()),this,SLOT(addWidget1()));


}


void NewCofigMenu::addWidget1()
{

    addWidget();
}


void NewCofigMenu::addWidget()
{
    if(Count == 5){
        return;
    }
    Count++;

    MainMenu* TempMainMenu = new MainMenu();
    tabW->insertTab(Count,TempMainMenu->ControlMenu,QString(" 测试样机配置界面"));
//    emit addControlMenuTab(TempMainMenu->ControlMenu,Count-1);
    ControlMainMenuCreat.insert(Count-1,TempMainMenu);
    ControlMainMenuCreat.resize(5);
    tabW->setCurrentIndex(Count);
}

void NewCofigMenu::onTabCloseRequested( int value)
{

    if(value>0){
       ControlMainMenuCreat[value-1]->Close();
       tabW->removeTab(value);
       ControlMainMenuCreat[value-1]->closeEvent();
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

void NewCofigMenu::closeEvent(QCloseEvent *event)
{
    for(int i = 0;i<5;i++)
    {
        if(ControlMainMenuCreat[i]!=NULL){
            ControlMainMenuCreat[i]->~MainMenu();
        }
    }
}


NewCofigMenu::~NewCofigMenu()
{
    delete ui;
}
