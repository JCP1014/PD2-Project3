#ifndef LCDNUMBER_H
#define LCDNUMBER_H

#include<QLCDNumber>
#include<QTimer>
#include<QTime>
#include<QGraphicsScene>
class LCDNumber : public QLCDNumber
{
    Q_OBJECT
public:
    LCDNumber(QGraphicsScene * parent, int min, int sec);
    QTimer * timer;
    QTime * timeValue;
public slots:
    void setDisplay();

};

#endif // LCDNUMBER_H
