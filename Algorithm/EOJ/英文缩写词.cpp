/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月8日 星期三 20:12:21
 *    @Filename: 英文缩写词.cpp
 */

// 这个题其实是翻转字符串的模型题，说明我当时没有理解透
// 花了2小时，总算找出了bug
// ___PEOPLE’S_REPUBLIC___OF__CHINA
// j每次也要更新，每次j = i，不然会TLE
// 这道题给我的启示是：不要上来就敲代码，先把一些关键点在纸上写清楚

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // ___PEOPLE’S_REPUBLIC___OF__CHINA
    string s1;
    while(getline(cin, s1)) {
        int n = s1.size();

        for (int i = 0, j = 0; i < n;) {
            // 去除连续空格
            while(j < n && ((s1[j] == '-') || (s1[j] == ' '))) j ++;
            if (j == n) break;
            i = j;

            // 核心
            {
                while(j < n && ((s1[j] != '-') && (s1[j] != ' '))) j ++;

                string s = s1.substr(i, j - i);
                char t = s[0];

                // 判断忽略的单词
                for (int k = 0; k < s.size(); k ++) {
                    s[k] = tolower(s[k]);
                }
                if (s != "of" && s != "the" && s != "a" && s != "an" && s != "of" && s != "for" && s != "and") {
                    cout << t;
                }

                i = j;
            }
        }
        cout << endl;
    }

    return 0;
}






// // 此方法无法处理"-"的情况,所以还是用getline去读吧
// #include <iostream>

// using namespace std;

// int main() {
//     #ifdef ONLINE_JUDGE
//     #else
//     freopen("in.txt","r",stdin);
// #endif

// string s;
// while(cin >> s) {
//     char c = getchar();
//     char t = s[0];
//     for (int i = 0; i < s.size(); i ++) {
//         s[i] = tolower(s[i]);
//     }
//     if (s != "of" && s != "the" && s != "a" && s != "an" && s != "of" && s != "for" && s != "and") {
//         cout << t;
//         // cout << s << endl;
//     }
//     if (c == '\n') cout << endl;
//     }

//     return 0;
// }
