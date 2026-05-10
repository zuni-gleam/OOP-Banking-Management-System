#include "totp.h"
#include <QDateTime>
#include <QMessageAuthenticationCode>
#include <QCryptographicHash>

totp::totp()
{
}




static QByteArray base32decode(const QString& input)
{
    const QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
    QByteArray result;
    int buffer = 0;
    int bitsLeft = 0;

    for (QChar c : input.toUpper())
    {
        if (c == '=') break;
        int val = alphabet.indexOf(c);
        if (val < 0) continue;

        buffer = (buffer << 5) | val;
        bitsLeft += 5;

        if (bitsLeft >= 8)
        {
            bitsLeft -= 8;
            result.append((char)((buffer >> bitsLeft) & 0xFF));
        }
    }
    return result;
}

static QString computecode(const QByteArray& keyBytes, qint64 step)
{
    QByteArray timebytes;
    timebytes.resize(8);
    for (int i = 7; i >= 0; --i)
    {
        timebytes[i] = (char)(step & 0xFF);
        step >>= 8;
    }

    QByteArray hmac = QMessageAuthenticationCode::hash(timebytes, keyBytes, QCryptographicHash::Sha1);

    int offset = hmac[hmac.length() - 1] & 0x0F;
    int code = ((hmac[offset]     & 0x7F) << 24) |
               ((hmac[offset + 1] & 0xFF) << 16) |
               ((hmac[offset + 2] & 0xFF) <<  8) |
                (hmac[offset + 3] & 0xFF);

    code = code % 1000000;
    QString result = QString::number(code);
    while (result.length() < 6) result = "0" + result;
    return result;
}

QString totp::generate(const QString& secret)
{
    QByteArray keyBytes = base32decode(secret);
    qint64 t = QDateTime::currentSecsSinceEpoch() / 30;
    return computecode(keyBytes, t);
}

bool totp::verify(const QString& secret, const QString& inputcode)
{
    QByteArray keyBytes = base32decode(secret);
    qint64 t = QDateTime::currentSecsSinceEpoch() / 30;


    for (int delta = -1; delta <= 1; ++delta)
    {
        if (computecode(keyBytes, t + delta) == inputcode)
        {
            return true;
        }
    }
    return false;
}
