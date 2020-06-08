#include "mywidget.h"
#include "ui_mywidget.h"

#include <QDialog>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    connect(ui->showChildButton, &QPushButton::clicked, this, &MyWidget::ShowChildDialog);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::ShowChildDialog()
{
    QDialog *dialog = new QDialog(this);
    dialog->setModal(true);
    dialog->show();
}
