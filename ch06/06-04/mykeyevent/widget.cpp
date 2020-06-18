#include "widget.h"
#include "ui_widget.h"

#include <QKeyEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_M)
        {
            if(windowState() != Qt::WindowMaximized)
            {
                setWindowState(Qt::WindowMaximized);
            }
            else
            {
                setWindowState(Qt::WindowNoState);
            }
        }
    }
    else
    {
        QWidget::keyPressEvent(event);
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{

}
