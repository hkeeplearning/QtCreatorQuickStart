#include "widget.h"
#include "ui_widget.h"

#include <QKeyEvent>
#include <QWheelEvent>

// 如果要对一个特定的事件进行处理，而且不希望它在后面的传递过程中被处理，
// 那么就返回true，否则，返回false

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->textEdit->installEventFilter(this);
    ui->spinBox->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->textEdit)
    {
        if(event->type() == QEvent::Wheel)
        {
            QWheelEvent *wheelEvent = static_cast<QWheelEvent *>(event);
            if(wheelEvent->delta() > 0)
            {
                ui->textEdit->zoomIn();
            }
            else
            {
                ui->textEdit->zoomOut();
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(obj == ui->spinBox)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if(keyEvent->key() == Qt::Key_Space)
            {
                ui->spinBox->setValue(0);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return QWidget::eventFilter(obj, event);
    }
}
