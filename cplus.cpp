#include "cplus.h"
#include<QTimer>

CPlus::CPlus(QGraphicsItem * parent)
{
    setPixmap(QPixmap(":/image/img/c++ 2.png"));

    /*arrowsound = new QMediaPlayer();
    arrowsound->setMedia(QUrl("qrc:/sound/snd/arrowsound.mp3"));
    arrowsound->setVolume(200);
    arrowsound->play();*/

    // Connect a timer to move
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
}
