#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "qrcodedialog.h"
#include "../models/user.h"
#include "../models/account.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <QRandomGenerator>
#include <QDateTime>
#include <QRegularExpression>

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


static QString generatetotpsecret()
{
    const QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
    QString result;
    for (int i = 0; i < 16; i++)
        result += chars[QRandomGenerator::global()->bounded(32)];
    return result;
}

void registerwindow::handlecreate()
{
    QString uname = ui->unameinput->text().trimmed();
    QString pass  = ui->passinput->text();
    QString name  = ui->nameinput->text().trimmed();
    QString phone = ui->phoneinput->text().trimmed();
    QString email = ui->emailinput->text().trimmed();
    QString addr  = ui->addrinput->text().trimmed();

    QString acctype = "savings";
    if (ui->acctypebox->currentIndex() == 1)
    {
        acctype = "current";
    }


    QString tier = "gold";
    int tierIdx = ui->tierbox->currentIndex();
    if (tierIdx == 1)
    {
        tier = "platinum";
    }
    else if (tierIdx == 2)
    {
        tier = "diamond";
    }

    QString sq = ui->sqbox->currentText();
    QString sa = ui->sainput->text().trimmed();

    if (uname.isEmpty() || pass.isEmpty() || name.isEmpty() || sa.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please fill in all required fields.");
        return;
    }

    if (pass.length() < 6)
    {
        QMessageBox::warning(this, "Error", "Password must be at least 6 characters long.");
        return;
    }

    // Phone: only digits allowed (7-15 digits)
    if (!phone.isEmpty())
    {
        QRegularExpression phoneRe("^[0-9]{7,15}$");
        if (!phoneRe.match(phone).hasMatch())
        {
            QMessageBox::warning(this, "Invalid Phone Number",
                "Phone number must contain digits only (7–15 digits).\n"
                "Example: 03001234567");
            ui->phoneinput->setFocus();
            return;
        }
    }

    // Email: must end with @gmail.com if provided
    if (!email.isEmpty())
    {
        QRegularExpression emailRe("^[a-zA-Z0-9._%+\\-]+@gmail\\.com$");
        if (!emailRe.match(email).hasMatch())
        {
            QMessageBox::warning(this, "Invalid Email Address",
                "Email must be a valid Gmail address ending with @gmail.com\n"
                "Example: yourname@gmail.com");
            ui->emailinput->setFocus();
            return;
        }
    }

    if (user::exists(uname))
    {
        QMessageBox::warning(this, "Error", "Username already exists.");
        return;
    }

    QString hashed = QString(QCryptographicHash::hash(pass.toUtf8(), QCryptographicHash::Sha256).toHex());


    QString totpsecret = generatetotpsecret();

    user u(-1, uname, hashed, "customer", name, phone, addr, sq, sa, totpsecret, tier);
    if (u.savetodb())
    {
        user created = user::loadfromdb(uname);
        if (created.isvalid())
        {
            account::createindb(created.getid(), acctype);


            QRCodeDialog qrdlg(uname, totpsecret, this);
            qrdlg.exec();
            emit registrationdone();
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to create account.");
    }
}

void registerwindow::handlereturn()
{
    emit backrequested();
}

void registerwindow::clearfields()
{
    ui->unameinput->clear();
    ui->passinput->clear();
    ui->nameinput->clear();
    ui->phoneinput->clear();
    ui->emailinput->clear();
    ui->addrinput->clear();
    ui->sainput->clear();
    ui->acctypebox->setCurrentIndex(0);
    ui->sqbox->setCurrentIndex(0);
    ui->tierbox->setCurrentIndex(0);
}
