/********************************************************************************
** Form generated from reading UI file 'ScenarioEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENARIOEDIT_H
#define UI_SCENARIOEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
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

class Ui_ScenarioEditClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QLabel *label;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *posXEdit;
    QLineEdit *posYEdit;
    QLineEdit *cmdEdit;
    QPushButton *mouseBackButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ScenarioEditClass)
    {
        if (ScenarioEditClass->objectName().isEmpty())
            ScenarioEditClass->setObjectName(QStringLiteral("ScenarioEditClass"));
        ScenarioEditClass->resize(1920, 1350);
        ScenarioEditClass->setMinimumSize(QSize(1920, 1350));
        ScenarioEditClass->setMaximumSize(QSize(1920, 1350));
        ScenarioEditClass->setMouseTracking(true);
        ScenarioEditClass->setTabletTracking(false);
        actionOpen = new QAction(ScenarioEditClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(ScenarioEditClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(ScenarioEditClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMouseTracking(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 300, 70));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        label->setFont(font);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(350, 100, 1500, 1100));
        frame->setStyleSheet(QStringLiteral("#frame{border:4px solid rgb(200,200,255)} "));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1400, 60, 60, 30));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1460, 60, 40, 30));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1600, 60, 40, 30));
        posXEdit = new QLineEdit(centralWidget);
        posXEdit->setObjectName(QStringLiteral("posXEdit"));
        posXEdit->setGeometry(QRect(1500, 60, 100, 30));
        posXEdit->setContextMenuPolicy(Qt::DefaultContextMenu);
        posYEdit = new QLineEdit(centralWidget);
        posYEdit->setObjectName(QStringLiteral("posYEdit"));
        posYEdit->setGeometry(QRect(1640, 60, 100, 30));
        posYEdit->setContextMenuPolicy(Qt::DefaultContextMenu);
        cmdEdit = new QLineEdit(centralWidget);
        cmdEdit->setObjectName(QStringLiteral("cmdEdit"));
        cmdEdit->setGeometry(QRect(300, 1200, 800, 50));
        mouseBackButton = new QPushButton(centralWidget);
        mouseBackButton->setObjectName(QStringLiteral("mouseBackButton"));
        mouseBackButton->setGeometry(QRect(350, 50, 150, 46));
        ScenarioEditClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ScenarioEditClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 37));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        ScenarioEditClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ScenarioEditClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ScenarioEditClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ScenarioEditClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ScenarioEditClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionSave);

        retranslateUi(ScenarioEditClass);

        QMetaObject::connectSlotsByName(ScenarioEditClass);
    } // setupUi

    void retranslateUi(QMainWindow *ScenarioEditClass)
    {
        ScenarioEditClass->setWindowTitle(QApplication::translate("ScenarioEditClass", "\346\203\263\345\256\232\347\274\226\350\276\221", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("ScenarioEditClass", "\346\211\223\345\274\200", Q_NULLPTR));
        actionSave->setText(QApplication::translate("ScenarioEditClass", "\344\277\235\345\255\230", Q_NULLPTR));
        label->setText(QApplication::translate("ScenarioEditClass", "      \346\250\241\345\236\213\345\210\227\350\241\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("ScenarioEditClass", "Pos:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ScenarioEditClass", "x:", Q_NULLPTR));
        label_4->setText(QApplication::translate("ScenarioEditClass", "y:", Q_NULLPTR));
        mouseBackButton->setText(QApplication::translate("ScenarioEditClass", "\351\274\240\346\240\207\346\201\242\345\244\215", Q_NULLPTR));
        menu->setTitle(QApplication::translate("ScenarioEditClass", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScenarioEditClass: public Ui_ScenarioEditClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENARIOEDIT_H
