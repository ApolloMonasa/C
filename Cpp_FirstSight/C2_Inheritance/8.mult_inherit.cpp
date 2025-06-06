/*************************************************************************
	> File Name: 8.mult_inherit.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 06 Jun 2025 01:00:01 PM CST
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

class Base1 {};
class Base2 {};
class A : public Base1, protected Base2 {};


/*
 * typical usage
 * 功能拼装
 */
class Flyable {
public:
    void fly() {
        cout << "flying in the sky" << endl;
    }
 };
class Swimmable {
public:
    void swim() {
        cout << "Swimming in the water" << endl;
    }
};

class Duck : public Flyable, public Swimmable {
public:
    void quack() {
        cout << "Quack, Ga Ga Ga" << endl;
        return ;
    }
};

int main() {
    Duck d;
    d.fly();
    d.swim();
    d.quack();
    return 0;
}
