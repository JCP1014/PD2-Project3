#ifndef LIGHT_H
#define LIGHT_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
#include<QMediaPlayer>

class Light : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Light(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void blood();
private:
    QMediaPlayer * bbsound;
    int hp;
};
#endif // LIGHT_H
