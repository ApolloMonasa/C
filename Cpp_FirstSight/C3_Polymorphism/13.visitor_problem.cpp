/*************************************************************************
	> File Name: 13.visitor_problem.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 15 Jun 2025 03:50:50 PM CST
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
 * 介绍访问者模式这种架构
 */

class Base {
public:
    virtual ~Base() {}
    virtual void output() = 0;
};

class A : public Base {
    void output() override {
        cout << "Class A\n";
    }
};
class B : public Base {
    void output() override {
        cout << "Class B\n";
    }
};
class C : public Base {
    void output() override {
        cout << "Class C\n";
    }
};

int main() {
    srand(time(0));
    Base *p;
    switch(rand() % 3) {
        case 0 :p = new A; break;
        case 1 :p = new B; break;
        case 2 :p = new C; break;
    }

    p->output();

    if(dynamic_cast<A *>(p) != nullptr) {
        cout << "Class A : dynamic_cast\n";
    }
    if(dynamic_cast<B *>(p) != nullptr) {
        cout << "Class B : dynamic_cast\n";
    }
    if(dynamic_cast<C *>(p) != nullptr) {
        cout << "Class C : dynamic_cast\n";
    }
}
