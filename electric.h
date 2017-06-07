#ifndef ELECTRIC_H
#define ELECTRIC_H

#include"bread1.h"

class Electric : public Bread1
{
    Q_OBJECT
public:
    Electric(QGraphicsItem * parent=0);
private:
    QList<QPointF> points;
    QPointF destn;
    int point_index;
    int hp;
    int STEP_SIZE;
};

#endif // ELECTRIC_H
