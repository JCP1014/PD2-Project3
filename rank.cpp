#include "rank.h"
#include<QPixmap>
#include<QPainter>
#include<QLabel>
#include"iostream"
#include"fstream"
#include"QFont"


Rank::Rank(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("Rank Board"));
    setWindowIcon(QPixmap(":/image/img/rank.png"));
    QLabel * label = new QLabel(this);
    label->setPixmap(QPixmap(":/image/img/rank.png"));
    label->setGeometry(25,0,530,680);
    ok = new QPushButton(this);
    ok->setText(tr("OK"));
    ok->setFont(QFont("Purisa",30));
    ok->setGeometry(438,580,110,70);
    QPalette * palette = new QPalette();
    palette->setColor(QPalette::Button,QColor(185,62,0));
    ok->setPalette(*palette);
    setModal(true);
    sort();
    score1 = list[0];
    blank1 = new QLCDNumber(this);
    blank1->display(score1);
    blank1->setGeometry(350,55,150,50);
    blank1->setSegmentStyle(QLCDNumber::Flat);
    blank1->setStyleSheet("border: 0.1px dashed solid rgb(105,14,0); color: rgb(105,14,0);");
    blank1->setDigitCount(5);
    score2 = list[1];
    blank2 = new QLCDNumber(this);
    blank2->display(score2);
    blank2->setGeometry(350,145,150,50);
    blank2->setSegmentStyle(QLCDNumber::Flat);
    blank2->setStyleSheet("border: 0.1px dashed solid rgb(105,14,0); color: rgb(105,14,0);");
    blank2->setDigitCount(5);
    score3 = list[2];
    blank3 = new QLCDNumber(this);
    blank3->display(score3);
    blank3->setGeometry(350,245,150,50);
    blank3->setSegmentStyle(QLCDNumber::Flat);
    blank3->setStyleSheet("border: 0.1px dashed solid rgb(105,14,0); color: rgb(105,14,0);");
    blank3->setDigitCount(5);
    score4 = list[3];
    blank4 = new QLCDNumber(this);
    blank4->display(score4);
    blank4->setGeometry(350,340,150,50);
    blank4->setSegmentStyle(QLCDNumber::Flat);
    blank4->setStyleSheet("border: 0.1px dashed solid rgb(105,14,0); color: rgb(105,14,0);");
    blank4->setDigitCount(5);
    score5 = list[4];
    blank5 = new QLCDNumber(this);
    blank5->display(score5);
    blank5->setGeometry(350,425,150,50);
    blank5->setSegmentStyle(QLCDNumber::Flat);
    blank5->setStyleSheet("border: 0.1px dashed solid rgb(105,14,0); color: rgb(105,14,0);");
    blank5->setDigitCount(5);

    QLabel * label1 = new QLabel(this);
    label1->setText(tr("No.1"));
    label1->setFont(QFont("Purisa",35));
    label1->setGeometry(80,55,150,50);
    QLabel * label2 = new QLabel(this);
    label2->setText(tr("No.2"));
    label2->setFont(QFont("Purisa",35));
    label2->setGeometry(80,145,150,50);
    QLabel * label3 = new QLabel(this);
    label3->setText(tr("No.3"));
    label3->setFont(QFont("Purisa",35));
    label3->setGeometry(80,245,150,50);
    QLabel * label4 = new QLabel(this);
    label4->setText(tr("No.4"));
    label4->setFont(QFont("Purisa",35));
    label4->setGeometry(80,340,150,50);
    QLabel * label5 = new QLabel(this);
    label5->setText(tr("No.5"));
    label5->setFont(QFont("Purisa",35));
    label5->setGeometry(80,425,150,50);
}

void Rank::sort()
{
    std::ifstream inFile("file.out",std::ios::in);
    for(int i=0;i<10000;++i)
     {
        if(!inFile.eof())
        {
            inFile >> score[i];
            list.push_back(score[i]);
         }
     }
     qSort(list.begin(),list.end(),qGreater<int>());
}
