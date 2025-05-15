/*************************************************************************
	> File Name: 22.property.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 01 May 2025 09:43:38 PM CST
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

class People {
public:
    People() {cnt++;}
    string name;//成员属性：分别属于不同对象
    static int cnt;//类属性：所有对象公用//但是这里只是一个声明， 我们需要再类外面单独定义
    ~People() {cnt--;};
};

int People::cnt = 0;

void f() {
    People a, b;
    cout << "cnt : " << People::cnt << endl;
}

int main() {
    People a, b;
    a.name = "Apollo";
    cout << "cnt : "<< People::cnt << endl;
    People c;
    cout << "cnt : "<< People::cnt << endl;
    f();
    cout << "cnt : "<< People::cnt << endl;


    return 0;
}
