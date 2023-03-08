#include "WarEngine.h"

WarEngine::WarEngine(QObject *parent)
	: QObject(parent)
{
	//生成引擎要做的工作:
	createStatus = true;
	failString = "引擎正常生成";
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
	emit SendMsgLog("定时器创建成功，步长" + QString::number(out_time) + "ms");

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
	obj1->SetName("测试单元1");
	obj1->SetID(1);
	modelList.push_back(obj1);
	emit SendMsgLog("加入模型: " + QString::fromStdString(obj1->ToString()));

	BaseObject* obj2 = new BaseObject();
	obj2->SetName("测试单元2");
	obj2->SetID(2);
	modelList.push_back(obj2);
	emit SendMsgLog("加入模型: " + QString::fromStdString(obj2->ToString()));*/
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
		return "越界值";
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
	//执行所有模型的Move函数
	string moveDataStr = "\n ";
	if (modelList.size())
	{
		for (int i = 0; i < modelList.size(); i++)
		{
			moveDataStr += modelList[i]->ToString();
			moveDataStr += " Move ";
			Pos pos = modelList[i]->Move();
			moveDataStr +=
				("经度" + to_string(pos.lon) +
					" 纬度" + to_string(pos.lat) +
					" 高度" + to_string(pos.alt)) + "\n";
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

	//解析
	QJsonParseError parseError;
	QJsonDocument doc = QJsonDocument::fromJson(data.toStdString().c_str(), &parseError);
	if (parseError.error != QJsonParseError::NoError) {
		emit SendMsgLog("引擎读取想定文件错误");
		return;
	}
	else
	{
		emit SendMsgLog("引擎读取想定文件成功");
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
			emit SendMsgLog("从想定加入模型: " + QString::fromStdString(obj->ToString()));
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