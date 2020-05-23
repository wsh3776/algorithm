// 超时
#include <iostream>

using namespace std;

typedef long long LL;

LL fastpow(int a, LL k, LL p) {
    LL res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res % p;
}

int main() {
    
    LL n, m;
    cin >> n >> m;

    LL a = 2;
    for (int i = 0; i < n; i ++) {
        a = fastpow(2, a, m);
    }

    cout << a << endl;

    return 0;
}
