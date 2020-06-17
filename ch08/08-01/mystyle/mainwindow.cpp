#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette palette1 = ui->pushButton->palette();
    // 颜色的角色 color role
    // QPalette中，颜色角色用来指定该颜色所起的作用，比如背景色或者时文本颜色等
    palette1.setColor(QPalette::ButtonText, Qt::red);
    palette1.setColor(QPalette::Button, Qt::green);
    ui->pushButton->setPalette(palette1);

    ui->spinBox->setDisabled(true);
    QPalette palette2 = ui->spinBox->palette();
    palette2.setColor(QPalette::Disabled, QPalette::Base, Qt::blue);
    ui->spinBox->setPalette(palette2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

