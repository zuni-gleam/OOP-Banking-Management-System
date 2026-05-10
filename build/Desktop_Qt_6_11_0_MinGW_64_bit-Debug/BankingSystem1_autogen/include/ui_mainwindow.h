/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titlelabel;
    QLabel *sublabel;
    QHBoxLayout *cardslayout;
    QPushButton *custbtn;
    QPushButton *adminbtn;
    QPushButton *regbtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 550);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #111111; color: white; font-family: 'Segoe UI';"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(50, 50, 50, 50);
        titlelabel = new QLabel(centralwidget);
        titlelabel->setObjectName("titlelabel");
        titlelabel->setStyleSheet(QString::fromUtf8("font-size: 32px; font-weight: bold; color: white; letter-spacing: 2px;\n"
"color: rgb(255, 85 ,0);"));
        titlelabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titlelabel);

        sublabel = new QLabel(centralwidget);
        sublabel->setObjectName("sublabel");
        sublabel->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #FFFFFF; margin-bottom: 20px;"));
        sublabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(sublabel);

        cardslayout = new QHBoxLayout();
        cardslayout->setSpacing(20);
        cardslayout->setObjectName("cardslayout");
        custbtn = new QPushButton(centralwidget);
        custbtn->setObjectName("custbtn");
        custbtn->setMinimumSize(QSize(200, 180));
        custbtn->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; border-radius: 8px; font-size: 18px; font-weight: bold; color: white; padding: 20px;"));

        cardslayout->addWidget(custbtn);

        adminbtn = new QPushButton(centralwidget);
        adminbtn->setObjectName("adminbtn");
        adminbtn->setMinimumSize(QSize(200, 180));
        adminbtn->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; border-radius: 8px; font-size: 18px; font-weight: bold; color: white; padding: 20px;"));

        cardslayout->addWidget(adminbtn);

        regbtn = new QPushButton(centralwidget);
        regbtn->setObjectName("regbtn");
        regbtn->setMinimumSize(QSize(200, 180));
        regbtn->setStyleSheet(QString::fromUtf8("background-color: #FF6B00; border-radius: 8px; font-size: 18px; font-weight: bold; color: black; padding: 20px;"));

        cardslayout->addWidget(regbtn);


        verticalLayout->addLayout(cardslayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BAAZ Limited Banking", nullptr));
        titlelabel->setText(QCoreApplication::translate("MainWindow", "BAAZ Limited", nullptr));
        sublabel->setText(QCoreApplication::translate("MainWindow", "banking so smooth even your budget smiles :)", nullptr));
        custbtn->setText(QCoreApplication::translate("MainWindow", "customer access", nullptr));
        adminbtn->setText(QCoreApplication::translate("MainWindow", "admin access", nullptr));
        regbtn->setText(QCoreApplication::translate("MainWindow", "create account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
