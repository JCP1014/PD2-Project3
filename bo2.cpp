#include "bo2.h"
#include<QPixmap>
#include<QTimer>
#include<qmath.h>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>
#include"scene.h"
#include"luffy1.h"
#include"zoro1.h"
#include"bread1.h"
#include"curry1.h"
#include"din1.h"
#include"totoro1.h"
#include"lulumi1.h"
#include"arrow.h"
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"totoro2.h"
#include"lulumi2.h"

#include<QMediaPlayerControl>

Bo2::Bo2(QGraphicsItem *parent)
{
    hp = 15;
    setPixmap(QPixmap(":/image/img/bo2.png"));
    int y[2] = {0,360};
    setPos(rand()%279+197,y[rand()%2]);
    points << QPointF(200,200) << QPointF(400,200);
    point_index = 0;
    destn = points[0];

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(150);
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(move()));
    timer2->start(250);


    walksound = new QMediaPlayer();
    walksound->setMedia(QUrl("qrc:/sound/snd/Walking on grass.mp3"));
    walksound->setVolume(50);
    walksound->play();

    curesound = new QMediaPlayer();
    curesound->setMedia(QUrl("qrc:/sound/snd/cure.mp3"));
    curesound->setVolume(50);

}

void Bo2::rotate_to_point(QPointF face)
{
    QLineF ln(pos(),face);
    setRotation(-1*ln.angle());
}

void Bo2::move()
{
    int STEP_SIZE = 10;
    double theta = rotation();
    double dx = STEP_SIZE*qCos(qDegreesToRadians(theta));
    double dy = STEP_SIZE*qSin(qDegreesToRadians(theta));
    setPos(x()-dx,y()-dy);

    // Out of the scene
    if(pos().y()<0 || pos().y()>520 || pos().x()<-540 || pos().x()>840)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Bo2::blood()
{
    // Colliding with minions
    QList<QGraphicsItem *> colliding_items = this->collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Luffy1))
            hp -= 3;
        if(typeid(*(colliding_items[i])) == typeid(Zoro1))
            hp -= 3;
        if(typeid(*(colliding_items[i])) == typeid(Bread1))
            hp -= 4;
        if(typeid(*(colliding_items[i])) == typeid(Curry1))
            hp -= 4;
        if(typeid(*(colliding_items[i])) == typeid(Din1))
            hp -= 2;
        if(typeid(*(colliding_items[i])) == typeid(Bo2))
            hp += 3;
        if(typeid(*(colliding_items[i])) == typeid(Totoro1))
            hp -= 5;
        if(typeid(*(colliding_items[i])) == typeid(Lulumi1))
            hp -= 4;
        if(typeid(*(colliding_items[i])) == typeid(Arrow))
            hp -= 1;

        if(typeid(*(colliding_items[i])) == typeid(Luffy2))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Zoro2))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Bread2))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Curry2))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Din2))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Bo2))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Totoro2))
                curesound->play();
        if(typeid(*(colliding_items[i])) == typeid(Lulumi2))
                curesound->play();
    }

    if(hp<=0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}
