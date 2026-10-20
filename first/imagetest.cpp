#include "imagetest.h"
#include "ui_imagetest.h"
#include"QPixmap"
imagetest::imagetest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::imagetest)
{
    ui->setupUi(this); 
}

imagetest::~imagetest()
{
    delete ui;
}

//显示图数据
void imagetest::on_pushButton_clicked()
{
    static int number = 2;
    QString filename = ":/image/y" + QString("%1").arg(number) + ".png";
    //实例化图像对象
    QPixmap pix(filename);
    //设置显示大小和控件一致
    pix = pix.scaled(ui->label->size());
    //最后显示图像
    ui->label->setPixmap(pix);
}
