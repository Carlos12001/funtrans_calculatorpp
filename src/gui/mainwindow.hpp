#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:


    void on_button_help_clicked();
//    void on_button_clear_clicked();
//    void on_button_divi_clicked();
//    void on_button_exp_clicked();
//    void on_button_sin_clicked();
//    void on_button_cos_clicked();
//    void on_button_tan_clicked();
//    void on_button_ln_clicked();
//    void on_button_logy_clicked();
//    void on_button_power_clicked();
//    void on_button_sinh_clicked();
//    void on_button_cosh_clicked();
//    void on_button_sqrt_clicked();
//    void on_button_tanh_clicked();
//    void on_button_root_clicked();
//    void on_button_asin_clicked();
//    void on_button_atan_clicked();
//    void on_button_csc_clicked();
//    void on_button_sec_clicked();
//    void on_button_cot_clicked();
};
#endif // MAINWINDOW_H
