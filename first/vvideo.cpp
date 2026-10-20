#include "vvideo.h"

vvideo::vvideo(QWidget *parent):QVideoWidget(parent)
{

}
vvideo::~vvideo()
{

}
void vvideo::keyPressEvent(QKeyEvent* event)
{
   //判断键盘按下的按键是否为esc
    if(event->key() == Qt::Key_Escape)
    {
        //将子窗口恢复为播放窗口大小
        this->setWindowFlags(Qt::SubWindow);
        //恢复原始大小
        this->showNormal();
    }
}
