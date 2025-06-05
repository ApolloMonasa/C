/*************************************************************************
	> File Name: 2.obj_size.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 15 May 2025 09:55:38 PM CST
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

#define P(c) {\
    printf("class %s : %zd\n", #c, sizeof(c));\
}

class Base {
public:
    Base() : x(0x1111111111111111) {}
    long long x;
};

class A : public Base {
public:
    A() : y(0x22222222) {}
    int y;
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

int main() {
    P(Base);
    P(A);
    A a;
    output_address(&a, sizeof(a));
    printf("简单继承场景中：父类数据在前\n");
    return 0;
}
