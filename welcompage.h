#ifndef WELCOMPAGE_H
#define WELCOMPAGE_H

#include <QWidget>

namespace Ui {
class WelcomPage;
}

class WelcomPage : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomPage(QWidget *parent = 0);
    ~WelcomPage();

private slots:
    void on_pushButton_clicked();

signals:
    void Creatfirstone();

private:
    Ui::WelcomPage *ui;
};

#endif // WELCOMPAGE_H
