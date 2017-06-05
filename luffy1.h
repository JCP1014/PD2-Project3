#ifndef LUFFY1_H
#define LUFFY1_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>
#include<QMediaPlayer>

class Luffy1 : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
        Luffy1(QGraphicsItem * parent=0);
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

#endif // LUFFY1_H
