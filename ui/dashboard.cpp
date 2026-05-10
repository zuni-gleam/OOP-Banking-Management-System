#include "dashboard.h
#include "ui_dashboard.h"
#include "totpdialog.h"
#include "../db/dbmanager.h"
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QInputDialog>
#include <QRegularExpression>
#include <memory>
#include <cmath>

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

    ui->depTitle->setVisible(false);
    ui->depinput->setVisible(false);
    ui->depbtn->setVisible(false);
    ui->withTitle->setVisible(false);
    ui->withinput->setVisible(false);
    ui->withbtn->setVisible(false);
    ui->line2->setVisible(false);

    refreshui();

    connect(ui->xferbtn,          &QPushButton::clicked, this, &dashboard::handletransfer);
    connect(ui->saveprofilebtn,   &QPushButton::clicked, this, &dashboard::handleupdateprofile);
    connect(ui->loancalcbtn,      &QPushButton::clicked, this, &dashboard::handleloancalc);
    connect(ui->currcalcbtn,      &QPushButton::clicked, this, &dashboard::handlecurrencycalc);
    connect(ui->logoutbtn,        &QPushButton::clicked, this, &dashboard::handlelogout);
    connect(ui->filtertxnbtn,     &QPushButton::clicked, this, &dashboard::handlefiltertransactions);
    connect(ui->searchtxnbtn,     &QPushButton::clicked, this, &dashboard::handlesearchtransactions);
    connect(ui->cleartxnbtn,      &QPushButton::clicked, this, &dashboard::handlecleartxnfilter);
    connect(ui->deleteaccbtn,     &QPushButton::clicked, this, &dashboard::handledeleteaccount);
}

dashboard::~dashboard()
{
    delete ui;
    if (currentaccount) delete currentaccount;
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
        currentaccount->syncdailyusage();
        ui->balancelabel->setText("Rs " + QString::number(currentaccount->getbal(), 'f', 2));
        ui->accnumlabel->setText("Acc ID: #" + QString::number(currentaccount->getid()));
        ui->acctypelabel->setText("Type: " + currentaccount->gettype().toUpper() +
                                  " (" + currentuser.gettier().toUpper() + ")");


        double limit = currentaccount->getdailylimit();
        double used  = currentaccount->getdailyused();
        ui->dailylimitlabel->setText(
            QString("Daily Limit: Rs %1 | Used: Rs %2 | Remaining: Rs %3")
                .arg(limit, 0, 'f', 0)
                .arg(used, 0, 'f', 0)
                .arg(limit - used, 0, 'f', 0));


        if (currentaccount->ispenalized())
            ui->penaltylabel->setText("âš  Account penalized: Rs 500 fee applied (balance below minimum)");
        else
            ui->penaltylabel->setText("Account standing: Good");
    }


    QString secret = currentuser.getsecret();
    if (!secret.isEmpty())
        ui->totpkeylabel->setText("ðŸ”  Google Auth Key: " + secret +
                                  "  (Add to Google Authenticator for transfer verification)");
    else
        ui->totpkeylabel->setText("ðŸ”  Google Auth Key: Not set (contact support)");

    loadtransactions();
}

void dashboard::loadtransactions(const QString& typefilter, const QString& idfilter)
{
    if (!currentaccount)
    {
        return;
    }

    ui->txntable->setRowCount(0);
    QSqlQuery q;


    if (!idfilter.isEmpty())
    {
        q.prepare("SELECT txntype, amount, balafter, targetacc, createdat, id FROM transactions "
                  "WHERE accid = ? AND id = ? ORDER BY id DESC LIMIT 50");
        q.addBindValue(currentaccount->getid());
        q.addBindValue(idfilter.toInt());
    }
    else if (!typefilter.isEmpty() && typefilter != "ALL")
    {
        q.prepare("SELECT txntype, amount, balafter, targetacc, createdat, id FROM transactions "
                  "WHERE accid = ? AND LOWER(txntype) LIKE ? ORDER BY id DESC LIMIT 50");
        q.addBindValue(currentaccount->getid());
        q.addBindValue("%" + typefilter.toLower() + "%");
    }
    else
    {
        q.prepare("SELECT txntype, amount, balafter, targetacc, createdat, id FROM transactions "
                  "WHERE accid = ? ORDER BY id DESC LIMIT 50");
        q.addBindValue(currentaccount->getid());
    }

    q.exec();

    int row = 0;
    while (q.next())
    {
        ui->txntable->insertRow(row);
        ui->txntable->setItem(row, 0, new QTableWidgetItem(q.value(5).toString()));
        ui->txntable->setItem(row, 1, new QTableWidgetItem(q.value(4).toString()));
        ui->txntable->setItem(row, 2, new QTableWidgetItem(q.value(0).toString().toUpper()));
        ui->txntable->setItem(row, 3, new QTableWidgetItem("Rs " + QString::number(q.value(1).toDouble(), 'f', 2)));
        ui->txntable->setItem(row, 4, new QTableWidgetItem("Rs " + QString::number(q.value(2).toDouble(), 'f', 2)));
        QString details = q.value(3).toString();
        if (details.isEmpty())
        {
            details = "-";
        }
        ui->txntable->setItem(row, 5, new QTableWidgetItem(details));
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


void dashboard::handlefiltertransactions()
{
    QString filter = ui->txntypefilterinput->text().trimmed();
    loadtransactions(filter.isEmpty() ? "ALL" : filter, "");
}


void dashboard::handlesearchtransactions()
{
    QString idstr = ui->txnidsearchinput->text().trimmed();
    if (idstr.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a Transaction ID to search.");
        return;
    }
    bool ok;
    int txnid = idstr.toInt(&ok);
    if (!ok || txnid <= 0)
    {
        QMessageBox::warning(this, "Error", "Transaction ID must be a positive number.");
        return;
    }
    loadtransactions("", idstr);
}


void dashboard::handlecleartxnfilter()
{
    ui->txntypefilterinput->clear();
    ui->txnidsearchinput->clear();
    loadtransactions();
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

        double balAfterDeposit = currentaccount->getbal();
        addtransaction("deposit", amt, balAfterDeposit);


        double interest = currentaccount->canapplymonthlyinterest() ? currentaccount->calcinterest() : 0.0;
        if (interest > 0)
        {
            currentaccount->deposit(interest);
            currentaccount->markinterestapplied();
            addtransaction("interest", interest, currentaccount->getbal());
            QMessageBox::information(this, "Success",
                                     "Deposited Rs " + QString::number(amt, 'f', 2) +
                                         "\n\nMonthly interest applied: Rs " + QString::number(interest, 'f', 2));
        }
        else
        {
            QMessageBox::information(this, "Success", "Deposited Rs " + QString::number(amt, 'f', 2));
        }

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


    double remaining = currentaccount->getdailylimit() - currentaccount->getdailyused();
    if (amt > remaining)
    {
        QMessageBox::warning(this, "Daily Limit Exceeded",
                             QString("Your %1 tier daily limit does not allow this withdrawal.\n"
                                     "Remaining today: Rs %2").arg(currentuser.gettier().toUpper()).arg(remaining, 0, 'f', 0));
        return;
    }

    if (currentaccount->withdraw(amt))
    {
        addtransaction("withdrawal", amt, currentaccount->getbal());
        QMessageBox::information(this, "Success", "Withdrew Rs " + QString::number(amt, 'f', 2));
        ui->withinput->clear();
        refreshui();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Withdrawal failed. Check minimum balance or overdraft rules.");
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


    double remaining = currentaccount->getdailylimit() - currentaccount->getdailyused();
    if (amt > remaining)
    {
        QMessageBox::warning(this, "Daily Limit Exceeded",
                             QString("Your %1 tier daily limit does not allow this transfer.\n"
                                     "Remaining today: Rs %2\n"
                                     "Upgrade your tier to increase limits.").arg(currentuser.gettier().toUpper()).arg(remaining, 0, 'f', 0));
        return;
    }

    user recipient = user::loadfromdb(targetuname);
    std::unique_ptr<account> recipientacc(account::loadfromdb(recipient.getid(), "savings"));
    if (!recipientacc)
        recipientacc.reset(account::loadfromdb(recipient.getid(), "current"));

    if (!recipientacc)
    {
        QMessageBox::critical(this, "Error", "Recipient account not active.");
        return;
    }


    totpdialog securebox(currentuser.getsecret(), this);
    if (securebox.exec() != QDialog::Accepted)
    {
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction())
    {
        QMessageBox::critical(this, "Error", "Could not start transfer safely.");
        return;
    }

    bool ok = currentaccount->withdraw(amt);
    if (ok)
    {
        ok = recipientacc->deposit(amt);
    }

    if (ok)
    {
        QSqlQuery senderq;
        senderq.prepare("INSERT INTO transactions (accid, txntype, amount, balafter, targetacc) VALUES (?, 'transfer', ?, ?, ?)");
        senderq.addBindValue(currentaccount->getid());
        senderq.addBindValue(amt);
        senderq.addBindValue(currentaccount->getbal());
        senderq.addBindValue("To: " + targetuname);
        ok = senderq.exec();
    }

    if (ok)
    {
        QSqlQuery receiverq;
        receiverq.prepare("INSERT INTO transactions (accid, txntype, amount, balafter, targetacc) VALUES (?, 'deposit', ?, ?, ?)");
        receiverq.addBindValue(recipientacc->getid());
        receiverq.addBindValue(amt);
        receiverq.addBindValue(recipientacc->getbal());
        receiverq.addBindValue("From: " + currentuser.getuname());
        ok = receiverq.exec();
    }

    if (ok && db.commit())
    {
        QMessageBox::information(this, "Success", "Transferred Rs " + QString::number(amt, 'f', 2) + " successfully!");
        ui->xfertargetinput->clear();
        ui->xferamtinput->clear();
        refreshui();
    }
    else
    {
        db.rollback();
        delete currentaccount;
        currentaccount = account::loadfromdb(currentuser.getid(), "savings");
        if (!currentaccount)
        {
            currentaccount = account::loadfromdb(currentuser.getid(), "current");
        }
        QMessageBox::critical(this, "Error", "Transfer failed. Insufficient funds or limit exceeded.");
        refreshui();
    }
}


void dashboard::handleupdateprofile()
{
    QString name  = ui->namelineedit->text().trimmed();
    QString phone = ui->phonelineedit->text().trimmed();
    QString addr  = ui->addrlineedit->text().trimmed();

    if (name.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Full Name cannot be empty.");
        return;
    }


    if (!phone.isEmpty())
    {
        QRegularExpression phoneRe("^[0-9]{7,15}$");
        if (!phoneRe.match(phone).hasMatch())
        {
            QMessageBox::warning(this, "Error", "Phone number must be 7â€“15 digits (numbers only).");
            return;
        }
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


bool dashboard::checkloanleligibility(double requestedamt, double income)
{
    double balance = currentaccount ? currentaccount->getbal() : 0.0;

    double minbalancecheck = requestedamt * 0.20;
    return (balance >= minbalancecheck && income > 0);
}

void dashboard::handleloancalc()
{
    double principle   = ui->loanamtinput->text().toDouble();
    double annualrate  = ui->loanrateinput->text().toDouble() / 100.0;
    int    months      = ui->loanmonthsinput->text().toInt();


    double income = 0.0;
    if (ui->loanincomeinput)
        income = ui->loanincomeinput->text().toDouble();

    if (principle <= 0 || annualrate <= 0 || months <= 0)
    {
        QMessageBox::warning(this, "Error", "Please enter valid loan parameters.");
        return;
    }

    double monthlyrate = annualrate / 12.0;



    if (monthlyrate < 0.000001)
    {
        QMessageBox::warning(this, "Error", "Interest rate is too small to calculate EMI accurately. Please enter a realistic rate.");
        return;
    }


    bool eligible = checkloanleligibility(principle, income);
    QString eligibilitytext = eligible ?
                                  "âœ“ You are ELIGIBLE for this loan (balance >= 20% of loan amount)" :
                                  "âœ— You are NOT ELIGIBLE (insufficient balance or income not provided)";

    double emi = (principle * monthlyrate * pow(1 + monthlyrate, months)) /
                 (pow(1 + monthlyrate, months) - 1);
    double totalamt = emi * months;
    double totalinterest = totalamt - principle;

    ui->emilabel->setText(
        QString("Monthly EMI: Rs %1\nTotal Amount: Rs %2\nTotal Interest: Rs %3\n%4")
            .arg(emi, 0, 'f', 2)
            .arg(totalamt, 0, 'f', 2)
            .arg(totalinterest, 0, 'f', 2)
            .arg(eligibilitytext));
}


void dashboard::handlecurrencycalc()
{
    double amt  = ui->currinput->text().toDouble();
    QString from = ui->currfrombox->currentText();
    QString to   = ui->currtobox->currentText();

    if (amt <= 0)
    {
        QMessageBox::warning(this, "Error", "Please enter a valid amount to convert.");
        return;
    }


    if (from == to)
    {
        QMessageBox::warning(this, "Error", "Please select two different currencies.");
        return;
    }


    double rate = -1.0;
    if (from == "USD" && to == "PKR")
    {
        rate = 278.50;
    }
    else if (from == "PKR" && to == "USD")
    {
        rate = 1.0 / 278.50;
    }
    else if (from == "EUR" && to == "PKR")
    {
        rate = 302.20;
    }
    else if (from == "PKR" && to == "EUR")
    {
        rate = 1.0 / 302.20;
    }
    else if (from == "GBP" && to == "PKR")
    {
        rate = 352.80;
    }
    else if (from == "PKR" && to == "GBP")
    {
        rate = 1.0 / 352.80;
    }
    else if (from == "USD" && to == "EUR")
    {
        rate = 0.92;
    }
    else if (from == "EUR" && to == "USD")
    {
        rate = 1.08;
    }
    else if (from == "USD" && to == "GBP")
    {
        rate = 0.79;
    }
    else if (from == "GBP" && to == "USD")
    {
        rate = 1.27;
    }
    else if (from == "EUR" && to == "GBP")
    {
        rate = 0.86;
    }
    else if (from == "GBP" && to == "EUR")
    {
        rate = 1.16;
    }

    if (rate < 0)
    {
        QMessageBox::warning(this, "Error", "Conversion rate not available for this pair.");
        return;
    }

    double result = amt * rate;
    ui->currresult->setText(
        QString("%1 %2 = %3 %4 (Rate: 1 %2 = %5 %4)")
            .arg(amt, 0, 'f', 2).arg(from)
            .arg(result, 0, 'f', 2).arg(to)
            .arg(rate, 0, 'f', 4));
}


void dashboard::handledeleteaccount()
{
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Delete Account",
        "Are you sure you want to permanently delete your account?\n"
        "All your data, account history, and balance will be lost.\n"
        "This action CANNOT be undone.",
        QMessageBox::Yes | QMessageBox::No);

    if (reply != QMessageBox::Yes)
    {
        return;
    }


    bool ok;
    QString confirm = QInputDialog::getText(this, "Confirm Deletion",
                                            "Type your username to confirm permanent deletion:", QLineEdit::Normal, "", &ok);
    if (!ok || confirm.trimmed() != currentuser.getuname())
    {
        QMessageBox::information(this, "Cancelled", "Account deletion cancelled.");
        return;
    }

    if (currentuser.deleteaccount())
    {
        QMessageBox::information(this, "Deleted", "Your account has been permanently deleted.");
        emit loggedout();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to delete account.");
    }
}

void dashboard::handlelogout()
{
    emit loggedout();
}