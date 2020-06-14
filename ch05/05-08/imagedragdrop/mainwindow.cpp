#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPainter>
#include <QMimeData>
#include <QDrag>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAcceptDrops(true);
    QLabel *label = new QLabel(this);
    QPixmap pix("../imagedragdrop/logo.png");
    label->setPixmap(pix);
    label->resize(pix.size());
    label->move(100, 100);
    label->setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel *>(childAt(event->pos()));
    if(!child->inherits("QLabel"))
    {
        qDebug() << "Is not QLabel.";
        return;
    }

    QPixmap pix = *(child->pixmap());
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    // 当前鼠标指针的坐标减去图片左上角的坐标
    dataStream << pix << QPoint(event->pos() - child->pos());
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("myimage/png", itemData);
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pix);
    drag->setHotSpot(event->pos() - child->pos());
    QPixmap tempPix = pix;
    QPainter painter;
    painter.begin(&tempPix);
    painter.fillRect(pix.rect(), QColor(127, 127, 127, 127));
    painter.end();
    child->setPixmap(tempPix);
    if(drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction)
            == Qt::MoveAction)
    {
        child->close();
    }
    else
    {
        child->show();
        child->setPixmap(pix);
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
//        event->setDropAction(Qt::CopyAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
//        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        QByteArray itemData = event->mimeData()->data("myimage/png");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        QPixmap pix;
        QPoint offset;
        dataStream >> pix >> offset;
        QLabel *label = new QLabel(this);
        label->setPixmap(pix);
        label->resize(pix.size());
        label->move(event->pos() - offset);
        label->show();
        label->setAttribute(Qt::WA_DeleteOnClose);
//        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
