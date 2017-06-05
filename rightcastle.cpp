#include "rightcastle.h"
#include<QPixmap>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include"arrow.h"
#include<QLineF>
#include"scene.h"
#include<QGraphicsScene>
#include<QTimer>
#include"arrow.h"
#include"scene.h"
#include"luffy1.h"
#include"zoro1.h"
#include"bread1.h"
#include"curry1.h"
#include"din1.h"
#include"bo1.h"
#include"totoro1.h"
#include"lulumi1.h"
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"bo2.h"
#include"totoro2.h"
#include"lulumi2.h"
#include"dialog.h"
#include<QMessageBox>
#include<QMediaPlayer>
#include<QMediaPlaylist>

RightCastle::RightCastle(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    hp = 50;
    bar = new QProgressBar();
    bar->setValue(hp/50*100);
    bar->show();
    // Create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3) << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // Scale points
    int SCALE_FACTOR = 100;
    for(size_t i=0,n=points.size();i<n;++i )
        points[i] *= SCALE_FACTOR;

    // Create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->QAbstractGraphicsShapeItem::setPen(QPen(Qt::transparent));

    //Move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+400,y()+175);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    QTimer * timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer1->start(900);
    QTimer * timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(blood()));
    timer2->start(1000);
    QTimer * timer3 = new QTimer();
    connect(timer3,SIGNAL(timeout()),this,SLOT(create2_1()));
    timer3->start(3000);
    QTimer * timer4 = new QTimer();
    connect(timer4,SIGNAL(timeout()),this,SLOT(create2_2()));
    timer4->start(13000);
    QTimer * timer5 = new QTimer();
    connect(timer5,SIGNAL(timeout()),this,SLOT(create2_3()));
    timer5->start(5000);
    QTimer * timer6 = new QTimer();
    connect(timer6,SIGNAL(timeout()),this,SLOT(create2_4()));
    timer6->start(11000);
    QTimer * timer7 = new QTimer();
    connect(timer7,SIGNAL(timeout()),this,SLOT(create2_5()));
    timer7->start(9000);
    QTimer * timer8 = new QTimer();
    connect(timer8,SIGNAL(timeout()),this,SLOT(create2_6()));
    timer8->start(7000);
    QTimer * timer9 = new QTimer();
    connect(timer9,SIGNAL(timeout()),this,SLOT(create2_7()));
    timer9->start(15000);
    QTimer * timer10 = new QTimer();
    connect(timer10,SIGNAL(timeout()),this,SLOT(create2_8()));
    timer10->start(17000);

    damagedsound = new QMediaPlayer();
    damagedsound->setMedia(QUrl("qrc:/sound/snd/Punch.mp3"));
    damagedsound->setVolume(50);

    destroyedsound = new QMediaPlayer();
    destroyedsound->setMedia(QUrl("qrc:/sound/snd/destroy.mp3"));
    destroyedsound->setVolume(500);

    swordsound = new QMediaPlayer();
    swordsound->setMedia(QUrl("qrc:/sound/snd/sword.mp3"));
    swordsound->setVolume(250);

}

double RightCastle::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void RightCastle::attack()
{
    Arrow * arrow = new Arrow();
    arrow->setPos(x()+400,y()+175);

    QLineF ln(QPointF(x()+400,y()+175),QPointF(attack_destn.x()+50,attack_destn.y()+50));
    int angle = ln.angle();

    arrow->setRotation(-angle);
    this->scene()->addItem(arrow);
 }

void RightCastle::acquire_target()
{
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();
    if(colliding_items.size()<=4)
    {
        has_target = false;
        return;
    }

    double closest_dist =500;
    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Luffy1 * luffy1 = dynamic_cast<Luffy1 *>(colliding_items[i]);
        if(luffy1)
        {
            double this_dist = distanceTo(luffy1);
            if(this_dist<closest_dist)
            {
                closest_dist = this_dist;
                closest_pos = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Zoro1 * zoro1 = dynamic_cast<Zoro1 *>(colliding_items[i]);
        {
            if(zoro1)
            {
                double this_dist = distanceTo(zoro1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Bread1 * bread1 = dynamic_cast<Bread1 *>(colliding_items[i]);
        {
            if(bread1)
            {
                double this_dist = distanceTo(bread1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Curry1 * curry1 = dynamic_cast<Curry1 *>(colliding_items[i]);
        {
            if(curry1)
            {
                double this_dist = distanceTo(curry1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Din1 * din1 = dynamic_cast<Din1 *>(colliding_items[i]);
        {
            if(din1)
            {
                double this_dist = distanceTo(din1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Bo1 * bo1 = dynamic_cast<Bo1 *>(colliding_items[i]);
        {
            if(bo1)
            {
                double this_dist = distanceTo(bo1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Totoro1 * totoro1 = dynamic_cast<Totoro1 *>(colliding_items[i]);
        {
            if(totoro1)
            {
                double this_dist = distanceTo(totoro1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Lulumi1 * lulumi1 = dynamic_cast<Lulumi1 *>(colliding_items[i]);
        {
            if(lulumi1)
            {
                double this_dist = distanceTo(lulumi1);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();
}

void RightCastle::blood()
{
    QList<QGraphicsItem *> reaching_items = this->collidingItems();
    if(reaching_items.size()<=1)
    {
        damaged = false;
        return;
    }
    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Luffy1 * luffy1 = dynamic_cast<Luffy1 *>(reaching_items[i]);
        if(luffy1)
        {
            hp -= 3;
            bar->setValue(hp*2);
            damagedsound->play();
        }
    }
    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Zoro1 * zoro1 = dynamic_cast<Zoro1 *>(reaching_items[i]);
        if(zoro1)
        {
            hp -= 3;
            bar->setValue(hp*2);
            swordsound->play();
        }
    }
    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Bread1 * bread1 = dynamic_cast<Bread1 *>(reaching_items[i]);
        if(bread1)
        {
            hp -= 4;
            bar->setValue(hp*2);
            damagedsound->play();
        }
    }
    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Curry1 * curry1 = dynamic_cast<Curry1 *>(reaching_items[i]);
        if(curry1)
        {
            hp -= 4;
            bar->setValue(hp*2);
            damagedsound->play();
        }
    }
    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Din1 * din1 = dynamic_cast<Din1 *>(reaching_items[i]);
        if(din1)
        {
            hp -= 2;
            bar->setValue(hp*2);
            damagedsound->play();
        }
    }
    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Totoro1 * totoro1 = dynamic_cast<Totoro1 *>(reaching_items[i]);
        if(totoro1)
        {
            hp -= 5;
            bar->setValue(hp*2);
            damagedsound->play();
        }
    }
    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Lulumi1 * lulumi1 = dynamic_cast<Lulumi1 *>(reaching_items[i]);
        if(lulumi1)
        {
            hp -= 4;
            bar->setValue(hp*2);
            damagedsound->play();
        }
    }

    if(hp<=0)
    {
        bar->setValue(hp*2);
        destroyedsound->play();
        scene()->removeItem(this);
        QMessageBox * msg = new QMessageBox();
        msg->setIconPixmap(QPixmap(":/image/img/win.png"));
        msg->setWindowIcon(QPixmap(":/image/img/win_icon.png"));
        msg->setWindowTitle("Game Result");
        msg->setText("Congratulations !");
        msg->setInformativeText("You Win !");
        msg->setStandardButtons(QMessageBox::Ok);
        msg->show();
        QMediaPlaylist * playlist = new QMediaPlaylist();
        playlist->addMedia(QUrl("qrc:/sound/snd/win.mp3"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        QMediaPlayer * music = new QMediaPlayer();
        music->setPlaylist(playlist);
        music->play();
        delete this;
        return;
    }
}

void RightCastle::create2_1(){   Luffy2 * luffy2 = new Luffy2();  scene()->addItem(luffy2);    }
void RightCastle::create2_2(){   Zoro2 * zoro2 = new Zoro2();  scene()->addItem(zoro2);    }
void RightCastle::create2_3(){   Bread2 * bread2 = new Bread2();  scene()->addItem(bread2);    }
void RightCastle::create2_4(){   Curry2 * curry2 = new Curry2();  scene()->addItem(curry2);    }
void RightCastle::create2_5(){   Din2 * din2 = new Din2();  scene()->addItem(din2);    }
void RightCastle::create2_6(){   Bo2 * bo2 = new Bo2();  scene()->addItem(bo2);    }
void RightCastle::create2_7(){   Totoro2 * totoro2 = new Totoro2();  scene()->addItem(totoro2);    }
void RightCastle::create2_8(){   Lulumi2 * lulumi2 = new Lulumi2();  scene()->addItem(lulumi2);    }

