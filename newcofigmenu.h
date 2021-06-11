#ifndef NEWCOFIGMENU_H
#define NEWCOFIGMENU_H

#include <QWidget>
#include <QPushButton>
#include<QVBoxLayout>
#include<QTabWidget>
#include"mainmenu.h"
#include"welcompage.h"

namespace Ui {
class NewCofigMenu;
}

class NewCofigMenu : public QWidget
{
    Q_OBJECT
public slots:
    void addWidget();
    void addWidget1();
    void onTabCloseRequested( int value);

public:
    explicit NewCofigMenu(QWidget *parent = 0);
    ~NewCofigMenu();
    void closeEvent(QCloseEvent *event);
private:
    Ui::NewCofigMenu *ui;
    QVBoxLayout* vLayout;
    QTabWidget* tabW;
    QVector<MainMenu*> ControlMainMenuCreat;
    WelcomPage *pwelcom;
    QToolButton* m_tabClosebutton;


    int Count =0;


};

#endif // NEWCOFIGMENU_H
