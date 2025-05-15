/*************************************************************************
	> File Name: 31.array_object.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 15 May 2025 03:54:37 PM CST
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

class ARRAY {
public:
    ARRAY() : data(new int[10]) {}
    int &operator[](int ind) {
        return data[ind];
    }
    int *data;
};

int main() {
    srand(time(0));
    ARRAY a;
    for (int i = 0; i < 10; i++) {
        a[i] = rand()%100;
    }
    for (int i = 0; i < 10; i++) {
        cout << a[i] << ' '; 
    }
    cout << endl;
    return 0;
}
