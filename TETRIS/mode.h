#ifndef __MODE_H
#define __MODE_H

#define TEGAME_ROWS 20
#define TEGAME_COLS 15

extern char g_chBackground[TEGAME_ROWS][TEGAME_COLS];
extern char g_chBrick[4][4];
extern int g_nRow;
extern int g_nCol;
extern int g_End;

void InitBackground(void);
void GetNewBrick(void);
void CombineBgBrick(void);
void DetachBgBrick(void);
int TeIsCanMove(int nToRow, int nToCol);
void Rotate(void);
int IsCanRotate(void);


#endif
