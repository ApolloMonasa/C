/*************************************************************************
	> File Name: 10.copy_constructor.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 24 Apr 2025 06:50:43 PM CST
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
    A() : x(0), y(1) {
        cout << this << "  default constructor\n";
    }
    A(const A& a) : x(a.x), y(a.y) {
        cout << this << "  copy constructor\n";
    }
    void operator=(const A &a) {
        cout << this << " operator=" << endl;
        return ;
    }
    void output() {
        cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    const A c;
    A a, b = c;
    b = a;
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    a.output();
    b.output();
    //=拷贝和=赋值 区别？
    //在对象的生命周期中的不同阶段
    

    return 0;
}
