#ifndef ZORO2_H
#define ZORO2_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>
#include<QMediaPlayer>

class Zoro2: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Zoro2(QGraphicsItem * parent=0);
        void rotate_to_point(QPointF face);

    public slots:
        void move();
        void blood();
    private:
        QList<QPointF> points;
        QPointF destn;
        int point_index;
        int hp;
        QMediaPlayer * attacksound;
};


#endif // ZORO2_H
