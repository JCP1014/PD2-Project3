#ifndef TORNADO_H
#define TORNADO_H

#include<QGraphicsPixmapItem>
#include<QList>
#include<QObject>
#include<QGraphicsScene>

class Tornado : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Tornado(QGraphicsItem * parent=0);

    public slots:
        void move();
        void disappear();
};

#endif // TORNADO_H
