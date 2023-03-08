#pragma once

#include <QObject>
#include <QtNetwork/QtNetwork>
#include <QVector>
#include "WarEngine.h"
#include "PublicStruct/Data.h"
#include "Model/BaseObject.h"


class NetManager  : public QObject
{
	Q_OBJECT

public:
	NetManager(QObject *parent);
	~NetManager();
	void Init();
	bool ConnectToServer(QString hostIP);
	void FirstConnect(int Camp);
	void SendEntityToServer(QVector<BaseObject*> &datas);

private:
	QTcpSocket* warSocket = nullptr;
};
