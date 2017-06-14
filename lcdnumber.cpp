#include "lcdnumber.h"
#include<QMessageBox>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include"dialog.h"
#include"iostream"
#include"fstream"
using namespace std;

LCDNumber::LCDNumber(QGraphicsScene* parent,int min,int sec)
{
            setSegmentStyle(QLCDNumber::Flat);
            setStyleSheet("border: 1px solid white; color: black; background: yellow;");
            timer = new QTimer();
            timeValue = new QTime(0,min,sec);
            this->display(timeValue->toString());
            QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setGameTime()));

            timer2 = new QTimer();
            scoreValue = sec;
            QObject::connect(timer2,SIGNAL(timeout()),this,SLOT(setScore()));

            timer3 = new QTimer();
            timeValue = new QTime(0,min,sec);
            QObject::connect(timer3,SIGNAL(timeout()),this,SLOT(setChooseTime()));
 }

void LCDNumber::setGameTime()
{
    if(timeValue->minute()==0 && timeValue->second()==0)
    {
            this->timer->stop();
            scoreValue = 0;
            ofstream outFile("file.out",ios::app);
            outFile << scoreValue << endl;
            outFile.close();
            QMessageBox* msg = new QMessageBox();
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
            return;
    }
        this->timeValue->setHMS(0,this->timeValue->addSecs(-1).minute(),this->timeValue->addSecs(-1).second());
        this->display(this->timeValue->toString());
}

void LCDNumber::setScore()
{
    scoreValue = scoreValue-5;
    this->display(this->scoreValue);
}

void LCDNumber::setChooseTime()
{
    if(timeValue->minute()==0 && timeValue->second()==0)
    {
            this->timer->stop();
            this->CLOSE();
    }
        this->timeValue->setHMS(0,this->timeValue->addSecs(-1).minute(),this->timeValue->addSecs(-1).second());
        this->display(this->timeValue->toString());
}

void LCDNumber::CLOSE()
{
    this->close();
    emit isClosed();
}
