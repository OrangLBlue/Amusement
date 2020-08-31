#include "view.h"
#include "mode.h"
#include "stdio.h"
#include "sys.h"
#include "delay.h"
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



int g_End = 0;
int g_BrickCount = 0;
//int g_nFlag = 1;

void OnLeft(void)
{
	//若能左移，则左移
	if (IsCanMove(g_nRow, g_nCol - 1))
	{
		g_nCol--;
		ShowGame();
	}
}

void OnRight(void)
{
	if (IsCanMove(g_nRow, g_nCol + 1))
	{
		g_nCol++;
		ShowGame();
	}
}

void OnUp(void)
{
	if (IsCanRotate())
	{
		Rotate();
		ShowGame();
	}
}

void OnDown(void)
{
	if (IsCanMove(g_nRow + 1, g_nCol))
	{
		g_nRow++;
		ShowGame();	
	}
	else
	{
		//固定方块至背景,并产生新方块
		
		CombineBgBrick();
		Remove();
		ShowBackground();
		GetNewBrick();
		
		//判断游戏是否结束，并给出对应提示	
		if (IsCanMove(g_nRow + 1, g_nCol))
		{
			g_BrickCount++;
		}
		else
		{
			IsEnd();
			delay_ms(1);
		}
	}
}


void ShowGame(void)
{
	//system("cls");
	//CombineBgBrick();
	ShowBrick();
	//DetachBgBrick();
}



void DeleteBrick(void)
{
	u8 i;
	u8 j;
	for( i = 0; i < 4; i++)
	{
		for( j = 0; j < 4; j++)
		{
			if(g_chBrick[i][j] == 1)
			{
				//MoveCursorTo(i + g_nRow, j + g_nCol);
				//WriteChar(i + g_nRow, j + g_nCol, "  ", SetConsoleColor(COLOR_BLUE, COLOR_YELLOW));
				  POINT_COLOR = GRAY;
			    Show_Str((i + g_nRow)*16,(j + g_nCol)*16,16,16,"  ",16,0);
				//printf("■");
			}
		}
		//MoveCursorTo(g_nRow, g_nCol);
		printf("\r\n");

	}
}

void ShowBrick(void)
{
	u8 i;
	u8 j;
	for ( i = 0; i < 4; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			if (g_chBrick[i][j] == 1)
			{
				
				//MoveCursorTo(i + g_nRow, j + g_nCol);
				//WriteChar(i + g_nRow, j + g_nCol, "■", SetConsoleColor(COLOR_BLUE, COLOR_WHITE));
				POINT_COLOR = BROWN;
				Show_Str((i + g_nRow)*16,(j + g_nCol)*16,16,16,"■",16,1);
				//printf("■");
			}
		}
		POINT_COLOR = BRRED;
		Show_Str(0,0,64,16,"Score：",16,1); 
		BrickCount(64, 0, 128, 16, 16, 1);
		//MoveCursorTo(g_nRow, g_nCol);
		//printf("\r\n");

	}
}


void ShowBackground(void)
{
	u8 nRow;
	u8 nCol;
	for (nRow = 0; nRow < GAME_ROWS; nRow++)
	{
		for (nCol = 0; nCol < GAME_COLS; nCol++)
		{
			if (g_chBackground[nRow][nCol] == 1)
			{
				POINT_COLOR = GBLUE;
				Show_Str((nRow)*16,(nCol)*16,16,16,"■",16,1);
				//WriteChar(nRow, nCol, "■", SetConsoleColor(COLOR_BLUE, COLOR_WHITE));
				//printf("■");
			}

			else
			{
				POINT_COLOR = GRAY;
				Show_Str((nRow)*16,(nCol)*16,16,16,"  ",16,0);
				//WriteChar(nRow, nCol, "  ", SetConsoleColor(COLOR_BLUE, COLOR_YELLOW));
				//printf("  ");
			}
		}
		printf("\r\n");
	}
}

//检测消行
void Remove(void)
{
	int nCount = 0;
	u8 nRow;
	u8 nCol;
	u8 i;
	u8 j;
	for (nRow = GAME_ROWS - 2; nRow > 0; nRow--)
	{
		for (nCol = 1; nCol < GAME_COLS -1; nCol++)
		{
			if (g_chBackground[nRow][nCol] == 1)
				nCount++;
		}
		if (nCount == GAME_COLS-2)
		{
			for (i = nRow; i > 0; i--)
			{
				for (j = 0; j < GAME_COLS - 1; j++)
				{
					g_chBackground[i][j] = g_chBackground[i - 1][j];
				}
			}
			nRow++;
		}
		nCount = 0;
	}
}

//在指定位置开始显示得分	    
//支持自动换行
//(x,y):起始坐标
//width,height:区域
//size :字体大小
void BrickCount(u16 x,u16 y,u16 width,u16 height,u8 size,u8 mode)//显示当前得分即已玩砖数
{
	u8 chBrickCount[10] = { 0 };
	int nBrickCount = g_BrickCount;
	int i;
	int j = 0;
	
	while(nBrickCount/10)
	{
		nBrickCount /= 10;
		j++;		
	}
	
	nBrickCount = g_BrickCount;	
	
	for(i = j; i >= 0 ; i--)
	{
		chBrickCount[i] = nBrickCount % 10 + '0';
		nBrickCount /= 10;
				
		if(nBrickCount == 0)
			break;
	}
	
	POINT_COLOR = RED;
	Show_Str(x,y,width,height,chBrickCount,size,mode); 

}

void IsEnd(void)
{
	LCD_Display_Dir(0);
	LCD_Scan_Dir(L2R_U2D);
	
	POINT_COLOR = BRRED;
	Show_Str(48,24,96,24,"Score：",24, 0); 
	BrickCount(120, 24, 128, 24, 24, 0);	
		
	POINT_COLOR = BRED;
	Show_Str(0,72,240,24," 啊！砖砖下不来啦！ ",24,0); 
	Show_Str(0,120,240,24,"您是否要开始新的旅程",24,0);	
		
		
	POINT_COLOR = LIGHTGREEN;
	Show_Str(0,216,240,16,"确定键重新开始，返回键退出游戏",16,0);		
	
	
	while(g_nData == 1)	
	{
		g_key = USART_ReceiveData(USART2);//读取按键值		
		
		switch (g_key)
			{
				case'q':
					g_key = 'x';
					voice(41);
					g_nData = 0;
					break;
				case'x':
					g_key = 'x';
					voice(41);
					g_nData = 0;
					break;
				case'r':				
					g_nData = 2;
					voice(41);				
					break;
				default:
					break;
			}
	}
}