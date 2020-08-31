#ifndef __VIEW_H
#define __VIEW_H

#include "sys.h"

extern int g_BrickCount;

void ShowBackground(void);
void ShowBrick(void);
void ShowGame(void);
void OnLeft(void);
void OnRight(void);
void OnUp(void);
void OnDown(void);
void Remove(void);
void DeleteBrick(void);
void BrickCount(u16 x,u16 y,u16 width,u16 height,u8 size,u8 mode);
void IsEnd(void);



#endif
