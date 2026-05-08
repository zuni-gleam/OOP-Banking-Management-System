#include "mainwindow.h"
#include <QApplication>
#include <QDir>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir().mkdir("data");

    MainWindow w;
    w.show();

    return a.exec();
}