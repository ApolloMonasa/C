/*************************************************************************
	> File Name: 1.class_object.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 23 Apr 2025 10:38:20 AM CST
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

class Cat {};
class Dog {};
class People {
public:
    string name;
    int age;

    void say() {
        cout << "My name is " << name << "(" << age << " years old)" << endl;
    }
};

int main() {
    Cat garfield;
    Dog odie1, odie2;
    People hug, song;

    hug.name = "Captain Hu";
    hug.age = 50;
    hug.say();
    song.name = "Captain Song";
    song.age = 32;
    song.say();
    return 0;
}
