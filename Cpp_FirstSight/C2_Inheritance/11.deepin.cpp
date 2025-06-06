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
        if(i % 8 == 0 && i != n-1) printf("\n");
        printf("%02X", p[i]);
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
        this->y1 = 0xbbbbbbbb;
    }
    void set_x(int x) {
        this->x = x;
        return ;
    }
    int y1;
};
class C : virtual public A {
public:
    C() {
        this->y2 = 0xcccccccc;
    }
    int get_x() {
        return this->x;
    }
    int y2;
};
class D : public B, public C {
public:
    D() : z(0xdddddddd) {}
    int z;
};

bool is_little() {
    static int n = 1;
    // 00 00 00 01
    // 01 00 00 00
    unsigned char *p = (unsigned char *)&n;
    return p[0] == 1;
}

void reverse_ptr(uintptr_t &ptr) {
    unsigned char *p1 = (unsigned char *)&ptr;
    unsigned char *p2 = p1 + sizeof(uintptr_t) - 1;
    while(p1 < p2) {
        swap(p1[0], p2[0]);
        p1++; p2--;
    }
    return ;
}

int main() {
    D d;
    /*
     * 注意观察采用虚继承前后的结果
     */
    print_address((uintptr_t)&d, sizeof(d));
    //判断大小端系统
    if(is_little()) printf("little\n");
    uintptr_t ptr;
    int n;
    while (~scanf("%lx%d", &ptr, &n)) {
        if(is_little()) reverse_ptr(ptr);
        print_address(ptr, n);
    }
    return 0;
}
