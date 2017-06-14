#include "smalllight.h"
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
#include<QMediaPlayerControl>

SmallLight::SmallLight(QGraphicsItem * parent): QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/img/small.png"));

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
    remove_timer->start(3000);
}

void SmallLight::magic()
{
    QList<QGraphicsItem *> colliding_items = this->collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Luffy2) || typeid(*(colliding_items[i])) == typeid(Zoro2) || typeid(*(colliding_items[i])) == typeid(Bread2) || typeid(*(colliding_items[i])) == typeid(Curry2) || typeid(*(colliding_items[i])) == typeid(Din2) || typeid(*(colliding_items[i])) == typeid(Bo2) || typeid(*(colliding_items[i])) == typeid(Totoro2) || typeid(*(colliding_items[i])) == typeid(Lulumi2))
        {
            colliding_items[i]->setScale(0.3);
        }
    }
}

void SmallLight::REMOVE()
{
    scene()->removeItem(this);
    delete this;
    return;
}
