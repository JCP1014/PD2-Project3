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
    QTimer * timer,*timer2,*timer3;
    QTime * timeValue;
    int scoreValue;
signals:
    void isClosed();
public slots:
    void setGameTime();
    void setChooseTime();
    void setScore();
    void CLOSE();

};

#endif // LCDNUMBER_H
