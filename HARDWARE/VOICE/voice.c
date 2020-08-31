#include "voice.h"
#include "delay.h"
#include "usart3.h"
#include "usart.h"
#include "string.h"

void voice(u8 x)
{
	switch(x)
	{
		case 0:  //设置初始音量为24
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x06);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x0f);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);		
		break;
		
		case 1: //播放曲目1
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x01);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 2:  
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x02);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
	
		case 3:  
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
	
		case 4: 
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);	
		break;
		
		case 5: 
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x05);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 6: 
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x06);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 7: 
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x07);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 8: 
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x08);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 9: 
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x09);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
						
		case 10:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x0a);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 11: 
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x0b);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
						
		case 12:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x0c);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 13:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x0d);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 14:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x0e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 15:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x0f);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 16:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x10);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 17:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x11);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 18:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x12);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 19:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x13);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 20:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x14);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 21:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x15);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 22:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x16);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 23:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x17);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 24:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x18);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 25:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x19);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 26:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x1a);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 27:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x1b);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 28:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x1c);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 29:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x1d);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1200);
		break;
		
		case 30:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x1e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
		
		case 31:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x1f);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
		
		case 32:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x20);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
		
		case 33:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x21);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
		
		case 34:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x22);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
		
		case 35:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x23);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
		
		case 36:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x24);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
		
		case 37:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x25);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
		
		case 38:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x26);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
		
		case 39:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x27);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
		
		case 40:
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x04);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x03);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x00);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x28);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		case 41://暂停
						USART_SendData(USART3, 0x7e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x02);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0x0e);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						USART_SendData(USART3, 0xef);//向串口3发送数据
						while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
						delay_ms(1400);
		break;
	}
}
