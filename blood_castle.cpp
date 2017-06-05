#include "blood_castle.h"
#include<QFont>

Blood_castle::Blood_castle()
{
    blood = 50;
    setPlainText(QString("Blood: ") + QString::number(blood));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Vemana2000",18));
}

void Blood_castle::decrease()
{
    --blood;
    setPlainText(QString("Droid Sans ") + QString::number(blood));
}

int Blood_castle::getBlood()
{
    return blood;
}
