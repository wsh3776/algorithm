// 此模版适合于小数据，且 mi两两互质的情况
// 直接用公式求解

// 一个数被3除余1，被4除余2，被5除余4，这个数最小是几? 用模版可算出答案是 34
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 30;

LL m[N], a[N];

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a ;
    }
    LL d = exgcd(b , a % b, y ,x);
    y -= a / b * x;
    return d;
}

int main() {
    LL n;
    cin >> n;

    LL M = 1;
    for (LL i = 1; i <= n; i++) {
        cin >> m[i] >> a[i];
        M *= m[i];
    }

    LL res = 0;
    for (LL i = 1; i <= n; i++) {
        LL M_i = M / m[i], x, y;
        exgcd(M_i, m[i], x, y); // tmp和 m[i] 一定互素，x 为 M_i 模m[i]的逆
        res = res + a[i] * M_i * x;
    }

    cout << (res % M + M) % M << endl;

    return 0;
}