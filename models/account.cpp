#include "account.h"
#include "savingsaccount.h"
#include "currentaccount.h"
#include "../db/dbmanager.h"
#include <QtSql/QSqlQuery>
#include <QDate>

account::account()
{
    id = -1;
    userid = -1;
    balance = 0.0;
    minbalance = 10000.0;
    penalized = 0;
    dailyused = 0.0;
    dailydate = QDate::currentDate().toString(Qt::ISODate);
    interestmonth = "";
    tier = "gold";
}

account::account(int id, int userid, const QString& acctype, double balance,
                 double minbalance, int penalized, double dailyused, const QString& dailydate,
                 const QString& interestmonth, const QString& tier)
{
    this->id = id;
    this->userid = userid;
    this->acctype = acctype;
    this->balance = balance;
    this->minbalance = minbalance;
    this->penalized = penalized;
    this->dailyused = dailyused;
    this->dailydate = dailydate;
    this->interestmonth = interestmonth;
    this->tier = tier;
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

double account::getdailylimit() const
{

    if (tier == "diamond")
    {
        return 500000.0;
    }

    if (tier == "platinum")
    {
        return 200000.0;
    }

    return 50000.0;
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

    syncdailyusage();

    double limit = getdailylimit();
    if (dailyused + amt > limit)
    {
        return false;
    }


    double projected = balance - amt;
    if (acctype == "savings" && projected < 0.0)
    {
        return false;
    }

    if (acctype == "current" && projected < -5000.0)
    {
        return false;
    }

    balance = projected;
    if (!applyrules())
    {
        return false;
    }

    dailyused = dailyused + amt;
    savebalance();
    savedailyused();


    checkandapplypenalty();
    return true;
}

void account::applypenalty()
{


    if (balance >= 500.0)
        balance = balance - 500.0;
    else
        balance = 0.0;
    penalized = 1;
    savebalance();
    savepenalty();
}


void account::checkandapplypenalty()
{
    if (balance < minbalance && penalized == 0)
    {
        applypenalty();
    }
}

void account::resetdaily()
{
    dailyused = 0.0;
    dailydate = QDate::currentDate().toString(Qt::ISODate);
    savedailyused();
}

void account::syncdailyusage()
{
    QString today = QDate::currentDate().toString(Qt::ISODate);
    if (dailydate != today)
    {
        dailyused = 0.0;
        dailydate = today;
        savedailyused();
    }
}

bool account::canapplymonthlyinterest() const
{
    if (acctype != "savings")
    {
        return false;
    }

    return interestmonth != QDate::currentDate().toString("yyyy-MM");
}

bool account::markinterestapplied()
{
    interestmonth = QDate::currentDate().toString("yyyy-MM");
    return saveinterestmonth();
}

account* account::loadfromdb(int userid, const QString& acctype)
{
    QSqlQuery q;
    q.prepare("SELECT a.id, a.userid, a.acctype, a.balance, a.minbalance, a.penalized, "
              "a.dailyused, a.dailydate, a.interestmonth, u.tier "
              "FROM accounts a JOIN users u ON a.userid = u.id "
              "WHERE a.userid = ? AND a.acctype = ?");
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
        QString date = q.value(7).toString();
        QString month = q.value(8).toString();
        QString t = q.value(9).toString();

        account *loaded = nullptr;
        if (type == "savings")
        {
            loaded = new savingsaccount(aid, uid, type, bal, minbal, pen, daily, date, month, t);
        }

        if (type == "current")
        {
            loaded = new currentaccount(aid, uid, type, bal, minbal, pen, daily, date, month, t);
        }

        if (loaded)
        {
            loaded->syncdailyusage();
        }

        return loaded;
    }
    return nullptr;
}

bool account::createindb(int userid, const QString& acctype)
{
    QSqlQuery q;
    q.prepare("INSERT INTO accounts (userid, acctype, balance, minbalance, penalized, dailyused, dailydate, interestmonth) "
              "VALUES (?, ?, 0.0, 10000.0, 0, 0.0, ?, '')");
    q.addBindValue(userid);
    q.addBindValue(acctype);
    q.addBindValue(QDate::currentDate().toString(Qt::ISODate));
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
    q.prepare("UPDATE accounts SET dailyused = ?, dailydate = ? WHERE id = ?");
    q.addBindValue(dailyused);
    q.addBindValue(dailydate);
    q.addBindValue(id);
    return q.exec();
}

bool account::saveinterestmonth() const
{
    QSqlQuery q;
    q.prepare("UPDATE accounts SET interestmonth = ? WHERE id = ?");
    q.addBindValue(interestmonth);
    q.addBindValue(id);
    return q.exec();
}
