/*************************************************************************
	> File Name: 2.namespace.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 16 Apr 2025 09:45:40 PM CST
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



//OLD C
int apple_cnt = 0;
void apple_inc() {
    apple_cnt += 1;
    return ;
}

int banana_cnt = 0;
void banana_inc() {
    banana_cnt += 1;
    return ;
}

//C++
namespace apple {
    int cnt = 0;
    void inc() {
        cnt += 1;
        return ;
    }
}
namespace banana {
    int cnt = 0;
    void inc() {
        cnt += 1;
        return ;
    }
}

#define P(msg) printf(#msg " = %d\n", msg);

namespace apple {
    void dec() {
        cnt -= 1;
        return ;
    }
}

namespace {
    int a = 1;
}

int main() {
    //way 1
    printf("域限定符::\n");
    apple::cnt = 5;
    apple::inc();
    P(apple::cnt)
    banana::inc();
    P(banana::cnt)
    //way 2
    printf("using name(::object)\n");
    using banana::cnt;
    cnt += 100;
    P(apple::cnt)
    P(banana::cnt)
    //多代码段定义
    printf("多代码段定义\n");
    apple::dec();
    P(apple::cnt)
    //匿名的名字空间
    printf("匿名的名字空间\n");
    P(a)
    return 0;
}
