#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *gateway = this->takeCentralWidget();

    stack = new QStackedWidget(this);
    stack->addWidget(gateway);

    regwin = new registerwindow(this);
    stack->addWidget(regwin);

    loginwin = new loginwindow(this);
    stack->addWidget(loginwin);

    adminwin = new adminloginwindow(this);
    stack->addWidget(adminwin);

    setCentralWidget(stack);

    connect(ui->custbtn, &QPushButton::clicked, this, &MainWindow::handlecustomerclick);
    connect(ui->adminbtn, &QPushButton::clicked, this, &MainWindow::handleadminclick);
    connect(ui->regbtn, &QPushButton::clicked, this, &MainWindow::handleregisterclick);

    QPushButton *regback = regwin->findChild<QPushButton*>("backbtn");
    if (regback)
    {
        connect(regback, &QPushButton::clicked, this, [=]()
                {
                    stack->setCurrentIndex(0);
                });
    }

    QPushButton *loginback = loginwin->findChild<QPushButton*>("backbtn");
    if (loginback)
    {
        connect(loginback, &QPushButton::clicked, this, [=]()
                {
                    stack->setCurrentIndex(0);
                });
    }

    QPushButton *adminback = adminwin->findChild<QPushButton*>("backbtn");
    if (adminback)
    {
        connect(adminback, &QPushButton::clicked, this, [=]()
                {
                    stack->setCurrentIndex(0);
                });
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handlecustomerclick()
{
    stack->setCurrentIndex(2);
}

void MainWindow::handleadminclick()
{
    stack->setCurrentIndex(3);
}

void MainWindow::handleregisterclick()
{
    stack->setCurrentIndex(1);
}