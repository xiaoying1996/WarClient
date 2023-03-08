/********************************************************************************
** Form generated from reading UI file 'AddModel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMODEL_H
#define UI_ADDMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddModelClass
{
public:

    void setupUi(QWidget *AddModelClass)
    {
        if (AddModelClass->objectName().isEmpty())
            AddModelClass->setObjectName(QStringLiteral("AddModelClass"));
        AddModelClass->resize(600, 400);

        retranslateUi(AddModelClass);

        QMetaObject::connectSlotsByName(AddModelClass);
    } // setupUi

    void retranslateUi(QWidget *AddModelClass)
    {
        AddModelClass->setWindowTitle(QApplication::translate("AddModelClass", "\346\267\273\345\212\240\346\250\241\345\236\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddModelClass: public Ui_AddModelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMODEL_H
