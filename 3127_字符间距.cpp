/**
 * Author: shwei
 * Date: 2019/08/16 10:04
 * LastEditTime: 2019/09/02 20:55
 */

// 3
// ab
// bd
// bdabbdcdabdababcccbd
// a
// a
// aaa
// a11
// a21
// a11xa21xa11xa21xa21xa11
// case #0:
// 14
// case #1:
// 1
// case #2:
// 13

#include <iostream>

using namespace std;

typedef long long ll;

int main(void)
{

#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    for (int cnt = 0; cnt < T; cnt ++)
    {
        string s1, s2, s;
        cin >> s1 >> s2 >> s;

        if (s.find(s1) == string::npos || s.find(s2) == string::npos)
        {
            cout << "case #" << cnt << ":" << endl;
            cout << 0 << endl;
        }
        else
        {
            int res = 0;
            int a1 = s.find(s1), a2 = s.rfind(s1);
            int b1 = s.find(s2), b2 = s.rfind(s2);

            int s1tos2 = abs(a1 - b2) - (int)s1.size();
            if (s1tos2 < 0)
            {
                s1tos2 = 0;
            }
            int s2tos1 = abs(a2 - b1) - (int)s2.size();
            if (s2tos1 < 0)
            {
                s2tos1 = 0;
            }

            res = max(s1tos2, s2tos1);

            cout << "case #" << cnt << ":" << endl;
            cout << res << endl;
        }
    }

    return 0;
}
