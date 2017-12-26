#pragma once
#include "SnackPer.h"
#include "Settings.h"
#include <vector>
using namespace std;

class Snack
{
private:

	Settings aiSettings;


	//列表中单位蛇数目
	int count;

	//设置所有单位蛇的储存上一个单位蛇xy的属性
	void setAllSnackFrontXY();

public:
	//蛇列表
	vector<SnackPer> snackList;

	//单位蛇数加1
	void addSnackPer();

	//重置整条蛇
	void resetAllSnack();

	//更新整条蛇
	void updateAllSnack();

	//绘制整条蛇
	void drawAllSnack();


	//获得蛇列表元素数目
	int getCount();

	Snack();
	~Snack();
};

