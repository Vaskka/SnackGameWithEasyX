#include "stdafx.h"
#include "SnackGame.h"
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <tchar.h>
//键盘键值
#define KEY_UP     119 //w
#define KEY_RIGHT  100 //d
#define KEY_DOWN   115 //s
#define KEY_LEFT   97  //a
#define START_GAME 32
//文字常量
#define GAMEOVER "Game Over!"
#define NAV_GAME "press SPACE to start"

void SnackGame::updateSnack()
{


	//检查是否吃到食物
	int i = 0;
	while (true)
	{
		if (checkFoodSnackPerCollide(this->myFoodList.food[i], this->mySnack.snackList[0]))
		{
			//分数增加
			this->score += this->aiSettings.getFoodScore();
			//删除吃掉的食物
			this->myFoodList.deleteIndexFood(i);
			//蛇长度+1
			this->mySnack.addSnackPer();

			i--;
		}
		i++;
		if (i >= this->myFoodList.getCount())
			break;
	}

	/*是否与边界碰撞*/
	//左右边界传送门
	if(this->mySnack.snackList[0].getX() + this->aiSettings.getSnackPerSide() > this->width)
	{
		int newX = this->mySnack.snackList[0].getX() - this->width;
		int newY = this->mySnack.snackList[0].getY();

		this->mySnack.snackList[0].setXY(newX, newY);
	}

	if (this->mySnack.snackList[0].getX() + this->aiSettings.getSnackPerSide() < 0)
	{
		int newX = this->mySnack.snackList[0].getX() + this->width;
		int newY = this->mySnack.snackList[0].getY();
		this->mySnack.snackList[0].setXY(newX, newY);
	}
	//上下边界死亡
	if (this->mySnack.snackList[0].getY() < 0 || this->mySnack.snackList[0].getY() > this->height)
	{
		this->resetGame(this->mySnack);
		return;
	}

	//蛇撞自己死亡
	if (this->checkSnackHeadBodyCollide())
		this->resetGame(this->mySnack);

	//更新并绘制蛇
	this->mySnack.drawAllSnack();
	this->mySnack.updateAllSnack();

}

//更新食物
void SnackGame::updateFood(Snack mySnack)
{
	if (this->myFoodList.getCount() == 0)
	{
		this->myFoodList.resetFoodList(mySnack); 
	}


	for (int i = 0; i < this->myFoodList.getCount(); i++)
	{
		this->myFoodList.food[i].drawFood();
	}

}

//吃到食物而加分
void SnackGame::foodAddScore()
{
	this->score += this->aiSettings.getFoodScore();
}

//处理按键事件
void SnackGame::handleKeyDownEvent(int key)
{

	switch (key)
	{
	case KEY_UP:
		if ((this->mySnack.snackList[0].getMovingDirection() != 3) && this->activity)
		{
			this->mySnack.snackList[0].setMovingDirection(1);
		}
		break;
	case KEY_RIGHT:
		if ((this->mySnack.snackList[0].getMovingDirection() != 4) && this->activity)
		{
			this->mySnack.snackList[0].setMovingDirection(2);
		}
		break;
	case KEY_DOWN:
		if ((this->mySnack.snackList[0].getMovingDirection() != 1) && this->activity)
		{
			this->mySnack.snackList[0].setMovingDirection(3);
		}
		break;
	case KEY_LEFT:
		if ((this->mySnack.snackList[0].getMovingDirection() != 2) && this->activity)
		{
			this->mySnack.snackList[0].setMovingDirection(4);
		}
		break;
	case START_GAME:
		if (!(this->activity))
		{
			this->activity = true;
			this->score = 0;
		}
		break;

	}

}

//检查上午蛇是否碰撞
bool SnackGame::checkFoodSnackPerCollide(Food f, SnackPer s)
{
	//食物的定位点
	int lux, ldx, rux, rdx;
	int luy, ldy, ruy, rdy;

	lux = f.getX();
	luy = f.getY();

	rux = f.getX() + this->aiSettings.getFoodSize();
	ruy = f.getY();

	ldx = f.getX();
	ldy = f.getY() + this->aiSettings.getFoodSize();

	rdx = f.getX() + this->aiSettings.getFoodSize();
	rdy = f.getY() + this->aiSettings.getFoodSize();

	int mx = (lux + rux) / 2;
	int my = luy;

	if (checkPointInSnackPer(lux, luy, s) ||
		checkPointInSnackPer(rux, ruy, s) || 
		checkPointInSnackPer(ldx, ldy, s) || 
		checkPointInSnackPer(rdx, rdy, s) ||
		checkPointInSnackPer(mx, my, s))
		return true;

	return false;
}

//检查蛇头是否与身体碰撞
bool SnackGame::checkSnackHeadBodyCollide()
{
	//构造定位点
	int lux, ldx, rux, rdx;
	int luy, ldy, ruy, rdy;

	lux = this->mySnack.snackList[0].getX();
	luy = this->mySnack.snackList[0].getY();

	rux = this->mySnack.snackList[0].getX() + this->aiSettings.getSnackPerSide();
	ruy = this->mySnack.snackList[0].getY();

	ldx = this->mySnack.snackList[0].getX();
	ldy = this->mySnack.snackList[0].getY() + this->aiSettings.getSnackPerSide();

	rdx = this->mySnack.snackList[0].getX() + this->aiSettings.getSnackPerSide();
	rdy = this->mySnack.snackList[0].getY() + this->aiSettings.getSnackPerSide();

	for (int i = 1; i < this->mySnack.getCount(); i++)
	{
		if (checkPointInSnackPer(lux, luy, this->mySnack.snackList[i]) ||
			checkPointInSnackPer(rux, ruy, this->mySnack.snackList[i]) ||
			checkPointInSnackPer(ldx, ldy, this->mySnack.snackList[i]) ||
			checkPointInSnackPer(rdx, rdy, this->mySnack.snackList[i]))
			return true;
	}

	return false;
}

//检查某点是否在单位蛇内
bool SnackGame::checkPointInSnackPer(int x, int y, SnackPer d) 
{
	int left = d.getX();
	int right = d.getX() + this->aiSettings.getSnackPerSide();
	int up = d.getY();
	int down = d.getY() + this->aiSettings.getSnackPerSide();

	if ((x >= left && x <= right) && (y >= up && y <= down))
		return true;

	return false;
}

//重置游戏
void SnackGame::resetGame(Snack mySnack)
{
	this->activity = false;
	this->mySnack.resetAllSnack();
	this->myFoodList.resetFoodList(mySnack);
	this->isFirst = false;


}

//显示分数
void SnackGame::showScore()
{
	TCHAR scoreText[2333];
	_stprintf(scoreText, _T("Score:%d"), this->score);
	outtextxy(this->aiSettings.getScoreXY(), this->aiSettings.getScoreXY(), scoreText);

}


//游戏主循环
void SnackGame::runGame()
{
	initgraph(this->width, this->height);
	
	//游戏主循环
	while (true)
	{

		if (_kbhit())
		{
			//获取按键并处理
			int key = _getch();
			this->handleKeyDownEvent(key);
		}

		if (this->activity) 
		{
			//更新蛇
			this->updateSnack();
			//更新食物
			this->updateFood(this->mySnack);
			//显示文字
			this->showScore();
			//延时
			Sleep(this->aiSettings.getSpeed());
			//清屏
			cleardevice();

		}
		else
		{
			//如果第一次游戏
			if (this->isFirst)
			{
				settextcolor(this->textColor);
				moveto(this->width / 2, this->height / 2);
				outtext(_T(NAV_GAME));
			}
			else
			{
				moveto(this->width / 2, this->height / 2);
				outtext(_T(GAMEOVER));
				moveto(this->width / 2, this->height / 2 + this->aiSettings.getTextPadding());
				outtext(_T(NAV_GAME));
				moveto(this->width / 2, this->height / 2 + 2 * this->aiSettings.getTextPadding());
				outtext(_T("Score:"));
				TCHAR s[2333];
				_stprintf(s, _T("%d"), this->score);
				outtext(s);
			}
		}

	}


}

SnackGame::SnackGame(int width, int height)
{
	this->aiSettings = Settings();
	aiSettings.setWidth(width);
	aiSettings.setHeight(height);
	this->score = 0;
	this->activity = false;
	this->width = width;
	this->height = height;
	this->mySnack = Snack();
	this->myFoodList = FoodList();
	this->isFirst = true;
	this->textColor = this->aiSettings.getTextColor();
}


SnackGame::~SnackGame()
{
}
