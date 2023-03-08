#pragma once
#include <QString>
struct Pos {
	double lon;
	double lat;
	double alt;
};

struct Speed3D {
	double speedLon;
	double speedLat;
	double speedAlt;
};

struct EntityData {
	QString EntityName;
	int ID;
	int Camp;
	Pos pos;
	Speed3D speed;
};