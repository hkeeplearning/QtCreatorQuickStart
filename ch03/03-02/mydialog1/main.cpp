#include "mywidget.h"
#include <QApplication>

// QDialog：所有对话框类的基类
// 按照运行对话框时，是否还可以和改程序的其他窗口进行交互，对话框分为模态和非模态两类
// 模态 (modal)
// 非模态 (modeless)
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();

    return a.exec();
}
