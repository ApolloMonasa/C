/*************************************************************************
	> File Name: 11.deep_copy.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 24 Apr 2025 07:47:25 PM CST
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

class Array {
    int n, *data;
public:
    Array() : n(10), data(new int[n]) {
        memset(data, 0, sizeof(data));
    }
    Array(const Array& a) : n(a.n), data(new int[n]) {
        //for (int i = 0; i < a.n; i++) data[i] = a.data[i];
        memcpy(data, a.data, sizeof(data));
    }
    void set(int ind, int val) {data[ind] = val;}
    int size() {return n;}
    void output() {
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array a, b = a;
    for (int i = 0; i < a.size(); i++) {
        a.set(i, 1);
    }
    for (int i = 0; i < b.size(); i++) {
        b.set(i, i);
    }
    a.output();
    b.output();
    a.set(5, 1001);
    a.output();
    b.output();
    return 0;
}
