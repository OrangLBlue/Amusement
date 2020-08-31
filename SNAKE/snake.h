#ifndef _SNAKE_H
#define _SNAKE_H

typedef struct tagSnake{//����ṹ������
	int S_nRow;//�ߺ�����
	int S_nCol;//��������
	struct tagSnake* next;//������һ��������

}Snake;

typedef enum Direction//����ö��
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}nDirection;

extern nDirection g_SDir;//����
extern Snake* g_pSHead;//��ͷ
extern int g_CountNode;//��¼��ǰ�ڵ���


void SnakeInit(void);//��ʼ����
void ShowSnake(void);//��ʾ��
void AddNode(void);//����һ���ڵ�
Snake* BodyFind(int NodeNum);//Ѱ�ҵڼ����ڵ㣬�������Ǹ��ڵ�ĵ�ַ
void ChangeDir(char chInput);//����ͷ����
void MoveSnake(void);//�ƶ���

#endif

