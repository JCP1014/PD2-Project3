#ifndef TOTORO2_H
#define TOTORO2_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>

class Totoro2 : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
        Totoro2(QGraphicsItem * parent=0);
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
#endif // TOTORO2_H
