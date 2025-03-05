//#define _CRT_SECURE_NO_WARNINGS 1
//#include "sweeper.h"
//
//int count = EASY_COUNT;
//
////菜单打印
//menu()
//{
//	printf("**********************************\n");
//	printf("********    1.play       *********\n");
//	printf("********    0.exit       *********\n");
//	printf("**********************************\n");
//	printf("请选择-->:");
//}
//
//
//void InitBoard(char board[ROWS][COLS], int row, int col, char set)
//{
//	int i = 0, j = 0;
//	for (; i < row; i++)
//	{
//		for (j=0; j < col; j++)
//		{
//			board[i][j] = set;
//		}
//	}
//
//}
//
//void DisplayBoard(char board[ROWS][COLS], int row, int col)
//{
//	int i = 0, j = 0;
//	printf("-------扫雷------\n");
//	printf("0 ");
//	for (i = 1; i <= col; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//
//	for (i=1; i <= row; i++)
//	{
//		printf("%d ", i);
//		for (j=1; j <= col; j++)
//		{
//			printf("%c ", board[i][j]);
//		}
//		printf("\n");
//	}
//	printf("-------扫雷------\n");
//
//}
//
//void SetMine(char board[ROWS][COLS], int row, int col)
//{
//	
//	while (count)
//	{
//		//如何布置？生成随机下标！
//		//x：1-9  y：1-9
//		int x = rand() % row + 1;
//		int y = rand() % col + 1;
//		if (board[x][y] != '1')
//		{
//			board[x][y] = '1';
//			count--;
//		}
//
//	}
//}
//
//int GetMineCount(char mine[ROWS][COLS], int x, int y)
//{
//	int i = 0, j = 0;
//	int sum = 0;
//	//for (i = -1; i <= 1; i++)
//	//{
//	//	for (j = -1; j <= 1; j++)
//	//	{
//	//		sum += mine[x + i][y + j] - '0';
//	//	}
//	//}
//	sum = mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x - 1][y] + mine[x + 1][y] + mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] - 8 * '0';
//	return sum;
//}
//
//void Sweep(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	int x = 0, y = 0, win = 0, count = EASY_COUNT;//之所以在这里重新为count赋值，是因为，在之前的布雷环节让它变小了。
//
//	while (win<ROW*COL-count)
//	{
//		printf("请输入要排查的坐标(x,y)：");
//		next:
//		scanf("%d %d", &x, &y);
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (mine[x][y] == '1')
//			{
//				printf("你被炸死了！游戏结束！！\n");
//				DisplayBoard(mine, ROW, COL);
//				break;
//			}
//			else
//			{
//				win++;
//				//统计周围雷数
//				int c = GetMineCount(mine, x, y);
//				show[x][y] = c + '0';
//				DisplayBoard(show, ROW, COL);
//			}
//		}
//		else
//		{
//			printf("输入坐标有误！请重新输入！\n");
//			goto next;
//		}
//
//	}
//	if (win == ROW * COL - count)
//	{
//		printf("恭喜你，排雷成功!!!!!!\n");
//		DisplayBoard(mine, ROW, COL);
//	}
//
//
//}
//
