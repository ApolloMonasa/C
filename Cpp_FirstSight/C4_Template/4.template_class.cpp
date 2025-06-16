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

int main() {
    Point<int> int_point;
    Point<double> double_point;
    Point<string> string_point;
    cout << sizeof(int_point) << endl;
    cout << sizeof(double_point) << endl;
    int_point = {3, 4};
    double_point = {3.4, 4.5};
    string_point = {"abc", "def"};
    cout << int_point << endl;
    cout << double_point << endl;
    cout << string_point << endl;
    //没有参数的模板函数是全特化,当成原来模板的补丁
    //面对特殊需求，需要用到全特化
    int_point.output("abc");
    double_point.output(1314);
    string_point.output(123);

    return 0;
}
