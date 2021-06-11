/********************************************************************************
** Form generated from reading UI file 'welcompage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMPAGE_H
#define UI_WELCOMPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomPage
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *WelcomPage)
    {
        if (WelcomPage->objectName().isEmpty())
            WelcomPage->setObjectName(QStringLiteral("WelcomPage"));
        WelcomPage->resize(414, 293);
        textEdit = new QTextEdit(WelcomPage);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(20, 76, 331, 121));
        textEdit->setReadOnly(true);

        retranslateUi(WelcomPage);

        QMetaObject::connectSlotsByName(WelcomPage);
    } // setupUi

    void retranslateUi(QWidget *WelcomPage)
    {
        WelcomPage->setWindowTitle(QApplication::translate("WelcomPage", "Form", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("WelcomPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600;\">\346\254\242\350\277\216\344\275\277\347\224\250\346\225\243\347\203\255\351\200\273\350\276\221\346\216\247\345\210\266\350\275\257\344\273\266</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WelcomPage: public Ui_WelcomPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMPAGE_H
