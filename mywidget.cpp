#include "mywidget.h"
#include "ui_mywidget.h"
#include <QMessageBox>
#include <QDebug>
#include <QAction>
#include <QFileDialog>
MyWidget::MyWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MyWidget)
{
  ui->setupUi(this);
}

/**
 * @brief MyWidget::~MyWidget
 * 析构函数：用来释放
 */
MyWidget::~MyWidget()
{
  delete ui;
}

void MyWidget::on_pb_SelectFile_clicked()//选择文件功能函数
{
  if(false == OpenSeleteFile())//弹出选择文件对话框 如果成功选择文件，主线程myWidget类就有对象存储了文件路径
  {
    return;
  }
  if(FilePath == NULL)//如果没有选择文件，即文件路径为空
  {
    return;
  }
  ui->le_FilePath->setText(FilePath);//如果选中了文件，setText() 或者 insert() 改变其中的文本,那么行编辑器中就会出现选中的文件的路径
  ShowTxtToWindow();
}

void MyWidget::on_pb_SaveFile_clicked()//保存文件功能函数
{
	if(FilePath == NULL){
		QMessageBox::information(this,QString::fromUtf8("提示"),QString::fromUtf8("请选择保存的文件"),"OK");
	}else{
		int flag = QMessageBox::information(NULL, "提示", "是否保存文件", QMessageBox::No, QMessageBox::Yes);
		if(flag == QMessageBox::Yes){
			QFile myfile(FilePath);//创建一个输出文件的文档
		    if (myfile.open(QFile::WriteOnly|QFile::Text))//注意WriteOnly是往文本中写入的时候用，ReadOnly是在读文本中内容的时候用，Text表示将原来文件中的内容按行输出
		    {
		        QTextStream out(&myfile);
		        out << ui->textEdit->toPlainText();
		    }
			ShowTxtToWindow();
		}
	}
}

bool MyWidget::OpenSeleteFile()//弹出选择文件对话框
{
	/**
   * @brief strPath
   * 类名::函数名->此时的函数是一个静态函数。例如：getOpenFileName
   * getOpenFileName()函数提供了六个参数：
   *  * 第一个参数的作用是用于指定父组件，基本上构造函数都会提供一个默认的值，即parent = 0;
   *  * 第二个参数的作用是显示的按钮的标题
   *  * 第三个参数的作用是对话框显示时默认打开的目录
   *  * 第四个参数的作用是对话框的后缀名过滤器，过滤掉不需要选择的文件名称
   *  * 第五个参数的作用是默认选择的过滤器
   *  * 第六个参数的作用是对话框的一些参数设定，例如对话框只显示文件夹等信息
   *  ** 注意：还函数有的参数这是可以不需要选择的，例如最后两个参数都是可以省略的，
   *       但是第一个参数和第三个参数当没有特殊要求的时候，将第一个参数置为NULL，
   *       第三个参数置为空字符串。即"";
   */
   //选择的文件是所有类型的文件，strPath用来保存选取文件的路径
  QString strPath = QFileDialog::getOpenFileName(NULL,QString::fromUtf8("打开文件"),"",QObject::tr("*(*.*)"));
  if(strPath == NULL)//用户没有选择文件
  {
    QMessageBox::information(this,QString::fromUtf8("提示"),QString::fromUtf8("选择文件失败"),"OK");
    return false;//用户点击的取消按钮
  }
  FilePath = strPath;//保存用户的文件路径
  return true;
}

void MyWidget::ShowTxtToWindow()//显示文本文件中的内容
{
	QString fileName = FilePath;
	
    if(!fileName.isEmpty())
    {
        QFile *file = new QFile;
        file->setFileName(fileName);
        bool ok = file->open(QIODevice::ReadOnly);
        if(ok)
        {
            QTextStream in(file);
            ui->textEdit->setText(in.readAll());
            file->close();
            delete file;
        }
        else
        {
            QMessageBox::information(this,"错误信息","打开文件:" + file->errorString());
        }
    }
}



