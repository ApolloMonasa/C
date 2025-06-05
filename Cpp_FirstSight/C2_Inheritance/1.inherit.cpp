/*************************************************************************
	> File Name: 1.inherit.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 15 May 2025 09:25:08 PM CST
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
protected://子类和本类可以访问
    string name;
public:
    Animal() = delete;
    Animal(string name) : name(name) {}
    void set(string name) {this->name = name;}
    void say(){
        cout << "My name is " << name << '\n';
    }

};

class Cat : public Animal {
public:
    Cat(string name) : Animal(name) {}
    void run() {
        cout << "I can run with four legs\n";
    }
};

class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {}
    void run() {
        cout << "I can run with four legs\n";
    }
};
class Bat : public Animal {
public:
    Bat(string name) : Animal(name) {}
    void fly() {
        cout << "I can fly, I am " << this->name << endl;
    }
};
int main() {
    Cat a1("Garfield");
    Dog a2("Odie");
    Bat a3("Draacula");
    a1.run();
    a2.run();
    a3.fly();

    return 0;
}
