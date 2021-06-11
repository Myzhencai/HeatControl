/********************************************************************************
** Form generated from reading UI file 'controlmainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLMAINMENU_H
#define UI_CONTROLMAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlMainMenu
{
public:

    void setupUi(QWidget *ControlMainMenu)
    {
        if (ControlMainMenu->objectName().isEmpty())
            ControlMainMenu->setObjectName(QStringLiteral("ControlMainMenu"));
        ControlMainMenu->resize(2000, 1500);

        retranslateUi(ControlMainMenu);

        QMetaObject::connectSlotsByName(ControlMainMenu);
    } // setupUi

    void retranslateUi(QWidget *ControlMainMenu)
    {
        ControlMainMenu->setWindowTitle(QApplication::translate("ControlMainMenu", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ControlMainMenu: public Ui_ControlMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLMAINMENU_H
