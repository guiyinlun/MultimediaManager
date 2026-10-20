#include "first.h"
#include "join.h"
#include "welcome.h"
#include "ui_first.h"

first::first(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::first)
{
    ui->setupUi(this);
    SQL_init();

}

first::~first()
{
    delete ui;
}
void first::on_pushButtondl_clicked()
{
    //获取账户和密码
    QSqlQuery query;
    query.exec("select * from user");
    while (query.next()) {
            int i = query.value(0).toInt();
            QString name = query.value(1).toString();
            QString sex = query.value(2).toString();
            QString username = query.value(3).toString();
            QString password = query.value(4).toString();
            qDebug() <<i<< name << sex<< username<< password;
    }
    QString username = ui->lineUsername->text();
    QString pwd = ui->linePassword->text();
    //准备sql语句  对比账户和密码
    QString sql = QString("select * from user where username='%1' and password='%2';").arg(username).arg(pwd);
    //执行sql语句
    query.exec(sql);

    //判断执行结果
    if(!query.next())
    {
        QMessageBox::information(this, "登录提示", "登录失败   ");
    }
    else
    {
        QMessageBox::information(this, "登录提示", "登录成功   ");
        QString name = query.value(1).toString();
        qDebug()<< name;
        //主界面初始化
        welcome* w = new welcome();
        //通过主界面对象传递账户信息
        w->set_Name(name);
        //展示界面
        w->show();
        //关闭当前页面
        this->close();
    }
}

void first::on_pushButtonzc_clicked()
{
    //创建界面对象
    join* w = new join;
    //展示界面
    w->show();
    //隐藏此界面
    this->close();
}


