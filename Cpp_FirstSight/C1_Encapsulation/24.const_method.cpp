/*************************************************************************
	> File Name: 24.const_method.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 02 May 2025 11:02:15 PM CST
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
    A(int x, int y) : x(x), y(y), z(0) {}
    void output() const {
        z++;
        cout << x << ", " << y << "(" << z << ")" << '\n';
    }
    int x, y;
    mutable int z;//miutibo, 可变的， 被它修饰的变量，可以在常成员函数（方法）中修改
};

int main() {
    const A a(3, 4);//const类型的对象只能调用const类型的方法
    a.output();//不是看修改没， 而是看能不能修改
    a.output();//不是看修改没， 而是看能不能修改
    a.output();//不是看修改没， 而是看能不能修改
    a.output();//不是看修改没， 而是看能不能修改
    return 0;
}
