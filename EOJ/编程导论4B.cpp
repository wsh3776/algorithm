/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月8日 星期三 14:27:52
 *    @Filename: 编程导论4B.cpp
 */

// 注意：字符和数字的转换
// 大数相加模型
#include <iostream>

using namespace std;

string Add(string s1, string s2) {
    // s1 = 125
    // s2 =  34

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    string res = "";
    int t = 0;
    for (int i = 0; i < s1.size() || i < s2.size(); i ++) {
        if (i < s1.size()) t += s1[i] - 48;
        if (i < s2.size()) t += s2[i] - 48;
        res += to_string(t % 2);
        t = t / 2;
    }

    if (t > 0) res += to_string(t);
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt","r",stdin);
    #endif

    // 10110111
    string s;
    cin >> s;

    string ans = "";
    for (int i = 0; i < 17; i ++) {
        ans = Add(ans, s);
    }

    cout << ans << endl;

    return 0;
}