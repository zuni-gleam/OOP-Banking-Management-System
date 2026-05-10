#include "adminloginwindow.h"
#include "ui_adminloginwindow.h"
#include "../models/user.h"
#include "../security/hasher.h"
#include <QMessageBox>


adminloginwindow::adminloginwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminloginwindow)
{
    ui->setupUi(this);

    connect(ui->loginbtn, &QPushButton::clicked, this, &adminloginwindow::handleadminlogin);
    connect(ui->backbtn, &QPushButton::clicked, this, &adminloginwindow::handlereturn);
}

adminloginwindow::~adminloginwindow()
{
    delete ui;
}

void adminloginwindow::handleadminlogin()
{
    QString uname = ui->unameinput->text().trimmed();
    QString pass = ui->passinput->text();

    if (uname.isEmpty() || pass.isEmpty())
    {
        QMessageBox::warning(this, "access denied", "please enter complete credentials");
        return;
    }

    if (!user::exists(uname))
    {
        QMessageBox::critical(this, "access denied", "invalid admin privileges");
        return;
    }

    user u = user::loadfromdb(uname);

    QString hashedinput = hasher::hash(pass);

    if (u.getrole() == "admin" && u.getpass() == hashedinput)
    {
        QMessageBox::information(this, "success", "welcome administrator, level 1 clearance granted");
        emit loginconfirmed();
    }
    else
    {
        QMessageBox::critical(this, "access denied", "credentials mismatch detected");
    }
}

void adminloginwindow::handlereturn()
{
    this->close();
}

void adminloginwindow::clearfields()
{
    ui->unameinput->clear();
    ui->passinput->clear();
}