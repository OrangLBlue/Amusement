#include "show_badapple.h"
#include "sram.h" 
#include "malloc.h" 
#include "ff.h"  
#include "lcd.h"
#include "delay.h"
#include "text.h"
#include "voice.h"
#include "usart3.h"
#include "string.h"
#include "interface.h"

void Show_Bad_Apple(void)
{
	
	u8  key;
	u8 *tempbuf;
//	u8 *pname;
	//u8 fn;
	FIL * fftemp;
	u32 bread;
	u32 len_num;
	u32 mm_num;
	u32 num;
	
	u8 dt;

	LCD_Display_Dir(1);
	//voice(3);
	
	voice(1);

  voice(1);
	while(g_nData == 1)
	{
		tempbuf=mymalloc(SRAMEX,mm_num);
		fftemp=(FIL*)mymalloc(SRAMEX,sizeof(FIL));//申请内存
		if(fftemp == NULL)
		{
		POINT_COLOR=RED; 
		Show_Str(30,170,240,16,"没有图片文件!",16,0);
		delay_ms(200);				  
		LCD_Fill(30,170,240,186,WHITE);//清除显示	     
		delay_ms(200);		
		break;
		}
			
//		strcpy((char*)pname,"0:/PICTURE/");				//复制路径(目录)
//		strcat((char*)pname,(const char*)fn);  			//将文件名接在后面
		f_open(fftemp,"0:/apple/apple.bin", FA_READ); //打开路径下文件
		LCD_Scan_Dir(L2R_U2D);//从左到右,从上到下
		LCD_Set_Window(0,0,320,240);
		LCD_SetCursor(0,0);//设置光标位置  
		LCD_WriteRAM_Prepare();   	//开始写入GRAM
		len_num=mm_num;			//写入的数据长度
		bread=mm_num;
		mm_num=9600; //设置一个屏幕需要的内存
		
//下面注释的5行代码，是测速函数，可用串口查看刷屏速度，串口波特率为115200		

		while(g_nData && bread==mm_num)//死循环执行读SD卡
		{
//			TIM_Cmd(TIM3,ENABLE);
//			TIM3->CNT=0;
			f_read(fftemp,tempbuf,mm_num,(UINT *)&bread);
			for(len_num=0;len_num < 9600;len_num++)
			{
				dt=tempbuf[len_num];
				for(num=0;num<8;num++)
				{
					if((dt<<num)&0x80) LCD->LCD_RAM=0x0000;
					else LCD->LCD_RAM=0xFFFF;
					
				}
			}
//			key = USART_ReceiveData(USART3);
//			if(key == 'S')
//				g_nData = 0;
			g_key = USART_ReceiveData(USART2);
			if (g_key == 'q' || g_key == 'x')
			{
				g_key = 'x';
				voice(41);
				g_nData = 0;
			}
			delay_ms(21);
//			num=TIM_GetCounter(TIM3);
//			printf("刷屏速度:%d FPS\r\n",10000/num);
//			TIM_Cmd(TIM3,DISABLE);				
		}
	}	
	myfree(SRAMEX,tempbuf);
	myfree(SRAMEX,fftemp);
	LCD_Display_Dir(0);
	LCD_Clear(WHITE);
	delay_ms(50);
	ShowBagin();
	
}
