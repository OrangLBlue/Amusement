#include <stdio.h>
#include <stdlib.h>
#include "mode.h"
#include "view.h"
#include "usart.h"
#include "sram.h" 
#include "led.h"
#include "lcd.h"
#include "key.h"  
#include "show_badapple.h"
#include "usmart.h"  
#include "sdio_sdcard.h"    
#include "malloc.h" 
#include "w25qxx.h"    
#include "ff.h"  
#include "exfuns.h"    
#include "fontupd.h"
#include "text.h"	
#include "timer.h"
#include "string.h"
#include "exti.h"
#include "usart3.h"
#include "voice.h"
#include "interface.h"
#include "readp.h"
#include "piclib.h"
#include "usart2.h"
#include "rng.h"


char g_chBackground[GAME_ROWS][GAME_COLS];
char g_chBrick[4][4];
int g_nShape = 0;//形状，系数16
int g_nRotate = 0;//朝向，系数4
int g_nRow = 0;
int g_nCol = 0;

char g_chBrickPool[][4] = {
	1, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0,//长条
	0, 0, 0, 0,

	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,

	1, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,

	1, 1, 1, 0,//T
	0, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	0, 1, 0, 0,
	1, 1, 0, 0,
	0, 1, 0, 0,
	0, 0, 0, 0,

	0, 1, 0, 0,
	1, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 0, 0, 0,
	1, 1, 0, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,

	1, 0, 0, 0,//L
	1, 0, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,

	1, 1, 1, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,
	0, 1, 0, 0,
	0, 1, 0, 0,
	0, 0, 0, 0,

	0, 0, 1, 0,
	1, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,//短条
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 0, 0, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 0, 0, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,//方块
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	0, 1, 0, 0,//倒L
	0, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,

	1, 0, 0, 0,
	1, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 1, 0,
	0, 0, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	
	1, 1, 0, 0,
	0, 1, 1, 0,
	0, 0, 0, 0,//Z
	0, 0, 0, 0,

	0, 1, 0, 0,
	1, 1, 0, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,

	1, 1, 0, 0,
	0, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	0, 1, 0, 0,
	1, 1, 0, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,
	
	0, 1, 1, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,//倒Z
	0, 0, 0, 0,

	1, 0, 0, 0,
	1, 1, 0, 0,
	0, 1, 0, 0,
	0, 0, 0, 0,

	0, 1, 1, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,

	1, 0, 0, 0,
	1, 1, 0, 0,
	0, 1, 0, 0,
	0, 0, 0, 0,
	
	

};



void InitBackground(void)
{
	u8 nRow;
	u8 nCol;
	for (nRow = 0; nRow < GAME_ROWS; nRow++)
	{
		for (nCol = 0; nCol < GAME_COLS; nCol++)
		{
			if (nRow == GAME_ROWS - 1
				|| nCol == 0
				|| nCol == GAME_COLS - 1)
			{
				g_chBackground[nRow][nCol] = 1;
			}
			else
			{
				g_chBackground[nRow][nCol] = 0;
			}
		}
	}
}

void GetNewBrick(void)
{
	u8 nRow;
	u8 nCol;
	u8 nShapeCount;
	u8 nPoolRows;
	g_nRow = 0;
	g_nCol = GAME_COLS / 2 - 1;   

	nShapeCount = sizeof(g_chBrickPool) / sizeof(g_chBrickPool[0]) / 16;//整个数组所站的空间/第一个元素所占的空间/一个形状包含的元素个数，求出总共有多少个形状
	g_nShape = RNG_Get_RandomNum() % nShapeCount;   //形状总数量范围内随机
	g_nRotate = RNG_Get_RandomNum() % 4;			   

	nPoolRows = g_nShape * 16 + g_nRotate * 4;//随机第几个形状的第几个朝向

	for (nRow = 0; nRow < 4; nRow++)
	{
		for (nCol = 0; nCol < 4; nCol++)
		{
			g_chBrick[nRow][nCol] = g_chBrickPool[nRow + nPoolRows][nCol];

		}
	}

}


int IsCanMove(int nToRow, int nToCol)    //碰撞检测
{
	u8 nRow;
	u8 nCol;
	for (nRow = 0; nRow < 4; nRow++)
	{
		for (nCol = 0; nCol < 4; nCol++)
		{
			if (g_chBrick[nRow][nCol] == 1)  //检查砖在次=此坐标下是否为一
			{
				if (g_chBackground[nRow + nToRow][nCol + nToCol] == 1)   //检查背景在此坐标系下是否为一
				{
					return 0;//不可以移动
				}
			}
		}
	}
	DeleteBrick();
	return 1;//可以移动
}

int IsCanRotate(void)//判断是否可以旋转
{
	u8 nRow;
	u8 nCol;
	u8 i;
	u8 j;
	char chNextShape[4][4] = { 0 };

	int nNextRotate = (g_nRotate + 1) % 4;
	int nPoolRows = g_nShape * 16 + nNextRotate * 4;
	for (nRow = 0; nRow < 4; nRow++)
	{
		for (nCol = 0; nCol < 4; nCol++)
		{
			chNextShape[nRow][nCol] = g_chBrickPool[nRow + nPoolRows][nCol];

		}
	}
	for (i = 0; i < 4; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			if (chNextShape[i][j] == 1)
			{
				if (g_chBackground[i + g_nRow][j + g_nCol] == 1)
				{
					return 0;//不能旋转

				}
			}
		}
	}
	DeleteBrick();
	return 1;
}

void Rotate(void)//旋转
{
	u8 nRow;
	u8 nCol;
	u8 nPoolRows ;
	g_nRotate = (g_nRotate + 1) % 4;
	nPoolRows = g_nShape * 16 + g_nRotate * 4;
	for ( nRow = 0; nRow < 4; nRow++)
	{
		for ( nCol = 0; nCol < 4; nCol++)
		{
			g_chBrick[nRow][nCol] = g_chBrickPool[nRow + nPoolRows][nCol];

		}
	}

}

void CombineBgBrick(void)
{
	u8 nRow;
	u8 nCol;
	for ( nRow = 0; nRow < 4; nRow++)
	{
		for ( nCol = 0; nCol < 4; nCol++)
		{
			if (g_chBrick[nRow][nCol] == 1)
			{
				g_chBackground[nRow + g_nRow][nCol + g_nCol] = 1;
			}
		}
	}
}

void DetachBgBrick(void)
{
	u8 nRow;
	u8 nCol;
	for ( nRow = 0; nRow < 4; nRow++)
	{
		for ( nCol = 0; nCol < 4; nCol++)
		{
			if (g_chBrick[nRow][nCol] == 1)
			{
				g_chBackground[nRow + g_nRow][nCol + g_nCol] = 0;

			}
		}
	}
}
