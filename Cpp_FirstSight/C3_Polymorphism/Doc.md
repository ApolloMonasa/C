# 多态

>为不同的数据类型的实体提供统一的接口

## 多态的分类

分为**编译时多态**以及**运行时多态**。

### 编译时多态

在编译时就可以确定的多态。或者说成在代码中就能看清调用何种多态版本。
比如：
1. 函数重载（运算符重载）
2. 模板

### 运行时多态

只有在运行时，得到输入信息后，才知道调用何种多态版本。
比如：
1. 虚函数:让对象可以执行自己重写的同名方法，而不是父类的同名方法,这需要借助**virtual**和**override**关键字。

```cpp
class Animal {
public:
    virtual void run() {
        cout << "I don't know how to run\n";
    }
};

class Cat : public Animal {
public:
    void run() override {
        cout << "I can run with four legs\n";
    }

};

int main() {
    Cat c;
    Animal *p = &c;
    c.run();
    p->run();
    return 0;
}
```

### override关键字

实际上对虚函数没有语法上的作用,但是它可以将一些运行时的错误提前暴露在编译阶段。
是一个很好的习惯，不用它是一个很坏的习惯。
```cpp
class Base {
public:
    virtual void test() {
        cout << "Base class test" << endl;
    }
    virtual void foo() {
        cout << "Base class foo" << endl;
    }
};
class A :public Base {
public:
    void test() {
        cout << "A class test" << endl;
    }

    void foo() override {
        cout << "A class foo\n";
    }
};
```


### final关键字

用来定义最后一个被重写的虚函数版本。**We cannot override a final function**

```cpp

struct Base {
    virtual void test() {
        cout << "Base" << endl;
        return ;
    }
};

struct A : Base {
    void test() override final {
        cout << "A" << endl;
    }
};

struct B : A {
};
```

## 虚函数和纯虚函数

