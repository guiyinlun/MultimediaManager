#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>
#include <QPixmap>//图像类
#include <QSplashScreen>//动画类
#include <QThread>//线程类

namespace Ui {
class welcome;
}

class welcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = nullptr);
    ~welcome();

private slots:

   void on_pushButtonxc_clicked();

   void on_pushButtonplayer_clicked();

   void on_pushButtonfh_clicked();

   void on_pushButton_clicked();

public:
    void set_Name(const QString value);
    QString username;

private:
    Ui::welcome *ui;
};

#endif // WELCOME_H
