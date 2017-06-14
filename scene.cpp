#include "scene.h"
#include<QGraphicsScene>
#include "lefttower.h"
#include"leftcastle.h"
#include"righttower.h"
#include"rightcastle.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QProgressBar>
#include"lcdnumber.h"
#include<QMessageBox>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include"dialog.h"

Scene::Scene(QObject *parent) : QGraphicsScene()
{
    screenMode = 0;
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sound/snd/bgsound.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer * music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
}

void Scene::Init()
{
    // Start
    btn_start = new Btn();
    QPixmap start;
    start.load(":/image/img/startbtn.png");
    start = start.scaled(start.width(),start.height(),Qt::KeepAspectRatio);
    btn_w = (start.width());
    btn_h = (start.height());
    btn_start->setPixmap(start);
    btn_start->setPos(380,400);
    addItem(btn_start);
    btn_yes = new Btn();
    QPixmap yes;
    yes.load(":/image/img/choose.png");
    btn_yes->setPixmap(yes);
    btn_yes->setPos(437,10);
    addItem(btn_yes);
    btn_no = new Btn();
    QPixmap no;
    no.load(":/image/img/cancel.png");
    btn_no->setPixmap(no);
    btn_no->setPos(630,10);
    addItem(btn_no);

    chooseTime = new LCDNumber(this,0,12);
    this->addWidget(chooseTime);
    chooseTime->setDigitCount(2);
    chooseTime->setGeometry(322,10,100,75);
    //chooseTime->timer->start(1000);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     if(screenMode==0)
    {
        // Beginning page
        if(event->scenePos().x() > btn_start->pos().x() && event->scenePos().x() <= btn_start->pos().x()+btn_w)
        {
             // Now x is in range , judge y
            if(event->scenePos().y() > btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y()+btn_h)
            {
                // x , y both in button area

                LCDNumber * number = new LCDNumber(this,3,0);
                number->setStyleSheet("border: 1px solid white; color: rgb(0,255,0); background: black;");
                this->addWidget(number);
                number->setGeometry(690,0,150,50);
                number->timer->start(1000);

                bgChange();

                //myscore = new LCDNumber(this,0,0);
                //this->addWidget(myscore);
                //myscore->setGeometry(-550,0,150,50);
            }
        }
    }
    else if(screenMode==1)
    {
            // Starting page
            if(event->scenePos().x() > btn_back->pos().x()&&event->scenePos().x() <= btn_back->pos().x()+btn_small_w)
            {
                // Now x is in range, judge y
                if(event->scenePos().y() > btn_back->pos().y()&&event->scenePos().y() <= btn_back->pos().y()+btn_small_h)
                {
                    // x,y both in back button area
                    bgRecover();
                    screenMode = 0;
                }
            }
    }
     //cout << "Now event x: " << event->scenePos().x()<< " event y: " << event->scenePos().y() << endl;
}

void Scene::bgChange()
{
    // Change background picture
    QImage bg;
    bg.load(":/image/img/gamebg2.png");
    bg = bg.scaled(bg.width()*4/5,bg.height());
    this->setBackgroundBrush(bg);
    // Remove btn
    this->removeItem(btn_start);
    this->removeItem(btn_yes);
    this->removeItem(btn_no);
    this->chooseTime->timer->stop();
    this->chooseTime->close();

    // Back
    btn_back = new Btn();
    QPixmap bk;
    bk.load(":/image/img/backbtn.png");
    btn_small_w = bk.width();
    btn_small_h = bk.height();
    bk = bk.scaled(161,86,Qt::KeepAspectRatio);
    btn_back->setPixmap(bk);
    btn_back->setPos(680,510);
    addItem(btn_back);


    // Set the building on it
   ltower1 = new LeftTower();
   ltower2 = new LeftTower();
   lcastle = new LeftCastle();
   rtower1 = new RightTower();
   rtower2 = new RightTower();
   rcastle = new RightCastle();
   QPixmap lbd1,lbd2,lbd3;
   QPixmap rbd1,rbd2,rbd3;
   // Left_Tower_1
   lbd1.load(":/image/img/tower.png");
   lbd1 = lbd1.scaled(lbd1.width()*1/6,lbd1.height()*1/6,Qt::KeepAspectRatio);
   ltower1->setPixmap(lbd1);
   ltower1->setPos(-485,10);
   this->addItem(ltower1);
   // Left_Tower_2
   lbd2.load(":/image/img/tower.png");
   lbd2 = lbd2.scaled(lbd2.width()*1/6,lbd2.height()*1/6,Qt::KeepAspectRatio);
   ltower2->setPixmap(lbd2);
   ltower2->setPos(-485,445);
   this->addItem(ltower2);
   // Left_Castle
   lbd3.load(":/image/img/castle.png");
   lbd3 = lbd3.scaled(lbd3.width()*2/5,lbd3.height()*2/5,Qt::KeepAspectRatio);
   lcastle->setPixmap(lbd3);
   lcastle->setPos(-830,120);
   this->addItem(lcastle);
   // Right_Tower_1
   rbd1.load(":/image/img/tower.png");
   rbd1 = rbd1.scaled(rbd1.width()*1/6,rbd1.height()*1/6,Qt::KeepAspectRatio);
   rtower1->setPixmap(rbd1);
   rtower1->setPos(355,10);
   this->addItem(rtower1);
   // Right_Tower_2
   rbd2.load(":/image/img/tower.png");
   rbd2 = rbd2.scaled(rbd2.width()*1/6,rbd2.height()*1/6,Qt::KeepAspectRatio);
   rtower2->setPixmap(rbd2);
   rtower2->setPos(355,445);
   this->addItem(rtower2);
   // Right_Castle
   rbd3.load(":/image/img/castle2.png");
   rbd3 = rbd3.scaled(rbd3.width()*2/5,rbd3.height()*2/5,Qt::KeepAspectRatio);
   rcastle->setPixmap(rbd3);
   rcastle->setPos(235,120);
   this->addItem(rcastle);

   scoreBoard = new LCDNumber(this,0,10000);
   this->addWidget(scoreBoard);
   scoreBoard->setGeometry(-539,0,150,50);
   scoreBoard->display(rcastle->score);

   ltower1->bar->setGeometry(110,100,100,30);
   ltower1->bar->setWindowTitle("my tower1");
   ltower2->bar->setGeometry(110,550,100,30);
   ltower2->bar->setWindowTitle("my tower2");
   lcastle->bar->setGeometry(20,350,200,30);
   lcastle->bar->setWindowTitle("my castle");
   rtower1->bar->setGeometry(1700,100,100,30);
   rtower1->bar->setWindowTitle("AI's tower1");
   rtower2->bar->setGeometry(1700,550,100,30);
   rtower2->bar->setWindowTitle("AI's tower2");
   rcastle->bar->setGeometry(1700,350,200,30);
   rcastle->bar->setWindowTitle("AI's castle");

   QPalette * palette = new QPalette();
   palette->setColor(QPalette::Highlight,Qt::red);
   ltower1->bar->setPalette(*palette);
   ltower1->bar->setFormat("HP");
   ltower2->bar->setPalette(*palette);
   ltower2->bar->setFormat("HP");
   lcastle->bar->setPalette(*palette);
   lcastle->bar->setFormat("HP");
   rtower1->bar->setPalette(*palette);
   rtower1->bar->setFormat("HP");
   rtower2->bar->setPalette(*palette);
   rtower2->bar->setFormat("HP");
   rcastle->bar->setPalette(*palette);
   rcastle->bar->setFormat("HP");
}

void Scene::bgRecover()
{
    // Remove item
    removeItem(btn_back);
    removeItem(ltower1);
    removeItem(ltower2);
    removeItem(lcastle);
    removeItem(rtower1);
    removeItem(rtower2);
    removeItem(rcastle);

    // Add back initial page
    addItem(btn_start);
    QImage bg;
    bg.load(":/image/img/bg1.png");
    bg = bg.scaled(320,480);
    this->setBackgroundBrush(bg);
}
