/*************************************************************************
	> File Name: 4.MySet.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 01 Apr 2025 09:51:37 AM CST
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

class SimpleSet {
private:
    vector<int> elements;

public:
    // 添加元素
    void add(int element) {
        if (!contains(element)) {
            elements.push_back(element);
        }
    }

    // 删除元素
    void myremove(int element) {
        elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
    }

    // 判断元素是否存在
    bool contains(int element) const {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    // 获取集合大小
    size_t size() const {
        return elements.size();
    }

    // 判断集合是否为空
    bool isEmpty() const {
        return elements.empty();
    }

    // 清空集合
    void clear() {
        elements.clear();
    }

    // 求交集
    SimpleSet intersection(const SimpleSet& other) const {
        SimpleSet result;
        for (int elem : elements) {
            if (other.contains(elem)) {
                result.add(elem);
            }
        }
        return result;
    }

    // 求差集 (this - other)
    SimpleSet difference(const SimpleSet& other) const {
        SimpleSet result;
        for (int elem : elements) {
            if (!other.contains(elem)) {
                result.add(elem);
            }
        }
        return result;
    }

    // 打印集合内容
    void print(const string& name = "") const {
        if (!name.empty()) {
            cout << name << ": ";
        }
        cout << "{ ";
        for (size_t i = 0; i < elements.size(); ++i) {
            cout << elements[i];
            if (i != elements.size() - 1) {
                cout << ", ";
            }
        }
        cout << " }" << endl;
    }
};

// 测试程序
int main() {
    SimpleSet setA, setB;

    // 添加元素
    setA.add(1);
    setA.add(2);
    setA.add(3);
    setA.add(4);

    setB.add(3);
    setB.add(4);
    setB.add(5);
    setB.add(6);

    // 打印集合
    setA.print("Set A");
    setB.print("Set B");

    // 测试交集
    SimpleSet intersection = setA.intersection(setB);
    intersection.print("A ∩ B");

    // 测试差集
    SimpleSet difference = setA.difference(setB);
    difference.print("A - B");

    // 测试删除元素
    setA.myremove(2);
    setA.print("Set A after removing 2");

    // 测试包含关系
    cout << "Set A contains 3? " << (setA.contains(3) ? "Yes" : "No") << endl;
    cout << "Set A contains 5? " << (setA.contains(5) ? "Yes" : "No") << endl;

    // 测试集合大小
    cout << "Size of Set A: " << setA.size() << endl;

    return 0;
}
