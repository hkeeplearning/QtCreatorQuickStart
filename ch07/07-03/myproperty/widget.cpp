#include "widget.h"
#include "ui_widget.h"
#include "myclass.h"

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyClass *cls = new MyClass(this);
    connect(cls, &MyClass::userNameChanged, this, &Widget::userChanged);
    cls->setUserName("zhangsan");
    qDebug() << "use name: " << cls->getUserName();
    cls->setProperty("userName", "linux");
    qDebug() << "use name: " << cls->property("userName").toString();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::userChanged(QString userName)
{
    qDebug() << "use name changed: " << userName;
}
