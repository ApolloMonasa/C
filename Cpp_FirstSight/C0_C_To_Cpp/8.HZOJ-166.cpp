/*************************************************************************
	> File Name: 8.HZOJ-166.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Apr 2025 05:56:17 PM CST
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
    string a, b;
    int x;
    cin >> a >> x >> b;

    int L = a.length();
    cout << min(L, 100) << endl;//min要求参数类型完全相同
    a.insert(x-1, b);
    cout << a << endl;
    cout << a.size() - a.rfind("x") << endl;
    return 0;
}
