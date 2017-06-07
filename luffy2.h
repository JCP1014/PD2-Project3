#ifndef LUFFY2_H
#define LUFFY2_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>

class Luffy2 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
     public:
         Luffy2(QGraphicsItem * parent=0);
         void rotate_to_point(QPointF face);
         int score;

     public slots:
            void move();
            void blood();
     private:
         QList<QPointF> points;
         QPointF destn;
         int point_index;
         int hp;
};

#endif // LUFFY2_H
