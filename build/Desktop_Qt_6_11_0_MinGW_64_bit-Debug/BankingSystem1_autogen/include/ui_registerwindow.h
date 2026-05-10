/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerwindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titlelabel;
    QLabel *label_1;
    QLineEdit *unameinput;
    QLabel *label_2;
    QLineEdit *passinput;
    QLabel *label_3;
    QLineEdit *nameinput;
    QLabel *label_4;
    QLineEdit *phoneinput;
    QLabel *label_5;
    QLineEdit *addrinput;
    QLabel *label_6;
    QComboBox *acctypebox;
    QLabel *label_7;
    QComboBox *sqbox;
    QLabel *label_8;
    QLineEdit *sainput;
    QPushButton *createbtn;
    QPushButton *backbtn;

    void setupUi(QWidget *registerwindow)
    {
        if (registerwindow->objectName().isEmpty())
            registerwindow->setObjectName("registerwindow");
        registerwindow->resize(450, 650);
        registerwindow->setStyleSheet(QString::fromUtf8("background-color: #111111; color: white; font-family: 'Segoe UI';"));
        verticalLayout = new QVBoxLayout(registerwindow);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(40, 40, 40, 40);
        titlelabel = new QLabel(registerwindow);
        titlelabel->setObjectName("titlelabel");
        titlelabel->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: white; margin-bottom: 10px;"));
        titlelabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titlelabel);

        label_1 = new QLabel(registerwindow);
        label_1->setObjectName("label_1");

        verticalLayout->addWidget(label_1);

        unameinput = new QLineEdit(registerwindow);
        unameinput->setObjectName("unameinput");
        unameinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        verticalLayout->addWidget(unameinput);

        label_2 = new QLabel(registerwindow);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        passinput = new QLineEdit(registerwindow);
        passinput->setObjectName("passinput");
        passinput->setEchoMode(QLineEdit::Password);
        passinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        verticalLayout->addWidget(passinput);

        label_3 = new QLabel(registerwindow);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        nameinput = new QLineEdit(registerwindow);
        nameinput->setObjectName("nameinput");
        nameinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        verticalLayout->addWidget(nameinput);

        label_4 = new QLabel(registerwindow);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        phoneinput = new QLineEdit(registerwindow);
        phoneinput->setObjectName("phoneinput");
        phoneinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        verticalLayout->addWidget(phoneinput);

        label_5 = new QLabel(registerwindow);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        addrinput = new QLineEdit(registerwindow);
        addrinput->setObjectName("addrinput");
        addrinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        verticalLayout->addWidget(addrinput);

        label_6 = new QLabel(registerwindow);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        acctypebox = new QComboBox(registerwindow);
        acctypebox->addItem(QString());
        acctypebox->addItem(QString());
        acctypebox->setObjectName("acctypebox");
        acctypebox->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        verticalLayout->addWidget(acctypebox);

        label_7 = new QLabel(registerwindow);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        sqbox = new QComboBox(registerwindow);
        sqbox->addItem(QString());
        sqbox->addItem(QString());
        sqbox->addItem(QString());
        sqbox->setObjectName("sqbox");
        sqbox->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        verticalLayout->addWidget(sqbox);

        label_8 = new QLabel(registerwindow);
        label_8->setObjectName("label_8");

        verticalLayout->addWidget(label_8);

        sainput = new QLineEdit(registerwindow);
        sainput->setObjectName("sainput");
        sainput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        verticalLayout->addWidget(sainput);

        createbtn = new QPushButton(registerwindow);
        createbtn->setObjectName("createbtn");
        createbtn->setStyleSheet(QString::fromUtf8("background-color: #FF6B00; color: black; font-weight: bold; padding: 10px; border-radius: 4px; font-size: 14px; margin-top: 5px;"));

        verticalLayout->addWidget(createbtn);

        backbtn = new QPushButton(registerwindow);
        backbtn->setObjectName("backbtn");
        backbtn->setStyleSheet(QString::fromUtf8("background-color: transparent; color: #FF6B00; border: none; font-weight: bold;"));

        verticalLayout->addWidget(backbtn);


        retranslateUi(registerwindow);

        QMetaObject::connectSlotsByName(registerwindow);
    } // setupUi

    void retranslateUi(QWidget *registerwindow)
    {
        registerwindow->setWindowTitle(QCoreApplication::translate("registerwindow", "Create Account", nullptr));
        titlelabel->setText(QCoreApplication::translate("registerwindow", "CREATE ACCOUNT", nullptr));
        label_1->setText(QCoreApplication::translate("registerwindow", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("registerwindow", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("registerwindow", "Full Name", nullptr));
        label_4->setText(QCoreApplication::translate("registerwindow", "Phone Number", nullptr));
        label_5->setText(QCoreApplication::translate("registerwindow", "Address", nullptr));
        label_6->setText(QCoreApplication::translate("registerwindow", "Account Type", nullptr));
        acctypebox->setItemText(0, QCoreApplication::translate("registerwindow", "Savings Account", nullptr));
        acctypebox->setItemText(1, QCoreApplication::translate("registerwindow", "Current Account", nullptr));

        label_7->setText(QCoreApplication::translate("registerwindow", "Security Question", nullptr));
        sqbox->setItemText(0, QCoreApplication::translate("registerwindow", "What is your mother's maiden name?", nullptr));
        sqbox->setItemText(1, QCoreApplication::translate("registerwindow", "What was the name of your first pet?", nullptr));
        sqbox->setItemText(2, QCoreApplication::translate("registerwindow", "What city were you born in?", nullptr));

        label_8->setText(QCoreApplication::translate("registerwindow", "Security Answer", nullptr));
        createbtn->setText(QCoreApplication::translate("registerwindow", "CREATE ACCOUNT", nullptr));
        backbtn->setText(QCoreApplication::translate("registerwindow", "Return to Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerwindow: public Ui_registerwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
