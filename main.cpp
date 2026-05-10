#include "mainwindow.h"
#include "db/dbmanager.h"
#include <QApplication>
#include <QDir>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir().mkdir("data");

    dbmanager::get().open("data/bank.db");
    dbmanager::get().createtables();
    dbmanager::get().seedadmin();

    MainWindow w;
    w.show();

    return a.exec();
}