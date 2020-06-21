#include "widget.h"
#include "ui_widget.h"

#include "../MyPlugin/regexpinterface.h"

#include <QPluginLoader>
#include <QMessageBox>
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    if(!loadPlugin())
    {
        QMessageBox::information(this, "Error", "could not load dll");
        ui->lineEdit->setEnabled(false);
        ui->pushButton->setEnabled(false);
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString str = regexpInterface->regexp(ui->lineEdit->text());
    ui->label->setText(str);
}

bool Widget::loadPlugin()
{
    QPluginLoader pluginLoader("D:/GitRepo/CPlusPlus/QtCreatorQuickStart/ch09/09-05/build-MyFirstPlugin-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/plugins/MyPlugin.dll");
    QObject *plugin = pluginLoader.instance();
    if(plugin)
    {
        regexpInterface = qobject_cast<RegExpInterface *>(plugin);
        if(regexpInterface)
        {
            return true;
        }
    }
    return false;
}
