#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e6 + 7, mod = 1e9 + 7;

int a[N];
LL fact[N], infact[N];

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

// 预处理阶乘

int main() {
    int T;
    cin >> T;

    init();

    while (T --) {
        int n, m;
        cin >> n >> m;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a + 1, a + n + 1);

        int res = 0;
        for (int i = m; i <= n; i ++) {
            int x = i - 1, y = m - 1;
            res = (res % mod + a[i] * 1ll * fact[x] % mod * infact[x - y] % mod * infact[y] % mod) % mod;
        }
        cout << res << endl;
    }

    return 0;
}