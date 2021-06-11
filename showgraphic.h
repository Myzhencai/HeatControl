#ifndef SHOWGRAPHIC_H
#define SHOWGRAPHIC_H

#include <QMainWindow>

namespace Ui {
class Showgraphic;
}

class Showgraphic : public QMainWindow
{
    Q_OBJECT

public:
    explicit Showgraphic(QWidget *parent = 0);
    ~Showgraphic();


public slots:
    void MakeFanshowbuttonenable(int);
    void MakeFanshowbuttonUNenable(int);

    void MakeTECTempshowbuttonenable(int);
    void MakeTECTempshowbuttonUNenable(int);

    void MakeTECDutyshowbuttonenable(int);
    void MakeTECDutyshowbuttonUNenable(int);


private slots:
    void on_pushButton_clicked();


    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButton10_clicked();

    void on_pushButton11_clicked();

    void on_pushButton12_clicked();

    void on_pushButton13_clicked();

    void on_pushButton14_clicked();

    void on_pushButton15_clicked();

    void on_pushButton16_clicked();

    void on_pushButton17_clicked();

    void on_pushButton18_clicked();

    void on_pushButton19_clicked();

    void on_TEC1_clicked();

    void on_TEC2_clicked();

    void on_TEC3_clicked();

    void on_TEC4_clicked();

    void on_TEC5_clicked();

    void on_TEC6_clicked();

    void on_TECD1_clicked();

    void on_TECD2_clicked();

    void on_TECD3_clicked();

    void on_TECD4_clicked();

    void on_TECD5_clicked();

    void on_TECD6_clicked();

signals:
    void pushButtonshowReal();
    void pushButtonhideReal();
    void pushButtonshowReal1();
    void pushButtonhideReal1();
    void pushButtonshowReal2();
    void pushButtonhideReal2();
    void pushButtonshowReal3();
    void pushButtonhideReal3();
    void pushButtonshowReal4();
    void pushButtonhideReal4();
    void pushButtonhideReal5();
    void pushButtonshowReal5();
    void pushButtonshowReal6();
    void pushButtonhideReal6();
    void pushButtonshowReal7();
    void pushButtonhideReal7();
    void pushButtonshowReal8();
    void pushButtonhideReal8();
    void pushButtonshowReal9();
    void pushButtonhideReal9();

    void pushButtonshowReal10();
    void pushButtonhideReal10();
    void pushButtonshowReal11();
    void pushButtonhideReal11();
    void pushButtonshowReal12();
    void pushButtonhideReal12();
    void pushButtonshowReal13();
    void pushButtonhideReal13();
    void pushButtonhideReal14();
    void pushButtonshowReal14();
    void pushButtonhideReal15();
    void pushButtonshowReal15();
    void pushButtonshowReal16();
    void pushButtonhideReal16();
    void pushButtonshowReal17();
    void pushButtonhideReal17();
    void pushButtonshowReal18();
    void pushButtonhideReal18();
    void pushButtonshowReal19();
    void pushButtonhideReal19();

    void ButtonshowReal();
    void ButtonhideReal();
    void ButtonshowReal1();
    void ButtonhideReal1();
    void ButtonshowReal2();
    void ButtonhideReal2();
    void ButtonshowReal3();
    void ButtonhideReal3();
    void ButtonshowReal4();
    void ButtonhideReal4();
    void ButtonshowReal5();
    void ButtonhideReal5();



    void uttonshowReal();
    void uttonhideReal();
    void uttonshowReal1();
    void uttonhideReal1();
    void uttonshowReal2();
    void uttonhideReal2();
    void uttonshowReal3();
    void uttonhideReal3();
    void uttonshowReal4();
    void uttonhideReal4();
    void uttonshowReal5();
    void uttonhideReal5();

private:
    Ui::Showgraphic *ui;
};

#endif // SHOWGRAPHIC_H
