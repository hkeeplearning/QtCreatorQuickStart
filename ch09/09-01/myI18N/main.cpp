#include "mainwindow.h"

#include <QApplication>
#include <QGuiApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("../myI18N/myI18N_zh_CN.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
