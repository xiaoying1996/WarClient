#pragma once

//�ô��뽫��������Ϊ����,ʹ���Ĳ�����
#if defined(_MSC_VER) && (_MSC_VER >= 1600)    
# pragma execution_character_set("utf-8")    
#endif

#include <QMainWindow>
#include <vector>
#include "ui_ScenarioEdit.h"
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <string>
#include <QStringList>
#include <QtCore>
#include <QFileDialog>
#include <QMouseEvent>
#include <qcursor.h>
#include <QPixmap>
#include <QPushButton>
#include <QMap>
#include <QVector>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QFile>
#include <QJsonArray>
#include "SettingChoose.h"

using namespace std;

enum MouseStatus {
	Free,
	PutModel,
	SetModel,
	ChooseDest,
};

class ScenarioEdit : public QMainWindow
{
	Q_OBJECT

public:
	ScenarioEdit(QWidget *parent = nullptr);
	~ScenarioEdit();

	int CreateModelTree(string dir);
	void ShowIcons();
	void ChooseModelDest();
	void DoScenarioCheck();

private:
	Ui::ScenarioEditClass ui;
	SettingChoose* settingChoose = nullptr;
	QTreeWidget* ModelTree = nullptr;
	QTreeWidgetItem* head = nullptr;
	MouseStatus mouse = Free;//��ǰ���״̬
	QTreeWidgetItem* currentItem = nullptr;
	QCursor* myCursor = nullptr;
	QIcon* currentIcon = nullptr;
	QMap<QPushButton*, QMap<QString,QString>> modelMap;//�洢ģ�����ݵ�����
	QVector<int> IDVec;//�Ѿ�ʹ�ù���ID
	QPushButton* currentBtn = nullptr;

private slots:
	void on_ModelName_clicked(QTreeWidgetItem* item, int i);
	void on_mouseBackButton_clicked();
	void on_actionSave_triggered();
	void on_actionOpen_triggered();
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void slot_ModelBtn_Clicked();
	void slot_doChoose(int i);
};
