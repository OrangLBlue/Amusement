#include "game.h"
#include "snake.h"
#include "text.h"
#include "lcd.h"
#include "malloc.h"	  
#include "rng.h"

Snake* g_pSHead = NULL;//蛇头
int g_CountNode = 1;//记录当前节点数

nDirection g_SDir;//存储蛇头朝向

void SnakeInit(void)//初始化蛇
{
	//随机蛇头的朝向
	switch (rand() % 4)
	{
	case UP:
		g_SDir = UP;
		break;
	case DOWN:
		g_SDir = DOWN;
		break;
	case LEFT:
		g_SDir = LEFT;
		break;
	case RIGHT:
		g_SDir = RIGHT;
		break;
	default:
		break;
	}

	//创建蛇头
	g_pSHead = (Snake*)mymalloc(SRAMEX,sizeof(Snake));//申请一片放置为蛇头相关信息的内存
	//check
	if (g_pSHead == NULL)
	{	
		POINT_COLOR = RED;
		Show_Str(296, 96,24,240,"蛇头初始化失败", 24, 1);
		return;
	}
	mymemset(g_pSHead, 0, sizeof(Snake));//请理杂乱的内存赋予0

	//随机生成蛇头的位置	
	g_pSHead->S_nRow = RNG_Get_RandomNum() % (GAME_ROWS - 8) + 4;//蛇头的横坐标
	g_pSHead->S_nCol = RNG_Get_RandomNum() % (GAME_COLS - 8) + 4;//蛇头的纵坐标

	g_pSHead->next = NULL;//约定蛇的末端是空


	AddNode();
	AddNode();
}

void ShowSnake(void)//显示蛇
{
	Snake *pNode = g_pSHead;
	int i;
	for (i = 0; i < g_CountNode; i++)
	{	
		if (i == 0)//如果是蛇头则在蛇头位置打印■
		{
			POINT_COLOR = BRRED;
			Show_Str(pNode->S_nRow*16, pNode->S_nCol*16, 16, 16, "■", 16, 1);
		}
		else//如果是蛇身则挨个在蛇身位置打印◆
		{
			POINT_COLOR = BROWN;
			pNode = pNode->next;
			Show_Str(pNode->S_nRow*16, pNode->S_nCol*16, 16, 16, "◆", 16, 1);
		}
	}

}

void AddNode(void)//增加一个节点
{
	int nNewRow;
	int nNewCol;
	if (g_CountNode == 1)//若只有一个节点（即只有蛇头）
	{
		Snake* pNewSNode = NULL;//创建新节点
		pNewSNode = (Snake*)mymalloc(SRAMEX,sizeof(Snake));//为新节点申请一片空间存放相关信息
		if (pNewSNode == NULL)
		{
			POINT_COLOR = RED;
			Show_Str(296, 48,24,240,"节点创建失败", 24, 1);
			return;
		}
		mymemset(pNewSNode, 0, sizeof(Snake));

		nNewRow = g_pSHead->S_nRow;
		nNewCol = g_pSHead->S_nCol;
		switch (g_SDir)
		{
		case UP:
			nNewRow += 1;
			break;
		case DOWN:
			nNewRow -= 1;
			break;
		case LEFT:
			nNewCol += 1;
			break;
		case RIGHT:
			nNewCol -= 1;
			break;
		default:
			break;
		}
		pNewSNode->S_nRow = nNewRow;
		pNewSNode->S_nCol = nNewCol;
		g_pSHead->next = pNewSNode;
		pNewSNode->next = NULL;//约定链表最后以NULL结束
		g_CountNode++;//节点数加一
	}
	else//若大于一个节点
	{
		Snake* pTail = BodyFind(g_CountNode);//存储倒数第一个节点
		Snake* pTail2 = BodyFind(g_CountNode - 1);//存储倒数第二个节点

		Snake* pNewSNode = NULL;//创建新节点	
		pNewSNode = (Snake*)mymalloc(SRAMEX,sizeof(Snake));
		if (pNewSNode == NULL)
		{
			POINT_COLOR = RED;
			Show_Str(296, 48,24,240,"节点创建失败", 24, 1);
			return;
		}
		mymemset(pNewSNode, 0, sizeof(Snake));

		 nNewRow = pTail->S_nRow;
		 nNewCol = pTail->S_nCol;
		//根据最后两个节点的相对关系，进行判断新节点的位置
		if (pTail->S_nRow == pTail2->S_nRow
			&& pTail->S_nCol > pTail2->S_nCol)
		{
			nNewCol += 1;
		}
		else if (pTail->S_nRow == pTail2->S_nRow
			&& pTail->S_nCol < pTail2->S_nCol)
		{
			nNewCol -= 1;
		}
		else if (pTail->S_nRow > pTail2->S_nRow
			&& pTail->S_nCol == pTail2->S_nCol)
		{
			nNewRow += 1;
		}
		else if (pTail->S_nRow < pTail2->S_nRow
			&& pTail->S_nCol == pTail2->S_nCol)
		{
			nNewRow -= 1;
		}

		pNewSNode->S_nRow = nNewRow;
		pNewSNode->S_nCol = nNewCol;
		pTail->next = pNewSNode;
		pNewSNode->next = NULL;
		
		g_CountNode++;//节点数加一
	}
}

//寻找第几个节点，并返回那个节点的地址   
//其中参数 NodeNum 就是指定的第几个节点（这里正常取值从1开始到g_CountNode结束）
Snake* BodyFind(int NodeNum)
{
	int nCount = 0;
	Snake* pNode = g_pSHead;
	if (NodeNum >= 1 && NodeNum <= g_CountNode)//为防止传参错误限定一下区间
	{
		while (NULL != pNode)
		{
			nCount++;
			if (NodeNum == nCount)
				break;
			pNode = pNode->next;
		}
		return pNode;//找到该节点后返回该节点
	}
	else
	{
			POINT_COLOR = RED;
			Show_Str(296, 48,24,240,"没有找到该段身体呢", 24, 1);
	}
	return NULL;
}

//改蛇头朝向
//参数 chDirection 为从玩家哪里获取的方向键值
//		a	
//  w   d   s
void ChangeDir(char chDirection)
{
	if ((chDirection == 'w' && g_SDir == RIGHT) ||//方向相反无法改变方向
		(chDirection == 'a' && g_SDir == DOWN) ||
		(chDirection == 'd' && g_SDir == UP) ||
		(chDirection == 's' && g_SDir == LEFT))
	{
		return;
	}

	switch (chDirection)
	{
	case 'a':
		g_SDir = UP;
		break;
	case 'd':
		g_SDir = DOWN;
		break;
	case 'w':
		g_SDir = LEFT;
		break;
	case 's':
		g_SDir = RIGHT;
		break;
	default:
		break;
	}
}


//if ((chDirection == 'a' && g_SDir == LEFT) ||//方向相同可加速移动
//	(chDirection == 'w' && g_SDir == UP) ||
//	(chDirection == 's' && g_SDir == DOWN) ||
//	(chDirection == 'd' && g_SDir == RIGHT))
//{
//	MoveSnake();
//	return;
//}

void MoveSnake(void)//移动蛇
{
	int i;
	for (i = g_CountNode; i >= 2; i--)//身体从后往前一次覆盖
	{
		BodyFind(i)->S_nRow = BodyFind(i - 1)->S_nRow;
		BodyFind(i)->S_nCol = BodyFind(i - 1)->S_nCol;
	}

	switch (g_SDir)//头部坐标由朝向决定
	{
	case UP:
		g_pSHead->S_nRow -= 1;
		break;
	case DOWN:
		g_pSHead->S_nRow += 1;
		break;
	case LEFT:
		g_pSHead->S_nCol -= 1;
		break;
	case RIGHT:
		g_pSHead->S_nCol += 1;
		break;
	default:
		break;
	}
}
