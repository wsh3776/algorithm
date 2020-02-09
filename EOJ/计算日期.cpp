/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月8日 星期三 14:37:50
 *    @Filename: 给定第几天计算日期.cpp
 */

// 闰年的判断方法
// 口诀：四年一闰，百年不闰，四百年再闰

// 根据这个写出的程序的核心算法就是：

// if（(n % 4 == 0 && n % 100 != 0) || n % 400 == 0）

#include <iostream>

using namespace std;

int year, day;

int months[] = {31, 28, 31, 30, 31, 30,  31, 31, 30, 31, 30, 31}; // Not leap year

bool isLeapYear(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        return true;
    }
    return false;
}

void solve(int y, int d) {
    if (isLeapYear(y)) months[1] ++; // 29 days

    int tot = 0;
    for (int i = 0 ; i < 12; i ++) {
        tot += months[i];
        if (d <= tot) {
            int mm = i;
            int dd = d - (tot - months[i]);
            cout << year << "年的第" << day << "天是" << mm + 1 << "月" << dd << "日" << endl;
            break;
        }
    }
}

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt", "r", stdin);
    #endif


    cin >> year >> day;

    solve(year, day);

}