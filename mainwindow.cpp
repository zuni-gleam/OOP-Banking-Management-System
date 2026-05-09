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
}

void MainWindow::handlecustomerclick()
{
    QMessageBox::information(this, "Customer Access");
}

void MainWindow::handleadminclick()
{
    QMessageBox::information(this, "Admin Access");
}

void MainWindow::handleregisterclick()
{
    if (!regwin)
    {
        regwin = new registerwindow();
    }
    regwin->show();
}