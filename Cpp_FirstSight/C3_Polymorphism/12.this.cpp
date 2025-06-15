/*************************************************************************
	> File Name: 11.virtual_function_table.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 15 Jun 2025 02:54:48 PM CST
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
    virtual void test() {
        cout << "test : Class Base " << endl;
    }
    virtual void test2(int x) {
        cout << this << "  test2 : Class Base " << x << endl;
    }
    virtual void test3() {
       cout << this << "  test3 : Class A "  << endl;
    }

};

class A : public Base {
public:
    int y;
    void test() override {
        cout << "test : Class A\n";
    }
    void test2(int x) override {
        cout << this << "  test2 : Class A " << x << endl;
    }
    void test3() override {
       cout << this << "  test3 : Class A " << y << endl;
    }
};

typedef void (*funcT)();
typedef void (*funcT2)(void *, int);
typedef void (*funcT3)(void *);

void test1() {
    A a, a2;
    cout << "virtual table address : " << ((funcT **)(&a))[0] << endl;;
    ((funcT **)(&a))[0][0]();

    a.test2(100);
    ((funcT2 **)(&a))[0][1](&a, 100);//传参失败,这个内容涉及this指针的深入理解

    a.y = 123;
    a2.y = 456;
    ((funcT3 **)(&a))[0][2](&a2);//传参失败,这个内容涉及this指针的深入理解
}

int main() {
    test1();
    return 0;
}
