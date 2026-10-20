#ifndef PHOTODH_H
#define PHOTODH_H

#include <QMainWindow>
#include <QMovie>
#include <QDebug>
namespace Ui {
class photodh;
}

class photodh : public QMainWindow
{
    Q_OBJECT

public:
    explicit photodh(QWidget *parent = nullptr);
    ~photodh();
    void movie_show();
    QString username;
private slots:
    void count_image(int number);
private:
    Ui::photodh *ui;
    QMovie* movie;
};

#endif // PHOTODH_H
