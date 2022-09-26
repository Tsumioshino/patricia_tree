/********************************************************************************
** Form generated from reading UI file 'gerandodot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GERANDODOT_H
#define UI_GERANDODOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_GerandoDot
{
public:
    QPlainTextEdit *plain;

    void setupUi(QDialog *GerandoDot)
    {
        if (GerandoDot->objectName().isEmpty())
            GerandoDot->setObjectName(QString::fromUtf8("GerandoDot"));
        GerandoDot->resize(400, 300);
        plain = new QPlainTextEdit(GerandoDot);
        plain->setObjectName(QString::fromUtf8("plain"));
        plain->setGeometry(QRect(10, 10, 381, 281));

        retranslateUi(GerandoDot);

        QMetaObject::connectSlotsByName(GerandoDot);
    } // setupUi

    void retranslateUi(QDialog *GerandoDot)
    {
        GerandoDot->setWindowTitle(QCoreApplication::translate("GerandoDot", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GerandoDot: public Ui_GerandoDot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GERANDODOT_H
