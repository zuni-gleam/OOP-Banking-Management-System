#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class account
{
public:
    account();
    account(int id, int userid, const QString& acctype, double balance,
            double minbalance, int penalized, double dailyused);

    int getid() const;
    int getuserid() const;
    QString gettype() const;
    double getbal() const;
    double getminbal() const;
    int ispenalized() const;
    double getdailyused() const;

    bool deposit(double amt);
    bool withdraw(double amt);
    void applypenalty();
    void resetdaily();

    virtual double calcinterest() = 0;
    virtual bool applyrules() = 0;
    virtual ~account() = default;

    static account* loadfromdb(int userid, const QString& acctype);
    static bool createindb(int userid, const QString& acctype);
    bool savebalance() const;
    bool savepenalty() const;
    bool savedailyused() const;

protected:
    int id;
    int userid;
    QString acctype;
    double balance;
    double minbalance;
    int penalized;
    double dailyused;
};

#endif