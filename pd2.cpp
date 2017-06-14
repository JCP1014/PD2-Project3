#include "pd2.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include"scene.h"
#include"phone.h"
#include"cplus.h"
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"bo1.h"
#include"totoro2.h"
#include"lulumi2.h"
#include"arrow.h"
#include"lens.h"
#include<QList>

PD2::PD2(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    hp = 1000;
    setPixmap(QPixmap(":/image/img/hero.png"));
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(blood()));
    timer2->start(50);
    bbsound = new QMediaPlayer();
    bbsound->setMedia(QUrl("qrc:/sounds/bb.mp3"));
}

void PD2::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        //prevent player out of the scene
        if (pos().x() > -540)
            setPos(x()-10,y());
    }
    if (event->key() == Qt::Key_Right){
        //prevent player out of the scene
        if (pos().x() + 100 < 840)
            setPos(x()+10,y());
    }
    if (event->key() == Qt::Key_Up){
        //prevent player out of the scene
        if (pos().y() > 0)
            setPos(x(),y()-10);
    }
    if (event->key() == Qt::Key_Down){
        //prevent player out of the scene
        if (pos().y()+80 < 520)
            setPos(x(),y()+10);
    }
    if (event->key() == Qt::Key_Space){
        //create a bullet
        Phone * phone = new Phone();
        phone->setPos(x()+110,y()+65);
        scene()->addItem(phone);

        //play bbsound
        if (bbsound->state() == QMediaPlayer::PlayingState){
            bbsound->setPosition(0);
        }
        else if (bbsound->state() == QMediaPlayer::StoppedState){
            bbsound->play();
        }
    }
    if (event->key() == Qt::Key_Alt){
        //create a bullet
        CPlus * cplus = new CPlus();
        cplus->setPos(x()+110,y()+65);
        scene()->addItem(cplus);

        //play bbsound
        if (bbsound->state() == QMediaPlayer::PlayingState){
            bbsound->setPosition(0);
        }
        else if (bbsound->state() == QMediaPlayer::StoppedState){
            bbsound->play();
        }
    }
}

void PD2::blood()
{
    // Colliding with minions
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
        if(typeid(*(colliding_items[i])) == typeid(Lens))
            hp += 5;

    }

    if(hp<=0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}
