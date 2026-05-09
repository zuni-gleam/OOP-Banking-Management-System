#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    regwin = nullptr;
    loginwin = nullptr;

    connect(ui->custbtn, &QPushButton::clicked, this, &MainWindow::handlecustomerclick);
    connect(ui->adminbtn, &QPushButton::clicked, this, &MainWindow::handleadminclick);
    connect(ui->regbtn, &QPushButton::clicked, this, &MainWindow::handleregisterclick);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (regwin)
    {
        delete regwin;
    }
    if (loginwin)
    {
        delete loginwin;
    }
}

void MainWindow::handlecustomerclick()
{
    if (!loginwin)
    {
        loginwin = new loginwindow();
    }
    loginwin->show();
}

void MainWindow::handleadminclick()
{
    QMessageBox::information(this, "Admin Access", "Admin login screen coming soon!");
}

void MainWindow::handleregisterclick()
{
    if (!regwin)
    {
        regwin = new registerwindow();
    }
    regwin->show();
}