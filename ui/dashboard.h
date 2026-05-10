#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include "../models/user.h"
#include "../models/account.h"

namespace Ui {
class dashboard;
}

class dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit dashboard(const user& activeuser, QWidget *parent = nullptr);
    ~dashboard();

signals:
    void loggedout();

private slots:
    void handledeposit();
    void handlewithdraw();
    void handletransfer();
    void handleupdateprofile();
    void handleloancalc();
    void handlecurrencycalc();
    void handlefiltertransactions();
    void handlesearchtransactions();
    void handlecleartxnfilter();
    void handledeleteaccount();
    void handlelogout();

private:
    Ui::dashboard *ui;
    user currentuser;
    account *currentaccount;

    void refreshui();
    void loadtransactions(const QString& typefilter = "", const QString& idfilter = "");
    void addtransaction(const QString& type, double amount, double balafter, const QString& target = "");
    bool checkloanleligibility(double requestedamt, double income);
};

#endif
