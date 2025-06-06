/*************************************************************************
	> File Name: 10.virtual_inheritance_model.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 06 Jun 2025 01:25:30 PM CST
 ************************************************************************/
/*
 * 探索当前编译器下的虚继承模型
 * 1.是不是真的存储2个实例
 */
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


void print_address(uintptr_t ptr, int n) {
    unsigned char *p = (unsigned char *)ptr;
    printf("address %p : ", p);
    for (int i = 0; i < n; i++) {
        if(i % 4 == 0) printf("\n");
        printf("%02X ", p[i]);
    }
    printf("\n");
}

class A {
public:
    A() {
        this->x = 0xaaaaaaaa;
    }
    int x;
};
class B : virtual public A {
public:
    B() {
        //this->x = 0xbbbbbbbb;
    }
    void set_x(int x) {
        this->x = x;
        return ;
    }
};
class C : virtual public A {
public:
    C() {
        //this->x = 0xcccccccc;
    }
    int get_x() {
        return this->x;
    }
};
class D : public B, public C {

};

int main() {
    D d;
    /*
     * 注意观察采用虚继承前后的结果
     */
    print_address((uintptr_t)&d, sizeof(d));
    return 0;
}
