// SnackGameEasyX.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define WIDTH  600
#define HEIGHT 600

int main()
{
	SnackGame myGame = SnackGame(WIDTH, HEIGHT);
	myGame.runGame();

    return 0;
}

