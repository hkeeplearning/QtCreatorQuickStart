#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QProgressDialog>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    QColorDialog color(this);
    color.setCurrentColor(Qt::red);
    color.setOption(QColorDialog::ShowAlphaChannel);
    color.exec();
    QColor colorValue = color.currentColor();
    qDebug() << "color: " << colorValue;
}

void MyWidget::on_pushButton_2_clicked()
{

}

void MyWidget::on_pushButton_5_clicked()
{
    QFileDialog fileDlg(this);

}

void MyWidget::on_pushButton_7_clicked()
{

}
