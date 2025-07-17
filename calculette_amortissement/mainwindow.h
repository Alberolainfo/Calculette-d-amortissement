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
    void calculAmortisssement(double sommeEmprunte, double duree, double intere);

private :
    void displayInfo();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
