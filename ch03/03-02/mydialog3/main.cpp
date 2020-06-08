#include "mywidget.h"
#include "mydialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDialog dialog;
    // Shows the dialog as a modal dialog, blocking until the user closes it
    if(dialog.exec() == QDialog::Accepted)
    {
        MyWidget w;
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
