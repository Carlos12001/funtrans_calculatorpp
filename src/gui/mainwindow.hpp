#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../header.hpp"
#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:

    static void showErrorDialog(const QString& message);

    static void setGreenButtonStyle(QPushButton* button);

    static void setRedButtonStyle(QPushButton* button);

    bool incorrectInputX();

    bool incorrectInputY();

    void resetYAndEqual();

    void resetEqual();

    void onLineEditXTextChanged(const QString& text);

    void onLineEditYTextChanged(const QString& text);

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

    void onButtonFactorialClicked();

    void onButtonPIClicked();

    void onButtonAcosClicked();

    void onButtonLog10Clicked();

    void onButtonXSignClicked();

    void onButtonYSignClicked();

};
#endif // MAINWINDOW_H
