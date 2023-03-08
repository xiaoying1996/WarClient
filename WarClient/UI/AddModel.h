#pragma once

#include <QWidget>
#include "ui_AddModel.h"

class AddModel : public QWidget
{
	Q_OBJECT

public:
	AddModel(QWidget *parent = nullptr);
	~AddModel();

private:
	Ui::AddModelClass ui;
};
