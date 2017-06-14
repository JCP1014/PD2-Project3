#include "tornado.h"
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

Tornado::Tornado(QGraphicsItem *parent) : QObject()
{
        setPixmap(QPixmap(":/image/img/tornado.png"));

        QTimer * timer1 = new QTimer();
        connect(timer1,SIGNAL(timeout()),this,SLOT(magic()));
        timer1->start(10);

        QTimer * timer2 = new QTimer();
        connect(timer2,SIGNAL(timeout()),this,SLOT(disappear()));
        timer2->start(600);
}

void Tornado::magic()
{
    int STEP_SIZE = 5;
    setPos(x(),y()-STEP_SIZE);

    if(pos().y()<0 || pos().y()>520 || pos().x()<-540 || pos().x()>840)
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
            colliding_items[i]->moveBy(0,-10);
        }
    }
}

void Tornado::disappear()
{
    scene()->removeItem(this);
    delete this;
    return;
}
