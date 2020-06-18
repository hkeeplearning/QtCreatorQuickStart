#include "widget.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QString str = "Hello";
    QVariant v5 = str;
    qDebug() << v5.canConvert(QVariant::Int);
    qDebug() << v5.convert(QVariant::Int);

    return a.exec();
}
