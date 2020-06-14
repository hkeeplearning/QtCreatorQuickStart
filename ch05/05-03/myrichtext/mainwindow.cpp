#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *action_textTable = new QAction(tr("table"), this);
    QAction *action_textList = new QAction(tr("list"), this);
    QAction *action_textImage = new QAction(tr("image"), this);
    connect(action_textTable, &QAction::triggered, this, &MainWindow::insertTable);
    connect(action_textList, &QAction::triggered, this, &MainWindow::insertList);
    connect(action_textImage, &QAction::triggered, this, &MainWindow::insertImage);
    ui->toolBar->addAction(action_textTable);
    ui->toolBar->addAction(action_textList);
    ui->toolBar->addAction(action_textImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertTable()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;
    format.setCellSpacing(2);
    format.setCellPadding(10);
    cursor.insertTable(2, 2, format);
}

void MainWindow::insertList()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListDecimal);
    cursor.insertList(format);
}

void MainWindow::insertImage()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextImageFormat format;
    format.setName("../myrichtext/logo.png");
    cursor.insertImage(format);
}

