/*************************************************************************
	> File Name: 5.MyData.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 03 Apr 2025 01:33:11 PM CST
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

class Date {
private:
    int year;
    int month;
    int day;

    int getMaxDay(int y, int m) const {
        if (m == 2) {
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        } else {
            return 31;
        }
    }

public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}

    void setDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    void addOneDay() {
        day++;
        int max_day = getMaxDay(year, month);
        if (day > max_day) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    void input() {
        cin >> year >> month >> day;
    }

    void output() const {
        cout << year << "年" << month << "月" << day << "日" << endl;
    }
};

int main() {
    // 测试日期加一天
    cout << "测试日期加一天\n";
    Date d1(2023, 4, 3);
    d1.output();        // 2023年4月3日
    d1.addOneDay();
    d1.output();        // 2023年4月4日

    // 测试闰年2月
    cout << "测试闰年2月\n";
    Date d2(2020, 2, 28);
    d2.output();        // 2020年2月28日
    d2.addOneDay();
    d2.output();        // 2020年2月29日

    // 测试非闰年2月
    cout << "测试非闰年2月\n";
    Date d3(2021, 2, 28);
    d3.output();        // 2021年2月28日
    d3.addOneDay();
    d3.output();        // 2021年3月1日

    // 测试跨年
    cout << "测试跨年\n";
    Date d4(2023, 12, 31);
    d4.output();        // 2023年12月31日
    d4.addOneDay();
    d4.output();        // 2024年1月1日

    // 测试大月
    cout << "测试大月\n";
    Date d5(2023, 3, 31);
    d5.output();        // 2023年3月31日
    d5.addOneDay();
    d5.output();        // 2023年4月1日

    // 测试小月
    cout << "测试小月\n";
    Date d6(2023, 4, 30);
    d6.output();        // 2023年4月30日
    d6.addOneDay();
    d6.output();        // 2023年5月1日

    // 测试输入输出
    cout << "测试输入输出\n";
    Date d7;
    cout << "请输入日期（格式：XXXX XX XX）：";
    d7.input();
    d7.output();

    return 0;
}
