#ifndef _FOOD_H
#define _FOOD_H

typedef struct tagFood{
	int F_nRow;
	int F_nCol;
}Food;

extern Food* g_pFoodPlace;

void NewFood(void);//产生新食物
void ShowFood(void);//显示食物

#endif
