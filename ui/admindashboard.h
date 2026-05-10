#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QWidget>

namespace Ui {
class admindashboard;
}

class admindashboard : public QWidget
{
    Q_OBJECT

public:
    explicit admindashboard(QWidget *parent = nullptr);
    ~admindashboard();
    void handlerefresh();

signals:
    void loggedout();

private slots:
    void loaddatabase();
    void handledeleteselected();
    void handleupgradetier();
    void handleadmindeposit();
    void handleadminwithdraw();
    void handlelogout();
    void loaddelrequests();
    void handleapprovedeletion();
    void handledenydeletion();

private:
    Ui::admindashboard *ui;
};

#endif
