#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "../models/user.h"
#include "../models/account.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <iostream>

using namespace std;

registerwindow::registerwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerwindow)
{
    ui->setupUi(this);

    connect(ui->createbtn, &QPushButton::clicked, this, &registerwindow::handlecreate);
    connect(ui->backbtn, &QPushButton::clicked, this, &registerwindow::handlereturn);
}

registerwindow::~registerwindow()
{
    delete ui;
}

void registerwindow::handlecreate()
{
    QString uname = ui->unameinput->text().trimmed();
    QString pass = ui->passinput->text();
    QString name = ui->nameinput->text().trimmed();
    QString phone = ui->phoneinput->text().trimmed();
    QString addr = ui->addrinput->text().trimmed();

    QString acctype = "savings";
    if (ui->acctypebox->currentIndex() == 1)
    {
        acctype = "current";
    }

    QString sq = ui->sqbox->currentText();
    QString sa = ui->sainput->text().trimmed();

    if (uname.isEmpty() || pass.isEmpty() || name.isEmpty() || sa.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please fill in all required fields.");
        return;
    }

    if (user::exists(uname))
    {
        QMessageBox::warning(this, "Error", "Username already exists.");
        return;
    }

    QString hashed = QString(QCryptographicHash::hash(pass.toUtf8(), QCryptographicHash::Sha256).toHex());

    user u(-1, uname, hashed, "customer", name, phone, addr, sq, sa, "", "gold");
    if (u.savetodb())
    {
        user created = user::loadfromdb(uname);
        if (created.isvalid())
        {
            account::createindb(created.getid(), acctype);
            QMessageBox::information(this, "Success", "Account created successfully!");
            handlereturn();
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to create account.");
    }
}

void registerwindow::handlereturn()
{
    this->close();
}