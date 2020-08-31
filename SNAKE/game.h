#ifndef _GAME_H
#define _GAME_H

#include "sys.h"

#define GAME_ROWS 15
#define GAME_COLS 15


u8 SnakeBegin(void);//ģʽѡ��
void GameInit(void);//��Ϸ��ʼ��
void SnShowGame(void);//��ʾ��ϷԪ��
int SnIsCanMove(void);//��ײ���
int IsEatSelf(void);//�ж��Ƿ���ʳ
void IsEatFood(void);//����Ƿ�Ե�ʳ��
void ShowScore(u16 x,u16 y,u16 width,u16 height,u8 size,u8 mode);//����ͳ��
void Run(u8 nDeg);//������Ϸ


#endif

