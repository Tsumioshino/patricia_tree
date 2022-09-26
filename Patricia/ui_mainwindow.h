/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSobre;
    QAction *actionCarregar_chaves;
    QAction *actionIniciar;
    QAction *actionSair;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *i_chave;
    QLineEdit *i_conteudo;
    QPushButton *b_inserir;
    QFrame *line;
    QLineEdit *r_chave;
    QPushButton *b_remover;
    QFrame *line_2;
    QPushButton *b_buscar;
    QLineEdit *b_chave;
    QFrame *line_3;
    QPushButton *b_mostrar;
    QPushButton *pushButton;
    QPushButton *b_dot;
    QCheckBox *b_automostra;
    QLabel *label_5;
    QLabel *l_altura;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuArquivo;
    QMenu *menuBenchMark;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1049, 634);
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName(QString::fromUtf8("actionSobre"));
        actionCarregar_chaves = new QAction(MainWindow);
        actionCarregar_chaves->setObjectName(QString::fromUtf8("actionCarregar_chaves"));
        actionIniciar = new QAction(MainWindow);
        actionIniciar->setObjectName(QString::fromUtf8("actionIniciar"));
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(150, 0));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 67, 17));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 67, 17));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 67, 17));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 270, 67, 17));
        i_chave = new QLineEdit(groupBox);
        i_chave->setObjectName(QString::fromUtf8("i_chave"));
        i_chave->setGeometry(QRect(10, 50, 113, 25));
        i_conteudo = new QLineEdit(groupBox);
        i_conteudo->setObjectName(QString::fromUtf8("i_conteudo"));
        i_conteudo->setGeometry(QRect(10, 100, 113, 25));
        b_inserir = new QPushButton(groupBox);
        b_inserir->setObjectName(QString::fromUtf8("b_inserir"));
        b_inserir->setGeometry(QRect(10, 130, 89, 25));
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 150, 151, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        r_chave = new QLineEdit(groupBox);
        r_chave->setObjectName(QString::fromUtf8("r_chave"));
        r_chave->setGeometry(QRect(10, 190, 113, 25));
        b_remover = new QPushButton(groupBox);
        b_remover->setObjectName(QString::fromUtf8("b_remover"));
        b_remover->setGeometry(QRect(10, 220, 89, 25));
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 250, 151, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        b_buscar = new QPushButton(groupBox);
        b_buscar->setObjectName(QString::fromUtf8("b_buscar"));
        b_buscar->setGeometry(QRect(10, 320, 89, 25));
        b_chave = new QLineEdit(groupBox);
        b_chave->setObjectName(QString::fromUtf8("b_chave"));
        b_chave->setGeometry(QRect(10, 290, 113, 25));
        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 350, 151, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        b_mostrar = new QPushButton(groupBox);
        b_mostrar->setObjectName(QString::fromUtf8("b_mostrar"));
        b_mostrar->setGeometry(QRect(30, 400, 89, 25));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 460, 89, 25));
        b_dot = new QPushButton(groupBox);
        b_dot->setObjectName(QString::fromUtf8("b_dot"));
        b_dot->setGeometry(QRect(30, 370, 89, 25));
        b_automostra = new QCheckBox(groupBox);
        b_automostra->setObjectName(QString::fromUtf8("b_automostra"));
        b_automostra->setGeometry(QRect(30, 430, 92, 23));
        b_automostra->setChecked(true);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 510, 67, 17));
        l_altura = new QLabel(groupBox);
        l_altura->setObjectName(QString::fromUtf8("l_altura"));
        l_altura->setGeometry(QRect(80, 510, 67, 17));

        horizontalLayout->addWidget(groupBox);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1049, 22));
        menuArquivo = new QMenu(menuBar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        menuBenchMark = new QMenu(menuBar);
        menuBenchMark->setObjectName(QString::fromUtf8("menuBenchMark"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArquivo->menuAction());
        menuBar->addAction(menuBenchMark->menuAction());
        menuArquivo->addAction(actionCarregar_chaves);
        menuArquivo->addAction(actionSobre);
        menuArquivo->addAction(actionSair);
        menuBenchMark->addAction(actionIniciar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Arvore Patricia", nullptr));
        actionSobre->setText(QCoreApplication::translate("MainWindow", "Sobre...", nullptr));
        actionCarregar_chaves->setText(QCoreApplication::translate("MainWindow", "Carregar chaves", nullptr));
        actionIniciar->setText(QCoreApplication::translate("MainWindow", "Iniciar", nullptr));
        actionSair->setText(QCoreApplication::translate("MainWindow", "Sair", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Chave", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Conteudo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Chave", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Chave", nullptr));
        b_inserir->setText(QCoreApplication::translate("MainWindow", "Inserir", nullptr));
        b_remover->setText(QCoreApplication::translate("MainWindow", "Remover", nullptr));
        b_buscar->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        b_mostrar->setText(QCoreApplication::translate("MainWindow", "Mostrar", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Limpar", nullptr));
        b_dot->setText(QCoreApplication::translate("MainWindow", "Ver DOT", nullptr));
        b_automostra->setText(QCoreApplication::translate("MainWindow", "Auto", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Altura:", nullptr));
        l_altura->setText(QString());
        menuArquivo->setTitle(QCoreApplication::translate("MainWindow", "Arquivo", nullptr));
        menuBenchMark->setTitle(QCoreApplication::translate("MainWindow", "BenchMark", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
