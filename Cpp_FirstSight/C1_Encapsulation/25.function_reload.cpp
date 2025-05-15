/*************************************************************************
	> File Name: 25.function_reload.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 05 May 2025 12:31:05 PM CST
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
int add(int, int);

int add(int a, int b) {
    cout << "add(int,int): " << a+b << endl;
    return a+b;
}
double add(double a, int b) {
    cout << "add(double,int): " << a+b << endl;
    return a+b;
}

int add(int a, int b, int c) {
    cout << "add(int,int,int): " << a+b+c << endl;
    return a+b+c;
}
//能通过参数数量和类型匹配
//通过参数类型匹配时，优先从参数列表左侧向右侧匹配，如果第一个匹配上了，对后续参数当没有更好的选项时，就会发生强制类型转换
//不能通过返回值类型匹配
/*int add(double a, int b) {
    cout << "add(double,int): " << a+b << endl;
    return a+b;
}*/
int main() {
    add(3,4.0);
    add(3, 4);
    add(1,2,3);
    return 0;
}
