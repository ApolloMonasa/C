/*************************************************************************
	> File Name: 10.HZOJ-170.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 18 Apr 2025 07:01:55 PM CST
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
    string s;
    string olds = "Ban_smoking", news = "No_smoking";
    int oldlen = olds.size();
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        do {
            int pos = s.find(olds);
            if (pos == -1) break;
            s.replace(pos, oldlen, news);
        } while (1);
        cout << s << endl;
    }
    return 0;
}
