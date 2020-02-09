// 结构体排序
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Signtime {
    string name;
    int h;
    int m;
    int s;
} Signtime;

// Signtime <=> int

bool cmp(Signtime A, Signtime B) {
    if (A.h < B.h) return true;
    else if (A.h == B.h && A.m < B.m) return true;
    else if (A.h == B.h && A.m == B.m && A.s < B.s) return true;
    return false; // 其他情况return false
}

int main() {
    #ifdef ONLINE_JUDGE
    #else
    freopen("in.txt", "r", stdin);
    #endif

    int T;
    cin >> T;

    Signtime Sgin[T], Sgout[T];

    for(int i = 0; i < T; i ++) {
        string tmp;
        cin >> tmp;
        Sgin[i].name = tmp, Sgout[i].name = tmp;
        int a, b, c;
        scanf("%2d:%2d:%2d", &a, &b, &c);
        getchar();
        Sgin[i].h = a, Sgin[i].m = b, Sgin[i].s = c;
        scanf("%2d:%2d:%2d", &a, &b, &c);
        Sgout[i].h = a, Sgout[i].m = b, Sgout[i].s = c;
    }

    sort(Sgin, Sgin + T, cmp);
    sort(Sgout, Sgout + T, cmp);

    cout << Sgin[0].name << " " << Sgout[T - 1].name << endl;


    return 0;
}
// //法二
// //分析：将时间都转换为总秒数，最早和最迟的时间保存在变量minn和maxn中，并同时保存当前最早和最迟的人的ID，最后输出
// #include <iostream>
// #include <climits>
// using namespace std;
// int main() {
//     int n, minn = INT_MAX, maxn = INT_MIN;
//     scanf("%d", &n);
//     string unlocked, locked;
//     for(int i = 0; i < n; i++) {
//         string t;
//         cin >> t;
//         int h1, m1, s1, h2, m2, s2;
//         scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
//         int tempIn = h1 * 3600 + m1 * 60 + s1;
//         int tempOut = h2 * 3600 + m2 * 60 + s2;
//         if (tempIn < minn) {
//             minn = tempIn;
//             unlocked = t;
//         }
//         if (tempOut > maxn) {
//             maxn = tempOut;
//             locked = t;
//         }
//     }
//     cout << unlocked << " " << locked;
//     return 0;
// }