/*************************************************************************
	> File Name: 15.con_des_order.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 29 Apr 2025 11:18:53 AM CST
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
namespace test1{
class A {
public:
    A (string name) : name(name) {
        cout << name << " constructor\n";
    }
    ~A() {
        cout << name << " destructor\n";
    }
    string name;
};

class B {
    string name;
    A &a;
    int *data;
public:
    B(A &a, string name) : a(a), name(name) {
        cout << name << " constructor\n";
        if (a.name == "c") {
            data = new int[10];
        } else  {
            data = new int();
        }
    }
    ~B() {
        if (a.name == "c") {
            cout << name << " destructor int[]\n";
            delete[] data;
        } else {
            cout << name << " destructor int\n";
            delete data;
        }
    }
};

int main() {
    A c{"c"}, d("d");
    B a{c, "a"}, b{d, "b"};
    return 0;
}
//为什么总是先构造的后析构？？
//先产生的对象可能和后面的对象有关，所以我们析构的时候也可能要用到先前对象的信息， 所以就要后析构
}//test1


class A {
public:
    A (string name) : name(name) {
        cout << name << " constructor\n";
    }
    ~A() {
        cout << name << " destructor\n";
    }
    string name;
};

class B {
    A c, d;
    string name;
public:
    B(string name) : c(name+".c"), d(name+".d"), name(name) {
        cout << name << " constructor\n";
    }
    ~B() {
        cout << name << " destructor\n";
    }
};

int main() {
    B b{"b"};
    return 0;
}
//属性
 
