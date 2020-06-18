#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

// signals 前不能用public private 或者 protected，默认是public
// 信号只用声明，不需要也不能对它进行定义实现
// 信号没有返回值，只能是void
// 因为只有QObject类及其子类派生类才能使用信号和槽
// 必须加 Q_OBJECT
signals:
    void dlgReturn(int, int = 16);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
