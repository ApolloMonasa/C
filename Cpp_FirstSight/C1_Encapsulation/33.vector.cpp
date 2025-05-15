/*************************************************************************
	> File Name: 33.vector.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 15 May 2025 04:59:43 PM CST
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

class my_vector {
public:
    my_vector() : n(2), data(new int[n]), tail(0) {}
    typedef int* iterator;
    int *begin() {
        return data;
    }
    int *end() {
        return data+tail;
    }
    size_t size() {
        return tail;
    }
    int &operator[](int ind) {
        return data[ind];
    }
    void push_back(int x) {
        if(tail == n) expand();
        data[tail++] = x;
    }
private:
    void expand() {
        int *new_data = new int[2*n];
        memcpy(new_data, data, sizeof(data));
        delete[] data;
        data = new_data;
        n *= 2;
        cout << "expand : " << n/2 << "->" << n << '\n';
    }

    size_t n, tail;
    int *data;
};


int main() {
    vector<int> a;
    my_vector b;

    for (int i = 0; i < 10; i++) {
        a.push_back(rand()%100);
    }
    cout << "vector<int> a push_back done\n";
    for (int i = 0; i < 10; i++) {
        b.push_back(rand()%100);
    }
    cout << "my_vector b push_back done\n";

    cout << "vector for : ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
    cout << endl;

    cout << "my_vector for : ";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < a.size(); i++) {
        a[i] = 2* i;
    }
    cout << "vector<int> a update 2*i done\n";
    for (int i = 0; i < a.size(); i++) {
        b[i] = 3* i;
    }
    cout << "my_vector b update 3*i done\n";
    cout << "vector<int>::iterator : ";
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++) {
        int x = *iter;
        cout << x << ' ';
    }
    cout << endl;
    cout << "my_vector::iterator : ";
    for (my_vector::iterator iter = b.begin(); iter != b.end(); iter++) {
        int x = *iter;
        cout << x << ' ';
    }
    cout << endl;


    cout << "vector<int> new for : ";
    for (int x : a) {
        cout << x << ' ';
    }
    cout << endl;
    cout << "my_vector new for : ";
    for (int x : b) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
