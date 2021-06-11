//#include "configmainmenu.h"
#include "newcofigmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NewCofigMenu w;
    w.show();

    return a.exec();
}

