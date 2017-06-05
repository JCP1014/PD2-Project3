#ifndef LULUMI2_H
#define LULUMI2_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>

class Lulumi2: public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
        Lulumi2(QGraphicsItem * parent=0);
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
#endif // LULUMI2_H
