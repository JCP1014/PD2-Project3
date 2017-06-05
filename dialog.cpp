#include "dialog.h"
#include<QMessageBox>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
}

void Dialog::win()
{
    QMessageBox::information(this,tr("Congratulation !"),tr("You Win !"));
}

void Dialog::lose()
{
    QMessageBox::critical(this,tr("Oh no !"),tr("You Lose."));
}
