#include "totpdialog.h"
#include "ui_totpdialog.h"
#include "../security/totp.h"
#include <QMessageBox>


totpdialog::totpdialog(const QString& usersecret, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totpdialog),
    activepass(usersecret)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    connect(ui->verifybtn, &QPushButton::clicked, this, &totpdialog::handleverify);
    connect(ui->cancelbtn, &QPushButton::clicked, this, &totpdialog::handlecancel);
}

totpdialog::~totpdialog()
{
    delete ui;
}

void totpdialog::handleverify()
{
    QString typedpin = ui->pininput->text().trimmed();

    if (typedpin.length() != 6)
    {
        QMessageBox::warning(this, "Failed", "Authentication code must be exactly 6 digits.");
        return;
    }

    if (totp::verify(activepass, typedpin))
    {
        accept();
    }
    else
    {
        QMessageBox::critical(this, "Rejected", "Invalid TOTP code. Check your Google Authenticator app.");
    }
}

void totpdialog::handlecancel()
{
    reject();
}