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
template<typename T>
ostream &operator<<(ostream &os, const Point<T> &p ) {
    os << "(" << p.x << ", " << p.y <<")";
    return os;
}

int main() {
    Point<int> int_point;
    Point<double> double_point;
    cout << sizeof(int_point) << endl;
    cout << sizeof(double_point) << endl;
    int_point = {3, 4};
    double_point = {3.4, 4.5};
    cout << int_point << endl;
    cout << double_point << endl;
    int_point.output("abc");
    double_point.output(1314);

    return 0;
}
