#include "join.h"
#include"first.h"
#include "ui_join.h"

join::join(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::join)
{
    ui->setupUi(this);
}

join::~join()
{
    delete ui;
}
//数据库的初始化
void SQL_init()
{
    //添加数据库驱动
    QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
    //指定数据库的路径
    DB.setDatabaseName("./first.db");
    //打开数据库
    if(!DB.open())
    {
        qDebug() << "数据库打开失败";
    }
    else
    {
        //创建账户和密码的表格
        QSqlQuery query;
        //执行sql语句
        QString sql = QString("create table if not exists user(id integer primary key autoincrement,name ntext not null,sex ntext not null,username netext unique not null,password ntext not null);");
        if(!query.exec(sql))
        {
            qDebug() << "创建失败";
        }
        else
        {
            qDebug() << "创建成功";
        }
    }
}
//插入数据
void join::SQL_Init(QString name, QString sex, QString username, QString password)
{
    //插入表格
    QString sql = QString("insert into user(name,sex,username,password) values('%1','%2','%3','%4');")
                  .arg(name).arg(sex).arg(username).arg(password);
    //执行SQL语句
    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug() << "注册失败";
        QMessageBox::information(this, "注册提示", "注册失败   ");
    }
    else
    {
        qDebug() << "注册成功";
        QMessageBox::information(this, "注册提示", "注册成功   ");
    }
}


void join::on_btnzhuce_clicked()
{
    //获取当前的数据
        QString name = ui->lineName->text(); //用户名
        QString username = ui->lineUsername->text(); //用户账户
        QString password = ui->linePassword->text(); //用户密码
        QString passwords = ui->linePasswords->text();
        //当确认密码和账户密码一致
        if(password == passwords)
        {
            //判断是男还是女
            if(ui->rbtnboy->isChecked())
            {
                SQL_Init(name, "男", username, password);
            }
            else if(ui->rbtngril->isChecked())
            {
                SQL_Init(name, "女", username, password);
            }
        }
        else
        {
            QMessageBox::information(this, "密码提示标题", "两次输入的密码不一致");
            //清空密码和确认密码
            ui->linePassword->clear();
            ui->linePasswords->clear();
        }
}

void join::on_btnreset_clicked()
{
        //清空所有数据框
        ui->lineName->clear();
        ui->lineUsername->clear();
        ui->linePassword->clear();
        ui->linePasswords->clear();
}

void join::on_btnquit_clicked()
{
        //界面对象创建
        first * w = new first;
        //展示界面
        w->show();
        //关闭注册
        this->close();
}
