#include "hasher.h"
#include <QCryptographicHash>
#include <iostream>

using namespace std;

hasher::hasher()
{
}

QString hasher::hash(const QString& input)
{
    QByteArray bytes = input.toUtf8();
    QByteArray hash = QCryptographicHash::hash(bytes, QCryptographicHash::Sha256);
    return QString(hash.toHex());
}
