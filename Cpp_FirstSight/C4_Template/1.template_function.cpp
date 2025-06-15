/*************************************************************************
	> File Name: 1.template_function.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 15 Jun 2025 10:48:06 PM CST
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

template<typename T>
T add(T a, T b) {
    return a + b;
}

template<typename A, typename B>
void Print(A a, B b) {
    cout << a << ", " << b << endl;
}

int main() {
    int a = 1, b = 2;
    double c = 1.1, d = 2.0;
    float e = 3.1, f = 0.04;

    cout << add(a, b) << endl;
    cout << add(c, d) << endl;
    cout << add(e, f) << endl;


    //显式调用
    cout << add<double>(3.14, 2.72) << endl;
    Print<int, char>(123, 'c');

    return 0;
}
