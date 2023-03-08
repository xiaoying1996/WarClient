#pragma once

//�ô��뽫��������Ϊ����,ʹ���Ĳ�����
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
	//���붨�е�ģ�ͼ�������
	bool PutInModel();
	//�������е�ģ���ͷ�
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
	void handleTimeout();  //��ʱ������ 
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
	QString failString;		//����ɹ����ɻ�������ʧ�ܵ�ԭ��
	QString runFaultString;	//�������й����г��ֹ��ϵ�ԭ��
	QString scenarioFileDir;
	QVector<BaseObject*> modelList;//�洢�붨������ģ�͵�����

signals:
	void SendMsgLog(QString);
	void SendSysTime(QString);
	void SendModelLog(QString);
};
