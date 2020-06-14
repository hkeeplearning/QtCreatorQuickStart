#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QLineEdit;
class QDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void textFind();
    void findNext();

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit;
    QDialog *findDialog;
};
#endif // MAINWINDOW_H
