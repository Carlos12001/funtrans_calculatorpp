#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTime>
#include <Qtimer>
#include "../funtrans/funtrans.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->label->setText(QString::fromStdString(to_string(funtrans::pi_t)));
}

MainWindow::~MainWindow(){
    delete ui;
}
