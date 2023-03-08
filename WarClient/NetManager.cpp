#include "NetManager.h"

NetManager::NetManager(QObject *parent)
	: QObject(parent)
{}

NetManager::~NetManager()
{}

void NetManager::Init()
{
	warSocket = new QTcpSocket();
}

bool NetManager::ConnectToServer(QString hostIP)
{
	warSocket->connectToHost(hostIP,9000);
	return true;
}

void NetManager::FirstConnect(int Camp)
{
	QString sendStr = "";
	sendStr += "FirstConnect";
	sendStr += "*#*#";
	sendStr += "Camp";
	sendStr += "*#*#";
	sendStr += QString::number(Camp);
	QByteArray buffer = sendStr.toUtf8();
	warSocket->write(buffer);
}

void NetManager::SendEntityToServer(QVector<BaseObject*>&datas)
{
	QString sendStr = "";
	sendStr += "SendEntityToServer";
	sendStr += "*#*#";
	QString entityJson = "";
	
	QJsonObject obj;
	QJsonArray modelArray;
	for (int i = 0;i<datas.size();i++)
	{
		//生成BaseObject
		QJsonObject sub;

		sub.insert("Name", datas[i]->GetName());
		sub.insert("ID", datas[i]->GetID());
		sub.insert("Camp", datas[i]->GetCamp());
		sub.insert("Lon", datas[i]->GetPos().lon);
		sub.insert("Lat", datas[i]->GetPos().lat);
		sub.insert("Alt", datas[i]->GetPos().alt);
		
		modelArray.append(QJsonValue(sub));
	}

	obj.insert("BaseObject", QJsonValue(modelArray));
	//写入到文件，名字为info.json
	QJsonDocument doc(obj);
	QByteArray data = doc.toJson();

	QByteArray buffer = sendStr.toUtf8() + data;
	warSocket->write(buffer);
}