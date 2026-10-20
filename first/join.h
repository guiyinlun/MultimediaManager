#ifndef JOIN_H
#define JOIN_H

#include <QMainWindow>
void SQL_init();

namespace Ui {
class join;
}

class join : public QMainWindow
{
    Q_OBJECT

public:
    explicit join(QWidget *parent = nullptr);
    ~join();
    void SQL_Init(QString name, QString sex, QString username, QString password);
private slots:
    void on_btnzhuce_clicked();

    void on_btnreset_clicked();

    void on_btnquit_clicked();

private:
    Ui::join *ui;
};

#endif // JOIN_H
