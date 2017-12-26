#pragma once
#include "Food.h"
#include "Settings.h"
#include "Snack.h"
#include <vector>
using namespace std;

class FoodList
{
private:
	//设置
	Settings aiSettings;

	//食物列表中元素数目
	int count;
	

public:
	//食物列表
	vector<Food> food;

	//绘制所有食物
	void drawAllFood();
	//重置食物列表
	void resetFoodList(Snack s);
	//获得列表元素数量
	int getCount();
	//删除列表中指定索引的食物
	void deleteIndexFood(int n);
	//获得食物列表浅表副本
	Food* copy();

	FoodList();
	~FoodList();
};

