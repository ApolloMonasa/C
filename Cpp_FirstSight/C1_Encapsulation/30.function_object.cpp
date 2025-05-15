/*************************************************************************
	> File Name: 30.function_object.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 15 May 2025 03:37:52 PM CST
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

int add(int a, int b) {
    cout << "add function : ";
    return a+b;
}

class ADD {
public:
    int operator()(int a, int b) {
        cout << "class ADD function object : ";
        return a+b;
    }
};

bool cmp(int a, int b) {
    return a > b;
}

class CMP {
public:
    int operator()(int a, int b) {
        cout << tag << endl;
        return a>b;
    }
    CMP(int tag = 0) : tag(tag) {}
    int tag;
};

int main() {
    ADD add2;
    cout << add(3, 4) << endl;
    cout <<  add2(3, 4) << endl; 
    CMP cmp2;
    int a[10] = {4, 5, 3, 1, 9, 8, 7, 2, 6, 10};
    //sort(a, a+10, cmp2);
    sort(a, a+10, CMP(2333));
    

    for (int i = 0; i < 10; i++) {
        if(i) cout <<' ';
        cout << a[i];
    }
    cout << endl;
    return 0;
}
