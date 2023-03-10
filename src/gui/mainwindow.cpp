#include "mainwindow.hpp"
#include "../header.hpp"
#include "../funtrans/funtrans.hpp"
#include "./ui_mainwindow.h"
#include <QTime>
#include <Qtimer>
#include <QDesktopServices>
#include <QMessageBox>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->buttonHelp, &QPushButton::clicked,
            this, &MainWindow::onButtonHelpClicked);

    connect(ui->buttonClear, &QPushButton::clicked,
            this, &MainWindow::onButtonClearClicked);

    connect(ui->buttonDivi, &QPushButton::clicked,
            this, &MainWindow::onButtonDiviClicked);

    connect(ui->buttonExp, &QPushButton::clicked,
            this, &MainWindow::onButtonExpClicked);

    connect(ui->buttonSin, &QPushButton::clicked,
            this, &MainWindow::onButtonSinClicked);

    connect(ui->buttonCos, &QPushButton::clicked,
            this, &MainWindow::onButtonCosClicked);

    connect(ui->buttonTan, &QPushButton::clicked,
            this, &MainWindow::onButtonTanClicked);

    connect(ui->buttonLn, &QPushButton::clicked,
            this, &MainWindow::onButtonLnClicked);

    connect(ui->buttonLogy, &QPushButton::clicked,
            this, &MainWindow::onButtonLogyClicked);

    connect(ui->buttonPower, &QPushButton::clicked,
            this, &MainWindow::onButtonPowerClicked);

    connect(ui->buttonSinh, &QPushButton::clicked,
            this, &MainWindow::onButtonSinhClicked);

    connect(ui->buttonCosh, &QPushButton::clicked,
            this, &MainWindow::onButtonCoshClicked);

    connect(ui->buttonSqrt, &QPushButton::clicked,
            this, &MainWindow::onButtonSqrtClicked);

    connect(ui->buttonTanh, &QPushButton::clicked,
            this, &MainWindow::onButtonTanhClicked);

    connect(ui->buttonRoot, &QPushButton::clicked,
            this, &MainWindow::onButtonRootClicked);

    connect(ui->buttonAsin, &QPushButton::clicked,
            this, &MainWindow::onButtonAsinClicked);

    connect(ui->buttonAtan, &QPushButton::clicked,
            this, &MainWindow::onButtonAtanClicked);

    connect(ui->buttonCsc, &QPushButton::clicked,
            this, &MainWindow::onButtonCscClicked);

    connect(ui->buttonSec, &QPushButton::clicked,
            this, &MainWindow::onButtonSecClicked);

    connect(ui->buttonCot, &QPushButton::clicked,
            this, &MainWindow::onButtonCotClicked);

    connect(ui->buttonFactorial, &QPushButton::clicked,
            this, &MainWindow::onButtonFactorialClicked);

    connect(ui->buttonPI, &QPushButton::clicked,
            this, &MainWindow::onButtonPIClicked);

    QRegularExpressionValidator *validator =
    new QRegularExpressionValidator(QRegularExpression(
                        "^[0-9]{0,50}(\\.[0-9]{0,50})?$"), this);
    ui->lineEditX->setValidator(validator);
    ui->lineEditY->setValidator(validator);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::showErrorDialog(const QString& message) {
    QMessageBox errorMessage;
    errorMessage.setIcon(QMessageBox::Critical);
    errorMessage.setWindowTitle("Error");
    errorMessage.setText(message);
    errorMessage.setStandardButtons(QMessageBox::Ok);
    errorMessage.exec();
}

void MainWindow::onButtonHelpClicked() {
    QString manualFilePath = QCoreApplication::applicationDirPath() +
                             "/resources/user_manual.pdf";
    QUrl manualFileUrl = QUrl::fromLocalFile(manualFilePath);
    if (!QDesktopServices::openUrl(manualFileUrl)) {
        QMessageBox::warning(this,
                             tr("Error"),
                             tr("No se puede abrir el manual local."));
    }
    else{
    QDesktopServices::openUrl(QUrl(
"https://estudianteccr-my.sharepoint.com/:w:/g/personal"
"/carlos_andres12001_estudiantec_cr"
"/ERbrWpZKlxNPvpSA8ychQxIBlg1tXkwrePMdH7psgyrorg?e=FIttP1",
            QUrl::TolerantMode));
    }
}

void MainWindow::onButtonClearClicked() {
    ui->lineEditX->clear();
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();
}

void MainWindow::onButtonDiviClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    if (x == 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser distinto de cero)");
        return;
    }

    decimal_50_digits result = funtrans::divi_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonExpClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    if (x < -1100) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser mayor que -1100)");
        return;
    }

    decimal_50_digits result = funtrans::exp_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonSinClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    decimal_50_digits pi = funtrans::pi_t;
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    if (x > pi / 2 || x < -pi / 2) {
        showErrorDialog("Valor de x no permitido "
                        "(debe estar en el rango [-??/2, ??/2])");
        return;
    }

    decimal_50_digits result = funtrans::sin_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));


}

void MainWindow::onButtonCosClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    decimal_50_digits pi = funtrans::pi_t;
    decimal_50_digits two_pi = pi * decimal_50_digits(2);
    decimal_50_digits result;

    if (x == 0 || x == pi || x == -pi) {
        result = decimal_50_digits(1);
    } else if (x == two_pi || x == -two_pi) {
        result = decimal_50_digits(1);
    } else {
        result = funtrans::cos_t(x);
    }

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonTanClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    decimal_50_digits pi = funtrans::pi_t;

    if (abs(x - (pi / 2)) < 1e-15 || abs(x - (3 * pi / 2)) < 1e-15 ||
        abs(x - (5 * pi / 2)) < 1e-15 ||
        abs(x - (7 * pi / 2)) < 1e-15) {
        showErrorDialog("Valor de x no permitido");
        return;
    }

    decimal_50_digits result = funtrans::tan_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonLnClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    if (x <= 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser mayor que cero)");
        return;
    }

    decimal_50_digits result = funtrans::ln_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonLogyClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    if (ui->lineEditY->text().isEmpty()) {
        showErrorDialog("Valor de y est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    string y_str = ui->lineEditY->text().toStdString();
    decimal_50_digits y(y_str);
    ui->plaintTextEqual->clear();

    if (x <= 0 || y <= 0) {
        showErrorDialog("Valores de x e y no permitidos "
                        "(deben ser mayores que cero)");
        return;
    }

    decimal_50_digits result = funtrans::log_t(y, x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonPowerClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    if (ui->lineEditY->text().isEmpty()) {
        showErrorDialog("Valor de y est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    string y_str = ui->lineEditY->text().toStdString();
    decimal_50_digits y(y_str);
    ui->plaintTextEqual->clear();

    decimal_50_digits result = funtrans::power_t(x, y);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonSinhClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->plaintTextEqual->clear();

    decimal_50_digits result = funtrans::sinh_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonCoshClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->plaintTextEqual->clear();

    decimal_50_digits result = funtrans::cosh_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonSqrtClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    if (x < 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser mayor o igual que cero)");
        return;
    }

    decimal_50_digits result = funtrans::sqrt_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonTanhClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    decimal_50_digits result = funtrans::tanh_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonRootClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    if (ui->lineEditY->text().isEmpty()) {
        showErrorDialog("Valor de y est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    string y_str = ui->lineEditY->text().toStdString();
    decimal_50_digits y(y_str);
    ui->plaintTextEqual->clear();

    if (!funtrans::is_positive_integer(y)) {
        showErrorDialog("Valor de y no permitido "
                        "(tiene que ser entero si quieres usar decimales"
                        " utiliza power(x, y)).");
        return;
    }

    int y_int = static_cast<int>(floor(y));

    decimal_50_digits result = funtrans::root_t(x, y_int);
    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonAsinClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    if (x < -1 || x > 1) {
        showErrorDialog("Valor de x no permitido");
        return;
    }

    decimal_50_digits result = funtrans::asin_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonAtanClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    decimal_50_digits result = funtrans::atan_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonCscClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    decimal_50_digits pi = funtrans::pi_t;

    if (funtrans::abs_t(fmod(x, pi)) < 1e-15) {
        showErrorDialog("Valor de x no permitido");
        return;
    }

    decimal_50_digits result = funtrans::csc_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonSecClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    decimal_50_digits pi = funtrans::pi_t;

    if (abs(fmod(x, pi / 2)) < 1e-15) {
        showErrorDialog("Valor de x no permitido");
        return;
    }

    decimal_50_digits result = funtrans::sec_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonCotClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();

    decimal_50_digits pi = funtrans::pi_t;

    if (abs(x) < 1e-15 || abs(x - pi) < 1e-15 ||
        abs(x - (2 * pi)) < 1e-15 || abs(x - (3 * pi)) < 1e-15) {
        showErrorDialog("Valor de x no permitido");
        return;
    }

    decimal_50_digits result = funtrans::cot_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonFactorialClicked() {
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x est?? vaci??.");
        return;
    }
    string x_str = ui->lineEditX->text().toStdString();
    decimal_50_digits x(x_str);
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();
    if (x<0&&!funtrans::is_positive_integer(x)) {
        showErrorDialog("Valor de x no permitido");
        return;
    }

    decimal_50_digits result = funtrans::factorial_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonPIClicked() {
    decimal_50_digits pi = funtrans::pi_t;

    QMessageBox msgBox;
    msgBox.setText("En qu?? desea establecer el valor de PI?");

    QPushButton *xButton = msgBox.addButton(tr("x"),
                                            QMessageBox::ActionRole);
    QPushButton *yButton = msgBox.addButton(tr("y"),
                                            QMessageBox::ActionRole);

    msgBox.exec();

    if (msgBox.clickedButton() == xButton)
        ui->lineEditX->setText(QString(pi.str().c_str()));
    else if (msgBox.clickedButton() == yButton)
        ui->lineEditY->setText(QString(pi.str().c_str()));
    else
        ui->lineEditX->setText(QString(pi.str().c_str()));
}
