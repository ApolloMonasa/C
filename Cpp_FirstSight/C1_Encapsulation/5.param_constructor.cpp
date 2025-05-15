/*************************************************************************
	> File Name: 5.param_constructor.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 23 Apr 2025 03:50:53 PM CST
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

class A {
    int x, y;
public:
    //委托构造
    A() : A(100, 1000) {  }


    /*A(){
        x = 100, y = 1000;
    }*/

    /*A(int xx, int yy) {
        x = xx, y = yy;
    }*/
    A(int x, int y) {
        this->x = x, this->y = y;
    }
    void output() {
        cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    A a(10, 100), b{20, 23};
    a.output();
    b.output();
    //当有了有参构造之后，隐式默认构造会被删除， 如果还想这样写，就要手动写一个显式默认构造
    A c;
    c.output();
    return 0;
}
