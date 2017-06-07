#include "linear.h"
#include<QTimer>
#include<QVector>
#include<QPolygonF>
#include<QLineF>
#include"arrow.h"
#include"scene.h"
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"bo2.h"
#include"totoro2.h"
#include"lulumi2.h"
#include"lefttower.h"

Linear::Linear(QGraphicsItem * parent)
{
    hp = 100;
    STEP_SIZE = 1;
    setPixmap(QPixmap(":/image/img/linear.png"));
    points << QPointF(200,200) << QPointF(400,200);
    point_index = 0;
    destn = points[0];

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(1000);
    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(blood()));
    timer2->start(250);

    // Create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3) << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // Scale points
    int SCALE_FACTOR = 90;
    for(size_t i=0,n=points.size();i<n;++i )
        points[i] *= SCALE_FACTOR;

    // Create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->QAbstractGraphicsShapeItem::setPen(QPen(Qt::transparent));

    //Move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+175,y()+85);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());


    QTimer * timer3 = new QTimer();
    connect(timer3,SIGNAL(timeout()),this,SLOT(LeftTower::acquire_target()));
    timer3->start(100);

}
