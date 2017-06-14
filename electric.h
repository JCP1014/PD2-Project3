#ifndef ELECTRIC_H
#define ELECTRIC_H

#include"luffy1.h"

class Electric : public Luffy1
{
    Q_OBJECT
public:
    Electric(QGraphicsItem * parent=0);
public slots:
    void attack();
private:
    int hp;
    int STEP_SIZE;
};

#endif // ELECTRIC_H
