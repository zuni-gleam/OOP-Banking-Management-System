#include "currentaccount.h"

currentaccount::currentaccount() : account()
{
    acctype = "current";
}

currentaccount::currentaccount(int id, int userid, const QString& acctype, double balance,
                               double minbalance, int penalized, double dailyused, const QString& dailydate,
                               const QString& interestmonth, const QString& tier)
    : account(id, userid, acctype, balance, minbalance, penalized, dailyused, dailydate, interestmonth, tier)
{}

double currentaccount::calcinterest()
{
    return 0.0;
}

bool currentaccount::applyrules()
{

    return balance >= -5000.0;
}
