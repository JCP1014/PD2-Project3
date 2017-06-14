#ifndef SMALLLIGHT_H
#define SMALLLIGHT_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include<QMediaPlayer>

class SmallLight : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SmallLight(QGraphicsItem * parent=0);

public slots:
    void magic();
    void REMOVE();

private:
        QMediaPlayer * arrowsound;
};

#endif // SMALLLIGHT_H
