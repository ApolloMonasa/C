/*************************************************************************
	> File Name: 1.snakearr.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 06 Mar 2025 04:43:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>

void printSnakeMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int num = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        // 从顶部到底部填充左列
        for (int i = top; i <= bottom; ++i) {
            matrix[i][left] = num++;
        }
        left++;

        // 从左边到右边填充底部行
        for (int i = left; i <= right; ++i) {
            matrix[bottom][i] = num++;
        }
        bottom--;

        // 从底部到顶部填充右列
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][right] = num++;
            }
            right--;
        }

        // 从右边到左边填充顶部行
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[top][i] = num++;
            }
            top++;
        }
    }

    // 打印矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "请输入矩阵的大小 n: ";
    cin >> n;

    printSnakeMatrix(n);

    return 0;
}
