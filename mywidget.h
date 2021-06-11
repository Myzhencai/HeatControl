#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QAction>
namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
  Q_OBJECT
  
public:
  explicit MyWidget(QWidget *parent = 0);//声明为explicit的构造函数不能在隐式转换中使用。
  ~MyWidget();//析构函数，用于释放创建的对象
  
private slots:
  void on_pb_SelectFile_clicked();//选择文件
  void on_pb_SaveFile_clicked();//保存文件
  
private:
  Ui::MyWidget *ui;
  QString FilePath;//记录文件的路径
  
  bool OpenSeleteFile();//弹出选择文件对话框
  void ShowTxtToWindow();//显示txt文件内容
};
#endif // MYWIDGET_H
