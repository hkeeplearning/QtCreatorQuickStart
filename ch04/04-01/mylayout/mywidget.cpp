#include "mywidget.h"
#include "ui_mywidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

//    QVBoxLayout *layout = new QVBoxLayout;
//    layout->addWidget(ui->fontComboBox);
//    layout->addWidget(ui->textEdit);
//    layout->setSpacing(50);
//    layout->setContentsMargins(0, 0, 50, 100);
//    setLayout(layout);

//    QGridLayout *layout = new QGridLayout;
//    layout->addWidget(ui->fontComboBox, 0, 0, 1, 2);
//    layout->addWidget(ui->pushButton, 0, 2, 1, 1);
//    layout->addWidget(ui->textEdit, 1, 0, 1, 3);
//    setLayout(layout);


}

MyWidget::~MyWidget()
{
    delete ui;
}
