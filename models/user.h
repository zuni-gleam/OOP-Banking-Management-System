#ifndef USER_H
#define USER_H

#include <QString>

class user
{
public:
    user();
    user(int id, const QString& uname, const QString& pass, const QString& role,
         const QString& name, const QString& phone, const QString& addr,
         const QString& sq, const QString& sa, const QString& secret, const QString& tier);

    int getid() const;
    QString getuname() const;
    QString getpass() const;
    QString getrole() const;
    QString getname() const;
    QString getphone() const;
    QString getaddr() const;
    QString getsq() const;
    QString getsa() const;
    QString getsecret() const;
    QString gettier() const;
    bool isvalid() const;

    void setphone(const QString& p);
    void setaddr(const QString& a);
    void setname(const QString& n);
    void setpass(const QString& p);
    void setsecret(const QString& s);
    void settier(const QString& t);

    static user loadfromdb(const QString& uname);
    static user loadfromid(int uid);
    static bool exists(const QString& uname);
    bool savetodb() const;
    bool updateprofile() const;
    bool updatepass() const;
    bool deleteaccount() const;

private:
    int id;
    QString uname;
    QString pass;
    QString role;
    QString fullname;
    QString phone;
    QString addr;
    QString sq;
    QString sa;
    QString secret;
    QString tier;
};

#endif
