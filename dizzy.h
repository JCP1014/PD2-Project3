#ifndef DIZZY_H
#define DIZZY_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include<QMediaPlayer>

class Dizzy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Dizzy(QGraphicsItem * parent=0);

public slots:
    void magic();
    void REMOVE();

private:
        QMediaPlayer * arrowsound;
            int angle;
};
#endif // DIZZY_H
