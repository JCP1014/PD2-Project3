#ifndef LEFTTOWER_H
#define LEFTTOWER_H

#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
#include<QPointF>
#include<QObject>
#include<QGraphicsView>
#include<QMediaPlayer>
#include<QProgressBar>

class LeftTower : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        LeftTower(QGraphicsItem * parent=0);
        double distanceTo(QGraphicsItem * item);
        void attack();
        QProgressBar * bar;
    public slots:
        void acquire_target();
        void blood();

    private:
        QGraphicsPolygonItem * attack_area;
        QPointF attack_destn;
        bool has_target;
        QPointF closest_pos;
        bool damaged;
        int hp;
        QMediaPlayer * damagedsound;
        QMediaPlayer * destroyedsound;
        QMediaPlayer * swordsound;


};

#endif // LEFTTOWER_H
