#ifndef PHOTOS_H
#define PHOTOS_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileDialog>//文件弹窗操作
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QPixmap>
#include <QSplashScreen>//动画类
#include <QThread>//线程类

namespace Ui {
class photos;
}

class photos : public QMainWindow
{
    Q_OBJECT

public:
    explicit photos(QWidget *parent = nullptr);
    ~photos();
    void showImage(QString filename);
    QString username;
private slots:
    void on_pushButtonxz_clicked();

    void on_pushButtonfh_clicked();

    void on_pushButtons_clicked();

    void on_pushButtonx_clicked();

    void on_pushButtonzd_clicked();

    void on_pushButtonzt_clicked();

    void on_pushButtongb_clicked();
    void  updateDateTime();
    void  playImage();

private:
    Ui::photos *ui;
    QTimer ftimer;
        QTimer ftimer2;
        QStringList dirpathlist;//定义路径保存的变量
        int listflag = 0;//定义显示图像的标志位
    public:
        int i;
        void   set_userName(const QString value);
        //设置文件对话框的访问默认路径和过滤器
        QString dir = "D:/桌面/yimage";
        QString filter = "select file(*.jpg *.png *.jpeg *.bmp *.webp)";
};

#endif // PHOTOS_H
