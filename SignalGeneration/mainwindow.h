#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "graphicsfield.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_radioButton_VILCHM_clicked(bool checked);
    void on_radioButton_FKM_clicked(bool checked);
    void on_radioButton_AIM_clicked(bool checked);
    void on_real_part_of_signal_clicked(bool checked);

    void on_imag_part_of_signal_clicked(bool checked);

    void on_phase_clicked(bool checked);

    void on_absolute_clicked(bool checked);

    void on_frequency_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void toggleLight();
    void widgetDisappearance(QWidget *widget);
    void widgetAppearance(QWidget *widget);
    void widgetAppearanceSlide(QWidget *widget);
    GraphicsField *graphics_field;
};
#endif // MAINWINDOW_H
