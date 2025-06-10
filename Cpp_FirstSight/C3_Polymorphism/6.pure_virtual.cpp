/*************************************************************************
	> File Name: 6.pure_virtual.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 10 Jun 2025 08:16:23 PM CST
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

class Flyable {
public:
    virtual void fly() = 0;
};

class Animal {
public:
    virtual void run() = 0;
};

class Cat : public Animal {
public:
    void run() override {
        cout << "Cat run\n";
    }
};

class Bat : public Animal, public Flyable {
public:
    void fly() override {
        cout << "Bat fly\n";
    }
    void run() override {
        cout << "Bat run\n";
    }
};

void f1(Flyable &obj) {
    cout << "this is obj : ";
    obj.fly();
    return ;
}

int main() {
    Cat c;
    c.run();
    Bat b;
    f1(b);
    return 0; 
}
