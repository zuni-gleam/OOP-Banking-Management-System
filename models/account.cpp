#include "account.h"
#include "savingsaccount.h"
#include "currentaccount.h"
#include "../db/dbmanager.h"
#include <QtSql/QSqlQuery>
#include <iostream>

using namespace std;

account::account()
{
    id = -1;
    userid = -1;
    balance = 0.0;
    minbalance = 10000.0;
    penalized = 0;
    dailyused = 0.0;
}

account::account(int id, int userid, const QString& acctype, double balance,
                 double minbalance, int penalized, double dailyused)
{
    this->id = id;
    this->userid = userid;
    this->acctype = acctype;
    this->balance = balance;
    this->minbalance = minbalance;
    this->penalized = penalized;
    this->dailyused = dailyused;
}

int account::getid() const
{
    return id;
}

int account::getuserid() const
{
    return userid;
}

QString account::gettype() const
{
    return acctype;
}

double account::getbal() const
{
    return balance;
}

double account::getminbal() const
{
    return minbalance;
}

int account::ispenalized() const
{
    return penalized;
}

double account::getdailyused() const
{
    return dailyused;
}

bool account::deposit(double amt)
{
    if (amt <= 0)
    {
        return false;
    }
    balance = balance + amt;
    return savebalance();
}

bool account::withdraw(double amt)
{
    if (amt <= 0)
    {
        return false;
    }
    if (!applyrules())
    {
        return false;
    }
    if (balance - amt < -5000)
    {
        return false;
    }
    balance = balance - amt;
    dailyused = dailyused + amt;
    savebalance();
    savedailyused();
    return true;
}

void account::applypenalty()
{
    balance = balance - 500.0;
    penalized = 1;
    savebalance();
    savepenalty();
}

void account::resetdaily()
{
    dailyused = 0.0;
    savedailyused();
}

account* account::loadfromdb(int userid, const QString& acctype)
{
    QSqlQuery q;
    q.prepare("SELECT id, userid, acctype, balance, minbalance, penalized, dailyused "
              "FROM accounts WHERE userid = ? AND acctype = ?");
    q.addBindValue(userid);
    q.addBindValue(acctype);
    q.exec();
    if (q.next())
    {
        int aid = q.value(0).toInt();
        int uid = q.value(1).toInt();
        QString type = q.value(2).toString();
        double bal = q.value(3).toDouble();
        double minbal = q.value(4).toDouble();
        int pen = q.value(5).toInt();
        double daily = q.value(6).toDouble();

        if (type == "savings")
        {
            return new savingsaccount(aid, uid, type, bal, minbal, pen, daily);
        }
        if (type == "current")
        {
            return new currentaccount(aid, uid, type, bal, minbal, pen, daily);
        }
    }
    return nullptr;
}

bool account::createindb(int userid, const QString& acctype)
{
    QSqlQuery q;
    q.prepare("INSERT INTO accounts (userid, acctype, balance, minbalance, penalized, dailyused) "
              "VALUES (?, ?, 0.0, 10000.0, 0, 0.0)");
    q.addBindValue(userid);
    q.addBindValue(acctype);
    return q.exec();
}

bool account::savebalance() const
{
    QSqlQuery q;
    q.prepare("UPDATE accounts SET balance = ? WHERE id = ?");
    q.addBindValue(balance);
    q.addBindValue(id);
    return q.exec();
}

bool account::savepenalty() const
{
    QSqlQuery q;
    q.prepare("UPDATE accounts SET penalized = ? WHERE id = ?");
    q.addBindValue(penalized);
    q.addBindValue(id);
    return q.exec();
}

bool account::savedailyused() const
{
    QSqlQuery q;
    q.prepare("UPDATE accounts SET dailyused = ? WHERE id = ?");
    q.addBindValue(dailyused);
    q.addBindValue(id);
    return q.exec();
}