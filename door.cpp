#include "door.h"
#include<QPixmap>
#include"scene.h"
#include<QList>
#include"luffy1.h"
#include"zoro1.h"
#include"bread1.h"
#include"curry1.h"
#include"din1.h"
#include"bo1.h"
#include"totoro1.h"
#include"lulumi1.h"
#include"linear.h"
#include"electric.h"
#include"matlab.h"
#include"lens.h"
#include"light.h"
#include<QTimer>

Door::Door(QGraphicsItem *parent) : QObject()
{
        setPixmap(QPixmap(":/image/img/door.png"));

        QTimer * timer1 = new QTimer();
        connect(timer1,SIGNAL(timeout()),this,SLOT(magic()));
        timer1->start(10);

        QTimer * timer2 = new QTimer();
        connect(timer2,SIGNAL(timeout()),this,SLOT(disappear()));
        timer2->start(600);
}

void Door::magic()
{
    int STEP_SIZE = 5;
    //setPos(x()+STEP_SIZE,y());

    if(pos().x()<-540 || pos().x()>840)
    {
        scene()->removeItem(this);
        delete this;
    }

    // Collide with minions
    QList<QGraphicsItem *> colliding_items = this->collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Luffy1) || typeid(*(colliding_items[i])) == typeid(Zoro1) || typeid(*(colliding_items[i])) == typeid(Bread1) || typeid(*(colliding_items[i])) == typeid(Curry1) || typeid(*(colliding_items[i])) == typeid(Din1) || typeid(*(colliding_items[i])) == typeid(Bo1) || typeid(*(colliding_items[i])) == typeid(Totoro1) || typeid(*(colliding_items[i])) == typeid(Lulumi1) || typeid(*(colliding_items[i])) == typeid(Linear) || typeid(*(colliding_items[i])) == typeid(Electric) || typeid(*(colliding_items[i])) == typeid(Matlab) || typeid(*(colliding_items[i])) == typeid(Lens) || typeid(*(colliding_items[i])) == typeid(Light))
        {
            colliding_items[i]->moveBy(160,0);
        }
    }
}

void Door::disappear()
{
    scene()->removeItem(this);
    delete this;
    return;
}
