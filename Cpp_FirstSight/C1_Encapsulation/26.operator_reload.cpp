/*************************************************************************
	> File Name: 26.operator_reload.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 05 May 2025 12:45:42 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<numeric>
using namespace std;

class A {
public:
    A(int x, int y) : x(x), y(y) {}
    int x, y;
    void output() {
        cout << "(" << x << ", "<<y << ")" << endl;
    }
};

A operator+(A a, A b) {
    return A(a.x+b.x, a.y+b.y);
}

int main() {
    A a(3, 4), b(7, 10);
    A c = a+b;
    c.output();
    //cout << c << endl;
    //见TEST
    return 0;
}
