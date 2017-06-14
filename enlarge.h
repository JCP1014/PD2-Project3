#ifndef ENLARGE_H
#define ENLARGE_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include<QMediaPlayer>

class Enlarge : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enlarge(QGraphicsItem * parent=0);

public slots:
    void magic();
    void REMOVE();

private:
        QMediaPlayer * arrowsound;
};


#endif // ENLARGE_H
