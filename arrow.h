#ifndef ARROW_H
#define ARROW_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include<QMediaPlayer>

class Arrow : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Arrow(QGraphicsItem * parent=0);
    int STEP_SIZE;
public slots:
    void move();

private:
        QMediaPlayer * arrowsound;
};

#endif // ARROW_H
