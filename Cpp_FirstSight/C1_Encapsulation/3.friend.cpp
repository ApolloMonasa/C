/*************************************************************************
	> File Name: 3.friend.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 23 Apr 2025 11:14:02 AM CST
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

class A {
public:
    void output() {
        cout << "Class A : " << x << ", " << y << endl;
    }
friend int main();//相关函数声明前面加friend关键字
friend void test1();
friend class B;//同样也是声明之前加一个friend
private:
    int x, y;
};

void test1() {
    A a;
    cout << "test1 changes A\n";
    a.x = 5, a.y = 6;
    a.output();
    return;
}

/*void test2(A &a) {
    a.x = 1, a.y = 3;//这种访问权限不能转移， 只能main函数自己访问，main函数调用的函数不能去访问。
    a.output();
}*/

struct B {
    void change(A &a) {
        cout << "B changes A\n";
        a.x = 100, a.y = 200;
        return ;
    }
};

int main() {
    A a;
    a.x = 3, a.y = 4;
    a.output();
    //test2();
    
    test1();
    B b;
    b.change(a);
    a.output();
    return 0;
}
