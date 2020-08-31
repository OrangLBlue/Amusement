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


void GameInit(void)//��Ϸ��ʼ��
{
	
	voice(2);
	delay_ms(50);
	BACK_COLOR = GRAY;
	g_CountNode = 1;
	WallInit();//��ʼ��ǽ
	SnakeInit();//��ʼ����
	NewFood();//��ʼ��ʳ��
	SnShowGame();//����ʼ����ɵĽ�����ӻ�
	g_nData = 1;
}

void SnShowGame(void)//��ʾ��Ϸ
{
	LCD_Clear(GRAY);
	ShowFood();	
	ShowSnake();
	WallInit();
	
	
	POINT_COLOR = RED;
	Show_Str(72, 264, 240, 16,"Score��", 16, 1);
	ShowScore(120, 288, 240, 16, 16, 1);//������ʾ
}


int SnIsCanMove(void)//��ײ���
{
	if (g_pSHead->S_nRow == 0 || 
		g_pSHead->S_nRow == GAME_ROWS -1||
		g_pSHead->S_nCol == 0 ||
		g_pSHead->S_nCol == GAME_COLS -1||
		IsEatSelf())								//�ж���ͷ�Ƿ��ǽ�غϻ����������غ�
	{
		return 0;//ײ��
	}

	return 1;//ûײ
}

void IsEatFood(void)//����Ƿ�Ե�ʳ��
{
	if (g_pSHead->S_nRow == g_pFoodPlace->F_nRow &&
		g_pSHead->S_nCol == g_pFoodPlace->F_nCol)	//�ж���ͷ�Ƿ���ʳ��
	{
		AddNode();									//�غ�������һ���ڵ�
		free(g_pFoodPlace);							//�ͷŴ洢��ǰʳ����ڴ�ռ�
		NewFood();									//�����µ�ʳ��
	}
}

int IsEatSelf(void)//�ж��Ƿ���ʳ
{
	if (g_CountNode >= 5)
	{
		Snake* pNode = BodyFind(5);						//�ܳ�5�����ڲ�������ʳ�����Դӵ������ʼ
		while (NULL != pNode)							//���������ߣ��ж��ǲ����Լ������Լ� ��ͷ�����������������Ƿ����غ�
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


void ShowScore(u16 x,u16 y,u16 width,u16 height,u8 size,u8 mode)//����ͳ��
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
	Show_Str(48,24,96,24,"Score��",24, 0); 
	ShowScore(144, 24, 128, 24, 24, 0);	
		
	POINT_COLOR = BRED;
	Show_Str(0,72,240,24," ����С��ѳְ�ˣ�  ",24,0); 
	Show_Str(0,120,240,24,"���Ƿ�ҪС��������",24,0);	
		
		
	POINT_COLOR = GREEN;
	Show_Str(0,216,240,16,"ȷ�������¿�ʼ�����ؼ��˳���Ϸ",16,0);		
	
	
	while(g_nData == 1)	
	{
		g_key = USART_ReceiveData(USART2);//��ȡ����ֵ		
		
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
					g_nData = 2;//����
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
	Show_Str(72,120,240,24,"̰����",24,1);	
	
	POINT_COLOR = BLUE;	
	Show_Str(48,168,240,16,"��ѡ����Ҫ��ս���Ѷ�",16,1);
	
	Show_Str(48,192,240,16,"  ��  ��ͨ  ����  ",16,1);
	
	Show_Str(48,216,240,16,"  ��     ��     ��  ",16,1);
	
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


//��Ϸ����
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
			MoveSnake();//�ƶ���
			if (!SnIsCanMove())
			{
				POINT_COLOR = RED;
				Show_Str(296, 96,24,240,"ײ����", 24, 1);
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
				ChangeDir(g_key);	//�ı���ͷ����
				g_key = 0;
				break;		
		}
//		USART_SendData(USART1, g_key);		
//		delay_ms(1);
//		USART_SendData(USART1, g_SDir);						
	}	
	for (i = g_CountNode; i >= 1; i--)//�Ӻ���ǰ���������ߣ����ͷŴ洢�ڵ��ÿ���ռ�
	{
		pTail = BodyFind(i);
		myfree(SRAMEX ,pTail);
	}
	myfree(SRAMEX,g_pFoodPlace);//�ͷŴ洢�ռ�
}



