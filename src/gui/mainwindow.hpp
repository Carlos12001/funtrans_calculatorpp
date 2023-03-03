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

    void onButtonHelpClicked();

    void onButtonClearClicked();

    void onButtonDiviClicked();

    void onButtonExpClicked();

    void onButtonSinClicked();

    void onButtonCosClicked();

    void onButtonTanClicked();

    void onButtonLnClicked();

    void onButtonLogyClicked();

    void onButtonPowerClicked();

    void onButtonSinhClicked();

    void onButtonCoshClicked();

    void onButtonSqrtClicked();

    void onButtonTanhClicked();

    void onButtonRootClicked();

    void onButtonAsinClicked();

    void onButtonAtanClicked();

    void onButtonCscClicked();

    void onButtonSecClicked();

    void onButtonCotClicked();
};
#endif // MAINWINDOW_H
