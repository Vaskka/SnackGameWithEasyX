#include "stdafx.h"
#include "FoodList.h"
#include "Settings.h"
#include <cstdlib>
#include <ctime>

//画出所有食物
void FoodList::drawAllFood()
{
	for (int i = 0; i < this->count; i++)
	{
		this->food[i].drawFood();
	}

}

//重置食物列表
void FoodList::resetFoodList(Snack s)
{
	srand((unsigned)time(NULL));
	this->count = this->aiSettings.getFoodNum();

	for (int i = 0; i < this->count; i++)
	{
		bool flag;
		int x, y;
		//确保每个食物的坐标不会重复以及食物不会刷新在蛇身上
		do 
		{
			flag = false;
			x = rand() % (this->aiSettings.getWidth() - this->aiSettings.getFoodSize());
			y = rand() % (this->aiSettings.getWidth() - this->aiSettings.getFoodSize());
			//防止食物刷新在蛇身上
			int lux = x;
			int luy = y;
			int rux = x + this->aiSettings.getFoodSize();
			int ruy = y;
			int ldx = x;
			int ldy = y + this->aiSettings.getFoodSize();
			int rdx = x + this->aiSettings.getFoodSize();
			int rdy = y + this->aiSettings.getFoodSize();
			for (int i = 0; i < s.snackList.size(); i++)
			{
				//构造每个单位蛇的定位点
				int top = s.snackList[i].y;
				int right = s.snackList[i].x + this->aiSettings.getSnackPerSide();
				int bottom = s.snackList[i].y + this->aiSettings.getSnackPerSide();
				int left = s.snackList[i].x;

				if (((lux >= left && lux <= right) && (luy >= top && luy <= bottom)) ||
					((rux >= left && rux <= right) && (ruy >= top && ruy <= bottom)) ||
					((ldx >= left && ldx <= right) && (ldy >= top && ldy <= bottom)) ||
					((rdx >= left && rdx <= right) && (rdy >= top && rdy <= bottom)))
				{
					//若出现碰撞
					flag = true;
					break;
				}


			}

			//检查食物重叠
			for (int j = 0; j < i; j++)
			{
				if (this->food[j].getX() == x || this->food[j].getY() == y)
				{
					//若重复(概率较小)
					flag == true;
					break;
				}

			}
		} while (flag);

		Food newFood = Food();
		newFood.setX(x);
		newFood.setY(y);
		this->food[i] = newFood;

	}

}

int FoodList::getCount()
{
	return this->count;
}

//删除食物列表某个索引的食物
void FoodList::deleteIndexFood(int n)
{
	if (n < 0 || n >= this->count)
	{
		throw ("要删除的索引不在列表中");
		return;
	}
	else
	{
		this->food.erase(this->food.begin() + n);
		this->count--;
	}

}

//获得食物列表的浅表副本
Food * FoodList::copy()
{
	Food* CopyFoodList = new Food[this->count];
	for (int i = 0; i < this->count; i++)
	{
		CopyFoodList[i] = this->food[i];
	}

	return CopyFoodList;
	
}

FoodList::FoodList()
{
	srand((unsigned)time(NULL));
	this->aiSettings = Settings();
	this->count = this->aiSettings.getFoodNum();
	this->food = vector<Food>(2333);
	//初始化食物列表
	for (int i = 0; i < this->count; i++)
	{
		this->food[i] = Food();
	}
	
	//初始化食物坐标
	for (int i = 0; i < this->count; i++)
	{
		bool flag;
		int x, y;
		//确保每个食物的坐标不会重叠，且不会与蛇重叠
		do
		{
			flag = false;
			x = rand() % (this->aiSettings.getWidth() - this->aiSettings.getFoodSize());
			y = rand() % (this->aiSettings.getWidth() - this->aiSettings.getFoodSize());

			//避免食物刷在蛇身上
			int top = this->aiSettings.getHeight() / 2;
			int right = this->aiSettings.getWidth() / 2 + this->aiSettings.getSnackPerSide();
			int bottom = this->aiSettings.getHeight() / 2 + this->aiSettings.getSnackPerInitCount() * this->aiSettings.getSnackPerSide();
			int left = this->aiSettings.getWidth() / 2;

			int lux = x;
			int luy = y;
			int rux = x + this->aiSettings.getFoodSize();
			int ruy = y;
			int ldx = x;
			int ldy = y + this->aiSettings.getFoodSize();
			int rdx = x + this->aiSettings.getFoodSize();
			int rdy = y + this->aiSettings.getFoodSize();

			if (((lux >= left && lux <= right) && (luy >= top && luy <= bottom)) ||
				((rux >= left && rux <= right) && (ruy >= top && ruy <= bottom)) ||
				((ldx >= left && ldx <= right) && (ldy >= top && ldy <= bottom)) ||
				((rdx >= left && rdx <= right) && (rdy >= top && rdy <= bottom)))
				flag = true;

			//避免食物重叠
			for (int j = 0; j < i; j++)
			{
				if (this->food[j].getX() == x || this->food[j].getY() == y)
				{
					flag == true;
					break;
				}
			}
		} while (flag);

		this->food[i].setX(x);
		this->food[i].setY(y);

	}



}


FoodList::~FoodList()
{
}
