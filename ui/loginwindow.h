#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "../models/user.h"

namespace Ui {
class loginwindow;
}

class loginwindow : public QWidget
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr);
    ~loginwindow();
    void clearfields();

signals:
    void loginsuccessful(user loggedinuser);

private slots:
    void handlelogin();
    void handleforgotpassword();
    void handlereturn();

private:
    Ui::loginwindow *ui;
};

#endif