#ifndef PHONE_H
#define PHONE_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include"arrow.h"

class Phone : public Arrow
{
    Q_OBJECT
public:
    Phone(QGraphicsItem * parent=0);
};

#endif // PHONE_H
