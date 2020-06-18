#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setColor(QColor(100, 100, 100, 100));
    effect->setBlurRadius(2);
    effect->setOffset(10);
    ui->label->setGraphicsEffect(effect);

//    setWindowOpacity(0.8);
//    setWindowFlag(Qt::FramelessWindowHint);
//    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(), QColor(255, 255, 255, 10));
}

