// 核心：预处理出阶乘 （用扩展欧几里得算法求逆元，也可以用快速幂fastpow(i, mod - 2, mod)，但 mod 需为质数

#include <iostream>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7, N = 1e5 + 7;

LL fact[N], infact[N];
LL x, y;

LL exgcd(int a, int b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void init() {
    fact[1] = infact[1] = 1;
    for (int i = 2; i <= N; i ++) {
        fact[i] = fact[i - 1] * i % mod;
        exgcd(i, mod, x, y);
        infact[i] = infact[i - 1] * x % mod; 
    }
}

int main() {
    int n;
    cin >> n;

    while(n --) {
        int a, b;
        cin >> a >> b;
        LL res = fact[a] * infact[a - b] % mod * infact[b] % mod;
        cout << res << endl;
    }

    return 0;
}