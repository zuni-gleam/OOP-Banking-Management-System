#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "../models/user.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QCryptographicHash>


loginwindow::loginwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);

    connect(ui->loginbtn,       &QPushButton::clicked, this, &loginwindow::handlelogin);
    connect(ui->backbtn,        &QPushButton::clicked, this, &loginwindow::handlereturn);
    connect(ui->forgotpassbtn,  &QPushButton::clicked, this, &loginwindow::handleforgotpassword);
}

loginwindow::~loginwindow()
{
    delete ui;
}

void loginwindow::handlelogin()
{
    QString uname = ui->unameinput->text().trimmed();
    QString pass  = ui->passinput->text();

    if (uname.isEmpty() || pass.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
        return;
    }

    if (!user::exists(uname))
    {
        QMessageBox::warning(this, "Error", "Username does not exist.");
        return;
    }

    user u = user::loadfromdb(uname);
    QString hashed = QString(QCryptographicHash::hash(pass.toUtf8(), QCryptographicHash::Sha256).toHex());

    if (u.getpass() == hashed && u.getrole() == "customer")
    {
        emit loginsuccessful(u);
    }
    else
    {
        QMessageBox::critical(this, "Error", "Incorrect password or role.");
    }
}


void loginwindow::handleforgotpassword()
{
    bool ok;

    QString uname = QInputDialog::getText(this, "Forgot Password",
                        "Enter your username:", QLineEdit::Normal, "", &ok);
    if (!ok || uname.trimmed().isEmpty())
    {
        return;
    }

    uname = uname.trimmed();

    if (!user::exists(uname))
    {
        QMessageBox::warning(this, "Not Found", "Username not found.");
        return;
    }

    user u = user::loadfromdb(uname);


    QString answer = QInputDialog::getText(this, "Security Question",
                        u.getsq(), QLineEdit::Normal, "", &ok);
    if (!ok || answer.trimmed().isEmpty())
    {
        return;
    }

    if (answer.trimmed().toLower() != u.getsa().toLower())
    {
        QMessageBox::critical(this, "Failed", "Incorrect security answer.");
        return;
    }


    QString newpass = QInputDialog::getText(this, "Reset Password",
                        "Enter your new password (min 6 chars):", QLineEdit::Password, "", &ok);
    if (!ok || newpass.length() < 6)
    {
        QMessageBox::warning(this, "Error", "Password must be at least 6 characters.");
        return;
    }

    QString hashed = QString(QCryptographicHash::hash(newpass.toUtf8(), QCryptographicHash::Sha256).toHex());
    u.setpass(hashed);
    if (u.updatepass())
    {
        QMessageBox::information(this, "Success", "Password reset successfully! Please log in.");
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to reset password.");
    }
}

void loginwindow::handlereturn()
{
    this->close();
}

void loginwindow::clearfields()
{
    ui->unameinput->clear();
    ui->passinput->clear();
}
