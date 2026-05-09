#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "../models/user.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <iostream>

using namespace std;

loginwindow::loginwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);

    connect(ui->loginbtn, &QPushButton::clicked, this, &loginwindow::handlelogin);
    connect(ui->backbtn, &QPushButton::clicked, this, &loginwindow::handlereturn);
}

loginwindow::~loginwindow()
{
    delete ui;
}

void loginwindow::handlelogin()
{
    QString uname = ui->unameinput->text().trimmed();
    QString pass = ui->passinput->text();

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
        QMessageBox::information(this, "Success", "Welcome back, " + u.getname() + "!");
        // We will open Zunaira's Dashboard here once we write it next!
        this->close();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Incorrect password or role.");
    }
}

void loginwindow::handlereturn()
{
    this->close();
}