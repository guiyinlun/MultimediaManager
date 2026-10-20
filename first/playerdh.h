#ifndef PLAYERDH_H
#define PLAYERDH_H

#include <QMainWindow>
#include <QMovie>
#include <QDebug>

namespace Ui {
class playerdh;
}

class playerdh : public QMainWindow
{
    Q_OBJECT

public:
    explicit playerdh(QWidget *parent = nullptr);
    ~playerdh();
    void movie_show();
    QString username;
private slots:
    void count_image(int number);
private:
    Ui::playerdh *ui;
    QMovie* movie;//实例化对象
};

#endif // PLAYERDH_H
