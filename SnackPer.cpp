#include "stdafx.h"
#include "SnackPer.h"

//更新单位蛇的位置
void SnackPer::snackPerUpdate()
{
	//如果是蛇头，则按方向移动
	if (this->isHead)
	{
		switch (this->movingDirection)
		{
		case 1:
			this->y -= (this->snackPerSide + this->padding);
			break;
		case 2:
			this->x += (this->snackPerSide + this->padding);
			break;
		case 3:
			this->y += (this->snackPerSide + this->padding);
			break;
		case 4:
			this->x -= (this->snackPerSide + this->padding);
		default:
			break;
		}
	}
	else
	{
		//如果是蛇身体就跃迁到储存的上一个单位蛇的位置
		this->x = this->frontX;
		this->y = this->frontY;
	}

}

//绘制自身
void SnackPer::snackPerDraw()
{
	if (this->isHead)
	{

		//设置填充颜色和画线样式
		setfillcolor(this->snackHeadColor);
		setlinecolor(this->snackHeadColor);
		//绘制填充矩形
		fillrectangle(
			this->x,
			this->y,
			this->x + this->snackPerSide,
			this->y + this->snackPerSide
		);
	}
	else
	{
		//设置填充颜色和画线样式
		setfillcolor(this->snackColor);
		setlinecolor(this->snackColor);
		//绘制填充矩形
		fillrectangle(
			this->x,
			this->y,
			this->x + this->snackPerSide,
			this->y + this->snackPerSide
		);

	}

}


void SnackPer::setXY(int X, int Y)
{
	this->x = X;
	this->y = Y;
}

int SnackPer::getX()
{
	return this->x;
}

int SnackPer::getY()
{
	return this->y;
}

int SnackPer::getMovingDirection()
{
	return this->movingDirection;
}

void SnackPer::setMovingDirection(int mvgdrcn)
{
	this->movingDirection = mvgdrcn;
}

void SnackPer::setHead(bool ih)
{
	this->isHead = ih;
}

bool SnackPer::getHead()
{
	return this->isHead;
}

void SnackPer::setFrontXY(int x, int y)
{
	this->frontX = x;
	this->frontY = y;
}

SnackPer::SnackPer()
{
	Settings aiSettings = Settings();

	this->x = this->aiSettings.getWidth() / 2;
	this->y = this->aiSettings.getHeight() / 2;
	this->isHead = false;
	this->movingDirection = 1;
	this->snackPerSide = this->aiSettings.getSnackPerSide();
	this->snackHeadColor = this->aiSettings.getSnackHeadColor();
	this->snackColor = this->aiSettings.getSnackColor();
	this->padding = this->aiSettings.getSnackPerPadding();
	this->frontX = 0;
	this->frontY = 0;

}

SnackPer::SnackPer(int x, int y):SnackPer()
{
	this->x = x;
	this->y = y;
}


SnackPer::~SnackPer()
{
}
