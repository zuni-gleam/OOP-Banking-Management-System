#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QWidget>

namespace Ui {
class admindashboard;
}

class admindashboard : public QWidget
{
    Q_OBJECT

public:
    explicit admindashboard(QWidget *parent = nullptr);
    ~admindashboard();
    void handlerefresh();

private slots:
    void loaddatabase();
    void handlelogout();

private:
    Ui::admindashboard *ui;
};

#endif
