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
void MainWindow::calculAmortisssement(long double sommeEmprunte, long double duree, long double intere)
{
    long double t;//variable pour stocker la valeur du taux d'interé
    long double n;//variable pour stocker le nombre total de mensualité
    long double M;//variable qui stocke la valeur des mensualité
    long double C;//variable qui stocke la montant total des intérêts
    long double Total;//varible qui stocke le cout total du crédits
    t = (intere/100)/12;
    n = duree * 12;
    M = (sommeEmprunte * t)/(1 - pow(1 + t, -n));
    C = (M * n) - sommeEmprunte;
    Total = M * n;

    QString text; // Variable du texte à afficher dans textBrowser
    text = "<p style='text-align:center;'><strong>Pour un emprunt de " + formatageNombre(sommeEmprunte) +
           " € à un taux d'intérêt de " + formatageNombre(intere) + " %<br/> et une durée de " +
           formatageNombre(duree) + " ans :</strong>";
    text += "<ul><li> La valeur des mensualités est de " + formatageNombre(M) + " €</li>";
    text += "<li> Le montant total des intérêts est de " + formatageNombre(C) + " €</li>";
    text += "<li> Le coût total du crédit est de " + formatageNombre(Total) + " €</li></ul></p>";

    ui->textBrowser->clear();
    ui->textBrowser->insertHtml(text);
}

/**
 * @brief MainWindow::formatageNombre
 * Cette fonction recupére un nombre brut (exemple : 100000.50),
 * renvoie un qstring plus lissible (exemple : 100 000,50)
 * @param nombre : nombre a traité
 * @return un string formaté pour l'affichage
 */
QString MainWindow::formatageNombre(long double nombre)
{
    QString textNonFormate = QString::number(nombre, 'f', 2);//nombre brut retrenscris en qstring
    QString textFormate = "";//variable pour stocké le nombre formaté
    int i = 0;

    for(i; textNonFormate[i] != "."; i++)//recupere les nombre avant la virgule
    {
        textFormate += textNonFormate[i];
    }

    for(i; i >= 0; i--)//suprime le nombre avant la virgule ainsi que la virgule elle meme
    {
        textNonFormate.remove(i, 1);
    }

    int size = textFormate.size();
    std::reverse(textFormate.begin(), textFormate.end());
    int inser = 3;
    for(i = 0; i <= size; i++)//insere les espace
    {
        if(i % 3 == 0 && i != 0)
        {
            textFormate.insert(inser, ' ');
            inser += 4;
        }
    }

    std::reverse(textFormate.begin(), textFormate.end());
    if(textNonFormate.toInt() != 0)
    {
        textFormate += "," + textNonFormate;
    }
    if(textFormate[0] == " ")
    {
        textFormate.remove(0, 1);
    }

    return textFormate;
}

void MainWindow::displayInfo()
{
    QString text = "⚠️ Les valeurs affichées ne sont pas représentatives de celles pratiquées par les banques.\n"
                   "La valeur maximal des entrées ne doit pas être superieur à 5 000 000 000\n\n";
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
