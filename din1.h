#ifndef DIN1_H
#define DIN1_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>
#include<QMediaPlayer>

class Din1 : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
        Din1(QGraphicsItem * parent=0);
        void rotate_to_point(QPointF face);

    public slots:
            void move();
            void blood();
    private:
        QList<QPointF> points;
        QPointF destn;
        int point_index;
        int hp;
        QMediaPlayer * walksound;
};

#endif // DIN1_H
