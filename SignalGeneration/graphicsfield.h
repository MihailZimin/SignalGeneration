#ifndef GRAPHICSFIELD_H
#define GRAPHICSFIELD_H

#include <QtCore>
#include <QtGui>
#include <QtCharts>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QString>
#include <QDebug>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QGraphicsScene>
#include <QFont>

class GraphicsField
{
public:
    GraphicsField(QMainWindow* parent);

    QGraphicsScene* getScene(){ return scene; }

    QStackedWidget *stacked_widget;

private:
    QGraphicsScene* scene;
    static const int MARGIN = 0;
};

#endif // GRAPHICSFIELD_H
