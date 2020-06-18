#include "mywidget.h"
#include "ui_mywidget.h"
#include "mylineedit.h"

#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    lineEdit = new MyLineEdit(this);
    lineEdit->move(100, 100);
    lineEdit->installEventFilter(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

bool MyWidget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == lineEdit)
    {
        if(event->type() == QEvent::KeyPress)
        {
            qDebug() << tr("Widget event filter");
        }
    }
    return QWidget::eventFilter(obj, event);
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("MyWidget key press event ") << event->text();
}
