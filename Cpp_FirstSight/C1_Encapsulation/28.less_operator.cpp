/*************************************************************************
	> File Name: 28.less_operator.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 05 May 2025 01:43:15 PM CST
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
    A(int x = 0) : x(x) {}
    int x;
    bool operator<(const A &obj) const {
        return x < obj.x;
    }
    bool operator>(const A &obj) const {
        return obj < *this;
    }
    bool operator==(const A &obj) const {
        return !(*this < obj) && !(obj < *this);
    }

    bool operator!=(const A &obj) const {
        return !(*this == obj);
    }
    bool operator>=(const A &obj) const {
        return (obj<*this)||(obj==*this);
    }
    bool operator<=(const A &obj) const {
        return (*this < obj)||(*this==obj);
    }
};
map<A, int> h;
#define P(stmt) {\
    cout << #stmt << " : " << (stmt) << endl;\
}
int main() {
    A a(3), b(4);
    h[a] = 123;
    cout << h[a] << endl;
    P(a < b);
    P(a > b);
    P(a == b);
    P(a != b);
    P(a <= b);
    P(a >= b);
    return 0;
}
