#include "showgraphic.h"
#include "ui_showgraphic.h"


Showgraphic::Showgraphic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Showgraphic)
{
    ui->setupUi(this);
}

Showgraphic::~Showgraphic()
{
    delete ui;
}


void Showgraphic::MakeFanshowbuttonenable(int value){
    switch (value) {
    case 1:
        ui->pushButton->setEnabled(true);
        break;
    case 2:
        ui->pushButton1->setEnabled(true);
        break;
    case 3:
        ui->pushButton2->setEnabled(true);
        break;
    case 4:
        ui->pushButton3->setEnabled(true);
        break;
    case 5:
        ui->pushButton4->setEnabled(true);
        break;
    case 6:
        ui->pushButton5->setEnabled(true);
        break;
    case 7:
        ui->pushButton6->setEnabled(true);
        break;
    case 8:
        ui->pushButton7->setEnabled(true);
        break;
    case 9:
        ui->pushButton8->setEnabled(true);
        break;
    case 10:
        ui->pushButton9->setEnabled(true);
        break;
    case 11:
        ui->pushButton10->setEnabled(true);
        break;
    case 12:
        ui->pushButton11->setEnabled(true);
        break;
    case 13:
        ui->pushButton12->setEnabled(true);
        break;
    case 14:
        ui->pushButton13->setEnabled(true);
        break;
    case 15:
        ui->pushButton14->setEnabled(true);
        break;
    case 16:
        ui->pushButton15->setEnabled(true);
        break;
    case 17:
        ui->pushButton16->setEnabled(true);
        break;
    case 18:
        ui->pushButton17->setEnabled(true);
        break;
    case 19:
        ui->pushButton18->setEnabled(true);
        break;
    case 20:
        ui->pushButton19->setEnabled(true);
        break;
    default:
        break;
    }
}
void Showgraphic::MakeFanshowbuttonUNenable(int value){
    switch (value) {
    case 1:
        ui->pushButton->setEnabled(false);
        break;
    case 2:
        ui->pushButton1->setEnabled(false);
        break;
    case 3:
        ui->pushButton2->setEnabled(false);
        break;
    case 4:
        ui->pushButton3->setEnabled(false);
        break;
    case 5:
        ui->pushButton4->setEnabled(false);
        break;
    case 6:
        ui->pushButton5->setEnabled(false);
        break;
    case 7:
        ui->pushButton6->setEnabled(false);
        break;
    case 8:
        ui->pushButton7->setEnabled(false);
        break;
    case 9:
        ui->pushButton8->setEnabled(false);
        break;
    case 10:
        ui->pushButton9->setEnabled(false);
        break;
    case 11:
        ui->pushButton10->setEnabled(false);
        break;
    case 12:
        ui->pushButton11->setEnabled(false);
        break;
    case 13:
        ui->pushButton12->setEnabled(false);
        break;
    case 14:
        ui->pushButton13->setEnabled(false);
        break;
    case 15:
        ui->pushButton14->setEnabled(false);
        break;
    case 16:
        ui->pushButton15->setEnabled(false);
        break;
    case 17:
        ui->pushButton16->setEnabled(false);
        break;
    case 18:
        ui->pushButton17->setEnabled(false);
        break;
    case 19:
        ui->pushButton18->setEnabled(false);
        break;
    case 20:
        ui->pushButton19->setEnabled(false);
        break;
    default:
        break;
    }

}

void Showgraphic::MakeTECTempshowbuttonenable(int value){
    switch (value) {
    case 1:
        ui->TEC1->setEnabled(true);
        break;
    case 2:
        ui->TEC2->setEnabled(true);
        break;
    case 3:
        ui->TEC3->setEnabled(true);
        break;
    case 4:
        ui->TEC4->setEnabled(true);
        break;
    case 5:
        ui->TEC5->setEnabled(true);
        break;
    case 6:
        ui->TEC6->setEnabled(true);
        break;
    default:
        break;
    }

}
void Showgraphic::MakeTECTempshowbuttonUNenable(int value){
    switch (value) {
    case 1:
        ui->TEC1->setEnabled(false);
        break;
    case 2:
        ui->TEC2->setEnabled(false);
        break;
    case 3:
        ui->TEC3->setEnabled(false);
        break;
    case 4:
        ui->TEC4->setEnabled(false);
        break;
    case 5:
        ui->TEC5->setEnabled(false);
        break;
    case 6:
        ui->TEC6->setEnabled(false);
        break;
    default:
        break;
    }

}

void Showgraphic::MakeTECDutyshowbuttonenable(int value){
    switch (value) {
    case 1:
        ui->TECD1->setEnabled(true);
        break;
    case 2:
        ui->TECD2->setEnabled(true);
        break;
    case 3:
        ui->TECD3->setEnabled(true);
        break;
    case 4:
        ui->TECD4->setEnabled(true);
        break;
    case 5:
        ui->TECD5->setEnabled(true);
        break;
    case 6:
        ui->TECD6->setEnabled(true);
        break;
    default:
        break;
    }

}



void Showgraphic::MakeTECDutyshowbuttonUNenable(int value){
    switch (value) {
    case 1:
        ui->TECD1->setEnabled(false);
        break;
    case 2:
        ui->TECD2->setEnabled(false);
        break;
    case 3:
        ui->TECD3->setEnabled(false);
        break;
    case 4:
        ui->TECD4->setEnabled(false);
        break;
    case 5:
        ui->TECD5->setEnabled(false);
        break;
    case 6:
        ui->TECD6->setEnabled(false);
        break;
    default:
        break;
    }

}

void Showgraphic::on_pushButton_clicked()
{
    if(this->ui->pushButton->text() == "风扇1实时图")
    {
        this->ui->pushButton->setText("风扇1实时图关闭");
        emit pushButtonshowReal();

    }
    else
    {
        this->ui->pushButton->setText("风扇1实时图");
        emit pushButtonhideReal();

    }
}

void Showgraphic::on_pushButton1_clicked()
{
    if(this->ui->pushButton1->text() == "风扇2实时图")
    {
        this->ui->pushButton1->setText("风扇2实时图关闭");
        emit pushButtonshowReal1();

    }
    else
    {
        this->ui->pushButton1->setText("风扇2实时图");
        emit pushButtonhideReal1();

    }
}

void Showgraphic::on_pushButton2_clicked()
{
    if(this->ui->pushButton2->text() == "风扇3实时图")
    {
        this->ui->pushButton2->setText("风扇3实时图关闭");
        emit pushButtonshowReal2();

    }
    else
    {
        this->ui->pushButton2->setText("风扇3实时图");
        emit pushButtonhideReal2();

    }
}

void Showgraphic::on_pushButton3_clicked()
{
    if(this->ui->pushButton3->text() == "风扇4实时图")
    {
        this->ui->pushButton3->setText("风扇4实时图关闭");
        emit pushButtonshowReal3();

    }
    else
    {
        this->ui->pushButton3->setText("风扇4实时图");
        emit pushButtonhideReal3();

    }
}

void Showgraphic::on_pushButton4_clicked()
{
    if(this->ui->pushButton4->text() == "风扇5实时图")
    {
        this->ui->pushButton4->setText("风扇5实时图关闭");
        emit pushButtonshowReal4();

    }
    else
    {
        this->ui->pushButton4->setText("风扇5实时图");
        emit pushButtonhideReal4();

    }
}

void Showgraphic::on_pushButton5_clicked()
{
    if(this->ui->pushButton5->text() == "风扇6实时图")
    {
        this->ui->pushButton5->setText("风扇6实时图关闭");
        emit pushButtonshowReal5();

    }
    else
    {
        this->ui->pushButton->setText("风扇6实时图");
        emit pushButtonhideReal5();

    }
}

void Showgraphic::on_pushButton6_clicked()
{
    if(this->ui->pushButton6->text() == "风扇7实时图")
    {
        this->ui->pushButton6->setText("风扇7实时图关闭");
        emit pushButtonshowReal6();

    }
    else
    {
        this->ui->pushButton6->setText("风扇7实时图");
        emit pushButtonhideReal6();

    }
}

void Showgraphic::on_pushButton7_clicked()
{
    if(this->ui->pushButton7->text() == "风扇8实时图")
    {
        this->ui->pushButton7->setText("风扇8实时图关闭");
        emit pushButtonshowReal7();

    }
    else
    {
        this->ui->pushButton7->setText("风扇8实时图");
        emit pushButtonhideReal7();

    }
}

void Showgraphic::on_pushButton8_clicked()
{
    if(this->ui->pushButton8->text() == "风扇9实时图")
    {
        this->ui->pushButton8->setText("风扇9实时图关闭");
        emit pushButtonshowReal8();

    }
    else
    {
        this->ui->pushButton8->setText("风扇9实时图");
        emit pushButtonhideReal8();

    }
}

void Showgraphic::on_pushButton9_clicked()
{
    if(this->ui->pushButton9->text() == "风扇10实时图")
    {
        this->ui->pushButton9->setText("风扇10实时图关闭");
        emit pushButtonshowReal9();

    }
    else
    {
        this->ui->pushButton9->setText("风扇10实时图");
        emit pushButtonhideReal9();

    }
}

void Showgraphic::on_pushButton10_clicked()
{
    if(this->ui->pushButton10->text() == "风扇11实时图")
    {
        this->ui->pushButton10->setText("风扇11实时图关闭");
        emit pushButtonshowReal10();

    }
    else
    {
        this->ui->pushButton10->setText("风扇11实时图");
        emit pushButtonhideReal10();

    }
}

void Showgraphic::on_pushButton11_clicked()
{
    if(this->ui->pushButton11->text() == "风扇12实时图")
    {
        this->ui->pushButton11->setText("风扇12实时图关闭");
        emit pushButtonshowReal11();

    }
    else
    {
        this->ui->pushButton11->setText("风扇12实时图");
        emit pushButtonhideReal11();

    }
}

void Showgraphic::on_pushButton12_clicked()
{
    if(this->ui->pushButton12->text() == "风扇13实时图")
    {
        this->ui->pushButton12->setText("风扇13实时图关闭");
        emit pushButtonshowReal12();

    }
    else
    {
        this->ui->pushButton12->setText("风扇13实时图");
        emit pushButtonhideReal12();

    }
}

void Showgraphic::on_pushButton13_clicked()
{
    if(this->ui->pushButton13->text() == "风扇14实时图")
    {
        this->ui->pushButton13->setText("风扇14实时图关闭");
        emit pushButtonshowReal13();

    }
    else
    {
        this->ui->pushButton13->setText("风扇14实时图");
        emit pushButtonhideReal13();

    }
}

void Showgraphic::on_pushButton14_clicked()
{
    if(this->ui->pushButton14->text() == "风扇15实时图")
    {
        this->ui->pushButton14->setText("风扇15实时图关闭");
        emit pushButtonshowReal14();

    }
    else
    {
        this->ui->pushButton14->setText("风扇15实时图");
        emit pushButtonhideReal14();

    }
}

void Showgraphic::on_pushButton15_clicked()
{
    if(this->ui->pushButton15->text() == "风扇16实时图")
    {
        this->ui->pushButton15->setText("风扇16实时图关闭");
        emit pushButtonshowReal15();

    }
    else
    {
        this->ui->pushButton15->setText("风扇16实时图");
        emit pushButtonhideReal15();

    }
}

void Showgraphic::on_pushButton16_clicked()
{
    if(this->ui->pushButton16->text() == "风扇17实时图")
    {
        this->ui->pushButton16->setText("风扇17实时图关闭");
        emit pushButtonshowReal16();

    }
    else
    {
        this->ui->pushButton16->setText("风扇17实时图");
        emit pushButtonhideReal16();

    }
}

void Showgraphic::on_pushButton17_clicked()
{
    if(this->ui->pushButton17->text() == "风扇18实时图")
    {
        this->ui->pushButton17->setText("风扇18实时图关闭");
        emit pushButtonshowReal17();

    }
    else
    {
        this->ui->pushButton17->setText("风扇18实时图");
        emit pushButtonhideReal17();

    }
}

void Showgraphic::on_pushButton18_clicked()
{
    if(this->ui->pushButton18->text() == "风扇19实时图")
    {
        this->ui->pushButton18->setText("风扇19实时图关闭");
        emit pushButtonshowReal18();

    }
    else
    {
        this->ui->pushButton18->setText("风扇19实时图");
        emit pushButtonhideReal18();

    }
}

void Showgraphic::on_pushButton19_clicked()
{
    if(this->ui->pushButton19->text() == "风扇20实时图")
    {
        this->ui->pushButton19->setText("风扇20实时图关闭");
        emit pushButtonshowReal19();

    }
    else
    {
        this->ui->pushButton19->setText("风扇20实时图");
        emit pushButtonhideReal19();

    }
}

void Showgraphic::on_TEC1_clicked()
{
    if(this->ui->TEC1->text() == "TEC1实时温度图")
    {
        this->ui->TEC1->setText("TEC1实时图关闭");
        emit ButtonshowReal();

    }
    else
    {
        this->ui->TEC1->setText("TEC1实时温度图");
        emit ButtonhideReal();

    }
}

void Showgraphic::on_TEC2_clicked()
{
    if(this->ui->TEC2->text() == "TEC2实时温度图")
    {
        this->ui->TEC2->setText("TEC2实时图关闭");
        emit ButtonshowReal1();

    }
    else
    {
        this->ui->TEC2->setText("TEC2实时温度图");
        emit ButtonhideReal1();

    }
}

void Showgraphic::on_TEC3_clicked()
{
    if(this->ui->TEC3->text() == "TEC3实时温度图")
    {
        this->ui->TEC3->setText("TEC3实时图关闭");
        emit ButtonshowReal2();

    }
    else
    {
        this->ui->TEC3->setText("TEC3实时温度图");
        emit ButtonhideReal2();

    }
}

void Showgraphic::on_TEC4_clicked()
{
    if(this->ui->TEC4->text() == "TEC4实时温度图")
    {
        this->ui->TEC4->setText("TEC4实时图关闭");
        emit ButtonshowReal3();

    }
    else
    {
        this->ui->TEC4->setText("TEC4实时温度图");
        emit ButtonhideReal3();

    }
}

void Showgraphic::on_TEC5_clicked()
{
    if(this->ui->TEC5->text() == "TEC5实时温度图")
    {
        this->ui->TEC5->setText("TEC5实时图关闭");
        emit ButtonshowReal4();

    }
    else
    {
        this->ui->TEC5->setText("TEC5实时温度图");
        emit ButtonhideReal4();

    }
}

void Showgraphic::on_TEC6_clicked()
{
    if(this->ui->TEC6->text() == "TEC6实时温度图")
    {
        this->ui->TEC6->setText("TEC6实时图关闭");
        emit ButtonshowReal5();

    }
    else
    {
        this->ui->TEC6->setText("TEC6实时温度图");
        emit ButtonhideReal5();

    }
}

void Showgraphic::on_TECD1_clicked()
{
    if(this->ui->TECD1->text() == "TEC1实时占空比")
    {
        this->ui->TECD1->setText("TEC1占空比关闭");
        emit uttonshowReal();

    }
    else
    {
        this->ui->TECD1->setText("TEC1实时占空比");
        emit uttonhideReal();

    }
}

void Showgraphic::on_TECD2_clicked()
{
    if(this->ui->TECD2->text() == "TEC2实时占空比")
    {
        this->ui->TECD2->setText("TEC2占空比关闭");
        emit uttonshowReal1();

    }
    else
    {
        this->ui->TECD2->setText("TEC2实时占空比");
        emit uttonhideReal1();

    }
}

void Showgraphic::on_TECD3_clicked()
{
    if(this->ui->TECD3->text() == "TEC3实时占空比")
    {
        this->ui->TECD3->setText("TEC3占空比关闭");
        emit uttonshowReal2();

    }
    else
    {
        this->ui->TECD3->setText("TEC3实时占空比");
        emit uttonhideReal2();

    }
}

void Showgraphic::on_TECD4_clicked()
{
    if(this->ui->TECD4->text() == "TEC4实时占空比")
    {
        this->ui->TECD4->setText("TEC4占空比关闭");
        emit uttonshowReal3();

    }
    else
    {
        this->ui->TECD4->setText("TEC4实时占空比");
        emit uttonhideReal3();

    }
}

void Showgraphic::on_TECD5_clicked()
{
    if(this->ui->TECD5->text() == "TEC5实时占空比")
    {
        this->ui->TECD5->setText("TEC5占空比关闭");
        emit uttonshowReal4();

    }
    else
    {
        this->ui->TECD5->setText("TEC5实时占空比");
        emit uttonhideReal4();

    }
}

void Showgraphic::on_TECD6_clicked()
{
    if(this->ui->TECD6->text() == "TEC6实时占空比")
    {
        this->ui->TECD6->setText("TEC6占空比关闭");
        emit uttonshowReal5();

    }
    else
    {
        this->ui->TECD6->setText("TEC6实时占空比");
        emit uttonhideReal5();

    }
}
