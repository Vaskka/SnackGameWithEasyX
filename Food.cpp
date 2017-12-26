#include "stdafx.h"
#include "Food.h"
#include "graphics.h"

//绘制食物
void Food::drawFood()
{

	//设置食物矩形的样式并画出矩形
	setfillcolor(this->foodColor);
	setlinecolor(this->foodColor);
	fillrectangle(
		this->x,
		this->y,
		this->x + this->foodSide,
		this->y + this->foodSide
	);

}

void Food::setX(int X)
{
	this->x = X;
}

void Food::setY(int Y)
{
	this->y = Y;
}

int Food::getX()
{
	return this->x;
}

int Food::getY()
{
	return this->y;
}

Food::Food()
{
	aiSettings = Settings();
	this->foodSide = aiSettings.getFoodSize();
	this->foodColor = aiSettings.getFoodColor();
	this->x = 0;
	this->y = 0;
}


Food::~Food()
{
}
