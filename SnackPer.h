#pragma once
#include <graphics.h>
#include "Settings.h"
#include "SnackPer.h"

class SnackPer
{
private:
	Settings aiSettings;
	//是否是蛇头
	bool isHead;
	//边长
	int snackPerSide;
	//蛇的边距
	int padding;
	//蛇头的颜色
	int snackHeadColor;
	//蛇身的颜色
	int snackColor;
	//正在移动的方向(1：上、2：右、3：下、4：左)
	int movingDirection;
	//上一个单位蛇xy
	int frontX;
	int frontY;


public:

	//左上角坐标
	int x;
	int y;


	//设置x,y
	void setXY(int X, int Y);

	//获得x
	int getX();
	//获得y
	int getY();

	//更新自身
	void snackPerUpdate();

	//绘制自身
	void snackPerDraw();

	//获得移动方向
	int getMovingDirection();

	//设置移动方向
	void setMovingDirection(int mvgdrcn);

	//设置蛇头
	void setHead(bool ih);
	//获得蛇头状态
	bool getHead();

	//设置储存上一个单位蛇的x,y值
	void setFrontXY(int x, int y);

	SnackPer();
	SnackPer(int x, int y);
	~SnackPer();
};

