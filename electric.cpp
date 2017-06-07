#include "electric.h"
#include<QTimer>

Electric::Electric(QGraphicsItem * parent)
{
    hp = 7;
    STEP_SIZE = 20;
    setPixmap(QPixmap(":/image/img/electric.png"));
    points << QPointF(200,200) << QPointF(400,200);
    point_index = 0;
    destn = points[0];

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(150);
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(move()));
    timer2->start(250);

}
