#ifndef REGEXPINTERFACE_H
#define REGEXPINTERFACE_H

#include <QString>

class RegExpInterface
{
public:
    virtual ~RegExpInterface() {}
    virtual QString regexp(const QString &message) = 0;
};

#endif // REGEXPINTERFACE_H
