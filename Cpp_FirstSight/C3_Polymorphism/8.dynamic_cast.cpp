/*************************************************************************
	> File Name: 8.dynamic_cast.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 13 Jun 2025 08:36:14 PM CST
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
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {
public:
    void output() {
        cout << "x = " << x << ", y = " << y << endl;
        return ;
    }
    int x, y;
};

int main() {
    //A *p1 = new A;
    B *p1 = new B;
    Base *p2 = p1;//隐式转换
    //B *p3 = dynamic_cast<B *>(p2);
    A *p3 = dynamic_cast<A *>(p2);
    if(p3 == nullptr) {
        cout << "convert failed\n";
    }
    //else p3->output();
    else cout << "sucsseed!\n";
    return 0;
}
