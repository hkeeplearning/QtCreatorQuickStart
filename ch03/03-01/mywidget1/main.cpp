#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *widget = new QWidget;
    widget->setWindowTitle(QObject::tr("This is a widget"));

    QLabel *label = new QLabel();
    label->setWindowTitle(QObject::tr("This is a label"));
    label->setText(QObject::tr("Hello world!"));
    label->resize(180, 20);

    QLabel *label1 = new QLabel(widget);
    label1->setText(QObject::tr("Nothing is easy"));
    label1->resize(250, 20);

    label->show();
    widget->show();
    int ret = app.exec();

    delete label;
    delete  widget;

    return ret;
}
