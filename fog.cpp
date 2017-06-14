#include "fog.h"
#include<QPixmap>
#include"scene.h"
#include<QList>
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"bo2.h"
#include"totoro2.h"
#include"lulumi2.h"
#include<QTimer>

Fog::Fog(QGraphicsItem *parent) : QObject()
{
        setPixmap(QPixmap(":/image/img/fog.png"));

        QTimer * timer1 = new QTimer();
        connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
        timer1->start(10);

        QTimer * timer2 = new QTimer();
        connect(timer2,SIGNAL(timeout()),this,SLOT(disappear()));
        timer2->start(600);
}

void Fog::move()
{
    int STEP_SIZE = 5;
    setPos(x()+STEP_SIZE,y());

    if(pos().x()<-540 || pos().x()>840)
    {
        scene()->removeItem(this);
        delete this;
    }

    // Collide with minions
    QList<QGraphicsItem *> colliding_items = this->collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Luffy2) || typeid(*(colliding_items[i])) == typeid(Zoro2) || typeid(*(colliding_items[i])) == typeid(Bread2) || typeid(*(colliding_items[i])) == typeid(Curry2) || typeid(*(colliding_items[i])) == typeid(Din2) || typeid(*(colliding_items[i])) == typeid(Bo2) || typeid(*(colliding_items[i])) == typeid(Totoro2) || typeid(*(colliding_items[i])) == typeid(Lulumi2) )
        {
            colliding_items[i]->moveBy(20,0);
        }
    }
}

void Fog::disappear()
{
    scene()->removeItem(this);
    delete this;
    return;
}
