#include "admindashboard.h"
#include "ui_admindashboard.h"
#include "../models/account.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QInputDialog>
#include <QPushButton>
#include <memory>


admindashboard::admindashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admindashboard)
{
    ui->setupUi(this);

    QPushButton *depositbtn = new QPushButton("admin deposit", this);
    depositbtn->setStyleSheet("background-color: #222222; border: 1px solid #35C759; color: #35C759; padding: 8px 15px; font-weight: bold; border-radius: 5px;");
    QPushButton *withdrawbtn = new QPushButton("admin withdraw", this);
    withdrawbtn->setStyleSheet("background-color: #222222; border: 1px solid #FF9500; color: #FF9500; padding: 8px 15px; font-weight: bold; border-radius: 5px;");
    ui->topHeader->insertWidget(3, depositbtn);
    ui->topHeader->insertWidget(4, withdrawbtn);

    connect(ui->refreshbtn,  &QPushButton::clicked, this, &admindashboard::handlerefresh);
    connect(ui->deletebtn,   &QPushButton::clicked, this, &admindashboard::handledeleteselected);
    connect(ui->upgradetbtn, &QPushButton::clicked, this, &admindashboard::handleupgradetier);
    connect(depositbtn,      &QPushButton::clicked, this, &admindashboard::handleadmindeposit);
    connect(withdrawbtn,     &QPushButton::clicked, this, &admindashboard::handleadminwithdraw);
    connect(ui->logoutbtn,   &QPushButton::clicked, this, &admindashboard::handlelogout);

    loaddatabase();
}

admindashboard::~admindashboard()
{
    delete ui;
}

void admindashboard::loaddatabase()
{
    ui->maintable->setRowCount(0);


    QSqlQuery q;
    q.exec("SELECT users.id, users.username, users.fullname, users.tier, "
           "accounts.balance, accounts.acctype, accounts.penalized, accounts.id "
           "FROM users "
           "LEFT JOIN accounts ON users.id = accounts.userid "
           "WHERE users.role = 'customer' "
           "ORDER BY users.id ASC");

    int row = 0;
    int customercount = 0;
    double totalcapital = 0.0;

    while (q.next())
    {
        ui->maintable->insertRow(row);


        QTableWidgetItem* iditem = new QTableWidgetItem(q.value(0).toString());
        iditem->setData(Qt::UserRole, q.value(0).toInt());
        iditem->setData(Qt::UserRole + 1, q.value(7).toInt());
        ui->maintable->setItem(row, 0, iditem);

        ui->maintable->setItem(row, 1, new QTableWidgetItem(q.value(1).toString()));
        ui->maintable->setItem(row, 2, new QTableWidgetItem(q.value(2).toString()));
        ui->maintable->setItem(row, 3, new QTableWidgetItem(q.value(3).toString()));

        QString baltext = "no account";
        if (!q.value(4).isNull())
        {
            double bal = q.value(4).toDouble();
            baltext = "Rs " + QString::number(bal, 'f', 2);
            totalcapital += bal;
        }
        ui->maintable->setItem(row, 4, new QTableWidgetItem(baltext));
        ui->maintable->setItem(row, 5, new QTableWidgetItem(q.value(5).toString()));


        QString penstatus = q.value(6).toInt() ? "penalized" : "good";
        ui->maintable->setItem(row, 6, new QTableWidgetItem(penstatus));

        row++;
        customercount++;
    }

    ui->usercountlabel->setText(QString::number(customercount));
    ui->capitallabel->setText("Rs " + QString::number(totalcapital, 'f', 2));
}

void admindashboard::handleadmindeposit()
{
    int selectedrow = ui->maintable->currentRow();
    if (selectedrow < 0)
    {
        QMessageBox::warning(this, "no selection", "please select a customer row first.");
        return;
    }

    QTableWidgetItem* iditem = ui->maintable->item(selectedrow, 0);
    QTableWidgetItem* nameitem = ui->maintable->item(selectedrow, 1);
    QTableWidgetItem* typeitem = ui->maintable->item(selectedrow, 5);
    if (!iditem || !nameitem || !typeitem || iditem->data(Qt::UserRole + 1).toInt() <= 0)
    {
        QMessageBox::warning(this, "no account", "selected customer does not have an active account.");
        return;
    }

    bool inputok = false;
    double amount = QInputDialog::getDouble(this, "admin deposit",
                                            "enter deposit amount for " + nameitem->text() + ":",
                                            0.0, 0.01, 1000000000.0, 2, &inputok);
    if (!inputok)
    {
        return;
    }

    int userid = iditem->data(Qt::UserRole).toInt();
    QString acctype = typeitem->text().toLower();
    std::unique_ptr<account> selected(account::loadfromdb(userid, acctype));
    if (!selected)
    {
        QMessageBox::critical(this, "error", "could not load selected account.");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction())
    {
        QMessageBox::critical(this, "error", "could not start admin deposit safely.");
        return;
    }

    bool ok = selected->deposit(amount);
    if (ok)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO transactions (accid, txntype, amount, balafter, targetacc) VALUES (?, 'deposit', ?, ?, 'admin cash deposit')");
        q.addBindValue(selected->getid());
        q.addBindValue(amount);
        q.addBindValue(selected->getbal());
        ok = q.exec();
    }

    if (ok && selected->canapplymonthlyinterest())
    {
        double interest = selected->calcinterest();
        if (interest > 0.0)
        {
            ok = selected->deposit(interest) && selected->markinterestapplied();
            if (ok)
            {
                QSqlQuery q;
                q.prepare("INSERT INTO transactions (accid, txntype, amount, balafter, targetacc) VALUES (?, 'interest', ?, ?, 'monthly savings interest')");
                q.addBindValue(selected->getid());
                q.addBindValue(interest);
                q.addBindValue(selected->getbal());
                ok = q.exec();
            }
        }
    }

    if (ok && db.commit())
    {
        QMessageBox::information(this, "success", "deposit completed.");
        loaddatabase();
    }
    else
    {
        db.rollback();
        QMessageBox::critical(this, "error", "deposit failed.");
    }
}

void admindashboard::handleadminwithdraw()
{
    int selectedrow = ui->maintable->currentRow();
    if (selectedrow < 0)
    {
        QMessageBox::warning(this, "no selection", "please select a customer row first.");
        return;
    }

    QTableWidgetItem* iditem = ui->maintable->item(selectedrow, 0);
    QTableWidgetItem* nameitem = ui->maintable->item(selectedrow, 1);
    QTableWidgetItem* typeitem = ui->maintable->item(selectedrow, 5);
    if (!iditem || !nameitem || !typeitem || iditem->data(Qt::UserRole + 1).toInt() <= 0)
    {
        QMessageBox::warning(this, "no account", "selected customer does not have an active account.");
        return;
    }

    bool inputok = false;
    double amount = QInputDialog::getDouble(this, "admin withdraw",
                                            "enter withdrawal amount for " + nameitem->text() + ":",
                                            0.0, 0.01, 1000000000.0, 2, &inputok);
    if (!inputok)
    {
        return;
    }

    int userid = iditem->data(Qt::UserRole).toInt();
    QString acctype = typeitem->text().toLower();
    std::unique_ptr<account> selected(account::loadfromdb(userid, acctype));
    if (!selected)
    {
        QMessageBox::critical(this, "error", "could not load selected account.");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction())
    {
        QMessageBox::critical(this, "error", "could not start admin withdrawal safely.");
        return;
    }

    bool ok = selected->withdraw(amount);
    if (ok)
    {
        QSqlQuery q;
        q.prepare("INSERT INTO transactions (accid, txntype, amount, balafter, targetacc) VALUES (?, 'withdrawal', ?, ?, 'admin cash withdrawal')");
        q.addBindValue(selected->getid());
        q.addBindValue(amount);
        q.addBindValue(selected->getbal());
        ok = q.exec();
    }

    if (ok && db.commit())
    {
        QMessageBox::information(this, "success", "withdrawal completed.");
        loaddatabase();
    }
    else
    {
        db.rollback();
        QMessageBox::critical(this, "error", "withdrawal failed. check balance, overdraft, or daily limit.");
    }
}


void admindashboard::handledeleteselected()
{
    int selectedrow = ui->maintable->currentRow();
    if (selectedrow < 0)
    {
        QMessageBox::warning(this, "no selection", "please select a customer row to delete.");
        return;
    }

    QTableWidgetItem* iditem = ui->maintable->item(selectedrow, 0);
    QTableWidgetItem* nameitem = ui->maintable->item(selectedrow, 1);
    if (!iditem || !nameitem)
    {
        return;
    }

    int userid = iditem->data(Qt::UserRole).toInt();
    QString username = nameitem->text();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "confirm delete",
        QString("Are you sure you want to permanently delete customer account:\n\n"
                "Username: %1\n\n"
                "This will remove all their accounts and transaction history.").arg(username),
        QMessageBox::Yes | QMessageBox::No);

    if (reply != QMessageBox::Yes)
    {
        return;
    }

    QSqlQuery q;


    q.prepare("DELETE FROM transactions WHERE accid IN (SELECT id FROM accounts WHERE userid = ?)");
    q.addBindValue(userid);
    if (!q.exec())
    {
        QMessageBox::critical(this, "error", "failed to delete transaction history.");
        return;
    }


    q.prepare("DELETE FROM accounts WHERE userid = ?");
    q.addBindValue(userid);
    if (!q.exec())
    {
        QMessageBox::critical(this, "error", "failed to delete account records.");
        return;
    }


    q.prepare("DELETE FROM users WHERE id = ? AND role = 'customer'");
    q.addBindValue(userid);
    bool ok = q.exec();

    if (ok && q.numRowsAffected() > 0)
    {
        QMessageBox::information(this, "Deleted",
            QString("Customer account '%1' has been permanently deleted.").arg(username));
        loaddatabase();
    }
    else
    {
        QMessageBox::critical(this, "error", "failed to delete the account.");
    }
}


void admindashboard::handleupgradetier()
{
    int selectedrow = ui->maintable->currentRow();
    if (selectedrow < 0)
    {
        QMessageBox::warning(this, "no selection", "please select a customer row to upgrade.");
        return;
    }

    QTableWidgetItem* iditem   = ui->maintable->item(selectedrow, 0);
    QTableWidgetItem* nameitem = ui->maintable->item(selectedrow, 1);
    QTableWidgetItem* tieritem = ui->maintable->item(selectedrow, 3);
    if (!iditem || !nameitem || !tieritem)
    {
        return;
    }

    int userid       = iditem->data(Qt::UserRole).toInt();
    QString username = nameitem->text();
    QString curtier  = tieritem->text().toLower();

    QString newtier;
    if (curtier == "gold")
    {
        newtier = "platinum";
    }
    else if (curtier == "platinum")
    {
        newtier = "diamond";
    }
    else
    {
        QMessageBox::information(this, "max tier",
            QString("customer '%1' is already at diamond tier.").arg(username));
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "confirm upgrade",
        QString("upgrade '%1' from %2 to %3?\n\nnew daily limit: Rs %4")
            .arg(username)
            .arg(curtier)
            .arg(newtier)
            .arg(newtier == "platinum" ? "200,000" : "500,000"),
        QMessageBox::Yes | QMessageBox::No);

    if (reply != QMessageBox::Yes)
    {
        return;
    }

    QSqlQuery q;
    q.prepare("UPDATE users SET tier = ? WHERE id = ? AND role = 'customer'");
    q.addBindValue(newtier);
    q.addBindValue(userid);
    bool ok = q.exec();

    if (ok && q.numRowsAffected() > 0)
    {
        QMessageBox::information(this, "upgraded",
            QString("'%1' has been upgraded to %2 tier.").arg(username).arg(newtier));
        loaddatabase();
    }
    else
    {
        QMessageBox::critical(this, "error", "failed to upgrade tier.");
    }
}

void admindashboard::handlerefresh()
{
    loaddatabase();
}


void admindashboard::handlelogout()
{
    emit loggedout();
}
