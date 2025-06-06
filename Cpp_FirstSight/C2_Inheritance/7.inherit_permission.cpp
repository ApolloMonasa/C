/*************************************************************************
	> File Name: 7.inherit_permission.cpp(with some designed bucket_countgs)
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 06 Jun 2025 12:23:36 PM CST
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

class Base {
public:
    int public_x;
protected:
    int protected_x;
private:
    int private_x;
friend class A;
};

/*
 * 继承权限根本就不影响子类对于父类方法属性的访问
 * 可以看作是多一层的权限控制
 * friend用来在定义类时候给与最大权限
 */

class A : public Base {
public:
    void set() {
        this->public_x = 2;
        this->protected_x = 2;
        this->private_x = 2;
    }
};

class B : protected A {
public:
    void set() {
        this->public_x = 2;
        this->protected_x = 2;
        this->private_x = 2;
    }
};


int main() {
    A a;
    a.set();
    a.public_x = 3;
    a.protected_x = 3;
    a.private_x = 3;
    return 0;
}
