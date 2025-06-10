/*************************************************************************
	> File Name: 4.final.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 10 Jun 2025 07:33:50 PM CST
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

struct Base {
    virtual void test() {
        cout << "Base" << endl;
        return ;
    }
};

struct A : Base {
    void test() override final {
        cout << "A" << endl;
    }
};

struct B : A {
};

int main() {
    Base *p = new B;
    p->test();
    return 0;
}
