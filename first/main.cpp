#include "first.h"
#include "gplayer.h"
#include "welcome.h"
#include "playerdh.h"
#include <QApplication>
#include <QApplication>
#include <QPixmap>//图像类
#include <QSplashScreen>//动画类
#include <QThread>//线程类


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    first w;
    //Filetest w;
    //welcome w;
    //playerdh w;
    w.show();
    //startAnimation.finish(&w);
    return a.exec();
}
