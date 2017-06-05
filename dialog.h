#ifndef DIALOG_H
#define DIALOG_H

#include<QDialog>
#include<QVBoxLayout>
#include<QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget *parent = 0);
    void win();
    void lose();

private:
    QVBoxLayout *mainLayout;

};

#endif // DIALOG_H
