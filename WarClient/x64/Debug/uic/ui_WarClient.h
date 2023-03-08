/********************************************************************************
** Form generated from reading UI file 'WarClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARCLIENT_H
#define UI_WARCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarClientClass
{
public:
    QWidget *centralWidget;
    QPushButton *AddModelBtn;
    QTextEdit *ModelLogEdit;
    QTextEdit *MsgLogEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *StartEngineBtn;
    QLabel *label_3;
    QLineEdit *EngineStatusEdit;
    QLabel *label_4;
    QLineEdit *SystemTimeEdit;
    QLabel *label_5;
    QPushButton *ServialModelBtn;
    QPushButton *DestoryedModelBtn;
    QPushButton *ScenarioEditBtn;
    QPushButton *OpenScenBtn;
    QCheckBox *PosBox;
    QCheckBox *attackBox;
    QCheckBox *destoryBox;
    QCheckBox *cmdBox;
    QComboBox *CampBox;
    QLabel *label_6;
    QPushButton *Situation2DBtn;
    QLabel *label_7;
    QComboBox *LengthBox;
    QLabel *label_8;
    QLineEdit *ServerIPEdit;
    QPushButton *ConnectBtn;
    QLabel *label_9;
    QLabel *ConnectStatusLab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WarClientClass)
    {
        if (WarClientClass->objectName().isEmpty())
            WarClientClass->setObjectName(QStringLiteral("WarClientClass"));
        WarClientClass->resize(1640, 1200);
        WarClientClass->setMinimumSize(QSize(1640, 1200));
        WarClientClass->setMaximumSize(QSize(1640, 1200));
        centralWidget = new QWidget(WarClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AddModelBtn = new QPushButton(centralWidget);
        AddModelBtn->setObjectName(QStringLiteral("AddModelBtn"));
        AddModelBtn->setGeometry(QRect(0, 0, 200, 70));
        QFont font;
        font.setPointSize(12);
        AddModelBtn->setFont(font);
        ModelLogEdit = new QTextEdit(centralWidget);
        ModelLogEdit->setObjectName(QStringLiteral("ModelLogEdit"));
        ModelLogEdit->setGeometry(QRect(0, 400, 500, 800));
        MsgLogEdit = new QTextEdit(centralWidget);
        MsgLogEdit->setObjectName(QStringLiteral("MsgLogEdit"));
        MsgLogEdit->setGeometry(QRect(500, 400, 500, 800));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 350, 200, 50));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(500, 350, 150, 50));
        StartEngineBtn = new QPushButton(centralWidget);
        StartEngineBtn->setObjectName(QStringLiteral("StartEngineBtn"));
        StartEngineBtn->setGeometry(QRect(500, 0, 200, 70));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        StartEngineBtn->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(500, 150, 200, 70));
        label_3->setFont(font1);
        EngineStatusEdit = new QLineEdit(centralWidget);
        EngineStatusEdit->setObjectName(QStringLiteral("EngineStatusEdit"));
        EngineStatusEdit->setGeometry(QRect(700, 150, 200, 70));
        EngineStatusEdit->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(500, 250, 200, 70));
        label_4->setFont(font1);
        SystemTimeEdit = new QLineEdit(centralWidget);
        SystemTimeEdit->setObjectName(QStringLiteral("SystemTimeEdit"));
        SystemTimeEdit->setGeometry(QRect(700, 250, 300, 70));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(10);
        SystemTimeEdit->setFont(font2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1000, 10, 200, 90));
        label_5->setFont(font1);
        ServialModelBtn = new QPushButton(centralWidget);
        ServialModelBtn->setObjectName(QStringLiteral("ServialModelBtn"));
        ServialModelBtn->setGeometry(QRect(1200, 10, 200, 90));
        ServialModelBtn->setFont(font1);
        DestoryedModelBtn = new QPushButton(centralWidget);
        DestoryedModelBtn->setObjectName(QStringLiteral("DestoryedModelBtn"));
        DestoryedModelBtn->setGeometry(QRect(1400, 10, 200, 90));
        DestoryedModelBtn->setFont(font1);
        ScenarioEditBtn = new QPushButton(centralWidget);
        ScenarioEditBtn->setObjectName(QStringLiteral("ScenarioEditBtn"));
        ScenarioEditBtn->setGeometry(QRect(0, 100, 200, 70));
        ScenarioEditBtn->setFont(font1);
        OpenScenBtn = new QPushButton(centralWidget);
        OpenScenBtn->setObjectName(QStringLiteral("OpenScenBtn"));
        OpenScenBtn->setGeometry(QRect(300, 0, 200, 70));
        OpenScenBtn->setFont(font1);
        PosBox = new QCheckBox(centralWidget);
        PosBox->setObjectName(QStringLiteral("PosBox"));
        PosBox->setGeometry(QRect(200, 270, 140, 30));
        attackBox = new QCheckBox(centralWidget);
        attackBox->setObjectName(QStringLiteral("attackBox"));
        attackBox->setGeometry(QRect(200, 300, 140, 30));
        destoryBox = new QCheckBox(centralWidget);
        destoryBox->setObjectName(QStringLiteral("destoryBox"));
        destoryBox->setGeometry(QRect(200, 330, 140, 30));
        cmdBox = new QCheckBox(centralWidget);
        cmdBox->setObjectName(QStringLiteral("cmdBox"));
        cmdBox->setGeometry(QRect(200, 360, 140, 30));
        CampBox = new QComboBox(centralWidget);
        CampBox->setObjectName(QStringLiteral("CampBox"));
        CampBox->setGeometry(QRect(700, 85, 100, 50));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(590, 85, 100, 50));
        label_6->setFont(font);
        Situation2DBtn = new QPushButton(centralWidget);
        Situation2DBtn->setObjectName(QStringLiteral("Situation2DBtn"));
        Situation2DBtn->setGeometry(QRect(300, 100, 200, 70));
        Situation2DBtn->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(800, 85, 100, 50));
        label_7->setFont(font);
        LengthBox = new QComboBox(centralWidget);
        LengthBox->setObjectName(QStringLiteral("LengthBox"));
        LengthBox->setGeometry(QRect(900, 85, 100, 50));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 180, 120, 30));
        ServerIPEdit = new QLineEdit(centralWidget);
        ServerIPEdit->setObjectName(QStringLiteral("ServerIPEdit"));
        ServerIPEdit->setGeometry(QRect(120, 180, 200, 30));
        ConnectBtn = new QPushButton(centralWidget);
        ConnectBtn->setObjectName(QStringLiteral("ConnectBtn"));
        ConnectBtn->setGeometry(QRect(330, 180, 60, 30));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 220, 120, 30));
        ConnectStatusLab = new QLabel(centralWidget);
        ConnectStatusLab->setObjectName(QStringLiteral("ConnectStatusLab"));
        ConnectStatusLab->setGeometry(QRect(120, 220, 100, 30));
        WarClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WarClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1640, 37));
        WarClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WarClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        WarClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WarClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WarClientClass->setStatusBar(statusBar);

        retranslateUi(WarClientClass);

        QMetaObject::connectSlotsByName(WarClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *WarClientClass)
    {
        WarClientClass->setWindowTitle(QApplication::translate("WarClientClass", "WarClient", Q_NULLPTR));
        AddModelBtn->setText(QApplication::translate("WarClientClass", "\346\250\241\345\236\213\346\267\273\345\212\240", Q_NULLPTR));
        label->setText(QApplication::translate("WarClientClass", "\346\250\241\345\236\213\346\227\245\345\277\227\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("WarClientClass", "\347\263\273\347\273\237\346\227\245\345\277\227\344\277\241\346\201\257", Q_NULLPTR));
        StartEngineBtn->setText(QApplication::translate("WarClientClass", "\350\277\220\350\241\214\345\274\225\346\223\216", Q_NULLPTR));
        label_3->setText(QApplication::translate("WarClientClass", "   \350\277\220\350\241\214\347\212\266\346\200\201:", Q_NULLPTR));
        label_4->setText(QApplication::translate("WarClientClass", "   \347\263\273\347\273\237\346\227\266\351\227\264:", Q_NULLPTR));
        label_5->setText(QApplication::translate("WarClientClass", "\346\210\221\346\226\271\345\215\225\344\275\215\346\200\273\350\247\210", Q_NULLPTR));
        ServialModelBtn->setText(QApplication::translate("WarClientClass", "\347\216\260\345\255\230\350\243\205\345\244\207", Q_NULLPTR));
        DestoryedModelBtn->setText(QApplication::translate("WarClientClass", "\346\257\201\344\274\244\350\243\205\345\244\207", Q_NULLPTR));
        ScenarioEditBtn->setText(QApplication::translate("WarClientClass", "\346\203\263\345\256\232\347\274\226\350\276\221", Q_NULLPTR));
        OpenScenBtn->setText(QApplication::translate("WarClientClass", "\346\211\223\345\274\200\346\203\263\345\256\232", Q_NULLPTR));
        PosBox->setText(QApplication::translate("WarClientClass", "\345\235\220\346\240\207", Q_NULLPTR));
        attackBox->setText(QApplication::translate("WarClientClass", "\346\224\273\345\207\273", Q_NULLPTR));
        destoryBox->setText(QApplication::translate("WarClientClass", "\346\257\201\344\274\244", Q_NULLPTR));
        cmdBox->setText(QApplication::translate("WarClientClass", "\346\214\207\344\273\244", Q_NULLPTR));
        CampBox->clear();
        CampBox->insertItems(0, QStringList()
         << QApplication::translate("WarClientClass", "1", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "2", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "3", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "4", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "5", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "6", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "7", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "8", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "9", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "10", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "11", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "12", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("WarClientClass", "\351\230\265\350\220\245:", Q_NULLPTR));
        Situation2DBtn->setText(QApplication::translate("WarClientClass", "\344\272\214\347\273\264\346\200\201\345\212\277", Q_NULLPTR));
        label_7->setText(QApplication::translate("WarClientClass", "\346\255\245\351\225\277:", Q_NULLPTR));
        LengthBox->clear();
        LengthBox->insertItems(0, QStringList()
         << QApplication::translate("WarClientClass", "1000", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "500", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "300", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "200", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "100", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "50", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "20", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "10", Q_NULLPTR)
         << QApplication::translate("WarClientClass", "5", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("WarClientClass", "\346\234\215\345\212\241\345\231\250IP:", Q_NULLPTR));
        ConnectBtn->setText(QApplication::translate("WarClientClass", "\350\277\236\346\216\245", Q_NULLPTR));
        label_9->setText(QApplication::translate("WarClientClass", "\350\277\236\346\216\245\347\212\266\346\200\201:", Q_NULLPTR));
        ConnectStatusLab->setText(QApplication::translate("WarClientClass", "\346\234\252\350\277\236\346\216\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WarClientClass: public Ui_WarClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARCLIENT_H
