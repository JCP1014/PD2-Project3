#ifndef DRAWCARDS_H
#define DRAWCARDS_H

#include <QDialog>
#include<QPushButton>
#include<QGridLayout>
#include<QFrame>
#include<QLCDNumber>

class DrawCards : public QDialog
{
    Q_OBJECT
public:
    DrawCards(QWidget *parent = 0);
    QLCDNumber * card;
    QPushButton *go;
    QPushButton *finish;
private:
    QGridLayout *layout;
    QFrame * frame;

};

#endif // DRAWCARDS_H
