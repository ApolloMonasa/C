/*************************************************************************
	> File Name: 14.visitor.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 15 Jun 2025 04:19:42 PM CST
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

/*
 * 使用场景
 * 需要根据派生类的类型执行不同操作
 * 不希望增加成员方法
 * 代码维护方便，功能拓展方便
 */

class A;
class B;
class C;

class Base {
public:
    //定义访问者接口
    class IVisitor{
    public:
        virtual void visit(A *) = 0;
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
    };
    virtual void AC(IVisitor *) = 0;
    virtual ~Base() {}

    int x;
};

class A : public Base {
    void AC(IVisitor *vis) override {
        vis->visit(this);
        return ;
    }
};
class B : public Base {
    void AC(IVisitor *vis) override {
        vis->visit(this);
        return ;
    }
};
class C : public Base {
    void AC(IVisitor *vis) override {
        vis->visit(this);
        return ;
    }
};

class DynamicVisitor : public Base::IVisitor {
public:
    virtual void visit(A *) override {
        cout << "Class A : dynamic_cast\n";
    }
    virtual void visit(B *) override {
        cout << "Class B : dynamic_cast\n";
    }
    virtual void visit(C *) override {
        cout << "Class C : dynamic_cast\n";
    }
};

class NewVisitor : public Base::IVisitor {
public:
    virtual void visit(A *a) override {
        result = a->x + 1;
        return ;
    }
    virtual void visit(B *b) override {
        result = b->x + 2;
        return ;
    }
    virtual void visit(C *c) override {
        result = c->x + 3;
        return ;
    }
    int result;
};

int main() {
    srand(time(0));
    Base *p;
    switch(rand() % 3) {
        case 0 :p = new A; break;
        case 1 :p = new B; break;
        case 2 :p = new C; break;
    }
    p->x = 1000;
    //type1
    //p->AC();

    //type2
    if(dynamic_cast<A *>(p) != nullptr) {
        cout << "Class A : dynamic_cast\n";
    }
    if(dynamic_cast<B *>(p) != nullptr) {
        cout << "Class B : dynamic_cast\n";
    }
    if(dynamic_cast<C *>(p) != nullptr) {
        cout << "Class C : dynamic_cast\n";
    }
    //type3
    cout << "Visitor!\n";
    DynamicVisitor vis;
    p->AC(&vis);

    NewVisitor vis2;
    p->AC(&vis2);
    cout << "result : " << vis2.result << endl;
}
