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
int g_nShape = 0;//��״��ϵ��16
int g_nRotate = 0;//����ϵ��4
int g_nRow = 0;
int g_nCol = 0;

char g_chBrickPool[][4] = {
	1, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0,//����
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

	1, 1, 0, 0,//����
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

	1, 1, 0, 0,//����
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

	0, 1, 0, 0,//��L
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
	0, 0, 0, 0,//��Z
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

	nShapeCount = sizeof(g_chBrickPool) / sizeof(g_chBrickPool[0]) / 16;//����������վ�Ŀռ�/��һ��Ԫ����ռ�Ŀռ�/һ����״������Ԫ�ظ���������ܹ��ж��ٸ���״
	g_nShape = RNG_Get_RandomNum() % nShapeCount;   //��״��������Χ�����
	g_nRotate = RNG_Get_RandomNum() % 4;			   

	nPoolRows = g_nShape * 16 + g_nRotate * 4;//����ڼ�����״�ĵڼ�������

	for (nRow = 0; nRow < 4; nRow++)
	{
		for (nCol = 0; nCol < 4; nCol++)
		{
			g_chBrick[nRow][nCol] = g_chBrickPool[nRow + nPoolRows][nCol];

		}
	}

}


int IsCanMove(int nToRow, int nToCol)    //��ײ���
{
	u8 nRow;
	u8 nCol;
	for (nRow = 0; nRow < 4; nRow++)
	{
		for (nCol = 0; nCol < 4; nCol++)
		{
			if (g_chBrick[nRow][nCol] == 1)  //���ש�ڴ�=���������Ƿ�Ϊһ
			{
				if (g_chBackground[nRow + nToRow][nCol + nToCol] == 1)   //��鱳���ڴ�����ϵ���Ƿ�Ϊһ
				{
					return 0;//�������ƶ�
				}
			}
		}
	}
	DeleteBrick();
	return 1;//�����ƶ�
}

int IsCanRotate(void)//�ж��Ƿ������ת
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
					return 0;//������ת

				}
			}
		}
	}
	DeleteBrick();
	return 1;
}

void Rotate(void)//��ת
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
