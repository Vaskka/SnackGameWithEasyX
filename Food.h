#pragma once
#include "Settings.h"

class Food
{
private:

	//设置
	Settings aiSettings;
	//食物边长
	int foodSide;
	//食物颜色
	int foodColor;
	//食物位置
	int x;
	int y;

public:

	//绘制食物
	void drawFood();

	//设置点
	void setX(int X);
	void setY(int Y);

	//获取点
	int getX();
	int getY();


	Food();
	~Food();
};

