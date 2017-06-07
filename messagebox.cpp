#include "messagebox.h"
#include"scene.h"
#include"mainwindow.h"

extern Scene * scene1;

MessageBox::MessageBox()
{
    scene1->number->timer->stop();
}
