#include "Situation2D.h"

Situation2D::Situation2D(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Situation2D::~Situation2D()
{}

void Situation2D::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    //绘制矩形边框,矩形边框为红色，宽度为5
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(5);
    painter.setPen(pen);
    //painter.drawPixmap()
    for (auto iter = modelList.begin(); iter != modelList.end(); iter++)
    {
        int x = (*iter)->GetPos().lon;
        int y = (*iter)->GetPos().lat;
        painter.drawRect(x,y,10,10);
        painter.drawText(x , y , (*iter)->GetName());
    }
}

void Situation2D::SetModels(QVector<BaseObject*> &modelList)
{
    this->modelList = modelList;
    this->repaint();
}