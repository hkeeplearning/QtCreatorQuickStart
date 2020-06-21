#ifndef REGEXPINTERFACE_H
#define REGEXPINTERFACE_H

#include <QObject>
#include <QString>

class RegExpInterface
{
public:
    virtual ~RegExpInterface() {}
    virtual QString regexp(const QString &message) = 0;
};

#define RegExpInterface_DII "123621"

Q_DECLARE_INTERFACE(RegExpInterface, RegExpInterface_DII)

#endif // REGEXPINTERFACE_H
