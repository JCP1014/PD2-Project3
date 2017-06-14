#ifndef MATLAB_H
#define MATLAB_H

#include"luffy1.h"

class Matlab : public Luffy1
{
    Q_OBJECT
public:
    Matlab(QGraphicsItem * parent=0);
public slots:
    void attack();
private:
    int hp;
    int STEP_SIZE;

};

#endif // MATLAB_H
