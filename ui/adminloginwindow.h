#ifndef ADMINLOGINWINDOW_H
#define ADMINLOGINWINDOW_H

#include <QWidget>

namespace Ui {
class adminloginwindow;
}

class adminloginwindow : public QWidget
{
    Q_OBJECT

public:
    explicit adminloginwindow(QWidget *parent = nullptr);
    ~adminloginwindow();

private slots:
    void handleadminlogin();
    void handlereturn();

signals:
    void loginconfirmed();

private:
    Ui::adminloginwindow *ui;
};

#endif