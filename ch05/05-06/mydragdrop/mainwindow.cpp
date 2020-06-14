#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setAcceptDrops(false);
    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls())
    {
        qDebug() << "Enter";
        event->acceptProposedAction();
        event->accept();
    }
    else
    {
        qDebug() << "Ignore";
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasUrls())
    {
        QList<QUrl> urlList = mimeData->urls();
        QString filename = urlList.at(0).toLocalFile();
        if(!filename.isEmpty())
        {
            QFile file(filename);
            if(!file.open(QIODevice::ReadOnly))
            {
                return;
            }
            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
        }
    }
}

