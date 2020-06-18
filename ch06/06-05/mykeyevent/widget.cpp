#include "widget.h"
#include "ui_widget.h"

#include <QKeyEvent>
#include <QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFocus();
    keyUp = false;
    keyLeft = false;
    move = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        qDebug() << "press: " << event->isAutoRepeat();
        if(event->isAutoRepeat())
        {
            return;
        }
    }
    else if(event->key() == Qt::Key_Left)
    {
        if(event->isAutoRepeat())
        {
            return;
        }
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        qDebug() << "release: " << event->isAutoRepeat();
        if(event->isAutoRepeat())
        {
            return;
        }
        keyUp = false;
        if(move)
        {
            move = false;
            return;
        }
        if(keyLeft)
        {
            ui->pushButton->move(30, 80);
        }
        else
        {
            ui->pushButton->move(120, 80);
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(event->isAutoRepeat())
        {
            return;
        }
        keyLeft = false;
        if(move)
        {
            move = false;
            return;
        }
        if(keyUp)
        {
            ui->pushButton->move(30, 80);
        }
        else
        {
            ui->pushButton->move(30, 80);
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        ui->pushButton->move(120, 120);
    }
}
