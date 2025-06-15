/*************************************************************************
	> File Name: 2.add.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 15 Jun 2025 11:04:04 PM CST
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


#include <sstream>

#define P(func) {\
    cout << #func << " = " << func << endl;\
}

//V1
/*
template<typename T>
//同名模板变量不能表示不同类型
T add(T a, T b) {
    return a + b;
}*/

//V2
/*
template<typename T, typename U>
decltype(T() + U()) add(T a, U b) {
    return a + b;
}*/

//V3
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b){
    return a + b;
}

void is_type(int a) {
    cout << "a is int\n";
}
void is_type(double a) {
    cout << "a is double\n";
}

class A {
public:
    A(int x) : x(x) {};
    int x;
};
class B {
public:
    B(double x = 0) : x(x) {}
    double x;
};

string operator+(const A &a, const B &b) {
    ostringstream ss;
    ss << a.x << ", " << b.x;
    return ss.str();
}

int main() {
    //cout << add(3.4, 6) << endl;
    //
    //但是显示指定类型是可以的
    //P(add<double>(3.4, 6));
    //P(add<int>(3.4, 6));
    

    //解决：decltype
    decltype(3.4 + 6) a;
    is_type(a);

    P(add(3.4, 6));
    P(add(6, 3.4));

    //bug3
    A a1(9);
    B a2(3.4);

    P(add(a1, a2));

    return 0;
}
