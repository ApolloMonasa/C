/*************************************************************************
	> File Name: 1.DFS.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 21 Apr 2025 03:26:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>
#include<stdbool.h>

#define MAXN 150
//direction array
const int dxy[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point points[MAXN];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
    return ;
}

int empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, Point p) {
    if (s->top < MAXN - 1) {
        s->points[++(s->top)] = p;
    }
    return ;
}

Point pop(Stack *s) {
    return s->points[(s->top)--];
}

int dfs(int maze[][MAXN], int vis[][MAXN], int rows, int cols, Stack *path, Point cur, Point end) {
    if (cur.x == end.x && cur.y == end.y) {
        push(path, cur);
        return 1;
    }

    vis[cur.x][cur.y] = 1;
    push(path, cur);

    for (int i = 0; i < 4; i++) {
        int nx = cur.x + dxy[i][0];
        int ny = cur.y + dxy[i][1];
        Point next = {nx, ny};
        if (nx >= 1 && nx <= rows && ny >= 1 && ny <= cols && maze[nx][ny] == 0 && !vis[nx][ny]) {
            if (dfs(maze, vis, rows, cols, path, next, end)) {
                return 1;
            }
        }
    }

    //can't
    pop(path);
    return 0;
}

void DFS(int maze[][MAXN], int rows, int cols, Point start, Point end) {
    int vis[MAXN][MAXN] = {0};
    Stack path, *p = &path;
    initStack(p);
    
    if (dfs(maze, vis, rows, cols, p, start, end)) {
        printf("Find Way:\n");
        for (int i = 0; i <= path.top; i++) {
            printf("(%d, %d) ", path.points[i].x, path.points[i].y);
        }
        printf("\n");

        printf("迷宫路径图\n");
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                int isPath = 0;
                for (int k = 0; k <= path.top; k++) {
                    if (path.points[k].x == i && path.points[k].y == j) {
                        isPath = 1;
                        break;
                    }
                }
                if(isPath) {
                    printf("%2c", '*');
                } else {
                    printf("%2c", maze[i][j] ? '#' : ' ');
                }
            }
            printf("\n");
        }
    } else {
        printf("Can't Find!\n");
    }
}

void output(int maze[][MAXN], int rows, int cols, Point start, Point end){
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (i == start.x && j == start.y) printf(" S");
            else if (i == end.x && j == end.y) printf(" E");
            else {
                printf("%2c", maze[i][j] ? '#' : ' ');
            }
        }
        printf("\n");
    }
}

int main() {
    //example maze same as picture
    int maze[MAXN][MAXN] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int rows = 8;
    int cols = 10;

    Point start = {1, 1};
    Point end = {7, 10};

    //测试能找到出口的样例
    printf("test 1 :\n");
    output(maze, rows, cols, start, end);
    DFS(maze, rows, cols, start, end);
    //测试不能找到出口的样例
    printf("test 2 :\n");
    maze[8][10] = 1;
    output(maze, rows, cols, start, end);
    DFS(maze, rows, cols, start, end);

    return 0;
}
