#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *action_textFind = new QAction(tr("Find"), this);
    connect(action_textFind, &QAction::triggered, this, &MainWindow::textFind);
    ui->toolBar->addAction(action_textFind);

    findDialog = new QDialog(this);
    lineEdit = new QLineEdit(findDialog);
    QPushButton *btn = new QPushButton(findDialog);
    btn->setText(tr("Find next"));
    connect(btn, &QPushButton::clicked, this, &MainWindow::findNext);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    findDialog->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::textFind()
{
    if(findDialog)
    {
        findDialog->show();
    }
}

void MainWindow::findNext()
{
    QString string = lineEdit->text();
    bool isFound = ui->textEdit->find(string, QTextDocument::FindBackward);
    if(isFound)
    {
        qDebug() << tr("line number: %1, column: %2")
                    .arg(ui->textEdit->textCursor().blockNumber())
                    .arg(ui->textEdit->textCursor().columnNumber());
    }
}

