#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::calculAmortisssement(double sommeEmprunte, double duree, double intere){
    double t;
    double n;
    double M;
    double C;
    double Total;
    t = (intere/100)/12;
    n = duree * 12;
    M = (sommeEmprunte * t)/(1 - pow(1 + t, -n));
    C = (M * n) - sommeEmprunte;
    Total = (M * n) + sommeEmprunte;
}
