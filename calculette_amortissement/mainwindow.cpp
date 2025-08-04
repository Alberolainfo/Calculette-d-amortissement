#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), enFrancais(true)
{
    ui->setupUi(this);


    ui->layoutLangue->setAlignment(Qt::AlignRight);
    initTexte();

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->actionInfo, &QAction::triggered, this, &MainWindow::displayInfo);
    connect(ui->actionQuitter, &QAction::triggered, this, &MainWindow::close);

    ui->radioButtonFr->setChecked(true);
    breakQtCode(ui->putInteret);
    breakQtCode(ui->putSomme);

}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief MainWindow::initTexte
 * Inittialise les texte pour leurs utilisation
 */
void MainWindow::initTexte(){
    titre[0] = "Calculette d'amortissement";
    titre[1] = "Amortization Calculator";

    texteWarning[0] = "Les valeurs d'entrée doivent être strictement supérieures à 0";
    texteWarning[1] = "Input values must be strictly greater than 0";

    texteInfo[0] = "⚠️ Les valeurs affichées ne sont pas représentatives de celles pratiquées par les banques.\n"
                   "La valeur maximal des entrées ne doit pas être superieur à 5 000 000 000\n\n"
                   "Ce logiciel effectue une simulation de crédit bancaire à partir des informations suivantes :\n"
                   "  - Le montant de la somme empruntée\n"
                   "  - Le taux d'intérêt bancaire (en pourcentage)\n"
                   "  - La durée du prêt (en années)\n\n"
                   "Une fois ces données collectées, le logiciel calcule :\n"
                   "  - Le coût total du crédit\n"
                   "  - Le montant des mensualités\n"
                   "  - Le montant total des intérêts\n";
    texteInfo[1] = "⚠️ The displayed values are not representative of those used by banks.\n"
                   "The maximum value for inputs must not exceed 5,000,000,000.\n\n"
                   "This software simulates a bank loan based on the following information:\n"
                   "  - The amount borrowed\n"
                   "  - The interest rate (in percentage)\n"
                   "  - The loan duration (in years)\n\n"
                   "Once this data is entered, the software calculates:\n"
                   "  - The total cost of the loan\n"
                   "  - The monthly payments\n"
                   "  - The total interest paid\n";

    texteIntituleFr[0] = "Somme du prêt :";
    texteIntituleFr[1] = "Taux d'intêrets :";
    texteIntituleFr[2] = "Années :";

    texteIntituleEn[0] = "Loan amount:";
    texteIntituleEn[1] = "Interest rate:";
    texteIntituleEn[2] = "Years:";

    titreInfo[0] = "Informations";
    titreInfo[1] = "Information";

    titreWarning[0] = "Alerte";
    titreWarning[1] = "Alert";

    texteGenerer[0] = "<p style='text-align:center;'><strong>Pour un emprunt de %1"
                    " € à un taux d'intérêt de %2 %<br/> et une durée de %3 ans :</strong>"
                    "<ul><li> La valeur des mensualités est de %4 €</li>"
                    "<li> Le montant total des intérêts est de %5 €</li>"
                    "<li> Le coût total du crédit est de %6 €</li></ul></p>";
    texteGenerer[1] = "<p style='text-align:center;'><strong>For a loan of %1 $ at an interest rate of %2%"
                      "<br/> and a term of %3 years:</strong>"
                    "<ul><li> The monthly payment amount is %4 $</li>"
                    "<li> The total amount of interest is %5 $</li>"
                    "<li> The total cost of the loan is %6 $</li></ul></p>";
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
    long double valueInteret;
    long double nbMensualite;
    long double valueMensualite;
    long double totalInteret;
    long double totalCreditCost;
    valueInteret = (intere/100)/12;
    nbMensualite = duree * 12;
    valueMensualite = (sommeEmprunte * valueInteret)/(1 - pow(1 + valueInteret, - nbMensualite));
    totalInteret = (valueMensualite * nbMensualite) - sommeEmprunte;
    totalCreditCost = valueMensualite * nbMensualite;

    int indice;
    (enFrancais) ? indice = 0 : indice = 1;
    QString text = QString(texteGenerer[indice])
                       .arg(formatageNombre(sommeEmprunte)) .arg(formatageNombre(intere))
                       .arg(formatageNombre(duree)) .arg(formatageNombre(valueMensualite)) .arg(formatageNombre(totalInteret))
                       .arg(formatageNombre(totalCreditCost)); // Variable du texte à afficher dans textBrowser

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
    char espace = ' ';
    (enFrancais) ? espace = ' ' : espace = ',';
    char virgule = ',';
    (enFrancais) ? virgule = ',' : virgule = '.';
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
            textFormate.insert(inser, espace);
            inser += 4;
        }
    }

    std::reverse(textFormate.begin(), textFormate.end());
    if(textNonFormate.toInt() != 0)
    {
        textFormate += virgule + textNonFormate;
    }
    if(textFormate[0] == espace)
    {
        textFormate.remove(0, 1);
    }

    return textFormate;
}

void MainWindow::displayInfo()
{
    QString text;
    int indice = 0;
    (enFrancais == true) ? indice = 0 : indice = 1;
    text = texteInfo[indice];
    QMessageBox::information(this, titreInfo[indice], text);
}

//Entrée nombre flottant virgule ou point
void MainWindow::breakQtCode(QDoubleSpinBox *doubleSpinBox)
{
    class DoubleValidator : public QValidator
    {
        const QValidator *old;
    public:
        DoubleValidator(const QValidator *old_)
            : QValidator(const_cast<QValidator*>(old_)), old(old_)
        {}

        void fixup ( QString & input ) const
        {
            input.replace(".", QLocale().decimalPoint());
            input.replace(",", QLocale().decimalPoint());
            old->fixup(input);
        }
        QValidator::State validate ( QString & input, int & pos ) const
        {
            fixup(input);
            return old->validate(input, pos);
        }
    };
    QLineEdit *lineEdit = doubleSpinBox->findChild<QLineEdit*>();
    lineEdit->setValidator(new DoubleValidator(lineEdit->validator()));
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->putSomme->value() <= 0 || ui->putInteret->value() <= 0 || ui->putAnnee->value() <= 0)
    {
        int indice = 0;
        (enFrancais == true) ? indice = 0 : indice = 1;
        QMessageBox::critical(this, titreWarning[indice], texteWarning[indice]);
    }
    else
    {
        double somme = ui->putSomme->value();
        double duree = ui->putAnnee->value();
        double interet = ui->putInteret->value();

        calculAmortisssement(somme, duree, interet);
    }
}

void MainWindow::on_radioButtonEn_toggled(bool checked)
{
    enFrancais = false;
    ui->label_4->clear();
    ui->label_4->setText(titre[1]);
    ui->label->setText(texteIntituleEn[0]);
    ui->label_2->setText(texteIntituleEn[1]);
    ui->label_3->setText(texteIntituleEn[2]);
    ui->pushButton->setText("Confirm");
    ui->actionInfo->setText("Information");
    ui->actionQuitter->setText("Quit");
    ui->textBrowser->clear();
}


void MainWindow::on_radioButtonFr_toggled(bool checked)
{
    enFrancais = true;
    ui->label_4->clear();
    ui->label_4->setText(titre[0]);
    ui->label->setText(texteIntituleFr[0]);
    ui->label_2->setText(texteIntituleFr[1]);
    ui->label_3->setText(texteIntituleFr[2]);
    ui->pushButton->setText("Valider");
    ui->actionInfo->setText("Informations");
    ui->actionQuitter->setText("Quitter");
    ui->textBrowser->clear();
}

