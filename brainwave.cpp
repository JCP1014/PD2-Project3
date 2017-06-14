#include "brainwave.h"
#include<QTimer>

BrainWave::BrainWave(QGraphicsItem * parent)
{
    setPixmap(QPixmap(":/image/img/brainwave.png"));
    STEP_SIZE = 1;
    /*arrowsound = new QMediaPlayer();
    arrowsound->setMedia(QUrl("qrc:/sound/snd/arrowsound.mp3"));
    arrowsound->setVolume(200);
    arrowsound->play();*/

    // Connect a timer to move
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(5000);
}
