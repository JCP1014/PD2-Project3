#ifndef RIGHTCASTLE_H
#define RIGHTCASTLE_H

#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
#include<QPointF>
#include<QObject>
#include<QGraphicsScene>
#include<QMediaPlayer>
#include<QProgressBar>

class RightCastle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    RightCastle(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem *item);
    void attack();
    int hp;
    QProgressBar * bar;

public slots:
    void acquire_target();
    void blood();
    void create2_1();
    void create2_2();
    void create2_3();
    void create2_4();
    void create2_5();
    void create2_6();
    void create2_7();
    void create2_8();

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

#endif // RIGHTCASTLE_H
