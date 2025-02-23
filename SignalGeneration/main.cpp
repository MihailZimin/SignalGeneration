#include "mainwindow.h"


#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QPen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1780, 1000);
    w.show();

    return a.exec();
}
