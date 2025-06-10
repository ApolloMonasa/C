/*************************************************************************
	> File Name: 2.runtime_polymorphism.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 10 Jun 2025 05:11:37 PM CST
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

int f(int x) {
    return 2 * x;
}

double f(double x) {
    return 3.0 * x;
}

class Base {
public:
    virtual void test() {
        cout << "Base class test\n";
        return ;
    }
};

class A : public Base {
public:
    void test() override {
        cout << "A class test\n";return;
    }
};
class B : public Base {
public:
    void test() override {
        cout << "B class test\n";return;
    }
};

Base *rand_object() {
    switch(rand() % 3) {
        case 0 : return new Base;
        case 1 : return new A;
        case 2 : return new B;
    }
    return nullptr;
}

int main() {
    srand((unsigned size_t)time(NULL));
    cout << f(123) << endl;
    cout << f(12.3) << endl;
    rand_object()->test();
    return 0;
}
