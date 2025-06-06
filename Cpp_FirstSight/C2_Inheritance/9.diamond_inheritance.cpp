/*************************************************************************
	> File Name: 9.diamond_inheritance.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 06 Jun 2025 01:11:07 PM CST
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

/*
 * 结构特征：
 * 存在一个功能基类
 * 两个中间子类
 * 一个最终子类
 * 
 * 存在问题：
 * 数据冗余
 * 二义性
 *
 * 解决方法：
 * 虚拟继承(virtual key word)
 * 加在中间继承子类的继承列表
 */

class A {
public:
    int x;
};
class B : virtual public A {
public:
    void set_x(int x) {
        this->x = x;
        return ;
    }
};
class C : virtual public A {
public:
    int get_x() {
        return this->x;
    }
};
class D : public B, public C {

};

int main() {
    D d;
    d.set_x(123);
    cout << "after set_x(123) : \n";
    cout << d.get_x() << endl;
    return 0;
}
