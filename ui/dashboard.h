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

private slots:
    void handledeposit();
    void handlewithdraw();
    void handletransfer();
    void handleupdateprofile();
    void handleloancalc();
    void handlecurrencycalc();
    void handlelogout();

private:
    Ui::dashboard *ui;
    user currentuser;
    account *currentaccount;

    void refreshui();
    void loadtransactions();
    void addtransaction(const QString& type, double amount, double balafter, const QString& target = "");
};

#endif
