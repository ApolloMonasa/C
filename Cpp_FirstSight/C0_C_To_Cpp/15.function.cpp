/*************************************************************************
	> File Name: 15.function.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 22 Apr 2025 08:18:28 PM CST
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
#include<functional>

void test() {
    cout << "hello test\n";
}

int add(int a, int b) {
    cout << "normal function : ";
    return a + b;
}

class ADD {
public:
    int operator()(int a, int b) const {
        cout << "function object : ";
        return a + b;
    }
} add2;

int main() {
    function<void(void)> p1 = test;
    p1();
    function<int(int, int)> p2 = add;
    cout  << p2(1, 1) << endl;
    //除了和原生函数指针相同的用途之外， function还能指向函数对象和lambda表达式
    cout << add2(1, 1) << endl;
    p2 = add2;
    cout << p2(3, 4) << endl;
    auto add3 = [](int a, int b)->int{
      cout << "lambda : ";
        return a + b;
    };
    p2 = add3;
    cout << p2(3, 4) << endl;
    
    return 0;
}
