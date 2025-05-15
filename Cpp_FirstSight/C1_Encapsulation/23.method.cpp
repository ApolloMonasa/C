/*************************************************************************
	> File Name: 23.method.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 02 May 2025 07:56:17 PM CST
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
    void say() {
        cout << "say something : " << this << endl;
    }
    static void class_say() {
        cout << "class say something : "  << endl;
    }
};

int main() {
    People a;
    a.say();
    a.class_say();
    People::class_say();
    return 0;
}
