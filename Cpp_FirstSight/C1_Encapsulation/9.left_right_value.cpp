/*************************************************************************
	> File Name: 9.left_right_value.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 23 Apr 2025 09:41:16 PM CST
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

#define TEST(expr) {\
    cout << #expr;\
    f(expr);\
}
void g(int &x) {
    cout << "g : left value\n";
    return ;
}
void g(int &&x) {
    cout << "g : right value\n";
    return ;
}


//一个&叫做左值引用，优先绑定在左值
//两个&&叫做右值引用， 优先绑定在右值
void f(int &x) {
    cout << " is left value\n";
    g(x);
    return ;
}
//利用函数重载的特性判断究竟是左值还是右值
void f(int &&x) {
    cout << " is right value\n";
//    g(move(x));//保持右值方法1
    g(forward<int &&>(x));//保持右值方法2
    
    return ;
}

//优先但不是必须,const 修饰可以把他变成一个常量， 代表不被修改，就可以绑定到右值了
void test(int const  &x) {
    cout << "test function\n";
    return ;
}

int main() {
    int a = 12, b = 13;
    TEST(123);//r
    TEST(12 + 23);//r
    TEST(a + b);//产生中间值就是匿名变量->r
    TEST(a);
    TEST(b);
    TEST(a++);
    TEST(++a);
    (++a) = 1001;
    cout << a << endl;
    //(a++) = 1001;
    //cout << a << endl;
    test(12 + 23);
    return 0;
}
