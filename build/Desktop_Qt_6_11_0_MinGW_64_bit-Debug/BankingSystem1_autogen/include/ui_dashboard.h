/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dashboard
{
public:
    QVBoxLayout *mainVertical;
    QHBoxLayout *headerLayout;
    QLabel *welcomeuserlabel;
    QSpacerItem *headerSpacer;
    QPushButton *logoutbtn;
    QHBoxLayout *bodyLayout;
    QGroupBox *accountBox;
    QVBoxLayout *accountVertical;
    QLabel *accnumlabel;
    QLabel *acctypelabel;
    QLabel *balTitle;
    QLabel *balancelabel;
    QFrame *line1;
    QLabel *profUnameTitle;
    QLabel *usernamelabel;
    QLabel *profNameTitle;
    QLineEdit *namelineedit;
    QLabel *profPhoneTitle;
    QLineEdit *phonelineedit;
    QLabel *profAddrTitle;
    QLineEdit *addrlineedit;
    QPushButton *saveprofilebtn;
    QVBoxLayout *opsAndHistory;
    QHBoxLayout *transactionsLayout;
    QGroupBox *opsBox;
    QVBoxLayout *opsVertical;
    QLabel *depTitle;
    QHBoxLayout *depLayout;
    QLineEdit *depinput;
    QPushButton *depbtn;
    QLabel *withTitle;
    QHBoxLayout *withLayout;
    QLineEdit *withinput;
    QPushButton *withbtn;
    QFrame *line2;
    QLabel *xferTitle;
    QLineEdit *xfertargetinput;
    QLineEdit *xferamtinput;
    QPushButton *xferbtn;
    QGroupBox *historyBox;
    QVBoxLayout *historyVertical;
    QTableWidget *txntable;
    QHBoxLayout *calcLayout;
    QGroupBox *loanBox;
    QVBoxLayout *loanVertical;
    QHBoxLayout *loanRow;
    QLineEdit *loanamtinput;
    QLineEdit *loanrateinput;
    QLineEdit *loanmonthsinput;
    QPushButton *loancalcbtn;
    QLabel *emilabel;
    QGroupBox *currencyBox;
    QVBoxLayout *currVertical;
    QHBoxLayout *currRow;
    QLineEdit *currinput;
    QComboBox *currfrombox;
    QLabel *arrowLabel;
    QComboBox *currtobox;
    QPushButton *currcalcbtn;
    QLabel *currresult;

    void setupUi(QWidget *dashboard)
    {
        if (dashboard->objectName().isEmpty())
            dashboard->setObjectName("dashboard");
        dashboard->resize(1100, 750);
        dashboard->setStyleSheet(QString::fromUtf8("background-color: #111111; color: white; font-family: 'Segoe UI';"));
        mainVertical = new QVBoxLayout(dashboard);
        mainVertical->setSpacing(15);
        mainVertical->setObjectName("mainVertical");
        mainVertical->setContentsMargins(20, 20, 20, 20);
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName("headerLayout");
        welcomeuserlabel = new QLabel(dashboard);
        welcomeuserlabel->setObjectName("welcomeuserlabel");
        welcomeuserlabel->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: white;"));

        headerLayout->addWidget(welcomeuserlabel);

        headerSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerLayout->addItem(headerSpacer);

        logoutbtn = new QPushButton(dashboard);
        logoutbtn->setObjectName("logoutbtn");
        logoutbtn->setStyleSheet(QString::fromUtf8("background-color: transparent; border: 1px solid #FF6B00; color: #FF6B00; font-weight: bold; padding: 6px 15px; border-radius: 4px;"));

        headerLayout->addWidget(logoutbtn);


        mainVertical->addLayout(headerLayout);

        bodyLayout = new QHBoxLayout();
        bodyLayout->setSpacing(15);
        bodyLayout->setObjectName("bodyLayout");
        accountBox = new QGroupBox(dashboard);
        accountBox->setObjectName("accountBox");
        accountBox->setMaximumSize(QSize(320, 16777215));
        accountBox->setStyleSheet(QString::fromUtf8("QGroupBox { font-weight: bold; border: 1px solid #333333; border-radius: 6px; margin-top: 10px; padding: 10px; } QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #FF6B00; }"));
        accountVertical = new QVBoxLayout(accountBox);
        accountVertical->setSpacing(10);
        accountVertical->setObjectName("accountVertical");
        accnumlabel = new QLabel(accountBox);
        accnumlabel->setObjectName("accnumlabel");
        accnumlabel->setStyleSheet(QString::fromUtf8("font-size: 15px; font-weight: bold; color: #888888;"));

        accountVertical->addWidget(accnumlabel);

        acctypelabel = new QLabel(accountBox);
        acctypelabel->setObjectName("acctypelabel");
        acctypelabel->setStyleSheet(QString::fromUtf8("font-size: 13px; color: #888888;"));

        accountVertical->addWidget(acctypelabel);

        balTitle = new QLabel(accountBox);
        balTitle->setObjectName("balTitle");

        accountVertical->addWidget(balTitle);

        balancelabel = new QLabel(accountBox);
        balancelabel->setObjectName("balancelabel");
        balancelabel->setStyleSheet(QString::fromUtf8("font-size: 32px; font-weight: bold; color: #FF6B00;"));

        accountVertical->addWidget(balancelabel);

        line1 = new QFrame(accountBox);
        line1->setObjectName("line1");
        line1->setFrameShape(QFrame::Shape::HLine);
        line1->setFrameShadow(QFrame::Shadow::Sunken);

        accountVertical->addWidget(line1);

        profUnameTitle = new QLabel(accountBox);
        profUnameTitle->setObjectName("profUnameTitle");

        accountVertical->addWidget(profUnameTitle);

        usernamelabel = new QLabel(accountBox);
        usernamelabel->setObjectName("usernamelabel");
        usernamelabel->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        accountVertical->addWidget(usernamelabel);

        profNameTitle = new QLabel(accountBox);
        profNameTitle->setObjectName("profNameTitle");

        accountVertical->addWidget(profNameTitle);

        namelineedit = new QLineEdit(accountBox);
        namelineedit->setObjectName("namelineedit");
        namelineedit->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 5px; color: white; border-radius: 4px;"));

        accountVertical->addWidget(namelineedit);

        profPhoneTitle = new QLabel(accountBox);
        profPhoneTitle->setObjectName("profPhoneTitle");

        accountVertical->addWidget(profPhoneTitle);

        phonelineedit = new QLineEdit(accountBox);
        phonelineedit->setObjectName("phonelineedit");
        phonelineedit->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 5px; color: white; border-radius: 4px;"));

        accountVertical->addWidget(phonelineedit);

        profAddrTitle = new QLabel(accountBox);
        profAddrTitle->setObjectName("profAddrTitle");

        accountVertical->addWidget(profAddrTitle);

        addrlineedit = new QLineEdit(accountBox);
        addrlineedit->setObjectName("addrlineedit");
        addrlineedit->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 5px; color: white; border-radius: 4px;"));

        accountVertical->addWidget(addrlineedit);

        saveprofilebtn = new QPushButton(accountBox);
        saveprofilebtn->setObjectName("saveprofilebtn");
        saveprofilebtn->setStyleSheet(QString::fromUtf8("background-color: #FF6B00; color: black; font-weight: bold; padding: 8px; border-radius: 4px;"));

        accountVertical->addWidget(saveprofilebtn);


        bodyLayout->addWidget(accountBox);

        opsAndHistory = new QVBoxLayout();
        opsAndHistory->setSpacing(15);
        opsAndHistory->setObjectName("opsAndHistory");
        transactionsLayout = new QHBoxLayout();
        transactionsLayout->setSpacing(15);
        transactionsLayout->setObjectName("transactionsLayout");
        opsBox = new QGroupBox(dashboard);
        opsBox->setObjectName("opsBox");
        opsBox->setMinimumSize(QSize(320, 0));
        opsBox->setStyleSheet(QString::fromUtf8("QGroupBox { font-weight: bold; border: 1px solid #333333; border-radius: 6px; margin-top: 10px; padding: 10px; } QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #FF6B00; }"));
        opsVertical = new QVBoxLayout(opsBox);
        opsVertical->setSpacing(8);
        opsVertical->setObjectName("opsVertical");
        depTitle = new QLabel(opsBox);
        depTitle->setObjectName("depTitle");

        opsVertical->addWidget(depTitle);

        depLayout = new QHBoxLayout();
        depLayout->setObjectName("depLayout");
        depinput = new QLineEdit(opsBox);
        depinput->setObjectName("depinput");
        depinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        depLayout->addWidget(depinput);

        depbtn = new QPushButton(opsBox);
        depbtn->setObjectName("depbtn");
        depbtn->setStyleSheet(QString::fromUtf8("background-color: #FF6B00; color: black; font-weight: bold; padding: 6px 15px; border-radius: 4px;"));

        depLayout->addWidget(depbtn);


        opsVertical->addLayout(depLayout);

        withTitle = new QLabel(opsBox);
        withTitle->setObjectName("withTitle");

        opsVertical->addWidget(withTitle);

        withLayout = new QHBoxLayout();
        withLayout->setObjectName("withLayout");
        withinput = new QLineEdit(opsBox);
        withinput->setObjectName("withinput");
        withinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        withLayout->addWidget(withinput);

        withbtn = new QPushButton(opsBox);
        withbtn->setObjectName("withbtn");
        withbtn->setStyleSheet(QString::fromUtf8("background-color: #FF6B00; color: black; font-weight: bold; padding: 6px 15px; border-radius: 4px;"));

        withLayout->addWidget(withbtn);


        opsVertical->addLayout(withLayout);

        line2 = new QFrame(opsBox);
        line2->setObjectName("line2");
        line2->setFrameShape(QFrame::Shape::HLine);
        line2->setFrameShadow(QFrame::Shadow::Sunken);

        opsVertical->addWidget(line2);

        xferTitle = new QLabel(opsBox);
        xferTitle->setObjectName("xferTitle");

        opsVertical->addWidget(xferTitle);

        xfertargetinput = new QLineEdit(opsBox);
        xfertargetinput->setObjectName("xfertargetinput");
        xfertargetinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        opsVertical->addWidget(xfertargetinput);

        xferamtinput = new QLineEdit(opsBox);
        xferamtinput->setObjectName("xferamtinput");
        xferamtinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 6px; color: white; border-radius: 4px;"));

        opsVertical->addWidget(xferamtinput);

        xferbtn = new QPushButton(opsBox);
        xferbtn->setObjectName("xferbtn");
        xferbtn->setStyleSheet(QString::fromUtf8("background-color: #FF6B00; color: black; font-weight: bold; padding: 8px; border-radius: 4px;"));

        opsVertical->addWidget(xferbtn);


        transactionsLayout->addWidget(opsBox);

        historyBox = new QGroupBox(dashboard);
        historyBox->setObjectName("historyBox");
        historyBox->setStyleSheet(QString::fromUtf8("QGroupBox { font-weight: bold; border: 1px solid #333333; border-radius: 6px; margin-top: 10px; padding: 10px; } QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #FF6B00; }"));
        historyVertical = new QVBoxLayout(historyBox);
        historyVertical->setObjectName("historyVertical");
        txntable = new QTableWidget(historyBox);
        if (txntable->columnCount() < 5)
            txntable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        txntable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        txntable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        txntable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        txntable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        txntable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        txntable->setObjectName("txntable");
        txntable->setStyleSheet(QString::fromUtf8("QTableWidget { background-color: #161616; gridline-color: #333333; border: 1px solid #333333; border-radius: 4px; color: white; } QHeaderView::section { background-color: #1A1A1A; color: #FF6B00; font-weight: bold; border: 1px solid #333333; padding: 5px; }"));

        historyVertical->addWidget(txntable);


        transactionsLayout->addWidget(historyBox);


        opsAndHistory->addLayout(transactionsLayout);

        calcLayout = new QHBoxLayout();
        calcLayout->setSpacing(15);
        calcLayout->setObjectName("calcLayout");
        loanBox = new QGroupBox(dashboard);
        loanBox->setObjectName("loanBox");
        loanBox->setStyleSheet(QString::fromUtf8("QGroupBox { font-weight: bold; border: 1px solid #333333; border-radius: 6px; margin-top: 10px; padding: 10px; } QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #FF6B00; }"));
        loanVertical = new QVBoxLayout(loanBox);
        loanVertical->setSpacing(6);
        loanVertical->setObjectName("loanVertical");
        loanRow = new QHBoxLayout();
        loanRow->setObjectName("loanRow");
        loanamtinput = new QLineEdit(loanBox);
        loanamtinput->setObjectName("loanamtinput");
        loanamtinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 5px; color: white; border-radius: 4px;"));

        loanRow->addWidget(loanamtinput);

        loanrateinput = new QLineEdit(loanBox);
        loanrateinput->setObjectName("loanrateinput");
        loanrateinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 5px; color: white; border-radius: 4px;"));

        loanRow->addWidget(loanrateinput);

        loanmonthsinput = new QLineEdit(loanBox);
        loanmonthsinput->setObjectName("loanmonthsinput");
        loanmonthsinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 5px; color: white; border-radius: 4px;"));

        loanRow->addWidget(loanmonthsinput);


        loanVertical->addLayout(loanRow);

        loancalcbtn = new QPushButton(loanBox);
        loancalcbtn->setObjectName("loancalcbtn");
        loancalcbtn->setStyleSheet(QString::fromUtf8("background-color: #FF6B00; color: black; font-weight: bold; padding: 6px; border-radius: 4px;"));

        loanVertical->addWidget(loancalcbtn);

        emilabel = new QLabel(loanBox);
        emilabel->setObjectName("emilabel");
        emilabel->setStyleSheet(QString::fromUtf8("font-weight: bold; color: white; font-size: 13px;"));
        emilabel->setAlignment(Qt::AlignCenter);

        loanVertical->addWidget(emilabel);


        calcLayout->addWidget(loanBox);

        currencyBox = new QGroupBox(dashboard);
        currencyBox->setObjectName("currencyBox");
        currencyBox->setStyleSheet(QString::fromUtf8("QGroupBox { font-weight: bold; border: 1px solid #333333; border-radius: 6px; margin-top: 10px; padding: 10px; } QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #FF6B00; }"));
        currVertical = new QVBoxLayout(currencyBox);
        currVertical->setSpacing(6);
        currVertical->setObjectName("currVertical");
        currRow = new QHBoxLayout();
        currRow->setObjectName("currRow");
        currinput = new QLineEdit(currencyBox);
        currinput->setObjectName("currinput");
        currinput->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 5px; color: white; border-radius: 4px;"));

        currRow->addWidget(currinput);

        currfrombox = new QComboBox(currencyBox);
        currfrombox->addItem(QString());
        currfrombox->addItem(QString());
        currfrombox->addItem(QString());
        currfrombox->setObjectName("currfrombox");
        currfrombox->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 4px; color: white;"));

        currRow->addWidget(currfrombox);

        arrowLabel = new QLabel(currencyBox);
        arrowLabel->setObjectName("arrowLabel");

        currRow->addWidget(arrowLabel);

        currtobox = new QComboBox(currencyBox);
        currtobox->addItem(QString());
        currtobox->addItem(QString());
        currtobox->addItem(QString());
        currtobox->setObjectName("currtobox");
        currtobox->setStyleSheet(QString::fromUtf8("background-color: #1A1A1A; border: 1px solid #333333; padding: 4px; color: white;"));

        currRow->addWidget(currtobox);


        currVertical->addLayout(currRow);

        currcalcbtn = new QPushButton(currencyBox);
        currcalcbtn->setObjectName("currcalcbtn");
        currcalcbtn->setStyleSheet(QString::fromUtf8("background-color: #FF6B00; color: black; font-weight: bold; padding: 6px; border-radius: 4px;"));

        currVertical->addWidget(currcalcbtn);

        currresult = new QLabel(currencyBox);
        currresult->setObjectName("currresult");
        currresult->setStyleSheet(QString::fromUtf8("font-weight: bold; color: white; font-size: 13px;"));
        currresult->setAlignment(Qt::AlignCenter);

        currVertical->addWidget(currresult);


        calcLayout->addWidget(currencyBox);


        opsAndHistory->addLayout(calcLayout);


        bodyLayout->addLayout(opsAndHistory);


        mainVertical->addLayout(bodyLayout);


        retranslateUi(dashboard);

        QMetaObject::connectSlotsByName(dashboard);
    } // setupUi

    void retranslateUi(QWidget *dashboard)
    {
        dashboard->setWindowTitle(QCoreApplication::translate("dashboard", "Apex Trust - Customer Portal", nullptr));
        welcomeuserlabel->setText(QCoreApplication::translate("dashboard", "Welcome back, User!", nullptr));
        logoutbtn->setText(QCoreApplication::translate("dashboard", "LOG OUT", nullptr));
        accountBox->setTitle(QCoreApplication::translate("dashboard", "ACCOUNT INFO & PROFILE", nullptr));
        accnumlabel->setText(QCoreApplication::translate("dashboard", "Acc ID: #1", nullptr));
        acctypelabel->setText(QCoreApplication::translate("dashboard", "Type: SAVINGS (GOLD)", nullptr));
        balTitle->setText(QCoreApplication::translate("dashboard", "AVAILABLE BALANCE", nullptr));
        balancelabel->setText(QCoreApplication::translate("dashboard", "Rs 0.00", nullptr));
        profUnameTitle->setText(QCoreApplication::translate("dashboard", "Username", nullptr));
        usernamelabel->setText(QCoreApplication::translate("dashboard", "username", nullptr));
        profNameTitle->setText(QCoreApplication::translate("dashboard", "Full Name", nullptr));
        profPhoneTitle->setText(QCoreApplication::translate("dashboard", "Phone Number", nullptr));
        profAddrTitle->setText(QCoreApplication::translate("dashboard", "Address", nullptr));
        saveprofilebtn->setText(QCoreApplication::translate("dashboard", "UPDATE PROFILE", nullptr));
        opsBox->setTitle(QCoreApplication::translate("dashboard", "QUICK ACTIONS", nullptr));
        depTitle->setText(QCoreApplication::translate("dashboard", "Deposit Cash", nullptr));
        depinput->setPlaceholderText(QCoreApplication::translate("dashboard", "Amount (Rs)", nullptr));
        depbtn->setText(QCoreApplication::translate("dashboard", "DEPOSIT", nullptr));
        withTitle->setText(QCoreApplication::translate("dashboard", "Withdraw Cash", nullptr));
        withinput->setPlaceholderText(QCoreApplication::translate("dashboard", "Amount (Rs)", nullptr));
        withbtn->setText(QCoreApplication::translate("dashboard", "WITHDRAW", nullptr));
        xferTitle->setText(QCoreApplication::translate("dashboard", "Transfer Funds", nullptr));
        xfertargetinput->setPlaceholderText(QCoreApplication::translate("dashboard", "Recipient Username", nullptr));
        xferamtinput->setPlaceholderText(QCoreApplication::translate("dashboard", "Amount (Rs)", nullptr));
        xferbtn->setText(QCoreApplication::translate("dashboard", "TRIGGER SECURE TRANSFER", nullptr));
        historyBox->setTitle(QCoreApplication::translate("dashboard", "TRANSACTION HISTORY", nullptr));
        QTableWidgetItem *___qtablewidgetitem = txntable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("dashboard", "Timestamp", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = txntable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("dashboard", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = txntable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("dashboard", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = txntable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("dashboard", "Balance After", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = txntable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("dashboard", "Details", nullptr));
        loanBox->setTitle(QCoreApplication::translate("dashboard", "LOAN EMI CALCULATOR", nullptr));
        loanamtinput->setPlaceholderText(QCoreApplication::translate("dashboard", "Amount (Rs)", nullptr));
        loanrateinput->setPlaceholderText(QCoreApplication::translate("dashboard", "Rate (%)", nullptr));
        loanmonthsinput->setPlaceholderText(QCoreApplication::translate("dashboard", "Months", nullptr));
        loancalcbtn->setText(QCoreApplication::translate("dashboard", "CALCULATE EMI", nullptr));
        emilabel->setText(QCoreApplication::translate("dashboard", "Monthly EMI: Rs 0.00", nullptr));
        currencyBox->setTitle(QCoreApplication::translate("dashboard", "CURRENCY EXCHANGER", nullptr));
        currinput->setPlaceholderText(QCoreApplication::translate("dashboard", "Amount", nullptr));
        currfrombox->setItemText(0, QCoreApplication::translate("dashboard", "PKR", nullptr));
        currfrombox->setItemText(1, QCoreApplication::translate("dashboard", "USD", nullptr));
        currfrombox->setItemText(2, QCoreApplication::translate("dashboard", "EUR", nullptr));

        arrowLabel->setText(QCoreApplication::translate("dashboard", "\342\206\222", nullptr));
        currtobox->setItemText(0, QCoreApplication::translate("dashboard", "USD", nullptr));
        currtobox->setItemText(1, QCoreApplication::translate("dashboard", "PKR", nullptr));
        currtobox->setItemText(2, QCoreApplication::translate("dashboard", "EUR", nullptr));

        currcalcbtn->setText(QCoreApplication::translate("dashboard", "CONVERT", nullptr));
        currresult->setText(QCoreApplication::translate("dashboard", "Converted: 0.00 USD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dashboard: public Ui_dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
