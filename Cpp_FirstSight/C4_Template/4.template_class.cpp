/*************************************************************************
	> File Name: 4.template_class.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 16 Jun 2025 10:21:45 AM CST
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
class Point {
public:
    T x, y;
    Point() = default;
    Point(T x, T y) : x(x), y(y) {}
    template<typename U>
    void output(U u) {
        cout << "(" << x << ", " << y << ")" << u <<  endl;
        return ;
    }
};

//全特化
template<>
class Point<string> {
public:
    string x, y;
    Point() = default;
    Point(string x, string y) : x(x), y(y) {}
    template<typename U>
    void output(U u) {
        cout << "string : (" << x << ", " << y << ")" << u <<  endl;
        return ;
    }
};
//偏特化,保留模板参数
template<typename T>
class Point<T *> {
public:
    T *x, *y;
    Point() = default;
    Point(T *x, T *y) : x(x), y(y) {}
    template<typename U>
    void output(U u) {
        cout << "(" << *x << ", " << *y << ")" << u <<  endl;
        return ;
    }
};

template<typename T>
ostream &operator<<(ostream &os, const Point<T> &p ) {
    os << "(" << p.x << ", " << p.y <<")";
    return os;
}
//全特化
template<>
ostream &operator<<(ostream &os, const Point<string> &p ) {
    os << "string : (" << p.x << ", " << p.y <<")";
    return os;
}
//模板函数偏特化假象
template<typename T>
ostream &operator<<(ostream &os, const Point<T *> &p ) {
    os << "int * : (" << *p.x << ", " << *p.y <<")";
    return os;
}
//本质上模板函数没有偏特化
//只是函数重载罢了

int main() {
    Point<int> int_point;
    Point<double> double_point;
    Point<string> string_point;
    Point<int *> int_pointter_point;
    int a = 999, b = 888, *c = &a, *d = &b;
    int_pointter_point = {c, d};


    cout << sizeof(int_point) << endl;
    cout << sizeof(double_point) << endl;
    int_point = {3, 4};
    double_point = {3.4, 4.5};
    string_point = {"abc", "def"};
    cout << int_point << endl;
    cout << double_point << endl;
    cout << string_point << endl;
    cout << int_pointter_point << endl;
    //没有参数的模板函数是全特化,当成原来模板的补丁
    //面对特殊需求，需要用到全特化
    int_point.output("abc");
    double_point.output(1314);
    string_point.output(123);
    int_pointter_point.output("int *");//我们希望输出指针指向的值，这时候使用偏特化

    return 0;
}
