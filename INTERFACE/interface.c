#include "interface.h"
#include "fontupd.h"
#include "w25qxx.h"
#include "lcd.h"
#include "text.h"	
#include "string.h"												    
#include "usart.h"
#include "delay.h"
#include "readp.h"


void ShowBagin(void)
{
  ReadP_From_SD("0:/PICTURE","0:/PICTURE/0002.bmp");
	POINT_COLOR=RED; 
	Show_Str(0,0,240,24,"����һ�ŷ��棡����",24,1); 
//	Show_Str(90,55,240,16,"�γ����",16,1);
		
//	POINT_COLOR=BRED;
//	Show_Str(40,95,240,16,"�����ˣ�",16,1);
//	Show_Str(55,125,240,16,"���ӿ�ѧ�뼼��1��",16,1);
//	Show_Str(95,155,240,16,"��Ǭ��",16,1);
//	Show_Str(40,185,240,16,"ѧ�ţ�20172447",16,1);
//		
//	POINT_COLOR=BRRED;
//	Show_Str(40,225,240,16,"ָ����ʦ��",16,1);
//	Show_Str(95,255,240,16,"��Ʈ��",16,1);
//	delay_ms(1500);
// 
}





