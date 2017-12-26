#pragma once
#include "Settings.h"
#include "Snack.h"
#include "FoodList.h"

class SnackGame
{
private:
	//设置
	Settings aiSettings;
	//游戏是否激活状态
	bool activity;
	//分数
	int score;
	//首次游戏
	bool isFirst;
	//窗口大小
	int width;
	int height;
	//文字字体颜色
	int textColor;
	//蛇
	Snack mySnack;
	//食物列表
	FoodList myFoodList;


	//更新蛇
	void updateSnack();
	
	//更新食物
	void updateFood(Snack mySnack);

	//吃到食物加分
	void foodAddScore();

	//处理按键事件
	void handleKeyDownEvent(int key);

	//检查食物与蛇的碰撞
	bool checkFoodSnackPerCollide(Food f, SnackPer s);

	//检查蛇头与蛇身的碰撞
	bool checkSnackHeadBodyCollide();

	//检查点在单位蛇矩形内
	bool checkPointInSnackPer(int x, int y, SnackPer d);

	//重置游戏
	void resetGame(Snack mySnack);

	//显示分数
	void showScore();

public:

	//运行游戏
	void runGame();

	SnackGame(int width, int height);
	~SnackGame();
};

