#include "regexpplugin.h"

#include <QRegExp>
#include <QtPlugin>

QString RegExpPlugin::regexp(const QString &message)
{
    QRegExp re("\\d+");
    re.indexIn(message);
    QString str = re.cap(0);
    return str;
}
