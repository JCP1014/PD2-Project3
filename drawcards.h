#ifndef DRAWCARDS_H
#define DRAWCARDS_H

#include <QDialog>
#include<QPushButton>
#include<QGridLayout>
#include<QLCDNumber>
#include<QLabel>

class DrawCards : public QDialog
{
    Q_OBJECT
public:
    DrawCards(QWidget *parent = 0);
    QLCDNumber * card;
    QPushButton *go;
    QPushButton *finish;
    int money;
    QLabel *label3;
private:
    QGridLayout *layout;
};

#endif // DRAWCARDS_H
