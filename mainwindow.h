#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "ui/registerwindow.h"
#include "ui/loginwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handlecustomerclick();
    void handleadminclick();
    void handleregisterclick();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stack;
    registerwindow *regwin;
    loginwindow *loginwin;
};

#endif
