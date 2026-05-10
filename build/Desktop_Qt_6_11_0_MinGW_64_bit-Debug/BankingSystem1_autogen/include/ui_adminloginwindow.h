/********************************************************************************
** Form generated from reading UI file 'adminloginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGINWINDOW_H
#define UI_ADMINLOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminloginwindow
{
public:
    QVBoxLayout *mainVertical;
    QLabel *headerlabel;
    QLabel *sublabel;
    QLabel *label_1;
    QLineEdit *unameinput;
    QLabel *label_2;
    QLineEdit *passinput;
    QPushButton *loginbtn;
    QPushButton *backbtn;

    void setupUi(QWidget *adminloginwindow)
    {
        if (adminloginwindow->objectName().isEmpty())
            adminloginwindow->setObjectName("adminloginwindow");
        adminloginwindow->resize(400, 400);
        adminloginwindow->setStyleSheet(QString::fromUtf8("background-color: #0D0D0D; color: white; font-family: 'Segoe UI';"));
        mainVertical = new QVBoxLayout(adminloginwindow);
        mainVertical->setSpacing(15);
        mainVertical->setObjectName("mainVertical");
        mainVertical->setContentsMargins(40, 50, 40, 50);
        headerlabel = new QLabel(adminloginwindow);
        headerlabel->setObjectName("headerlabel");
        headerlabel->setStyleSheet(QString::fromUtf8("color: #FF3B3B; font-size: 22px; font-weight: bold;"));
        headerlabel->setAlignment(Qt::AlignCenter);

        mainVertical->addWidget(headerlabel);

        sublabel = new QLabel(adminloginwindow);
        sublabel->setObjectName("sublabel");
        sublabel->setStyleSheet(QString::fromUtf8("color: #666666; font-size: 12px; margin-bottom: 10px;"));
        sublabel->setAlignment(Qt::AlignCenter);

        mainVertical->addWidget(sublabel);

        label_1 = new QLabel(adminloginwindow);
        label_1->setObjectName("label_1");

        mainVertical->addWidget(label_1);

        unameinput = new QLineEdit(adminloginwindow);
        unameinput->setObjectName("unameinput");
        unameinput->setStyleSheet(QString::fromUtf8("background-color: #151515; border: 1px solid #331111; padding: 10px; color: white; border-radius: 4px;"));

        mainVertical->addWidget(unameinput);

        label_2 = new QLabel(adminloginwindow);
        label_2->setObjectName("label_2");

        mainVertical->addWidget(label_2);

        passinput = new QLineEdit(adminloginwindow);
        passinput->setObjectName("passinput");
        passinput->setEchoMode(QLineEdit::Password);
        passinput->setStyleSheet(QString::fromUtf8("background-color: #151515; border: 1px solid #331111; padding: 10px; color: white; border-radius: 4px;"));

        mainVertical->addWidget(passinput);

        loginbtn = new QPushButton(adminloginwindow);
        loginbtn->setObjectName("loginbtn");
        loginbtn->setStyleSheet(QString::fromUtf8("background-color: #FF3B3B; color: white; font-weight: bold; padding: 12px; border-radius: 4px; font-size: 13px; margin-top: 15px;"));

        mainVertical->addWidget(loginbtn);

        backbtn = new QPushButton(adminloginwindow);
        backbtn->setObjectName("backbtn");
        backbtn->setStyleSheet(QString::fromUtf8("background-color: transparent; color: #888888; border: none; font-weight: bold; margin-top: 5px;"));

        mainVertical->addWidget(backbtn);


        retranslateUi(adminloginwindow);

        QMetaObject::connectSlotsByName(adminloginwindow);
    } // setupUi

    void retranslateUi(QWidget *adminloginwindow)
    {
        adminloginwindow->setWindowTitle(QCoreApplication::translate("adminloginwindow", "Bank Administration Access", nullptr));
        headerlabel->setText(QCoreApplication::translate("adminloginwindow", "SECURE ADMINISTRATION", nullptr));
        sublabel->setText(QCoreApplication::translate("adminloginwindow", "Authorized system users only. Operations logged.", nullptr));
        label_1->setText(QCoreApplication::translate("adminloginwindow", "Admin Username", nullptr));
        label_2->setText(QCoreApplication::translate("adminloginwindow", "Administrative Password", nullptr));
        loginbtn->setText(QCoreApplication::translate("adminloginwindow", "VALIDATE ACCESS", nullptr));
        backbtn->setText(QCoreApplication::translate("adminloginwindow", "Return to Station", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminloginwindow: public Ui_adminloginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGINWINDOW_H
