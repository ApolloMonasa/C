/*************************************************************************
	> File Name: 5.cin.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Apr 2025 01:51:53 PM CST
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

int main() {
    int a;
    cout << "cin : ";
    cin >> a;
    cout << "a = " << a << endl;
    double b;
    char c[100];
    cout << "cin  double string : ";
    cin >> b >> c;
    cout << "b = " << b << "\n" << "c = " << c << endl;

    while (cin >> a) {
        cout << "EOF read : a = " << a << endl;
    }
    return 0;
}
