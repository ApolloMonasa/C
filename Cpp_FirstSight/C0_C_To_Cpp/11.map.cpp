/*************************************************************************
	> File Name: 11.map.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Apr 2025 10:45:40 PM CST
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
    map<int, int> arr1;
    arr1[10000] = 1;
    arr1[-10000] = 2;
    
    map<double, int> arr2;
    arr2[1.5] = 3;
    arr2[2.5] = 4;
    arr2[3.5] = 5;
    
    cout << arr1.size() << ' ' << arr2.size() << endl;

    cout << arr1[10000] << ' ' << arr1[1] << endl;
    //访问未初始化的键值会自动创建
    cout << arr1.size() << ' ' << arr2.size() << endl;

    for (auto x : arr1) {
        cout << x.first << " " << x.second << endl;
    }
    for (auto x : arr2) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
