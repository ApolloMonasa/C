/*************************************************************************
	> File Name: 6.Mystack.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 17 Apr 2025 04:49:27 PM CST
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

// 定义单链表节点类
template <typename T>
struct ListNode {
    T data;
    ListNode* next;
    ListNode(const T& value) : data(value), next(nullptr) {}
};

// 定义整型栈类
template <typename T>
class Stack {
private:
    ListNode<T>* topNode;

public:
    // 构造函数
    Stack() : topNode(nullptr) {}

    // 复制构造函数
    Stack(const Stack& other) {
        if (other.topNode == nullptr) {
            topNode = nullptr;
            return;
        }
        ListNode<T>* source = other.topNode;
        topNode = new ListNode<T>(source->data);
        ListNode<T>* current = topNode;
        source = source->next;
        while (source != nullptr) {
            current->next = new ListNode<T>(source->data);
            current = current->next;
            source = source->next;
        }
    }

    // 移动构造函数
    Stack(Stack&& other) noexcept {
        topNode = other.topNode;
        other.topNode = nullptr;
    }

    // 复制赋值运算符
    Stack& operator=(const Stack& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        if (other.topNode == nullptr) {
            topNode = nullptr;
            return *this;
        }
        ListNode<T>* source = other.topNode;
        topNode = new ListNode<T>(source->data);
        ListNode<T>* current = topNode;
        source = source->next;
        while (source != nullptr) {
            current->next = new ListNode<T>(source->data);
            current = current->next;
            source = source->next;
        }
        return *this;
    }

    // 移动赋值运算符
    Stack& operator=(Stack&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        clear();
        topNode = other.topNode;
        other.topNode = nullptr;
        return *this;
    }

    // 析构函数
    ~Stack() {
        clear();
    }

    // 入栈操作
    void push(const T& value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    // 出栈操作
    void pop() {
        if (topNode != nullptr) {
            ListNode<T>* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // 获取栈顶元素
    T& top() {
        return topNode->data;
    }

    // 判断栈是否为空
    bool empty() const {
        return topNode == nullptr;
    }

    // 清空栈
    void clear() {
        while (topNode != nullptr) {
            ListNode<T>* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};

// 测试程序
int main() {
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);

    // 测试复制构造
    Stack<int> stack2(stack1);
    std::cout << "stack2 top: " << stack2.top() << std::endl;

    // 测试移动构造
    Stack<int> stack3(std::move(stack1));
    std::cout << "stack3 top: " << stack3.top() << std::endl;

    // 测试复制赋值
    Stack<int> stack4;
    stack4 = stack2;
    std::cout << "stack4 top: " << stack4.top() << std::endl;

    // 测试移动赋值
    Stack<int> stack5;
    stack5 = std::move(stack4);
    std::cout << "stack5 top: " << stack5.top() << std::endl;

    while (!stack5.empty()) {
        std::cout << stack5.top() << " ";
        stack5.pop();
    }
    std::cout << std::endl;

    return 0;
}
