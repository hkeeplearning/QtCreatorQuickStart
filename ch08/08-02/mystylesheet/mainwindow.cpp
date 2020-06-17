#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    setStyleSheet("QPushButton{background:yellow}QSlider{background:blue}");

//    ui->pushButton->setStyleSheet("background:yellow");
//    ui->horizontalSlider->setStyleSheet("background:blue");
}

MainWindow::~MainWindow()
{
    delete ui;
}

