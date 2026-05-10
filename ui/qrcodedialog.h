#ifndef QRCODEDIALOG_H
#define QRCODEDIALOG_H

#include <QDialog>
#include <QString>





class QRCodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QRCodeDialog(const QString& username,
                          const QString& secret,
                          QWidget *parent = nullptr);
    ~QRCodeDialog();

private:

    QString builduri(const QString& username, const QString& secret) const;



    QVector<QVector<bool>> generateqr(const QString& text) const;


    void paintEvent(QPaintEvent *event) override;

    QVector<QVector<bool>> qrmatrix;
    QString rawsecret;
    QString rawuri;
    int     qrsize;
};

#endif
