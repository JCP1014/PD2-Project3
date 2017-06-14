#include "lens.h"
#include<QTimer>

Lens::Lens(QGraphicsItem * parent)
{
    hp = 55;
    STEP_SIZE = 10;
    setPixmap(QPixmap(":/image/img/lens.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(150);
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(blood()));
    timer2->start(1000);

    curesound = new QMediaPlayer();
    curesound->setMedia(QUrl("qrc:/sound/snd/cure.mp3"));
    curesound->setVolume(50);

}
