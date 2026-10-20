#ifndef IMAGETEST_H
#define IMAGETEST_H

#include <QMainWindow>
#include"QTimer"
#include"QPixmap"
namespace Ui {
class imagetest;
}

class imagetest : public QMainWindow
{
    Q_OBJECT

public:
    explicit imagetest(QWidget *parent = nullptr);
    ~imagetest();

private slots:
    void on_pushButton_clicked();

private:
    Ui::imagetest *ui;
};

static imagetest xxx;

#endif // IMAGETEST_H
