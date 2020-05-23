// x[i] y[i] z[i] 的相对位置要记下来 然后去他们最小的
// 核心：只要看每个点前面有几个点保护他
// 如何得到每个点前面有多少个点呢
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e7;

unsigned long long x[N], y[N], z[N];

ULL cnt[N];

int n;

ULL k1, k2;
ULL CoronavirusBeats() {
    ULL k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

bool check(ULL a1, ULL b1, ULL c1, ULL a2, ULL b2, ULL c2) {
    if (a1 >= a2 && b1 >= b2 && c1 >= c2) {
        if (a1 > a2 || b1 > b2 || c1 > c2) return true;
    }

    return false;
}

struct node {
    ULL a;
    ULL b;
    ULL c;
    ULL index;
    ULL cnt;
};

bool cmp(node A, node B) {
    if (A.a < B.a) return true;
    if (A.a == A.a && A.b < B.b) return true;
    if (A.a == A.a && A.b == B.b && A.c < B.c) return true;
    return false;
}

bool cmp2(node A, node B) {
    return A.index < B.index;
}

node Po[N];

void init() {
    for (int i = 1; i <= n; ++i) {
        x[i] = CoronavirusBeats();
        y[i] = CoronavirusBeats();
        z[i] = CoronavirusBeats();
        // cin >> x[i] >> y[i] >> z[i];
        // cout << x[i] << " " << y[i] << " " << z[i] << endl;
        Po[i].a = x[i], Po[i].b = y[i], Po[i].c = z[i];
        Po[i].index = i;
        Po[i].cnt = 0;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    cin >> n;
    cin >> k1 >> k2;

    init();

    sort(Po + 1, Po + n + 1, cmp);

    ULL res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ULL a1 = Po[i].a, b1 = Po[i].b, c1 = Po[i].c, a2 = Po[j].a, b2 = Po[j].b, c2 = Po[j].c;
            if (check(a1, b1, c1, a2, b2, c2)) {
                if (Po[i].cnt < Po[j].cnt + 1) Po[i].cnt = Po[j].cnt + 1;
            }
            // cout << j << " : " << cnt[i] << endl;
        }
        if (Po[i].cnt > res) {
            res = Po[i].cnt;
        }
    }

    cout << res + 1 << endl;

    // for (int i = 1; i <= n; i ++) {
    //     ULL a1 = Po[i].a, b1 = Po[i].b, c1 = Po[i].c;
    //     cout << a1 << " " << b1 << " " << c1 << endl;
    // }

    sort(Po + 1, Po + n + 1, cmp2);
    for (int i = 1; i <= n - 1; i++)
        cout << Po[i].cnt << " ";

    cout << Po[n].cnt << endl;

    return 0;
}
