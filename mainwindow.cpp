#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , userdash(nullptr)
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

    admindash = new admindashboard(this);
    stack->addWidget(admindash);

    setCentralWidget(stack);

    connect(ui->custbtn, &QPushButton::clicked, this, &MainWindow::handlecustomerclick);
    connect(ui->adminbtn, &QPushButton::clicked, this, &MainWindow::handleadminclick);
    connect(ui->regbtn, &QPushButton::clicked, this, &MainWindow::handleregisterclick);

    connect(adminwin, &adminloginwindow::loginconfirmed, this, [=]() 
    {
        admindash->handlerefresh();
        stack->setCurrentIndex(4);
    });

    QPushButton *adminlogout = admindash->findChild<QPushButton*>("logoutbtn");
    if (adminlogout) 
    {
        connect(adminlogout, &QPushButton::clicked, this, [=]() 
        {
            stack->setCurrentIndex(0);
        });
    }

    QPushButton *regback = regwin->findChild<QPushButton*>("backbtn");
    if (regback)
    {
        admindash->handlerefresh();
        stack->setCurrentIndex(4);
    });


    connect(admindash, &admindashboard::loggedout, this, [=]()
    {
        stack->setCurrentIndex(0);
    });


    connect(regwin, &registerwindow::registrationdone, this, [=]()
    {
        loginwin->clearfields();
        stack->setCurrentIndex(2);
    });


    connect(regwin, &registerwindow::backrequested, this, [=]()
    {
        stack->setCurrentIndex(0);
    });

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
    loginwin->clearfields();
    stack->setCurrentIndex(2);
}

void MainWindow::handleadminclick()
{
    adminwin->clearfields();
    stack->setCurrentIndex(3);
}

void MainWindow::handleregisterclick()
{
    regwin->clearfields();
    stack->setCurrentIndex(1);
}

void MainWindow::openuserdashboard(user loggedinuser)
{

    if (userdash)
    {
        stack->removeWidget(userdash);
        delete userdash;
        userdash = nullptr;
    }

    userdash = new dashboard(loggedinuser, this);


    connect(userdash, &dashboard::loggedout, this, [=]()
    {
        loginwin->clearfields();
        stack->setCurrentIndex(0);
    });

    stack->addWidget(userdash);
    stack->setCurrentWidget(userdash);
}