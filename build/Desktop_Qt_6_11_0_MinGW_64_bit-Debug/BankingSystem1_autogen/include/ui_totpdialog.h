/********************************************************************************
** Form generated from reading UI file 'totpdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTPDIALOG_H
#define UI_TOTPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_totpdialog
{
public:
    QVBoxLayout *mainBox;
    QLabel *titlelabel;
    QLabel *infolabel;
    QLineEdit *pininput;
    QHBoxLayout *btnRow;
    QPushButton *cancelbtn;
    QPushButton *verifybtn;

    void setupUi(QDialog *totpdialog)
    {
        if (totpdialog->objectName().isEmpty())
            totpdialog->setObjectName("totpdialog");
        totpdialog->resize(915, 429);
        totpdialog->setStyleSheet(QString::fromUtf8("background-color: #151515; color: white; border: 2px solid #FF6B00; border-radius: 10px;"));
        mainBox = new QVBoxLayout(totpdialog);
        mainBox->setSpacing(15);
        mainBox->setObjectName("mainBox");
        mainBox->setContentsMargins(25, 25, 25, 25);
        titlelabel = new QLabel(totpdialog);
        titlelabel->setObjectName("titlelabel");
        titlelabel->setStyleSheet(QString::fromUtf8("font-weight: bold; color: #FF6B00; font-size: 16px; border: none;"));
        titlelabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainBox->addWidget(titlelabel);

        infolabel = new QLabel(totpdialog);
        infolabel->setObjectName("infolabel");
        infolabel->setStyleSheet(QString::fromUtf8("color: #aaaaaa; font-size: 12px; border: none;"));
        infolabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        infolabel->setWordWrap(true);

        mainBox->addWidget(infolabel);

        pininput = new QLineEdit(totpdialog);
        pininput->setObjectName("pininput");
        pininput->setStyleSheet(QString::fromUtf8("background-color: #0A0A0A; color: #FF6B00; font-size: 24px; font-weight: bold; border: 1px solid #333333; padding: 10px; border-radius: 5px;"));
        pininput->setMaxLength(6);
        pininput->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainBox->addWidget(pininput);

        btnRow = new QHBoxLayout();
        btnRow->setSpacing(10);
        btnRow->setObjectName("btnRow");
        cancelbtn = new QPushButton(totpdialog);
        cancelbtn->setObjectName("cancelbtn");
        cancelbtn->setStyleSheet(QString::fromUtf8("background-color: transparent; border: 1px solid #555555; color: white; padding: 8px; border-radius: 4px;"));

        btnRow->addWidget(cancelbtn);

        verifybtn = new QPushButton(totpdialog);
        verifybtn->setObjectName("verifybtn");
        verifybtn->setStyleSheet(QString::fromUtf8("background-color: #FF6B00; color: black; font-weight: bold; padding: 8px; border-radius: 4px; border: none;"));

        btnRow->addWidget(verifybtn);


        mainBox->addLayout(btnRow);


        retranslateUi(totpdialog);

        QMetaObject::connectSlotsByName(totpdialog);
    } // setupUi

    void retranslateUi(QDialog *totpdialog)
    {
        totpdialog->setWindowTitle(QCoreApplication::translate("totpdialog", "Security Check", nullptr));
        titlelabel->setText(QCoreApplication::translate("totpdialog", "2FA VERIFICATION", nullptr));
        infolabel->setText(QCoreApplication::translate("totpdialog", "Enter the dynamic 6-digit authorization code from your device to confirm.", nullptr));
        pininput->setPlaceholderText(QCoreApplication::translate("totpdialog", "******", nullptr));
        cancelbtn->setText(QCoreApplication::translate("totpdialog", "Abort", nullptr));
        verifybtn->setText(QCoreApplication::translate("totpdialog", "AUTHORIZE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class totpdialog: public Ui_totpdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTPDIALOG_H
