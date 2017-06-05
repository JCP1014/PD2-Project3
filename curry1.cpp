#include "curry1.h"
#include<QPixmap>
#include<QTimer>
#include<qmath.h>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>
#include"scene.h"
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"bo1.h"
#include"totoro2.h"
#include"lulumi2.h"
#include"arrow.h"

Curry1::Curry1(QGraphicsItem *parent)
{
    hp = 7;
    setPixmap(QPixmap(":/image/img/curry1.png"));
    //setPos(rand()%246-230,rand()%523);
    points << QPointF(200,200) << QPointF(400,200);
    point_index = 0;
    destn = points[0];

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(150);
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(move()));
    timer2->start(250);

}

void Curry1::rotate_to_point(QPointF face)
{
    QLineF ln(pos(),face);
    setRotation(-1*ln.angle());
}

void Curry1::move()
{
    int STEP_SIZE = 20;
    double theta = rotation();
    double dx = STEP_SIZE*qCos(qDegreesToRadians(theta));
    double dy = STEP_SIZE*qSin(qDegreesToRadians(theta));
    setPos(x()+dx,y()+dy);

    // Out of the scene
    if(pos().y()<0 || pos().y()>520 || pos().x()<-540 || pos().x()>840)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Curry1::blood()
{
    // Collide with minions
    QList<QGraphicsItem *> colliding_items = this->collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Luffy2))
            hp -= 3;
        if(typeid(*(colliding_items[i])) == typeid(Zoro2))
            hp -= 3;
        if(typeid(*(colliding_items[i])) == typeid(Bread2))
            hp -= 4;
        if(typeid(*(colliding_items[i])) == typeid(Curry2))
            hp -= 4;
        if(typeid(*(colliding_items[i])) == typeid(Din2))
            hp -= 2;
        if(typeid(*(colliding_items[i])) == typeid(Bo1))
            hp += 3;
        if(typeid(*(colliding_items[i])) == typeid(Totoro2))
            hp -= 5;
        if(typeid(*(colliding_items[i])) == typeid(Lulumi2))
            hp -= 4;
        if(typeid(*(colliding_items[i])) == typeid(Arrow))
            hp -= 1;
    }

    if(hp<=0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}
