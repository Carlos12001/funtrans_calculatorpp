#include "mainwindow.hpp"
#include "../header.hpp"
#include "./ui_mainwindow.h"
#include <QTime>
#include <Qtimer>
#include <QDesktopServices>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->buttonHelp,SIGNAL(clicked()),this,SLOT(on_button_help_clicked()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_button_help_clicked() {
    cout << "Open Manual" << endl;
    QDesktopServices::openUrl(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/resources/user_manual.pdf"));
}