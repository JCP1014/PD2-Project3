#ifndef MATLAB_H
#define MATLAB_H

#include"bread1.h"

class Matlab : public Bread1
{
    Q_OBJECT
public:
    Matlab(QGraphicsItem * parent=0);
private:
    QList<QPointF> points;
    QPointF destn;
    int point_index;
    int hp;
    int STEP_SIZE;

};

#endif // MATLAB_H
