#pragma once

#include <QMainWindow>
#include "ui_SettingChoose.h"

class SettingChoose : public QMainWindow
{
	Q_OBJECT

public:
	SettingChoose(QWidget *parent = nullptr);
	~SettingChoose();

private:
	Ui::SettingChooseClass ui;

signals:
	void sig_Choosed(int i);

private slots:
	void on_ChooseDestBtn_clicked();
};
