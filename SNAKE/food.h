#ifndef _FOOD_H
#define _FOOD_H

typedef struct tagFood{
	int F_nRow;
	int F_nCol;
}Food;

extern Food* g_pFoodPlace;

void NewFood(void);//������ʳ��
void ShowFood(void);//��ʾʳ��

#endif
