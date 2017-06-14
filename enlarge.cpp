#include "enlarge.h"
#include<QPixmap>
#include<QTimer>
#include<QList>
#include<QGraphicsScene>
#include"scene.h"
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
#include<QMediaPlayerControl>

Enlarge::Enlarge(QGraphicsItem * parent): QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/img/enlarge.png"));

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

void Enlarge::magic()
{
    QList<QGraphicsItem *> colliding_items = this->collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Luffy1) || typeid(*(colliding_items[i])) == typeid(Zoro1) || typeid(*(colliding_items[i])) == typeid(Bread1) || typeid(*(colliding_items[i])) == typeid(Curry1) || typeid(*(colliding_items[i])) == typeid(Din1) || typeid(*(colliding_items[i])) == typeid(Bo1) || typeid(*(colliding_items[i])) == typeid(Totoro1) || typeid(*(colliding_items[i])) == typeid(Lulumi1) || typeid(*(colliding_items[i])) == typeid(Linear) || typeid(*(colliding_items[i])) == typeid(Electric) || typeid(*(colliding_items[i])) == typeid(Matlab) || typeid(*(colliding_items[i])) == typeid(Lens) || typeid(*(colliding_items[i])) == typeid(Light))
        {
            colliding_items[i]->setScale(2);
        }
    }
}

void Enlarge::REMOVE()
{
    scene()->removeItem(this);
    delete this;
    return;
}
