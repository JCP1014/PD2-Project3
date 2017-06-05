#include "zoro2.h"
#include<QPixmap>
#include<QTimer>
#include<qmath.h>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>
#include"luffy1.h"
#include"zoro1.h"
#include"bread1.h"
#include"curry1.h"
#include"din1.h"
#include"bo2.h"
#include"totoro1.h"
#include"lulumi1.h"
#include"arrow.h"


Zoro2::Zoro2(QGraphicsItem *parent)
{
        hp = 11;
        setPixmap(QPixmap(":/image/img/zoro2.png"));
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

        attacksound = new QMediaPlayer();
        attacksound->setMedia(QUrl("qrc:/sound/snd/sword.mp3"));
        attacksound->setVolume(50);
}

void Zoro2::rotate_to_point(QPointF face)
{
    QLineF ln(pos(),face);
    setRotation(-1*ln.angle());
}

void Zoro2::move()
{
    int STEP_SIZE = 15;
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

void Zoro2::blood()
{
    // Colliding with minions
    QList<QGraphicsItem *> colliding_items = this->collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Luffy1))
            hp -= 3;
            attacksound->play();
        if(typeid(*(colliding_items[i])) == typeid(Zoro1))
            hp -= 3;
            attacksound->play();
        if(typeid(*(colliding_items[i])) == typeid(Bread1))
            hp -= 4;
            attacksound->play();
        if(typeid(*(colliding_items[i])) == typeid(Curry1))
            hp -= 4;
            attacksound->play();
        if(typeid(*(colliding_items[i])) == typeid(Din1))
            hp -= 2;
            attacksound->play();
        if(typeid(*(colliding_items[i])) == typeid(Bo2))
            hp += 3;
        if(typeid(*(colliding_items[i])) == typeid(Totoro1))
            hp -= 5;
            attacksound->play();
        if(typeid(*(colliding_items[i])) == typeid(Lulumi1))
            hp -= 4;
            attacksound->play();
        if(typeid(*(colliding_items[i])) == typeid(Arrow))
            hp -= 1;
            attacksound->play();
    }

    if(hp<=0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}
