#include "mylineedit.h"

#include <QEvent>
#include <QDebug>
#include <QKeyEvent>

MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit (parent)
{

}

bool MyLineEdit::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        qDebug() << tr("MyLineEdit event");
    }
    return QLineEdit::event(event);
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("MyLineEdit key press event ") << event->text();
    QLineEdit::keyPressEvent(event);
    event->ignore();
}
