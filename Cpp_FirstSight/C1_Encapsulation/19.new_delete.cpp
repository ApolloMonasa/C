/*************************************************************************
	> File Name: 19.new_delete.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 01 May 2025 04:16:39 PM CST
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
    A(){}
    A(int) : type("A(int)"){
        cout << type << " constructor\n";
    }
    A(double) : type("A(double)") {
        cout << type << " constructor\n";
    }
    A(int, int) : type("A(int, int)"){
        cout << type << " constructor\n";
    }
    ~A() {
        cout << type << " destructor\n";
    }
    string type;
};

int main() {
    int *p1 = new int;//申请单一变量
    int *p2 = new int(100);//赋值
    int *p3 = new int[100];//申请连续空间
    cout << p1 << ' ' << "sizeof(*p1) = " << sizeof(*p1) << endl;
    cout << p2 << " *p2 = " << *p2 << endl;
    for (int i = 0; i < 100; i++) {
        p3[i] = i + 1;
    }
    for (int i = 0; i < 100; i++) {
        cout << p3[i] << " ";
    }
    cout << endl;

    delete p1;
    delete p2;
    delete[] p3;

    A *a1 = new A(1);
    A *a2 = new A(2.0);
    A *a3 = new A(3, 3);
    delete a1;
    delete a2;
    delete a3;

    A *arr = new A[100];//这个时候调用的是默认构造，那么没有默认构造怎么办？
}
