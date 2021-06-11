#ifndef TCPNETCLIENT_H
#define TCPNETCLIENT_H

#include <QMainWindow>

namespace Ui {
class TcpNetClient;
}

class TcpNetClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit TcpNetClient(QWidget *parent = 0);
    ~TcpNetClient();

private:
    Ui::TcpNetClient *ui;
};

#endif // TCPNETCLIENT_H
