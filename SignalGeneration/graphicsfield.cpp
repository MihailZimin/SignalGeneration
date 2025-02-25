#include "graphicsfield.h"
#include <QGraphicsScene>

GraphicsField::GraphicsField(QMainWindow* parent) {
    QLineSeries *real_part = new QLineSeries();
    QLineSeries *imaginary_part = new QLineSeries();
    QLineSeries *phase = new QLineSeries();
    QLineSeries *absolute = new QLineSeries();

    real_part->append(0, 2);
    real_part->append(1, 1);
    real_part->append(2, 6);
    real_part->append(3, 22);
    real_part->append(5, 3);
    real_part->append(6, 25);
    real_part->append(8, 12);
    real_part->append(10, 4);
    real_part->append(11, 7);
    real_part->append(13, 6);

    imaginary_part->append(0, 2);
    imaginary_part->append(1, 1);
    imaginary_part->append(5, 3);
    imaginary_part->append(6, 25);
    imaginary_part->append(8, 12);
    imaginary_part->append(10, 4);
    imaginary_part->append(11, 7);
    imaginary_part->append(13, 6);


    QChart *real_chart = new QChart();
    QChart *imaginary_chart = new QChart();
    QChart *phase_chart = new QChart();
    QChart *absolute_chart = new QChart();


    real_chart->legend()->hide();
    real_chart->addSeries(real_part);
    real_chart->createDefaultAxes();
    real_chart->axes(Qt::Vertical).constFirst()->setRange(0, 32);
    real_chart->axes(Qt::Vertical).constFirst()->setTitleText("Децибелы");
    real_chart->axes(Qt::Horizontal).constFirst()->setRange(0, 32);
    real_chart->axes(Qt::Horizontal).constFirst()->setTitleText("Дискреты");
    real_chart->setVisible(true);

    imaginary_chart->legend()->hide();
    imaginary_chart->addSeries(imaginary_part);
    imaginary_chart->createDefaultAxes();
    imaginary_chart->axes(Qt::Vertical).constFirst()->setRange(0, 32);
    imaginary_chart->axes(Qt::Vertical).constFirst()->setTitleText("Децибелы");
    imaginary_chart->axes(Qt::Horizontal).constFirst()->setRange(0, 32);
    imaginary_chart->axes(Qt::Horizontal).constFirst()->setTitleText("Дискреты");
    imaginary_chart->setVisible(true);

    phase_chart->legend()->hide();
    phase_chart->addSeries(phase);
    phase_chart->createDefaultAxes();
    phase_chart->axes(Qt::Vertical).constFirst()->setRange(0, 32);
    phase_chart->axes(Qt::Vertical).constFirst()->setTitleText("Децибелы");
    phase_chart->axes(Qt::Horizontal).constFirst()->setRange(0, 32);
    phase_chart->axes(Qt::Horizontal).constFirst()->setTitleText("Дискреты");
    phase_chart->setVisible(true);

    absolute_chart->legend()->hide();
    absolute_chart->addSeries(absolute);
    absolute_chart->createDefaultAxes();
    absolute_chart->axes(Qt::Vertical).constFirst()->setRange(0, 32);
    absolute_chart->axes(Qt::Vertical).constFirst()->setTitleText("Децибелы");
    absolute_chart->axes(Qt::Horizontal).constFirst()->setRange(0, 32);
    absolute_chart->axes(Qt::Horizontal).constFirst()->setTitleText("Дискреты");
    absolute_chart->setVisible(true);


    QFont font;
    font.setPointSize(14);
    font.setBold(true);

    real_chart->setTitle("Действительная часть сигнала");
    real_chart->setTitleFont(font);
    imaginary_chart->setTitle("Мнимая часть сигнала");
    imaginary_chart->setTitleFont(font);
    phase_chart->setTitle("Фаза сигнала");
    phase_chart->setTitleFont(font);
    absolute_chart->setTitle("Модуль сигнала");
    absolute_chart->setTitleFont(font);


    QChartView *real_chartview = new QChartView(real_chart);
    QChartView *imaginary_chartview = new QChartView(imaginary_chart);
    QChartView *phase_chartview = new QChartView(phase_chart);
    QChartView *absolute_chartview = new QChartView(absolute_chart);

    real_chartview->setRenderHint(QPainter::Antialiasing);
    real_chartview->setVisible(true);

    imaginary_chartview->setRenderHint(QPainter::Antialiasing);
    imaginary_chartview->setVisible(true);

    phase_chartview->setRenderHint(QPainter::Antialiasing);
    phase_chartview->setVisible(true);

    absolute_chartview->setRenderHint(QPainter::Antialiasing);
    absolute_chartview->setVisible(true);


    scene = new QGraphicsScene(parent);
    QGraphicsView *view = new QGraphicsView(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setScene(scene);

    stacked_widget = new QStackedWidget();

    stacked_widget->resize(view->width()+280, view->height()+260);


    real_chartview->resize(stacked_widget->width() - MARGIN, stacked_widget->height() - MARGIN);
    imaginary_chartview->resize(stacked_widget->width() - MARGIN, stacked_widget->height() - MARGIN);
    phase_chartview->resize(stacked_widget->width() - MARGIN, stacked_widget->height() - MARGIN);
    absolute_chartview->resize(stacked_widget->width() - MARGIN, stacked_widget->height() - MARGIN);

    stacked_widget->addWidget(real_chartview);
    stacked_widget->addWidget(imaginary_chartview);
    stacked_widget->addWidget(phase_chartview);
    stacked_widget->addWidget(absolute_chartview);
    stacked_widget->setCurrentIndex(0);

    scene->addWidget(stacked_widget);
}
