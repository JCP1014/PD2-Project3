#ifndef CURRY2_H
#define CURRY2_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>

class Curry2 : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
        Curry2(QGraphicsItem * parent=0);
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
#endif // CURRY2_H
