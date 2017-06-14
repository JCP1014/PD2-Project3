#include "electric.h"
#include<QTimer>
#include"brainwave.h"
#include"scene.h"

Electric::Electric(QGraphicsItem * parent)
{
    hp = 51;
    STEP_SIZE = 15;
    setPixmap(QPixmap(":/image/img/electric.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(150);
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(blood()));
    timer2->start(1000);
    QTimer * timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(attack()));
    timer3->start(500);
}

void Electric::attack()
{
    BrainWave * brainwave = new BrainWave();
    brainwave->setPos(x()+90,y()+30);
    scene()->addItem(brainwave);
}
