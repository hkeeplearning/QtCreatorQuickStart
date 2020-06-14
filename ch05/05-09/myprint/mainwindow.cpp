#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *action_print = new QAction(tr("print"), this);
    QAction *action_printPreview = new QAction(tr("preview"), this);
    QAction *action_createPdf = new QAction(tr("pdf"), this);
    connect(action_print, &QAction::triggered, this, &MainWindow::doPrint);
    connect(action_printPreview, &QAction::triggered, this, &MainWindow::doPrintPreview);
    connect(action_createPdf, &QAction::triggered, this, &MainWindow::createPdf);
    ui->toolBar->addAction(action_print);
    ui->toolBar->addAction(action_printPreview);
    ui->toolBar->addAction(action_createPdf);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doPrint()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    if(ui->textEdit->textCursor().hasSelection())
    {
        dlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    }
    if(dlg.exec() == QDialog::Accepted)
    {
        ui->textEdit->print(&printer);
    }
}

void MainWindow::doPrintPreview()
{
    QPrinter printer;
    QPrintPreviewDialog preview(&printer, this);
    connect(&preview, &QPrintPreviewDialog::paintRequested, this, &MainWindow::printPreview);
    preview.exec();
}

void MainWindow::printPreview(QPrinter *printer)
{
    ui->textEdit->print(printer);
}

void MainWindow::createPdf()
{
    QString filename = QFileDialog::getSaveFileName(this,
                       tr("export"), QString(), "*.pdf");
    if(!filename.isEmpty())
    {
        if(QFileInfo(filename).suffix().isEmpty())
        {
            filename.append(".pdf");
        }
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);
        ui->textEdit->print(&printer);
    }
}

