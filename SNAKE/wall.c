#include "wall.h"
#include "game.h"
#include "text.h"
#include "lcd.h"
#include "CSnake.h"

void WallInit(void)//Χǽ��ʼ��
{
	int nRow;
	int nCol;
	//�ڱ�Ե��������Χǽ
	for (nRow = 0; nRow < GAME_ROWS; nRow++)
	{
		for (nCol = 0; nCol < GAME_COLS; nCol++)
		{
			if (nRow == 0 ||
				nRow == GAME_ROWS - 1 ||
				nCol == 0 ||
				nCol == GAME_COLS - 1)
			{
				  POINT_COLOR = BLUE;
			    Show_Str(nRow*16,nCol*16,16,16,"��",16,1);
			}
		}
	}
}
