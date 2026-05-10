#include "totp.h"
#include <QDateTime>
#include <QMessageAuthenticationCode>
#include <QCryptographicHash>
#include <iostream>

using namespace std;

totp::totp()
{
}

QString totp::generate(const QString& secret)
{
    qint64 t = QDateTime::currentSecsSinceEpoch() / 30;
    QByteArray timebytes;
    timebytes.resize(8);
    for (int i = 7; i >= 0; --i)
    {
        timebytes[i] = (char)(t & 0xFF);
        t >>= 8;
    }

    QByteArray hmac = QMessageAuthenticationCode::hash(timebytes, secret.toUtf8(), QCryptographicHash::Sha1);

    int offset = hmac[hmac.length() - 1] & 0x0F;
    int code = ((hmac[offset] & 0x7F) << 24) |
               ((hmac[offset + 1] & 0xFF) << 16) |
               ((hmac[offset + 2] & 0xFF) << 8) |
               (hmac[offset + 3] & 0xFF);

    code = code % 1000000;
    QString finalcode = QString::number(code);
    while (finalcode.length() < 6)
    {
        finalcode = "0" + finalcode;
    }
    return finalcode;
}

bool totp::verify(const QString& secret, const QString& inputcode)
{
    return generate(secret) == inputcode;
}
