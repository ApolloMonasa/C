/*************************************************************************
	> File Name: 13.HZOJ-172.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 22 Apr 2025 07:00:45 PM CST
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
    set<string> s;
    string str;
    for (int i = 0; i < 10; i++) {
        cin >> str;
        s.insert(str);
    }
    for (auto x : s) {
        cout << x << "\n";
    } 
    return 0;
}
