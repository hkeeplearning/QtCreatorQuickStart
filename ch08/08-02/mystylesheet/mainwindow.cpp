#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    setStyleSheet("QPushButton{background:yellow}QSlider{background:blue}");

//    ui->pushButton->setStyleSheet("background:yellow");
//    ui->horizontalSlider->setStyleSheet("background:blue");

    file = new QFile(":/qss/qss/my.qss", this);
    file->open(QFile::ReadOnly);
    QString styleSheet = tr(file->readAll());
    setStyleSheet(styleSheet);
    file->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(file->fileName() == ":/qss/qss/my.qss")
    {
        file->setFileName(":/qss/qss/my2.qss");
    }
    else
    {
        file->setFileName(":/qss/qss/my.qss");
    }
    file->open(QFile::ReadOnly);
    QString styleSheet = tr(file->readAll());
    setStyleSheet(styleSheet);
    file->close();
}
