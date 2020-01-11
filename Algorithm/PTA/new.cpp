/**
 *    @Author: Wilson79
 *    @Datetime: 2020年1月8日 星期三 20:12:21
 *    @Filename: 英文缩写词.cpp
 */

// 花了2小时，总算找出了bug
// __we___are_of__China
// j每次也要更新，每次j = i，不然会TLE
// 这道题给我的启示是：不要上来就敲代码，先把一些关键点在纸上写清楚

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    for (int i = 0; i < n; i++) {
        int j = -1;
        for (j = i - 1; j >= 0; j --) {
            if (a[j] >= a[i]) continue;
            cout << a[j] << endl;
            break;
        }

        if (j == -1) cout << -1 << endl;
    }

    
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt", "r", stdin);
    #endif

    // PEOPLE’S REPUBLIC OF CHINA
    string s1;
    while(getline(cin, s1)) {
        // cout << s1 << endl;
        int n = s1.size();

        // 删除开头的连续空格
        int r = 0;
        while(s1[r] == ' ') r ++;

        for (int i = r, j = r; i < n;) {
            // 找到第一个空格
            while((j < n) && ((s1[j] != '-') && (s1[j] != ' '))) {
                j++;
            } 

            string s = s1.substr(i, j - i);
            char t = s[0];

            // 判断忽略的单词
            for (int k = 0; k < s.size(); k ++) {
                s[k] = tolower(s[k]);
            }
            if (s != "of" && s != "the" && s != "a" && s != "an" && s != "of" && s != "for" && s != "and") {
                cout << t;
            }

            //  中间连续空格时，让j到最后一个空格 判断条件最好在纸上写下
            while(j < n && s[j] == ' ') j ++;
            

            // 重置i和j的位置 
            i = j;
            j = i;
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
