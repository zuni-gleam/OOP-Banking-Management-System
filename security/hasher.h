#ifndef HASHER_H
#define HASHER_H

#include <QString>

class hasher
{
public:
    hasher();
    static QString hash(const QString& input);
};

#endif
