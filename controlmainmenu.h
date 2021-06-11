#ifndef CONTROLMAINMENU_H
#define CONTROLMAINMENU_H

#include <QWidget>
#include<QVBoxLayout>
#include<QTabWidget>
#include<heatcontrolmenu.h>

namespace Ui {
class ControlMainMenu;
}

class ControlMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ControlMainMenu(QWidget *parent = 0);
    ~ControlMainMenu();

public slots:
    void onTabCloseRequested(int);
    void addControlMenuTab(HeatControlMenu* value,int number);
    void showControlMenu(int value);

private:
    Ui::ControlMainMenu *ui;
    QVBoxLayout* vLayout;
    QTabWidget* tabW;
};

#endif // CONTROLMAINMENU_H
