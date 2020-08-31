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
	Show_Str(0,0,240,24,"这是一张封面！！！",24,1); 
//	Show_Str(90,55,240,16,"课程设计",16,1);
		
//	POINT_COLOR=BRED;
//	Show_Str(40,95,240,16,"制作人：",16,1);
//	Show_Str(55,125,240,16,"电子科学与技术1班",16,1);
//	Show_Str(95,155,240,16,"程乾杰",16,1);
//	Show_Str(40,185,240,16,"学号：20172447",16,1);
//		
//	POINT_COLOR=BRRED;
//	Show_Str(40,225,240,16,"指导老师：",16,1);
//	Show_Str(95,255,240,16,"徐飘荣",16,1);
//	delay_ms(1500);
// 
}





