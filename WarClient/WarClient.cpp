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
    //����������λ�����б�
    SelfServialTable = new QTableWidget(this);
    SelfServialTable->resize(600, 500);
    SelfServialTable->move(1000, 100);
    SelfServialTable->setColumnCount(3);
    QStringList table_h_headers;
    table_h_headers << "��λ����" << "��λID"<<"����ֵ";
    SelfServialTable->setHorizontalHeaderLabels(table_h_headers);
    //ui.SelfModelWidget->addWidget(SelfServialTable);
    SelfServialTable->verticalHeader()->setHidden(true);
    
    //����������λ�����б�
    SelfDestoryedTable = new QTableWidget(this);
    SelfDestoryedTable->resize(600, 500);
    SelfDestoryedTable->move(1000, 100);
    SelfDestoryedTable->setColumnCount(3);
    table_h_headers.clear();
    table_h_headers << "��λ����" << "��λID" << "���˷�ʽ";
    SelfDestoryedTable->setHorizontalHeaderLabels(table_h_headers);
    //ui.SelfModelWidget->addWidget(SelfDestoryedTable);
    SelfDestoryedTable->setHorizontalHeaderLabels(table_h_headers);
    SelfServialTable->show();
    SelfDestoryedTable->hide();

    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :ϵͳ��ʼ��ʼ��");
    ui.EngineStatusEdit->setText("ֹͣ");
    if (warEngine == nullptr)
    {
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :�������������");
        warEngine = new WarEngine(this);
        if (warEngine->GetCreateStatus())
        {
            ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :" + warEngine->GetFailString());
            //�����źŲۣ����淢��ϵͳ��־�Ĵ���
            connect(warEngine, SIGNAL(SendMsgLog(QString)), this, SLOT(slot_EngineMsgRecved(QString)));
            //�����źŲۣ����淢��ϵͳʱ��Ĵ���
            connect(warEngine, SIGNAL(SendSysTime(QString)), this, SLOT(slot_EngineTimeRecved(QString)));
            //�����źŲۣ�����ģ��������ݵĴ���
            connect(warEngine, SIGNAL(SendModelLog(QString)), this, SLOT(slot_EngineModelRecved(QString)));
        }
        else {
            ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :" + warEngine->GetFailString());
        }  
    }
    else
    {
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :��������ظ�����");
    }
    connect(this, SIGNAL(sig_posEnable(int)), warEngine, SLOT(slot_ChangePosEnable(int)));
    connect(this, SIGNAL(sig_attackEnable(int)), warEngine, SLOT(slot_ChangePosEnable(int)));
    connect(this, SIGNAL(sig_destoryEnable(int)), warEngine, SLOT(slot_ChangePosEnable(int)));
    connect(this, SIGNAL(sig_cmdEnable(int)), warEngine, SLOT(slot_ChangePosEnable(int)));
    connect(ui.LengthBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_LengthChanged()));
    connect(this, SIGNAL(sig_SengLength(int)), warEngine, SLOT(slot_LengthChanged(int)));

    //Tcp��ز���
    netManager = new NetManager(this);
    netManager->Init();
}

//������ģ�Ͱ�ť�Ĳۺ���
void WarClient::on_AddModelBtn_clicked()
{
    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :��ʾ���ģ�ʹ���");
    addModel = new AddModel();
    addModel->show();
}

//����붨�༭��ť�Ĳۺ���
void WarClient::on_ScenarioEditBtn_clicked()
{
    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :��ʾ�붨�༭����");
    scenarioEdit = new ScenarioEdit();
    scenarioEdit->show();
}

void WarClient::on_OpenScenBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0, "���ļ�", "Data\\scenario", "JSON Files(*.json)",
        0, 0);
    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :���붨�ļ�:" + filename);
    warEngine->SetScenarioDir(filename);
    isScenarioOpen = true;
}

//����������еĲۺ���
void WarClient::on_StartEngineBtn_clicked()
{
    if (!isScenarioOpen)
    {
        QMessageBox::StandardButton result = QMessageBox::warning(this, "��������ʧ��", "ԭ��:δ���붨�ļ�");
        return;
    }
    if (!warEngine->GetCreateStatus())
    {
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :" + warEngine->GetFailString());
        QMessageBox::StandardButton result = QMessageBox::warning(this, "���洴��ʧ��", "ԭ��:" + warEngine->GetFailString());
        return;
    }
    warEngine->SetCampID(ui.CampBox->currentText().toInt());
    if (warEngine->Start())
    {
        ui.EngineStatusEdit->setText("����");
        engineStatus = true;
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :���濪ʼ����");
        ui.ServialModelBtn->setText("�ִ�װ��: " + QString::fromStdString(to_string(warEngine->GetServialModelCount())));
    }
    else {
        ui.EngineStatusEdit->setText("����");
        engineStatus = false;
        ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + " :���濪ʼ����ʧ��");
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
    //int row = SelfServialTable->rowCount();//��ȡ����е�ǰ������
    //SelfServialTable->setRowCount(row + 1);//��һ
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
    //����һ�����⣬�����������������ʱ����һ�������ڿ��ܺ��������꣬�ͻ��������
    //��һ��ѭ����������סÿ��ѭ�����е�ʱ�䣬���ǳ�������ʱ�䣬�������һ�Σ����ǲ��㲽��ʱ�䣬����delay��������ʱ��
    QVector<BaseObject *> objects = warEngine->GetAllModels();
    if (situation2D != nullptr)
    {
        situation2D->SetModels(objects);
    }
    netManager->SendEntityToServer(objects);
    ui.MsgLogEdit->append(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss") + ": " + "���������������ʵ��������" + QString::number(objects.size()));
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
        ui.ConnectStatusLab->setText("����");
    }
    else {
        ui.ConnectStatusLab->setText("�Ͽ�");
    }
    netManager->FirstConnect(ui.CampBox->currentText().toInt());
}