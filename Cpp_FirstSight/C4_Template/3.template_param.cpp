/*************************************************************************
	> File Name: 3.template_param.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 16 Jun 2025 09:56:08 AM CST
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

template<typename T>
void Type(T a) {
    cout << "Type(T a) = " << a << endl;
    return ;
}

template<typename T>
void Type(T *a) {
    cout << "Type(T *a) = " << a  << ", " << *a<< endl;
    return ;
}


int main() {
    int a = 122;
    Type(a);
    double b = 12.3;
    Type(b);
    /*
     * 这就是隐式推导
     * 1.匹配模板
     * 2.类型推导
     */
    
    int *p1 = &a;
    double *p2  = &b;
    Type(p1);
    Type(p2);

    //显式推导就是之前的显式地指定模板的类型
    Type<char>(a);
    Type<double>(b);
    Type<int>(p1);
    Type<double>(p2);


}
