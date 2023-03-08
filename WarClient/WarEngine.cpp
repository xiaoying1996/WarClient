#include "WarEngine.h"

WarEngine::WarEngine(QObject *parent)
	: QObject(parent)
{
	//��������Ҫ���Ĺ���:
	createStatus = true;
	failString = "������������";
}

WarEngine::~WarEngine()
{
	PutOutModel();
}

bool WarEngine::Start()
{
	runStatus = true;
	m_pTimer = new QTimer(this);
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
	int out_time = 1000;
	m_pTimer->start(out_time);
	emit SendMsgLog("��ʱ�������ɹ�������" + QString::number(out_time) + "ms");

	ReadScenario();

	if(PutInModel())
		return true;
	else
	{
		return false;
	}
}

bool WarEngine::GetCreateStatus()
{
	return createStatus;
}

QString WarEngine::GetFailString()
{
	return failString;
}

QString WarEngine::GetRunFaultString()
{
	return runFaultString;
}

bool WarEngine::PutInModel()
{
	/*BaseObject* obj1 = new BaseObject();
	obj1->SetName("���Ե�Ԫ1");
	obj1->SetID(1);
	modelList.push_back(obj1);
	emit SendMsgLog("����ģ��: " + QString::fromStdString(obj1->ToString()));

	BaseObject* obj2 = new BaseObject();
	obj2->SetName("���Ե�Ԫ2");
	obj2->SetID(2);
	modelList.push_back(obj2);
	emit SendMsgLog("����ģ��: " + QString::fromStdString(obj2->ToString()));*/
	return true;
}

bool WarEngine::PutOutModel()
{
	if (modelList.size())
	{
		for (auto iter = modelList.begin(); iter != modelList.end(); iter++)
		{
			delete *iter;
		}
	}
	modelList.clear();
	return true;
}

int WarEngine::GetServialModelCount()
{
	return modelList.size();
}

QString WarEngine::GetModelNameByIndex(int i)
{
	if (modelList.size() > i)
	{
		QString name_Return = modelList[i]->GetName();
		return name_Return;
	}
	else {
		return "Խ��ֵ";
	}
}

int WarEngine::GetModelIdByIndex(int i)
{
	if (modelList.size() > i)
	{
		int ID_Return = modelList[i]->GetID();
		return ID_Return;
	}
	else {
		return 0;
	}
}

void WarEngine::handleTimeout()
{
	emit SendSysTime(QDateTime::currentDateTime().toString(" yyyy-MM-dd hh:mm:ss"));
	//ִ������ģ�͵�Move����
	string moveDataStr = "\n ";
	if (modelList.size())
	{
		for (int i = 0; i < modelList.size(); i++)
		{
			moveDataStr += modelList[i]->ToString();
			moveDataStr += " Move ";
			Pos pos = modelList[i]->Move();
			moveDataStr +=
				("����" + to_string(pos.lon) +
					" γ��" + to_string(pos.lat) +
					" �߶�" + to_string(pos.alt)) + "\n";
		}
	}
	if(posEnable)
		emit SendModelLog(QString::fromStdString(moveDataStr));
}

QString WarEngine::GetScenarioDir()
{
	return scenarioFileDir;
}
void WarEngine::SetScenarioDir(QString filename)
{
	scenarioFileDir = filename;
}

void WarEngine::ReadScenario()
{
	QFile file(scenarioFileDir);
	file.open(QIODevice::ReadOnly);
	QByteArray data = file.readAll();
	file.close();

	//����
	QJsonParseError parseError;
	QJsonDocument doc = QJsonDocument::fromJson(data.toStdString().c_str(), &parseError);
	if (parseError.error != QJsonParseError::NoError) {
		emit SendMsgLog("�����ȡ�붨�ļ�����");
		return;
	}
	else
	{
		emit SendMsgLog("�����ȡ�붨�ļ��ɹ�");
	}
	QJsonObject obj = doc.object();
	if (obj.contains("BaseObject"))
	{
		QJsonValue arrayTemp = obj.value("BaseObject");
		QJsonArray array = arrayTemp.toArray();
		for (int i = 0; i < array.size(); i++)
		{
			QJsonValue sub = array.at(i);
			QJsonObject subObj = sub.toObject();
			QStringList keyList = subObj.keys();
			BaseObject* obj = new BaseObject();
			Pos pos;
			Pos destpos;
			for (int i = 0; i < keyList.size(); i++)
			{
				QString val = subObj.value(keyList[i]).toString();
				if (keyList[i] == "Name")
					obj->SetName(val.toStdString());
				else if (keyList[i] == "ID")
					obj->SetID(val.toInt());
				else if(keyList[i] == "LON")
				{
					pos.lon = val.toInt();
				}
				else if(keyList[i] == "LAT")
				{
					pos.lat = val.toInt();
				}
				else if(keyList[i] == "ALT")
				{ 
					pos.alt = val.toInt();
				}
				else if (keyList[i] == "DestLon")
				{
					destpos.lon = val.toInt();
				}
				else if (keyList[i] == "DestLat")
				{
					destpos.lat = val.toInt();
				}
				else if (keyList[i] == "DestAlt")
				{
					destpos.alt = val.toInt();
				}
			}
			obj->SetPos(pos);
			obj->SetDestPos(destpos);
			Speed3D speed;
			speed.speedLon = 1;
			speed.speedLat = 1;
			speed.speedAlt = 0;
			obj->SetSpeed(speed);
			obj->SetCamp(campID);
			obj->SetTypeID(1);
			modelList.push_back(obj);
			emit SendMsgLog("���붨����ģ��: " + QString::fromStdString(obj->ToString()));
		}
	}
}

void WarEngine::slot_ChangePosEnable(int i)
{
	if (i == 0)
		posEnable = false;
	if (i == 2)
		posEnable = true;
}
void WarEngine::slot_ChangeAttackEnable(int i)
{
	if (i == 0)
		attackEnable = false;
	if (i == 2)
		attackEnable = true;
}
void WarEngine::slot_ChangeDestoryEnable(int i)
{
	if (i == 0)
		destoryEnable = false;
	if (i == 2)
		destoryEnable = true;
}
void WarEngine::slot_ChangeCmdEnable(int i)
{
	if (i == 0)
		cmdEnable = false;
	if (i == 2)
		cmdEnable = true;
}

void WarEngine::SetCampID(int i)
{
	campID = i;
}
int WarEngine::GetCampID()
{
	int i = campID;
	return i;
}

QVector<BaseObject*>& WarEngine::GetAllModels()
{
	return modelList;
}

void WarEngine::slot_LengthChanged(int i)
{
	m_pTimer->setInterval(i);
}