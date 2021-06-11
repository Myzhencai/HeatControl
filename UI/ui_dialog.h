/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QTextBrowser *tb_rx_buf;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_2;
    QPushButton *btn_clear;
    QTextEdit *te_tx_buf;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QCheckBox *checkBox;
    QCheckBox *cb_send_enter;
    QPushButton *btn_send;
    QLabel *label_3;
    QComboBox *cbb_baud;
    QLabel *label_4;
    QComboBox *cbb_com;
    QPushButton *btn_serch;
    QPushButton *btn_uart_Ctrl;
    QLabel *lbe_red;
    QPushButton *btn_led1_Ctrl;
    QLabel *lbe_blue;
    QPushButton *btn_led2_Ctrl;
    QPushButton *btn_led1_Ctrl_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(660, 279);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        Dialog->setFont(font);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        tb_rx_buf = new QTextBrowser(Dialog);
        tb_rx_buf->setObjectName(QStringLiteral("tb_rx_buf"));
        QFont font1;
        font1.setPointSize(10);
        tb_rx_buf->setFont(font1);

        formLayout->setWidget(0, QFormLayout::SpanningRole, tb_rx_buf);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBox_2 = new QCheckBox(Dialog);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setFont(font1);

        horizontalLayout->addWidget(checkBox_2);

        btn_clear = new QPushButton(Dialog);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        btn_clear->setFont(font1);

        horizontalLayout->addWidget(btn_clear);


        formLayout->setLayout(1, QFormLayout::SpanningRole, horizontalLayout);

        te_tx_buf = new QTextEdit(Dialog);
        te_tx_buf->setObjectName(QStringLiteral("te_tx_buf"));
        te_tx_buf->setFont(font1);

        formLayout->setWidget(2, QFormLayout::SpanningRole, te_tx_buf);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        horizontalLayout_2->addWidget(label_7);

        checkBox = new QCheckBox(Dialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font1);

        horizontalLayout_2->addWidget(checkBox);

        cb_send_enter = new QCheckBox(Dialog);
        cb_send_enter->setObjectName(QStringLiteral("cb_send_enter"));
        cb_send_enter->setFont(font1);

        horizontalLayout_2->addWidget(cb_send_enter);

        btn_send = new QPushButton(Dialog);
        btn_send->setObjectName(QStringLiteral("btn_send"));
        btn_send->setFont(font1);

        horizontalLayout_2->addWidget(btn_send);


        formLayout->setLayout(3, QFormLayout::SpanningRole, horizontalLayout_2);


        gridLayout->addLayout(formLayout, 0, 0, 6, 1);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        cbb_baud = new QComboBox(Dialog);
        cbb_baud->setObjectName(QStringLiteral("cbb_baud"));

        gridLayout->addWidget(cbb_baud, 0, 2, 1, 1);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        cbb_com = new QComboBox(Dialog);
        cbb_com->setObjectName(QStringLiteral("cbb_com"));

        gridLayout->addWidget(cbb_com, 1, 2, 1, 1);

        btn_serch = new QPushButton(Dialog);
        btn_serch->setObjectName(QStringLiteral("btn_serch"));

        gridLayout->addWidget(btn_serch, 2, 1, 1, 1);

        btn_uart_Ctrl = new QPushButton(Dialog);
        btn_uart_Ctrl->setObjectName(QStringLiteral("btn_uart_Ctrl"));
        btn_uart_Ctrl->setFont(font);

        gridLayout->addWidget(btn_uart_Ctrl, 2, 2, 1, 1);

        lbe_red = new QLabel(Dialog);
        lbe_red->setObjectName(QStringLiteral("lbe_red"));

        gridLayout->addWidget(lbe_red, 3, 1, 1, 1);

        btn_led1_Ctrl = new QPushButton(Dialog);
        btn_led1_Ctrl->setObjectName(QStringLiteral("btn_led1_Ctrl"));

        gridLayout->addWidget(btn_led1_Ctrl, 3, 2, 1, 1);

        lbe_blue = new QLabel(Dialog);
        lbe_blue->setObjectName(QStringLiteral("lbe_blue"));

        gridLayout->addWidget(lbe_blue, 4, 1, 1, 1);

        btn_led2_Ctrl = new QPushButton(Dialog);
        btn_led2_Ctrl->setObjectName(QStringLiteral("btn_led2_Ctrl"));

        gridLayout->addWidget(btn_led2_Ctrl, 4, 2, 1, 1);

        btn_led1_Ctrl_2 = new QPushButton(Dialog);
        btn_led1_Ctrl_2->setObjectName(QStringLiteral("btn_led1_Ctrl_2"));

        gridLayout->addWidget(btn_led1_Ctrl_2, 5, 1, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", "\346\216\245\346\224\266\347\252\227\345\217\243", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("Dialog", "16\350\277\233\345\210\266\346\216\245\346\224\266", Q_NULLPTR));
        btn_clear->setText(QApplication::translate("Dialog", "\346\270\205\351\231\244\346\216\245\346\224\266", Q_NULLPTR));
        label_7->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201\347\252\227\345\217\243", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Dialog", "16\350\277\233\345\210\266\345\217\221\351\200\201", Q_NULLPTR));
        cb_send_enter->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201\346\226\260\350\241\214", Q_NULLPTR));
        btn_send->setText(QApplication::translate("Dialog", "\345\215\225\345\221\275\344\273\244\350\241\214\345\217\221\351\200\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "\344\270\262\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        btn_serch->setText(QApplication::translate("Dialog", "\346\220\234\347\264\242\344\270\262\345\217\243", Q_NULLPTR));
        btn_uart_Ctrl->setText(QApplication::translate("Dialog", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        lbe_red->setText(QApplication::translate("Dialog", "\347\272\242\347\201\257", Q_NULLPTR));
        btn_led1_Ctrl->setText(QApplication::translate("Dialog", "\347\202\271\344\272\256", Q_NULLPTR));
        lbe_blue->setText(QApplication::translate("Dialog", "\350\223\235\347\201\257", Q_NULLPTR));
        btn_led2_Ctrl->setText(QApplication::translate("Dialog", "\347\202\271\344\272\256", Q_NULLPTR));
        btn_led1_Ctrl_2->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201\347\225\214\351\235\242\345\275\223\345\211\215\351\205\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
