#include "game.h"
#include "snake.h"
#include "text.h"
#include "lcd.h"
#include "malloc.h"	  
#include "rng.h"

Snake* g_pSHead = NULL;//��ͷ
int g_CountNode = 1;//��¼��ǰ�ڵ���

nDirection g_SDir;//�洢��ͷ����

void SnakeInit(void)//��ʼ����
{
	//�����ͷ�ĳ���
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

	//������ͷ
	g_pSHead = (Snake*)mymalloc(SRAMEX,sizeof(Snake));//����һƬ����Ϊ��ͷ�����Ϣ���ڴ�
	//check
	if (g_pSHead == NULL)
	{	
		POINT_COLOR = RED;
		Show_Str(296, 96,24,240,"��ͷ��ʼ��ʧ��", 24, 1);
		return;
	}
	mymemset(g_pSHead, 0, sizeof(Snake));//�������ҵ��ڴ渳��0

	//���������ͷ��λ��	
	g_pSHead->S_nRow = RNG_Get_RandomNum() % (GAME_ROWS - 8) + 4;//��ͷ�ĺ�����
	g_pSHead->S_nCol = RNG_Get_RandomNum() % (GAME_COLS - 8) + 4;//��ͷ��������

	g_pSHead->next = NULL;//Լ���ߵ�ĩ���ǿ�


	AddNode();
	AddNode();
}

void ShowSnake(void)//��ʾ��
{
	Snake *pNode = g_pSHead;
	int i;
	for (i = 0; i < g_CountNode; i++)
	{	
		if (i == 0)//�������ͷ������ͷλ�ô�ӡ��
		{
			POINT_COLOR = BRRED;
			Show_Str(pNode->S_nRow*16, pNode->S_nCol*16, 16, 16, "��", 16, 1);
		}
		else//����������򰤸�������λ�ô�ӡ��
		{
			POINT_COLOR = BROWN;
			pNode = pNode->next;
			Show_Str(pNode->S_nRow*16, pNode->S_nCol*16, 16, 16, "��", 16, 1);
		}
	}

}

void AddNode(void)//����һ���ڵ�
{
	int nNewRow;
	int nNewCol;
	if (g_CountNode == 1)//��ֻ��һ���ڵ㣨��ֻ����ͷ��
	{
		Snake* pNewSNode = NULL;//�����½ڵ�
		pNewSNode = (Snake*)mymalloc(SRAMEX,sizeof(Snake));//Ϊ�½ڵ�����һƬ�ռ��������Ϣ
		if (pNewSNode == NULL)
		{
			POINT_COLOR = RED;
			Show_Str(296, 48,24,240,"�ڵ㴴��ʧ��", 24, 1);
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
		pNewSNode->next = NULL;//Լ�����������NULL����
		g_CountNode++;//�ڵ�����һ
	}
	else//������һ���ڵ�
	{
		Snake* pTail = BodyFind(g_CountNode);//�洢������һ���ڵ�
		Snake* pTail2 = BodyFind(g_CountNode - 1);//�洢�����ڶ����ڵ�

		Snake* pNewSNode = NULL;//�����½ڵ�	
		pNewSNode = (Snake*)mymalloc(SRAMEX,sizeof(Snake));
		if (pNewSNode == NULL)
		{
			POINT_COLOR = RED;
			Show_Str(296, 48,24,240,"�ڵ㴴��ʧ��", 24, 1);
			return;
		}
		mymemset(pNewSNode, 0, sizeof(Snake));

		 nNewRow = pTail->S_nRow;
		 nNewCol = pTail->S_nCol;
		//������������ڵ����Թ�ϵ�������ж��½ڵ��λ��
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
		
		g_CountNode++;//�ڵ�����һ
	}
}

//Ѱ�ҵڼ����ڵ㣬�������Ǹ��ڵ�ĵ�ַ   
//���в��� NodeNum ����ָ���ĵڼ����ڵ㣨��������ȡֵ��1��ʼ��g_CountNode������
Snake* BodyFind(int NodeNum)
{
	int nCount = 0;
	Snake* pNode = g_pSHead;
	if (NodeNum >= 1 && NodeNum <= g_CountNode)//Ϊ��ֹ���δ����޶�һ������
	{
		while (NULL != pNode)
		{
			nCount++;
			if (NodeNum == nCount)
				break;
			pNode = pNode->next;
		}
		return pNode;//�ҵ��ýڵ�󷵻ظýڵ�
	}
	else
	{
			POINT_COLOR = RED;
			Show_Str(296, 48,24,240,"û���ҵ��ö�������", 24, 1);
	}
	return NULL;
}

//����ͷ����
//���� chDirection Ϊ����������ȡ�ķ����ֵ
//		a	
//  w   d   s
void ChangeDir(char chDirection)
{
	if ((chDirection == 'w' && g_SDir == RIGHT) ||//�����෴�޷��ı䷽��
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


//if ((chDirection == 'a' && g_SDir == LEFT) ||//������ͬ�ɼ����ƶ�
//	(chDirection == 'w' && g_SDir == UP) ||
//	(chDirection == 's' && g_SDir == DOWN) ||
//	(chDirection == 'd' && g_SDir == RIGHT))
//{
//	MoveSnake();
//	return;
//}

void MoveSnake(void)//�ƶ���
{
	int i;
	for (i = g_CountNode; i >= 2; i--)//����Ӻ���ǰһ�θ���
	{
		BodyFind(i)->S_nRow = BodyFind(i - 1)->S_nRow;
		BodyFind(i)->S_nCol = BodyFind(i - 1)->S_nCol;
	}

	switch (g_SDir)//ͷ�������ɳ������
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
