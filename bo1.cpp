#include "bo1.h"
#include<QPixmap>
#include<QTimer>
#include<qmath.h>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>
#include"scene.h"
#include"lefttower.h"
#include"leftcastle.h"
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"totoro2.h"
#include"lulumi2.h"
#include"arrow.h"
#include"luffy1.h"
#include"zoro1.h"
#include"bread1.h"
#include"curry1.h"
#include"din1.h"
#include"totoro1.h"
#include"lulumi1.h"
#include<QMediaPlayerControl>

Bo1::Bo1(QGraphicsItem *parent) : QObject()
{
    hp = 15;
    setPixmap(QPixmap(":/image/img/bo1.png"));
    //int y[2] = {0,360};
    //setPos(rand()%279-258,y[rand()%2]);
    points << QPointF(rand(),rand()) << QPointF(400,200);
    point_index = 0;
    destn = points[0];

    QTimer * timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
    timer1->start(150);
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(blood()));
    timer2->start(250);

    walksound = new QMediaPlayer();
    walksound->setMedia(QUrl("qrc:/sound/snd/Walking on grass.mp3"));
    walksound->setVolume(50);
    walksound->play();

    curesound = new QMediaPlayer();
    curesound->setMedia(QUrl("qrc:/sound/snd/cure.mp3"));
    curesound->setVolume(50);

}

void Bo1::rotate_to_point(QPointF face)
{
    QLineF ln(pos(),face);
    setRotation(-1*ln.angle());
}

void Bo1::move()
{
    int STEP_SIZE = 10;
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

void Bo1::blood()
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

        if(typeid(*(colliding_items[i])) == typeid(Luffy1))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Zoro1))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Bread1))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Curry1))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Din1))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Bo1))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Totoro1))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Lulumi1))
                curesound->play();
    }

    if(hp<=0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

}


