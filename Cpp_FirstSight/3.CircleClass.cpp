/*************************************************************************
	> File Name: 3.CircleClass.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 19 Mar 2025 06:36:04 PM CST
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
using namespace std;

class Circle {
private :
    double radius;

public:
    // set R
    void SetRadius(double r) {
        if(r > 0) {
            radius = r;
        } else {
            perror("Invalid Radius!!\n");
        }
    }

    double getRadius() const {
        return radius;
    }

    double getArea() const {
        return M_PI * radius * radius;
    }

    double getCircumference() const {
        return 2 * M_PI * radius;
    }
};

void test_my_circle() {
    Circle myCircle;
    printf("Input Radius :");
    double x;
    cin >> x;
    myCircle.SetRadius(x);
    printf("Radius = %lf\n", myCircle.getRadius());
    printf("Area = %lf\n", myCircle.getArea());
    printf("Ciecumference = %lf\n", myCircle.getCircumference());
    return ;
}

int main() {
    test_my_circle();
}
