/********************************************************************************
** Form generated from reading UI file 'mostradot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOSTRADOT_H
#define UI_MOSTRADOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MostraDot
{
public:
    QPushButton *fechar;
    QPlainTextEdit *dotEdit;
    QPushButton *b_copy;

    void setupUi(QDialog *MostraDot)
    {
        if (MostraDot->objectName().isEmpty())
            MostraDot->setObjectName(QString::fromUtf8("MostraDot"));
        MostraDot->resize(787, 560);
        fechar = new QPushButton(MostraDot);
        fechar->setObjectName(QString::fromUtf8("fechar"));
        fechar->setGeometry(QRect(690, 520, 89, 25));
        dotEdit = new QPlainTextEdit(MostraDot);
        dotEdit->setObjectName(QString::fromUtf8("dotEdit"));
        dotEdit->setGeometry(QRect(10, 10, 771, 501));
        b_copy = new QPushButton(MostraDot);
        b_copy->setObjectName(QString::fromUtf8("b_copy"));
        b_copy->setGeometry(QRect(478, 520, 161, 25));

        retranslateUi(MostraDot);

        QMetaObject::connectSlotsByName(MostraDot);
    } // setupUi

    void retranslateUi(QDialog *MostraDot)
    {
        MostraDot->setWindowTitle(QCoreApplication::translate("MostraDot", "Dialog", nullptr));
        fechar->setText(QCoreApplication::translate("MostraDot", "Fechar", nullptr));
        b_copy->setText(QCoreApplication::translate("MostraDot", "Copiar Clipboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MostraDot: public Ui_MostraDot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOSTRADOT_H
