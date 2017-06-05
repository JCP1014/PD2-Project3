#ifndef BO1_H
#define BO1_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>
#include<QGraphicsView>
#include<QGraphicsItem>
#include<QMediaPlayer>

class Bo1 : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
        Bo1(QGraphicsItem * parent=0);
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
        QMediaPlayer * curesound;

};

#endif // BO1_H
