/*************************************************************************
	> File Name: 5.inherit_constructor_order.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 05 Jun 2025 10:05:40 PM CST
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
    Base() {
        cout << "Base constructor" << endl;
    }
    ~Base() {
        cout << "Base destructor" << endl;
    }
};
class A : public Base {
public:
    A() {
        data = new int[10];
        cout << "A constructor, data : " << data  << endl;
    }
    ~A() {
        if(data != nullptr) delete[] data;
        cout << "A destructor" << endl;
    }
    int *data;
};

class B : public Base {
public:
    B() {
        cout << "B constructor\n";

    }
    ~B() {
        cout << "B destructor\n";
    }
};
class C : public Base {
public:
    C() {
        cout << "C constructor\n";

    }
    ~C() {
        cout << "C destructor\n";
    }
};

/*
 * 先进行父类构造，后进行父类析构
 */

void func1() {
    cout << "Func1 : \n";
    A a;
    return ;
}

void func2() {
    /*
     * typical bug
     * p is a pointer of Base, so delete calls ~Base()
     * so ~A() is not called
     * 一个简单的改法是：(A *)p
     * 实际工程中改法见func3
     */
    cout << "Func2 : \n";
    Base *p = new A;
    delete (A *)p;
    return ;
}

void func3() {
    cout << "Func3 : \n";
    Base *p;
    switch(rand() % 3) {
        case 0: p = new A(); break;
        case 1: p = new B(); break;
        case 2: p = new C(); break;
    }
    delete p;
    /*
     * 暂时留下一个悬念，留待后面讲解
     * 当不知道具体类型的时候，如何正确调用析构函数
    */

}

int main() {
    srand(time(0));
    func1();
    func2();
    func3();
    return 0;
}
