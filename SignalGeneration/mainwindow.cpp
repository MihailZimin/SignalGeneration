#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QSplineSeries *series = new QSplineSeries();

    series->append(0, 2);
    series->append(1, 1);
    series->append(2, 6);
    series->append(3, 22);
    series->append(5, 3);
    series->append(6, 25);
    series->append(8, 12);
    series->append(10, 4);
    series->append(11, 7);
    series->append(13, 6);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 32);
    chart->axes(Qt::Horizontal).first()->setRange(0, 32);
    chart->setVisible(true);

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setVisible(true);

    //setCentralWidget(chartview);
    Scene = new QGraphicsScene(this);
    QGraphicsView view(Scene);
    view.setRenderHint(QPainter::Antialiasing);
    //view.resize(981, 621);
    view.setScene(Scene);
    chartview->resize(view.width(), view.height());
    Scene->addWidget(chartview);
    ui->graphicsView->setScene(Scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}
