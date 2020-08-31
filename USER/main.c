#include "head.h"

//����������240*320������ԭ��TFTLCE��ʾ��

u16 g_key; 
u8 g_nData = 0;


void Init();//��ʼ��

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
			case 'z':
					g_nData = 1;
					RunTetris();
					voice(41); break;
			case 'c':
					GPIO_SetBits(GPIOB, GPIO_Pin_8);
					USART_SendData(USART1,'s');
					delay_ms(1);GPIO_ResetBits(GPIOF, GPIO_Pin_9);
					g_nData = 1;
					delay_ms(1000);
					Show_Bad_Apple();
					voice(41);
					GPIO_ResetBits(GPIOB, GPIO_Pin_8);break;
			default:break;
	  }
	}
	
}

//������ʹ�ö�ʱ��3����ˢ�����٣����ڴ�ӡˢ���ٶȣ����ڲ�����Ϊ115200
//ȫ������ʱ��ע�͵����ٺ�������ȻӰ��ˢ���ٶ�
//void UartASendStr (u8 *pucStr, u8 ulNum);
//void ACK(void) ;

void Init()
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	USART3_Init(9600);
	USART2_Init(9600);
	To_Pi_Init();					//��ʼ��LED  
 	LCD_Init();					//LCD��ʼ��  
 	KEY_Init();					//������ʼ��  
	W25QXX_Init();				//��ʼ��W25Q128
	usmart_dev.init(168);		//��ʼ��USMART
	voice(0);
	voice(41);
	EXTIX_Init();
	TIM3_Int_Init(9999,8399);//��ʼ�������ʱ�����ڲ���ʹ�� 1��
	//TIM3_Int_Init(9999,8399);
	TIM_Cmd(TIM3,DISABLE); 	
	
	FSMC_SRAM_Init();    	//��ʼ���ⲿSRAM  
	my_mem_init(SRAMIN);		//��ʼ���ڲ��ڴ�� 
	my_mem_init(SRAMEX);		//��ʼ���ⲿ�ڴ��
	my_mem_init(SRAMCCM);		//��ʼ��CCM�ڴ�� 
	exfuns_init();				//Ϊfatfs��ر��������ڴ�  
	piclib_init();
  RNG_Init();	
  f_mount(fs[0],"0:",1); 		//����SD�� 
 	f_mount(fs[1],"1:",1); 		//����FLASH.
	delay_ms(10);
	font_init();//��ʼ������
	delay_ms(10);
	SD_Init();
	delay_ms(10);
//	ACK();
  LCD_Clear(WHITE);
	delay_ms(10);
	ShowBagin();//��ʼ	
}


//ģ�������������
int main1(void)
{	
	Init();
	
	
	while(1)
	{ 		
		POINT_COLOR = BRRED;
		Show_Str(48,24,96,24,"Score��",24, 0); 
		BrickCount(120, 24, 128, 24, 24, 0);	
		
		POINT_COLOR = BRED;
		Show_Str(0,72,240,24," ����שש�²�������",24,0); 
		Show_Str(0,120,240,24,"���Ƿ�Ҫ��ʼ�µ��ó�",24,0);	
		
		
		POINT_COLOR = LIGHTGREEN;
		Show_Str(0,216,240,16,"ȷ�������¿�ʼ�����ؼ��˳���Ϸ",16,0);		
	
	}
	
}