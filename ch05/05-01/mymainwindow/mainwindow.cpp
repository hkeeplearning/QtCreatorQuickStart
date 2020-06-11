#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolButton>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *editMenu = ui->menubar->addMenu(tr("Edit(&E)"));
    QAction *actionOpen = editMenu->addAction(
                QIcon(":/image/images/open.png"),
                tr("Open File(&O)"));
    actionOpen->setShortcut(QKeySequence("Ctrl+O"));
    ui->toolBar->addAction(actionOpen);

    QActionGroup *group = new QActionGroup(this);
    QAction *action_L = group->addAction(tr("LeftAlign(&L)"));
    action_L->setCheckable(true);
    QAction *action_R = group->addAction(tr("RightAlign(&R)"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(tr("CenterAlign(&C)"));
    action_C->setCheckable(true);
    action_L->setChecked(true);
    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText(tr("Color"));
    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction(tr("red"));
    colorMenu->addAction(tr("yellow"));
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolBar->addWidget(toolBtn);
    QSpinBox *spinBox = new QSpinBox(this);
    ui->toolBar->addWidget(spinBox);
}

MainWindow::~MainWindow()
{
    delete ui;
}

