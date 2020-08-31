// russia.cpp : 定义控制台应用程序的入口点。
//
#include "tetris.h"
#include <stdlib.h>
#include "mode.h"
#include "delay.h"
#include "view.h"
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




void RunTetris(void)
{
	
	u32 num;
	u32 Count1 = 0;
	
	while (g_nData)
	{		
		ReadP_From_SD("0:/PICTURE","0:/PICTURE/0001.bmp");
		POINT_COLOR = BRRED;
		Show_Str(48,120,240,24,"俄罗斯方块",24,1);	
		delay_ms(300);
		
		BACK_COLOR = GRAY;
		LCD_Display_Dir(1);
		LCD_Scan_Dir(R2L_D2U);
		voice(2);
		InitBackground();//初始化背景
		GetNewBrick();//获得新砖
		//CombineBgBrick();
		ShowBackground();//显示背景
		DetachBgBrick();//分解背景和砖
		delay_ms(10);
		
		g_nData = 1;
		
		while (g_nData == 1)
		{
			TIM_Cmd(TIM3,ENABLE);
			TIM3->CNT=0;
			num=TIM_GetCounter(TIM3);
			
			if ((10000/num) >= 20)
			{
				Count1++;
			}
			if(Count1 >= 10)
			{			
				OnDown();
				Count1 = 0;
				TIM_Cmd(TIM3,DISABLE);
			}  

			g_key = USART_ReceiveData(USART2);//读取按键值			
			
			switch (g_key)
			{
				case'a':
					OnLeft();g_key = 0;
					break;
				case'w':
					OnUp();g_key = 0;
					break;
				case's':
					OnDown();
					break;
				case'd':
					OnRight();g_key = 0;
					break;
				case'q':
					g_key = 'x';
					LCD_Display_Dir(0);
					LCD_Scan_Dir(L2R_U2D);
					voice(41);
					g_nData = 0;
					break;
				case'x':
					g_key = 'x';
					LCD_Display_Dir(0);
					LCD_Scan_Dir(L2R_U2D);
					voice(41);
					g_nData = 0;
					break;
				default:
					break;
			}
		}
		g_BrickCount = 0;
		delay_ms(10);	
	}
}
