/*************************************************************************
	> File Name: 1.test1.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 01 May 2025 09:25:21 PM CST
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
    ~A() {
        cout << "destructor\n";
    }
public:
    A() {
        cout << "constructor\n";
    }
    void destroy() {
        delete this;
    }
};

int main() {
    A *pa = new A();
    pa->destroy();
    return 0;
}
