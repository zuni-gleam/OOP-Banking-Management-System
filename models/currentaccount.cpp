#include "currentaccount.h"
#include <iostream>

using namespace std;

currentaccount::currentaccount() : account()
{
    acctype = "current";
}

currentaccount::currentaccount(int id, int userid, const QString& acctype, double balance,
                               double minbalance, int penalized, double dailyused)
    : account(id, userid, acctype, balance, minbalance, penalized, dailyused)
{
}

double currentaccount::calcinterest()
{
    return 0.0;
}

bool currentaccount::applyrules()
{
    if (balance < minbalance)
    {
        penalized = 1;
        savepenalty();
    }
    return balance > -5000.0;
}