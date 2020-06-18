#include "mywidget.h"
#include "ui_mywidget.h"
#include "mylineedit.h"

#include <QKeyEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    lineEdit = new MyLineEdit(this);
    lineEdit->move(100, 100);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("MyWidget key press event ") << event->text();
}
