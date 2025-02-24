#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphics_field = GraphicsField(this);
    ui->graphicsView->setScene(graphics_field.getScene());

    ui->label_8->setPixmap(QPixmap(":/new/images/hed.png"));

    ui->radioButton_FKM->setChecked(true);
    if (ui->radioButton_FKM->isChecked()) {
        ui->Barker1_13Button->show();
        ui->Barker13_13Button->show();
        ui->Barker5_13Button->show();
    }
    ui->Barker1_13Button->setChecked(true);
    ui->real_part_of_signal->setChecked(true);
    ui->noise_off->setChecked(true);

    ui->deviation_groupBox->hide();
    ui->groupBox_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_VILCHM_clicked(bool checked)
{
    if (checked) {
        widgetDisappearance(ui->Barker_frame);
        ui->deviation_groupBox->setVisible(true);
        ui->groupBox_2->setVisible(true);
        widgetAppearance(ui->deviation_groupBox);
        widgetAppearance(ui->groupBox_2);
    }
}


void MainWindow::on_radioButton_FKM_clicked(bool checked)
{
    if (checked) {
        widgetDisappearance(ui->deviation_groupBox);
        widgetDisappearance(ui->groupBox_2);
        ui->Barker_frame->setVisible(true);
        widgetAppearance(ui->Barker_frame);
    }
}


void MainWindow::on_radioButton_AIM_clicked(bool checked)
{
    if (checked) {
        widgetDisappearance(ui->deviation_groupBox);
        widgetDisappearance(ui->groupBox_2);
        widgetDisappearance(ui->Barker_frame);
    }
}

void MainWindow::widgetAppearance(QWidget *widget) {
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(widget);
    widget->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(500);
    animation->setStartValue(0);
    animation->setEndValue(1);
    connect(animation, &QPropertyAnimation::finished, widget, [widget]() {
        widget->show();
    });
    animation->start();
}


void MainWindow::widgetDisappearance(QWidget *widget) {
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(widget);
    widget->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(500);
    animation->setStartValue(1);
    animation->setEndValue(0);
    connect(animation, &QPropertyAnimation::finished, widget, [widget]() {
        widget->hide();
    });
    animation->start();

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

void MainWindow::on_real_part_of_signal_clicked(bool checked)
{
    if (checked) {
        graphics_field.stacked_widget->setCurrentIndex(0);
    }
}

