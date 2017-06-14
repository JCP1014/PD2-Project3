#ifndef BOMB_H
#define BOMB_H

#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
#include<QPointF>
#include<QObject>
#include<QGraphicsScene>
#include<QMediaPlayer>
#include <QList>


class Bomb : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Bomb(QGraphicsItem * parent=0);
        double distanceTo(QGraphicsItem *item);
        void rotateToPoint(QPointF p);

    public slots:
        void magic();
        void move();
        void REMOVE();

private:
        QGraphicsPolygonItem * attack_area;
        QPointF attack_destn;
        bool has_target;
        QPointF closest_pos;
        bool damaged;
        QMediaPlayer * damagedsound;
        QMediaPlayer * destroyedsound;
        QMediaPlayer * swordsound;
        QList<QPointF> points;
        QPointF dest;
        int point_index;
        QPixmap pic;
        QTimer * timer2;

};
#endif // BOMB_H
