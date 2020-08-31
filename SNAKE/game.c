#include "sys.h"
#include "game.h"
#include "snake.h"
#include "food.h"
#include "wall.h"
#include "text.h"
#include "lcd.h"
#include "CSnake.h"
#include "malloc.h"
#include "usart2.h"
#include "timer.h"
#include "voice.h"
#include "lcd.h"
#include "delay.h"
#include "readp.h"


void GameInit(void)//游戏初始化
{
	
	voice(2);
	delay_ms(50);
	BACK_COLOR = GRAY;
	g_CountNode = 1;
	WallInit();//初始化墙
	SnakeInit();//初始化蛇
	NewFood();//初始化食物
	SnShowGame();//将初始化完成的结果可视化
	g_nData = 1;
}

void SnShowGame(void)//显示游戏
{
	LCD_Clear(GRAY);
	ShowFood();	
	ShowSnake();
	WallInit();
	
	
	POINT_COLOR = RED;
	Show_Str(72, 264, 240, 16,"Score：", 16, 1);
	ShowScore(120, 288, 240, 16, 16, 1);//分数显示
}


int SnIsCanMove(void)//碰撞检测
{
	if (g_pSHead->S_nRow == 0 || 
		g_pSHead->S_nRow == GAME_ROWS -1||
		g_pSHead->S_nCol == 0 ||
		g_pSHead->S_nCol == GAME_COLS -1||
		IsEatSelf())								//判断蛇头是否和墙重合或是与身体重合
	{
		return 0;//撞了
	}

	return 1;//没撞
}

void IsEatFood(void)//检测是否吃到食物
{
	if (g_pSHead->S_nRow == g_pFoodPlace->F_nRow &&
		g_pSHead->S_nCol == g_pFoodPlace->F_nCol)	//判断蛇头是否与食物
	{
		AddNode();									//重合则增加一个节点
		free(g_pFoodPlace);							//释放存储当前食物的内存空间
		NewFood();									//产生新的食物
	}
}

int IsEatSelf(void)//判断是否自食
{
	if (g_CountNode >= 5)
	{
		Snake* pNode = BodyFind(5);						//总长5个以内不存在自食，所以从第五个开始
		while (NULL != pNode)							//遍历整条蛇，判断是不是自己吃了自己 即头部坐标与身体坐标是否有重合
		{
			if (g_pSHead->S_nRow == pNode->S_nRow &&
				g_pSHead->S_nCol == pNode->S_nCol)
			{
				return 1;
			}
			pNode = pNode->next;
		}
	}
	return 0;
}


void ShowScore(u16 x,u16 y,u16 width,u16 height,u8 size,u8 mode)//分数统计
{
	int nScore = g_CountNode - 3;
	u8 chScore[3] = {0};
	int i = 0;
	int j = 0;
	while(nScore/10)
	{
		nScore = nScore/10;
		j++;
	}
	
	nScore = g_CountNode - 3;
	for(i = j; i >= 0; i--)
	{ 
		chScore[j] = nScore%10 + '0';
		nScore = nScore/10;
	}
	POINT_COLOR = RED;
	Show_Str(x, y, width, height, chScore, size, mode);
	

}


void SnIsEnd(void)
{
	POINT_COLOR = RED;
	Show_Str(48,24,96,24,"Score：",24, 0); 
	ShowScore(144, 24, 128, 24, 24, 0);	
		
	POINT_COLOR = BRED;
	Show_Str(0,72,240,24," 啊！小蛇殉职了！  ",24,0); 
	Show_Str(0,120,240,24,"您是否要小蛇重生呢",24,0);	
		
		
	POINT_COLOR = GREEN;
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
					g_nData = 2;//重来
					voice(41);				
					break;
				default:
					break;
			}
	}
}


u8 SnakeBegin(void)
{
	u8 uDegree = 1;
	char chKey = 0;
	u8 uFlag = 1;
	
	ReadP_From_SD("0:/PICTURE","0:/PICTURE/0003.bmp");
	delay_ms(100);
	POINT_COLOR = BRRED;
	Show_Str(72,120,240,24,"贪吃蛇",24,1);	
	
	POINT_COLOR = BLUE;	
	Show_Str(48,168,240,16,"请选择你要挑战的难度",16,1);
	
	Show_Str(48,192,240,16,"  简单  普通  困难  ",16,1);
	
	Show_Str(48,216,240,16,"  ←     ↑     →  ",16,1);
	
	while(uFlag)
	{
		chKey = USART_ReceiveData(USART2);
		
		switch(chKey)
		{
			case'a':
				uDegree = 5;g_key = 0;uFlag = 0;
				break;
			case'w':
				uDegree = 3;g_key = 0;uFlag = 0;
				break;
			case'd':
				uDegree = 1;g_key = 0;uFlag = 0;
				break;
			case'q':
				g_key = 'x';
				g_nData = 0;uFlag = 0;
				break;
			case'x':
				g_key = 'x';
				g_nData = 0;uFlag = 0;
				break;
			default:
				break;
		}
	}
	delay_ms(100);
	return uDegree; 
}


//游戏运行
void Run(u8 nDeg)
{
	int i;

	
	Snake *pTail = NULL;
//	RTC_TimeTypeDef RTC_Timest;
//	
//	RTC_GetTime(RTC_Format_BIN,&RTC_Timest);	
//	clkStart =RTC_Timest.RTC_Seconds ;
//	clkEnd = RTC_Timest.RTC_Seconds;
	g_nTime = 0;
	while (g_nData == 1)
	{
//		RTC_GetTime(RTC_Format_BIN,&RTC_Timest);	
//		clkEnd = RTC_Timest.RTC_Seconds;
		if (g_nTime >= nDeg)		
		{
			MoveSnake();//移动蛇
			if (!SnIsCanMove())
			{
				POINT_COLOR = RED;
				Show_Str(296, 96,24,240,"撞啦！", 24, 1);
				SnIsEnd();
			}	
			IsEatFood();
			SnShowGame();	
			g_nTime	= 0;		
		}
		
		g_key = USART_ReceiveData(USART2);
		//USART_SendData(USART1, g_key);	

		switch (g_key)
		{
			case'q':
				g_key = 'x';
				g_nData = 0;
				break;
			case'x':
				g_key = 'x';
				g_nData = 0;
				break;
			default:
				ChangeDir(g_key);	//改变蛇头朝向
				g_key = 0;
				break;		
		}
//		USART_SendData(USART1, g_key);		
//		delay_ms(1);
//		USART_SendData(USART1, g_SDir);						
	}	
	for (i = g_CountNode; i >= 1; i--)//从后往前遍历整条蛇，并释放存储节点的每个空间
	{
		pTail = BodyFind(i);
		myfree(SRAMEX ,pTail);
	}
	myfree(SRAMEX,g_pFoodPlace);//释放存储空间
}



