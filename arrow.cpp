#include "arrow.h"
#include<QPixmap>
#include<QTimer>
#include<qmath.h>
#include<QList>
#include<QGraphicsScene>
#include"scene.h"
#include"luffy1.h"
#include"luffy2.h"
#include"zoro1.h"
#include"zoro2.h"
#include"bread1.h"
#include"bread2.h"
#include"curry1.h"
#include"curry2.h"
#include"din1.h"
#include"din2.h"
#include"bo1.h"
#include"bo2.h"
#include"totoro1.h"
#include"totoro2.h"
#include"lulumi1.h"
#include"lulumi2.h"
#include<QMediaPlayerControl>

Arrow::Arrow(QGraphicsItem * parent): QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/img/arrow.png"));

    arrowsound = new QMediaPlayer();
    arrowsound->setMedia(QUrl("qrc:/sound/snd/arrowsound.mp3"));
    arrowsound->setVolume(200);
    arrowsound->play();

    // Connect a timer to move
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
}

void Arrow::move()
{
    int STEP_SIZE = 30;
    double theta = rotation();
    double dx = STEP_SIZE*qCos(qDegreesToRadians(theta));
    double dy = STEP_SIZE*qSin(qDegreesToRadians(theta));
    setPos(x()+dx,y()+dy);

   //  Out of the scene
    if(pos().y()<0 || pos().y()>520 || pos().x()<-540 || pos().x()>840)
   {
       scene()->removeItem(this);
       delete this;
   }

    // Collide with minions
    QList<QGraphicsItem *> colliding_items = this->collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Luffy1) || typeid(*(colliding_items[i])) == typeid(Luffy2) || typeid(*(colliding_items[i])) == typeid(Zoro1) || typeid(*(colliding_items[i])) == typeid(Zoro2) || typeid(*(colliding_items[i])) == typeid(Bread1) || typeid(*(colliding_items[i])) == typeid(Bread2) || typeid(*(colliding_items[i])) == typeid(Curry1) || typeid(*(colliding_items[i])) == typeid(Curry2) ||typeid(*(colliding_items[i])) == typeid(Din1) || typeid(*(colliding_items[i])) == typeid(Din2) || typeid(*(colliding_items[i])) == typeid(Bo1) || typeid(*(colliding_items[i])) == typeid(Bo2) || typeid(*(colliding_items[i])) == typeid(Totoro1) || typeid(*(colliding_items[i])) == typeid(Totoro2) || typeid(*(colliding_items[i])) == typeid(Lulumi1) || typeid(*(colliding_items[i])) == typeid(Lulumi2) )
        {
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

}
