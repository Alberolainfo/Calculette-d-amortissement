#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->actionInfo, &QAction::triggered, this, &MainWindow::displayInfo);
    connect(ui->actionQuitter, &QAction::triggered, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Calcule les mensualités d’un crédit.
 *
 * Cette fonction prend en compte le capital emprunté, la durée et le taux d’intérêt
 * Calcule et affiche la mensualité, le coût total du crédit et le montant des intérêts.
 *
 * @param sommeEmprunte Montant emprunté (capital).
 * @param duree Durée de l’emprunt en années.
 * @param intere Taux d’intérêt annuel (en pourcentage).
 */
void MainWindow::calculAmortisssement(double sommeEmprunte, double duree, double intere)
{
    double t;//variable pour stocker la valeur du taux d'interé
    double n;//variable pour stocké le nombre total de mensualité
    double M;//variable qui stocke la valeur des mensualité
    double C;//variable qui stocke la montant total des intérêts
    double Total;//varible qui stocke le cout total du crédits
    t = (intere/100)/12;
    n = duree * 12;
    M = (sommeEmprunte * t)/(1 - pow(1 + t, -n));
    C = (M * n) - sommeEmprunte;
    Total = M * n;

    QString text; // Variable du texte à afficher dans textBrowser
    text = "Pour un emprunt de " + QString::number(sommeEmprunte) +
           " € à un taux d'intérêt de " + QString::number(intere) + " % et une durée de " +
           QString::number(duree) + " ans :\n\n";
    text += "  - La valeur des mensualités est de " + QString::number(M) + " €\n";
    text += "  - Le montant total des intérêts est de " + QString::number(C) + " €\n";
    text += "  - Le coût total du crédit est de " + QString::number(Total) + " €\n";

    ui->textBrowser->setText(text);
    ui->textBrowser->selectAll();
    ui->textBrowser->setAlignment(Qt::AlignCenter);
}

void MainWindow::displayInfo()
{
    QString text = "⚠️ Les valeurs affichées ne sont pas représentatives de celles pratiquées par les banques.\n\n";
    text += "Ce logiciel effectue une simulation de crédit bancaire à partir des informations suivantes :\n";
    text += "  - Le montant de la somme empruntée\n";
    text += "  - Le taux d'intérêt bancaire (en pourcentage)\n";
    text += "  - La durée du prêt (en années)\n\n";
    text += "Une fois ces données collectées, le logiciel calcule :\n";
    text += "  - Le coût total du crédit\n";
    text += "  - Le montant des mensualités\n";
    text += "  - Le montant total des intérêts\n";
    QMessageBox::information(this, "Informations", text);
}

void MainWindow::on_pushButton_clicked()
{


    if(ui->putSomme->value() <= 0 || ui->putInteret->value() <= 0 || ui->putAnnee->value() <= 0)
        QMessageBox::critical(this, "Alerte", "Les valeurs d'entrées doivent être strictement supérieur à 0");
    else

    {
        double somme = ui->putSomme->value();
        double duree = ui->putAnnee->value();
        double interet = ui->putInteret->value();

        calculAmortisssement(somme, duree, interet);
    }
}


/*void MainWindow::on_pushButton_clicked()
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
}*/
