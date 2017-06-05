#ifndef BREAD1_H
#define BREAD1_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>

class Bread1 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
     public:
         Bread1(QGraphicsItem * parent=0);
         void rotate_to_point(QPointF face);

     public slots:
             void move();
             void blood();
     private:
         QList<QPointF> points;
         QPointF destn;
         int point_index;
         int hp;
};

#endif // BREAD1_H
