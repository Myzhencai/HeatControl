#include "welcompage.h"
#include "ui_welcompage.h"

WelcomPage::WelcomPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomPage)
{
    ui->setupUi(this);
}

WelcomPage::~WelcomPage()
{
    delete ui;
}

void WelcomPage::on_pushButton_clicked()
{
    emit Creatfirstone();

}
