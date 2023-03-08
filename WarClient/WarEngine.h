#pragma once

//该带码将程序设置为中文,使中文不乱码
#if defined(_MSC_VER) && (_MSC_VER >= 1600)    
# pragma execution_character_set("utf-8")    
#endif

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QVector>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QFile>
#include <QJsonArray>
#include "Model\BaseObject.h"
class WarEngine  : public QObject
{
	Q_OBJECT

public:
	WarEngine(QObject *parent);
	~WarEngine();
	bool Start();
	bool GetCreateStatus();
	QString GetFailString();
	QString GetRunFaultString();
	//将想定中的模型加入容器
	bool PutInModel();
	//将容器中的模型释放
	bool PutOutModel();
	int GetServialModelCount();
	QString GetModelNameByIndex(int i);
	int GetModelIdByIndex(int i);
	QString GetScenarioDir();
	void SetScenarioDir(QString filename);
	void ReadScenario();
	void SetCampID(int i);
	int GetCampID();
	QVector<BaseObject*>& GetAllModels();


public slots:
	void handleTimeout();  //超时处理函数 
	void slot_ChangePosEnable(int i);
	void slot_ChangeAttackEnable(int i);
	void slot_ChangeDestoryEnable(int i);
	void slot_ChangeCmdEnable(int i);
	void slot_LengthChanged(int i);

private:
	bool createStatus;
	bool runStatus = false;
	bool isRunFault = false;
	bool posEnable = false;
	bool attackEnable = false;
	bool destoryEnable = false;
	bool cmdEnable = false;
	int campID;
	QTimer* m_pTimer;
	QString failString;		//引擎成功生成或者生成失败的原因
	QString runFaultString;	//引擎运行过程中出现故障的原因
	QString scenarioFileDir;
	QVector<BaseObject*> modelList;//存储想定中所有模型的容器

signals:
	void SendMsgLog(QString);
	void SendSysTime(QString);
	void SendModelLog(QString);
};
