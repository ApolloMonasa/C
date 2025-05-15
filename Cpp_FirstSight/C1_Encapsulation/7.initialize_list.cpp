/*************************************************************************
	> File Name: 7.initialize_list.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 23 Apr 2025 04:34:46 PM CST
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

namespace test1 {
class A {
    int x, y;
public:
    A() : A(1, 1) {}
    A(int x, int y) : x(x), y(y) {
        cout << "We just now used initialize_list to init x and y!\n";
    }
    void output() {
        cout << x << ", " <<  y << endl;
    }
};

int main() {
    A a(1, 2);
    a.output();
    A c;
    c.output();
    return 0;
}
};//test1


namespace test2 {

class B {

public :
    B(int x) : x(x) {
        cout << this << " : Class B constructor" << endl;
    }
    int x;
};

class A {
    B x, y;
public:
    A() : A(1, 1) {}
    A(int z) : y(z), x(z) {
        cout << "x : " << &x << endl;
        cout << "y : " << &y << endl;
        cout << "初始化列表执行顺序不是书写顺序， 而是定义顺序\n";
    }
    A(int x, int y) : x(x), y(y) {
        cout << "We just now used initialize_list to init x and y!\n";
    }
    void output() {
        cout << x.x << ", " <<  y.x << endl;
    }
};



    int main() {
        A a(5);//should x = 6, y = 5?
        a.output();
        return 0;
    }
};//test2


namespace test3 {

//使用初始化列表最重要的一个考量是效率问题,无论是代码简洁上还是执行效率上都是
//它比带参构造少两个赋值过程， 它直接调用相关字段的构造函数完成赋值
class B {
public :
    //B不能缺少默认构造,但有些时候有些类就是没有默认构造， 你咋整, 都要这样加一个毫无意义的默认构造吗？
    B() {
        cout << this << " default constructor\n";
    }
    B(int x) {
        cout << this << " : Class B constructor" << endl;
    }
    int x;
};

class A {
    B x, y;
public:
    A() : A(1, 1) {}
    A(int x, int y)  {
        this->x.x = x;
        this->y.x = y;
    }
    void output() {
        cout << x.x << ", " <<  y.x << endl;
    }
};

int main() {
    A a(3, 4);
    a.output();
    return 0;
}

};//test3


int main() {
    //test1::main();
    //test2::main();
    test3::main();
    return 0;
}
