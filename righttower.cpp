#include "righttower.h"
#include<QPixmap>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include<QLineF>
#include<QGraphicsScene>
#include<QTimer>
#include"arrow.h"
#include"scene.h"
#include"luffy1.h"
#include"zoro1.h"
#include"bread1.h"
#include"curry1.h"
#include"din1.h"
#include"bo1.h"
#include"totoro1.h"
#include"lulumi1.h"

RightTower::RightTower(QGraphicsItem *parent) : QObject(),QGraphicsPixmapItem(parent)
{
    hp = 25;
    bar = new QProgressBar();
    bar->setValue(hp/25*100);
    bar->show();
    // Create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3) << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // Scale points
    int SCALE_FACTOR = 90;
    for(size_t i=0,n=points.size();i<n;++i )
        points[i] *= SCALE_FACTOR;

    // Create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->QAbstractGraphicsShapeItem::setPen(QPen(Qt::transparent));

    //Move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+175,y()+85);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());


    QTimer * timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer1->start(900);
    QTimer * timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(blood()));
    timer2->start(1000);

    damagedsound = new QMediaPlayer();
    damagedsound->setMedia(QUrl("qrc:/sound/snd/Punch.mp3"));
    damagedsound->setVolume(50);

    destroyedsound = new QMediaPlayer();
    destroyedsound->setMedia(QUrl("qrc:/sound/snd/destroy.mp3"));
    destroyedsound->setVolume(500);

    swordsound = new QMediaPlayer();
    swordsound->setMedia(QUrl("qrc:/sound/snd/sword.mp3"));
    swordsound->setVolume(250);

}

double RightTower::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void RightTower::attack()
{
    Arrow * arrow = new Arrow();
    arrow->setPos(x()+175,y()+80);

    QLineF ln(QPointF(x()+175,y()+80),QPointF(attack_destn.x()+50,attack_destn.y()+50));
    int angle = ln.angle();

    arrow->setRotation(-angle);
    this->scene()->addItem(arrow);

}

void RightTower::acquire_target()
{
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if(colliding_items.size()<=4)
    {
        has_target = false;
        return;
    }

    double closest_dist = 500;
    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Luffy1 * luffy1 = dynamic_cast<Luffy1 *>(colliding_items[i]);
        {
            if(luffy1)
            {   double this_dist = distanceTo(luffy1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Totoro1 * totoro1 = dynamic_cast<Totoro1 *>(colliding_items[i]);
        {
            if(totoro1)
            {
                double this_dist = distanceTo(totoro1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Zoro1 * zoro1 = dynamic_cast<Zoro1 *>(colliding_items[i]);
        {
            if(zoro1)
            {
                double this_dist = distanceTo(zoro1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Bread1 * bread1 = dynamic_cast<Bread1 *>(colliding_items[i]);
        {
            if(bread1)
            {
                double this_dist = distanceTo(bread1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Curry1 * curry1 = dynamic_cast<Curry1 *>(colliding_items[i]);
        {
            if(curry1)
            {
                double this_dist = distanceTo(curry1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Din1 * din1 = dynamic_cast<Din1 *>(colliding_items[i]);
        {
            if(din1)
            {
                double this_dist = distanceTo(din1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Bo1 * bo1 = dynamic_cast<Bo1 *>(colliding_items[i]);
        {
            if(bo1)
            {
                double this_dist = distanceTo(bo1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Lulumi1 * lulumi1 = dynamic_cast<Lulumi1 *>(colliding_items[i]);
        {
            if(lulumi1)
            {
                double this_dist = distanceTo(lulumi1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();
}\

void RightTower::blood()
{
    QList<QGraphicsItem *> reaching_items = this->collidingItems();
    if(reaching_items.size()<=1)
    {
        damaged = false;
        return;
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Luffy1 * luffy1 = dynamic_cast<Luffy1 *>(reaching_items[i]);
        if(luffy1)
        {
            hp -= 3;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Zoro1 * zoro1 = dynamic_cast<Zoro1 *>(reaching_items[i]);
        if(zoro1)
        {
             hp -= 3;
             bar->setValue(hp*4);
             swordsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Bread1 * bread1 = dynamic_cast<Bread1 *>(reaching_items[i]);
        if(bread1)
        {
            hp -= 4;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Curry1 * curry1 = dynamic_cast<Curry1 *>(reaching_items[i]);
        if(curry1)
        {
            hp -= 4;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Din1 * din1 = dynamic_cast<Din1 *>(reaching_items[i]);
        if(din1)
        {
            hp -= 2;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Totoro1 * totoro1 = dynamic_cast<Totoro1 *>(reaching_items[i]);
        if(totoro1)
        {
            hp -= 5;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Lulumi1 * lulumi1 = dynamic_cast<Lulumi1 *>(reaching_items[i]);
        if(lulumi1)
        {
            hp -= 4;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    if(hp<=0)
    {
        bar->setValue(hp*2);
        destroyedsound->play();
        scene()->removeItem(this);
        delete this;
        return;
    }
}
