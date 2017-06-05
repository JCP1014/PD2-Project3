#ifndef BTN_H
#define BTN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

using namespace std;

class Btn : public QGraphicsPixmapItem
{
    public:
        Btn();
    signals:
        void clicked();
};

#endif // BTN_H
