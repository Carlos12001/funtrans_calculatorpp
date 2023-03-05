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
    errorMessage.setText("El valor ingresado está fuera del dominio.");
    errorMessage.setDetailedText(message);
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
"https://estudianteccr-my.sharepoint.com/:w:/g/personal/carlos_andres12001_estudiantec_cr/ERbrWpZKlxNPvpSA8ychQxIBlg1tXkwrePMdH7psgyrorg?e=FIttP1",
            QUrl::TolerantMode));
    }
}

void MainWindow::onButtonClearClicked() {
    ui->lineEditX->clear();
    ui->lineEditY->clear();
    ui->plaintTextEqual->clear();
}

void MainWindow::onButtonDiviClicked() {
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

}

void MainWindow::onButtonSinClicked() {

}

void MainWindow::onButtonCosClicked() {

}

void MainWindow::onButtonTanClicked() {

}

void MainWindow::onButtonLnClicked() {

}

void MainWindow::onButtonLogyClicked() {

}

void MainWindow::onButtonPowerClicked() {

}

void MainWindow::onButtonSinhClicked() {

}

void MainWindow::onButtonCoshClicked() {

}

void MainWindow::onButtonSqrtClicked() {

}

void MainWindow::onButtonTanhClicked() {

}

void MainWindow::onButtonRootClicked() {

}

void MainWindow::onButtonAsinClicked() {

}

void MainWindow::onButtonAtanClicked() {

}

void MainWindow::onButtonCscClicked() {

}

void MainWindow::onButtonSecClicked() {

}

void MainWindow::onButtonCotClicked() {

}

void MainWindow::onButtonPIClicked() {

}
