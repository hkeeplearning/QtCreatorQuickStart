#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextFrame>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTextDocument *document = ui->textEdit->document();
    QTextFrame *rootFrame = document->rootFrame();
    QTextFrameFormat format;
    format.setBorderBrush(Qt::red);
    format.setBorder(3);
    rootFrame->setFrameFormat(format);

    QTextFrameFormat frameFormat;
    frameFormat.setBackground(Qt::lightGray);
    frameFormat.setMargin(10);
    frameFormat.setPadding(5);
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertFrame(frameFormat);

    QAction *action_textFrame = new QAction(tr("frame"), this);
    connect(action_textFrame, &QAction::triggered, this, &MainWindow::showTextFrame);
    ui->toolBar->addAction(action_textFrame);

    QAction *action_textBlock = new QAction(tr("block"), this);
    connect(action_textBlock, &QAction::triggered, this, &MainWindow::showTextBlock);
    ui->toolBar->addAction(action_textBlock);

    QAction *action_textFont = new QAction(tr("font"), this);
    action_textFont->setCheckable(true);
    connect(action_textFont, &QAction::toggled, this, &MainWindow::setTextFont);
    ui->toolBar->addAction(action_textFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextFrame()
{
    QTextDocument *document = ui->textEdit->document();
    QTextFrame *rootFrame = document->rootFrame();
    QTextFrame::iterator it;
    for (it = rootFrame->begin(); !(it.atEnd()); ++it)
    {
        QTextFrame *childFrame = it.currentFrame();
        QTextBlock childBlock = it.currentBlock();
        if(childFrame)
        {
            qDebug() << "Frame";
        }
        else if(childBlock.isValid())
        {
            qDebug() << "Block: " << childBlock.text();
        }
    }
}

void MainWindow::showTextBlock()
{
    QTextDocument *document = ui->textEdit->document();
    QTextBlock block = document->firstBlock();
    for (int i = 0; i < document->blockCount(); ++i)
    {
        qDebug() << tr("block text %1, block line number: %2, content: %3")
                    .arg(i)
                    .arg(block.firstLineNumber())
                    .arg(block.text());
        block = block.next();
    }
}

void MainWindow::setTextFont(bool checked)
{
    if(checked)
    {
        QTextCursor cursor = ui->textEdit->textCursor();
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);
        QTextCharFormat charFormat;
        charFormat.setBackground(Qt::lightGray);
        charFormat.setForeground(Qt::blue);
        charFormat.setFont(QFont(tr("宋体")));
        charFormat.setFontUnderline(true);
        cursor.setCharFormat(charFormat);
        cursor.insertText(tr("test font"));
    }
    else
    {

    }
}

