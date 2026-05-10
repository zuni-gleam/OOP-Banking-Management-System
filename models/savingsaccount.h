#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "account.h"

class savingsaccount : public account
{
public:
    savingsaccount();
    savingsaccount(int id, int userid, const QString& acctype, double balance,
                   double minbalance, int penalized, double dailyused, const QString& dailydate,
                   const QString& interestmonth, const QString& tier = "gold");

    double calcinterest() override;
    bool applyrules() override;
};

#endif
