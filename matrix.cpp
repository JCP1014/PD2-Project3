#include "matrix.h"
#include<QTimer>

Matrix::Matrix(QGraphicsItem * parent)
{
    setPixmap(QPixmap(":/image/img/matrix.png"));
    STEP_SIZE = 1;
    /*arrowsound = new QMediaPlayer();
    arrowsound->setMedia(QUrl("qrc:/sound/snd/arrowsound.mp3"));
    arrowsound->setVolume(200);
    arrowsound->play();*/

    // Connect a timer to move
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(600);
}
