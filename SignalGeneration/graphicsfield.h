#ifndef GRAPHICSFIELD_H
#define GRAPHICSFIELD_H

#include <QtCore>
#include <QtGui>
#include <QtCharts>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QString>
#include <QDebug>

class GraphicsField
{
public:
    GraphicsField(QMainWindow* parent);

    QGraphicsScene* getScene(){ return scene; }

private:
    QGraphicsScene* scene;
    static const int MARGIN = 0;
};

#endif // GRAPHICSFIELD_H
