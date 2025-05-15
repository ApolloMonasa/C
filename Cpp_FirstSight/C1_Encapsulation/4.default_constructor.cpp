/*************************************************************************
	> File Name: 4.default_constructor.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 23 Apr 2025 11:35:55 AM CST
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
    //1.没返回值2.和类同名3.声明的时候隐式调用
    A(){
        x = 0, y = 0;
        cout << "Default constructor\n";
    }
    void output() {
        cout << "(" << x << ", " <<  y << ")" << endl;
    }
};

int main() {
    A a;
    a.output();
    A b();//会被编译器当错函数声明,或者创建一个不存在的类A()的对象
    //b.output();
    
    //test
    A b();
    b();

    //How to deal it
    A bb{};
    bb.output();
    
    return 0;
}

A b() {
    cout << "hello function b\n";
    return A();
}
