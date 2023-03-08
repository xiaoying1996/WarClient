#include "WarClient.h"

WarClient::WarClient(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    init();

}

WarClient::~WarClient()
{}

void WarClient::init()
{
    //创建己方单位生存列表
    SelfServialTable = new QTableWidget(this);
    SelfServialTable->resize(600, 500);
    SelfServialTable->move(1000, 100);
    SelfServialTable->setColumnCount(3);
    QStringList table_h_headers;
    table_h_headers << "单位名称" << "单位ID"<<"生命值";
    SelfServialTable->setHorizontalHeaderLabels(table_h_headers);
    //ui.SelfModelWidget->addWidget(SelfServialTable);
    SelfServialTable->verticalHeader()->setHidden(true);
    
    //创建己方单位毁伤列表
    SelfDestoryedTable = new QTableWidget(this);
    SelfDestoryedTable->resize(600, 500);
    SelfDestoryedTable->move(1000, 100);
    SelfDestoryedTable->setColumnCount(3);
    table_h_headers.clear();
    table_h_headers << "单位名称" << "单位ID" << "毁伤方式";
    SelfDestoryedTable->setHorizontalHeaderLabels(table_h_headers);
    //ui.SelfModelWidget->addWidget(SelfDestoryedTable);
    SelfDestoryedTable->setHorizontalHeaderLabels(table_h_headers);
    SelfServialTable->show();
    SelfDestoryedTable->hide();

    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :系统开始初始化");
    ui.EngineStatusEdit->setText("停止");
    if (warEngine == nullptr)
    {
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :引擎对象生成中");
        warEngine = new WarEngine(this);
        if (warEngine->GetCreateStatus())
        {
            ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :" + warEngine->GetFailString());
            //连接信号槽，引擎发送系统日志的处理
            connect(warEngine, SIGNAL(SendMsgLog(QString)), this, SLOT(slot_EngineMsgRecved(QString)));
            //连接信号槽，引擎发送系统时间的处理
            connect(warEngine, SIGNAL(SendSysTime(QString)), this, SLOT(slot_EngineTimeRecved(QString)));
            //连接信号槽，引擎模型相关数据的处理
            connect(warEngine, SIGNAL(SendModelLog(QString)), this, SLOT(slot_EngineModelRecved(QString)));
        }
        else {
            ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :" + warEngine->GetFailString());
        }  
    }
    else
    {
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :引擎对象重复生成");
    }
    connect(this, SIGNAL(sig_posEnable(int)), warEngine, SLOT(slot_ChangePosEnable(int)));
    connect(this, SIGNAL(sig_attackEnable(int)), warEngine, SLOT(slot_ChangePosEnable(int)));
    connect(this, SIGNAL(sig_destoryEnable(int)), warEngine, SLOT(slot_ChangePosEnable(int)));
    connect(this, SIGNAL(sig_cmdEnable(int)), warEngine, SLOT(slot_ChangePosEnable(int)));
    connect(ui.LengthBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_LengthChanged()));
    connect(this, SIGNAL(sig_SengLength(int)), warEngine, SLOT(slot_LengthChanged(int)));

    //Tcp相关操作
    netManager = new NetManager(this);
    netManager->Init();
}

//点击添加模型按钮的槽函数
void WarClient::on_AddModelBtn_clicked()
{
    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :显示添加模型窗口");
    addModel = new AddModel();
    addModel->show();
}

//点击想定编辑按钮的槽函数
void WarClient::on_ScenarioEditBtn_clicked()
{
    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :显示想定编辑窗口");
    scenarioEdit = new ScenarioEdit();
    scenarioEdit->show();
}

void WarClient::on_OpenScenBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0, "打开文件", "Data\\scenario", "JSON Files(*.json)",
        0, 0);
    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :打开想定文件:" + filename);
    warEngine->SetScenarioDir(filename);
    isScenarioOpen = true;
}

//点击引擎运行的槽函数
void WarClient::on_StartEngineBtn_clicked()
{
    if (!isScenarioOpen)
    {
        QMessageBox::StandardButton result = QMessageBox::warning(this, "引擎启动失败", "原因:未打开想定文件");
        return;
    }
    if (!warEngine->GetCreateStatus())
    {
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :" + warEngine->GetFailString());
        QMessageBox::StandardButton result = QMessageBox::warning(this, "引擎创建失败", "原因:" + warEngine->GetFailString());
        return;
    }
    warEngine->SetCampID(ui.CampBox->currentText().toInt());
    if (warEngine->Start())
    {
        ui.EngineStatusEdit->setText("运行");
        engineStatus = true;
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :引擎开始运行");
        ui.ServialModelBtn->setText("现存装备: " + QString::fromStdString(to_string(warEngine->GetServialModelCount())));
    }
    else {
        ui.EngineStatusEdit->setText("故障");
        engineStatus = false;
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :引擎开始运行失败");
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :" + warEngine->GetRunFaultString());
    }
}

void WarClient::on_ServialModelBtn_clicked()
{
    SelfServialTable->show();
    SelfDestoryedTable->hide();
}

void WarClient::on_DestoryedModelBtn_clicked()
{
    SelfServialTable->hide();
    SelfDestoryedTable->show();
}

void WarClient::on_Situation2DBtn_clicked()
{
    situation2D = new Situation2D();
    situation2D->show();
}

void WarClient::slot_EngineMsgRecved(QString msg)
{
    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + ": " + msg);
}

void WarClient::slot_EngineTimeRecved(QString msg)
{
    static bool isFirst = true;
    ui.SystemTimeEdit->setText(msg);
    //int row = SelfServialTable->rowCount();//获取表格中当前总行数
    //SelfServialTable->setRowCount(row + 1);//加一
    if (isFirst)
    {
        SelfServialTable->setRowCount(warEngine->GetServialModelCount());
        for (int i = 0; i < warEngine->GetServialModelCount(); i++)
        {
            QString modelName = warEngine->GetModelNameByIndex(i);
            int ID = warEngine->GetModelIdByIndex(i);
            SelfServialTable->setItem(i, 0, new QTableWidgetItem(modelName));
            SelfServialTable->setItem(i, 1, new QTableWidgetItem(QString::number(ID)));
        }
        isFirst = false;
    }
    //存在一个问题，当这里的数据量过大时，在一个步长内可能函数处理不完，就会出现问题
    //做一个循环函数，记住每次循环运行的时间，若是超过步长时间，则进行下一次，若是不足步长时间，则用delay函数补足时间
    QVector<BaseObject *> objects = warEngine->GetAllModels();
    if (situation2D != nullptr)
    {
        situation2D->SetModels(objects);
    }
    netManager->SendEntityToServer(objects);
    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + ": " + "向服务器发送所有实体数量：" + QString::number(objects.size()));
}

void WarClient::slot_EngineModelRecved(QString msg)
{
    ui.ModelLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + ": " + msg);
}

void WarClient::on_PosBox_toggled()
{
    int i =ui.PosBox->checkState();
    emit sig_posEnable(i);
}
void WarClient::on_attackBox_toggled()
{
    int i = ui.attackBox->checkState();
    emit sig_attackEnable(i);
}
void WarClient::on_destoryBox_toggled()
{
    int i = ui.destoryBox->checkState();
    emit sig_destoryEnable(i);
}
void WarClient::on_cmdBox_toggled()
{
    int i = ui.cmdBox->checkState();
    emit sig_cmdEnable(i);
}

void WarClient::slot_LengthChanged()
{
    emit sig_SengLength(ui.LengthBox->currentText().toInt());
}

void WarClient::on_ConnectBtn_clicked()
{
    if (netManager->ConnectToServer(ui.ServerIPEdit->text()))
    {
        ui.ConnectStatusLab->setText("连接");
    }
    else {
        ui.ConnectStatusLab->setText("断开");
    }
    netManager->FirstConnect(ui.CampBox->currentText().toInt());
}