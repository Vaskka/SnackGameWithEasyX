#include "stdafx.h"
#include "Settings.h"

/*
int Settings::getWinWidth()
{
	return this->winWidth;
}

int Settings::getWinHeight()
{
	return this->winHeight;
}
*/

int Settings::getSpeed()
{
	return this->speed;
}

int Settings::getSnackPerSide()
{
	return this->snackPerSide;
}

int Settings::getSnackPerPadding()
{
	return this->snackPadding;
}

int Settings::getSnackColor()
{
	return this->snackColor;
}

int Settings::getSnackHeadColor()
{
	return this->snackHeadColor;
}

int Settings::getFoodSize()
{
	return this->foodSize;
}

int Settings::getFoodScore()
{
	return this->foodScore;
}

int Settings::getFoodColor()
{
	return this->foodColor;
}

int Settings::getSnackPerInitCount()
{
	return this->snackPerInitCount;
}

int Settings::getFoodNum()
{
	return this->foodNum;
}

int Settings::getTextColor()
{
	return this->textColor;
}

int Settings::getTextPadding()
{
	return this->textPadding;
}

int Settings::getScoreXY()
{
	return this->textScoreXY;
}

int Settings::getWidth()
{
	return this->winWidth;
}

int Settings::getHeight()
{
	return this->winHeight;
}

void Settings::setWidth(int w)
{
	this->winWidth = w;
}

void Settings::setHeight(int h)
{
	this->winHeight = h;
}

Settings::Settings()
{
	//窗口
	winWidth = 600;
	winHeight = 600;
	//游戏速度
	speed = 300;

	//蛇
	snackPerSide = 15;
	snackPadding = 2;
	snackColor = 0x33CC33;
	snackHeadColor = 0xAAAAAA;
	snackPerInitCount = 5;

	//食物
	foodSize = 15;
	foodScore = 1000;
	foodColor = 0x3344FF;
	foodNum = 1;

	/*文字*/
	textColor = 0xCCFF66;
	textPadding = 20;
	textScoreXY = 10;

}


Settings::~Settings()
{
}
