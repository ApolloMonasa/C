/*************************************************************************
	> File Name: 17.delete_default.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 29 Apr 2025 02:14:48 PM CST
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
    A() = default;
    A(const A &) = delete;
    A(int) {}
};

int main() {
    A a;
}
