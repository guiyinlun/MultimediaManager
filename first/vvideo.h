#ifndef VVIDEO_H
#define VVIDEO_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QkeyEvent>

class vvideo : public QVideoWidget
{
public:

    explicit vvideo(QWidget *parent = nullptr);
    ~vvideo();
    virtual void keyPressEvent(QKeyEvent* event);
};

#endif // VVIDEO_H
