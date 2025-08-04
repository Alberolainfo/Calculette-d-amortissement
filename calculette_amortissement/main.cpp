#include "mainwindow.h"

#include <QApplication>

#include <QtPlugin>

//Pour éviter que Qt charge dynamiquement certains plugins
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.QWidget::setWindowTitle("Calculette d'amortissement");
    QIcon icon("logo.ico");
    w.QWidget::setWindowIcon(icon);
    w.show();
    return a.exec();
}
