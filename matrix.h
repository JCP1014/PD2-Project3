#ifndef MATRIX_H
#define MATRIX_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include"arrow.h"

class Matrix : public Arrow
{
    Q_OBJECT
public:
    Matrix(QGraphicsItem * parent=0);
private:
    int STEP_SIZE;
};


#endif // MATRIX_H
