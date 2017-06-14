#ifndef FOG_H
#define FOG_H

#include<QGraphicsPixmapItem>
#include<QList>
#include<QObject>
#include<QGraphicsItem>
#include<QGraphicsScene>

class Fog : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Fog(QGraphicsItem * parent=0);

    public slots:
        void move();
        void disappear();
};


#endif // FOG_H
