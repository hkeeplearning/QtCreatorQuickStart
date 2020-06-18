#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyLineEdit;

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MyWidget *ui;
    MyLineEdit *lineEdit;
};

#endif // MYWIDGET_H
