#ifndef MATLABS_H
#define MATLABS_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include"arrow.h"

class Matlabs : public Arrow
{
    Q_OBJECT
public:
    Matlabs(QGraphicsItem * parent=0);
private:
    int STEP_SIZE;
};

#endif // MATLABS_H
