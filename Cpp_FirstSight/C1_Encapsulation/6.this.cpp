/*************************************************************************
	> File Name: 6.this.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 23 Apr 2025 04:08:15 PM CST
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
    int x, y;
public:
    A() : A(0, 0) {
        cout << this << " : default constructor\n";
    }
    A(int x, int y) {
        cout << this << " : param constructor\n";
        this->x = x, this->y = y;
    }
    void output() {
        cout << this << " : call function\n";
        cout << this->x << ", " << this->y << endl;
    }
};

int main() {
    A a(10, 101), b;
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    a.output();
    b.output();
    a.output();
    return 0;
}
