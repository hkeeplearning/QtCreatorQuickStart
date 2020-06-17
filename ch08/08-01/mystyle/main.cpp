#include "mainwindow.h"

#include <QApplication>
#include <QGuiApplication>
#include <QStyleFactory>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qDebug() << QStyleFactory::keys();

    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.show();
    return a.exec();
}
