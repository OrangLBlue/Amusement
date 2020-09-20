#include "head.h"

//本程序工作于240*320的正点原子TFTLCE显示屏

u16 g_key; 
u8 g_nData = 0;


void Init(void);//初始化

int main(void)
{	
	Init();
	
	while(1)
	{ 		
	
		if(g_key == 'x'|| g_key == 'q')
		{
				ShowBagin();
		}
		
		g_key = USART_ReceiveData(USART2);
		//USART_SendData(USART1,g_key);
//    if(g_key != NULL)
//		{			
//			g_key = 'z';
//		}
		switch(g_key)
		{
			case 'v':
					g_nData = 1;
					RunSnake();
					voice(41); break;
			case 'z':
					g_nData = 1;
					g_uFlag = 1;
					RunTetris();
					voice(41); break;
			case 'c':
					GPIO_SetBits(GPIOB, GPIO_Pin_8);
					//USART_SendData(USART1,'s');
					delay_ms(1);GPIO_ResetBits(GPIOF, GPIO_Pin_9);
					g_nData = 1;
					delay_ms(500);
					Show_Bad_Apple();
					voice(41);
					GPIO_ResetBits(GPIOB, GPIO_Pin_8);
			case 'b':
					delay_ms(1);
					GPIO_ResetBits(GPIOF, GPIO_Pin_9);
					g_nData = 1;
					delay_ms(500);
					Show_Aligei();
					voice(41); 
					break;
			default:break;
	  }
	}
	
}

//本程序使用定时器3进行刷屏测速，串口打印刷屏速度，串口波特率为115200
//全速运行时请注释掉测速函数，不然影响刷屏速度
//void UartASendStr (u8 *pucStr, u8 ulNum);
//void ACK(void) ;

void Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	
	uart_init(115200);		//初始化串口波特率为115200
	USART3_Init(9600);
	USART2_Init(9600);
	To_Pi_Init();					//初始化LED  
 	LCD_Init();					//LCD初始化  
 	KEY_Init();					//按键初始化  
	W25QXX_Init();				//初始化W25Q128
	usmart_dev.init(168);		//初始化USMART
		
	
	EXTIX_Init();
	TIM3_Int_Init(1899,8399);//初始化这个定时器用于测速使用 秒
	
	FSMC_SRAM_Init();    	//初始化外部SRAM  
	my_mem_init(SRAMIN);		//初始化内部内存池 
	my_mem_init(SRAMEX);		//初始化外部内存池
	my_mem_init(SRAMCCM);		//初始化CCM内存池 
	exfuns_init();				//为fatfs相关变量申请内存  
	piclib_init();
  RNG_Init();	
	//My_RTC_Init();		 		//初始化RTC
	RTC_Set_WakeUp(RTC_WakeUpClock_CK_SPRE_16bits,0);		//配置WAKE UP中断,1秒钟中断一次
  f_mount(fs[0],"0:",1); 		//挂载SD卡 
 	f_mount(fs[1],"1:",1); 		//挂载FLASH.
	delay_ms(10);
	font_init();//初始化字体
	delay_ms(10);
	SD_Init();
	delay_ms(10);
//	ACK();
  LCD_Clear(WHITE);
	delay_ms(10);
	ShowBagin();//开始	
	voice(0); 							//初始化音量为24
	delay_ms(50);
	voice(39);              //初始化模式为单曲循环
	delay_ms(50);
	voice(41);							//初始化为不播放任何音乐

}


//模块调试用主函数
//int main1(void)
//{	
//	Init();
//	
//	
//	while(1)
//	{ 		
//		POINT_COLOR = BRRED;
//		Show_Str(48,24,96,24,"Score：",24, 0); 
//		BrickCount(120, 24, 128, 24, 24, 0);	
//		
//		POINT_COLOR = BRED;
//		Show_Str(0,72,240,24," 啊！砖砖下不来啦！",24,0); 
//		Show_Str(0,120,240,24,"您是否要开始新的旅程",24,0);	
//		
//		
//		POINT_COLOR = LIGHTGREEN;
//		Show_Str(0,216,240,16,"确定键重新开始，返回键退出游戏",16,0);		
//	
//	}
//	
//}
