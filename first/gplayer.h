#ifndef GPLAYER_H
#define GPLAYER_H

#include <QMainWindow>
#include <QFileDialog>//文件对话框
#include <QListWidgetItem>
#include <QMediaPlaylist>//播放列表
#include <QMediaPlayer>//播放媒体
#include <QVideoWidget>
#include <QDebug>
#include <QFileInfo>
#include <QTime>
#include<QMovie>
#include "vvideo.h"

namespace Ui {
class gplayer;
}

class gplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit gplayer(QWidget *parent = nullptr);
    ~gplayer();

private slots:
    //获取媒体的播放进度长度
        void get_Sider(qint64 duration);
        //进度更新值
        void set_value(qint64 position);
        //水平滑条的移动 进度调整
        void on_hSlider_sliderMoved(int position);
        //垂直滑动条 修改音量
        void on_verticalSlider_sliderMoved(int position);
        //双击列表播放音乐
       void on_listWidgetgd_itemDoubleClicked(QListWidgetItem *item);
       void setButtonImage(QPushButton *button, QString image);
    void on_pushButtonbf_clicked();

    void on_pushButtons_clicked();

    void on_pushButtonzt_clicked();

    void on_pushButtonx_clicked();

    void on_pushButtonqp_clicked();

    void on_pushButtontj_clicked();

    void on_pushButtonsc_clicked();

    void on_pushButtonqk_clicked();

    void on_pushButtonfh_clicked();

private:
    Ui::gplayer *ui;
    QMediaPlayer* mplayer;
    //实例化播放列表
    QMediaPlaylist* playlist;
    int bfsx=1;
    //实例化播放窗口
    vvideo* videow;
public:
    void set_userName(const QString value);
    QString username;
};

#endif // GPLAYER_H
