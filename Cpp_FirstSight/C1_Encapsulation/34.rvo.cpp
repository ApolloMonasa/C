/*************************************************************************
	> File Name: 34.rvo.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 15 May 2025 08:00:11 PM CST
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
    A() {
        cout << "default constructor\n";
    }
    A(const A &a) {
        cout << "copy constructor\n";
    }
};

A f() {
    A temp;
    cout << "f() : temp :" << &temp << '\n'; 
    return temp;
    //返回值优化rvo指的是return的临时变量被优化掉了
    //命名返回值优化指的是temp直接当作a的别名（地址相同）
}

int main() {
//    A c, b(c);
    A a = f();
    cout <<  "a : " << &a << endl;
    return 0;
}
