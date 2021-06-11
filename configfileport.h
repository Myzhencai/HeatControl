#ifndef CONFIGFILEPORT_H
#define CONFIGFILEPORT_H

#include <QMainWindow>
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QTextEdit>
#include <QtEvents>
#include<QToolButton>

class ConfigFilePort : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConfigFilePort(QWidget *parent = 0);
    ~ConfigFilePort();


public:
    QMenu *fileMenu;
    QAction *openFileAct;
    QTextEdit *CurrentContent;
    bool CanNewOpenClose();
    int ShowWarning_BeforeNewOpenClose();
    int ShowWarning_WhenOpenFailed();
    int ShowWarning_WhenSaveFailed();


    void createConfigJson(std::vector<std::vector<int>> & value ,std::vector<std::vector<int>> & value1,\
                             std::vector<std::vector<int>> & value2,std::vector<std::vector<int>> & value3);

signals:
    void FanCreatWithJson(int,int,int,int);
    void PumpCreatWithJson(int,int);
    void TECCreatWithJson(int,int,int);
    void ClearAll();//读取新的文件对原来生成的界面全部清零
    void SetUsefulTwen();
    void SetUsefulTel();
    void ElecCreatWithJson(int,int);


public slots:
    void OpenFile();
    void SaveFile();
    void SaveFileAs();
    void SetIsCurrentContentModefied();
    void closeEvent(QCloseEvent *event);

};

#endif // CONFIGFILEPORT_H
