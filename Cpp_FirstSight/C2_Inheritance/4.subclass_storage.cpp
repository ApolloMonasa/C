/*************************************************************************
	> File Name: 4.subclass_storage.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 05 Jun 2025 09:34:54 PM CST
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

class Base1 {
public:
    Base1() : b1(0x11111111) {}
    int b1;
};

class Base2 {
public:
    Base2() : b2(0x22222222) {}
    int b2;
};

class A : public Base2, public Base1 {
public:
    A() : a(0x33333333) {}
    int a;
};

void output_address(void *_p, size_t n) {
    unsigned char *p = (unsigned char *)(_p);
    printf("%p : ", p);
    for (int i = 0; i < n; i++) {
        if(i%8==0) printf("\n");
        printf("%02X ", p[i]);
    }
    printf("\n");
}
/*
 * 存储顺序：
 * 父类在前，子类在后
 * 父类之间顺序取决于继承顺序
 */

class B : public Base1, public A {
public:
    B() : x(0x44444444) {}
    int x;
};

int main() {
    A a;
    B b;
    output_address(&a, sizeof(a));
    output_address(&b, sizeof(b));
    return 0;
}
