#include "photos.h"
#include "welcome.h"
#include "ui_photos.h"

photos::photos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::photos)
{
        ui->setupUi(this);
        ftimer.setInterval(1000);
        ftimer.start();
        connect(&ftimer, SIGNAL(timeout()), this, SLOT(updateDateTime()));
        ftimer2.setInterval(100);
        connect(ui->pushButtongb,SIGNAL(clicked()),this,SLOT(on_pushButtongb_clicked()));
        connect(&ftimer2, SIGNAL(timeout()), this, SLOT(playImage()));


}

photos::~photos()
{
    delete ui;
}
//用户
void photos::set_userName(const QString value)
{
    ui->labeluser->setText("用户:" + value);
}
//获取系统时间
void photos::updateDateTime()
{
    QString date=QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
    ui->labeltime->setText("现在时间: "+date);
}
//图片的显示操作
void photos::showImage(QString filename)
{
    //实例化图像对象
    QPixmap pix(filename);
    //设置显示大小和控件一致
    pix = pix.scaled(ui->labelshow->size());
    //最后显示图像
    ui->labelshow->setPixmap(pix);
    //显示图片的路径到任务栏
    ui->labeldir->setText("路径: "+filename);
}
//播放
void photos::playImage()
{
    //定义图标标识
    static int i = 0;
    //showImage(dirpathlist[i]);
    //获取完整图像操作路径
    QString filename = dirpathlist[i];
    qDebug()<< filename;
    i++;
    //判断i是否超过,超过路径
    if(i >= dirpathlist.size())
    {
       i = 0;
    }

    //显示图像内容
    QPixmap pix(filename);
    //设置图像的显示大小
    pix = pix.scaled(ui->labelshow->size());
    //显示图像数据
    ui->labelshow->setPixmap(pix);
     ui->labeldir->setText("路径: "+filename);
    //showImage(filename);

}
//选择
void photos::on_pushButtonxz_clicked()
{
    ftimer2.stop();
        //通过文件对话框进行文件选择
        dirpathlist = QFileDialog::getOpenFileNames(this, "选择图片", dir, filter);
        //通过for循环遍历获取每一个图片的访问路径
        for(int i = 0; i < dirpathlist.size(); i++)
        {
            qDebug() << i;
            qDebug() << dirpathlist.at(i); //输出每一个图片路径
        }
        //ui->labeldir->setText(dir);
        showImage(dirpathlist[0]);
}

//上
void photos::on_pushButtons_clicked()
{
    ftimer2.stop();
        if(listflag==0)
            listflag=dirpathlist.size()-1;
        else
        qDebug() << listflag--;
        showImage(dirpathlist[listflag]);
}
//下
void photos::on_pushButtonx_clicked()
{
    ftimer2.stop();
        if(listflag == dirpathlist.size()-1)
            listflag=0;
        else
        qDebug() << listflag++;
        showImage(dirpathlist[listflag]);
}
//自动
void photos::on_pushButtonzd_clicked()
{
ftimer2.start();
}
//暂停
void photos::on_pushButtonzt_clicked()
{
ftimer2.stop();
}
//返回
void photos::on_pushButtonfh_clicked()
{
    welcome* w = new welcome();
    //通过主界面对象传递账户信息
    w->set_Name(username);
    //展示界面
    w->show();
    //关闭当前页面
    this->close();
}
//关闭
void photos::on_pushButtongb_clicked()
{
    this->close();
}
