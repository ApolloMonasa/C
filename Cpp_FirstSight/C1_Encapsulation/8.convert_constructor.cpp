/*************************************************************************
	> File Name: 8.convert_constructor.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 23 Apr 2025 05:48:12 PM CST
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
    //这就叫做转换构造
    A(int z) : x(z), y(z) {
        cout << this << " : convert constructor\n";
    }
    void operator=(const A &a) {
        this->x = a.x;
        this->y = a.y;
        cout << this << " operator=\n";
    }
    void output() {
        cout << "(" << x << ". " << y << ")\n";
    }
};

int main() {
    A a(520), b{1314}, c = 5201314;
    a.output();
    b.output();
    c.output();
    return 0;
}
