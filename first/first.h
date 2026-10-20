#ifndef FIRST_H
#define FIRST_H

#include <QMainWindow>
#include <QSqlDatabase>//sql驱动
#include <QSqlQuery>//SQL语句执行
#include <QCryptographicHash>//加密类
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class first;
}

class first : public QMainWindow
{
    Q_OBJECT

public:
    explicit first(QWidget *parent = nullptr);
    ~first();

private slots:
    void on_pushButtondl_clicked();
    void on_pushButtonzc_clicked();
private:
    Ui::first *ui;
};
#endif // FIRST_H
