#include "mainwindow.h"
#include "PARAMETERS.h"


#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QPen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(WIDTH, HEIGHT);
    w.show();

    return a.exec();
}
