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

class INT {
    int *px;
public:
    INT() : px(new int(0)) {
        cout << "INT constructor\n";
    }
    INT(const INT &a) : px(new int(0)) {
        cout << "INT constructor\n";
        *px = *a.px;
    }
    ~INT() {
        cout << "INT destructor\n";
        delete px;
    }
    void set(int x) {*px = x;}
    int val() {return *px;}
};

class Array {
    int n;
    INT *data;
public:
    Array() : n(10), data(/*new INT[n]*/(INT *)malloc(sizeof(INT)*10)) {
        cout << this << " default constructor\n";
        for (int i = 0; i < n; i++) new(data+i) INT();
    }
    Array(const Array& a) : n(a.n), /*data(new INT[n])*/ data((INT *)malloc(sizeof(INT) * a.n)) {//问题出在这，原地构造要配合malloc使用
        cout << this << "copy\n";
        //for (int i = 0; i < a.n; i++) data[i] = a.data[i];
        //memcpy(data, a.data, sizeof(data));
        for (int i = 0; i < a.n; i++) new(data+i) INT(a.data[i]);
    }
    Array(Array &&a) : n(a.n), data(a.data) {
        cout << this << " move\n";
        a.n = 0;
        a.data = NULL;
    }
    ~Array() {
        cout << this << " destructor\n";
        if (!n) return ;
        for (int i = 0; i < n; i++) data[i].~INT();
        free(data);
    }
    void set(int ind, int val) {data[ind].set(val);}
    int size() {return n;}
    void output() {
        cout << data << " : ";
        for (int i = 0; i < n; i++) {
            cout << data[i].val() << " ";
        }
        cout << endl;
    }
    Array duplicate() {
        return Array(*this);
    }
};

int main() {
    Array a, b = a;
    a.set(0, 1001);
    b.set(0, 2002);
    a.output();
    b.output();
    return 0;
}
