#include "BaseObject.h"

Pos BaseObject::Move()
{
	if (pos.lon > destPos.lon && destPos.lon != 0)
	{
		pos.lon -= speed.speedLon;
	}
	else if (pos.lon < destPos.lon && destPos.lon != 0)
	{
		pos.lon += speed.speedLon;
	}
	if (pos.lat > destPos.lat && destPos.lat != 0)
	{
		pos.lat -= speed.speedLat;
	}
	else if (pos.lat < destPos.lat && destPos.lat != 0)
	{
		pos.lat += speed.speedLat;
	}
	if (pos.alt > destPos.alt && destPos.alt != 0)
	{
		pos.alt -= speed.speedAlt;
	}
	else if (pos.alt < destPos.alt && destPos.alt != 0)
	{
		pos.alt += speed.speedAlt;
	}
	Pos _pos;
	_pos.lon = pos.lon;
	_pos.lat = pos.lat;
	_pos.alt = pos.alt;
	return _pos;

}

string BaseObject::ToString()
{
	return "Ãû³Æ: " + name + "   ID: " + to_string(ID) + "   Camp:" + to_string(campID);
}

void BaseObject::SetPos(Pos pos)
{
	this->pos = pos;
}
void BaseObject::SetDestPos(Pos pos)
{
	this->destPos = pos;
}

void BaseObject::SetSpeed(Speed3D speed)
{
	this->speed = speed;
}

void BaseObject::SetCamp(int i)
{
	campID = i;
}
int BaseObject::GetCamp()
{
	int camp = campID;
	return camp;
}

int BaseObject::GetTypeID()
{
	int i = typeID;
	return i;
}
void BaseObject::SetTypeID(int type)
{
	typeID = type;
}

Pos BaseObject::GetPos()
{
	Pos _pos = pos;
	return _pos;
}