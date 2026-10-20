#include "photodh.h"
#include "photos.h"
#include "ui_photodh.h"

photodh::photodh(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::photodh)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//透明标题栏
    movie_show();
    //关联获取帧数据和槽函数设置
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(count_image(int)));
}

photodh::~photodh()
{
     delete ui;
}
//显示动态画面
void photodh::movie_show()
{
    //创建movie对象
    movie = new QMovie(":/Login/image/bgdonghuatwo.gif");
    //设置显示大小
    movie->setScaledSize(ui->label->size());
    //显示动态数据
    ui->label->setMovie(movie);
    //启动动画
    movie->start();
}

//设计槽函数
void photodh::count_image(int number)
{
    //计数比实际的数据多一位
    movie->frameCount();
    //判断比较最后的一张图片
    if(number >= movie->frameCount() - 1)
    {
        //播放暂停
        movie->stop();
        //实例化界面对象
        //切换界面操作
        photos* w = new photos;
        w->username=this->username;
        w->set_userName(this->username);
        w->show();
        //关闭该界面
        this->close();
    }
}

