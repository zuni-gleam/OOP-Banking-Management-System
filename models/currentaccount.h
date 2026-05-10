#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "account.h"

class currentaccount : public account
{
public:
    currentaccount();
    currentaccount(int id, int userid, const QString& acctype, double balance,
                   double minbalance, int penalized, double dailyused, const QString& dailydate,
                   const QString& interestmonth, const QString& tier = "gold");

    double calcinterest() override;
    bool applyrules() override;
};

#endif
