/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QTextEdit *textEdit_read;
    QPushButton *pushButton_close;
    QLineEdit *lineEdit_port;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton_connect;
    QLineEdit *lineEdit_ip;
    QTextEdit *textEdit_write;
    QPushButton *pushButton_send;
    QPushButton *pushButton_send_2;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QStringLiteral("TcpClient"));
        TcpClient->resize(447, 396);
        textEdit_read = new QTextEdit(TcpClient);
        textEdit_read->setObjectName(QStringLiteral("textEdit_read"));
        textEdit_read->setGeometry(QRect(20, 77, 408, 134));
        pushButton_close = new QPushButton(TcpClient);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(340, 40, 93, 27));
        pushButton_close->setMinimumSize(QSize(0, 27));
        lineEdit_port = new QLineEdit(TcpClient);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(120, 13, 208, 25));
        lineEdit_port->setMinimumSize(QSize(0, 25));
        label_2 = new QLabel(TcpClient);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 45, 93, 25));
        label_2->setMinimumSize(QSize(0, 25));
        label = new QLabel(TcpClient);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 13, 93, 25));
        label->setMinimumSize(QSize(0, 25));
        pushButton_connect = new QPushButton(TcpClient);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(340, 10, 93, 28));
        pushButton_connect->setMinimumSize(QSize(0, 28));
        lineEdit_ip = new QLineEdit(TcpClient);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        lineEdit_ip->setGeometry(QRect(120, 45, 208, 25));
        lineEdit_ip->setMinimumSize(QSize(0, 25));
        textEdit_write = new QTextEdit(TcpClient);
        textEdit_write->setObjectName(QStringLiteral("textEdit_write"));
        textEdit_write->setGeometry(QRect(20, 218, 408, 135));
        pushButton_send = new QPushButton(TcpClient);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(20, 360, 93, 27));
        pushButton_send->setMinimumSize(QSize(0, 27));
        pushButton_send_2 = new QPushButton(TcpClient);
        pushButton_send_2->setObjectName(QStringLiteral("pushButton_send_2"));
        pushButton_send_2->setGeometry(QRect(262, 360, 161, 27));
        pushButton_send_2->setMinimumSize(QSize(0, 27));

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QApplication::translate("TcpClient", "Form", Q_NULLPTR));
        pushButton_close->setText(QApplication::translate("TcpClient", "\346\226\255 \345\274\200", Q_NULLPTR));
        label_2->setText(QApplication::translate("TcpClient", "\346\234\215\345\212\241\345\231\250IP\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("TcpClient", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        pushButton_connect->setText(QApplication::translate("TcpClient", "\350\277\236 \346\216\245", Q_NULLPTR));
        pushButton_send->setText(QApplication::translate("TcpClient", "\345\217\221 \351\200\201", Q_NULLPTR));
        pushButton_send_2->setText(QApplication::translate("TcpClient", "\345\217\221\351\200\201\345\275\223\345\211\215\351\241\265\351\235\242\351\205\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
