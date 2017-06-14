#ifndef BRAINWAVE_H
#define BRAINWAVE_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include"arrow.h"

class BrainWave : public Arrow
{
    Q_OBJECT
public:
    BrainWave(QGraphicsItem * parent=0);
private:
    int STEP_SIZE;
};


#endif // BRAINWAVE_H
