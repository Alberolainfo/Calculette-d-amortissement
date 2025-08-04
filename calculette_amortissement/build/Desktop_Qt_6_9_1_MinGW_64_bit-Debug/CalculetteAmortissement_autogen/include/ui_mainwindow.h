/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInfo;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *layoutLangue;
    QRadioButton *radioButtonFr;
    QRadioButton *radioButtonEn;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *putSomme;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *putInteret;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *putAnnee;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuInformation;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(523, 564);
        MainWindow->setStyleSheet(QString::fromUtf8("*{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 0, 0);\n"
"	font: 700 12pt \"Segoe UI\";\n"
"}\n"
"#label_4{\n"
"	font: 800 26pt \"Segoe UI\";\n"
"	margin: 0.5em;\n"
"	margin-top: 0.2em;\n"
"	padding:0.2em;\n"
"	border: 2px solid rgb(255, 255, 255);\n"
"}\n"
"QPushButton{\n"
"	margin : 1.5em;\n"
"	margin-bottom: 0.2em;\n"
"	padding: 0.4em;\n"
"	background-color: rgb(57, 0, 170);\n"
"	border: 2px solid rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(50, 0, 150);\n"
"	border: 1px solid rgb(150, 150, 150);\n"
"}\n"
"QtextBrowser{\n"
"	background-color:black;\n"
"	font: 700 15pt \"Segoe UI\";\n"
"}\n"
"QRadioButton{\n"
"	font: 600 8pt \"Segoe UI\";\n"
"}\n"
"\n"
""));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName("actionInfo");
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName("actionQuitter");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        layoutLangue = new QVBoxLayout();
        layoutLangue->setObjectName("layoutLangue");
        radioButtonFr = new QRadioButton(centralwidget);
        radioButtonFr->setObjectName("radioButtonFr");
        radioButtonFr->setStyleSheet(QString::fromUtf8(""));

        layoutLangue->addWidget(radioButtonFr);

        radioButtonEn = new QRadioButton(centralwidget);
        radioButtonEn->setObjectName("radioButtonEn");
        radioButtonEn->setStyleSheet(QString::fromUtf8("left: 530px;"));

        layoutLangue->addWidget(radioButtonEn);


        verticalLayout_2->addLayout(layoutLangue);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_4->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        verticalLayout_2->addWidget(label_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        putSomme = new QDoubleSpinBox(centralwidget);
        putSomme->setObjectName("putSomme");
        putSomme->setMaximum(5000000000.000000000000000);

        horizontalLayout->addWidget(putSomme);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        putInteret = new QDoubleSpinBox(centralwidget);
        putInteret->setObjectName("putInteret");
        putInteret->setMaximum(100.000000000000000);

        horizontalLayout_2->addWidget(putInteret);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        putAnnee = new QSpinBox(centralwidget);
        putAnnee->setObjectName("putAnnee");

        horizontalLayout_3->addWidget(putAnnee);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout_3);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMaximumSize(QSize(16777215, 200));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        textBrowser->setReadOnly(true);

        verticalLayout_2->addWidget(textBrowser);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setAutoRepeatDelay(306);

        verticalLayout_2->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 523, 27));
        menuInformation = new QMenu(menuBar);
        menuInformation->setObjectName("menuInformation");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuInformation->menuAction());
        menuInformation->addSeparator();
        menuInformation->addSeparator();
        menuInformation->addAction(actionInfo);
        menuInformation->addAction(actionQuitter);

        retranslateUi(MainWindow);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionInfo->setText(QCoreApplication::translate("MainWindow", "Informations", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        radioButtonFr->setText(QCoreApplication::translate("MainWindow", "Francais", nullptr));
        radioButtonEn->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Calculette d'amortissement", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Somme du pr\303\252t :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Taux d'int\303\252rets :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ann\303\251es :", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:12pt; font-weight:700; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        menuInformation->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
