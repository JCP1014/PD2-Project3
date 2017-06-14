#ifndef ARROW_H
#define ARROW_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include<QMediaPlayer>
#include<QTimer>

class Arrow : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Arrow(QGraphicsItem * parent=0);

public slots:
    void move();

private:
        QMediaPlayer * arrowsound;
        int STEP_SIZE;
        QTimer * timer = new QTimer();
};

#endif // ARROW_H
