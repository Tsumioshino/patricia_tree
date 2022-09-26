/********************************************************************************
** Form generated from reading UI file 'resultadobusca.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTADOBUSCA_H
#define UI_RESULTADOBUSCA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ResultadoBusca
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *e_chave;
    QPlainTextEdit *e_conteudo;
    QPushButton *b_fechar;
    QLabel *label_3;
    QLineEdit *e_resultado;

    void setupUi(QDialog *ResultadoBusca)
    {
        if (ResultadoBusca->objectName().isEmpty())
            ResultadoBusca->setObjectName(QString::fromUtf8("ResultadoBusca"));
        ResultadoBusca->resize(539, 367);
        label = new QLabel(ResultadoBusca);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 60, 67, 17));
        label_2 = new QLabel(ResultadoBusca);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 100, 67, 17));
        e_chave = new QLineEdit(ResultadoBusca);
        e_chave->setObjectName(QString::fromUtf8("e_chave"));
        e_chave->setGeometry(QRect(120, 60, 391, 25));
        e_conteudo = new QPlainTextEdit(ResultadoBusca);
        e_conteudo->setObjectName(QString::fromUtf8("e_conteudo"));
        e_conteudo->setGeometry(QRect(120, 100, 391, 151));
        b_fechar = new QPushButton(ResultadoBusca);
        b_fechar->setObjectName(QString::fromUtf8("b_fechar"));
        b_fechar->setGeometry(QRect(420, 310, 89, 25));
        label_3 = new QLabel(ResultadoBusca);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 20, 67, 17));
        e_resultado = new QLineEdit(ResultadoBusca);
        e_resultado->setObjectName(QString::fromUtf8("e_resultado"));
        e_resultado->setGeometry(QRect(120, 20, 391, 25));

        retranslateUi(ResultadoBusca);

        QMetaObject::connectSlotsByName(ResultadoBusca);
    } // setupUi

    void retranslateUi(QDialog *ResultadoBusca)
    {
        ResultadoBusca->setWindowTitle(QCoreApplication::translate("ResultadoBusca", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ResultadoBusca", "Chave", nullptr));
        label_2->setText(QCoreApplication::translate("ResultadoBusca", "Conteudo", nullptr));
        b_fechar->setText(QCoreApplication::translate("ResultadoBusca", "Fechar", nullptr));
        label_3->setText(QCoreApplication::translate("ResultadoBusca", "Resultado:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultadoBusca: public Ui_ResultadoBusca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTADOBUSCA_H
