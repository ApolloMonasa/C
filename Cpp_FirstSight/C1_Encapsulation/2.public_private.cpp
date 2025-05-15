/*************************************************************************
	> File Name: 2.public_private.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 23 Apr 2025 11:00:26 AM CST
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

class People {
public:
    string name;
    int age;
    People() {
        initage();
    }

    void say() {
        cout << "My name is " << name << ", " << age << " years old" << endl;
    }
private:
    void initage() {
        srand(time(0));
        age = rand() % 100 + 1;
    }
};

int main() {
    People Apollo;
    Apollo.name = "Apollo";
    Apollo.say();
    return 0;
}
