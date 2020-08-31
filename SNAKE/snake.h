#ifndef _SNAKE_H
#define _SNAKE_H

typedef struct tagSnake{//蛇身结构体链表
	int S_nRow;//蛇横坐标
	int S_nCol;//蛇纵坐标
	struct tagSnake* next;//保存下一个节蛇身

}Snake;

typedef enum Direction//朝向枚举
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}nDirection;

extern nDirection g_SDir;//朝向
extern Snake* g_pSHead;//蛇头
extern int g_CountNode;//记录当前节点数


void SnakeInit(void);//初始化蛇
void ShowSnake(void);//显示蛇
void AddNode(void);//增加一个节点
Snake* BodyFind(int NodeNum);//寻找第几个节点，并返回那个节点的地址
void ChangeDir(char chInput);//改蛇头朝向
void MoveSnake(void);//移动蛇

#endif

