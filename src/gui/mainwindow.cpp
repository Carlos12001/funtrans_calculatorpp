#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include <QTime>
#include <Qtimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}
