#ifndef RANK_H
#define RANK_H

#include <QDialog>
#include<QPushButton>
#include<QLCDNumber>
#include<QList>
#include<QtAlgorithms>

class Rank : public QDialog
{
    Q_OBJECT
public:
    Rank(QWidget *parent = 0);
    QPushButton * ok;
    void sort();

private:
    QLCDNumber * blank1,* blank2,* blank3,* blank4,* blank5;
    int  score1, score2, score3, score4, score5;
    QList<int>list;
    int score[10000];
};

#endif // RANK_H
