/*************************************************************************
	> File Name: 9.const_cast.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 14 Jun 2025 09:43:08 PM CST
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
    A() : x(11), y(22) {}
    void output() const {
        cout << "x = " << x << ", y = " << y << endl;
    }
    int x, y;
};

void test1() {
    cout << "Test1\n";
    const int x = 123;
    const int *p1 = &x;
    //int *p2 = p1;
    //int *p2 = static_cast<int *>(p1);
    int *p2 = const_cast<int *>(p1);
    *p2 = 456;
    cout << *p2  << endl;
}

void test2() {
    cout << "Test2\n";
    const A a;
    const A *p1 = &a;
    //A &a2 = static_cast<A&>(a);
    A &a2 = const_cast<A&>(a);
    A *p2 = const_cast<A *>(p1);
    a.output();//注意const类型的对象只能使用const类型的方法
    p2->x = 22;
    p2->output();
    a2.y = 11;
    a2.output();
    
}


int main() {
    test1();
    test2();


    return 0;
}
