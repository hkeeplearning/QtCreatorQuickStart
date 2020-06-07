// QtWidgets 包含了众多类的定义，如QApplication，QWidget等
// Qt把没有嵌入到其他部件中的部件成为窗口
// 一般窗口都有边框和标题栏
// 窗口就是没有父部件的部件，又称为顶级部件
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 新建QWidget类对象，默认parent为0，所以他是个窗口
    QWidget *widget = new QWidget;
    // 设置窗口标题
    widget->setWindowTitle(QObject::tr("This is a widget"));
    // 新建QLabel对象，默认parent为0，所以他是一个窗口
    QLabel *label = new QLabel();
    label->setWindowTitle(QObject::tr("This is a label"));
    // 设置要显示的信息
    label->setText(QObject::tr("Hello world!"));
    // 改变部件的大小，以便显示出完整的内容
    label->resize(180, 20);
    // 指定了父窗口为widget，所以他不是一个窗口
    QLabel *label1 = new QLabel(widget);
    label1->setText(QObject::tr("Nothing is easy"));
    label1->resize(250, 20);

    QWidget *widget1 = new QWidget(0, Qt::Dialog);
    QWidget *widget2 = new QWidget(0, Qt::SplashScreen);
//    QLabel *label2 = new QLabel(widget2);
//    label2->setText(QObject::tr("label2"));

    // 在屏幕上显示
    label->show();
    widget->show();

    widget1->show();
    widget2->show();

    int ret = app.exec();

    delete widget2;
    delete widget1;
    delete label;
    delete  widget;

    return ret;
}
