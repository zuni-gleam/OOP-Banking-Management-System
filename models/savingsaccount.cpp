#include "savingsaccount.h"
#include <iostream>

using namespace std;

savingsaccount::savingsaccount() : account()
{
    acctype = "savings";
}

savingsaccount::savingsaccount(int id, int userid, const QString& acctype, double balance,
                               double minbalance, int penalized, double dailyused)
    : account(id, userid, acctype, balance, minbalance, penalized, dailyused)
{
}

double savingsaccount::calcinterest()
{
    return balance * 0.05 / 12.0;
}

bool savingsaccount::applyrules()
{
    if (balance < minbalance)
    {
        penalized = 1;
        savepenalty();
        return false;
    }
    return true;
}