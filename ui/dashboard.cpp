#include "dashboard.h
#include "ui_dashboard.h"
#include "../db/dbmanager.h"
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <iostream>

using namespace std;

dashboard::dashboard(const user& activeuser, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dashboard),
    currentuser(activeuser)
{
    ui->setupUi(this);

    currentaccount = account::loadfromdb(currentuser.getid(), "savings");
    if (!currentaccount)
    {
        currentaccount = account::loadfromdb(currentuser.getid(), "current");
    }

    refreshui();

    connect(ui->depbtn, &QPushButton::clicked, this, &dashboard::handledeposit);
    connect(ui->withbtn, &QPushButton::clicked, this, &dashboard::handlewithdraw);
    connect(ui->xferbtn, &QPushButton::clicked, this, &dashboard::handletransfer);
    connect(ui->saveprofilebtn, &QPushButton::clicked, this, &dashboard::handleupdateprofile);
    connect(ui->loancalcbtn, &QPushButton::clicked, this, &dashboard::handleloancalc);
    connect(ui->currcalcbtn, &QPushButton::clicked, this, &dashboard::handlecurrencycalc);
    connect(ui->logoutbtn, &QPushButton::clicked, this, &dashboard::handlelogout);
}

dashboard::~dashboard()
{
    delete ui;
    if (currentaccount)
    {
        delete currentaccount;
    }
}

void dashboard::refreshui()
{
    ui->welcomeuserlabel->setText("Welcome back, " + currentuser.getname() + "!");
    ui->usernamelabel->setText(currentuser.getuname());
    ui->namelineedit->setText(currentuser.getname());
    ui->phonelineedit->setText(currentuser.getphone());
    ui->addrlineedit->setText(currentuser.getaddr());

    if (currentaccount)
    {
        ui->balancelabel->setText("Rs " + QString::number(currentaccount->getbal(), 'f', 2));
        ui->accnumlabel->setText("Acc ID: #" + QString::number(currentaccount->getid()));
        ui->acctypelabel->setText("Type: " + currentaccount->gettype().toUpper() + " (" + currentuser.gettier().toUpper() + ")");
    }

    loadtransactions();
}

void dashboard::loadtransactions()
{
    if (!currentaccount) return;

    ui->txntable->setRowCount(0);
    QSqlQuery q;
    q.prepare("SELECT txntype, amount, balafter, targetacc, createdat FROM transactions "
              "WHERE accid = ? ORDER BY id DESC LIMIT 50");
    q.addBindValue(currentaccount->getid());
    q.exec();

    int row = 0;
    while (q.next())
    {
        ui->txntable->insertRow(row);
        ui->txntable->setItem(row, 0, new QTableWidgetItem(q.value(4).toString()));
        ui->txntable->setItem(row, 1, new QTableWidgetItem(q.value(0).toString().toUpper()));
        ui->txntable->setItem(row, 2, new QTableWidgetItem("Rs " + QString::number(q.value(1).toDouble(), 'f', 2)));
        ui->txntable->setItem(row, 3, new QTableWidgetItem("Rs " + QString::number(q.value(2).toDouble(), 'f', 2)));

        QString details = q.value(3).toString();
        if (details.isEmpty())
        {
            details = "-";
        }
        ui->txntable->setItem(row, 4, new QTableWidgetItem(details));
        row++;
    }
}

void dashboard::addtransaction(const QString& type, double amount, double balafter, const QString& target)
{
    QSqlQuery q;
    q.prepare("INSERT INTO transactions (accid, txntype, amount, balafter, targetacc) "
              "VALUES (?, ?, ?, ?, ?)");
    q.addBindValue(currentaccount->getid());
    q.addBindValue(type);
    q.addBindValue(amount);
    q.addBindValue(balafter);
    q.addBindValue(target);
    q.exec();
}

void dashboard::handledeposit()
{
    double amt = ui->depinput->text().toDouble();
    if (amt <= 0)
    {
        QMessageBox::warning(this, "Error", "Please enter a valid deposit amount.");
        return;
    }

    if (currentaccount->deposit(amt))
    {
        addtransaction("deposit", amt, currentaccount->getbal());
        QMessageBox::information(this, "Success", "Successfully deposited Rs " + QString::number(amt, 'f', 2));
        ui->depinput->clear();
        refreshui();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Deposit failed.");
    }
}

void dashboard::handlewithdraw()
{
    double amt = ui->withinput->text().toDouble();
    if (amt <= 0)
    {
        QMessageBox::warning(this, "Error", "Please enter a valid withdrawal amount.");
        return;
    }

    if (currentaccount->withdraw(amt))
    {
        addtransaction("withdrawal", amt, currentaccount->getbal());
        QMessageBox::information(this, "Success", "Successfully withdrew Rs " + QString::number(amt, 'f', 2));
        ui->withinput->clear();
        refreshui();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Withdrawal failed. Check min balance or overdraft rules.");
    }
}

void dashboard::handletransfer()
{
    QString targetuname = ui->xfertargetinput->text().trimmed();
    double amt = ui->xferamtinput->text().toDouble();

    if (targetuname.isEmpty() || amt <= 0)
    {
        QMessageBox::warning(this, "Error", "Please enter a valid target username and amount.");
        return;
    }

    if (targetuname == currentuser.getuname())
    {
        QMessageBox::warning(this, "Error", "You cannot transfer money to yourself.");
        return;
    }

    if (!user::exists(targetuname))
    {
        QMessageBox::warning(this, "Error", "Recipient username not found.");
        return;
    }

    user recipient = user::loadfromdb(targetuname);
    account *recipientacc = account::loadfromdb(recipient.getid(), "savings");
    if (!recipientacc)
    {
        recipientacc = account::loadfromdb(recipient.getid(), "current");
    }

    if (!recipientacc)
    {
        QMessageBox::critical(this, "Error", "Recipient account not active.");
        return;
    }

    if (currentaccount->withdraw(amt))
    {
        recipientacc->deposit(amt);

        addtransaction("transfer to " + targetuname, amt, currentaccount->getbal(), "To: " + targetuname);

        QSqlQuery q;
        q.prepare("INSERT INTO transactions (accid, txntype, amount, balafter, targetacc) VALUES (?, 'deposit', ?, ?, ?)");
        q.addBindValue(recipientacc->getid());
        q.addBindValue(amt);
        q.addBindValue(recipientacc->getbal());
        q.addBindValue("From: " + currentuser.getuname());
        q.exec();

        QMessageBox::information(this, "Success", "Transferred Rs " + QString::number(amt, 'f', 2) + " successfully!");
        ui->xfertargetinput->clear();
        ui->xferamtinput->clear();
        refreshui();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Transfer failed. Insufficient funds or overdraft limit exceeded.");
    }

    delete recipientacc;
}

void dashboard::handleupdateprofile()
{
    QString name = ui->namelineedit->text().trimmed();
    QString phone = ui->phonelineedit->text().trimmed();
    QString addr = ui->addrlineedit->text().trimmed();

    if (name.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Full Name cannot be empty.");
        return;
    }

    currentuser.setname(name);
    currentuser.setphone(phone);
    currentuser.setaddr(addr);

    if (currentuser.updateprofile())
    {
        QMessageBox::information(this, "Success", "Profile updated successfully!");
        refreshui();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to update profile.");
    }
}

void dashboard::handleloancalc()
{
    double principle = ui->loanamtinput->text().toDouble();
    double annualrate = ui->loanrateinput->text().toDouble() / 100.0;
    int months = ui->loanmonthsinput->text().toInt();

    if (principle <= 0 || annualrate <= 0 || months <= 0)
    {
        QMessageBox::warning(this, "Error", "Please enter valid loan parameters.");
        return;
    }

    double monthlyrate = annualrate / 12.0;
    double emi = (principle * monthlyrate * pow(1 + monthlyrate, months)) / (pow(1 + monthlyrate, months) - 1);

    ui->emilabel->setText("Monthly EMI: Rs " + QString::number(emi, 'f', 2));
}

void dashboard::handlecurrencycalc()
{
    double amt = ui->currinput->text().toDouble();
    QString from = ui->currfrombox->currentText();
    QString to = ui->currtobox->currentText();

    if (amt <= 0)
    {
        QMessageBox::warning(this, "Error", "Please enter a valid amount to convert.");
        return;
    }

    double rate = 1.0;
    if (from == "USD" && to == "PKR") rate = 278.50;
    else if (from == "PKR" && to == "USD") rate = 1.0 / 278.50;
    else if (from == "EUR" && to == "PKR") rate = 302.20;
    else if (from == "PKR" && to == "EUR") rate = 1.0 / 302.20;
    else if (from == "USD" && to == "EUR") rate = 0.92;
    else if (from == "EUR" && to == "USD") rate = 1.08;

    double result = amt * rate;
    ui->currresult->setText("Converted: " + QString::number(result, 'f', 2) + " " + to);
}

void dashboard::handlelogout()
{
    this->close();
}
