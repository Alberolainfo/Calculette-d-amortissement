#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>
#include "QMessageBox"
#include <QComboBox>
#include <QTextEdit>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void calculAmortisssement(long double sommeEmprunte, long double duree, long double intere);
    QString formatageNombre(long double nombre);
    void initTexte();

private slots:

    void on_radioButtonEn_toggled(bool checked);

    void on_radioButtonFr_toggled(bool checked);

private :
    void displayInfo();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool enFrancais;
    QString titre[2];//titre[0] = français & titre[1] = englais
    QString texteWarning[2];
    QString titreWarning[2];
    QString texteInfo[2];
    QString titreInfo[2];
    QString texteIntituleFr[3];
    QString texteIntituleEn[3];
    QString texteGenerer[2];
};
#endif // MAINWINDOW_H
