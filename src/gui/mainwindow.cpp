#include "mainwindow.hpp"
#include "../header.hpp"
#include "./ui_mainwindow.h"
#include <QTime>
#include <Qtimer>
#include <QDesktopServices>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->buttonHelp,
            &QPushButton::clicked,
            this,
            &MainWindow::onButtonHelpClicked);

}

MainWindow::~MainWindow(){
    delete ui;
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

}

void MainWindow::onButtonDiviClicked() {

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
