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

### virtual关键字

不能用来修饰类方法【static】。
virtual方法跟对象
非virtual方法跟着类


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

## 纯虚函数

相较于普通的虚函数，它最大的不一样就是它不需要函数体，而是一个 **= 0** 


但是它的所有子类中一定要有这个函数的实现，否则就是一个抽象类（不能创建对象的类）


可以用来设计对象的功能接口

```cpp
class Flyable {
public:
    virtual void fly() = 0;
};

class Animal {
public:
    virtual void run() = 0;
};

class Cat : public Animal {
public:
    void run() override {
        cout << "Cat run\n";
    }
};

class Bat : public Animal, public Flyable {
public:
    void fly() override {
        cout << "Bat fly\n";
    }
    void run() override {
        cout << "Bat run\n";
    }
};


void f1(Flyable &obj) {
    cout << "this is obj : ";
    obj.fly();
    return ;
}
```

正如之前讲继承所说的，类继承设计时，最好继承一个实体类，多个抽象类（这里就是我们的功能类）

## C++类型转换

>C语言已经有强制类型转换，那么，为什么还要费老大劲开发这四种类型转换呢？

第一：安全性差

第二：可读性差


### 静态转换：static_cast(主要，其他三种是补充,做到识别何种场景需要补充使用以下三种即可)

1. 做的是同类之间的转换，比如long\int\double\float\short

2. 也可以做const和非const变量的类型转换

3. 不能进行指针类型之间的转换

4. 不能进行const <type> *到 <type> *的类型转换

5. 存在继承关系（可以是父子，可以是爷孙，但是菱形继承的爷孙不行，兄弟不行）的类是同类的类，可以转换

6. 可以在类中定义转换运算符

```cpp
//1
static_cast<double>(要转换的变量);
//2
const int cx = 45;
int noncx = static_cast<int>(cx);
//3
int *x = new int;
float *fx = static_cast<float *>(x);
//4
const int *cx = new int;
int *non_cx = static_cast<int *>(cx);
//2
int * const p1 = new int;
int *p2 = static_cast<int *>(p1);

//5
class Base {};
class A : public Base{};
class B : public Base {};
class End : public A, public B {};
class AA : public A {};
void run() {
    Base *p1 = new Base;
    AA *p2 = static_cast<AA *>(p1);
    return ;
}
```



### 动态转换：dynamic_cast

> 什么情况才用得到？
> 防止把原本不是某类型的变量的地址转换成该类型的地址

如果是相同类型的指针转换，就会成功，否则就会返回一个空地址

至于为什么能够判断，就跟虚函数有关了，我们留到后面再探讨这个问题。

#### Example

```cpp
class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {
public:
    void output() {
        cout << "x = " << x << ", y = " << y << endl;
        return ;
    }
    int x, y;
};

int main() {
    A *p1 = new A;
    Base *p2 = p1;//隐式转换
    B *p3 = dynamic_cast<B *>(p2);
    if(p3 == nullptr) {
        cout << "convert failed\n";
    }
    else p3->output();
    return 0;
}
```

那么换个方向呢？就是把B换成A, 实际上不行。

### 常量转换：const_cast

### 指针转换：reinterpret_cast
