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

    ui->label_8->setPixmap(QPixmap(":/new/images/hed.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleLight()
{
    static bool isOn = false;

    if (isOn) {
        ui->label_8->setPixmap(QPixmap(":/new/images/light_off.png"));
    } else {
        ui->label_8->setPixmap(QPixmap(":/new/images/light_on.png"));

    }

    isOn = !isOn;
}
