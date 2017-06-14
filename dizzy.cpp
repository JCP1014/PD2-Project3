#include "dizzy.h"
#include<QPixmap>
#include<QTimer>
#include<QList>
#include<QGraphicsScene>
#include"scene.h"
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"bo2.h"
#include"totoro2.h"
#include"lulumi2.h"
#include"luffy1.h"
#include"zoro1.h"
#include"bread1.h"
#include"curry1.h"
#include"din1.h"
#include"bo1.h"
#include"totoro1.h"
#include"lulumi1.h"
#include<QMediaPlayerControl>

Dizzy::Dizzy(QGraphicsItem * parent): QObject(),QGraphicsPixmapItem(parent)
{
   QPixmap pic(":/image/img/dizzy.png");
    setPixmap(pic);
    setTransformOriginPoint(pic.width()/2,pic.height()/2);
    angle = 0;
    /*arrowsound = new QMediaPlayer();
    arrowsound->setMedia(QUrl("qrc:/sound/snd/arrowsound.mp3"));
    arrowsound->setVolume(200);
    arrowsound->play();*/

    // Connect a timer to move
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(magic()));
    move_timer->start(50);

    QTimer * remove_timer = new QTimer(this);
    connect(remove_timer,SIGNAL(timeout()),this,SLOT(REMOVE()));
    remove_timer->start(5000);
}

void Dizzy::magic()
{
    angle+=5;
    setRotation(angle);
    QList<QGraphicsItem *> colliding_items = this->collidingItems();
    for(size_t i = 0, n = colliding_items.size(); i<n; ++i)
    {
        Luffy2 * luffy2 = dynamic_cast<Luffy2 *>(colliding_items[i]);
        if(luffy2)
        {
            Luffy1 * luffy1 = new Luffy1();
            scene()->addItem(luffy1);
            luffy1->setPos(colliding_items[i]->QGraphicsItem::pos().x(),colliding_items[i]->QGraphicsItem::pos().y());
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    for(size_t i = 0, n = colliding_items.size(); i<n; ++i)
    {
        Zoro2 * zoro2 = dynamic_cast<Zoro2 *>(colliding_items[i]);
        if(zoro2)
        {
            Zoro1 * zoro1 = new Zoro1();
            scene()->addItem(zoro1);
            zoro1->setPos(colliding_items[i]->QGraphicsItem::pos().x(),colliding_items[i]->QGraphicsItem::pos().y());
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    for(size_t i = 0, n = colliding_items.size(); i<n; ++i)
    {
        Bread2 * bread2 = dynamic_cast<Bread2 *>(colliding_items[i]);
        if(bread2)
        {
            Bread1 * bread1 = new Bread1();
            scene()->addItem(bread1);
            bread1->setPos(colliding_items[i]->QGraphicsItem::pos().x(),colliding_items[i]->QGraphicsItem::pos().y());
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    for(size_t i = 0, n = colliding_items.size(); i<n; ++i)
    {
        Curry2 * curry2 = dynamic_cast<Curry2 *>(colliding_items[i]);
        if(curry2)
        {
            Curry1 * curry1 = new Curry1();
            scene()->addItem(curry1);
            curry1->setPos(colliding_items[i]->QGraphicsItem::pos().x(),colliding_items[i]->QGraphicsItem::pos().y());
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    for(size_t i = 0, n = colliding_items.size(); i<n; ++i)
    {
        Din2 * din2 = dynamic_cast<Din2 *>(colliding_items[i]);
        if(din2)
        {
            Din1 * din1 = new Din1();
            scene()->addItem(din1);
            din1->setPos(colliding_items[i]->QGraphicsItem::pos().x(),colliding_items[i]->QGraphicsItem::pos().y());
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    for(size_t i = 0, n = colliding_items.size(); i<n; ++i)
    {
        Bo2 * bo2 = dynamic_cast<Bo2 *>(colliding_items[i]);
        if(bo2)
        {
            Bo1 * bo1 = new Bo1();
            scene()->addItem(bo1);
            bo1->setPos(colliding_items[i]->QGraphicsItem::pos().x(),colliding_items[i]->QGraphicsItem::pos().y());
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    for(size_t i = 0, n = colliding_items.size(); i<n; ++i)
    {
        Totoro2 * totoro2 = dynamic_cast<Totoro2 *>(colliding_items[i]);
        if(totoro2)
        {
            Totoro1 * totoro1 = new Totoro1();
            scene()->addItem(totoro1);
            totoro1->setPos(colliding_items[i]->QGraphicsItem::pos().x(),colliding_items[i]->QGraphicsItem::pos().y());
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    for(size_t i = 0, n = colliding_items.size(); i<n; ++i)
    {
        Lulumi2 * lulumi2 = dynamic_cast<Lulumi2 *>(colliding_items[i]);
        if(lulumi2)
        {
            Lulumi1 * lulumi1 = new Lulumi1();
            scene()->addItem(lulumi1);
            lulumi1->setPos(colliding_items[i]->QGraphicsItem::pos().x(),colliding_items[i]->QGraphicsItem::pos().y());
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
}

void Dizzy::REMOVE()
{
    scene()->removeItem(this);
    delete this;
    return;
}
