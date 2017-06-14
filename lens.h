#ifndef LENS_H
#define LENS_H

#include"bo1.h"

class Lens : public Bo1
{
    Q_OBJECT
public:
    Lens(QGraphicsItem * parent=0);
private:
    int hp;
    int STEP_SIZE;

};

#endif // LENS_H
