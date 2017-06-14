#include "drawcards.h"
#include<QPixmap>
#include<QPainter>
#include<QLabel>
#include"stdlib.h"

DrawCards::DrawCards(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("Draw  Cards"));
    setWindowIcon(QPixmap(":/image/img/gacha.png"));
    layout = new QGridLayout(this);
    QLabel * label1 = new QLabel();
    label1->setPixmap(QPixmap(":/image/img/gacha.png"));
    layout->addWidget(label1,0,0,6,2);
    money = 150;
    QLabel * label2 = new QLabel();
    label2->setText(tr("Money: "));
   QFont ft1;
   ft1.setPointSize(15);
    label2->setFont(ft1);
    layout->addWidget(label2,6,3,2,1);
    label3 = new QLabel();
    label3->setText(QString::number(money));
    label3->setFont(QFont("Purisa",25));
    layout->addWidget(label3,6,4,2,1);
    QLabel * label4 = new QLabel();
    label4->setPixmap(QPixmap(":/image/img/coins.png"));
    layout->addWidget(label4,6,1,2,2);
    go = new QPushButton(this);
    go->setText(tr("Go!"));
    finish = new QPushButton(this);
    finish->setText(tr("Finish!"));
    layout->addWidget(go,8,3,1,1);
    layout->addWidget(finish,8,4,1,1);
    setModal(true);

    card = new QLCDNumber(this);
    card->setDigitCount(2);
    card->setSegmentStyle(QLCDNumber::Flat);
    card->setStyleSheet("border: 3px dashed rgb(113,191,255); color: rgb(255,89,0); background: rgb(252,219,222);");
    layout->addWidget(card,0,3,6,2);
}
