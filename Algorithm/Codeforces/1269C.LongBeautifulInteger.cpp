/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月9日 星期四 16:11:17
 *    @Filename: 1269C.LongBeautifulInteger.cpp
 */

#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
// "123" + "1" = "124"
string adds(string a, string b) {
    string res = "";
    int t = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size() || i < b.size(); i ++) {
        if (i < a.size()) t += a[i] - 48;
        if (i < b.size()) t += b[i] - 48;
 
        res += to_string(t % 10);
        t = t / 10;
    } 
 
    if (t > 0) res += to_string(t);
    reverse(res.begin(), res.end());
    return res;
}
 
int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt", "r", stdin);
    #endif
 
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
 
    string sub = s.substr(0, k), tmp = "";
 
    // 每个子串拼起来，看是否比x小，如果小了就让子串+1,否则直接输出结果
    int T = n / k;
    for (int i = 0; i < T; i ++) {
        tmp += sub;
    }
 
    tmp += s.substr(0, n % k);
    if (tmp >= s) {
        cout << n << endl;
        cout << tmp << endl;
     } else {
        sub = adds(sub, "1");
        tmp = "";
        for (int i = 0; i < T; i ++) {
            tmp += sub;
        }
        tmp += sub.substr(0, n % k);
        cout << n << endl;
        cout << tmp << endl;
    }
 
    return 0;
}