#include "configfileport.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QMenuBar>
#include<QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <vector>



QString CurrentFilePath="";             //当前文件路径

ConfigFilePort::ConfigFilePort(QWidget *parent) :
    QMainWindow(parent)
{
    this->setMaximumSize(800,800);
    this->setMinimumSize(800,800);
    fileMenu = new QMenu(this);
    openFileAct = new QAction(tr("打开"),this);

    fileMenu  = menuBar()->addMenu(tr("散热逻辑配置文件..."));

    fileMenu->addAction(openFileAct);

    connect(openFileAct,SIGNAL(triggered()),this,SLOT(OpenFile())) ;

    CurrentContent = new QTextEdit(this);
    CurrentContent->setReadOnly(true);
    CurrentContent->document()->setModified(false);         //将当前文本设置为未被修改
    this->setCentralWidget(CurrentContent);                 //将TextEdit设置为中央控件
    connect(CurrentContent,SIGNAL(textChanged()),this,SLOT(SetIsCurrentContentModefied()) );    //一旦文本被改变，则调用函数将文本设置为已被修改
}

ConfigFilePort::~ConfigFilePort()
{

}

/******************************************************************整个配置文件Json生成******************************************/
void ConfigFilePort::createConfigJson(std::vector<std::vector<int>> & value,std::vector<std::vector<int>> & value1,\
                                         std::vector<std::vector<int>> & value2,std::vector<std::vector<int>> & value3)
{
    QJsonArray FanJsonGroup;
    for(int i = 0; i<20;i++)
    {
        if(value[i][0] !=0)
        {
            QJsonObject FanJsonPart;
            FanJsonPart.insert("风扇ID", value[i][0]);
            FanJsonPart.insert("接线方式", value[i][1]);
            FanJsonPart.insert("最大电压",value[i][2]);
            FanJsonPart.insert("风扇(电压/占空比)", value[i][3]);
            FanJsonGroup.append(FanJsonPart);
        }
    }

    QJsonArray FanJsonGroup1;
    for(int i = 0; i<16;i++)
    {
        if(value1[i][0] !=0)
        {
            QJsonObject FanJsonPart;
            FanJsonPart.insert("水泵ID", value1[i][0]);
            FanJsonPart.insert("电压值", value1[i][1]);
            FanJsonGroup1.append(FanJsonPart);
        }
    }

    QJsonArray FanJsonGroup2;
    for(int i = 0; i<16;i++)
    {
        if(value2[i][0] !=0)
        {
            QJsonObject FanJsonPart;
            FanJsonPart.insert("TECID", value2[i][0]);
            FanJsonPart.insert("冷面温度", value2[i][1]);
            FanJsonPart.insert("TEC电压", value2[i][2]);
            FanJsonGroup2.append(FanJsonPart);
        }
    }

    QJsonArray FanJsonGroup3;
    for(int i = 0; i<16;i++)
    {
        if(value3[i][0] !=0)
        {
            QJsonObject FanJsonPart;
            FanJsonPart.insert("电流ID", value3[i][0]);
            FanJsonPart.insert("电流值", value3[i][1]);
            FanJsonGroup3.append(FanJsonPart);
        }
    }
    QJsonObject ConfigFile;
    ConfigFile.insert("风扇组",FanJsonGroup);
    ConfigFile.insert("水泵组",FanJsonGroup1);
    ConfigFile.insert("TEC组",FanJsonGroup2);
    ConfigFile.insert("电流组",FanJsonGroup3);

    QJsonDocument doc;
    doc.setObject(ConfigFile);

    QByteArray data = doc.toJson();

    //json写入文件
    QString filePath = QFileDialog::getSaveFileName(this,tr("另存"),tr(""),tr("文本文件(*.json)"));
    if(filePath == "")
        return;
    CurrentFilePath = filePath;
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        ShowWarning_WhenSaveFailed();
        CurrentFilePath = "";
        return;
    }
    file.write(data);
    CurrentContent->document()->setModified(false);
    file.close();
}




//判断是否在新建、打开、关闭之前文件是否已保存
bool ConfigFilePort::CanNewOpenClose()
{
    return !(CurrentContent->document()->isModified());
}


void ConfigFilePort::OpenFile()
{
    emit ClearAll();
    if(!CanNewOpenClose())//文件被改动过就另存为新文件
    {
        int ret = ShowWarning_BeforeNewOpenClose();
        if(ret  == QMessageBox::Save)
        {SaveFileAs();
            return;
        }
        else if(ret == QMessageBox::Cancel)
            return;
    }
    //打开新文件
    QString filePath = QFileDialog::getOpenFileName(this,tr("打开文件"),tr(""),tr("文本文件(*.json)"));

    if(filePath == "")
        return;
    CurrentFilePath = filePath;
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ShowWarning_WhenOpenFailed();
        CurrentFilePath = "";
        return;
    }

    //解析Json文件生成对应的界面
    QString value = file.readAll();
    CurrentContent->setText(value);
    file.close();

    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(), &parseJsonErr);
    if (!(parseJsonErr.error == QJsonParseError::NoError)) {
        QMessageBox::about(NULL, "提示", "配置文件错误！");
        return;
    }

    QJsonObject jsonObject = document.object();

    if(jsonObject.contains(QStringLiteral("电流组")))
      {
       QJsonValue arrayValue = jsonObject.value(QStringLiteral("电流组"));
       if(arrayValue.isArray())
         {
           QJsonArray array = arrayValue.toArray();
           for(int i=0;i<array.size();i++)
           {
            QJsonValue iconArray = array.at(i);
            QJsonObject icon = iconArray.toObject();

            int ElecID = icon["电流ID"].toInt();
            int ElecValue = icon["电流值"].toInt();

            emit ElecCreatWithJson(ElecID,ElecValue);

           }
         }
       }

    //风扇组Json解析
    if(jsonObject.contains(QStringLiteral("TEC组")))
      {
       QJsonValue arrayValue = jsonObject.value(QStringLiteral("TEC组"));
       if(arrayValue.isArray())
         {
           QJsonArray array = arrayValue.toArray();
           for(int i=0;i<array.size();i++)
           {
            QJsonValue iconArray = array.at(i);
            QJsonObject icon = iconArray.toObject();

            int ColdTemp = icon["冷面温度"].toInt();
            int TECID = icon["TECID"].toInt();
            int TECValue = icon["TEC电压"].toInt();
            emit TECCreatWithJson(TECID,ColdTemp,TECValue);
           }
         }
       }

    //风扇组Json解析
    if(jsonObject.contains(QStringLiteral("水泵组")))
      {
       QJsonValue arrayValue = jsonObject.value(QStringLiteral("水泵组"));
       if(arrayValue.isArray())
         {
           QJsonArray array = arrayValue.toArray();
           for(int i=0;i<array.size();i++)
           {
            QJsonValue iconArray = array.at(i);
            QJsonObject icon = iconArray.toObject();

            int PumpElec = icon["电压值"].toInt();
            int PumpID = icon["水泵ID"].toInt();
            qDebug()<<PumpID;
            qDebug()<<PumpElec;
            emit PumpCreatWithJson(PumpID,PumpElec);

           }
         }
       }

    if(jsonObject.contains(QStringLiteral("风扇组")))
      {
       QJsonValue arrayValue = jsonObject.value(QStringLiteral("风扇组"));
       if(arrayValue.isArray())
         {
           QJsonArray array = arrayValue.toArray();
           for(int i=0;i<array.size();i++)
           {
            QJsonValue iconArray = array.at(i);
            QJsonObject icon = iconArray.toObject();
            int ContectType = icon["接线方式"].toInt();
            int MaxElec = icon["最大电压"].toInt();
            int FanID = icon["风扇ID"].toInt();
            int FanDucy = icon["风扇(电压/占空比)"].toInt();
            if(ContectType == 4)
            {
                if(MaxElec == 12)
                {
                    emit SetUsefulTel();
                }
                if(MaxElec == 24)
                {
                    emit SetUsefulTwen();
                }
            }
            emit FanCreatWithJson(FanID,ContectType,MaxElec,FanDucy);
           }
         }
       }
    CurrentContent->document()->setModified(false);

}

void ConfigFilePort::SaveFile()
{

    QFile file(CurrentFilePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        ShowWarning_WhenSaveFailed();
        CurrentFilePath = "";
        return;
    }
    QTextStream textStream(&file);
    file.resize(0);
    textStream<<CurrentContent->toPlainText();
    file.close();
    CurrentContent->document()->setModified(false);
}

void ConfigFilePort::SaveFileAs()
{
    QString filePath = QFileDialog::getSaveFileName(this,tr("另存"),tr(""),tr("文本文件(*.txt)"));
    if(filePath == "")
        return;
    CurrentFilePath = filePath;
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        ShowWarning_WhenSaveFailed();
        CurrentFilePath = "";
        return;
    }
    QTextStream textStream(&file);
    textStream<<CurrentContent->toPlainText();
    file.close();
    CurrentContent->document()->setModified(false);
}

//文本被修改时调用的函数，将文本设置为已被修改
void ConfigFilePort::SetIsCurrentContentModefied()
{
    CurrentContent->document()->setModified(true);
}

//下面是为了简化QMessageBox而写的函数
int ConfigFilePort::ShowWarning_BeforeNewOpenClose()
{
    return QMessageBox::warning(this,tr("警告"),tr("还未保存"),QMessageBox::Save|QMessageBox::Ignore|QMessageBox::Cancel);
}

int ConfigFilePort::ShowWarning_WhenOpenFailed()
{
    return QMessageBox::warning(this,tr("错误"),tr("打开文件失败"));
}
int ConfigFilePort::ShowWarning_WhenSaveFailed()
{
    return QMessageBox::warning(this,tr("错误"),tr("保存文件失败"));
}

//关闭按钮触发时此函数被调用，检查文本是否已保存
void ConfigFilePort::closeEvent(QCloseEvent *event)
{
    if(!CanNewOpenClose())//只要文件改动了就保存成新的文件
    {
        int ret = ShowWarning_BeforeNewOpenClose();
        if(ret == QMessageBox::Save)
        {
            SaveFileAs();
            return;
        }
        else if(ret == QMessageBox::Cancel)
            event->ignore();                            //忽视关闭信号
        else
            event->accept();                            //接受关闭信号，文本关闭
    }
    SaveFile();
}
