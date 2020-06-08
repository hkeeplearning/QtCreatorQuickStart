#include "mywidget.h"
#include "ui_mywidget.h"

#include <QDialog>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

//    // 此时 dialog 一闪而过，因为 dialog 是一个对象，当 MyWidget 构造函数结束后，
//    // dialog 对象就会被自动释放
//    QDialog dialog(this);
//    dialog.show();

//    // 指向 QDialog 类对象的指针变量
//    // 为 dialog 指明了父窗口，所以没有必要使用delete释放该对象
//    // modeless
//    QDialog *dialog = new QDialog(this);
//    dialog->show();

//    // dialog 弹出，但是 mywidget没有出来，当关闭 dialog 后， mywidget才会弹出
//    // 模态对话框 (modal)
//    // 模态对话框 即没有关闭它之前，不能在于同一应用程序的其他窗口进行交互
//    // 比如新建时弹出的对话框
//    // 对非模态 既可以与它交互，也可以与同一程序中的其他窗口交互，
//    // 比如word中的搜索对话框
//    QDialog dialog(this);
//    dialog.exec();

    // 使用show也可以实现模态对话框
    // 但它有不同与使用exec实现的模态对话框
    // 调用完show函数后，会立即将控制权交给调用者，程序可以继续往下执行
    QDialog *dialog = new QDialog(this);
    dialog->setWindowModality(Qt::ApplicationModal);
//    dialog->setModal(true);
    dialog->show();
}

MyWidget::~MyWidget()
{
    delete ui;
}
