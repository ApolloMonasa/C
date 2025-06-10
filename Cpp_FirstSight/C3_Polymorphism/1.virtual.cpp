/*************************************************************************
	> File Name: 1.virtual.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 10 Jun 2025 04:56:27 PM CST
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

class Animal {
public:
    virtual void run() {
        cout << "I don't know how to run\n";
    }
};

class Cat : public Animal {
public:
    void run() override {
        cout << "I can run with four legs\n";
    }

};

int main() {
    Cat c;
    Animal *p = &c;
    c.run();
    p->run();
    return 0;
}
