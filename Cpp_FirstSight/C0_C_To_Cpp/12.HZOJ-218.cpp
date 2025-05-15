/*************************************************************************
	> File Name: 12.HZOJ-218.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Apr 2025 11:10:35 PM CST
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
    map<int, vector<int>> ip;
    int n, h;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h;
        ip[h].push_back(i);
    }
    int flag = 0;
    for (auto x : ip) {
        for (auto y : x.second) {
            if (flag) cout << " ";
            cout << y;
            flag = 1;
        }
    }
    cout  << endl;
    return 0;
}
