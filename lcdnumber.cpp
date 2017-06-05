#include "lcdnumber.h"
#include<QMessageBox>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include"dialog.h"

LCDNumber::LCDNumber(QGraphicsScene* parent,int min,int sec)
{
            setSegmentStyle(QLCDNumber::Flat);
            setStyleSheet("border: 1px solid white; color: black; background: yellow;");
            setGeometry(690,0,150,50);
            timer = new QTimer();
            timeValue = new QTime(0,min,sec);
            this->display(timeValue->toString());
            QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setDisplay()));

 }

void LCDNumber::setDisplay()
{
    this->timeValue->setHMS(0,this->timeValue->addSecs(-1).minute(),this->timeValue->addSecs(-1).second());
    this->display(this->timeValue->toString());
    if(this->timeValue->minute()==0 && this->timeValue->second()==0)
    {
        timer->stop();
        QMessageBox * msg = new QMessageBox();
        msg->setIconPixmap(QPixmap(":/image/img/lose3.png"));
        msg->setWindowIcon(QPixmap(":/image/img/lose_icon.png"));
        msg->setWindowTitle("Game Result");
        msg->setText("Oh no !");
        msg->setInformativeText("You Lose !");
        msg->setStandardButtons(QMessageBox::Ok);
        msg->show();
        QMediaPlaylist * playlist = new QMediaPlaylist();
        playlist->addMedia(QUrl("qrc:/sound/snd/fail.mp3"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        QMediaPlayer * music = new QMediaPlayer();
        music->setPlaylist(playlist);
        music->play();
    }
}
