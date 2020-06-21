#ifndef REGEXPPLUGIN_H
#define REGEXPPLUGIN_H

#include <QObject>
#include "regexpinterface.h"

class RegExpPlugin : public QObject,
        public RegExpInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID RegExpInterface_DII FILE "MyPlugin.json")
    Q_INTERFACES(RegExpInterface)

private:
    QString regexp(const QString &message);
};

#endif // REGEXPPLUGIN_H
