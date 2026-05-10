#include "savingsaccount.h"

savingsaccount::savingsaccount() : account()
{
    acctype = "savings";
}

savingsaccount::savingsaccount(int id, int userid, const QString& acctype, double balance,
                               double minbalance, int penalized, double dailyused, const QString& dailydate,
                               const QString& interestmonth, const QString& tier)
    : account(id, userid, acctype, balance, minbalance, penalized, dailyused, dailydate, interestmonth, tier)
{}

double savingsaccount::calcinterest()
{
    return balance * 0.05 / 12.0;
}

bool savingsaccount::applyrules()
{




    return true;
}
