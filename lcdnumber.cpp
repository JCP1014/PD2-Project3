#include "lcdnumber.h"
#include<QMessageBox>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include"dialog.h"

LCDNumber::LCDNumber(QGraphicsScene* parent,int min,int sec)
{
            setSegmentStyle(QLCDNumber::Flat);
            setStyleSheet("border: 1px solid white; color: black; background: yellow;");
            timer = new QTimer();
            timeValue = new QTime(0,min,sec);
            this->display(timeValue->toString());
            QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setDisplay()));
 }

void LCDNumber::setDisplay()
{
    this->timeValue->setHMS(0,this->timeValue->addSecs(-1).minute(),this->timeValue->addSecs(-1).second());
    this->display(this->timeValue->toString());
}


