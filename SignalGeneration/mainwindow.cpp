#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphicsfield.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GraphicsField graphics_field = GraphicsField(this);

    ui->graphicsView->setScene(graphics_field.getScene());


}

MainWindow::~MainWindow()
{
    delete ui;
}
