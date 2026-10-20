#include "gplayer.h"
#include "welcome.h"
#include "ui_gplayer.h"

gplayer::gplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gplayer)
{
    ui->setupUi(this);
    //初始化数据
    mplayer = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    videow = new vvideo(this); //播放窗口
    //设置自动寻环播放
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        //设置播放器的播放列表
        mplayer->setPlaylist(playlist);
        //将播放窗口添加到水平管理器
        ui->hshow->addWidget(videow);
        //设置播放器的输出窗口
        mplayer->setVideoOutput(videow);
        //绑定信号durationChanged和槽获取媒体总长度
        connect(mplayer, SIGNAL(durationChanged(qint64)), this, SLOT(get_Sider(qint64)));
        connect(mplayer, SIGNAL(positionChanged(qint64)), this, SLOT(set_value(qint64)));
}

gplayer::~gplayer()
{
    delete ui;
}
//用户
void gplayer::set_userName(const QString value)
{
    ui->labeluser->setText("用户:" + value);
    qDebug()<<username;
}
//获取媒体的播放进度长度
void gplayer::get_Sider(qint64 duration)
{
    qDebug() << duration;
    //设置进度条的最大值
    if(duration != 0)
    {
        //设置进度条最大值
        ui->hSlider->setMaximum(duration);
        //设置总时间label——old
        QTime t = QTime(duration / 1000 / 60 / 60, duration / 1000 / 60, duration / 1000 % 60);
        ui->label_old->setText(t.toString("hh:mm:ss"));
        //设置当前歌曲的选择对象
        ui->listWidgetgd->setCurrentRow(playlist->currentIndex());
    }
}
//进度更新值
void gplayer::set_value(qint64 position)
{
    //设置进度条值
    ui->hSlider->setValue(position);
    //设置进度时间label——old
    QTime t = QTime(position / 1000 / 60 / 60, position / 1000 / 60, position / 1000 % 60);
    ui->label_new->setText(t.toString("hh:mm:ss"));
}
//水平滑条的移动 进度调整
void gplayer::on_hSlider_sliderMoved(int position)
{
    //修改播放进度
    mplayer->setPosition(position);
}

//声音滑动条 修改音量
void gplayer::on_verticalSlider_sliderMoved(int position)
{
    //设置播放器的音量
    mplayer->setVolume(position);
    //显示修改之后的数据
    ui->labelvol->setNum(position);
}
//双击列表播放音乐
void gplayer::on_listWidgetgd_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << item->text();
    //获取播放对象
    int row = ui->listWidgetgd->currentRow();
    //将对应行的设置为播放列表的数据
    playlist->setCurrentIndex(row);
    //设置播放的音量
    mplayer->setVolume(ui->verticalSlider->value());
    //设置暂停按钮
    setButtonImage(ui->pushButtonzt, ":/Login/image/zt.png");
    //播放音乐
    mplayer->play();

}
//设置按钮图片
void gplayer::setButtonImage(QPushButton *button, QString image)
{
    button->setText("");
    QPixmap pixmap(image);
    QPixmap fitpixmap = pixmap.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    button->setIcon(QIcon(fitpixmap));
    button->setIconSize(QSize(50, 50));
    button->setFlat(true);
    button->setStyleSheet("border: 0px");
}
void gplayer::on_pushButtonbf_clicked()
{
    if(bfsx==1)
            {
                setButtonImage(ui->pushButtonbf, ":/Login/image/sj.png");
                bfsx=0;
            }
            else if(bfsx==0)
            {
                setButtonImage(ui->pushButtonbf, ":/Login/image/sx.png");
                bfsx=1;
            }
}

void gplayer::on_pushButtons_clicked()
{
    int row;
        if(bfsx==1)
        {
            //获取当前的播放行
            row = playlist->currentIndex();
            //如果歌曲为0 即首位
            if(row == 0)
            {
                row = ui->listWidgetgd->count();    //获取总数
            }
            //向前继续
            row--;
        }
        else if(bfsx==0)
        {
            //通过时间获取随机种子
             qsrand(QTime::currentTime().msec());
             //对行数据性随机设定
             row = qrand() % ui->listWidgetgd->count();
        }

            //设置上一首为选中行
            ui->listWidgetgd->setCurrentRow(row);
            //播放音乐
            on_listWidgetgd_itemDoubleClicked(ui->listWidgetgd->currentItem());
}

void gplayer::on_pushButtonzt_clicked()
{
    //判断当前的状态是否为播放状态
            if(mplayer->state() == QMediaPlayer::PlayingState)
            {
                //播放暂停
                mplayer->pause();
                //设置按键显示为继续
                setButtonImage(ui->pushButtonzt, ":/Login/image/bf.png");
                //movie->stop();
            }
            //判断当前状态是否为暂停状态
            else if(mplayer->state() == QMediaPlayer::PausedState)
            {
                //继续播放
                mplayer->play();
                //设置按键显示为暂停
                setButtonImage(ui->pushButtonzt, ":/Login/image/zt.png");
                //movie->start();
            }
}

void gplayer::on_pushButtonx_clicked()
{
    int row;
        if(bfsx==1)
        {
            //获取当前的播放行
                 row = playlist->currentIndex();
                //如果歌曲为0 即首位
                if(row == ui->listWidgetgd->count()-1)
                {
                    row = -1;    //获取总数
                }
                //向前继续
                row++;
        }
        else if(bfsx==0)
        {
            //通过时间获取随机种子
             qsrand(QTime::currentTime().msec());
             //对行数据性随机设定
             row = qrand() % ui->listWidgetgd->count();
        }
                //设置上一首为选中行
            ui->listWidgetgd->setCurrentRow(row);
            //播放音乐
            on_listWidgetgd_itemDoubleClicked(ui->listWidgetgd->currentItem());
}

void gplayer::on_pushButtonqp_clicked()
{
    //设置子窗口为顶层窗口
      videow->setWindowFlags(Qt::Window);
      //全屏
      videow->showFullScreen();
}

void gplayer::on_pushButtontj_clicked()
{
    //设置文件访问的限定
            QString dir = "D:\\CloudMusic";
            QString filter = "*.mp3 *.mp4 *.avi *.wav *.m4a";
            //通过文件对话框选择文件
            QStringList files = QFileDialog::getOpenFileNames(this,
                                "选择音频", dir, filter);
            //去掉重复文件
            for(int i = 0; i < ui->listWidgetgd->count(); i++) //显示的个数
            {
                for(int j = 0; j < files.count(); j++) //读取文件个数
                {
                    //将单个路径中的文件名读取
                    QFileInfo info(files.at(j));
                    //比较列表和读取的文件名是否相同
                    if(ui->listWidgetgd->item(i)->text() == info.fileName())
                    {
                        files.removeAt(j);
                        break;
                    }
                }
            }

            //如果选择之后没有添加文件
            if(files.isEmpty())
            {
                return;
            }

            //将非重复的数据添加到列表listwidget
            for(int i = 0; i < files.count(); i++)
            {
                //将路径中的文件名读取
                QFileInfo info(files.at(i));
                //获取单独的文件名添加到listwidget
                ui->listWidgetgd->addItem(info.fileName());
                //将文件添加到playlist
                playlist->addMedia(QUrl::fromLocalFile(files.at(i)));
            }
            ui->listWidgetgd->setCurrentRow(0);//选择首行
               //获取播放对象
               //int row = ui->listWidgetgd->currentRow();
               //将对应行的设置为播放列表的数据
               //playlist->setCurrentIndex(row);
               //设置播放的音量
               ui->verticalSlider->setValue(50);
               mplayer->setVolume(ui->verticalSlider->value());
               //播放音乐
              // mplayer->play();
}

void gplayer::on_pushButtonsc_clicked()
{
    //获取相应的操作行
        int row = ui->listWidgetgd->currentRow();
        //通过listwidget的条目操作获取
        QListWidgetItem* item = ui->listWidgetgd->takeItem(row);
        //删除指定条目
        if(item)
        {
           delete item;
         }
         //从播放列表删除
        playlist->removeMedia(row);
}

void gplayer::on_pushButtonqk_clicked()
{
        //清空列表
        ui->listWidgetgd->clear();
        //清空播放列表
        playlist->clear();
}

void gplayer::on_pushButtonfh_clicked()
{
    //清空列表
    ui->listWidgetgd->clear();
    //清空播放列表
    playlist->clear();
    welcome* w = new welcome();
    //通过主界面对象传递账户信息
    w->set_Name(username);
    //展示界面
    w->show();
    //关闭当前页面
    this->close();
}
