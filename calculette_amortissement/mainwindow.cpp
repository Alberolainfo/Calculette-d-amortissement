#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, MainWindow::on_pushButton_clicked);
    connect(ui->actionInfo, &QAction::triggered, this, &MainWindow::displayInfo);
    connect(ui->actionQuitter, &QAction::triggered, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayInfo(){
    QMessageBox::information(this, "Informations", "Les valeurs données ne sont pas représentatives de celles des banques");
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->putSomme->value() <= 0 || ui->putInteret->value() <= 0 || ui->putAnnee->value() <= 0)
        QMessageBox::information(this, "Alerte", "Les valeurs d'entrées doivent être strictement supérieur à 0");
    else{
        float tmp = ui->putSomme->value();
        float mensualite_annee = 0;
        float total_interet = 0;
        float cp_annee_remboursement = ui->putAnnee->value();
        QString text;

        for (int i = 1; i <= ui->putAnnee->value(); i++){

            total_interet += tmp * ui->putInteret->value() / 100;
            tmp += tmp * ui->putInteret->value() / 100;
            mensualite_annee = tmp / (cp_annee_remboursement * 12);

            text += "Annee " + QString::number(i) + " : \nSomme + Intêret = " + QString::number(tmp) + "\nMensualité = " + QString::number(mensualite_annee) + "\nIntêret totaux = " + QString::number(total_interet) + '\n';
            tmp -= mensualite_annee * 12;
            cp_annee_remboursement--;
            qDebug("%s", qUtf8Printable(text));
        }
        ui->textBrowser->setText(text);
        ui->textBrowser->selectAll();
        ui->textBrowser->setAlignment(Qt::AlignCenter);
        qDebug() << "Tu as cliqué\n";
    }
}

