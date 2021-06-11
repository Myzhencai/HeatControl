#ifndef CONFIGMAINMENU_H
#define CONFIGMAINMENU_H

#include <QWidget>
#include <QPushButton>
#include<QVBoxLayout>
#include<QTabWidget>
#include<controlmainmenu.h>
#include<mainmenu.h>

namespace Ui {
class ConfigMainMenu;
}

class ConfigMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigMainMenu(QWidget *parent = 0);
    ~ConfigMainMenu();
    void addWidget();
    void closeEvent(QCloseEvent *event);

signals:
    void addControlMenuTab(HeatControlMenu*,int);

public slots:
    void onTabCloseRequested(int);

private:
    Ui::ConfigMainMenu *ui;
    QVBoxLayout* vLayout;
    QTabWidget* tabW;
    ControlMainMenu * MainControlMenu;
    QVector<MainMenu*> ControlMainMenuCreat;
//    std::vector<MainMenu*> ControlMainMenuCreat{std::vector<MainMenu*>(5)};

    QVector<int> ControlMainMenuCreat1;
    int Count =0;

};

#endif // CONFIGMAINMENU_H
