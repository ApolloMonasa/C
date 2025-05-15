/*************************************************************************
	> File Name: 4.cout.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Apr 2025 07:47:22 PM CST
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
#include<iomanip>//setprecision 
#include<queue>
#include<numeric>
using namespace std;

int main() {
    int a = 123;
    cout << "hello world" << endl;
    cout << a << endl;
    cout << "a = " << a << endl;

    double b = 12.345;//默认6位有效数字，能短就短
    cout << b << endl;
    printf("%%lf = %lf\n", b);
    printf("%%g = %g\n", b);
    cout << setprecision(4) << b << endl;//4位有效数字
    cout << fixed  << setprecision(4) << b << endl;//fixed代表定点格式， 此时setprecision代表小数点后4位
    return 0;
}
