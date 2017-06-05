#include "mainwindow.h"
#include <QApplication>
#include<QDesktopWidget>
#include"lcdnumber.h"
#include<QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Set windows size
    QDesktopWidget wid;
    int screenW = 1440;
    int screenH = 800;
    w.setGeometry(wid.screen()->width()/2-(screenW/2),0,screenW,screenH);
    w.setFixedSize(screenW,screenH);
    // Set windows title and icon
    w.setWindowTitle("Project2");
    w.setWindowIcon(QIcon(":/image/img/icon.png"));
    w.show();

    return a.exec();
}
