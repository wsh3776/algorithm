/**
 *    @Author: Wilson79
 *    @Datetime: 2019年12月10日 星期二 15:24:39
 *    @Filename: 1265A.Beautiful String.cpp
 */

#include <iostream>

using namespace std;

string ans = "abc"; // 可以选择的填数内容

// 原来还可以在子函数进行cin和cout,简化代码
// 填数可以用一个循环去做，不满足条件就continue
void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i ++) {
        for (int j = 0; j < 3; j ++) {
            if (s[i] == '?') {
                if (i && s[i - 1] == ans[j]) continue;
                if (i + 1 < s.size() && s[i + 1] == ans[j]) continue;
                s[i] = ans[j]; // 将?修改成任一合适的字母
            }
        }
    }

    for (int i = 1; i < s.size(); i ++) {
        if (s[i - 1] == s[i]) {
            cout << "-1" << endl;
            return;
        }
    }

    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    while(t --) solve();

    return 0;
}





