#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.QWidget::setWindowTitle("Calculette d'amortissement");
    w.show();
    return a.exec();
}
