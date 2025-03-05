#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 80

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int row, int col, char set);

//打印棋盘
void DisplayBoard(char board[ROWS][COLS],int row,int col);

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

//排雷
void Sweep(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//计数
int GetMineCount(char mine[ROWS][COLS], int x, int y);
