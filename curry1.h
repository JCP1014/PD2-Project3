#ifndef CURRY1_H
#define CURRY1_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>

class Curry1 : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
        Curry1(QGraphicsItem * parent=0);
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

#endif // CURRY1_H
