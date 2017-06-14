#ifndef DOOR_H
#define DOOR_H

#include<QGraphicsPixmapItem>
#include<QList>
#include<QObject>
#include<QGraphicsItem>
#include<QGraphicsScene>

class Door : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Door(QGraphicsItem * parent=0);

    public slots:
        void magic();
        void disappear();
};
#endif // DOOR_H
