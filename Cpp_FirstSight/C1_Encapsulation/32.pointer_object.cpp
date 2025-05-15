/*************************************************************************
	> File Name: 32.pointer_object.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 15 May 2025 04:02:46 PM CST
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
public:
    int x, y;
};

class PointerA {
public:
    PointerA(A *p) : p(p) {}
    A *operator->() {return p;}
    A &operator*() {return *p;}
    A *p;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}

int main() {
    A a;
    PointerA p = &a;
    p->x = 3;
    p->y = 4;
    cout << *p << endl;
    return 0;
}
