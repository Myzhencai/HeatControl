/********************************************************************************
** Form generated from reading UI file 'timecount.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMECOUNT_H
#define UI_TIMECOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_timecount
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTimeEdit *timeEdit;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLCDNumber *lcd;
    QLabel *label_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *timecount)
    {
        if (timecount->objectName().isEmpty())
            timecount->setObjectName(QStringLiteral("timecount"));
        timecount->resize(205, 205);
        centralwidget = new QWidget(timecount);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 191, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        timeEdit = new QTimeEdit(layoutWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setMaximumTime(QTime(23, 59, 59));
        timeEdit->setTime(QTime(0, 0, 1));

        horizontalLayout->addWidget(timeEdit);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 40, 191, 71));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lcd = new QLCDNumber(layoutWidget_2);
        lcd->setObjectName(QStringLiteral("lcd"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        lcd->setFont(font);
        lcd->setDigitCount(5);
        lcd->setSegmentStyle(QLCDNumber::Flat);
        lcd->setProperty("value", QVariant(0));
        lcd->setProperty("intValue", QVariant(0));

        horizontalLayout_2->addWidget(lcd);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(layoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        timecount->setCentralWidget(centralwidget);
        menubar = new QMenuBar(timecount);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 205, 26));
        timecount->setMenuBar(menubar);
        statusbar = new QStatusBar(timecount);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        timecount->setStatusBar(statusbar);

        retranslateUi(timecount);

        QMetaObject::connectSlotsByName(timecount);
    } // setupUi

    void retranslateUi(QMainWindow *timecount)
    {
        timecount->setWindowTitle(QApplication::translate("timecount", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("timecount", "\346\227\266\351\227\264\350\256\276\347\275\256", Q_NULLPTR));
        label_2->setText(QApplication::translate("timecount", "\345\200\222\350\256\241\346\227\266", Q_NULLPTR));
        label_3->setText(QApplication::translate("timecount", "s", Q_NULLPTR));
        pushButton->setText(QApplication::translate("timecount", "\345\274\200\345\247\213\350\256\241\346\227\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class timecount: public Ui_timecount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMECOUNT_H
