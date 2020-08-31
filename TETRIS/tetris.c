// russia.cpp : 定义控制台应用程序的入口点。
//
#include "tetris.h"
#include <stdlib.h>
#include "mode.h"
#include "delay.h"
#include "view.h"
#include "lcd.h"
#include "timer.h"
#include "voice.h"
#include "usart2.h"
u8 g_uFlag = 1;

void RunTetris(void)
{
	
	u32 num;
	u32 Count1 = 0;
	u8 uDegree = 0;

	
	while (g_nData && g_uFlag)
	{		
		
		uDegree = TetrisBegin();//模式选择	
		if(uDegree == 0){
			g_uFlag = 0;
		}
		
		if(g_nData && g_uFlag)
		{
			voice(2);
			BACK_COLOR = GRAY;
			LCD_Display_Dir(1);
			LCD_Scan_Dir(R2L_D2U);
			
			InitBackground();//初始化背景
			GetNewBrick();//获得新砖
			//CombineBgBrick();
			ShowBackground();//显示背景
			DetachBgBrick();//分解背景和砖
			delay_ms(10);
			g_uFlag = 1;
			g_nData = 1;
			g_nTime = 0;
			while (g_nData == 1 && g_uFlag)
			{

//				TIM_Cmd(TIM3,ENABLE);
//				TIM3->CNT=0;
//				num=TIM_GetCounter(TIM3);	
//				if (Count1 <= 10000)
//				{
//					//Count1++;
//					//Count1 = 0;
//				}	
				if(g_nTime >= uDegree)
				{			
					OnDown();
					g_nTime = 0;
					//TIM_Cmd(TIM3,DISABLE);
				}  
//					Count1++;
//				if(Count1 >= 10){
//					OnDown();
//					Count1	= 0;				
//				}
				
				//delay_ms(10);
				g_key = USART_ReceiveData(USART2);//读取按键值			
				
				switch (g_key)
				{
					case'a':
						OnRight();g_key = 0;delay_ms(1);
						break;
					case'w':
						OnUp();g_key = 0;delay_ms(1);
						break;
					case's':
						OnDown();g_key = 0;delay_ms(1);
						break;
					case'd':
						OnLeft();g_key = 0;delay_ms(1);
						break;
					case'q':
						g_key = 'x';
						LCD_Display_Dir(0);
						LCD_Scan_Dir(L2R_U2D);
						g_nData = 0;
						g_uFlag = 0;
						break;
					case'x':
						g_key = 'x';
						LCD_Display_Dir(0);
						LCD_Scan_Dir(L2R_U2D);
						g_nData = 0;
						g_uFlag = 0;
						break;
					default:
						break;
				}
				if(g_uFlag == 1){
					g_nData = 1;
				}
			}
			g_BrickCount = 0;
			delay_ms(10);	
		}
	}
}
