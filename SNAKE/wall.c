#include "wall.h"
#include "game.h"
#include "text.h"
#include "lcd.h"
#include "CSnake.h"

void WallInit(void)//围墙初始化
{
	int nRow;
	int nCol;
	//在边缘画■建立围墙
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
			    Show_Str(nRow*16,nCol*16,16,16,"■",16,1);
			}
		}
	}
}
