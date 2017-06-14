#ifndef LINEAR_H
#define LINEAR_H

#include"luffy1.h"
#include<QGraphicsPolygonItem>

class Linear :  public Luffy1
{
    Q_OBJECT
public:
    Linear(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem * item);
public slots:
    void attack();
private:
    QList<QPointF> points;
    QPointF destn;
    int point_index;
    int hp;
    int STEP_SIZE;
    QGraphicsPolygonItem * attack_area;
    QPointF attack_destn;
    bool has_target;
    QPointF closest_pos;

};

#endif // LINEAR_H
