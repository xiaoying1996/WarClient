/********************************************************************************
** Form generated from reading UI file 'SettingChoose.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGCHOOSE_H
#define UI_SETTINGCHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingChooseClass
{
public:
    QWidget *centralWidget;
    QPushButton *ChooseDestBtn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SettingChooseClass)
    {
        if (SettingChooseClass->objectName().isEmpty())
            SettingChooseClass->setObjectName(QStringLiteral("SettingChooseClass"));
        SettingChooseClass->resize(500, 1000);
        SettingChooseClass->setMinimumSize(QSize(500, 1000));
        SettingChooseClass->setMaximumSize(QSize(500, 1000));
        centralWidget = new QWidget(SettingChooseClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ChooseDestBtn = new QPushButton(centralWidget);
        ChooseDestBtn->setObjectName(QStringLiteral("ChooseDestBtn"));
        ChooseDestBtn->setGeometry(QRect(0, 0, 200, 50));
        SettingChooseClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SettingChooseClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SettingChooseClass->setStatusBar(statusBar);

        retranslateUi(SettingChooseClass);

        QMetaObject::connectSlotsByName(SettingChooseClass);
    } // setupUi

    void retranslateUi(QMainWindow *SettingChooseClass)
    {
        SettingChooseClass->setWindowTitle(QApplication::translate("SettingChooseClass", "\351\200\211\351\241\271", Q_NULLPTR));
        ChooseDestBtn->setText(QApplication::translate("SettingChooseClass", "\351\200\211\346\213\251\347\273\210\347\202\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingChooseClass: public Ui_SettingChooseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGCHOOSE_H
