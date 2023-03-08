#include "SettingChoose.h"

SettingChoose::SettingChoose(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

SettingChoose::~SettingChoose()
{}

void SettingChoose::on_ChooseDestBtn_clicked()
{
	/*
	* 1:模型选择终点
	*/
	emit sig_Choosed(1);
}
