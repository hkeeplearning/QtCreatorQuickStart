#include "mywidget.h"
#include "ui_mywidget.h"
#include "mydialog.h"

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
    dialog->show();
}

void MyWidget::on_reLoginButton_clicked()
{
    close();
    MyDialog dialog;
    if(dialog.exec() == QDialog::Accepted)
    {
        show();
    }
}

void MyWidget::on_exitButton_clicked()
{
    close();
}
