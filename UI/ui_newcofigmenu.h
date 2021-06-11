/********************************************************************************
** Form generated from reading UI file 'newcofigmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCOFIGMENU_H
#define UI_NEWCOFIGMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewCofigMenu
{
public:

    void setupUi(QWidget *NewCofigMenu)
    {
        if (NewCofigMenu->objectName().isEmpty())
            NewCofigMenu->setObjectName(QStringLiteral("NewCofigMenu"));
        NewCofigMenu->resize(2000, 1055);

        retranslateUi(NewCofigMenu);

        QMetaObject::connectSlotsByName(NewCofigMenu);
    } // setupUi

    void retranslateUi(QWidget *NewCofigMenu)
    {
        NewCofigMenu->setWindowTitle(QApplication::translate("NewCofigMenu", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewCofigMenu: public Ui_NewCofigMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCOFIGMENU_H
