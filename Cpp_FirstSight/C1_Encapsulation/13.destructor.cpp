/*************************************************************************
	> File Name: 13.destructor.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 29 Apr 2025 11:03:38 AM CST
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

class A {
    int *data;
public:
    A() : data(new int[10]) {
        cout << this << " default constructor\n";
    }
    ~A() {
        delete[] data;
        cout << this << " destructor\n";
    }
};
int main() {
    A a, *pa = new A();
    cout << "a : " << &a << endl;
    cout << "pa : " << pa << endl;
    delete pa;
    return 0;
}
