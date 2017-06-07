#ifndef LIGHT_H
#define LIGHT_H

#include"bread1.h"

class Light : public Bread1
{
    Q_OBJECT
public:
    Light(QGraphicsItem *parent=0);
private:
    QList<QPointF> points;
    QPointF destn;
    int point_index;
    int hp;
    int STEP_SIZE;

};

#endif // LIGHT_H
