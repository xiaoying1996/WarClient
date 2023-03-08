#pragma once

//该带码将程序设置为中文,使中文不乱码
#if defined(_MSC_VER) && (_MSC_VER >= 1600)    
# pragma execution_character_set("utf-8")    
#endif

#include <string>
#include <QString>
#include "../PublicStruct/Data.h"

using namespace std;

class BaseObject
{
public:
	Pos Move();
	string ToString();
	void SetName(string nameStr) { name = nameStr; }
	void SetID(int IDVal) { ID = IDVal; }
	QString GetName() { return QString::fromStdString(this->name); }
	int GetID() { return ID; }
	void SetPos(Pos pos);
	void SetDestPos(Pos pos);
	void SetSpeed(Speed3D speed);
	void SetCamp(int i);
	int GetCamp();
	int GetTypeID();
	void SetTypeID(int type);
	Pos GetPos();
private:
	Pos pos;
	Pos destPos;
	Speed3D speed;
	int ID;
	int campID;
	int typeID;
	string name;
};

