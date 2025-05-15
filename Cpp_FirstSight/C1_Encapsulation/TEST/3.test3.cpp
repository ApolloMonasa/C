/*************************************************************************
	> File Name: 3.test3.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 05 May 2025 12:56:22 PM CST
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
    A(int x, int y) : x(x), y(y) {}
    int x,y;
};

A operator+(A a, A b) {
    return A(a.x+b.x, a.y+b.y);
}
ostream &operator<<(ostream &out, const A &a) {
    out << "operator<< : (" << a.x << ", " << a.y << ")";
    return out;
}
int main() {
    A a(3,4), b(7,10);
    A c = a+ b;
    cout << c << " : end" << endl;
}
