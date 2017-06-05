#ifndef BREAD2_H
#define BREAD2_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>

class Bread2 : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
        Bread2(QGraphicsItem * parent=0);
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
#endif // BREAD2_H
