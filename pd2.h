#ifndef PD2_H
#define PD2_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
#include<QMediaPlayer>

class PD2 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PD2(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
//public slots:
    //void spawn();
private:
    QMediaPlayer * bbsound;
};

#endif // PD2_H
