#pragma once
class Settings
{
private:

	//窗口
	int winWidth;
	int winHeight;

	//游戏速度
	int speed;

	/*蛇*/
	int snackPerSide;
	int snackPadding;
	int snackColor;
	int snackHeadColor;
	//初始单位蛇的个数
	int snackPerInitCount;

	/*食物*/
	int foodSize;
	int foodScore;
	int foodColor;
	//屏幕上同时显示的食物数
	int foodNum;

	/*文字*/
	int textColor;
	int textPadding;
	int textScoreXY;

public:

	int getSpeed();
	int getSnackPerSide();
	int getSnackPerPadding();
	int getSnackColor();
	int getSnackHeadColor();
	int getFoodSize();
	int getFoodScore();
	int getFoodColor();
	int getSnackPerInitCount();
	int getFoodNum();
	int getTextColor();
	int getTextPadding();
	int getScoreXY();
	int getWidth();
	int getHeight();

	//设置窗口宽高
	void setWidth(int w);
	void setHeight(int h);

	Settings();
	~Settings();
};

