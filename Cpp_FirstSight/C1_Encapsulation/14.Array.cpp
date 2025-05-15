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
        cout << this << " default constructor\n";
        memset(data, 0, sizeof(data));
    }
    Array(const Array& a) : n(a.n), data(new int[n]) {
        cout << this << "copy\n";
        //for (int i = 0; i < a.n; i++) data[i] = a.data[i];
        memcpy(data, a.data, sizeof(data));
    }
    Array(Array &&a) : n(a.n), data(a.data) {
        cout << this << " move\n";
        a.n = 0;
        a.data = NULL;
    }
    ~Array() {
        cout << this << " destructor\n";
        if (!n) return ;
        delete[] data;
    }
    void set(int ind, int val) {data[ind] = val;}
    int size() {return n;}
    void output() {
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    Array duplicate() {
        return Array(*this);
    }
};

int main() {
    Array a, b = a.duplicate();
    Array c;
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    Array d = move(c);// how to ensure C is right value
    return 0;
}
