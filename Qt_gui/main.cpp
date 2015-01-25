#include <QApplication>
#include "mainwindow.h"

#include <wiringPi.h>

MainWindow *ptWindow;

void setInterrupt(MainWindow *pt);
void interrupt();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    setInterrupt(&w);

    
    return a.exec();
}

void setInterrupt(MainWindow *pt)
{
    ptWindow = pt;

    wiringPiISR(4,INT_EDGE_FALLING, &interrupt);
}

void interrupt()
{
    ptWindow->interrupt();
}
