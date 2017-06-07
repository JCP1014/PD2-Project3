#include "drawcards.h"
#include<QPixmap>
#include<QPainter>
#include<QLabel>
#include"stdlib.h"

DrawCards::DrawCards(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("Draw  Cards"));
    setWindowIcon(QPixmap(":/image/img/gacha.png"));
    QLabel * label = new QLabel();
    label->setPixmap(QPixmap(":/image/img/gacha.png"));
    layout = new QGridLayout(this);
    layout->addWidget(label,0,0,2,1);
    go = new QPushButton(this);
    go->setText(tr("Go!"));
    finish = new QPushButton(this);
    finish->setText(tr("Finish!"));
    layout->addWidget(go,1,1,1,1);
    layout->addWidget(finish,1,2,1,1);
    setModal(true);

    card = new QLCDNumber(this);
    card->setSegmentStyle(QLCDNumber::Flat);
    card->setStyleSheet("border: 3px dashed rgb(113,191,255); color: rgb(255,89,0); background: rgb(252,219,222);");
    layout->addWidget(card,0,1,1,2);
}
