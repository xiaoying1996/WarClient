#include "ScenarioEdit.h"
#include<io.h>
#include<iostream>
#include<filesystem>
using namespace std;

int SelectDir() {

	for (auto& i : filesystem::directory_iterator("Model")) {
		string path = i.path().string();
		string extensionStr = i.path().extension().string();
	}
	return 0;
}


ScenarioEdit::ScenarioEdit(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	ModelTree = new QTreeWidget(this);
	ModelTree->resize(300, 1100);
	ModelTree->move(0, 150);
	ModelTree->show();
	ModelTree->setHeaderHidden(true);
	head = new QTreeWidgetItem();
	head->setText(0, "Model");
	ModelTree->addTopLevelItem(head);
	CreateModelTree("Model");
	ui.cmdEdit->setText("�޲���");
	setMouseTracking(true);
	ui.frame->setMouseTracking(true);
	settingChoose = new SettingChoose();
	settingChoose->hide();
	connect(settingChoose, SIGNAL(sig_Choosed(int)), this, SLOT(slot_doChoose(int)));
	//connect(ui.frame, SIGNAL(mousePressEvent(QEvent *)), this, SLOT(slot_mouseMove(QEvent *)));
	//ui.label->setScaledContents(true);
	myCursor = new QCursor(QPixmap("Data\\icon\\BaseObject.jpg").scaled(40,40,Qt::KeepAspectRatioByExpanding) , -1, -1);
}

ScenarioEdit::~ScenarioEdit()
{}

int ScenarioEdit::CreateModelTree(string dir)
{
	
	for (auto& i : filesystem::directory_iterator(dir)) {
		string path = i.path().string();
		string extensionStr = i.path().extension().string();
		QStringList pathList = QString::fromStdString(path).split("\\");
		int listSize = pathList.size();
		string currentPath = pathList[listSize - 1].toStdString();
		string parentPath = pathList[listSize - 2].toStdString();
		QStringList modelNameList = QString::fromStdString(currentPath).split(".");
		string currentModelName = modelNameList[0].toStdString();
		if (extensionStr == "")
		{
			QTreeWidgetItem* child = new QTreeWidgetItem();
			child->setText(0, QString::fromStdString(currentPath));
			head = *(ModelTree->findItems(QString::fromStdString(parentPath),Qt::MatchFlag::MatchContains ,0).begin());
			head->addChild(child);
			head = child;
			CreateModelTree(path);
		}
		else
		{
			QTreeWidgetItem* child = new QTreeWidgetItem();
			child->setText(0, QString::fromStdString(currentModelName));
			connect(ModelTree, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(on_ModelName_clicked(QTreeWidgetItem*, int)));//������¼����źŲۻ���
			//head = *(ModelTree->findItems(QString::fromStdString(parentPath), Qt::MatchFlag::MatchContains, 0).begin());
			head->addChild(child);
		}
	}
	return 0;
}

//����ģ������(ѡ��)�Ĳۺ���
void ScenarioEdit::on_ModelName_clicked(QTreeWidgetItem* item, int i)
{
	QString modelName = item->text(0);
	currentItem = item;
	mouse = PutModel;
	ui.cmdEdit->setText("����ģ��: " + item->text(0));
	if (currentIcon != nullptr)
	{
		delete currentIcon;
		QString iconPath = "Data\\icon\\" + currentItem->text(0) + ".jpg";
		currentIcon = new QIcon(iconPath);
	}
	else
	{
		QString iconPath = "Data\\icon\\" + currentItem->text(0) + ".jpg";
		currentIcon = new QIcon(iconPath);
		
	}
	
}

void ScenarioEdit::on_actionOpen_triggered()
{
	QString filename = QFileDialog::getOpenFileName(0, "���ļ�", "Data\\scenario", "JSON Files(*.json)",
		0, 0);
	//cout << filename.toStdString();
	//1.�������ϵ�ͼ�궼���
	//2.��ģ������ռ�õ��ڴ�delete
	for (auto iter = modelMap.begin(); iter != modelMap.end(); iter++)
	{
		iter.key()->hide();
		if (iter.key() != nullptr)
		{
			delete iter.key();
			iter.value().clear();
			QMap<QString,QString> test;
			iter.value().swap(test);
		}
	}
	modelMap.clear();
	//���붨�е����ݶ�д���ڴ���
	//��ͼ����ʾ�ڽ�����
	//������������
	QFile file(filename);
	file.open(QIODevice::ReadOnly);
	QByteArray data = file.readAll();
	file.close();

	//����
	QJsonParseError parseError;
	QJsonDocument doc = QJsonDocument::fromJson(data.toStdString().c_str(), &parseError);
	if (parseError.error != QJsonParseError::NoError) {
		ui.cmdEdit->setText("��ȡ�붨�ļ�����");
			return;
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
			QPushButton* icon = new QPushButton(ui.frame);
			QMap<QString, QString> dataMap;
			for (int i = 0; i < keyList.size(); i++)
			{
				QString val = subObj.value(keyList[i]).toString();
				dataMap[keyList[i]] = val;
			}
			modelMap[icon] = dataMap;
		}
	}
	ShowIcons();
}


void ScenarioEdit::on_actionSave_triggered()
{
	DoScenarioCheck();
	QString filename = QFileDialog::getSaveFileName(0, "�����ļ�", "Data\\scenario", "JSON Files(*.json)",
		0, 0);
	cout << filename.toStdString();
	//��ģ�����ݱ���ΪJSON�ļ�
	QJsonObject obj;
	QJsonArray modelArray;
	for (auto iter = modelMap.begin(); iter != modelMap.end(); iter++)
	{
		//����BaseObject
		QMap<QString, QString> data = iter.value();
		QJsonObject sub;
		for (auto iter2 = data.begin(); iter2 != data.end(); iter2++)
		{
			sub.insert(iter2.key(), iter2.value());
		}
		modelArray.append(QJsonValue(sub));
	}

	obj.insert("BaseObject", QJsonValue(modelArray));
	//д�뵽�ļ�������Ϊinfo.json
	QJsonDocument doc(obj);
	QByteArray data = doc.toJson();
	QFile file(filename);
	bool ok = file.open(QIODevice::WriteOnly);
	if (ok)
	{
		file.write(data);
		file.close();
	}
	else
	{
		qDebug() << "write error!" << endl;
	}
	ui.cmdEdit->setText("�����붨�ļ�" + filename);
}
void ScenarioEdit::mouseMoveEvent(QMouseEvent* event)
{
	
	if (event->x() > 350 && event->x() < 1850 && event->y()>150 && event->y()<1250 && mouse == PutModel)
	{
		this->setCursor(*myCursor);
		ui.posXEdit->setText(QString::number(event->x()-350));
		ui.posYEdit->setText(QString::number(event->y()-150));
	}
	else
	{
		this->setCursor(Qt::ArrowCursor);
		ui.posXEdit->setText(QString::number(0));
		ui.posYEdit->setText(QString::number(0));
	}
}

void ScenarioEdit::ShowIcons()
{
	for (auto iter = modelMap.begin(); iter != modelMap.end(); iter++)
	{
		QMap<QString, QString> data = iter.value();
		QString name = data["Name"];
		int lon = data["LON"].toInt();
		int lat = data["LAT"].toInt();
		QPushButton *icon = iter.key();
		icon->resize(40, 40);
		icon->move(lon,lat);
		if (currentIcon != nullptr)
		{
			delete currentIcon;
			QString iconPath = "Data\\icon\\" + name + ".jpg";
			currentIcon = new QIcon(iconPath);
		}
		else
		{
			QString iconPath = "Data\\icon\\" + name + ".jpg";
			currentIcon = new QIcon(iconPath);

		}
		icon->setIcon(*currentIcon);
		setStyleSheet("background-color: rgb(255, 255, 255);");
		setStyleSheet("border:none");   //���ر߿���
		icon->setFlat(true);
		icon->show();
	}
}

void ScenarioEdit::mousePressEvent(QMouseEvent* event)
{
	switch (mouse)
	{
	case Free:
		break;
	case PutModel:
		ui.cmdEdit->setText("�Ѳ���λ: " + currentItem->text(0) + "(" +
			QString::number(event->x()) + "," + QString::number(event->y()) + ")");
		//mouse = Free;//��ǰ���״̬
		//currentItem = nullptr;
		{
			QPushButton* icon = new QPushButton(ui.frame);
			icon->resize(40, 40);
			icon->move(event->x()-370, event->y()-175);
			icon->setIcon(*currentIcon);
			setStyleSheet("background-color: rgb(255, 255, 255);");
			setStyleSheet("border:none");   //���ر߿���
			icon->setFlat(true);
			icon->show();
			connect(icon, SIGNAL(clicked()), this, SLOT(slot_ModelBtn_Clicked()));
			QMap<QString, QString> modelData;
			modelData["Name"] = currentItem->text(0);
			int id = 1;
			bool isExist = false;
			while (1)
			{
				for (int i = 0; i < IDVec.size(); i++)
				{
					if (id == IDVec[i])
						isExist = true;
				}
				if (!isExist)
				{
					break;
				}
				else
				{
					id++;
					isExist = false;
				}
			}
			IDVec.push_back(id);
			modelData["ID"] = QString::number(id);
			modelData["LON"] = QString::number(event->x()-350);
			modelData["LAT"] = QString::number(event->y()-150);
			modelData["ALT"] = QString::number(0);
			modelMap[icon] = modelData;
		}
		break;
	case ChooseDest:
		for (auto iter = modelMap.begin(); iter != modelMap.end(); iter++)
		{
			QPushButton* key = iter.key();
			if (key == currentBtn)
			{
				iter.value()["DestLon"] = QString::number(event->x());
				iter.value()["DestLat"] = QString::number(event->y());
				iter.value()["Destalt"] = QString::number(0);
				ui.cmdEdit->setText("�����յ�ɹ�");
				break;
			}
		}
		mouse = Free;
		currentBtn = nullptr;
		break;
	default:
		break;
	}
}

void ScenarioEdit::on_mouseBackButton_clicked()
{
	ui.cmdEdit->setText("���ָ�");
	mouse = Free;//��ǰ���״̬
	currentItem = nullptr;
	myCursor = nullptr;
	currentIcon = nullptr;
}

void ScenarioEdit::slot_ModelBtn_Clicked()
{
	mouse = SetModel;
	currentBtn = qobject_cast<QPushButton*>(sender());
	settingChoose->show();
}

void ScenarioEdit::slot_doChoose(int i)
{
	switch (i)
	{
	case 1:
		ChooseModelDest();
		break;
	default:
		break;
	}
}

void ScenarioEdit::ChooseModelDest()
{
	mouse = ChooseDest;
	ui.cmdEdit->setText("ѡ��ģ�͵��յ�");
	settingChoose->hide();
}

void ScenarioEdit::DoScenarioCheck()
{
	for (auto iter = modelMap.begin(); iter != modelMap.end(); iter++)
	{
		QMap<QString, QString>* map = &(iter.value());
		if (map->find("DestLat") == map->end())
		{
			(* map)["DestLat"] = "0";
		}
		if (map->find("DestLon") == map->end())
		{
			(*map)["DestLon"] = "0";
		}
		if (map->find("DestAlt") == map->end())
		{
			(*map)["DestAlt"] = "0";
		}
	}
}