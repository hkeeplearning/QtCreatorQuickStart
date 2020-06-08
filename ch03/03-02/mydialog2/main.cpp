#include "mywidget.h"
#include <QApplication>

// 认识信号和槽
// Qt中使用信号和槽来完成对象之间的协同操作。
// 简单来说，信号和槽都是函数
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();

    return a.exec();
}
