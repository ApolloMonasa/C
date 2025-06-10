/*************************************************************************
	> File Name: 3.override.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 10 Jun 2025 07:20:11 PM CST
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
        cout << "Base class test" << endl;
    }
    virtual void foo() {
        cout << "Base class foo" << endl;
    }
};
class A :public Base {
public:
    void test() {
        cout << "A class test" << endl;
    }

    void foo() override {
        cout << "A class foo\n";
    }
};

int main() {
    Base *p = new A;
    p->test();
    p->foo();
    return 0;
}
