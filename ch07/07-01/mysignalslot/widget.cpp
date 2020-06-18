#include "widget.h"
#include "ui_widget.h"
#include "mydialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyDialog *dlg = new MyDialog(this);
    connect(dlg, &MyDialog::dlgReturn, this, &Widget::showValue);
    dlg->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showValue(int value, int val1)
{
    ui->label->setText(tr("value: %1, %2").arg(value).arg(val1));
}
