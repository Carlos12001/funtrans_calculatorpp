#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "../funtrans/funtrans.hpp"
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

    connect(ui->buttonAcos, &QPushButton::clicked,
            this, &MainWindow::onButtonAcosClicked);

    connect(ui->buttonLog10, &QPushButton::clicked,
            this, &MainWindow::onButtonLog10Clicked);

    connect(ui->buttonXSign, &QPushButton::clicked,
            this, &MainWindow::onButtonXSignClicked);

    connect(ui->buttonYSign, &QPushButton::clicked,
            this, &MainWindow::onButtonYSignClicked);

    auto *validator =
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
    setGreenButtonStyle(ui->buttonXSign);
    resetYAndEqual();
}

void MainWindow::onButtonDiviClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if (x == 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser distinto de cero)");
        return;
    }

    decimal_50_digits result = funtrans::divi_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonExpClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::exp_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonSinClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::sin_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonCosClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::cos_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonTanClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if(funtrans::is_mult_pi_divi2(x)){
        showErrorDialog("Valor de x no permitido "
                        "(x no puede ser (2k+1)*pi/2)");
        return;
    }

    decimal_50_digits result = funtrans::tan_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonLnClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if(ui->buttonXSign->text().toStdString()!="+"){
        showErrorDialog("Valor de x no permitido"
                        "(deben ser mayores que cero)");
        return;
    }

    if (x <= 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser mayor que cero)");
        return;
    }

    decimal_50_digits result = funtrans::ln_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonLog10Clicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if (x <= 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser mayor que cero)");
        return;
    }

    decimal_50_digits result = funtrans::log10_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonLogyClicked() {
    if (incorrectInputX())
        return;
    if (incorrectInputY())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    decimal_50_digits y( ui->lineEditY->text().toStdString());
    resetEqual();

    if (x <= 0 || y <= 0) {
        showErrorDialog("Valores de x e y no permitidos "
                        "(deben ser mayores que cero)");
        return;
    }

    decimal_50_digits result = funtrans::log_t(y, x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonPowerClicked() {
    if (incorrectInputX())
        return;
    if (incorrectInputY())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    decimal_50_digits y( ui->lineEditY->text().toStdString());
    resetEqual();

    if(y==0){
        ui->plaintTextEqual->setPlainText("1");
        return;
    }

    if(!funtrans::is_positive_integer(y) &&
    ui->buttonXSign->text().toStdString()!="+"){
        showErrorDialog("Valor de x no permitido"
                         " (para un y real "
                         " x no puede ser negativo.)");
        return;
    }

    auto result = funtrans::power_t(x, y);
    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonSinhClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::sinh_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonCoshClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::cosh_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonSqrtClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if(ui->buttonXSign->text().toStdString()!="+"){
        showErrorDialog("Valor de x no permitido"
                        "(deben ser mayores que cero)");
        return;
    }

    if (x < 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser mayor o igual que cero)");
        return;
    }

    decimal_50_digits result = funtrans::sqrt_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonTanhClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::tanh_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonRootClicked() {
    if (incorrectInputX())
        return;
    if (incorrectInputY())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    decimal_50_digits y( ui->lineEditY->text().toStdString());
    resetEqual();


    if (y==0) {
        showErrorDialog("Valor de y no permitido");
        return;
    }
    if (x==0) {
        ui->plaintTextEqual->setPlainText("0");
        return;
    }

    if(ui->buttonYSign->text().toStdString()!="+"){
        showErrorDialog("Valor de y no permitido"
                        "(tiene que ser entero si quieres negativos"
                        " utiliza power(x, y)).");
        return;
    }

    if (!funtrans::is_positive_integer(y)) {
        showErrorDialog("Valor de y no permitido "
                        "(tiene que ser entero si quieres usar decimales"
                        " utiliza power(x, y)).");
        return;
    }

    int y_int = static_cast<int>(floor(y));

    if(ui->buttonXSign->text().toStdString()!="+"&&y_int%2==0){
        showErrorDialog("Valor de x no permitido "
                        "(ya que tiene que ser un valor positivo "
                        "porque y es par).");
        return;
    }

    decimal_50_digits result = funtrans::root_t( funtrans::abs_t(x),
                                                 y_int);
    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));

    if(ui->buttonXSign->text().toStdString()!="+"&&y_int%2!=0)
        ui->plaintTextEqual->setPlainText("-"+
                ui->plaintTextEqual->toPlainText());
}

void MainWindow::onButtonAsinClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if (x < -1 || x > 1) {
        showErrorDialog("Valor de x no permitido"
                                "x debe ser -1<x<1");
        return;
    }

    decimal_50_digits result = funtrans::asin_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonAcosClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if (x < -1 || x > 1) {
        showErrorDialog("Valor de x no permitido"
                        "x debe ser -1<x<1");
        return;
    }

    decimal_50_digits result = funtrans::acos_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonAtanClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::atan_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonCscClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::csc_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonSecClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::sec_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonCotClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if(funtrans::is_mult_pi_divi2(x)){
        showErrorDialog("Valor de x no permitido "
                        "(x no puede ser (2k+1)*pi/2)");
        return;
    }

    decimal_50_digits result = funtrans::cot_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonFactorialClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if(ui->buttonXSign->text().toStdString()!="+"){
        showErrorDialog("Valor de x no permitido");
        return;
    }

    if (x<0) {
        showErrorDialog("Valor de x no permitido");
        return;
    }

    decimal_50_digits result = funtrans::factorial_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

void MainWindow::onButtonPIClicked() {
    decimal_50_digits pi = funtrans::pi_t;

    QMessageBox msgBox;
    msgBox.setText("En qué desea establecer el valor de PI?");

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

void MainWindow::onButtonXSignClicked() {
    string label = ui->buttonXSign->text().toStdString();
    string str_num =  ui->lineEditX->text().isEmpty()? "" :
                        ui->lineEditX->text().toStdString();
    if(label != "+"){
        str_num.erase(remove(str_num.begin(), str_num.end(),
                             '-'),
                      str_num.end());
        ui->lineEditX->setText(QString::fromStdString(str_num));
        setGreenButtonStyle(ui->buttonXSign);
    }
    else{
        ui->lineEditX->setText("-"+QString::fromStdString(str_num));
        setRedButtonStyle(ui->buttonXSign);
    }
}

void MainWindow::onButtonYSignClicked() {
    string label = ui->buttonYSign->text().toStdString();
    string str_num =  ui->lineEditY->text().isEmpty() ? "" :
            ui->lineEditY->text().toStdString();
    if(label != "+"){
        str_num.erase(remove(str_num.begin(), str_num.end(),
                             '-'),
                         str_num.end());
        ui->lineEditY->setText(QString::fromStdString(str_num));
        setGreenButtonStyle(ui->buttonYSign);
    }
    else{
        ui->lineEditY->setText("-"+QString::fromStdString(str_num));
        setRedButtonStyle(ui->buttonYSign);
    }
}

void MainWindow::setGreenButtonStyle(QPushButton* button){
    button->setText("+");
    button->setStyleSheet(
            "QPushButton {"
            "   border: none;"
            "   border-radius: 5px;"
            "   color: white;"
            "   font-size: 22px;"
            "   font-weight: bold;"
            "   padding: 10px 20px;"
            "   background-color: #2E8B57;"
            "}"
    );
}

void MainWindow::setRedButtonStyle(QPushButton* button){
    button->setText("-");
    button->setStyleSheet(
            "QPushButton {"
            "   border: none;"
            "   border-radius: 5px;"
            "   color: white;"
            "   font-size: 22px;"
            "   font-weight: bold;"
            "   padding: 10px 20px;"
            "   background-color: #de505c;"
            "}"
    );
}

void MainWindow::resetYAndEqual() {
    ui->lineEditY->clear();
    setGreenButtonStyle(ui->buttonYSign);
    resetEqual();
}

void MainWindow::resetEqual() {
    ui->plaintTextEqual->clear();
}

bool MainWindow::incorrectInputX(){
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x está vació.");
        return true;
    }
    else if (funtrans::notRealNumber(ui->lineEditX->text().toStdString())){
        showErrorDialog("Valor de x no es un numero real.");
        return true;
    }
    else
        return false;
}

bool MainWindow::incorrectInputY(){
    if (ui->lineEditY->text().isEmpty()) {
        showErrorDialog("Valor de y está vació.");
        return true;
    }
    else if (funtrans::notRealNumber(ui->lineEditY->text().toStdString())){
        showErrorDialog("Valor de y no es un numero real.");
        return true;
    }
    else
        return false;
}
