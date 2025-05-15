/*************************************************************************
	> File Name: 9.HZOJ-167.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Apr 2025 06:26:17 PM CST
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

    cout << a.size() << endl;
    cout << a.find('a') + 1 << endl;
    a.insert(x-1, b);
    cout << a << endl;
    return 0;
}
