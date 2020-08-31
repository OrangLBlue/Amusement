// snake.cpp : 定义控制台应用程序的入口点。
//
#include "CSnake.h"
#include "game.h"
#include "rng.h"
#include "lcd.h"

void RunSnake(void)
{
	while (g_nData)
	{
		u8 uDegree = 0;
		uDegree = SnakeBegin();
		GameInit();
		Run(uDegree);
	}
}
