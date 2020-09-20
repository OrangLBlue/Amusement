#include "show_aoligei.h"
#include "sram.h" 
#include "malloc.h" 
#include "ff.h"  
#include "lcd.h"
#include "delay.h"
#include "text.h"
#include "voice.h"
#include "usart3.h"
#include "string.h"

void Show_Aligei(void)
{
	u8 *tempbuf;
//	u8 *pname;
	//u8 fn;
	FIL * fftemp;
	u32 bread;
	u32 len_num;
	u32 mm_num;
	u32 num;
	
	u8 dt;

	voice(3);
	while(g_nData == 1)
	{	
		tempbuf=mymalloc(SRAMEX,mm_num);
		fftemp=(FIL*)mymalloc(SRAMEX,sizeof(FIL));//�����ڴ�
		if(fftemp == NULL)
		{
			POINT_COLOR=RED; 
			Show_Str(30,170,240,16,"û��ͼƬ�ļ�!",16,0);
			delay_ms(200);				  
			LCD_Fill(30,170,240,186,WHITE);//�����ʾ	     
			delay_ms(200);		
			break;
		}
			
		f_open(fftemp,"0:/aoligei/aoligei.bin", FA_READ); //��·�����ļ�
		LCD_Scan_Dir(L2R_U2D);//������,���ϵ���
		LCD_Set_Window(0,0,240,320);
		LCD_SetCursor(0,0);//���ù��λ��  
		LCD_WriteRAM_Prepare();   	//��ʼд��GRAM
		//len_num=mm_num;			//д������ݳ���
		bread=mm_num;
		mm_num=9600; //����һ����Ļ��Ҫ���ڴ�
		
//����ע�͵�5�д��룬�ǲ��ٺ��������ô��ڲ鿴ˢ���ٶȣ����ڲ�����Ϊ115200		

		while(g_nData && bread==mm_num)//��ѭ��ִ�ж�SD��
		{
//			TIM_Cmd(TIM3,ENABLE);
//			TIM3->CNT=0;
			f_read(fftemp,tempbuf,mm_num,(UINT *)&bread);
			for(len_num=0;len_num < mm_num;len_num++)
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
				g_nData = 0;
			}
			delay_ms(19);
//			num=TIM_GetCounter(TIM3);
//			printf("ˢ���ٶ�:%d FPS\r\n",10000/num);
//			TIM_Cmd(TIM3,DISABLE);				
		}
	}	
	myfree(SRAMEX,tempbuf);
	myfree(SRAMEX,fftemp);
	LCD_Clear(WHITE);
	delay_ms(50);	
}
