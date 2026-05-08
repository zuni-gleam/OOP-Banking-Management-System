#include "user.h"
#include "../db/dbmanager.h"
#include <QtSql/QSqlQuery>
#include <iostream>

using namespace std;

user::user()
{
    id = -1;
}

user::user(int id, const QString& uname, const QString& pass, const QString& role,
           const QString& name, const QString& phone, const QString& addr,
           const QString& sq, const QString& sa, const QString& secret, const QString& tier)
{
    this->id = id;
    this->uname = uname;
    this->pass = pass;
    this->role = role;
    this->fullname = name;
    this->phone = phone;
    this->addr = addr;
    this->sq = sq;
    this->sa = sa;
    this->secret = secret;
    this->tier = tier;
}

int user::getid() const
{
    return id;
}

QString user::getuname() const
{
    return uname;
}

QString user::getpass() const
{
    return pass;
}

QString user::getrole() const
{
    return role;
}

QString user::getname() const
{
    return fullname;
}

QString user::getphone() const
{
    return phone;
}

QString user::getaddr() const
{
    return addr;
}

QString user::getsq() const
{
    return sq;
}

QString user::getsa() const
{
    return sa;
}

QString user::getsecret() const
{
    return secret;
}

QString user::gettier() const
{
    return tier;
}

bool user::isvalid() const
{
    return id != -1;
}

void user::setphone(const QString& p)
{
    phone = p;
}

void user::setaddr(const QString& a)
{
    addr = a;
}

void user::setname(const QString& n)
{
    fullname = n;
}

void user::setpass(const QString& p)
{
    pass = p;
}

void user::setsecret(const QString& s)
{
    secret = s;
}

user user::loadfromdb(const QString& uname)
{
    QSqlQuery q;
    q.prepare("SELECT id, username, password, role, fullname, phone, address, "
              "securityq, securitya, totpsecret, tier FROM users WHERE username = ?");
    q.addBindValue(uname);
    q.exec();
    if (q.next())
    {
        return user(q.value(0).toInt(), q.value(1).toString(), q.value(2).toString(),
                    q.value(3).toString(), q.value(4).toString(), q.value(5).toString(),
                    q.value(6).toString(), q.value(7).toString(), q.value(8).toString(),
                    q.value(9).toString(), q.value(10).toString());
    }
    return user();
}

bool user::exists(const QString& uname)
{
    QSqlQuery q;
    q.prepare("SELECT id FROM users WHERE username = ?");
    q.addBindValue(uname);
    q.exec();
    return q.next();
}

bool user::savetodb() const
{
    QSqlQuery q;
    q.prepare("INSERT INTO users (username, password, role, fullname, phone, address, "
              "securityq, securitya, totpsecret, tier) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    q.addBindValue(uname);
    q.addBindValue(pass);
    q.addBindValue(role);
    q.addBindValue(fullname);
    q.addBindValue(phone);
    q.addBindValue(addr);
    q.addBindValue(sq);
    q.addBindValue(sa);
    q.addBindValue(secret);
    q.addBindValue(tier);
    return q.exec();
}

bool user::updateprofile() const
{
    QSqlQuery q;
    q.prepare("UPDATE users SET fullname = ?, phone = ?, address = ? WHERE id = ?");
    q.addBindValue(fullname);
    q.addBindValue(phone);
    q.addBindValue(addr);
    q.addBindValue(id);
    return q.exec();
}

bool user::updatepass() const
{
    QSqlQuery q;
    q.prepare("UPDATE users SET password = ? WHERE id = ?");
    q.addBindValue(pass);
    q.addBindValue(id);
    return q.exec();
}