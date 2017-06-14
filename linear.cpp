#include "linear.h"
#include<QTimer>
#include<QVector>
#include<QPolygonF>
#include<QLineF>
#include"scene.h"
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"bo1.h"
#include"totoro2.h"
#include"lulumi2.h"
#include"lefttower.h"
#include"matrix.h"
#include"lens.h"

Linear::Linear(QGraphicsItem * parent)
{
    hp = 51;
    STEP_SIZE = 15;
    setPixmap(QPixmap(":/image/img/linear.png"));
    points << QPointF(200,200) << QPointF(400,200);
    point_index = 0;
    destn = points[0];

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(150);
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(blood()));
    timer2->start(1000);
    QTimer * timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(attack()));
    timer3->start(3000);

}

void Linear::attack()
{
    Matrix * matrix = new Matrix();
    matrix->setPos(x()+90,y()+30);
    scene()->addItem(matrix);
}
