#include "matlab.h"
#include<QTimer>
#include"matlabs.h"
#include"scene.h"

Matlab::Matlab(QGraphicsItem * parent)
{
    hp = 59;
    STEP_SIZE = 10;
    setPixmap(QPixmap(":/image/img/matlab.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(1000);
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(blood()));
    timer2->start(1000);
    QTimer * timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(attack()));
    timer3->start(500);

}

void Matlab::attack()
{
    Matlabs * matlabs = new Matlabs();
    matlabs->setPos(x()+90,y()+30);
    scene()->addItem(matlabs);
}
