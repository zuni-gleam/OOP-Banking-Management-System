/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titlelabel;
    QLabel *sublabel;
    QLabel *label_1;
    QLineEdit *unameinput;
    QLabel *label_2;
    QLineEdit *passinput;
    QPushButton *loginbtn;
    QPushButton *backbtn;

    void setupUi(QWidget *loginwindow)
    {
        if (loginwindow->objectName().isEmpty())
            loginwindow->setObjectName("loginwindow");
        loginwindow->resize(400, 400);
        loginwindow->setStyleSheet(QString::fromUtf8("background-color: #111111; color: white; font-family: 'Segoe UI';"));
        verticalLayout = new QVBoxLayout(loginwindow);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(40, 40, 40, 40);
        titlelabel = new QLabel(loginwindow);
        titlelabel->setObjectName("titlelabel");
        titlelabel->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: white;"));
        titlelabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titlelabel);

        sublabel = new QLabel(loginwindow);
        sublabel->setObjectName("sublabel");
        sublabel->setStyleSheet(QString::fromUtf8("font-size: 13px; color: #888888; margin-bottom: 10px;"));
        sublabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(sublabel);

        label_1 = new QLabel(loginwindow);
        label_1->setObjectName("label_1");

        verticalLayout->addWidget(label_1);

        unameinput = new QLineEdit(loginwindow);
        unameinput->setObjectName("unameinput");
        unameinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 10px; color: white; border-radius: 4px; font-size: 14px;"));

        verticalLayout->addWidget(unameinput);

        label_2 = new QLabel(loginwindow);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        passinput = new QLineEdit(loginwindow);
        passinput->setObjectName("passinput");
        passinput->setEchoMode(QLineEdit::Password);
        passinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 10px; color: white; border-radius: 4px; font-size: 14px;"));

        verticalLayout->addWidget(passinput);

        loginbtn = new QPushButton(loginwindow);
        loginbtn->setObjectName("loginbtn");
        loginbtn->setStyleSheet(QString::fromUtf8("background-color: #FF6B00; color: black; font-weight: bold; padding: 12px; border-radius: 4px; font-size: 14px; margin-top: 10px;"));

        verticalLayout->addWidget(loginbtn);

        backbtn = new QPushButton(loginwindow);
        backbtn->setObjectName("backbtn");
        backbtn->setStyleSheet(QString::fromUtf8("background-color: transparent; color: white; border: none; font-weight: bold; font-size: 13px;"));

        verticalLayout->addWidget(backbtn);


        retranslateUi(loginwindow);

        QMetaObject::connectSlotsByName(loginwindow);
    } // setupUi

    void retranslateUi(QWidget *loginwindow)
    {
        loginwindow->setWindowTitle(QCoreApplication::translate("loginwindow", "Customer Login", nullptr));
        titlelabel->setText(QCoreApplication::translate("loginwindow", "CUSTOMER LOGIN", nullptr));
        sublabel->setText(QCoreApplication::translate("loginwindow", "Enter institutional login credentials", nullptr));
        label_1->setText(QCoreApplication::translate("loginwindow", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("loginwindow", "Password", nullptr));
        loginbtn->setText(QCoreApplication::translate("loginwindow", "ACCESS PORTAL", nullptr));
        backbtn->setText(QCoreApplication::translate("loginwindow", "Return to Gateway", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginwindow: public Ui_loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
