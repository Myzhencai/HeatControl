/********************************************************************************
** Form generated from reading UI file 'configmainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGMAINMENU_H
#define UI_CONFIGMAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigMainMenu
{
public:

    void setupUi(QWidget *ConfigMainMenu)
    {
        if (ConfigMainMenu->objectName().isEmpty())
            ConfigMainMenu->setObjectName(QStringLiteral("ConfigMainMenu"));
        ConfigMainMenu->resize(2000, 1500);

        retranslateUi(ConfigMainMenu);

        QMetaObject::connectSlotsByName(ConfigMainMenu);
    } // setupUi

    void retranslateUi(QWidget *ConfigMainMenu)
    {
        ConfigMainMenu->setWindowTitle(QApplication::translate("ConfigMainMenu", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigMainMenu: public Ui_ConfigMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGMAINMENU_H
