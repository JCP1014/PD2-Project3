#ifndef CPLUS_H
#define CPLUS_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include"arrow.h"

class CPlus : public Arrow
{
    Q_OBJECT
public:
    CPlus(QGraphicsItem * parent=0);
};

#endif // CPLUS_H
