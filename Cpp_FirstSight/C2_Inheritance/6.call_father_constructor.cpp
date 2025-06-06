/*************************************************************************
	> File Name: 6.call_father_constructor.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 06 Jun 2025 11:01:03 AM CST
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
    Base() : x(3) {
        cout << "Base default constructor" << endl;
    }
    Base(int x) {
        cout << "Base(int x) constructor" << endl;
    }
    
    Base(const Base &b) {
        x = b.x;
        cout << "Base copy constructor" << endl;
    }
    int x;
};

class A : public Base {
public:
    A() : y(4) {
        cout << "A default constructor" << endl;
    }
    /*默认会自动调用父类的拷贝构造
     * 但是当我们增加了这个子类的拷贝构造之后，父类的拷贝构造就不会自动调用了
     */
    A(const A &obj) : Base(obj) {
        this->y = obj.y;
        cout << "A copy constructor" << endl;
    }
    A &operator=(const A &a) {
        y = a.y;
        this->Base::operator=(a);
        return *this;
    }
    int y;
};

ostream &operator<<( ostream &out, const A &a) {
    out << "class A(" << a.x << ", " << a.y  << ")";
    return out;
}

int main() {
    /*
     * 子类的任何构造函数调用时
     * 默认调用父类的默认构造
     * 可以在初始化列表中显式调用父类的有参构造
    */
    A a, c;
    cout << "a :" << a << endl;
    cout << "c :" << c << endl;
    a.x = 1000, a.y = 999;
    c = a;
    cout << "(After c = a)c :" << c << endl;
    A b = a;
    cout << b << endl;
    return 0;
}
