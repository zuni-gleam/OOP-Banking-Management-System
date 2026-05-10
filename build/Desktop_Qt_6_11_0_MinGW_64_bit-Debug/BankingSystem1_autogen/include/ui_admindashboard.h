/********************************************************************************
** Form generated from reading UI file 'admindashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDASHBOARD_H
#define UI_ADMINDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admindashboard
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *topHeader;
    QLabel *titlelabel;
    QSpacerItem *hspacer1;
    QPushButton *refreshbtn;
    QPushButton *logoutbtn;
    QHBoxLayout *statsGrid;
    QFrame *frame1;
    QVBoxLayout *v1;
    QLabel *l1;
    QLabel *usercountlabel;
    QFrame *frame2;
    QVBoxLayout *v2;
    QLabel *l2;
    QLabel *capitallabel;
    QGroupBox *gridBox;
    QVBoxLayout *gridV;
    QTableWidget *maintable;

    void setupUi(QWidget *admindashboard)
    {
        if (admindashboard->objectName().isEmpty())
            admindashboard->setObjectName("admindashboard");
        admindashboard->resize(1000, 650);
        admindashboard->setStyleSheet(QString::fromUtf8("background-color: #0D0D0D; color: white; font-family: 'Segoe UI';"));
        mainLayout = new QVBoxLayout(admindashboard);
        mainLayout->setSpacing(20);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(25, 25, 25, 25);
        topHeader = new QHBoxLayout();
        topHeader->setObjectName("topHeader");
        titlelabel = new QLabel(admindashboard);
        titlelabel->setObjectName("titlelabel");
        titlelabel->setStyleSheet(QString::fromUtf8("font-size: 26px; font-weight: bold; color: #FF3333;"));

        topHeader->addWidget(titlelabel);

        hspacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topHeader->addItem(hspacer1);

        refreshbtn = new QPushButton(admindashboard);
        refreshbtn->setObjectName("refreshbtn");
        refreshbtn->setStyleSheet(QString::fromUtf8("background-color: #222222; border: 1px solid #FF3333; color: white; padding: 8px 15px; font-weight: bold; border-radius: 5px;"));

        topHeader->addWidget(refreshbtn);

        logoutbtn = new QPushButton(admindashboard);
        logoutbtn->setObjectName("logoutbtn");
        logoutbtn->setStyleSheet(QString::fromUtf8("background-color: #FF3333; color: black; padding: 8px 15px; font-weight: bold; border-radius: 5px; border: none;"));

        topHeader->addWidget(logoutbtn);


        mainLayout->addLayout(topHeader);

        statsGrid = new QHBoxLayout();
        statsGrid->setSpacing(20);
        statsGrid->setObjectName("statsGrid");
        frame1 = new QFrame(admindashboard);
        frame1->setObjectName("frame1");
        frame1->setStyleSheet(QString::fromUtf8("background-color: #151515; border-radius: 8px; border: 1px solid #333333; padding: 15px;"));
        v1 = new QVBoxLayout(frame1);
        v1->setObjectName("v1");
        l1 = new QLabel(frame1);
        l1->setObjectName("l1");
        l1->setStyleSheet(QString::fromUtf8("font-size: 13px; color: #888888; border: none;"));

        v1->addWidget(l1);

        usercountlabel = new QLabel(frame1);
        usercountlabel->setObjectName("usercountlabel");
        usercountlabel->setStyleSheet(QString::fromUtf8("font-size: 32px; font-weight: bold; color: white; border: none;"));

        v1->addWidget(usercountlabel);


        statsGrid->addWidget(frame1);

        frame2 = new QFrame(admindashboard);
        frame2->setObjectName("frame2");
        frame2->setStyleSheet(QString::fromUtf8("background-color: #151515; border-radius: 8px; border: 1px solid #333333; padding: 15px;"));
        v2 = new QVBoxLayout(frame2);
        v2->setObjectName("v2");
        l2 = new QLabel(frame2);
        l2->setObjectName("l2");
        l2->setStyleSheet(QString::fromUtf8("font-size: 13px; color: #888888; border: none;"));

        v2->addWidget(l2);

        capitallabel = new QLabel(frame2);
        capitallabel->setObjectName("capitallabel");
        capitallabel->setStyleSheet(QString::fromUtf8("font-size: 32px; font-weight: bold; color: #FF3333; border: none;"));

        v2->addWidget(capitallabel);


        statsGrid->addWidget(frame2);


        mainLayout->addLayout(statsGrid);

        gridBox = new QGroupBox(admindashboard);
        gridBox->setObjectName("gridBox");
        gridBox->setStyleSheet(QString::fromUtf8("QGroupBox { font-weight: bold; border: 1px solid #333333; margin-top: 10px; padding-top: 15px; color: #FF3333; } QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; }"));
        gridV = new QVBoxLayout(gridBox);
        gridV->setObjectName("gridV");
        maintable = new QTableWidget(gridBox);
        if (maintable->columnCount() < 6)
            maintable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        maintable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        maintable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        maintable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        maintable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        maintable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        maintable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        maintable->setObjectName("maintable");
        maintable->setStyleSheet(QString::fromUtf8("QTableWidget { background-color: #111111; gridline-color: #222222; color: white; border: 1px solid #333333; } QHeaderView::section { background-color: #222222; color: #FF3333; font-weight: bold; border: 1px solid #333333; padding: 5px; }"));

        gridV->addWidget(maintable);


        mainLayout->addWidget(gridBox);


        retranslateUi(admindashboard);

        QMetaObject::connectSlotsByName(admindashboard);
    } // setupUi

    void retranslateUi(QWidget *admindashboard)
    {
        admindashboard->setWindowTitle(QCoreApplication::translate("admindashboard", "Executive Command Center", nullptr));
        titlelabel->setText(QCoreApplication::translate("admindashboard", "ADMINISTRATIVE OVERVIEW", nullptr));
        refreshbtn->setText(QCoreApplication::translate("admindashboard", "REFRESH FEED", nullptr));
        logoutbtn->setText(QCoreApplication::translate("admindashboard", "SECURE LOGOUT", nullptr));
        l1->setText(QCoreApplication::translate("admindashboard", "TOTAL NETWORK USERS", nullptr));
        usercountlabel->setText(QCoreApplication::translate("admindashboard", "0", nullptr));
        l2->setText(QCoreApplication::translate("admindashboard", "TOTAL SYSTEM CAPITAL", nullptr));
        capitallabel->setText(QCoreApplication::translate("admindashboard", "Rs 0.00", nullptr));
        gridBox->setTitle(QCoreApplication::translate("admindashboard", "GLOBAL DATABASE REGISTRY", nullptr));
        QTableWidgetItem *___qtablewidgetitem = maintable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("admindashboard", "User ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = maintable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("admindashboard", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = maintable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("admindashboard", "Full Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = maintable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("admindashboard", "Role", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = maintable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("admindashboard", "Balance", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = maintable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("admindashboard", "Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admindashboard: public Ui_admindashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDASHBOARD_H
