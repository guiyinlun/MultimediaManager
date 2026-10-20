#include "welcome.h"
#include "first.h"
#include "playerdh.h"
#include "photodh.h"
#include "ui_welcome.h"

welcome::welcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);

}

welcome::~welcome()
{
    delete ui;
}
void welcome::set_Name(const QString value)
{
    ui->labelhyuser->setText("欢迎用户: " + value);
}

void welcome::on_pushButtonxc_clicked()
{ 
    username=(ui->labelhyuser->text()).mid(5);
    photodh* w = new photodh;
    w->username=this->username;
    //展示界面
    w->show();
    this->close();
}

void welcome::on_pushButtonplayer_clicked()
{
    username=(ui->labelhyuser->text()).mid(5);
    playerdh* w = new playerdh;
    w->username=this->username;
    //展示界面
    w->show();
    this->close();
}

void welcome::on_pushButtonfh_clicked()
{
    //创建界面对象
    first* w = new first;
    //展示界面
    w->show();
    //隐藏此界面
    this->close();
}

void welcome::on_pushButton_clicked()
{
    this->close();
}
