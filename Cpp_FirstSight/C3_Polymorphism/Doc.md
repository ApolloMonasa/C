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
1. 虚函数:让对象可以执行自己重写的同名方法，而不是父类的同名方法

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

## 虚函数和纯虚函数

