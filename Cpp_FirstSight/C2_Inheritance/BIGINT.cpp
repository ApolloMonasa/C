/*************************************************************************
	> File Name: HZOJ38_BIGINT.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 06 Jun 2025 12:06:55 PM CST
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

class BigInt : public vector<int> {
    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if(at(i) < 10) continue;
            if(i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
    }
public:
    BigInt() { push_back(0); }
    BigInt(int x) {
        push_back(x);
        process_digit();
    }
    BigInt &operator+=(const BigInt &a) {
        for (int i = 0; i < a.size(); i++) {
            if(i == size()) push_back(a.at(i));
            else at(i) += a.at(i);
        }
        process_digit();
        return *this;
    }
    BigInt operator+(const BigInt &a) {
        BigInt ret(*this);
        ret += a;
        return ret;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

BigInt f[105] = {0};

int main() {
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    cout << f[n] << endl;
    return 0;
}
