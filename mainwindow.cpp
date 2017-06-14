#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"scene.h"
#include"luffy1.h"
#include"zoro1.h"
#include"zoro2.h"
#include"bread1.h"
#include"bread2.h"
#include"curry1.h"
#include"curry2.h"
#include"din1.h"
#include"din2.h"
#include"bo1.h"
#include"bo2.h"
#include"totoro1.h"
#include"lulumi1.h"
#include"lulumi2.h"
#include"tornado.h"
#include"linear.h"
#include"electric.h"
#include"matlab.h"
#include"lens.h"
#include"light.h"
#include"pd2.h"
#include"fog.h"
#include"smalllight.h"
#include"dizzy.h"
#include"bomb.h"
#include"enlarge.h"
#include"door.h"
#include<QString>
#include<QLabel>
#include<QTimer>
#include"drawcards.h"
#include"lcdnumber.h"
#include<QMessageBox>
#include<QtAlgorithms>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene1 = new Scene();
    ui->graphicsView->setScene(scene1);
    scene1->setSceneRect(0,0,300,600);
    settingBg();

    draw = new DrawCards();
    draw->show();
    connect(draw->go,SIGNAL(clicked()),this,SLOT(getRandom()));
    connect(draw->finish,SIGNAL(clicked()),draw,SLOT(accept()));

    rankBoard = new Rank();
    rankBoard->show();
    connect(rankBoard->ok,SIGNAL(clicked()),rankBoard,SLOT(accept()));
    connect(draw,SIGNAL(accepted()),this,SLOT(chooseStart()));

    extra2 = new QWidget();
    extra2->setWindowTitle(tr("More Cards"));
    extra2->setWindowIcon(QPixmap(":/image/img/ball.png"));
    extra2->setGeometry(2000,0,200,900);
    layout2 = new QGridLayout(extra2);
    extra2->setLayout(layout2);
    extra2->show();

    dock = new QDockWidget(this);
    QLabel *label1 = new QLabel("                                                                                                                              Your    Minions", dock);
    label1->setStyleSheet("color: Blue; font-size: 14pt; font-weight: bold; background:rgb(255,255,128);");
    dock->setTitleBarWidget(label1);
    dock->setStyleSheet("QWidget { color:rgb(255,255,128); }");
    btnWidget = new QWidget();
    btnLayout = new QHBoxLayout();
    btnWidget->setLayout(btnLayout);
    dock->setWidget(btnWidget);
    dock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    this->addDockWidget(Qt::BottomDockWidgetArea,dock);


    choose = new QDockWidget(this);
    layout = new QGridLayout();
    allCards = new QWidget();
    allCards->setLayout(layout);
    choose->setWidget(allCards);
    choose->setFeatures(QDockWidget::DockWidgetClosable);
    this->addDockWidget(Qt::TopDockWidgetArea,choose);

    connect(scene1->chooseTime,SIGNAL(isClosed()),this,SLOT(closeChoose()));
    ManageCard();
    //dialog = new Dialog();
    //connect(card_buz,SIGNAL(clicked()),dialog,SLOT(exec()));
    ui->graphicsView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingBg()
{
    QImage bg;
    bg.load(":/image/img/bg1.png");
    bg = bg.scaled(320,480);
    scene1->setBackgroundBrush(bg);
    scene1->Init();
}

void MainWindow::ManageCard()
{
    card_luffy = new QPushButton(choose);
    layout->addWidget(card_luffy,0,0);
    card_luffy->setIcon(QIcon(":/image/img/luffy.png"));
    card_luffy->setIconSize(QSize(120,120));

    card_zoro = new QPushButton(choose);
    layout->addWidget(card_zoro,0,1);
    card_zoro->setIcon(QIcon(":/image/img/zoro1.png"));
    card_zoro->setIconSize(QSize(120,120));

    card_bread = new QPushButton(choose);
    layout->addWidget(card_bread,0,2);
    card_bread->setIcon(QIcon(":/image/img/bread1.png"));
    card_bread->setIconSize(QSize(120,120));

    card_curry = new QPushButton(choose);
    layout->addWidget(card_curry,0,3);
    card_curry->setIcon(QIcon(":/image/img/curry1.png"));
    card_curry->setIconSize(QSize(120,120));

    card_din = new QPushButton(choose);
    layout->addWidget(card_din,0,4);
    card_din->setIcon(QIcon(":/image/img/din1.png"));
    card_din->setIconSize(QSize(120,120));

    card_bo = new QPushButton(choose);
    layout->addWidget(card_bo,0,5);
    card_bo->setIcon(QIcon(":/image/img/bo1.png"));
    card_bo->setIconSize(QSize(120,120));

    card_totoro = new QPushButton(choose);
    layout->addWidget(card_totoro,0,6);
    card_totoro->setIcon(QIcon(":/image/img/totoro.png"));
    card_totoro->setIconSize(QSize(120,120));

    card_lulumi = new QPushButton(choose);
    layout->addWidget(card_lulumi,0,7);
    card_lulumi->setIcon(QIcon(":/image/img/lulumi1.png"));
    card_lulumi->setIconSize(QSize(120,120));

    card_pd2= new QPushButton(choose);
    layout->addWidget(card_pd2,1,6,2,2);
    card_pd2->setIcon(QIcon(":/image/img/hero.png"));
    card_pd2->setIconSize(QSize(360,145));

    card_linear = new QPushButton(choose);
    layout->addWidget(card_linear,1,0);
    card_linear->setIcon(QIcon(":/image/img/linear.png"));
    card_linear->setIconSize(QSize(120,120));

    card_electric = new QPushButton(choose);
    layout->addWidget(card_electric,1,1);
    card_electric->setIcon(QIcon(":/image/img/electric.png"));
    card_electric->setIconSize(QSize(120,120));

    card_matlab = new QPushButton(choose);
    layout->addWidget(card_matlab,1,2);
    card_matlab->setIcon(QIcon(":/image/img/matlab.png"));
    card_matlab->setIconSize(QSize(120,120));

    card_lens = new QPushButton(choose);
    layout->addWidget(card_lens,1,3);
    card_lens->setIcon(QIcon(":/image/img/lens.png"));
    card_lens->setIconSize(QSize(120,120));

    card_light = new QPushButton(choose);
    layout->addWidget(card_light,1,4,2,2);
    card_light->setIcon(QIcon(":/image/img/light.png"));
    card_light->setIconSize(QSize(360,145));

    card_tornado = new QPushButton(choose);
    layout2->addWidget(card_tornado,0,0);
    card_tornado->setIcon(QIcon(":/image/img/tornado.png"));
    card_tornado->setIconSize(QSize(120,110));

    card_fog = new QPushButton(choose);
    layout2->addWidget(card_fog,1,0);
    card_fog->setIcon(QIcon(":/image/img/fog.png"));
    card_fog->setIconSize(QSize(120,110));

    card_smallLight = new QPushButton(choose);
    layout2->addWidget(card_smallLight,2,0);
    card_smallLight->setIcon(QIcon(":/image/img/small.png"));
    card_smallLight->setIconSize(QSize(120,110));

    card_dizzy= new QPushButton(choose);
    layout2->addWidget(card_dizzy,3,0);
    card_dizzy->setIcon(QIcon(":/image/img/dizzy.png"));
    card_dizzy->setIconSize(QSize(120,110));

    card_bomb= new QPushButton(choose);
    layout2->addWidget(card_bomb,4,0);
    card_bomb->setIcon(QIcon(":/image/img/bomb.png"));
    card_bomb->setIconSize(QSize(120,110));

    card_enlarge= new QPushButton(choose);
    layout2->addWidget(card_enlarge,5,0);
    card_enlarge->setIcon(QIcon(":/image/img/enlarge.png"));
    card_enlarge->setIconSize(QSize(120,100));

    card_door= new QPushButton(choose);
    layout2->addWidget(card_door,6,0);
    card_door->setIcon(QIcon(":/image/img/door.png"));
    card_door->setIconSize(QSize(120,110));

    QPalette* palette1 = new QPalette();
    palette1->setColor(QPalette::Button,QColor(0,255,0));
    card_pd2->setPalette(*palette1);
    card_linear->setPalette(*palette1);
    card_electric->setPalette(*palette1);
    card_matlab->setPalette(*palette1);
    card_lens->setPalette(*palette1);
    card_light->setPalette(*palette1);

    QPalette* palette2 = new QPalette();
    palette2->setColor(QPalette::Button,QColor(60,255,255));
    card_luffy->setPalette(*palette2);
    card_zoro->setPalette(*palette2);
    card_bread->setPalette(*palette2);
    card_curry->setPalette(*palette2);
    card_din->setPalette(*palette2);
    card_bo->setPalette(*palette2);
    card_totoro->setPalette(*palette2);
    card_lulumi->setPalette(*palette2);

    QPalette* palette3 = new QPalette();
    palette3->setColor(QPalette::Button,QColor(255,0,51));
    card_tornado->setPalette(*palette3);
    card_fog->setPalette(*palette3);
    card_smallLight->setPalette(*palette3);
    card_dizzy->setPalette(*palette3);
    card_bomb->setPalette(*palette3);
    card_enlarge->setPalette(*palette3);
    card_door->setPalette(*palette3);

}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    luffy = false;
    zoro = false;
    bread = false;
    curry = false;
    din = false;
    bo = false;
    totoro = false;
    lulumi = false;
    linear = false;
    electric = false;
    matlab = false;
    lens = false;
    light = false;
    pd2 = false;
    tornado = false;
    fog = false;
    smallLight = false;
    dizzy = false;
    bomb = false;
    enlarge = false;
    door = false;

    connect(card_luffy,SIGNAL(clicked()),this,SLOT(set1()));
    connect(card_zoro,SIGNAL(clicked()),this,SLOT(set2()));
    connect(card_bread,SIGNAL(clicked()),this,SLOT(set3()));
    connect(card_curry,SIGNAL(clicked()),this,SLOT(set4()));
    connect(card_din,SIGNAL(clicked()),this,SLOT(set5()));
    connect(card_bo,SIGNAL(clicked()),this,SLOT(set6()));
    connect(card_totoro,SIGNAL(clicked()),this,SLOT(set7()));
    connect(card_lulumi,SIGNAL(clicked()),this,SLOT(set8()));
    connect(card_pd2,SIGNAL(clicked()),this,SLOT(set9()));
    connect(card_linear,SIGNAL(clicked()),this,SLOT(set10()));
    connect(card_electric,SIGNAL(clicked()),this,SLOT(set11()));
    connect(card_matlab,SIGNAL(clicked()),this,SLOT(set12()));
    connect(card_lens,SIGNAL(clicked()),this,SLOT(set13()));
    connect(card_light,SIGNAL(clicked()),this,SLOT(set14()));

    connect(card_luffy,SIGNAL(pressed()),this,SLOT(create1_1()));
    connect(card_zoro,SIGNAL(pressed()),this,SLOT(create1_2()));
    connect(card_bread,SIGNAL(pressed()),this,SLOT(create1_3()));
    connect(card_curry,SIGNAL(pressed()),this,SLOT(create1_4()));
    connect(card_din,SIGNAL(pressed()),this,SLOT(create1_5()));
    connect(card_bo,SIGNAL(pressed()),this,SLOT(create1_6()));
    connect(card_totoro,SIGNAL(pressed()),this,SLOT(create1_7()));
    connect(card_lulumi,SIGNAL(pressed()),this,SLOT(create1_8()));
    connect(card_linear,SIGNAL(pressed()),this,SLOT(create1_9()));
    connect(card_electric,SIGNAL(pressed()),this,SLOT(create1_10()));
    connect(card_matlab,SIGNAL(pressed()),this,SLOT(create1_11()));
    connect(card_lens,SIGNAL(pressed()),this,SLOT(create1_12()));
    connect(card_light,SIGNAL(pressed()),this,SLOT(create1_13()));
    connect(card_pd2,SIGNAL(pressed()),this,SLOT(create1_14()));
    connect(card_tornado,SIGNAL(pressed()),this,SLOT(create1_15()));
    connect(card_fog,SIGNAL(pressed()),this,SLOT(create1_16()));
    connect(card_smallLight,SIGNAL(pressed()),this,SLOT(create1_17()));
    connect(card_dizzy,SIGNAL(pressed()),this,SLOT(create1_18()));
    connect(card_bomb,SIGNAL(pressed()),this,SLOT(create1_19()));
    connect(card_enlarge,SIGNAL(pressed()),this,SLOT(create1_20()));
    connect(card_door,SIGNAL(pressed()),this,SLOT(create1_21()));
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(luffy==true)
    {
       Luffy1 * luffy1 = new Luffy1();
       luffy1->setPos(event->pos().x()-600,event->pos().y()-70);
       scene1->addItem(luffy1);
       btnLayout->addWidget(card_luffy);
       scene1->rcastle->score-=3;
       scene1->scoreBoard->display(scene1->rcastle->score);
       luffy = false;
    }
    if(zoro==true)
    {
       Zoro1 * zoro1 = new Zoro1();
       zoro1->setPos(event->pos().x()-600,event->pos().y()-70);
       scene1->addItem(zoro1);
       btnLayout->addWidget(card_zoro);
       scene1->rcastle->score-=3;
       scene1->scoreBoard->display(scene1->rcastle->score);
       zoro = false;
    }
    if(bread==true)
    {
       Bread1 * bread1 = new Bread1();
       bread1->setPos(event->pos().x()-600,event->pos().y()-70);
       scene1->addItem(bread1);
       btnLayout->addWidget(card_bread);
       scene1->rcastle->score-=3;
       scene1->scoreBoard->display(scene1->rcastle->score);
       bread = false;
    }
    if(curry==true)
    {
       Curry1 * curry1 = new Curry1();
       curry1->setPos(event->pos().x()-600,event->pos().y()-70);
       scene1->addItem(curry1);
       btnLayout->addWidget(card_curry);
       scene1->rcastle->score-=3;
       scene1->scoreBoard->display(scene1->rcastle->score);
       curry = false;
    }
    if(din==true)
    {
       Din1 * din1 = new Din1();
       din1->setPos(event->pos().x()-600,event->pos().y()-70);
       scene1->addItem(din1);
       btnLayout->addWidget(card_din);
       scene1->rcastle->score-=2;
       scene1->scoreBoard->display(scene1->rcastle->score);
       din = false;
    }
    if(bo==true)
    {
       Bo1 * bo1 = new Bo1();
       bo1->setPos(event->pos().x()-600,event->pos().y()-70);
       scene1->addItem(bo1);
       btnLayout->addWidget(card_bo);
       scene1->rcastle->score-=2;
       scene1->scoreBoard->display(scene1->rcastle->score);
       bo = false;
    }
    if(totoro==true)
    {
       Totoro1 * totoro1 = new Totoro1();
       totoro1->setPos(event->pos().x()-600,event->pos().y()-70);
       scene1->addItem(totoro1);
       btnLayout->addWidget(card_totoro);
       scene1->rcastle->score-=4;
       scene1->scoreBoard->display(scene1->rcastle->score);
       totoro = false;
    }
    if(lulumi==true)
    {
       Lulumi1 * lulumi1 = new Lulumi1();
       lulumi1->setPos(event->pos().x()-600,event->pos().y()-70);
       scene1->addItem(lulumi1);
       btnLayout->addWidget(card_lulumi);
       scene1->rcastle->score-=4;
       scene1->scoreBoard->display(scene1->rcastle->score);
       lulumi = false;
    }
    if(linear==true)
    {
       Linear * linear1 = new Linear();
       linear1->setPos(event->pos().x()-600,event->pos().y()-90);
       scene1->addItem(linear1);
       btnLayout->addWidget(card_linear);
       scene1->rcastle->score-=5;
       scene1->scoreBoard->display(scene1->rcastle->score);
       linear = false;
    }
    if(electric==true)
    {
       Electric * electric1 = new Electric();
       electric1->setPos(event->pos().x()-600,event->pos().y()-90);
       scene1->addItem(electric1);
       btnLayout->addWidget(card_electric);
       scene1->rcastle->score-=5;
       scene1->scoreBoard->display(scene1->rcastle->score);
       electric = false;
    }
    if(matlab==true)
    {
       Matlab * matlab1 = new Matlab();
       matlab1->setPos(event->pos().x()-600,event->pos().y()-90);
       scene1->addItem(matlab1);
       btnLayout->addWidget(card_matlab);
       scene1->rcastle->score-=5;
       scene1->scoreBoard->display(scene1->rcastle->score);
       matlab = false;
    }
    if(lens==true)
    {
       Lens * lens1 = new Lens();
       lens1->setPos(event->pos().x()-600,event->pos().y()-90);
       scene1->addItem(lens1);
       btnLayout->addWidget(card_lens);
       scene1->rcastle->score-=5;
       scene1->scoreBoard->display(scene1->rcastle->score);
       lens = false;
    }
    if(light==true)
    {
       Light * light1 = new Light();
       light1->setFlag(QGraphicsItem::ItemIsFocusable);
       light1->setFocus();
       light1->setPos(event->pos().x()-600,event->pos().y()-90);
       scene1->addItem(light1);
       btnLayout->addWidget(card_light);
       scene1->rcastle->score-=5;
       scene1->scoreBoard->display(scene1->rcastle->score);
       light = false;
    }
    if(pd2==true)
    {
       PD2 * pd21 = new PD2();
       pd21->setFlag(QGraphicsItem::ItemIsFocusable);
       pd21->setFocus();
       pd21->setPos(event->pos().x()-600,event->pos().y()-80);
       scene1->addItem(pd21);
       scene1->rcastle->score-=8;
       scene1->scoreBoard->display(scene1->rcastle->score);
       pd2 = false;
    }
    if(tornado==true)
    {
       Tornado * tornado1 = new Tornado();
       tornado1->setPos(event->pos().x()-650,event->pos().y()-70);
       scene1->addItem(tornado1);
       btnLayout->addWidget(card_tornado);
       scene1->rcastle->score-=6;
       scene1->scoreBoard->display(scene1->rcastle->score);
       tornado = false;
    }
    if(fog==true)
    {
       Fog * fog1 = new Fog();
       fog1->setPos(event->pos().x()-800,event->pos().y()-300);
       scene1->addItem(fog1);
       btnLayout->addWidget(card_fog);
       scene1->rcastle->score-=6;
       scene1->scoreBoard->display(scene1->rcastle->score);
       fog = false;
    }
    if(smallLight==true)
    {
       SmallLight * smalllight1 = new SmallLight();
       smalllight1->setPos(event->pos().x()-650,event->pos().y()-70);
       scene1->addItem(smalllight1);
       btnLayout->addWidget(card_smallLight);
       scene1->rcastle->score-=6;
       scene1->scoreBoard->display(scene1->rcastle->score);
       smallLight = false;
    }
    if(dizzy==true)
    {
       Dizzy* dizzy1 = new Dizzy();
       dizzy1->setPos(event->pos().x()-650,event->pos().y()-70);
       scene1->addItem(dizzy1);
       btnLayout->addWidget(card_dizzy);
       scene1->rcastle->score-=6;
       scene1->scoreBoard->display(scene1->rcastle->score);
       dizzy= false;
    }
    if(bomb==true)
    {
       Bomb * bomb1 = new Bomb();
       bomb1->setPos(event->pos().x()-650,event->pos().y()-70);
       scene1->addItem(bomb1);
       btnLayout->addWidget(card_bomb);
       scene1->rcastle->score-=6;
       scene1->scoreBoard->display(scene1->rcastle->score);
       bomb= false;
    }
    if(enlarge==true)
    {
       Enlarge * enlarge1 = new Enlarge();
       enlarge1->setPos(event->pos().x()-650,event->pos().y()-70);
       scene1->addItem(enlarge1);
       btnLayout->addWidget(card_enlarge);
       scene1->rcastle->score-=6;
       scene1->scoreBoard->display(scene1->rcastle->score);
       enlarge= false;
    }
    if(door==true)
    {
       Door * door1 = new Door();
       door1->setPos(event->pos().x()-650,event->pos().y()-70);
       scene1->addItem(door1);
       btnLayout->addWidget(card_door);
       scene1->rcastle->score-=6;
       scene1->scoreBoard->display(scene1->rcastle->score);
       door= false;
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    connect(card_luffy,SIGNAL(clicked()),this,SLOT(recover1()));
    connect(card_zoro,SIGNAL(clicked()),this,SLOT(recover2()));
    connect(card_bread,SIGNAL(clicked()),this,SLOT(recover3()));
    connect(card_curry,SIGNAL(clicked()),this,SLOT(recover4()));
    connect(card_din,SIGNAL(clicked()),this,SLOT(recover5()));
    connect(card_bo,SIGNAL(clicked()),this,SLOT(recover6()));
    connect(card_totoro,SIGNAL(clicked()),this,SLOT(recover7()));
    connect(card_lulumi,SIGNAL(clicked()),this,SLOT(recover8()));
    connect(card_pd2,SIGNAL(clicked()),this,SLOT(recover9()));
    connect(card_linear,SIGNAL(clicked()),this,SLOT(recover10()));
    connect(card_electric,SIGNAL(clicked()),this,SLOT(recover11()));
    connect(card_matlab,SIGNAL(clicked()),this,SLOT(recover12()));
    connect(card_lens,SIGNAL(clicked()),this,SLOT(recover13()));
    connect(card_light,SIGNAL(clicked()),this,SLOT(recover14()));
}

void MainWindow::create1_1(){   luffy= true;    }
void MainWindow::create1_2(){   zoro = true;   }
void MainWindow::create1_3(){   bread = true;   }
void MainWindow::create1_4(){   curry = true;   }
void MainWindow::create1_5(){   din = true; }
void MainWindow::create1_6(){   bo = true;  }
void MainWindow::create1_7(){   totoro = true;   }
void MainWindow::create1_8(){   lulumi = true;   }
void MainWindow::create1_9(){   linear = true;  }
void MainWindow::create1_10(){   electric = true;  }
void MainWindow::create1_11(){   matlab = true;  }
void MainWindow::create1_12(){   lens = true;  }
void MainWindow::create1_13(){   light = true;  }
void MainWindow::create1_14(){   pd2 = true;  }
void MainWindow::create1_15(){  tornado = true;    }
void MainWindow::create1_16(){  fog = true;    }
void MainWindow::create1_17(){  smallLight = true;    }
void MainWindow::create1_18(){  dizzy = true;    }
void MainWindow::create1_19(){  bomb = true;    }
void MainWindow::create1_20(){  enlarge = true;    }
void MainWindow::create1_21(){  door = true;    }

void MainWindow::set1(){    btnLayout->addWidget(card_luffy);   luffy = false;   }
void MainWindow::set2(){    btnLayout->addWidget(card_zoro);   zoro = false;    }
void MainWindow::set3(){    btnLayout->addWidget(card_bread);   bread = false;   }
void MainWindow::set4(){    btnLayout->addWidget(card_curry);   curry = false;   }
void MainWindow::set5(){    btnLayout->addWidget(card_din);   din = false;    }
void MainWindow::set6(){    btnLayout->addWidget(card_bo);   bo = false;    }
void MainWindow::set7(){    btnLayout->addWidget(card_totoro);   totoro = false;   }
void MainWindow::set8(){    btnLayout->addWidget(card_lulumi);   lulumi = false;    }
void MainWindow::set9(){    btnLayout->addWidget(card_pd2);   pd2= false;    }
void MainWindow::set10(){    btnLayout->addWidget(card_linear);   linear = false;  }
void MainWindow::set11(){    btnLayout->addWidget(card_electric);   electric = false;  }
void MainWindow::set12(){    btnLayout->addWidget(card_matlab);   matlab = false;  }
void MainWindow::set13(){    btnLayout->addWidget(card_lens);   lens = false;  }
void MainWindow::set14(){    btnLayout->addWidget(card_light);   light = false;  }

void MainWindow::recover1(){    layout->addWidget(card_luffy,0,0);  }
void MainWindow::recover2(){    layout->addWidget(card_zoro,0,1);  }
void MainWindow::recover3(){    layout->addWidget(card_bread,0,2);  }
void MainWindow::recover4(){    layout->addWidget(card_curry,0,3);  }
void MainWindow::recover5(){    layout->addWidget(card_din,0,4);  }
void MainWindow::recover6(){    layout->addWidget(card_bo,0,5);  }
void MainWindow::recover7(){    layout->addWidget(card_totoro,0,6);  }
void MainWindow::recover8(){    layout->addWidget(card_lulumi,0,7);  }
void MainWindow::recover9(){    layout->addWidget(card_pd2,1,6,2,2);  }
void MainWindow::recover10(){    layout->addWidget(card_linear,1,0);  }
void MainWindow::recover11(){    layout->addWidget(card_electric,1,1);  }
void MainWindow::recover12(){    layout->addWidget(card_matlab,1,2);  }
void MainWindow::recover13(){    layout->addWidget(card_lens,1,3);  }
void MainWindow::recover14(){    layout->addWidget(card_light,1,4,2,2);  }

void MainWindow::closeChoose()
{
    choose->close();
    scene1->chooseTime->close();
    extra2->close();
}

void MainWindow::getRandom()
{
    number = random()%7+1;
    draw->card->display(number);
    draw->card->setDigitCount(2);
    draw->money-=50;
    draw->label3->setText(QString::number(draw->money));
    if(draw->money==0)
    {
        disconnect(draw->go,SIGNAL(clicked()),this,SLOT(getRandom()));
    }
    if(number==1)   btnLayout->addWidget(card_tornado);
    if(number==2)   btnLayout->addWidget(card_fog);
    if(number==3)   btnLayout->addWidget(card_smallLight);
    if(number==4)   btnLayout->addWidget(card_dizzy);
    if(number==5)  btnLayout->addWidget(card_bomb);
    if(number==6)   btnLayout->addWidget(card_enlarge);
    if(number==7)   btnLayout->addWidget(card_door);
}

void MainWindow::chooseStart()
{
    scene1->chooseTime->timer3->start(1000);
    extra2->close();
}

/*void MainWindow::popup()
{
    QMessageBox * box = new QMessageBox();
    box->setText("test");
}*/

