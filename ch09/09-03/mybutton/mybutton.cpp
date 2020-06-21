#include "mybutton.h"

MyButton::MyButton(QWidget *parent) :
    QPushButton(parent)
{

}

QString MyButton::getName()
{
    return "MyButton";
}
