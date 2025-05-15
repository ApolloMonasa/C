/*************************************************************************
	> File Name: 3.swap.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Apr 2025 07:20:21 PM CST
 ************************************************************************/
//介绍引用参数



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
//Old C
void Cswap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
    return ;
}
//Cpp
void Cppswap(int& a, int& b) {
    int c = a;
    a = b; 
    b = c;
    return ;
}

int main() {
    int a = 'a';
    int b = 'b';

    //绑定操作
    int &c = a;

    printf("a =  %d, b = %d\n", a, b);
    Cswap(&a, &b);
    printf("Cswap\n");
    printf("a =  %d, b = %d\n", a, b);
    Cppswap(a, b);
    printf("Cppswap\n");
    printf("a =  %d, b = %d\n", a, b);
    printf("Operate on c\n");
    c += 100;
    printf("a = %d = c = %d\n", a, c);

    return 0;
}
