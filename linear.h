#ifndef LINEAR_H
#define LINEAR_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QList>
#include<QPointF>
#include"bread1.h"

class Linear :  public Bread1
{
    Q_OBJECT
public:
    Linear(QGraphicsItem * parent=0);
private:
    QList<QPointF> points;
    QPointF destn;
    int point_index;
    int hp;
    int STEP_SIZE;

};

#endif // LINEAR_H
