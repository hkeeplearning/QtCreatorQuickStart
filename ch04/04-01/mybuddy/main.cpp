#include "mywidget.h"

#include <QApplication>
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MyWidget w;
    w.show();
    return a.exec();
}
