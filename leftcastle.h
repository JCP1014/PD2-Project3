#ifndef LEFTCASTLE_H
#define LEFTCASTLE_H

#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
#include<QPointF>
#include<QObject>
#include<QGraphicsScene>
#include<QMediaPlayer>
#include<QProgressBar>

class LeftCastle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        LeftCastle(QGraphicsItem * parent=0);
        double distanceTo(QGraphicsItem *item);
        void attack();
        int hp;
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
        QMediaPlayer * damagedsound;
        QMediaPlayer * destroyedsound;
        QMediaPlayer * swordsound;

};

#endif // LEFTCASTLE_H
