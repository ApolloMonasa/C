/*************************************************************************
	> File Name: 7.string.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Apr 2025 02:28:22 PM CST
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

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << endl;
    if(s1 < s2) cout << "s1 < s2\n";
    else if (s1 > s2) cout << "s1 > s2\n";
    else cout << "s1 = s2\n";

    cout << "s1.length() = " << s1.length() << endl;
    cout << "s2.size() = " << s2.size() << endl;

    for (int i = 0; i < s1.size(); i++) {
        cout << "s1[" << i << "] = " << s1[i] << endl;
    }
    for (int i = 0; i < s2[i]; i++) {
        cout << "s2[" << i << "] = " << s2[i] << endl;
    }

    cout << s1 + s2 << endl;
    
    cout << s1.substr(1, 2) << endl;

    return 0;
}
