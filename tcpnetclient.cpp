#include "tcpnetclient.h"
#include "ui_tcpnetclient.h"

TcpNetClient::TcpNetClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TcpNetClient)
{
    ui->setupUi(this);
}

TcpNetClient::~TcpNetClient()
{
    delete ui;
}
