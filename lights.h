#ifndef LIGHTS_H
#define LIGHTS_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include"arrow.h"

class Lights : public Arrow
{
    Q_OBJECT
public:
    Lights(QGraphicsItem * parent=0);
private:
    int STEP_SIZE;
};
#endif // LIGHTS_H
