/*************************************************************************
	> File Name: 3.inherit_pointer.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 17 May 2025 06:55:00 PM CST
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

class Base {
public:
    Base(int x, int y) : x(x), y(y) {}
    int x, y;
};

class A : public Base {
public:
    A(int x, int y, int z) : Base(x, y), z(z) {}
    int z;
};

void func1(Base *p) {
    cout << "Base : " << p->x <<  ", " << p->y << endl;
    return ;
}

int main() {
    A a(3, 4, 5), *p = &a;//子类的地址可以隐式转换为父类的地址
    func1(p);
    Base &b = a;//子类对象可以绑定到父类引用
    return 0;
}
