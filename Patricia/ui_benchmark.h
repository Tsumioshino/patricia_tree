/********************************************************************************
** Form generated from reading UI file 'benchmark.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BENCHMARK_H
#define UI_BENCHMARK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BenchMark
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *output;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *b_dicionario;
    QPushButton *b_rodar;

    void setupUi(QDialog *BenchMark)
    {
        if (BenchMark->objectName().isEmpty())
            BenchMark->setObjectName(QString::fromUtf8("BenchMark"));
        BenchMark->resize(729, 464);
        verticalLayout = new QVBoxLayout(BenchMark);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        output = new QPlainTextEdit(BenchMark);
        output->setObjectName(QString::fromUtf8("output"));
        output->setReadOnly(true);

        verticalLayout->addWidget(output);

        line = new QFrame(BenchMark);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        b_dicionario = new QPushButton(BenchMark);
        b_dicionario->setObjectName(QString::fromUtf8("b_dicionario"));

        horizontalLayout->addWidget(b_dicionario);

        b_rodar = new QPushButton(BenchMark);
        b_rodar->setObjectName(QString::fromUtf8("b_rodar"));

        horizontalLayout->addWidget(b_rodar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BenchMark);

        QMetaObject::connectSlotsByName(BenchMark);
    } // setupUi

    void retranslateUi(QDialog *BenchMark)
    {
        BenchMark->setWindowTitle(QCoreApplication::translate("BenchMark", "Dialog", nullptr));
        b_dicionario->setText(QCoreApplication::translate("BenchMark", "Dicionario", nullptr));
        b_rodar->setText(QCoreApplication::translate("BenchMark", "Rodar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BenchMark: public Ui_BenchMark {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BENCHMARK_H
