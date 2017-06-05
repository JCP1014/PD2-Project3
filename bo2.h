#ifndef BO2_H
#define BO2_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>
#include<QMediaPlayer>

class Bo2 : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
        Bo2(QGraphicsItem * parent=0);
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
#endif // BO2_H
