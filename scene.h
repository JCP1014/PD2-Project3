#ifndef SCENE_H
#define SCENE_H

#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QMouseEvent>
#include<QGraphicsView>
#include "btn.h"
#include"lefttower.h"
#include"righttower.h"
#include"leftcastle.h"
#include"rightcastle.h"
#include"arrow.h"
#include"lcdnumber.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
    public:
        Scene(QObject *parent = 0);
        void Init();
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        LCDNumber * chooseTime;
        LCDNumber * number;
        LCDNumber * scoreBoard;
        LeftTower * ltower1;
        LeftTower * ltower2;
        LeftCastle * lcastle;
        RightTower * rtower1;
        RightTower * rtower2;
        RightCastle * rcastle;

    private:
        Btn *btn_start;
        Btn *btn_back;
        Btn *btn_yes,*btn_no;
        int btn_w;
        int btn_h;
        int btn_small_w;
        int btn_small_h;
        int screenMode;

    public slots:
        void bgChange();
        void bgRecover();
};

#endif // SCENE_H
