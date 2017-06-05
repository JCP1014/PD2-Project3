#ifndef DIN2_H
#define DIN2_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>

class Din2 : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
        Din2(QGraphicsItem * parent=0);
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
#endif // DIN2_H
