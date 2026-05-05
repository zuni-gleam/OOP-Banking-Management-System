#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui/loginwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startbutton_clicked()
{
    loginwindow *login = new loginwindow();
    login->show();
    this->close();
}