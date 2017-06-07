#ifndef LENS_H
#define LENS_H

#include"bread1.h"

class Lens : public Bread1
{
    Q_OBJECT
public:
    Lens(QGraphicsItem * parent=0);
private:
    QList<QPointF> points;
    QPointF destn;
    int point_index;
    int hp;
    int STEP_SIZE;

};

#endif // LENS_H
