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
    A &operator*=(int c) {
        x*=c, y*=c;
        return *this;
    }
};

A operator+(A a, A b) {
    return A(a.x+b.x, a.y+b.y);
}

ostream &operator<<(ostream &os, const A a) {
    os << "(" << a.x << ", " << a.y << ")";
    return os;
}

//类外重载把调用操作符的对象当参数
//类内重载把调用操作符的对象当对象
int main() {
    A a(3, 4), b(7, 10);
    A c = a+b;
    c.output();
    //cout << c << endl;
    //见test
    (c*=3)*=4;
    cout << c << endl;
    int n = 2;
    (n *= 3) *= 4;//右结合，返回左值
    cout << "n = " << n << '\n';
    return 0;
}
