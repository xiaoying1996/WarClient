/********************************************************************************
** Form generated from reading UI file 'Situation2D.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SITUATION2D_H
#define UI_SITUATION2D_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Situation2DClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Situation2DClass)
    {
        if (Situation2DClass->objectName().isEmpty())
            Situation2DClass->setObjectName(QStringLiteral("Situation2DClass"));
        Situation2DClass->resize(1600, 1200);
        Situation2DClass->setMinimumSize(QSize(1600, 1200));
        Situation2DClass->setMaximumSize(QSize(1600, 1200));
        centralWidget = new QWidget(Situation2DClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Situation2DClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Situation2DClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 37));
        Situation2DClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Situation2DClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Situation2DClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Situation2DClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Situation2DClass->setStatusBar(statusBar);

        retranslateUi(Situation2DClass);

        QMetaObject::connectSlotsByName(Situation2DClass);
    } // setupUi

    void retranslateUi(QMainWindow *Situation2DClass)
    {
        Situation2DClass->setWindowTitle(QApplication::translate("Situation2DClass", "Situation2D", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Situation2DClass: public Ui_Situation2DClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SITUATION2D_H
