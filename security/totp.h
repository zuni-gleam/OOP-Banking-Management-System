#ifndef TOTP_H
#define TOTP_H

#include <QString>

class totp
{
public:
    totp();
    static QString generate(const QString& secret);
    static bool verify(const QString& secret, const QString& inputcode);
};

#endif
