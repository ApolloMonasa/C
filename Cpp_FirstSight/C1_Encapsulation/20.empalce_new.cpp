/*************************************************************************
	> File Name: 20.empalce_new.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 01 May 2025 04:37:30 PM CST
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
    A(int x) : x(x), data(new int[10]) {
        cout << "constructor\n";
    }
    void output() {
        cout << "x : " << x << endl;
    }
    ~A() {
        cout << "destructor\n";
        delete[] data;
    }
    int x, *data;
};

int main() {
    //分成两步，1、申请空间 2、原地构造
    A *arr = (A *)malloc(sizeof(A) * 5);
    for (int i = 0; i < 5; i++) {
        new(arr + i) A(i);
    }
    for (int i = 0; i < 5; i++) {
        arr[i].output();
    }
    //尽管内存是malloc分配的但是回收不能直接用free，因为如果对象只有构造没有析构过程容易内存泄露，比如对象内有存储区
    //但是也不能用delete, 因为不是new申请的，得手动调析构函数
    for (int i = 0; i < 5; i++) {
        arr[i].~A();
    }
    free(arr);
    return 0;
}
