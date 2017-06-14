#include "bomb.h"
#include<QPixmap>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include"arrow.h"
#include<QLineF>
#include"scene.h"
#include<QGraphicsScene>
#include<QTimer>
#include"scene.h"
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"bo2.h"
#include"totoro2.h"
#include"lulumi2.h"
#include"qmath.h"

Bomb::Bomb(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/img/bomb.png"));
    pic.load(":/image/img/explode.png");
    setPos(20,350);
    point_index = 0;
    points << QPointF(200,200) << QPointF(400,0) << QPointF(600,200) << QPointF(800,400) << QPointF(1000,600);
    dest = points[0];
    rotateToPoint(dest);

    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3) << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);
    // Scale points
    int SCALE_FACTOR = 100;
    for(size_t i=0,n=points.size();i<n;++i )
        points[i] *= SCALE_FACTOR;

    // Create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->QAbstractGraphicsShapeItem::setPen(QPen(Qt::transparent));

    //Move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+150,y()-375);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    QTimer * timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(magic()));
    timer1->start(150);
    timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(move()));
    timer2->start(150);

}

double Bomb::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Bomb::magic()
{
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Luffy2) || typeid(*(colliding_items[i])) == typeid(Zoro2) || typeid(*(colliding_items[i])) == typeid(Bread2) || typeid(*(colliding_items[i])) == typeid(Curry2) || typeid(*(colliding_items[i])) == typeid(Din2) || typeid(*(colliding_items[i])) == typeid(Bo2) || typeid(*(colliding_items[i])) == typeid(Totoro2) || typeid(*(colliding_items[i])) == typeid(Lulumi2))
        {
           scene()->removeItem(colliding_items[i]);
           delete colliding_items[i];
           setPixmap(pic);
           timer2->stop();
           QTimer * remove_timer = new QTimer();
           remove_timer->start(1000);
           connect(remove_timer,SIGNAL(timeout()),this,SLOT(REMOVE()));
           return;
        }
    }
}

void Bomb::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void Bomb::move()
{
    QLineF ln(pos(),dest);
    /*if (ln.length() < 5){

    }*/

    // move enemy forward at current angle
    int STEP_SIZE = 141;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
    if(pos().x()<-540 || pos().x()>840)
    {
        scene()->removeItem(this);
        delete this;
    }
    point_index++;
    if(point_index==5)
    {
        setPixmap(pic);
        setPos(x(),y());
        timer2->stop();
        QTimer * remove_timer = new QTimer();
        remove_timer->start(1000);
        connect(remove_timer,SIGNAL(timeout()),this,SLOT(REMOVE()));
        return;
    }
    dest = points[point_index];
    rotateToPoint(dest);
}

void Bomb::REMOVE()
{
    scene()->removeItem(this);
    delete this;
}


