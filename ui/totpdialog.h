#ifndef TOTPDIALOG_H
#define TOTPDIALOG_H

#include <QDialog>

namespace Ui {
class totpdialog;
}

class totpdialog : public QDialog
{
    Q_OBJECT

public:
    explicit totpdialog(const QString& usersecret, QWidget *parent = nullptr);
    ~totpdialog();

private slots:
    void handleverify();
    void handlecancel();

private:
    Ui::totpdialog *ui;
    QString activepass;
};

#endif