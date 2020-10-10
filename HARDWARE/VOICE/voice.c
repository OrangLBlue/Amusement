#include "voice.h"
#include "delay.h"
#include "usart3.h"
#include "usart.h"
#include "string.h"

void voice(u8 x)
{
	switch(x)
	{
		case 0:  //���ó�ʼ����Ϊ24
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x06);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x0f);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);		
		break;
		
		case 1: //������Ŀ1
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x01);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 2:  
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x02);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
	
		case 3:  
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
	
		case 4: 
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);	
		break;
		
		case 5: 
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x05);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 6: 
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x06);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 7: 
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x07);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 8: 
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x08);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 9: 
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x09);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
						
		case 10:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x0a);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 11: 
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x0b);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
						
		case 12:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x0c);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 13:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x0d);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 14:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x0e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 15:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x0f);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 16:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x10);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 17:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x11);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 18:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x12);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 19:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x13);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 20:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x14);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 21:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x15);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 22:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x16);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 23:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x17);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 24:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x18);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 25:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x19);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 26:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x1a);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 27:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x1b);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 28:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x1c);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 29:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x1d);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1200);
		break;
		
		case 30:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x1e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
		
		case 31:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x1f);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
		
		case 32:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x20);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
		
		case 33:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x21);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
		
		case 34:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x22);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
		
		case 35:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x23);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
		
		case 36:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x24);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
		
		case 37:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x25);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
		
		case 38:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x26);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
		
		case 39:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x27);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
		
		case 40:
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x04);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x03);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x00);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x28);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		case 41://��ͣ
						USART_SendData(USART3, 0x7e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x02);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0x0e);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART3, 0xef);//�򴮿�3��������
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						delay_ms(1400);
		break;
	}
}
