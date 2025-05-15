/*************************************************************************
	> File Name: 2.SnakeArr.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 06 Mar 2025 04:47:54 PM CST
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
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    int num = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        for (int i = top; i <= bottom; ++i) {
            matrix[i][left] = num++;
        }
        left++;

        for (int i = left; i <= right; ++i) {
            matrix[bottom][i] = num++;
        }
        bottom--;

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][right] = num++;
            }
            right--;
        }

        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[top][i] = num++;
            }
            top++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int n;
    cin >> n;
    printSnakeMatrix(n);

    return 0;
}
