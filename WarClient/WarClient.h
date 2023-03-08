#pragma once

//该带码将程序设置为中文,使中文不乱码
#if defined(_MSC_VER) && (_MSC_VER >= 1600)    
# pragma execution_character_set("utf-8")    
#endif

#include <QtWidgets/QMainWindow>
#include "ui_WarClient.h"
#include "UI/AddModel.h"
#include "UI/ScenarioEdit.h"
#include "UI/Situation2D.h"
#include "WarEngine.h"
#include "NetManager.h"
#include <QDateTime>
#include <QMessageBox>
#include <QTableWidget>

class WarClient : public QMainWindow
{
    Q_OBJECT

public:
    WarClient(QWidget *parent = nullptr);
    ~WarClient();

    //初始化程序
    void init();

signals:
    void sig_posEnable(int i);
    void sig_attackEnable(int i);
    void sig_destoryEnable(int i);
    void sig_cmdEnable(int i);
    void sig_SengLength(int i);

private:
    Ui::WarClientClass ui;
    AddModel *addModel = nullptr;
    ScenarioEdit* scenarioEdit = nullptr;
    Situation2D* situation2D = nullptr;
    WarEngine* warEngine = nullptr;
    NetManager* netManager = nullptr;
    bool engineStatus = false;
    QTableWidget* SelfServialTable = nullptr;
    QTableWidget* SelfDestoryedTable = nullptr;
    bool isScenarioOpen = false;
private slots:
    void on_AddModelBtn_clicked();
    void on_StartEngineBtn_clicked();
    void on_OpenScenBtn_clicked();
    void on_ServialModelBtn_clicked();
    void on_DestoryedModelBtn_clicked();
    void on_ScenarioEditBtn_clicked();
    void on_Situation2DBtn_clicked();
    void on_ConnectBtn_clicked();
    void on_PosBox_toggled();
    void on_attackBox_toggled();
    void on_destoryBox_toggled();
    void on_cmdBox_toggled();
    void slot_EngineMsgRecved(QString msg);
    void slot_EngineTimeRecved(QString msg);
    void slot_EngineModelRecved(QString msg);
    void slot_LengthChanged();
};
