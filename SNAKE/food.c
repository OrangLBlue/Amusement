#include "food.h"
#include "game.h"
#include "snake.h"
#include "CSnake.h"
#include "malloc.h"
#include "rng.h"
#include "lcd.h"
#include "text.h"

Food* g_pFoodPlace = NULL;

void NewFood(void)//��ʳ��Ĳ���
{	
	int nRow;
	int nCol;
	Snake* pNode = g_pSHead;
	g_pFoodPlace = (Food*)mymalloc(SRAMEX,sizeof(Food));//Ϊ�洢ʳ�������Ϣ����һ�οռ�
	if (NULL == g_pFoodPlace)
	{
		POINT_COLOR = RED;
		Show_Str(296, 48,24,240,"ʳ������ʧ��", 24, 1);
		return;
	}
	mymemset(g_pFoodPlace, 0, sizeof(Food));

RSTFLAGE:
	pNode = g_pSHead;
	//�������ʳ���λ��
	nRow = RNG_Get_RandomNum() % (GAME_ROWS - 2) + 1;
	nCol = RNG_Get_RandomNum() % (GAME_COLS - 2) + 1;

	while (NULL != pNode)
	{
		if (pNode->S_nCol == nCol && pNode->S_nRow == nRow)//�ж���ʳ���Ƿ��������غϣ�
		{
			goto RSTFLAGE;//���غ������²���
		}
		pNode = pNode->next;
	}
	g_pFoodPlace->F_nRow = nRow;
	g_pFoodPlace->F_nCol = nCol;
}

void ShowFood(void)
{
	POINT_COLOR = GRED;
	Show_Str(g_pFoodPlace->F_nRow*16, g_pFoodPlace->F_nCol*16,16,16,"��", 16, 0);
}
