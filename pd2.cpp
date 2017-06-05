#include "pd2.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include"scene.h"
#include"phone.h"
#include"cplus.h"

PD2::PD2(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/img/hero.png"));

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
