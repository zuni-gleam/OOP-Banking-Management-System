#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>

namespace Ui {
class registerwindow;
}

class registerwindow : public QWidget
{
    Q_OBJECT

public:
    explicit registerwindow(QWidget *parent = nullptr);
    ~registerwindow();

private slots:
    void handlecreate();
    void handlereturn();

private:
    Ui::registerwindow *ui;
};

#endif