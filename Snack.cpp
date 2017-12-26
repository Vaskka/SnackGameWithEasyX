#include "stdafx.h"
#include "Snack.h"
#include <cstdlib>

//设置所有蛇的储存前一个单位蛇XY的坐标
void Snack::setAllSnackFrontXY()
{
	for (int i = 1; i < this->count; i++)
	{
		this->snackList[i].setFrontXY(this->snackList[i - 1].getX(), this->snackList[i - 1].getY());
	}
}

//蛇长度加1
void Snack::addSnackPer()
{
	//新的单位蛇
	SnackPer newSnackPer = SnackPer();
	int nx = this->snackList[this->count - 1].getX();
	int ny = this->snackList[this->count - 1].getY();
	newSnackPer.setXY(nx, ny);

	//蛇长度加1
	this->count++;
	this->snackList.push_back(newSnackPer);
}

void Snack::resetAllSnack()
{
	this->count = this->aiSettings.getSnackPerInitCount();
	this->snackList = vector<SnackPer>(this->aiSettings.getSnackPerInitCount());

	//初始化蛇列表
	for (int i = 0; i < this->count; i++)
	{
		this->snackList[i] = SnackPer();
	}
	//设置蛇头
	this->snackList[0].setHead(true);
	this->snackList[0].x = this->aiSettings.getWidth() / 2;
	this->snackList[0].y = this->aiSettings.getHeight() / 2;

	int dst = this->aiSettings.getSnackPerSide() + this->aiSettings.getSnackPerPadding();

	for (int i = 1; i < this->count; i++)
	{
		this->snackList[i].x = this->snackList[i - 1].x;
		this->snackList[i].y = this->snackList[i - 1].y + dst;
	}

	this->setAllSnackFrontXY();

}

//更新全部单位蛇
void Snack::updateAllSnack()
{
	for (int i = 0; i < this->count; i++)
	{
		this->snackList[i].snackPerUpdate();
	}
	//每次更新后都要再次设置储存上一个单位蛇的XY
	this->setAllSnackFrontXY();
}

//绘制全部单位蛇
void Snack::drawAllSnack()
{
	for (int i = 0; i < this->count; i++)
	{
		this->snackList[i].snackPerDraw();
	}

}


int Snack::getCount()
{
	return this->count;
}

Snack::Snack()
{
	aiSettings = Settings();
	count = this->aiSettings.getSnackPerInitCount();
	snackList = vector<SnackPer>(2333);

	//初始化蛇列表
	for (int i = 0; i < this->count; i++)
	{
		snackList[i] = SnackPer();
	}

	this->snackList[0].setHead(true);
	this->snackList[0].x = this->aiSettings.getWidth() / 2;
	this->snackList[0].y = this->aiSettings.getHeight() / 2;

	int dst =  this->aiSettings.getSnackPerSide() + this->aiSettings.getSnackPerPadding();

	for (int i = 1; i < this->count; i++)
	{
		this->snackList[i].x = this->snackList[i - 1].x;
		this->snackList[i].y = this->snackList[i - 1].y + dst;
	}

	this->setAllSnackFrontXY();

}


Snack::~Snack()
{
}
