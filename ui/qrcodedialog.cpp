#include "qrcodedialog.h"
#include "../qr/qrcodegen.hpp"
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QClipboard>
#include <QFrame>
#include <QPixmap>
#include <QUrl>
#include <string>

static QPixmap makeqrcodepixmap(const QString& text)
{
    std::string value = text.toStdString();
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(value.c_str(), qrcodegen::QrCode::Ecc::MEDIUM);
    int size = qr.getSize();
    int scale = 8;
    int border = 4;
    int imageSize = (size + border * 2) * scale;

    QImage image(imageSize, imageSize, QImage::Format_RGB32);
    image.fill(Qt::white);

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            if (qr.getModule(x, y))
            {
                for (int dy = 0; dy < scale; ++dy)
                {
                    for (int dx = 0; dx < scale; ++dx)
                    {
                        image.setPixel((x + border) * scale + dx,
                                       (y + border) * scale + dy,
                                       qRgb(0, 0, 0));
                    }
                }
            }
        }
    }

    return QPixmap::fromImage(image);
}

QRCodeDialog::QRCodeDialog(const QString& username,
                           const QString& secret,
                           QWidget *parent)
    : QDialog(parent), rawsecret(secret)
{
    setWindowTitle("Set Up Google Authenticator");
    setStyleSheet("background-color: #151515; color: white;");
    setFixedWidth(460);

    rawuri = builduri(username, secret);
    QPixmap qrpix = makeqrcodepixmap(rawuri);
    qrsize = qrpix.width();

    QVBoxLayout *main = new QVBoxLayout(this);
    main->setSpacing(14);
    main->setContentsMargins(24, 24, 24, 24);

    QLabel *title = new QLabel("BAAZ Limited Authenticator Setup");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-weight: bold; font-size: 15px; color: #FF6B00;");
    main->addWidget(title);

    QLabel *instr = new QLabel("Scan this QR code in Google Authenticator");
    instr->setAlignment(Qt::AlignCenter);
    instr->setWordWrap(true);
    instr->setStyleSheet("color: #aaaaaa; font-size: 12px;");
    main->addWidget(instr);

    QFrame *qrframe = new QFrame();
    qrframe->setFixedSize(qrpix.size());
    qrframe->setStyleSheet("background-color: white; border-radius: 0px;");

    QLabel *qrlabel = new QLabel(qrframe);
    qrlabel->setFixedSize(qrpix.size());
    qrlabel->setPixmap(qrpix);

    QHBoxLayout *qrrow = new QHBoxLayout();
    qrrow->addStretch();
    qrrow->addWidget(qrframe);
    qrrow->addStretch();
    main->addLayout(qrrow);

    QLabel *orLabel = new QLabel("or enter manually");
    orLabel->setAlignment(Qt::AlignCenter);
    orLabel->setStyleSheet("color: #777777; font-size: 11px;");
    main->addWidget(orLabel);

    QLabel *secretlabel = new QLabel(secret);
    secretlabel->setAlignment(Qt::AlignCenter);
    secretlabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    secretlabel->setStyleSheet(
        "background-color: #0A0A0A; color: #FF6B00; font-size: 18px; "
        "font-weight: bold; font-family: monospace; padding: 10px; "
        "border: 1px solid #333333; border-radius: 5px; letter-spacing: 3px;");
    main->addWidget(secretlabel);

    QLabel *hint = new QLabel("Use time-based setup if you enter the key manually.");
    hint->setWordWrap(true);
    hint->setAlignment(Qt::AlignCenter);
    hint->setStyleSheet("color: #777777; font-size: 10px;");
    main->addWidget(hint);

    QHBoxLayout *btnrow = new QHBoxLayout();
    QPushButton *copybtn = new QPushButton("Copy Secret");
    copybtn->setStyleSheet(
        "background-color: transparent; border: 1px solid #FF6B00; "
        "color: #FF6B00; padding: 8px 16px; border-radius: 4px; font-weight: bold;");
    QPushButton *donebtn = new QPushButton("Done");
    donebtn->setStyleSheet(
        "background-color: #FF6B00; color: black; padding: 8px 16px; "
        "border-radius: 4px; border: none; font-weight: bold;");
    btnrow->addWidget(copybtn);
    btnrow->addWidget(donebtn);
    main->addLayout(btnrow);

    connect(copybtn, &QPushButton::clicked, this, [=]()
    {
        QApplication::clipboard()->setText(secret);
        copybtn->setText("Copied");
    });
    connect(donebtn, &QPushButton::clicked, this, &QDialog::accept);

    adjustSize();
}

QRCodeDialog::~QRCodeDialog()
{
}

void QRCodeDialog::paintEvent(QPaintEvent *event)
{
    QDialog::paintEvent(event);
}

QString QRCodeDialog::builduri(const QString& username, const QString& secret) const
{
    QString safeUser = username;
    safeUser.replace(" ", "_");
    QString issuer = QString::fromLatin1(QUrl::toPercentEncoding("BAAZ Limited"));
    QString accountName = QString::fromLatin1(QUrl::toPercentEncoding(safeUser));
    return QString("otpauth://totp/%1:%2?secret=%3&issuer=%1")
               .arg(issuer).arg(accountName).arg(secret);
}

QVector<QVector<bool>> QRCodeDialog::generateqr(const QString& text) const
{
    std::string value = text.toStdString();
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(value.c_str(), qrcodegen::QrCode::Ecc::MEDIUM);
    QVector<QVector<bool>> matrix(qr.getSize(), QVector<bool>(qr.getSize(), false));
    for (int y = 0; y < qr.getSize(); ++y)
    {
        for (int x = 0; x < qr.getSize(); ++x)
        {
            matrix[y][x] = qr.getModule(x, y);
        }
    }

    return matrix;
}
