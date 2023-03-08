#pragma once

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include "ui_Situation2D.h"
#include "Model\BaseObject.h"

class Situation2D : public QMainWindow
{
	Q_OBJECT

public:
	Situation2D(QWidget *parent = nullptr);
	~Situation2D();
	void paintEvent(QPaintEvent*);
	void SetModels(QVector<BaseObject*> &modelList);
private:
	Ui::Situation2DClass ui;
	QVector<BaseObject*> modelList;
};
