#include "admindashboard.h"
#include "ui_admindashboard.h"
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <iostream>

using namespace std;

admindashboard::admindashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admindashboard)
{
    ui->setupUi(this);

    connect(ui->refreshbtn, &QPushButton::clicked, this, &admindashboard::handlerefresh);
    connect(ui->logoutbtn, &QPushButton::clicked, this, &admindashboard::handlelogout);

    loaddatabase();
}

admindashboard::~admindashboard()
{
    delete ui;
}

void admindashboard::loaddatabase()
{
    ui->maintable->setRowCount(0);

    QSqlQuery q;
    q.exec("SELECT users.id, users.username, users.fullname, users.role, "
           "accounts.balance, accounts.type "
           "FROM users LEFT JOIN accounts ON users.id = accounts.userid");

    int row = 0;
    int usercount = 0;
    double totalcapital = 0.0;

    while (q.next()) 
    {
        ui->maintable->insertRow(row);
        ui->maintable->setItem(row, 0, new QTableWidgetItem(q.value(0).toString()));
        ui->maintable->setItem(row, 1, new QTableWidgetItem(q.value(1).toString()));
        ui->maintable->setItem(row, 2, new QTableWidgetItem(q.value(2).toString()));
        ui->maintable->setItem(row, 3, new QTableWidgetItem(q.value(3).toString().toUpper()));
        
        QString baltext = "N/A";
        if (!q.value(4).isNull()) 
        {
            double bal = q.value(4).toDouble();
            baltext = "Rs " + QString::number(bal, 'f', 2);
            totalcapital += bal;
        }
        
        ui->maintable->setItem(row, 4, new QTableWidgetItem(baltext));
        ui->maintable->setItem(row, 5, new QTableWidgetItem(q.value(5).toString().toUpper()));
        
        row++;
        usercount++;
    }

    ui->usercountlabel->setText(QString::number(usercount));
    ui->capitallabel->setText("Rs " + QString::number(totalcapital, 'f', 2));
}

void admindashboard::handlerefresh()
{
    loaddatabase();
}

void admindashboard::handlelogout()
{
    this->close();
}
