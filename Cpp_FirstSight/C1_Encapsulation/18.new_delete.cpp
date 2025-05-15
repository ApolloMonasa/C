/*************************************************************************
	> File Name: 18.new_delete.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 01 May 2025 03:57:44 PM CST
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
    A() = delete;
    A(string msg) {
        cout << msg << " constructor\n";
    }
    ~A() {
        cout << "destructor\n";
    }
};

int main() {
    //malloc只把存储空间整出来了， 没有调用构造函数，而new会调用相关对象的构造函数
    //free和delete的差别类似
    A *malloc_a = (A *)malloc(sizeof(A));
    free(malloc_a);
    A *new_a = new A("new");
    delete new_a;
    return 0;
}
