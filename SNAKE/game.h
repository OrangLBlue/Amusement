#ifndef _GAME_H
#define _GAME_H

#include "sys.h"

#define GAME_ROWS 15
#define GAME_COLS 15


u8 SnakeBegin(void);//模式选择
void GameInit(void);//游戏初始化
void SnShowGame(void);//显示游戏元素
int SnIsCanMove(void);//碰撞检测
int IsEatSelf(void);//判断是否自食
void IsEatFood(void);//检测是否吃到食物
void ShowScore(u16 x,u16 y,u16 width,u16 height,u8 size,u8 mode);//分数统计
void Run(u8 nDeg);//运行游戏


#endif

