#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimerEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    id1 = startTimer(1000);
    id2 = startTimer(1500);
    id3 = startTimer(2200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1)
    {
        qDebug() << "timer1";
    }
    else if(event->timerId() == id2)
    {
        qDebug() << "timer2";
    }
    else
    {
        qDebug() << "timer3";
    }
}
