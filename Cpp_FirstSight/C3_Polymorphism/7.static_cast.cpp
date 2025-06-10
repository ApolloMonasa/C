/*************************************************************************
	> File Name: 7.static_cast.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 10 Jun 2025 09:33:54 PM CST
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

namespace T1 {
    void run() {
        int x = 123;
        //double *p = (double *)(x);
        //double *p = static_cast<double *>(x);
        double fx = static_cast<double>(x);
        const int cx = 456;
        int non_cx = static_cast<int>(cx);
        return ;
    }
}
namespace T2 {
    void run() {
        //int *x = new int;
        //float *fx = static_cast<float *>(x);
        //const int *cx = new int;
        //int *non_cx = static_cast<int *>(cx);
        int * const p1 = new int;
        int *p2 = static_cast<int *>(p1);
        return ;
    }
}

namespace T3 {
    class Base {};
    class A : public Base{
    public:
        //转换运算符
        operator int() {
            return 999;
        }
    };
    class B : public Base {};
    class End : public A, public B {};
    class AA : public A {};
    void run() {
        Base *p1 = new Base;
        AA *p2 = static_cast<AA *>(p1);

        A *a = new A;
        //转换运算符调用方式
        cout << (int)(*a) << endl;
        cout << static_cast<int>(*a) << endl;
        return ;
    }
}
int main() {
    T1::run();
    T2::run();
    T3::run();
    return 0;
}
