#include "food.h"
#include "game.h"
#include "snake.h"
#include "CSnake.h"
#include "malloc.h"
#include "rng.h"
#include "lcd.h"
#include "text.h"

Food* g_pFoodPlace = NULL;

void NewFood(void)//新食物的产出
{	
	int nRow;
	int nCol;
	Snake* pNode = g_pSHead;
	g_pFoodPlace = (Food*)mymalloc(SRAMEX,sizeof(Food));//为存储食物相关信息申请一段空间
	if (NULL == g_pFoodPlace)
	{
		POINT_COLOR = RED;
		Show_Str(296, 48,24,240,"食物申请失败", 24, 1);
		return;
	}
	mymemset(g_pFoodPlace, 0, sizeof(Food));

RSTFLAGE:
	pNode = g_pSHead;
	//随机产出食物的位置
	nRow = RNG_Get_RandomNum() % (GAME_ROWS - 2) + 1;
	nCol = RNG_Get_RandomNum() % (GAME_COLS - 2) + 1;

	while (NULL != pNode)
	{
		if (pNode->S_nCol == nCol && pNode->S_nRow == nRow)//判断新食物是否于蛇体重合，
		{
			goto RSTFLAGE;//若重合则重新产出
		}
		pNode = pNode->next;
	}
	g_pFoodPlace->F_nRow = nRow;
	g_pFoodPlace->F_nCol = nCol;
}

void ShowFood(void)
{
	POINT_COLOR = GRED;
	Show_Str(g_pFoodPlace->F_nRow*16, g_pFoodPlace->F_nCol*16,16,16,"★", 16, 0);
}
